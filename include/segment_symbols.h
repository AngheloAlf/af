#ifndef SEGMENT_SYMBOLS_H
#define SEGMENT_SYMBOLS_H

#include "ultra64.h"
#include "libc/stdint.h"
#include "other_types.h"


#define DECLARE_VRAM_SEGMENT(name) \
    extern u8 _ ## name ## SegmentStart[]; \
    extern u8 _ ## name ## SegmentEnd[]

#define DECLARE_ROM_SEGMENT(name) \
    extern u8 _ ## name ## SegmentRomStart[]; \
    extern u8 _ ## name ## SegmentRomEnd[]

#define DECLARE_DATA_SEGMENT(name)   \
    extern u8 _ ## name ## SegmentDataStart[]; \
    extern u8 _ ## name ## SegmentDataEnd[]; \
    extern u8 _ ## name ## SegmentDataSize[]

#define DECLARE_BSS_SEGMENT(name)   \
    extern u8 _ ## name ## SegmentBssStart[]; \
    extern u8 _ ## name ## SegmentBssEnd[]

#define DECLARE_SEGMENT(name) \
    DECLARE_VRAM_SEGMENT(name); \
    DECLARE_ROM_SEGMENT(name); \
    DECLARE_DATA_SEGMENT(name); \
    DECLARE_BSS_SEGMENT(name)

#define SEGMENT_VRAM_START(segment) (_ ## segment ## SegmentStart)
#define SEGMENT_VRAM_END(segment)   (_ ## segment ## SegmentEnd)
#define SEGMENT_VRAM_SIZE(segment)  ((uintptr_t)SEGMENT_VRAM_END(segment) - (uintptr_t)SEGMENT_VRAM_START(segment))

#define SEGMENT_ROM_START(segment) ((RomOffset) _ ## segment ## SegmentRomStart)
#define SEGMENT_ROM_END(segment)   ((RomOffset) _ ## segment ## SegmentRomEnd)
#define SEGMENT_ROM_SIZE(segment)  (SEGMENT_ROM_END(segment) - SEGMENT_ROM_START(segment))
#define SEGMENT_ROM_SIZE_ALT(segment)  ((size_t)(_ ## segment ## SegmentRomEnd - _ ## segment ## SegmentRomStart))

#define SEGMENT_DATA_SIZE_CONST(segment) ((RomOffset) _ ## segment ## SegmentDataSize)

#define SEGMENT_BSS_START(segment) (_ ## segment ## SegmentBssStart)
#define SEGMENT_BSS_END(segment)   (_ ## segment ## SegmentBssEnd)
#define SEGMENT_BSS_SIZE(segment)  ((uintptr_t)SEGMENT_BSS_END(segment) - (uintptr_t)SEGMENT_BSS_START(segment))


DECLARE_SEGMENT(header);

DECLARE_SEGMENT(ipl3);

DECLARE_SEGMENT(entry);

DECLARE_SEGMENT(boot);

DECLARE_SEGMENT(dmadata);

// DECLARE_SEGMENT();

DECLARE_SEGMENT(code);


// TODO: the rest of segments



#endif
