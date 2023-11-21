#include "m_board_ovl.h"

#include "libc/math.h"
#include "segment_symbols.h"
#include "m_submenu.h"
#include "z_std_dma.h"
#include "6B3DC0.h"
#include "6F5550.h"

#include "code_variables.h"

#include "overlays/gamestates/ovl_play/m_play.h"
#include "overlays/submenu/submenu_ovl/m_submenu_ovl.h"

extern Gfx* D_8088A7A0_jp[]; // lbl_806c7c60
extern Gfx* D_8088A8A0_jp[]; // lbl_806c8060
extern Gfx D_C000120[]; // lat_letter_mode
extern Gfx D_C000158[]; // lat_letter_sen_mode

extern Gfx D_C000040[]; // lat_hani_senT_model
extern Gfx D_C0001C0[]; // lat_point_mT_model

void mBD_roll_control(Submenu* submenu, struct_mSM_move_Move_arg1* arg1) {
    struct_8085E9B0_unk_106E0* temp_t0 = submenu->unk_2C->unk_106E0;
    struct_8085E9B0_unk_106E4* temp_a2 = submenu->unk_2C->unk_106E4;
    f32 temp_fa0;
    f32 temp_fv0;
    s32 temp_a0;
    s32 var_v1;
    f32 temp;

    if (temp_t0 == NULL) {
        return;
    }

    if (temp_a2->unk_00 == 1) {
        var_v1 = temp_t0->unk_22 + 2;
    } else {
        var_v1 = (temp_a2->unk_00 == 0) ? 0 : 9;
    }

    temp_a0 = var_v1 - temp_a2->unk_01;
    if (temp_a0 < -2) {
        temp_a2->unk_01 = var_v1 + 2;
        arg1->unk_20[1] = 1.0f;
    } else if (temp_a0 > 2) {
        temp_a2->unk_01 = var_v1 - 2;
        arg1->unk_20[1] = 1.0f;
    }

    temp_fa0 = (f32) ((temp_a2->unk_01 * 0x10) - 0x20);

    temp = temp_fa0 - arg1->unk_18[1];
    temp_fv0 = fabsf(temp);
    if (temp_fv0 > 0.1f) {
        if (temp_fv0 > 9.0f) {
            arg1->unk_20[1] *= 2.0f;
            if (arg1->unk_20[1] > 4.0f) {
                arg1->unk_20[1] = 4.0f;
            }
        } else if (temp_fv0 < 7.0f) {
            arg1->unk_20[1] *= 0.5f;
            if (arg1->unk_20[1] < 1.0f) {
                arg1->unk_20[1] = 1.0f;
            }
        }
        chase_f(&arg1->unk_18[1], temp_fa0, arg1->unk_20[1]);
    } else {
        arg1->unk_18[1] = temp_fa0;
    }
}

void mBD_roll_control2(struct_mSM_move_Move_arg1* arg0) {
    f32 temp_fv0 = arg0->unk_18[1] - arg0->unk_20[1];

    if (arg0->unk_20[1] < 1.0f) {
        arg0->unk_20[1] = 1.0f;
    }

    if (temp_fv0 > 0.0f) {
        arg0->unk_18[1] = temp_fv0;
        if (temp_fv0 > -15.0f) {
            arg0->unk_20[1] *= 2.0f;
            if (arg0->unk_20[1] > 16.0f) {
                arg0->unk_20[1] = 16.0f;
            }
        } else if (temp_fv0 < 31.0f) {
            arg0->unk_20[1] /= 2.0f;
            if (arg0->unk_20[1] < 1.0f) {
                arg0->unk_20[1] = 1.0f;

                //! FAKE
                label: ;
            }
        }
    } else {
        arg0->unk_18[1] = 0.0f;
        arg0->unk_20[1] = 0.0f;
    }
}

void mBD_move_Move(Submenu* submenu, struct_mSM_move_Move_arg1* arg1) {
    submenu->unk_2C->moveMove(submenu, arg1);
}

void mBD_move_Wait(Submenu* submenu, struct_mSM_move_Move_arg1* arg1) {
    if (getTrigger() & (A_BUTTON | B_BUTTON | START_BUTTON)) {
        submenu->unk_2C->moveChgBase(arg1, 4);
        sAdo_SysTrgStart(0x5F);
    }
}

void mBD_end_board(Submenu* submenu, struct_mSM_move_Move_arg1* arg1) {
    struct_mSM_move_Move_arg1* sp1C = &submenu->unk_2C->unk_10430;
    struct_8085E9B0* temp_v0 = submenu->unk_2C;

    temp_v0->moveChgBase(arg1, 4U);
    submenu->unk_2C->returnFunc(submenu, sp1C);
}

#if 0
void mBD_move_Play(Submenu* submenu, struct_mSM_move_Move_arg1* arg1) {
    if (submenu->unk_2C->unk_100D0[0x288].unk_30 == 4) {
        arg1->unk_04 = 3;
        submenu->unk_2C->unk_106E4->unk_01 = 2;
        mSM_open_submenu(submenu, SUBMENU_PROGRAM_15, 0, 0);
        return;
    }
    mBD_roll_control(arg1);
}
#else
void mBD_move_Play(Submenu* submenu, struct_mSM_move_Move_arg1*);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/mBD_move_Play.s")
#endif

#if 0
void mBD_move_Obey(Submenu* submenu, struct_mSM_move_Move_arg1* arg1) {
    s8* sp5C;
    struct_8085E9B0_unk_106E0* sp54;
    MailHeaderCommon* sp50;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    u8* sp40;
    u8 sp2C;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_v0;
    s8* temp_v1;
    struct_8085E9B0* temp_v0;
    struct_8085E9B0_unk_106E4* temp_s0;
    u8* var_a3;

    temp_v0 = submenu->unk_2C;
    temp_s0 = temp_v0->unk_106E4;
    temp_v1 = &temp_v0->unk_1042C[0x94];
    sp5C = temp_v1;
    mBD_roll_control2(arg1);
    if ((temp_v1->unk_4 == 0) && (temp_v1->unk_30 == 4)) {
        sp54 = submenu->unk_2C->unk_106E0;
        temp_v0_2 = temp_v1->unk_3C;
        if (temp_v0_2 == 0) {
            sp50 = &common_data.privateInfo->unk_3EE;
            mMl_copy_mail(temp_s0->unk_AC, &temp_s0->unk_08);
            temp_v0_3 = mMl_strlen(&temp_s0->unk_08.unk_2A.unk_6A, 0x10, 0x20);
            sp48 = temp_s0->unk_07 - temp_v0_3;
            sp4C = temp_v0_3;
            mem_copy(&sp2C, (u8* ) &temp_s0->unk_AC->unk_2A.unk_6A, 0x10U);
            var_a3 = &sp2C;
            var_v0 = 0;
            if (sp4C > 0) {
loop_5:
                if (*var_a3 == 0x20) {
                    var_v0 += 1;
                    var_a3 += 1;
                    if (var_v0 != sp4C) {
                        goto loop_5;
                    }
                }
            }
            sp40 = var_a3;
            sp44 = var_v0;
            mem_clear((u8* ) &temp_s0->unk_AC->unk_2A.unk_6A, 0x10U, 0x20U);
            if (sp48 < 0x10) {
                mem_copy((u8* ) (&temp_s0->unk_AC->unk_00.unk_00.unk_0.unk_0[sp48] + 0x94), var_a3, sp4C - var_v0);
            }
            sp50->unk_00 = (s8) temp_s0->unk_08.unk_27;
            mem_copy(sp50->unk_02, &temp_s0->unk_AC->unk_2A.unk_0, 0xAU);
            mem_copy(sp50->unk_0C, (u8* ) &temp_s0->unk_AC->unk_2A.unk_6A, 0x10U);
            temp_v0_4 = arg1->unk_3C;
            if (temp_v0_4 != -1) {
                mPr_SetPossessionItem(common_data.privateInfo, temp_v0_4, 0U, 0U);
                submenu->unk_2C->unk_106D0->unk_10C(submenu);
            }
            mBD_end_board(submenu, arg1);
        } else if (temp_v0_2 == 1) {
            mSM_open_submenu_new(submenu, SUBMENU_PROGRAM_10, 0, 0, (s32) &temp_s0->unk_08.unk_2A.unk_A);
            temp_s0->unk_00 = 1;
            temp_s0->unk_02 = 0;
            arg1->unk_04 = 1;
        } else {
            mBD_end_board(submenu, arg1);
        }
        if (sp54 != NULL) {
            sp54->unk_16 = 0;
            sp54->unk_20 = 0;
            sp54->unk_22 = 0;
        }
    }
}
#else
void mBD_move_Obey(Submenu* submenu, struct_mSM_move_Move_arg1*);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/mBD_move_Obey.s")
#endif

void mBD_move_End(Submenu* submenu, struct_mSM_move_Move_arg1* arg1) {
    submenu->unk_2C->moveEnd(submenu, arg1);
}

typedef void (*struct_8088ABA4_jp)(Submenu* submenu, struct_mSM_move_Move_arg1*);

extern struct_8088ABA4_jp ovl_move_proc_573[];

#if 0
struct_8088ABA4_jp ovl_move_proc_573[] = {
    mBD_move_Move,
    mBD_move_Play,
    mBD_move_Wait,
    mBD_move_Obey,
    mBD_move_End,
};
#endif

void mBD_board_ovl_move(Submenu* submenu) {
    struct_mSM_move_Move_arg1* temp_a1 = &submenu->unk_2C->unk_103E8;

    temp_a1->unk_0C(submenu);

    ovl_move_proc_573[temp_a1->unk_04](submenu, temp_a1);
}

void mBD_set_frame_dl(GraphicsContext* gfxCtx, struct_mSM_move_Move_arg1* arg1, f32 arg2, f32 arg3, struct_8085E9B0_unk_106E4* arg4) {
    s32 sp34 = arg4->unk_08.unk_29;

    gSegments[0xC] = OS_K0_TO_PHYSICAL(arg1->unk_28);

    Matrix_scale(16.0f, 16.0f, 1.0f, MTXMODE_NEW);
    Matrix_translate(arg2, arg3, 140.0f, MTXMODE_APPLY);

    OPEN_DISPS(gfxCtx);

    {
        Gfx* gfx = POLY_OPA_DISP;
        Gfx** temp_a1;

        gSPSegment(gfx++, 0x0C, arg1->unk_28);
        gSPMatrix(gfx++, _Matrix_to_Mtx_new(gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, D_C000120);

        gSPSegment(gfx++, 0x0C, (int)arg4->unk_B8 - arg4->unk_BC);
        gSPDisplayList(gfx++, D_8088A7A0_jp[sp34]);

        temp_a1 = &D_8088A8A0_jp[sp34];
        if (*temp_a1 != NULL) {
            gSPSegment(gfx++, 0x0C, arg1->unk_28);
            gSPDisplayList(gfx++, D_C000158);

            gSPSegment(gfx++, 0x0C, (uintptr_t)arg4->unk_B8 - arg4->unk_BC);
            gSPDisplayList(gfx++, *temp_a1);
        }

        gSPSegment(gfx++, 0x0C, arg1->unk_28);

        POLY_OPA_DISP = gfx;
    }

    CLOSE_DISPS(gfxCtx);
}

void mBD_set_point(Submenu* submenu, Game_Play* game_play, f32 arg2, f32 arg3) {
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    struct_8085E9B0_unk_106E4* temp_v0 = submenu->unk_2C->unk_106E4;

    submenu->unk_2C->unk_106E4->unk_B0 = ((f32) (temp_v0->unk_08.unk_27 + 3) * 12.0f) + arg2 + -96.0f;
    temp_v0->unk_B4 = arg3 - -76.0f;
    Matrix_scale(16.0f, 16.0f, 1.0f, MTXMODE_NEW);
    Matrix_translate(temp_v0->unk_B0, temp_v0->unk_B4, 140.0f, MTXMODE_APPLY);

    OPEN_DISPS(gfxCtx);
    {
        Gfx* gfx = POLY_OPA_DISP;
        s32 pad;

        gSPMatrix(gfx++, _Matrix_to_Mtx_new(gfxCtx), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gfx++, D_C000120);
        gSPDisplayList(gfx++, D_C0001C0);
        gSPDisplayList(gfx++, D_C000040);

        POLY_OPA_DISP = gfx;
    }
    CLOSE_DISPS(gfxCtx);
}

#if 0
void mBD_set_cursol(Submenu* submenu, Game_Play* game_play, f32 arg2, f32 arg3) {
    f32 var_fa0;
    f32 var_fv0;
    f32 var_fv1;
    s32 var_v0;
    struct_8085E9B0_unk_106E0* temp_t0;
    struct_8085E9B0_unk_106E4* temp_v1;

    temp_t0 = submenu->unk_2C->unk_106E0;
    temp_v1 = submenu->unk_2C->unk_106E4;

    if (temp_v1->unk_02 == 1) {
        mBD_set_point(submenu, game_play, arg2, arg3);
        return;
    }

    var_v0 = temp_t0->unk_20 - 1;
    if (temp_v1->unk_00 == 0) {
        if (temp_v1->unk_02 == 2) {
            var_v0 += 6;
        }
        var_fa0 = 0.0f;
        var_fv1 = 0.0f;
        var_fv0 = (f32) var_v0 + 0.3f;
    } else if (temp_v1->unk_00 == 1) {
        var_fa0 = 12.0f;
        var_fv0 = (f32) var_v0 + 0.3f;
        var_fv1 = (f32) (temp_t0->unk_22 + 1);
    } else {
        var_fa0 = 24.0f;
        var_fv1 = 7.0f;
        var_fv0 = (f32) ((var_v0 - temp_v1->unk_07) + 0x10) + 0.3f;
    }
    temp_t0->unk_2C(var_fa0, submenu, 64.0f + arg2 + (var_fv0 * 12.0f), 36.0f - ((arg3 - (var_fv1 * 16.0f)) - var_fa0));
}
#else
void mBD_set_cursol(Submenu* submenu, Game_Play* game_play, f32 arg2, f32 arg3);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/mBD_set_cursol.s")
#endif

typedef struct struct_8088AAA4_jp {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 unk_1;
    /* 0x2 */ u8 unk_2;
    /* 0x3 */ u8 unk_3;
} struct_8088AAA4_jp; // size = 0x4

void mBD_set_writing_footer(Submenu* submenu, Game_Play* game_play, f32 arg2, f32 arg3, struct_8088AAA4_jp* arg4) {
    struct_8085E9B0_unk_106E4* temp_v0 = submenu->unk_2C->unk_106E4;

    arg2 += 12.0f * (0x10 - temp_v0->unk_07);
    func_80090E98_jp(game_play, &temp_v0->unk_08.unk_2A.unk_6A, temp_v0->unk_07, arg2, arg3, arg4->unk_0, arg4->unk_1, arg4->unk_2, 0xFF, 0, 0, 1.0f, 1.0f, 0);
}

#ifdef NON_EQUIVALENT
void mBD_set_writing_body(Submenu* submenu, struct_mSM_move_Move_arg1* arg1, Game_Play* game_play, f32 arg3, f32* arg4, f32* arg5, f32* arg6, struct_8088AAA4_jp* arg7) {
    s32 var_s0;
    s32 var_s4;
    s32 var_s6;
    struct_8085E9B0_unk_106E4* temp_v0;
    s32 var_s1;
    char* var_s5;
    char* var_v0;

    temp_v0 = submenu->unk_2C->unk_106E4;

    var_s5 = temp_v0->unk_08.unk_2A.unk_0A;
    var_s1 = temp_v0->unk_06;
    for (var_s6 = 0; var_s6 < 6; var_s6++) {
        var_s4 = 0;

        for (var_s0 = 0, var_v0 = var_s5; (var_s0 < 0x10) && (var_s0 < var_s1); var_s0++, var_v0++) {
            if (*var_v0 == 0xCD) {
                var_s0 += 1;
                var_s4 = 1;
                break;
            }
        }

        if (var_s0 != 0) {
            s32 var_a2;

            if ((var_s4 != 0) && (arg1->unk_04 != 1)) {
                var_a2 = var_s0 - 1;
            } else {
                var_a2 = var_s0;
            }

            if (var_a2 != 0) {
                func_80090E98_jp(game_play, var_s5, var_a2, arg3, *arg4, arg7->unk_0, arg7->unk_1, arg7->unk_2, 0xFF, 0, 0, 1.0f, 1.0f, 0);
            }

            var_s1 -= var_s0;
            var_s5 = &var_s5[var_s0];
            if (var_s1 == 0) {
                if ((var_s6 != 5) && ((var_s4 != 0) || (var_s0 == 0x10))) {
                    *arg5 = arg3 - 160.0f;
                    *arg6 = 120.0f - (*arg4 + 16.0f);
                } else {
                    *arg5 = ((var_s0 * 12.0f) + arg3) - 160.0f;
                    *arg6 = 120.0f - *arg4;
                }
            }
        }

        *arg4 += 16.0f;
    }
}
#else
void mBD_set_writing_body(Submenu* submenu, struct_mSM_move_Move_arg1* arg1, Game_Play* game_play, f32 arg3, f32* arg4, f32* arg5, f32* arg6, struct_8088AAA4_jp* arg7);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/mBD_set_writing_body.s")
#endif

#if 0
void mBD_set_writing_header(Submenu* submenu, Game_Play* game_play, struct_mSM_move_Move_arg1* arg2, f32 arg3, f32 arg4, struct_8088AAA4_jp* arg5) {
    char sp68[0xA];
    f32 temp_fs0;
    s32 var_s2_2;
    struct_8085E9B0_unk_106E4* temp_s1;
    u8 temp_v0;
    u8 var_s2;

    temp_s1 = submenu->unk_2C->unk_106E4;
    if (arg2->unk_04 == 1) {
        if (temp_s1->unk_00 == 0) {
            var_s2 = 6;
        } else {
            var_s2 = temp_s1->unk_03;
        }

        func_80090E98_jp(game_play, &temp_s1->unk_08.unk_2A.unk_00[0], temp_s1->unk_08.unk_27, arg3, arg4, (s32) arg5->unk_0, (s32) arg5->unk_1, (s32) arg5->unk_2, 0xFF, 0, 0, 1.0f, 1.0f, 0);

        temp_fs0 = arg3 + ((f32) temp_s1->unk_08.unk_27 * 12.0f);
        func_80090E98_jp(game_play, &temp_s1->unk_08.unk_00.unk_00.unk_0.unk_0[0], (s32) var_s2, temp_fs0, arg4, 0xB9, 0, 0, 0xFF, 0, 0, 1.0f, 1.0f, 0);

        if (temp_s1->unk_08.unk_27 < 0xA) {
            func_80090E98_jp(game_play, (s8* ) (&temp_s1->unk_08.unk_2A.unk_00[temp_s1->unk_08.unk_27]), temp_s1->unk_05 - temp_s1->unk_08.unk_27, temp_fs0 + ((f32) var_s2 * 12.0f), arg4, (s32) arg5->unk_0, (s32) arg5->unk_1, (s32) arg5->unk_2, 0xFF, 0, 0, 1.0f, 1.0f, 0);
        }
    } else {
        temp_v0 = temp_s1->unk_08.unk_28;
        if ((temp_v0 == 2) || (temp_v0 == 3) || (temp_v0 == 5)) {
            mem_copy(&sp68, &temp_s1->unk_08.unk_2A.unk_00, 0xAU);
            var_s2_2 = 0xA;
        } else {
            mem_copy(&sp68, &temp_s1->unk_08.unk_2A.unk_00, (u32) temp_s1->unk_08.unk_27);
            mem_copy(&sp68[temp_s1->unk_08.unk_27], (u8* ) &temp_s1->unk_08, (u32) temp_s1->unk_03);

            if (temp_s1->unk_08.unk_27 < 0xA) {
                mem_copy(&sp68[temp_s1->unk_03 + temp_s1->unk_08.unk_27], &temp_s1->unk_08.unk_2A.unk_00[temp_s1->unk_08.unk_27], temp_s1->unk_05 - temp_s1->unk_08.unk_27);
            }
            var_s2_2 = temp_s1->unk_05 + temp_s1->unk_03;
        }
        func_80090E98_jp(game_play, sp68, var_s2_2, arg3, arg4, (s32) arg5->unk_0, (s32) arg5->unk_1, (s32) arg5->unk_2, 0xFF, 0, 0, 1.0f, 1.0f, 0);
    }
}
#else
void mBD_set_writing_header(Submenu* submenu, Game_Play* game_play, struct_mSM_move_Move_arg1* arg2, f32 arg3, f32 arg4, struct_8088AAA4_jp* arg5);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/mBD_set_writing_header.s")
#endif

extern struct_8088AAA4_jp D_8088AAA4_jp[];

#if 0
void mBD_set_character(Submenu* submenu, Game_Play* game_play, struct_mSM_move_Move_arg1* arg2, f32 arg3, f32 arg4) {
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    UNK_TYPE4* temp_v1; // sp34
    f32 temp_fv0; // sp30
    f32 temp_ft2;

    temp_fv0 = 64.0f + arg3;
    temp_ft2 = 36.0f - arg4;
    temp_v1 = &D_8088AAA4_jp[submenu->unk_2C->unk_106E4->unk_08.unk_29];
    sp40 = temp_ft2;
    mBD_set_writing_header(submenu, game_play, arg2, temp_fv0, temp_ft2, temp_v1);
    sp40 = sp40 + 28.0f;
    sp3C = temp_fv0 - 160.0f;
    sp38 = 120.0f - sp40;
    mBD_set_writing_body(submenu, arg2, game_play, temp_fv0, &sp40, &sp3C, &sp38, temp_v1);
    sp40 = sp40 + 12.0f;
    mBD_set_writing_footer(submenu, game_play, temp_fv0, sp40, temp_v1);
    if ((arg2->unk_04 == 1) && (submenu->unk_2C->unk_106E0 != NULL)) {
        mBD_set_cursol(submenu, game_play, arg3, arg4);
        submenu->unk_2C->unk_106E0->unk_28(submenu, game_play, sp3C, sp38);
    }
}
#else
void mBD_set_character(Submenu* submenu, Game_Play* game_play, struct_mSM_move_Move_arg1*, f32, f32);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/mBD_set_character.s")
#endif

void mBD_set_dl(Submenu* submenu, Game_Play* game_play, struct_mSM_move_Move_arg1* arg2) {
    GraphicsContext* gfxCtx = game_play->state.gfxCtx;
    f32 sp30 = arg2->unk_18[0];
    f32 sp2C = arg2->unk_18[1];

    mBD_set_frame_dl(gfxCtx, arg2, sp30, sp2C, submenu->unk_2C->unk_106E4);
    if ((arg2->unk_38 == 1) || (submenu->unk_2C->unk_106E4->unk_04 == 0)) {
        submenu->unk_2C->setCharMatrix(gfxCtx);
        mBD_set_character(submenu, game_play, arg2, sp30, sp2C);
    }
}

void mBD_board_ovl_draw(Submenu* submenu, struct Game_Play* game_play) {
    struct_mSM_move_Move_arg1* temp_a2 = &submenu->unk_2C->unk_103E8;

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
void mBD_board_ovl_init(Submenu* arg0) {
    struct_mSM_move_Move_arg1* temp_v1 = &arg0->unk_2C->unk_103E8; // sp5C
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
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/mBD_board_ovl_init.s")
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

//? mBD_board_ovl_init(Submenu*);                       /* extern */

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

    mBD_board_ovl_init(submenu);
    mBD_board_ovl_set_proc(submenu);
    func_8088A604_jp(submenu);
}
#else
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/mBD_board_ovl_construct.s")
#endif

void mBD_board_ovl_destruct(Submenu* submenu) {
    submenu->unk_2C->unk_106E4 = NULL;
}
