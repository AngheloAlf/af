#ifndef M_SUBMENU_OVL
#define M_SUBMENU_OVL

#include "ultra64.h"
#include "other_types.h"
#include "m_mail.h"
#include "unk.h"

struct GraphicsContext;
struct Game_Play;
struct Submenu;
struct PreRender;
struct struct_func_8085CE18_jp_arg4;

// TODO: Consider merging this two typedefs into one
typedef void (*SubmenuProgramOverlayFunc)(struct Submenu*);

typedef void (*struct_8085E9B0_unk_10670_unk_00)(struct Submenu*);
typedef void (*struct_8085E9B0_unk_10670_unk_04)(struct Submenu*, struct Game_Play*);

typedef struct SubmenuProgramOverlay {
    /* 0x00 */ RomOffset vromStart;
    /* 0x00 */ RomOffset vromEnd;
    /* 0x08 */ void* vramStart;
    /* 0x0C */ void* vramEnd;
    /* 0x10 */ SubmenuProgramOverlayFunc construct; // name based on original function names
    /* 0x14 */ SubmenuProgramOverlayFunc destruct;  // name based on original function names
    /* 0x18 */ SubmenuProgramOverlayFunc set_proc;  // name based on original function names
    /* 0x1C */ s32 unk_1C;
} SubmenuProgramOverlay; // size = 0x20

typedef struct struct_func_8085C20C_jp_arg1 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x4];
    /* 0x04 */ u16 unk_04;
    /* 0x06 */ u16 unk_06;
    /* 0x08 */ UNK_TYPE1 unk_08[0xC];
    /* 0x14 */ TexturePtr unk_14;
    /* 0x18 */ UNK_TYPE1 unk_18[0x8];
    /* 0x20 */ TexturePtr unk_20;
} struct_func_8085C20C_jp_arg1; // size >= 0x24

typedef struct struct_mSM_move_Move_arg1 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08; // SubmenuProgramId enum, not used directly to avoid possible circular dependencies
    /* 0x0C */ struct_8085E9B0_unk_10670_unk_00 unk_0C;
    /* 0x10 */ struct_8085E9B0_unk_10670_unk_04 unk_10;
    /* 0x14 */ UNK_TYPE unk_14;
    /* 0x18 */ f32 unk_18[2];
    /* 0x20 */ f32 unk_20[2];
    /* 0x28 */ void* unk_28;
    /* 0x2C */ UNK_TYPE4 unk_2C;
    /* 0x30 */ UNK_TYPE4 unk_30;
    /* 0x34 */ u32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ Mail* unk_40;
} struct_mSM_move_Move_arg1; // size >= 0x44

typedef struct struct_func_8085D43C_jp_arg2 {
    /* 0x0 */ RomOffset vromStart;
    /* 0x4 */ RomOffset vromEnd;
} struct_func_8085D43C_jp_arg2; // size = 0x8

typedef struct struct_8085E9B0_unk_10000 {
    /* 0x10000 */ void* unk_00;
    /* 0x10004 */ s32 unk_04;
    /* 0x10008 */ void* unk_08;
    /* 0x1000C */ UNK_TYPE1 unk_0C[0x58];
    /* 0x10064 */ UNK_TYPE4 unk_64;
    /* 0x10068 */ SubmenuProgramOverlay* unk_68[UNK_SIZE];
} struct_8085E9B0_unk_10000; // size >= 0x6C

typedef struct struct_8085E9B0_unk_10088 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ UNK_TYPE1 unk_04[0x4];
    /* 0x08 */ UNK_TYPE4 unk_08;
    /* 0x0C */ struct_8085E9B0_unk_10670_unk_00 unk_0C;
    /* 0x10 */ struct_8085E9B0_unk_10670_unk_04 unk_10;
    /* 0x14 */ UNK_TYPE4 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ UNK_TYPE1 unk_28[0x10];
    /* 0x38 */ UNK_TYPE4 unk_38;
    /* 0x3C */ UNK_TYPE4 unk_3C;
    /* 0x40 */ UNK_TYPE4 unk_40;
    /* 0x44 */ UNK_TYPE4 unk_44;
} struct_8085E9B0_unk_10088; // size = 0x48

typedef struct struct_8085E9B0_unk_10670 {
    /* 0x00 */ struct_8085E9B0_unk_10670_unk_00 unk_00;
    /* 0x04 */ struct_8085E9B0_unk_10670_unk_04 unk_04;
    /* 0x08 */ UNK_FUN_PTR unk_08;
    /* 0x0C */ UNK_FUN_PTR unk_0C;
    /* 0x10 */ UNK_FUN_PTR unk_10;
    /* 0x14 */ UNK_FUN_PTR unk_14;
    /* 0x18 */ UNK_TYPE1 unk_18[0x4];
    /* 0x1C */ UNK_TYPE4 unk_1C;
    /* 0x20 */ UNK_TYPE4 unk_20;
    /* 0x24 */ s16 unk_24;
    /* 0x26 */ u16 unk_26;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
} struct_8085E9B0_unk_10670; // size >= 0x30

typedef struct struct_8085E9B0_unk_106E4 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03;
    /* 0x04 */ u8 unk_04;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ Mail unk_08;
    /* 0xAC */ Mail* unk_AC;
    /* 0xB0 */ f32 unk_B0;
    /* 0xB4 */ f32 unk_B4;
    /* 0xB8 */ void* unk_B8;
    /* 0xBC */ unsigned int unk_BC; // TODO: unsigned int is used as a placeholder
} struct_8085E9B0_unk_106E4; // size = 0xC0

typedef UNK_RET (*struct_8085E9B0_unk_106E0_unk_28)(struct Submenu*, struct Game_Play*, f32, f32);
typedef UNK_RET (*struct_8085E9B0_unk_106E0_unk_2C)(f32, struct Submenu*, f32, f32);

typedef struct struct_8085E9B0_unk_106E0 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x20];
    /* 0x20 */ s16 unk_20;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ UNK_TYPE1 unk_24[0x4];
    /* 0x28 */ struct_8085E9B0_unk_106E0_unk_28 unk_28;
    /* 0x2C */ struct_8085E9B0_unk_106E0_unk_2C unk_2C;
} struct_8085E9B0_unk_106E0; // size >= 0x30

typedef void (*struct_8085E9B0_unk_106A4)(struct Submenu*, struct_mSM_move_Move_arg1*);
typedef void (*struct_8085E9B0_unk_106A8)(struct Submenu*, struct_mSM_move_Move_arg1*);
typedef void (*struct_8085E9B0_unk_106AC)(struct Submenu*, struct_mSM_move_Move_arg1*);
typedef void (*struct_8085E9B0_unk_106B0)(struct_mSM_move_Move_arg1*, u32);
typedef void (*struct_8085E9B0_unk_106B4)(struct GraphicsContext*);
typedef void (*struct_8085E9B0_unk_106B8)(struct GraphicsContext*, struct PreRender*, s32, s32, s32);
typedef void (*struct_8085E9B0_unk_106BC)(struct GraphicsContext*, struct struct_func_8085C20C_jp_arg1*, f32, f32, s16);
typedef void (*struct_8085E9B0_unk_106C0)(struct GraphicsContext*, f32, f32, f32, u16, s32, s32, s32, s32);
typedef void (*struct_8085E9B0_unk_106C4)(struct GraphicsContext*, f32, f32, f32, struct struct_func_8085CE18_jp_arg4*, s32, s32);
typedef void (*struct_8085E9B0_unk_106C8)(struct Submenu*, struct GraphicsContext*, s32);
typedef void (*struct_8085E9B0_unk_106CC)(struct Submenu*, void**, struct_func_8085D43C_jp_arg2*);

typedef struct struct_8085E9B0 {
    /* 0x00000 */ UNK_TYPE1 unk_00000[0x10000];
    /* 0x10000 */ struct_8085E9B0_unk_10000 unk_10000;
    /* 0x1006C */ UNK_TYPE1 unk_1006C[0x1C];
    /* 0x10088 */ struct_8085E9B0_unk_10088 unk_10088[UNK_SIZE];
    /* 0x100D0 */ UNK_TYPE1 unk_100D0[0x318];
    /* 0x103E8 */ struct_mSM_move_Move_arg1 unk_103E8;
    /* 0x1042C */ UNK_TYPE1 unk_1042C[0x4];
    /* 0x10430 */ struct_mSM_move_Move_arg1 unk_10430;
    /* 0x10474 */ UNK_TYPE1 unk_10474[0x1FC];
    /* 0x10670 */ struct_8085E9B0_unk_10670 unk_10670;
    /* 0x106A0 */ UNK_TYPE4 unk_106A0;
    /* 0x106A4 */ struct_8085E9B0_unk_106A4 returnFunc;
    /* 0x106A8 */ struct_8085E9B0_unk_106A8 moveMove;
    /* 0x106AC */ struct_8085E9B0_unk_106AC moveEnd;
    /* 0x106B0 */ struct_8085E9B0_unk_106B0 moveChgBase;
    /* 0x106B4 */ struct_8085E9B0_unk_106B4 setCharMatrix;
    /* 0x106B8 */ struct_8085E9B0_unk_106B8 cbufCopy;
    /* 0x106BC */ struct_8085E9B0_unk_106BC setDrawMode;
    /* 0x106C0 */ struct_8085E9B0_unk_106C0 drawItem;
    /* 0x106C4 */ struct_8085E9B0_unk_106C4 drawMail;
    /* 0x106C8 */ struct_8085E9B0_unk_106C8 setupView;
    /* 0x106CC */ struct_8085E9B0_unk_106CC unk_106CC;
    /* 0x106D0 */ UNK_TYPE1 unk_106D0[0x10];
    /* 0x106E0 */ struct_8085E9B0_unk_106E0* unk_106E0;
    /* 0x106E4 */ struct_8085E9B0_unk_106E4* unk_106E4;
    /* 0x106E8 */ UNK_TYPE1 unk_106E8[0x44];
    /* 0x1072C */ Mtx* unk_1072C;
} struct_8085E9B0; // size = 0x10730

void mSM_menu_ovl_init(struct Submenu* submenu);

#endif
