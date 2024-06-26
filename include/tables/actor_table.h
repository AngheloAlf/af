/**
 * Actor Table
 *
 * DEFINE_ACTOR should be used for normal actors
 *    - Argument 0: Name of the actor overlay segment in the spec (without the ovl_ part)
 *    - Argument 1: Enum value for this actor
 *    - Argument 2: Allocation type (normal, permanent or absolute)
 *
 * DEFINE_ACTOR_INTERNAL should be used for actors that aren't an overlay, with the same arguments as DEFINE_ACTOR
 *
 * DEFINE_ACTOR_UNSET is needed to define empty entries from the original game
 */
/* 0x00 */ DEFINE_ACTOR_INTERNAL(Player, ACTOR_PLAYER, ALLOCTYPE_NORMAL)
/* 0x01 */ DEFINE_ACTOR(BgItem, ACTOR_BG_ITEM, ALLOCTYPE_NORMAL)
/* 0x02 */ DEFINE_ACTOR(Sample, ACTOR_SAMPLE, ALLOCTYPE_NORMAL)
/* 0x03 */ DEFINE_ACTOR(Fieldm_Draw, ACTOR_FIELDM_DRAW, ALLOCTYPE_NORMAL)
/* 0x04 */ DEFINE_ACTOR(Field_Draw, ACTOR_FIELD_DRAW, ALLOCTYPE_NORMAL)
/* 0x05 */ DEFINE_ACTOR(Airplane, ACTOR_AIRPLANE, ALLOCTYPE_NORMAL)
/* 0x06 */ DEFINE_ACTOR(Room_Sunshine, ACTOR_ROOM_SUNSHINE, ALLOCTYPE_NORMAL)
/* 0x07 */ DEFINE_ACTOR(Lamp_Light, ACTOR_LAMP_LIGHT, ALLOCTYPE_NORMAL)
/* 0x08 */ DEFINE_ACTOR(Ev_Angler, ACTOR_EV_ANGLER, ALLOCTYPE_NORMAL)
/* 0x09 */ DEFINE_ACTOR(Ball, ACTOR_BALL, ALLOCTYPE_NORMAL)
/* 0x0A */ DEFINE_ACTOR(Haniwa, ACTOR_HANIWA, ALLOCTYPE_NORMAL)
/* 0x0B */ DEFINE_ACTOR(My_Room, ACTOR_MY_ROOM, ALLOCTYPE_NORMAL)
/* 0x0C */ DEFINE_ACTOR(Mbg, ACTOR_MBG, ALLOCTYPE_NORMAL)
/* 0x0D */ DEFINE_ACTOR(T_Tama, ACTOR_T_TAMA, ALLOCTYPE_NORMAL)
/* 0x0E */ DEFINE_ACTOR(BoxManager, ACTOR_BOX_MANAGER, ALLOCTYPE_NORMAL)
/* 0x0F */ DEFINE_ACTOR(BoxMove, ACTOR_BOX_MOVE, ALLOCTYPE_NORMAL)
/* 0x10 */ DEFINE_ACTOR(BoxTrick01, ACTOR_BOX_TRICK_01, ALLOCTYPE_NORMAL)
/* 0x11 */ DEFINE_ACTOR(Arrange_Room, ACTOR_ARRANGE_ROOM, ALLOCTYPE_NORMAL)
/* 0x12 */ DEFINE_ACTOR(Arrange_Furniture, ACTOR_ARRANGE_FURNITURE, ALLOCTYPE_NORMAL)
/* 0x13 */ DEFINE_ACTOR(TrainDoor, ACTOR_TRAIN_DOOR, ALLOCTYPE_NORMAL)
/* 0x14 */ DEFINE_ACTOR(T_Keitai, ACTOR_T_KEITAI, ALLOCTYPE_NORMAL)
/* 0x15 */ DEFINE_ACTOR(Halloween_Npc, ACTOR_HALLOWEEN_NPC, ALLOCTYPE_NORMAL)
/* 0x16 */ DEFINE_ACTOR(Ev_Pumpkin, ACTOR_EV_PUMPKIN, ALLOCTYPE_NORMAL)
/* 0x17 */ DEFINE_ACTOR(Ride_Off_Demo, ACTOR_RIDE_OFF_DEMO, ALLOCTYPE_NORMAL)
/* 0x18 */ DEFINE_ACTOR(Npc_Mamedanuki, ACTOR_NPC_MAMEDANUKI, ALLOCTYPE_NORMAL)
/* 0x19 */ DEFINE_ACTOR(Hanabi_Npc0, ACTOR_HANABI_NPC0, ALLOCTYPE_NORMAL)
/* 0x1A */ DEFINE_ACTOR(Hanabi_Npc1, ACTOR_HANABI_NPC1, ALLOCTYPE_NORMAL)
/* 0x1B */ DEFINE_ACTOR(Snowman, ACTOR_SNOWMAN, ALLOCTYPE_NORMAL)
/* 0x1C */ DEFINE_ACTOR(Npc_Post_Girl, ACTOR_NPC_POST_GIRL, ALLOCTYPE_NORMAL)
/* 0x1D */ DEFINE_ACTOR(Npc_Engineer, ACTOR_NPC_ENGINEER, ALLOCTYPE_NORMAL)
/* 0x1E */ DEFINE_ACTOR(Npc_Majin3, ACTOR_NPC_MAJIN3, ALLOCTYPE_NORMAL)
/* 0x1F */ DEFINE_ACTOR(Npc_Sleep_Obaba, ACTORNPC_SLEEP_OBABA, ALLOCTYPE_NORMAL)
/* 0x20 */ DEFINE_ACTOR(Npc, ACTOR_NPC, ALLOCTYPE_NORMAL)
/* 0x21 */ DEFINE_ACTOR(Effect_Control, ACTOR_EFFECT_CONTROL, ALLOCTYPE_NORMAL)
/* 0x22 */ DEFINE_ACTOR(Npc2, ACTOR_NPC2, ALLOCTYPE_NORMAL)
/* 0x23 */ DEFINE_ACTOR(Kamakura_Npc0, ACTOR_KAMAKURA_NPC0, ALLOCTYPE_NORMAL)
/* 0x24 */ DEFINE_ACTOR(Npc_Post_Man, ACTOR_NPC_POST_MAN, ALLOCTYPE_NORMAL)
/* 0x25 */ DEFINE_ACTOR(Shop_Design, ACTOR_SHOP_DESIGN, ALLOCTYPE_NORMAL)
/* 0x26 */ DEFINE_ACTOR(Quest_Manager, ACTOR_QUEST_MANAGER, ALLOCTYPE_NORMAL)
/* 0x27 */ DEFINE_ACTOR(MailBox, ACTOR_MAIL_BOX, ALLOCTYPE_NORMAL)
/* 0x28 */ DEFINE_ACTOR(House, ACTOR_HOUSE, ALLOCTYPE_NORMAL)
/* 0x29 */ DEFINE_ACTOR(Shop_Level, ACTOR_SHOP_LEVEL, ALLOCTYPE_NORMAL)
/* 0x2A */ DEFINE_ACTOR(Shop, ACTOR_SHOP, ALLOCTYPE_NORMAL)
/* 0x2B */ DEFINE_ACTOR(MyHouse, ACTOR_MY_HOUSE, ALLOCTYPE_NORMAL)
/* 0x2C */ DEFINE_ACTOR(Ev_Artist, ACTOR_EV_ARTIST, ALLOCTYPE_NORMAL)
/* 0x2D */ DEFINE_ACTOR(Ev_Broker, ACTOR_EV_BROKER, ALLOCTYPE_NORMAL)
/* 0x2E */ DEFINE_ACTOR(Ev_Designer, ACTOR_EV_DESIGNER, ALLOCTYPE_NORMAL)
/* 0x2F */ DEFINE_ACTOR(T_Umbrella, ACTOR_T_UMBRELLA, ALLOCTYPE_NORMAL)
/* 0x30 */ DEFINE_ACTOR(Npc_Shop_Master, ACTOR_NPC_SHOP_MASTER, ALLOCTYPE_NORMAL)
/* 0x31 */ DEFINE_ACTOR(Birth_Control, ACTOR_BIRTH_CONTROL, ALLOCTYPE_NORMAL)
/* 0x32 */ DEFINE_ACTOR(Shop_Manekin, ACTOR_SHOP_MANEKIN, ALLOCTYPE_NORMAL)
/* 0x33 */ DEFINE_ACTOR(Shop_Indoor, ACTOR_SHOP_INDOOR, ALLOCTYPE_NORMAL)
/* 0x34 */ DEFINE_ACTOR(Event_Manager, ACTOR_EVENT_MANAGER, ALLOCTYPE_NORMAL)
/* 0x35 */ DEFINE_ACTOR(Shop_Goods, ACTOR_SHOP_GOODS, ALLOCTYPE_NORMAL)
/* 0x36 */ DEFINE_ACTOR(BrShop, ACTOR_BR_SHOP, ALLOCTYPE_NORMAL)
/* 0x37 */ DEFINE_ACTOR(Weather, ACTOR_WEATHER, ALLOCTYPE_NORMAL)
/* 0x38 */ DEFINE_ACTOR(Post_Office, ACTOR_POST_OFFICE, ALLOCTYPE_NORMAL)
/* 0x39 */ DEFINE_ACTOR(Npc_Guide, ACTOR_NPC_GUIDE, ALLOCTYPE_NORMAL)
/* 0x3A */ DEFINE_ACTOR(Npc_Guide2, ACTOR_NPC_GUIDE2, ALLOCTYPE_NORMAL)
/* 0x3B */ DEFINE_ACTOR(Insect, ACTOR_INSECT, ALLOCTYPE_NORMAL)
/* 0x3C */ DEFINE_ACTOR(Station, ACTOR_STATION, ALLOCTYPE_NORMAL)
/* 0x3D */ DEFINE_ACTOR(Ev_CarpetPeddler, ACTOR_EV_CARPET_PEDDLER, ALLOCTYPE_NORMAL)
/* 0x3E */ DEFINE_ACTOR(Ev_KabuPeddler, ACTOR_EV_KABU_PEDDLER, ALLOCTYPE_NORMAL)
/* 0x3F */ DEFINE_ACTOR(Reserve, ACTOR_RESERVE, ALLOCTYPE_NORMAL)
/* 0x40 */ DEFINE_ACTOR(HandOverItem, ACTOR_HAND_OVER_ITEM, ALLOCTYPE_NORMAL)
/* 0x41 */ DEFINE_ACTOR(Npc_Conv_Master, ACTOR_NPC_CONV_MASTER, ALLOCTYPE_NORMAL)
/* 0x42 */ DEFINE_ACTOR(Npc_Super_Master, ACTOR_NPC_SUPER_MASTER, ALLOCTYPE_NORMAL)
/* 0x43 */ DEFINE_ACTOR(Npc_Depart_Master, ACTOR_NPC_DEPART_MASTER, ALLOCTYPE_NORMAL)
/* 0x44 */ DEFINE_ACTOR(Tools, ACTOR_TOOLS, ALLOCTYPE_NORMAL)
/* 0x45 */ DEFINE_ACTOR(Structure, ACTOR_STRUCTURE, ALLOCTYPE_NORMAL)
/* 0x46 */ DEFINE_ACTOR(Ev_Gypsy, ACTOR_EV_GYPSY, ALLOCTYPE_NORMAL)
/* 0x47 */ DEFINE_ACTOR(Npc_Police, ACTOR_NPC_POLICE, ALLOCTYPE_NORMAL)
/* 0x48 */ DEFINE_ACTOR(Train0, ACTOR_TRAIN0, ALLOCTYPE_NORMAL)
/* 0x49 */ DEFINE_ACTOR(Train1, ACTOR_TRAIN1, ALLOCTYPE_NORMAL)
/* 0x4A */ DEFINE_ACTOR(Npc_Station_Master, ACTOR_NPC_STATION_MASTER, ALLOCTYPE_NORMAL)
/* 0x4B */ DEFINE_ACTOR(Ev_Santa, ACTOR_EV_SANTA, ALLOCTYPE_NORMAL)
/* 0x4C */ DEFINE_ACTOR(Npc_Police2, ACTOR_NPC_POLICE2, ALLOCTYPE_NORMAL)
/* 0x4D */ DEFINE_ACTOR(Police_Box, ACTOR_POLICE_BOX, ALLOCTYPE_NORMAL)
/* 0x4E */ DEFINE_ACTOR(BgPoliceItem, ACTOR_BG_POLICE_ITEM, ALLOCTYPE_NORMAL)
/* 0x4F */ DEFINE_ACTOR(BgCherryItem, ACTOR_BG_CHERRY_ITEM, ALLOCTYPE_NORMAL)
/* 0x50 */ DEFINE_ACTOR(BgWinterItem, ACTOR_BG_WINTER_ITEM, ALLOCTYPE_NORMAL)
/* 0x51 */ DEFINE_ACTOR(BgXmasItem, ACTOR_BG_XMAS_ITEM, ALLOCTYPE_NORMAL)
/* 0x52 */ DEFINE_ACTOR(BgPostItem, ACTOR_BG_POST_ITEM, ALLOCTYPE_NORMAL)
/* 0x53 */ DEFINE_ACTOR(FallS, ACTOR_FALL_S, ALLOCTYPE_NORMAL)
/* 0x54 */ DEFINE_ACTOR(FallSESW, ACTOR_FALL_SESW, ALLOCTYPE_NORMAL)
/* 0x55 */ DEFINE_ACTOR(Ev_Broker2, ACTOR_EV_BROKER2, ALLOCTYPE_NORMAL)
/* 0x56 */ DEFINE_ACTOR(Broker_Design, ACTOR_BROKER_DESIGN, ALLOCTYPE_NORMAL)
/* 0x57 */ DEFINE_ACTOR(T_Utiwa, ACTOR_T_UTIWA, ALLOCTYPE_NORMAL)
/* 0x58 */ DEFINE_ACTOR(Psnowman, ACTOR_PSNOWMAN, ALLOCTYPE_NORMAL)
/* 0x59 */ DEFINE_ACTOR(My_Indoor, ACTOR_MY_INDOOR, ALLOCTYPE_NORMAL)
/* 0x5A */ DEFINE_ACTOR(Npc_Rcn_Guide, ACTOR_NPC_RCN_GUIDE, ALLOCTYPE_NORMAL)
/* 0x5B */ DEFINE_ACTOR(Intro_Demo, ACTOR_INTRO_DEMO, ALLOCTYPE_NORMAL)
/* 0x5C */ DEFINE_ACTOR(Shrine, ACTOR_SHRINE, ALLOCTYPE_NORMAL)
/* 0x5D */ DEFINE_ACTOR(Buggy, ACTOR_BUGGY, ALLOCTYPE_NORMAL)
/* 0x5E */ DEFINE_ACTOR(T_Hanabi, ACTOR_T_HANABI, ALLOCTYPE_NORMAL)
/* 0x5F */ DEFINE_ACTOR(Conveni, ACTOR_CONVENI, ALLOCTYPE_NORMAL)
/* 0x60 */ DEFINE_ACTOR(Super, ACTOR_SUPER, ALLOCTYPE_NORMAL)
/* 0x61 */ DEFINE_ACTOR(Depart, ACTOR_DEPART, ALLOCTYPE_NORMAL)
/* 0x62 */ DEFINE_ACTOR(Hanami_Npc0, ACTOR_HANAMI_NPC0, ALLOCTYPE_NORMAL)
/* 0x63 */ DEFINE_ACTOR(S_Car, ACTOR_S_CAR, ALLOCTYPE_NORMAL)
/* 0x64 */ DEFINE_ACTOR(Hanami_Npc1, ACTOR_HANAMI_NPC1, ALLOCTYPE_NORMAL)
/* 0x65 */ DEFINE_ACTOR(Npc_P_Sel, ACTOR_NPC_P_SEL, ALLOCTYPE_NORMAL)
/* 0x66 */ DEFINE_ACTOR(Npc_P_Sel2, ACTOR_NPC_P_SEL2, ALLOCTYPE_NORMAL)
/* 0x67 */ DEFINE_ACTOR(Npc_Rcn_Guide2, ACTOR_NPC_RCN_GUIDE2, ALLOCTYPE_NORMAL)
/* 0x68 */ DEFINE_ACTOR(Train_Window, ACTOR_TRAIN_WINDOW, ALLOCTYPE_NORMAL)
/* 0x69 */ DEFINE_ACTOR(Npc_Majin4, ACTOR_NPC_MAJIN4, ALLOCTYPE_NORMAL)
/* 0x6A */ DEFINE_ACTOR(Kamakura, ACTOR_KAMAKURA, ALLOCTYPE_NORMAL)
/* 0x6B */ DEFINE_ACTOR(Gyoei, ACTOR_GYOEI, ALLOCTYPE_NORMAL)
/* 0x6C */ DEFINE_ACTOR(Npc_Majin, ACTOR_NPC_MAJIN, ALLOCTYPE_NORMAL)
/* 0x6D */ DEFINE_ACTOR(T_NpcSao, ACTOR_T_NPC_SAO, ALLOCTYPE_NORMAL)
/* 0x6E */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_110)
/* 0x6F */ DEFINE_ACTOR(Uki, ACTOR_UKI, ALLOCTYPE_NORMAL)
/* 0x70 */ DEFINE_ACTOR(Npc_Majin2, ACTOR_NPC_MAJIN2, ALLOCTYPE_NORMAL)
/* 0x71 */ DEFINE_ACTOR(Normal_Npc, ACTOR_NORMAL_NPC, ALLOCTYPE_NORMAL)
/* 0x72 */ DEFINE_ACTOR(Set_Manager, ACTOR_SET_MANAGER, ALLOCTYPE_NORMAL)
/* 0x73 */ DEFINE_ACTOR(Set_Npc_Manager, ACTOR_SET_NPC_MANAGER, ALLOCTYPE_NORMAL)
/* 0x74 */ DEFINE_ACTOR(Npc_Shop_Mastersp, ACTOR_NPC_SHOP_MASTERSP, ALLOCTYPE_NORMAL)
/* 0x75 */ DEFINE_ACTOR(Room_Sunshine_Posthouse, ACTOR_ROOM_SUNSHINE_POSTHOUSE, ALLOCTYPE_NORMAL)
/* 0x76 */ DEFINE_ACTOR(Room_Sunshine_Police, ACTOR_ROOM_SUNSHINE_POLICE, ALLOCTYPE_NORMAL)
/* 0x77 */ DEFINE_ACTOR(Effectbg, ACTOR_EFFECTBG, ALLOCTYPE_NORMAL)
/* 0x78 */ DEFINE_ACTOR(Ev_Cherry_Manager, ACTOR_EV_CHERRY_MANAGER, ALLOCTYPE_NORMAL)
/* 0x79 */ DEFINE_ACTOR(Ev_Yomise, ACTOR_EV_YOMISE, ALLOCTYPE_NORMAL)
/* 0x7A */ DEFINE_ACTOR(Tokyoso_Npc0, ACTOR_TOKYOSO_NPC0, ALLOCTYPE_NORMAL)
/* 0x7B */ DEFINE_ACTOR(Tokyoso_Npc1, ACTOR_TOKYOSO_NPC1, ALLOCTYPE_NORMAL)
/* 0x7C */ DEFINE_ACTOR(Goza, ACTOR_GOZA, ALLOCTYPE_NORMAL)
/* 0x7D */ DEFINE_ACTOR(Radio, ACTOR_RADIO, ALLOCTYPE_NORMAL)
/* 0x7E */ DEFINE_ACTOR(Yatai, ACTOR_YATAI, ALLOCTYPE_NORMAL)
/* 0x7F */ DEFINE_ACTOR(Tokyoso_Control, ACTOR_TOKYOSO_CONTROL, ALLOCTYPE_NORMAL)
/* 0x80 */ DEFINE_ACTOR(Shop_Umbrella, ACTOR_SHOP_UMBRELLA, ALLOCTYPE_NORMAL)
/* 0x81 */ DEFINE_ACTOR(Gyo_Release, ACTOR_GTO_RELEASE, ALLOCTYPE_NORMAL)
/* 0x82 */ DEFINE_ACTOR(Tukimi, ACTOR_TUKIMI, ALLOCTYPE_NORMAL)
/* 0x83 */ DEFINE_ACTOR(Kamakura_Indoor, ACTOR_KAMAKURA_INDOOR, ALLOCTYPE_NORMAL)
/* 0x84 */ DEFINE_ACTOR(Ev_Miko, ACTOR_EV_MIKO, ALLOCTYPE_NORMAL)
/* 0x85 */ DEFINE_ACTOR(Gyo_Kage, ACTOR_GYO_KAGE, ALLOCTYPE_NORMAL)
/* 0x86 */ DEFINE_ACTOR(Mikuji, ACTOR_MIKUJI, ALLOCTYPE_NORMAL)
/* 0x87 */ DEFINE_ACTOR(House_Goki, ACTOR_HOUSE_GOKI, ALLOCTYPE_NORMAL)
/* 0x88 */ DEFINE_ACTOR(T_Cracker, ACTOR_T_CRACKER, ALLOCTYPE_NORMAL)
/* 0x89 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_137)
/* 0x8A */ DEFINE_ACTOR(T_Pistol, ACTOR_T_PISTOL, ALLOCTYPE_NORMAL)
/* 0x8B */ DEFINE_ACTOR(T_Flag, ACTOR_T_FLAG, ALLOCTYPE_NORMAL)
/* 0x8C */ DEFINE_ACTOR(T_Tumbler, ACTOR_T_TUMBLER, ALLOCTYPE_NORMAL)
/* 0x8D */ DEFINE_ACTOR(Tukimi_Npc0, ACTOR_TUKIMI_NPC0, ALLOCTYPE_NORMAL)
/* 0x8E */ DEFINE_ACTOR(Tukimi_Npc1, ACTOR_TUKIMI_NPC1, ALLOCTYPE_NORMAL)
/* 0x8F */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_143)
/* 0x90 */ DEFINE_ACTOR(Countdown_Npc0, ACTOR_COUNTDOWN_NPC0, ALLOCTYPE_NORMAL)
/* 0x91 */ DEFINE_ACTOR(Countdown_Npc1, ACTOR_COUNTDOWN_NPC1, ALLOCTYPE_NORMAL)
/* 0x92 */ DEFINE_ACTOR(Turi_Npc0, ACTOR_TURI_NPC0, ALLOCTYPE_NORMAL)
/* 0x93 */ DEFINE_ACTOR(Taisou_Npc0, ACTOR_TAISOU_NPC0, ALLOCTYPE_NORMAL)
/* 0x94 */ DEFINE_ACTOR(Count, ACTOR_COUNT, ALLOCTYPE_NORMAL)
/* 0x95 */ DEFINE_ACTOR(Garagara, ACTOR_GARAGARA, ALLOCTYPE_NORMAL)
/* 0x96 */ DEFINE_ACTOR(Tamaire_Npc0, ACTOR_TAMAIRE_NPC0, ALLOCTYPE_NORMAL)
/* 0x97 */ DEFINE_ACTOR(Tamaire_Npc1, ACTOR_TAMAIRE_NPC1, ALLOCTYPE_NORMAL)
/* 0x98 */ DEFINE_ACTOR(Hatumode_Npc0, ACTOR_HATUMODE_NPC0, ALLOCTYPE_NORMAL)
/* 0x99 */ DEFINE_ACTOR(Npc_Totakeke, ACTOR_NPC_TOTAKEKE, ALLOCTYPE_NORMAL)
/* 0x9A */ DEFINE_ACTOR(Count02, ACTOR_COUNT02, ALLOCTYPE_NORMAL)
/* 0x9B */ DEFINE_ACTOR(Hatumode_Control, ACTOR_HATUMODE_CONTROL, ALLOCTYPE_NORMAL)
/* 0x9C */ DEFINE_ACTOR(Tama, ACTOR_TAMA, ALLOCTYPE_NORMAL)
/* 0x9D */ DEFINE_ACTOR(Kago, ACTOR_KAGO, ALLOCTYPE_NORMAL)
/* 0x9E */ DEFINE_ACTOR(Turi, ACTOR_TURI, ALLOCTYPE_NORMAL)
/* 0x9F */ DEFINE_ACTOR(House_Clock, ACTOR_HOUSE_CLOCK, ALLOCTYPE_NORMAL)
/* 0xA0 */ DEFINE_ACTOR(Tunahiki_Control, ACTOR_TUNAHIKI, ALLOCTYPE_NORMAL)
/* 0xA1 */ DEFINE_ACTOR(Tunahiki_Npc0, ACTOR_TUNAHIKI_NPC0, ALLOCTYPE_NORMAL)
/* 0xA2 */ DEFINE_ACTOR(Tunahiki_Npc1, ACTOR_TUNAHIKI_NPC1, ALLOCTYPE_NORMAL)
/* 0xA3 */ DEFINE_ACTOR(Koinobori, ACTOR_KOINOBORI, ALLOCTYPE_NORMAL)
/* 0xA4 */ DEFINE_ACTOR(Bee, ACTOR_BEE, ALLOCTYPE_NORMAL)
/* 0xA5 */ DEFINE_ACTOR(Nameplate, ACTOR_NAMEPLATE, ALLOCTYPE_NORMAL)
/* 0xA6 */ DEFINE_ACTOR(Dump, ACTOR_DUMP, ALLOCTYPE_NORMAL)
/* 0xA7 */ DEFINE_ACTOR(Rope, ACTOR_ROPE, ALLOCTYPE_NORMAL)
/* 0xA8 */ DEFINE_ACTOR(Ev_Dozaemon, ACTOR_EV_DOZAEMON, ALLOCTYPE_NORMAL)
/* 0xA9 */ DEFINE_ACTOR(Windmill, ACTOR_WINDMILL, ALLOCTYPE_NORMAL)
/* 0xAA */ DEFINE_ACTOR(Lotus, ACTOR_LOTUS, ALLOCTYPE_NORMAL)
/* 0xAB */ DEFINE_ACTOR(Animal_Logo, ACTOR_ANIMAL_LOGO, ALLOCTYPE_NORMAL)
/* 0xAC */ DEFINE_ACTOR(Mikanbox, ACTOR_MIKANBOX, ALLOCTYPE_NORMAL)
/* 0xAD */ DEFINE_ACTOR(Douzou, ACTOR_DOUZOU, ALLOCTYPE_NORMAL)
/* 0xAE */ DEFINE_ACTOR(Npc_Rtc, ACTOR_NPC_RTC, ALLOCTYPE_NORMAL)
/* 0xAF */ DEFINE_ACTOR(Toudai, ACTOR_TOUDAI, ALLOCTYPE_NORMAL)
/* 0xB0 */ DEFINE_ACTOR(Npc_Restart, ACTOR_NPC_RESTART, ALLOCTYPE_NORMAL)
/* 0xB1 */ DEFINE_ACTOR(Npc_Majin5, ACTOR_NPC_MAJIN5, ALLOCTYPE_NORMAL)
/* 0xB2 */ DEFINE_ACTOR(Fuusen, ACTOR_FUUSEN, ALLOCTYPE_NORMAL)
/* 0xB3 */ DEFINE_ACTOR(Ev_Dokutu, ACTOR_EV_DOKUTU, ALLOCTYPE_NORMAL)
/* 0xB4 */ DEFINE_ACTOR(Dummy, ACTOR_DUMMY, ALLOCTYPE_NORMAL)
/* 0xB5 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_181)
/* 0xB6 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_182)
/* 0xB7 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_183)
/* 0xB8 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_184)
/* 0xB9 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_185)
/* 0xBA */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_186)
/* 0xBB */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_187)
/* 0xBC */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_188)
/* 0xBD */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_189)
/* 0xBE */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_190)
/* 0xBF */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_191)
/* 0xC0 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_192)
/* 0xC1 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_193)
/* 0xC2 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_194)
/* 0xC3 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_195)
/* 0xC4 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_196)
/* 0xC5 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_197)
/* 0xC6 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_198)
/* 0xC7 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_199)
/* 0xC8 */ DEFINE_ACTOR_UNSET(ACTOR_UNSET_200)
