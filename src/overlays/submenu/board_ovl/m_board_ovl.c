#include "m_board_ovl.h"

#include "m_submenu.h"

#include "overlays/submenu/submenu_ovl/m_submenu_ovl.h"

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80888E90_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889028_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088910C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088913C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889198_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088920C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889288_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_808894E4_jp.s")

void func_80889514_jp(Submenu* submenu);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889514_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889574_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088973C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889878_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_808899E4_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889A9C_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889CD8_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_80889FB0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088A15C_jp.s")

void func_8088A230_jp(Submenu* submenu, struct Game_Play*);
#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088A230_jp.s")

void mBD_board_ovl_set_proc(Submenu* submenu) {
    struct_8085E9B0_unk_10670* temp_v0 = &submenu->unk_2C->unk_10670;

    temp_v0->unk_00 = func_80889514_jp;
    temp_v0->unk_04 = func_8088A230_jp;
}

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088A2D0_jp.s")

#pragma GLOBAL_ASM("asm/jp/nonmatchings/overlays/submenu/board_ovl/m_board_ovl/func_8088A604_jp.s")

//? func_8088A2D0_jp(Submenu*);                       /* extern */
//? func_8088A604_jp(Submenu*);                       /* extern */
extern UNK_TYPE B_8088AC00_jp;
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
