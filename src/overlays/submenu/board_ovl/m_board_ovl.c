#include "m_board_ovl.h"

#include "segment_symbols.h"
#include "m_submenu.h"
#include "z_std_dma.h"

#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/submenu/submenu_ovl/m_submenu_ovl.h"

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80888E90_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889028_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088910C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088913C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889198_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088920C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889288_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_808894E4_jp.s")

typedef void (*struct_8088ABA4_jp)(Submenu* submenu, struct_8085E9B0_unk_103E8*);

// ovl_move_proc$573 ?
extern struct_8088ABA4_jp D_8088ABA4_jp[];

void mBD_board_ovl_move(Submenu* submenu) {
    struct_8085E9B0_unk_103E8* temp_a1 = &submenu->unk_2C->unk_103E8;

    // TODO: This can be either (submenu) or (submenu, temp_a1)
    temp_a1->unk_0C(submenu);

    D_8088ABA4_jp[temp_a1->unk_04](submenu, temp_a1);
}

void func_80889574_jp(GraphicsContext* gfxCtx, struct_8085E9B0_unk_103E8*, f32, f32, struct_8085E9B0_unk_106E4*);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889574_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088973C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889878_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_808899E4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889A9C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889CD8_jp.s")

void func_80889FB0_jp(Submenu* submenu, Game_Play* game_play, struct_8085E9B0_unk_103E8*, f32, f32);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889FB0_jp.s")

void mBD_set_dl(Submenu* submenu, Game_Play* game_play, struct_8085E9B0_unk_103E8* arg2) {
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    f32 sp30 = arg2->unk_18;
    f32 sp2C = arg2->unk_1C;

    func_80889574_jp(gfxCtx, arg2, sp30, sp2C, submenu->unk_2C->unk_106E4);
    if ((arg2->unk_38 == 1) || (submenu->unk_2C->unk_106E4->unk_04 == 0)) {
        submenu->unk_2C->setCharMatrix(gfxCtx);
        func_80889FB0_jp(submenu, game_play, arg2, sp30, sp2C);
    }
}

void mBD_board_ovl_draw(Submenu* submenu, struct Game_Play* game_play) {
    struct_8085E9B0_unk_103E8* temp_a2 = &submenu->unk_2C->unk_103E8;

    // TODO: this can be either (submenu, game_play) or (submenu, game_play, temp_a2)
    temp_a2->unk_10(submenu, game_play);
    if (submenu->unk_2C->unk_106E4->unk_B8 != 0) {
        mBD_set_dl(submenu, game_play, temp_a2);
    }
}

void mBD_board_ovl_set_proc(Submenu* submenu) {
    struct_8085E9B0_unk_10670* temp_v0 = &submenu->unk_2C->unk_10670;

    temp_v0->unk_00 = mBD_board_ovl_move;
    temp_v0->unk_04 = mBD_board_ovl_draw;
}

#ifdef NON_MATCHING
extern u8 D_8088ABB8_jp;
extern u8 D_8088ABBC_jp;

// regalloc
void func_8088A2D0_jp(Submenu* arg0) {
    struct_8085E9B0_unk_103E8* temp_v1 = &arg0->unk_2C->unk_103E8; // sp5C
    struct_8085E9B0_unk_106E4* temp_s0 = arg0->unk_2C->unk_106E4;

    arg0->unk_2C->unk_106A0 = 0;

    temp_v1->unk_04 = 0;
    temp_v1->unk_34 = 5;

    temp_s0->unk_00 = 1;
    temp_s0->unk_01 = 2;
    temp_s0->unk_02 = 0;

    temp_s0->unk_AC = temp_v1->unk_40;

    if (temp_v1->unk_38 == 0) {
        MailHeaderCommon* sp54 = &common_data.privateInfo->unk_3EE;
        s32 sp50;

        temp_s0->unk_04 = 1;
        temp_v1->unk_30 = 1;
        mSM_open_submenu_new(arg0, SUBMENU_PROGRAM_13, 0, 0, (s32) &temp_s0->unk_08.unk_2A.unk_0A);
        mMl_init_mail(&temp_s0->unk_08, &common_data.privateInfo->unk_000);

        temp_s0->unk_08.unk_29 = common_data.privateInfo->inventory.pockets[temp_v1->unk_3C] - 0x2000;

        if (sp54->unk_00 == -1) {
            sp50 = mMl_strlen(common_data.privateInfo->unk_000.unk_0.unk_0, 6, 0x20);
            mem_copy(&temp_s0->unk_08.unk_2A.unk_00, &D_8088ABB8_jp, 3U);
            mem_copy(&temp_s0->unk_08.unk_2A.unk_6A, (u8* ) common_data.privateInfo, (u32) sp50);
            mem_copy(&temp_s0->unk_08.unk_2A.unk_6A[sp50], &D_8088ABBC_jp, 2U);
            temp_s0->unk_08.unk_27 = 0;
        } else {
            mem_copy(&temp_s0->unk_08.unk_2A.unk_00, sp54->unk_02, 0xAU);
            mem_copy(&temp_s0->unk_08.unk_2A.unk_6A, sp54->unk_0C, 0x10U);

            //! FAKE: & 0xFF
            //temp_s0->unk_08.unk_27 = sp54->unk_00 & 0xFF;
            temp_s0->unk_08.unk_27 = sp54->unk_00;
        }
    } else {
        mMl_copy_mail(&temp_s0->unk_08, temp_v1->unk_40);
        if (temp_v1->unk_38 == 1) {
            temp_v1->unk_30 = 2;
        } else {
            temp_v1->unk_30 = 1;
            mSM_open_submenu_new(arg0, SUBMENU_PROGRAM_13, 1, 0, (s32) &temp_s0->unk_08.unk_2A.unk_0A);
        }
        temp_s0->unk_04 = 0;
        temp_s0->unk_03 = mMl_strlen(temp_s0->unk_08.unk_00.unk_00.unk_0.unk_0, 6, 0x20);
    }

    temp_s0->unk_05 = mMl_strlen(&temp_s0->unk_08.unk_2A.unk_00, 0xA, 0x20);
    temp_s0->unk_07 = mMl_strlen(&temp_s0->unk_08.unk_2A.unk_6A, 0x10, 0x20);
    temp_s0->unk_06 = mMl_strlen(&temp_s0->unk_08.unk_2A.unk_0A, 0x60, 0x20);

    if (temp_s0->unk_08.unk_27 > 0xA) {
        temp_s0->unk_08.unk_27 = 0xA;
    }
    if (temp_s0->unk_05 < temp_s0->unk_08.unk_27) {
        temp_s0->unk_05 = temp_s0->unk_08.unk_27;
    }

    temp_s0->unk_B0 = 0.0f;
    temp_s0->unk_B4 = 76.0f;
    if (temp_s0->unk_07 != 0) {
        s32 var_v0; // sp4C
        char* var_a3; // sp48
        char sp34[0x11];

        var_a3 = sp34;

        mem_copy(sp34, &temp_s0->unk_08.unk_2A.unk_6A, 0x10U);

        for (var_v0 = 0; var_v0 < temp_s0->unk_07; var_v0++) {
            if (*var_a3 != 0x20) {
                break;
            }
            var_a3 += 1;
        }

        mem_clear(&temp_s0->unk_08.unk_2A.unk_6A, 0x10U, 0x20U);
        mem_copy(&temp_s0->unk_08.unk_2A.unk_6A, var_a3, temp_s0->unk_07 - var_v0);
    }
}
#else
// mBD_board_ovl_init
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088A2D0_jp.s")
#endif

extern uintptr_t D_8088A9A0_jp[];
extern UNK_TYPE D_C000000;
extern UNK_TYPE D_C000000_;

void func_8088A604_jp(Submenu* submenu) {
    struct_8085E9B0_unk_106E4* temp_v0 = submenu->unk_2C->unk_106E4;
    RomOffset temp = SEGMENT_ROM_START(segment_00AE3000);
    void* vram;

    temp_v0->unk_BC = D_8088A9A0_jp[temp_v0->unk_08.unk_29];

    vram = temp_v0->unk_B8;
    if (vram == NULL) {
        temp_v0->unk_B8 = submenu->unk_2C->unk_10000.unk_00;
        submenu->unk_2C->unk_10000.unk_00 = (uintptr_t)submenu->unk_2C->unk_10000.unk_00 + 0x1400;
    }
    vram = temp_v0->unk_B8;

    DmaMgr_RequestSyncDebug(vram, temp + temp_v0->unk_BC - (uintptr_t)&D_C000000, D_8088A9A0_jp[temp_v0->unk_08.unk_29+1] - temp_v0->unk_BC, "../m_board_ovl.c", 1228);
    temp_v0->unk_BC = temp_v0->unk_BC - (uintptr_t)&D_C000000_;
}

//? func_8088A2D0_jp(Submenu*);                       /* extern */

// board_ovl_data
extern struct_8085E9B0_unk_106E4 B_8088AC00_jp;

extern struct_func_8085D43C_jp_arg2 D_8088ABC0_jp;

#ifdef NON_EQUIVALENT
void mBD_board_ovl_construct(Submenu* submenu) {
    struct_8085E9B0* temp_v1;

    temp_v1 = submenu->unk_2C;
    if (temp_v1->unk_106E4 == NULL) {
        temp_v1->unk_106CC(submenu, (void** ) &temp_v1->unk_100D0[0x340], &D_8088ABC0_jp);
        temp_v1->unk_106E4 = &B_8088AC00_jp;
    }

    func_8088A2D0_jp(submenu);
    mBD_board_ovl_set_proc(submenu);
    func_8088A604_jp(submenu);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/mBD_board_ovl_construct.s")
#endif

void mBD_board_ovl_destruct(Submenu* submenu) {
    submenu->unk_2C->unk_106E4 = NULL;
}
