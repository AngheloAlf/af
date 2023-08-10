#!/usr/bin/env python3

# SPDX-FileCopyrightText: © 2023 ZeldaRET
# SPDX-License-Identifier: MIT

from util import options

from segtypes.n64.segment import N64Segment
from segtypes.common.data import CommonSegData


class N64SegReloc(N64Segment, CommonSegData):
    def get_linker_section(self) -> str:
        return ".ovl"

    def get_section_flags(self) -> str|None:
        return "a"

    def split(self, rom_bytes: bytes):
        super().split(rom_bytes)

        if self.type.startswith(".") and not options.opts.disassemble_all:
            return

        if self.spim_section is None or not self.should_self_split():
            return

        path = self.asm_out_path()

        path.parent.mkdir(parents=True, exist_ok=True)

        self.print_file_boundaries()

        with path.open("w", newline="\n") as f:
            f.write('.include "macro.inc"\n\n')
            preamble = options.opts.generated_s_preamble
            if preamble:
                f.write(preamble + "\n")

            f.write(f".section {self.get_linker_section()}")
            section_flags = self.get_section_flags()
            if section_flags:
                f.write(f', "{section_flags}"')
            f.write("\n\n")

            f.write(self.spim_section.disassemble())
