#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2023 ZeldaRET
# SPDX-License-Identifier: MIT

from __future__ import annotations

import argparse
import dataclasses
import itertools
from pathlib import Path
import spimdisasm
import subprocess
import yaml


QUIET = False

def printVerbose(*args, **kwargs):
    if QUIET:
        return
    print(*args, **kwargs)


@dataclasses.dataclass
class OverlaySegment:
    name: str
    relocPath: Path # without extension
    files: list[Path]

def getOverlays(yamlPath: Path) -> list[OverlaySegment]:
    printVerbose("Parsing yaml...")

    with yamlPath.open("r") as f:
        yamlObj = yaml.load(f, Loader=yaml.SafeLoader)

    printVerbose("Searching for overlays...")

    options = yamlObj["options"]

    buildPath = Path(options.get("build_path", "build"))
    asmPath = Path(options.get("asm_path", "asm"))
    dataPath = Path(options.get("data_path", "data"))
    srcPath = Path(options.get("src_path", "src"))

    overlays: list[OverlaySegment] = []

    prevSeg = yamlObj["segments"][0]
    for segment in yamlObj["segments"][1:]:
        if not isinstance(segment, dict):
            continue

        name = segment.get("name", "")
        if name.endswith("_reloc"):
            segmentName = prevSeg.get("name", "")
            assert f"{segmentName}_reloc" == name, f"{segmentName}, {name}"
            # print(segmentName)

            # get the path of the reloc
            relocsubs = segment["subsegments"]
            assert isinstance(relocsubs, list), name
            assert len(relocsubs) == 1, name
            relocpath = relocsubs[0][2]

            subsegments = prevSeg.get("subsegments")
            assert isinstance(subsegments, list)

            # build/src/overlays/actors/ovl_player_actor/ovl_player_actor_reloc.s

            files = []
            for sub in subsegments:
                if isinstance(sub, list):
                    assert len(sub) >= 3
                    # print(sub)
                    filetype = sub[1]
                    filepath = sub[2]
                elif isinstance(sub, dict):
                    # print(sub)
                    filetype = sub["type"]
                    filepath = sub["name"]
                else:
                    assert False

                # print(filetype, filepath)
                if filetype in {"asm", "hasm"}:
                    computedPath = buildPath / asmPath / f"{filepath}.o"
                elif filetype in {"data", "rodata", "bss"}:
                    computedPath = buildPath / asmPath / dataPath / f"{filepath}.{filetype}.o"
                elif filetype in {"c", ".data", ".rodata", ".bss"}:
                    computedPath = buildPath / srcPath / f"{filepath}.o"
                else:
                    assert False

                if computedPath not in files:
                    # print(computedPath)
                    files.append(computedPath)

            relocPath = buildPath / srcPath / relocpath
            # print(relocPath)
            overlayInfo = OverlaySegment(name, relocPath, files)
            overlays.append(overlayInfo)

        prevSeg = segment

    return overlays

def writePrerequisites(overlays: list[OverlaySegment], oListPath: Path):
    printVerbose("Writing prerequisites...")

    oListPath.parent.mkdir(parents=True, exist_ok=True)
    with oListPath.open("w") as f:
        for ovl in overlays:
            relocO = ovl.relocPath.with_suffix(".o")
            relocD = ovl.relocPath.with_suffix(".d")

            ovl.relocPath.parent.mkdir(parents=True, exist_ok=True)
            with relocD.open("w") as relocDFile:
                relocDFile.write(f"{relocO}:")
                for ovlFile in ovl.files:
                    relocDFile.write(f" \\\n    {ovlFile}")

                relocDFile.write("\n\n")

                for ovlFile in ovl.files:
                    relocDFile.write(f"{ovlFile}:\n")
            f.write(f"{relocO}\n")

def main():
    # Args from command line
    parser = argparse.ArgumentParser(description="")

    parser.add_argument("yaml", help="Path to the yaml file", type=Path)
    parser.add_argument("o_list_path", help="Path to write the list of reloc .o files", type=Path)

    args = parser.parse_args()

    yamlPath: Path = args.yaml
    oListPath: Path = args.o_list_path

    overlays = getOverlays(yamlPath)

    writePrerequisites(overlays, oListPath)

    return 0


if __name__ == "__main__":
    exit(main())
