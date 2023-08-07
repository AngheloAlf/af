#!/usr/bin/env python3
import colorama
colorama.init()

import argparse
import dataclasses
import sys
import mapfile_parser
from pathlib import Path

def mapPathToSource(origName: Path) -> Path:
    # Try to map built path to the source path
    parts = origName.parts
    if parts[0] == "build":
        parts = parts[1:]

    path = Path(*parts)
    # Assume every file in the asm folder has .s extension, while everything else has .c extension
    if path.parts[0] == "asm":
        path = path.with_suffix(".s")
    else:
        path = path.with_suffix(".c")
    return path


def compareMapFiles(mapFileBuild: Path, mapFileExpected: Path) -> mapfile_parser.MapsComparisonInfo:
    print(f"Build mapfile:    {mapFileBuild}", file=sys.stderr)
    print(f"Expected mapfile: {mapFileExpected}", file=sys.stderr)
    print("", file=sys.stderr)

    if not mapFileBuild.exists():
        print(f"{colorama.Fore.LIGHTRED_EX}error{colorama.Fore.RESET}: mapfile not found at {mapFileBuild}. Did you enter the correct path?", file=sys.stderr)
        exit(1)

    if not mapFileExpected.exists():
        print(f"{colorama.Fore.LIGHTRED_EX}error{colorama.Fore.RESET}: expected mapfile not found at {mapFileExpected}. Is 'expected' missing or in a different folder?", file=sys.stderr)
        exit(1)

    buildMap = mapfile_parser.MapFile()
    buildMap.readMapFile(mapFileBuild)
    buildMap = buildMap.filterBySectionType(".bss")

    expectedMap = mapfile_parser.MapFile()
    expectedMap.readMapFile(mapFileExpected)
    expectedMap = expectedMap.filterBySectionType(".bss")

    return buildMap.compareFilesAndSymbols(expectedMap)


def printCsv(compInfo: mapfile_parser.MapsComparisonInfo, printAll = True):
    print("Symbol Name,Build Address,Build File,Expected Address,Expected File,Difference,GOOD/BAD/MISSING")

    # If it's bad or missing, don't need to do anything special.
    # If it's good, check for if it's in a file with bad or missing stuff, and check if print all is on. If none of these, print it.

    for symbolInfo in compInfo.comparedList:
        buildFile = symbolInfo.buildFile if symbolInfo.buildFile is not None else None
        expectedFile = symbolInfo.expectedFile if symbolInfo.expectedFile is not None else None

        buildFileName = ""
        if buildFile is not None:
            buildFileName = mapPathToSource(buildFile.filepath)

        expectedFileName = ""
        if expectedFile is not None:
            expectedFileName = mapPathToSource(expectedFile.filepath)

        symbolGood = colorama.Fore.RED + "BAD" + colorama.Fore.RESET
        if symbolInfo.diff is None:
            symbolGood = colorama.Fore.YELLOW + "MISSING" + colorama.Fore.RESET
            print(f"{symbolInfo.symbol.name},{symbolInfo.buildAddress:X},{buildFileName},{symbolInfo.expectedAddress:X},{expectedFileName},{symbolInfo.diff},{symbolGood}")
            continue

        if symbolInfo.diff == 0:
            symbolGood = colorama.Fore.GREEN + "GOOD" + colorama.Fore.RESET
            if not buildFile in compInfo.badFiles and not expectedFile in compInfo.badFiles:
                if not buildFile in compInfo.badFiles and not expectedFile in compInfo.badFiles:
                    if not printAll:
                        continue

        if buildFile != expectedFile:
            symbolGood += colorama.Fore.CYAN + " MOVED" + colorama.Fore.RESET
        print(f"{symbolInfo.symbol.name},{symbolInfo.buildAddress:X},{buildFileName},{symbolInfo.expectedAddress:X},{expectedFileName},{symbolInfo.diff:X},{symbolGood}")


def main():
    description = "Check that globally visible bss has not been reordered."
    epilog = """\
    N.B. Since this script reads the map files, it can only see globally visible bss; in-function static bss must be examined with other tools.
    """

    parser = argparse.ArgumentParser(description=description, epilog=epilog, formatter_class=argparse.RawTextHelpFormatter)
    parser.add_argument("mapFile", help="Path to a map file.")
    parser.add_argument("mapFileExpected", help="Path to the expected map file. Optional, default is 'expected/mapFile'.", nargs="?", default="")
    parser.add_argument("-a", "--print-all", help="Print all bss, not just non-matching.", action="store_true")
    parser.add_argument("-n", "--no-fun-allowed", help="Remove amusing messages.", action="store_true")
    args = parser.parse_args()

    mapfilePath = Path(args.mapFile)

    if args.mapFileExpected == "":
        mapfileExpectedPath = "expected" / mapfilePath
    else:
        mapfileExpectedPath = Path(args.mapFileExpected)


    compInfo = compareMapFiles(mapfilePath, mapfileExpectedPath)
    printCsv(compInfo, args.print_all)

    if len(compInfo.badFiles) + len(compInfo.missingFiles) != 0:
        print("", file=sys.stderr)

        if len(compInfo.badFiles) != 0:
            print(colorama.Fore.RED + "  BAD" + colorama.Style.RESET_ALL)

            for file in compInfo.badFiles:
                print(f"bss reordering in {mapPathToSource(file.filepath)}", file=sys.stderr)
            print("", file=sys.stderr)

            if not args.no_fun_allowed:
                print(colorama.Fore.LIGHTWHITE_EX +
                "  BSS is REORDERED!!\n"
                "  Oh! MY GOD!!" 
                + colorama.Style.RESET_ALL, file=sys.stderr)
                print("", file=sys.stderr)

        if len(compInfo.missingFiles) != 0:
            print(colorama.Fore.YELLOW + "  MISSING" + colorama.Style.RESET_ALL)

            for file in compInfo.missingFiles:
                print(f"Symbols missing from {mapPathToSource(file.filepath)}", file=sys.stderr)
            print("", file=sys.stderr)

            if not args.no_fun_allowed:
                print(colorama.Fore.LIGHTWHITE_EX + "  Error, should (not) be in here " + colorama.Style.RESET_ALL, file=sys.stderr)
                print("", file=sys.stderr)

            print("Some files appear to be missing symbols. Have they been renamed or declared as static? You may need to remake 'expected'", file=sys.stderr)

        return 1

    print("", file=sys.stderr)
    print(colorama.Fore.GREEN + "  GOOD" + colorama.Style.RESET_ALL, file=sys.stderr)

    if args.no_fun_allowed:
        return 0

    print("\n" + colorama.Fore.LIGHTWHITE_EX +
    colorama.Back.RED + "                                  " + colorama.Back.RESET + "\n" +
    colorama.Back.RED + "         CONGRATURATIONS!         " + colorama.Back.RESET + "\n" +
    colorama.Back.RED + "    All Global BSS is correct.    " + colorama.Back.RESET + "\n" +
    colorama.Back.RED + "             THANK YOU!           " + colorama.Back.RESET + "\n" +
    colorama.Back.RED + "      You are great decomper!     " + colorama.Back.RESET + "\n" +
    colorama.Back.RED + "                                  " + colorama.Style.RESET_ALL , file=sys.stderr)

    return 0

if __name__ == "__main__":
    ret = main()
    exit(ret)