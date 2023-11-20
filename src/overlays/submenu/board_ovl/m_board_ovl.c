#include "m_board_ovl.h"

#include "m_submenu.h"

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

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088A2D0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088A604_jp.s")

//? func_8088A2D0_jp(Submenu*);                       /* extern */
//? func_8088A604_jp(Submenu*);                       /* extern */
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
