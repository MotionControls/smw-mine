#include "consts.h"
#include "funcs.h"
#include "smw_rtl.h"
#include "variables.h"
#include "assets/smw_assets.h"

static FuncU8 *const kSpr0C5_BigBooBoss_BigBooBossPtrs[7] = {
    &Spr0C5_BigBooBoss_StoppedBeforeFadeIn,
    &Spr0C5_BigBooBoss_FadingIn,
    &Spr0C5_BigBooBoss_FloatingAroundWhileVisible,
    &Spr0C5_BigBooBoss_Hurt,
    &Spr0C5_BigBooBoss_FadingOut,
    &Spr0C5_BigBooBoss_FloatingAroundWhileInvisible,
    &Spr0C5_BigBooBoss_Dying,
};

static FuncU8 *const kUnk_388d9[3] = {
    &Spr0BE_Swooper_Waiting,
    &Spr0BE_Swooper_Swooping,
    &Spr0BE_Swooper_FlyStraight,
};

static FuncU8 *const kUnk_3a32c[10] = {
    &Spr0A0_ActivateBowserBattle_State00_InitialDescent,
    &Spr0A0_ActivateBowserBattle_State01_SwoopOut,
    &Spr0A0_ActivateBowserBattle_State02_SwoopIn,
    &Spr0A0_ActivateBowserBattle_State03_DropFireballs,
    &Spr0A0_ActivateBowserBattle_State04_RiseUpToDie,
    &Spr0A0_ActivateBowserBattle_State05_ClownCarMalfunction,
    &Spr0A0_ActivateBowserBattle_State06_DropPeachAndFlyOff,
    &Spr0A0_ActivateBowserBattle_State07_Phase1,
    &Spr0A0_ActivateBowserBattle_State08_Phase2,
    &Spr0A0_ActivateBowserBattle_State09_Phase3,  //
};

static FuncU8 *const kSpr07C_PrincessPeach_PrincessPeachPtrs[8] = {
    &Spr07C_PrincessPeach_FloatingDown, &Spr07C_PrincessPeach_WaitAfterFall, &Spr07C_PrincessPeach_WalkTowardsBro,
    &Spr07C_PrincessPeach_StandByBro,   &Spr07C_PrincessPeach_KissBro,       &Spr07C_PrincessPeach_DisplayMessage,
    &Spr07C_PrincessPeach_FadeText,
    &Spr07C_PrincessPeach_Fireworks,  //
};

static FuncU8 *const kSpr07A_Fireworks_FireworkPtrs[4] = {
    &Spr07A_Fireworks_InitialFire,
    &Spr07A_Fireworks_ShootUp,
    &Spr07A_Fireworks_Explode,
    &Spr07A_Fireworks_FadeAway,
};

static FuncU8 *const kUnk_3cc29[7] = {
    &Spr029_KoopaKid_WendyLemmy_State00_InPipe,        &Spr029_KoopaKid_WendyLemmy_State01_Rising,
    &Spr029_KoopaKid_WendyLemmy_State02_OutOfPipe,     &Spr029_KoopaKid_WendyLemmy_State03_Descending,
    &Spr029_KoopaKid_WendyLemmy_State04_Hurt,          &Spr029_KoopaKid_WendyLemmy_State05_Falling,
    &Spr029_KoopaKid_WendyLemmy_State06_SinkingInLava,
};

static const uint8 kSpr0AB_Rex_StompSounds[7] = { 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19,  };
static const uint8 kSpr01B_Football_DATA_038007[7] = { 0xf0, 0xf8, 0xfc, 0x0, 0x4, 0x8, 0x10,  };
static const uint8 kSpr01B_Football_DATA_03800E[4] = { 0xa0, 0xd0, 0xc0, 0xd0,  };
static const uint8 kSpr0C5_BigBooBoss_XAcceleration[2] = { 0xff, 0x1,  };
static const uint8 kSpr0C5_BigBooBoss_MaxXSpeed[2] = { 0xf0, 0x10,  };
static const uint8 kSpr0C5_BigBooBoss_MaxYSpeed[2] = { 0xc, 0xf4,  };
static const uint8 kSpr0C5_BigBooBoss_YAcceleration[2] = { 0x1, 0xff,  };
static const uint8 kSpr0C5_BigBooBoss_DATA_038102[4] = { 0x1, 0x2, 0x2, 0x1,  };
static const uint8 kNormalSpriteBooGFXRt_BigBooXDisp[80] = { 0x8, 0x8, 0x20, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x20, 0x30, 0x30, 0x30, 0x30, 0xfd, 0xc, 0xc, 0x27, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x10, 0x10, 0x1f, 0x20, 0x20, 0x1f, 0x2e, 0x2e, 0x2c, 0x2c, 0xfb, 0x12, 0x12, 0x30, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x10, 0x10, 0x1f, 0x20, 0x20, 0x1f, 0x2e, 0x2e, 0x2e, 0x2e, 0xf8, 0x11, 0xff, 0x8, 0x8, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x20, 0x30, 0x30, 0x30, 0x30,  };
static const uint8 kNormalSpriteBooGFXRt_BigBooYDisp[40] = { 0x12, 0x22, 0x18, 0x0, 0x10, 0x20, 0x30, 0x0, 0x10, 0x20, 0x30, 0x0, 0x10, 0x20, 0x30, 0x0, 0x10, 0x20, 0x30, 0x18, 0x16, 0x16, 0x12, 0x22, 0x0, 0x10, 0x20, 0x30, 0x0, 0x10, 0x20, 0x30, 0x0, 0x10, 0x20, 0x30, 0x0, 0x10, 0x20, 0x30,  };
static const uint8 kNormalSpriteBooGFXRt_BigBooTiles[80] = { 0xc0, 0xe0, 0xe8, 0x80, 0xa0, 0xa0, 0x80, 0x82, 0xa2, 0xa2, 0x82, 0x84, 0xa4, 0xc4, 0xe4, 0x86, 0xa6, 0xc6, 0xe6, 0xe8, 0xc0, 0xe0, 0xe8, 0x80, 0xa0, 0xa0, 0x80, 0x82, 0xa2, 0xa2, 0x82, 0x84, 0xa4, 0xc4, 0xe4, 0x86, 0xa6, 0xc6, 0xe6, 0xe8, 0xc0, 0xe0, 0xe8, 0x80, 0xa0, 0xa0, 0x80, 0x82, 0xa2, 0xa2, 0x82, 0x84, 0xa4, 0xa4, 0x84, 0x86, 0xa6, 0xa6, 0x86, 0xe8, 0xe8, 0xe8, 0xc2, 0xe2, 0x80, 0xa0, 0xa0, 0x80, 0x82, 0xa2, 0xa2, 0x82, 0x84, 0xa4, 0xc4, 0xe4, 0x86, 0xa6, 0xc6, 0xe6,  };
static const uint8 kNormalSpriteBooGFXRt_BigBooProp[80] = { 0x0, 0x0, 0x40, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x80, 0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  };
static const uint8 kSpr0C4_GreyFallingPlatform_XDisp[4] = { 0x0, 0x10, 0x20, 0x30,  };
static const uint8 kSpr0C4_GreyFallingPlatform_Tiles[4] = { 0x60, 0x61, 0x61, 0x62,  };
static const uint8 kSpr0C2_Blurp_MaxYSpeed[2] = { 0x4, 0xfc,  };
static const uint8 kSpr0C2_Blurp_XSpeed[2] = { 0x8, 0xf8,  };
static const uint8 kSpr0C2_Blurp_YAcceleration[2] = { 0x1, 0xff,  };
static const uint8 kSpr0C3_PorcuPuffer_PorcuPuffAccel[2] = { 0x1, 0xff,  };
static const uint8 kSpr0C3_PorcuPuffer_PorcuPuffMaxSpeed[2] = { 0x10, 0xf0,  };
static const uint8 kSpr0C3_PorcuPuffer_PocruPufferDispX[8] = { 0xf8, 0x8, 0xf8, 0x8, 0x8, 0xf8, 0x8, 0xf8,  };
static const uint8 kSpr0C3_PorcuPuffer_PocruPufferDispY[4] = { 0xf8, 0xf8, 0x8, 0x8,  };
static const uint8 kSpr0C3_PorcuPuffer_PocruPufferTiles[8] = { 0x86, 0xc0, 0xa6, 0xc2, 0x86, 0xc0, 0xa6, 0x8a,  };
static const uint8 kSpr0C3_PorcuPuffer_PocruPufferGfxProp[8] = { 0xd, 0xd, 0xd, 0xd, 0x4d, 0x4d, 0x4d, 0x4d,  };
static const uint8 kSpr0C1_WingedPlatform_FlyingBlockSpeedY[2] = { 0x8, 0xf8,  };
static const uint8 kSpr0C1_WingedPlatform_XDisp[10] = { 0x0, 0x10, 0x20, 0xf2, 0x2e, 0x0, 0x10, 0x20, 0xfa, 0x2e,  };
static const uint8 kSpr0C1_WingedPlatform_YDisp[10] = { 0x0, 0x0, 0x0, 0xf6, 0xf6, 0x0, 0x0, 0x0, 0xfe, 0xfe,  };
static const uint8 kSpr0C1_WingedPlatform_Tiles[10] = { 0x40, 0x40, 0x40, 0xc6, 0xc6, 0x40, 0x40, 0x40, 0x5d, 0x5d,  };
static const uint8 kSpr0C1_WingedPlatform_Prop[10] = { 0x32, 0x32, 0x32, 0x72, 0x32, 0x32, 0x32, 0x32, 0x72, 0x32,  };
static const uint8 kSpr0C1_WingedPlatform_TileSize[10] = { 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x0, 0x0,  };
static const uint8 kSpr0C0_SinkingLavaPlatform_LavaPlatTiles[3] = { 0x85, 0x86, 0x85,  };
static const uint8 kSpr0C0_SinkingLavaPlatform_DATA_038737[3] = { 0x43, 0x3, 0x3,  };
static const uint8 kSpr0BF_MegaMole_MegaMoleSpeed[2] = { 0x10, 0xf0,  };
static const uint8 kSpr0BF_MegaMole_TileDispX[8] = { 0x0, 0x10, 0x0, 0x10, 0x10, 0x0, 0x10, 0x0,  };
static const uint8 kSpr0BF_MegaMole_TileDispY[4] = { 0xf0, 0xf0, 0x0, 0x0,  };
static const uint8 kSpr0BF_MegaMole_Tiles[8] = { 0xc6, 0xc8, 0xe6, 0xe8, 0xca, 0xcc, 0xea, 0xec,  };
static const uint8 kSpr0BE_Swooper_Tiles[3] = { 0xae, 0xc0, 0xe8,  };
static const uint8 kSpr0BE_Swooper_MaxXSpeed[2] = { 0x10, 0xf0,  };
static const uint8 kSpr0BE_Swooper_XAcceleration[2] = { 0x1, 0xff,  };
static const uint8 kSpr0BD_SlidingNakedBlueKoopa_MaxXSpeed[2] = { 0x20, 0xe0,  };
static const uint8 kSpr0BD_SlidingNakedBlueKoopa_XAcceleration[2] = { 0x2, 0xfe,  };
static const uint8 kSpr0BC_BowserStatue_XSpeed[2] = { 0x10, 0xf0,  };
static const uint8 kSpr0BC_BowserStatue_FireSpawnXDispXLo[2] = { 0x10, 0xf0,  };
static const uint8 kSpr0BC_BowserStatue_FireSpawnXDispXHi[2] = { 0x0, 0xff,  };
static const uint8 kSpr0BC_BowserStatue_XDisp[6] = { 0x8, 0xf8, 0x0, 0x0, 0x8, 0x0,  };
static const uint8 kSpr0BC_BowserStatue_YDisp[3] = { 0x10, 0xf8, 0x0,  };
static const uint8 kSpr0BC_BowserStatue_Tiles[6] = { 0x56, 0x30, 0x41, 0x56, 0x30, 0x35,  };
static const uint8 kSpr0BC_BowserStatue_TileSize[3] = { 0x0, 0x2, 0x2,  };
static const uint8 kSpr0BC_BowserStatue_Prop[6] = { 0x0, 0x0, 0x0, 0x40, 0x40, 0x40,  };
static const uint8 kSpr0B7_CarrotTopLiftUpperRight_DATA_038BAA[128] = { 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x1f, 0x1e, 0x1d, 0x1c, 0x1b, 0x1a, 0x19, 0x18, 0x17, 0x16, 0x15, 0x14, 0x13, 0x12, 0x11, 0x10, 0xf, 0xe, 0xd, 0xc, 0xb, 0xa, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,  };
static const uint8 kSpr0B7_CarrotTopLiftUpperRight_DATA_038C2A[4] = { 0x0, 0xf8, 0x0, 0x8,  };
static const uint8 kSpr0B7_CarrotTopLiftUpperRight_XDisp[6] = { 0x10, 0x0, 0x10, 0x0, 0x10, 0x0,  };
static const uint8 kSpr0B7_CarrotTopLiftUpperRight_YDisp[6] = { 0x0, 0x10, 0x10, 0x0, 0x10, 0x10,  };
static const uint8 kSpr0B7_CarrotTopLiftUpperRight_Tiles[6] = { 0xe4, 0xe0, 0xe2, 0xe4, 0xe0, 0xe2,  };
static const uint8 kSpr0B7_CarrotTopLiftUpperRight_Prop[6] = { 0xb, 0xb, 0xb, 0x4b, 0x4b, 0x4b,  };
static const uint8 kSpr0B9_MessageBox_DATA_038D66[9] = { 0x0, 0x4, 0x7, 0x8, 0x8, 0x7, 0x4, 0x0, 0x0,  };
static const uint8 kSpr0BA_TimedPlatform_XDisp[3] = { 0x0, 0x10, 0xc,  };
static const uint8 kSpr0BA_TimedPlatform_YDisp[3] = { 0x0, 0x0, 0x4,  };
static const uint8 kSpr0BA_TimedPlatform_PlatformTiles[3] = { 0xc4, 0xc4, 0x0,  };
static const uint8 kSpr0BA_TimedPlatform_Prop[3] = { 0xb, 0x4b, 0xb,  };
static const uint8 kSpr0BA_TimedPlatform_TileSize[3] = { 0x2, 0x2, 0x0,  };
static const uint8 kSpr0BA_TimedPlatform_NumberTiles[4] = { 0xb6, 0xb5, 0xb4, 0xb3,  };
static const uint8 kSpr0BB_MovingCastleStone_XSpeed[4] = { 0x0, 0xf0, 0x0, 0x10,  };
static const uint8 kSpr0BB_MovingCastleStone_MovementTiming[4] = { 0x40, 0x50, 0x40, 0x50,  };
static const uint8 kSpr0BB_MovingCastleStone_XDisp[4] = { 0x0, 0x10, 0x0, 0x10,  };
static const uint8 kSpr0BB_MovingCastleStone_YDisp[4] = { 0x0, 0x0, 0x10, 0x10,  };
static const uint8 kSpr0BB_MovingCastleStone_Tiles[4] = { 0xcc, 0xce, 0xec, 0xee,  };
static const uint8 kSpr0B3_BowserStatueFire_XSpeed[2] = { 0x10, 0xf0,  };
static const uint8 kSpr0B3_BowserStatueFire_XDisp[4] = { 0x8, 0x0, 0x0, 0x8,  };
static const uint8 kSpr0B3_BowserStatueFire_Tiles[8] = { 0x32, 0x50, 0x33, 0x34, 0x32, 0x50, 0x33, 0x34,  };
static const uint8 kSpr0B3_BowserStatueFire_Prop[8] = { 0x9, 0x9, 0x9, 0x9, 0x89, 0x89, 0x89, 0x89,  };
static const uint8 kSprXXX_ReflectingEnemy_BooStreamTiles[8] = { 0x88, 0x8c, 0x8e, 0xa8, 0xaa, 0xae, 0x88, 0x8c,  };
static const uint8 kSpr0AE_FishinBoo_XAcceleration[2] = { 0x1, 0xff,  };
static const uint8 kSpr0AE_FishinBoo_MaxXSpeed[2] = { 0x20, 0xe0,  };
static const uint8 kSpr0AE_FishinBoo_YAcceleration[2] = { 0x1, 0xff,  };
static const uint8 kSpr0AE_FishinBoo_MaxYSpeed[2] = { 0x10, 0xf0,  };
static const uint8 kSpr0AE_FishinBoo_DATA_0390EB[4] = { 0x1a, 0x14, 0xee, 0xf8,  };
static const uint8 kSpr0AE_FishinBoo_DATA_0390EF[4] = { 0x0, 0x0, 0xff, 0xff,  };
static const uint8 kSpr0AE_FishinBoo_XDisp[40] = { 0xfb, 0x5, 0x0, 0xf2, 0xfd, 0x3, 0xea, 0xea, 0xea, 0xea, 0xfb, 0x5, 0x0, 0xfa, 0xfd, 0x3, 0xf2, 0xf2, 0xf2, 0xf2, 0xfb, 0x5, 0x0, 0xe, 0x3, 0xfd, 0x16, 0x16, 0x16, 0x16, 0xfb, 0x5, 0x0, 0x6, 0x3, 0xfd, 0xe, 0xe, 0xe, 0xe,  };
static const uint8 kSpr0AE_FishinBoo_YDisp[10] = { 0xb, 0xb, 0x0, 0x3, 0xf, 0xf, 0x13, 0x23, 0x33, 0x43,  };
static const uint8 kSpr0AE_FishinBoo_Tiles1[10] = { 0x60, 0x60, 0x64, 0x8a, 0x60, 0x60, 0xac, 0xac, 0xac, 0xce,  };
static const uint8 kSpr0AE_FishinBoo_Prop[10] = { 0x4, 0x4, 0xd, 0x9, 0x4, 0x4, 0xd, 0xd, 0xd, 0x7,  };
static const uint8 kSpr0AE_FishinBoo_Tiles2[4] = { 0xcc, 0xce, 0xcc, 0xce,  };
static const uint8 kSpr0AE_FishinBoo_DATA_039178[4] = { 0x0, 0x0, 0x40, 0x40,  };
static const uint8 kSpr0AE_FishinBoo_DATA_03917C[4] = { 0x0, 0x40, 0xc0, 0x80,  };
static const uint8 kSpr0B1_CreateEatBlock_XSpeed[5] = { 0x10, 0xf0, 0x0, 0x0, 0x0,  };
static const uint8 kSpr0B1_CreateEatBlock_YSpeed[5] = { 0x0, 0x0, 0x10, 0xf0, 0x0,  };
static const uint8 kSpr0B1_CreateEatBlock_DATA_039279[11] = { 0x0, 0x0, 0x1, 0x0, 0x2, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0,  };
static const uint8 kSpr0B1_CreateEatBlock_SubmapMovementData[75] = { 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0xf0, 0xf0, 0x20, 0x12, 0x10, 0x12, 0x10, 0x12, 0x10, 0x12, 0x10, 0x12, 0x10, 0x12, 0x10, 0x12, 0xd0, 0xc3, 0xf1, 0x21, 0x22, 0xf1, 0xf1, 0x51, 0x43, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0xf0, 0xf0, 0xf0, 0x60, 0x32, 0x60, 0x32, 0x71, 0x32, 0x60, 0x32, 0x61, 0x32, 0x70, 0x33, 0x10, 0x33, 0x10, 0x33, 0x10, 0x33, 0x10, 0x33, 0xf0, 0x10, 0xf2, 0x52, 0xff,  };
static const uint8 kSpr0B1_CreateEatBlock_MainMapMovementData[52] = { 0x80, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0x60, 0x23, 0x20, 0x23, 0xb0, 0x22, 0xa1, 0x22, 0xa0, 0x22, 0xa1, 0x22, 0xc0, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0x10, 0x13, 0xf0, 0xf0, 0xf0, 0x52, 0x50, 0x33, 0x50, 0x32, 0x50, 0x33, 0x50, 0x22, 0x50, 0x33, 0xf0, 0x50, 0x82, 0xff,  };
static const uint8 kSpr0AC_DownFirstWoodenSpike_DATA_039484[2] = { 0x1, 0xff,  };
static const uint8 kSpr0AC_DownFirstWoodenSpike_DATA_039486[2] = { 0x0, 0xff,  };
static const uint8 kSpr0AC_DownFirstWoodenSpike_YDisp[10] = { 0x0, 0x10, 0x20, 0x30, 0x40, 0x40, 0x30, 0x20, 0x10, 0x0,  };
static const uint8 kSpr0AC_DownFirstWoodenSpike_Tiles[10] = { 0x6a, 0x6a, 0x6a, 0x6a, 0x4a, 0x6a, 0x6a, 0x6a, 0x6a, 0x4a,  };
static const uint8 kSpr0AC_DownFirstWoodenSpike_Prop[10] = { 0x81, 0x81, 0x81, 0x81, 0x81, 0x1, 0x1, 0x1, 0x1, 0x1,  };
static const uint8 kSpr0AB_Rex_XSpeed[4] = { 0x8, 0xf8, 0x10, 0xf0,  };
static const uint8 kSpr0AB_Rex_RexKilledSpeed[2] = { 0xf0, 0x10,  };
static const uint8 kSpr0AB_Rex_XDisp[24] = { 0xfc, 0x0, 0xfc, 0x0, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x4, 0x0, 0x4, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0,  };
static const uint8 kSpr0AB_Rex_YDisp[12] = { 0xf1, 0x0, 0xf0, 0x0, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x8,  };
static const uint8 kSpr0AB_Rex_Tiles[12] = { 0x8a, 0xaa, 0x8a, 0xac, 0x8a, 0xaa, 0x8c, 0x8c, 0xa8, 0xa8, 0xa2, 0xb2,  };
static const uint8 kSpr0AB_Rex_Prop[2] = { 0x47, 0x7,  };
static const uint8 kSpr0AA_Fishbone_MaxXSpeed[2] = { 0x10, 0xf0,  };
static const uint8 kSpr0AA_Fishbone_XAcceleration[2] = { 0x1, 0xff,  };
static const uint8 kSpr0AA_Fishbone_XDisp[4] = { 0xf8, 0xf8, 0x10, 0x10,  };
static const uint8 kSpr0AA_Fishbone_YDisp[2] = { 0x0, 0x8,  };
static const uint8 kSpr0AA_Fishbone_Prop[4] = { 0x4d, 0xcd, 0xd, 0x8d,  };
static const uint8 kSpr0AA_Fishbone_TailTiles[4] = { 0xa3, 0xa3, 0xb3, 0xb3,  };
static const uint8 kSpr0A9_Reznor_ReznorStartPosLo[4] = { 0x0, 0x80, 0x0, 0x80,  };
static const uint8 kSpr0A9_Reznor_ReznorStartPosHi[4] = { 0x0, 0x0, 0x1, 0x1,  };
static const uint8 kSpr0A9_Reznor_ReboundSpeedX[2] = { 0x20, 0xe0,  };
static const uint8 kSpr0A9_Reznor_XDisp[8] = { 0x0, 0xf0, 0x0, 0xf0, 0xf0, 0x0, 0xf0, 0x0,  };
static const uint8 kSpr0A9_Reznor_YDisp[4] = { 0xe0, 0xe0, 0xf0, 0xf0,  };
static const uint8 kSpr0A9_Reznor_Tiles[12] = { 0x40, 0x42, 0x60, 0x62, 0x44, 0x46, 0x64, 0x66, 0x28, 0x28, 0x48, 0x48,  };
static const uint8 kSpr0A9_Reznor_Prop[12] = { 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0x3f, 0x7f, 0x3f,  };
static const uint8 kSpr0A9_Reznor_PlatformYDisp[8] = { 0x0, 0x3, 0x4, 0x5, 0x5, 0x4, 0x3, 0x0,  };
static const uint8 kSpr06F_DinoTorch_DATA_039C6E[3] = { 0x0, 0xfe, 0x2,  };
static const uint8 kSpr06F_DinoTorch_DATA_039C71[3] = { 0x0, 0xff, 0x0,  };
static const uint8 kSpr06F_DinoTorch_XSpeed[4] = { 0x8, 0xf8, 0x10, 0xf0,  };
static const uint8 kSpr06F_DinoTorch_DinoFlameTable[64] = { 0x41, 0x42, 0x42, 0x32, 0x22, 0x12, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x12, 0x22, 0x32, 0x42, 0x42, 0x42, 0x42, 0x41, 0x41, 0x41, 0x43, 0x43, 0x33, 0x23, 0x13, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x13, 0x23, 0x33, 0x43, 0x43, 0x43, 0x43, 0x41, 0x41,  };
static const uint8 kSpr06F_DinoTorch_DinoFlame1[4] = { 0xdc, 0x2, 0x10, 0x2,  };
static const uint8 kSpr06F_DinoTorch_DinoFlame2[4] = { 0xff, 0x0, 0x0, 0x0,  };
static const uint8 kSpr06F_DinoTorch_DinoFlame3[4] = { 0x24, 0xc, 0x24, 0xc,  };
static const uint8 kSpr06F_DinoTorch_DinoFlame4[4] = { 0x2, 0xdc, 0x2, 0xdc,  };
static const uint8 kSpr06F_DinoTorch_DinoFlame5[4] = { 0x0, 0xff, 0x0, 0xff,  };
static const uint8 kSpr06F_DinoTorch_DinoFlame6[4] = { 0xc, 0x24, 0xc, 0x24,  };
static const uint8 kSpr06F_DinoTorch_DinoTorchXDisp[10] = { 0xd8, 0xe0, 0xec, 0xf8, 0x0, 0xff, 0xff, 0xff, 0xff, 0x0,  };
static const uint8 kSpr06F_DinoTorch_DinoTorchYDisp[10] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0xd8, 0xe0, 0xec, 0xf8, 0x0,  };
static const uint8 kSpr06F_DinoTorch_DinoFlameTiles[10] = { 0x80, 0x82, 0x84, 0x86, 0x0, 0x88, 0x8a, 0x8c, 0x8e, 0x0,  };
static const uint8 kSpr06F_DinoTorch_DinoTorchProp[5] = { 0x9, 0x5, 0x5, 0x5, 0xf,  };
static const uint8 kSpr06F_DinoTorch_DinoTorchTiles[4] = { 0xea, 0xaa, 0xc4, 0xc6,  };
static const uint8 kSpr06F_DinoTorch_DinoRhinoXDisp[8] = { 0xf8, 0x8, 0xf8, 0x8, 0x8, 0xf8, 0x8, 0xf8,  };
static const uint8 kSpr06F_DinoTorch_DinoRhinoProp[8] = { 0x2f, 0x2f, 0x2f, 0x2f, 0x6f, 0x6f, 0x6f, 0x6f,  };
static const uint8 kSpr06F_DinoTorch_DinoRhinoYDisp[4] = { 0xf0, 0xf0, 0x0, 0x0,  };
static const uint8 kSpr06F_DinoTorch_DinoRhinoTiles[16] = { 0xc0, 0xc2, 0xe4, 0xe6, 0xc0, 0xc2, 0xe0, 0xe2, 0xc8, 0xca, 0xe8, 0xe2, 0xcc, 0xce, 0xec, 0xee,  };
static const uint8 kSpr06F_DinoTorch_DinoTilesWritten[5] = { 0x4, 0x3, 0x2, 0x1, 0x0,  };
static const uint8 kSpr0A8_Blargg_XSpeed[2] = { 0x10, 0xf0,  };
static const uint8 kSpr0A8_Blargg_XDisp[10] = { 0xf8, 0x8, 0xf8, 0x8, 0x18, 0x8, 0xf8, 0x8, 0xf8, 0xe8,  };
static const uint8 kSpr0A8_Blargg_YDisp[5] = { 0xf8, 0xf8, 0x8, 0x8, 0x8,  };
static const uint8 kSpr0A8_Blargg_Tiles[10] = { 0xa2, 0xa4, 0xc2, 0xc4, 0xa6, 0xa2, 0xa4, 0xe6, 0xc8, 0xa6,  };
static const uint8 kSpr0A8_Blargg_Prop[2] = { 0x45, 0x5,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A265[20] = { 0x4, 0x3, 0x2, 0x1, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,  };
static const uint8 kSpr0A0_ActivateBowserBattle_SmokeXDisp[72] = { 0xd5, 0xdd, 0x23, 0x2b, 0xd5, 0xdd, 0x23, 0x2b, 0xd5, 0xdd, 0x23, 0x2b, 0xd5, 0xdd, 0x23, 0x2b, 0xd6, 0xde, 0x22, 0x2a, 0xd6, 0xde, 0x22, 0x2a, 0xd7, 0xdf, 0x21, 0x29, 0xd7, 0xdf, 0x21, 0x29, 0xd8, 0xe0, 0x20, 0x28, 0xd8, 0xe0, 0x20, 0x28, 0xda, 0xe2, 0x1e, 0x26, 0xda, 0xe2, 0x1e, 0x26, 0xdc, 0xe4, 0x1c, 0x24, 0xdc, 0xe4, 0x1c, 0x24, 0xe0, 0xe8, 0x18, 0x20, 0xe0, 0xe8, 0x18, 0x20, 0xe8, 0xf0, 0x10, 0x18, 0xe8, 0xf0, 0x10, 0x18,  };
static const uint8 kSpr0A0_ActivateBowserBattle_SmokeYDisp[72] = { 0xdd, 0xd5, 0xd5, 0xdd, 0x23, 0x2b, 0x2b, 0x23, 0xdd, 0xd5, 0xd5, 0xdd, 0x23, 0x2b, 0x2b, 0x23, 0xde, 0xd6, 0xd6, 0xde, 0x22, 0x2a, 0x2a, 0x22, 0xdf, 0xd7, 0xd7, 0xdf, 0x21, 0x29, 0x29, 0x21, 0xe0, 0xd8, 0xd8, 0xe0, 0x20, 0x28, 0x28, 0x20, 0xe2, 0xda, 0xda, 0xe2, 0x1e, 0x26, 0x26, 0x1e, 0xe4, 0xdc, 0xdc, 0xe4, 0x1c, 0x24, 0x24, 0x1c, 0xe8, 0xe0, 0xe0, 0xe8, 0x18, 0x20, 0x20, 0x18, 0xf0, 0xe8, 0xe8, 0xf0, 0x10, 0x18, 0x18, 0x10,  };
static const uint8 kSpr0A0_ActivateBowserBattle_SmokeProp[8] = { 0x80, 0x40, 0x0, 0xc0, 0x0, 0xc0, 0x80, 0x40,  };
static const uint8 kSpr0A0_ActivateBowserBattle_SmokeTiles[9] = { 0xe3, 0xed, 0xed, 0xeb, 0xeb, 0xe9, 0xe9, 0xe7, 0xe7,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DuckingAnimationFrames[10] = { 0x0, 0x0, 0x0, 0x0, 0x2, 0x4, 0x6, 0x8, 0xa, 0xe,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A490[2] = { 0xff, 0x1,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A492[2] = { 0xc8, 0x38,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A494[2] = { 0x1, 0xff,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A496[2] = { 0x1c, 0xe4,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A498[4] = { 0x0, 0x2, 0x4, 0x2,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A4EB[2] = { 0x80, 0x0,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A52D[64] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x4, 0x6, 0x8, 0xa, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xe, 0xa, 0x8, 0x6, 0x4, 0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A56D[64] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x80, 0xa0, 0xc0, 0xe0, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x80, 0x60, 0x40, 0x30, 0x20, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A64D[20] = { 0x0, 0x0, 0x0, 0x0, 0xfc, 0xf8, 0xf4, 0xf0, 0xf4, 0xf8, 0xfc, 0x0, 0x4, 0x8, 0xc, 0x10, 0xc, 0x8, 0x4, 0x0,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A6F0[8] = { 0xe, 0xe, 0xa, 0x8, 0x6, 0x4, 0x2, 0x0,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A71F[2] = { 0x1, 0xff,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A721[2] = { 0x10, 0x80,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A723[2] = { 0x7, 0x3,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A725[2] = { 0xff, 0x1,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A727[2] = { 0xf0, 0x8,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A729[2] = { 0x1, 0xff,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A72B[2] = { 0x3, 0x3,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A72D[2] = { 0x60, 0x2,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A72F[2] = { 0x1, 0x1,  };
static const uint8 kSpr0A0_ActivateBowserBattle_RainingFireSounds[10] = { 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x19, 0x1A  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03A8BE[24] = { 0x0, 0x0, 0x0, 0x8, 0x10, 0x14, 0x14, 0x16, 0x16, 0x18, 0x18, 0x17, 0x16, 0x16, 0x17, 0x18, 0x18, 0x17, 0x14, 0x10, 0xc, 0x8, 0x4, 0x0,  };
static const uint8 kSpr07C_PrincessPeach_PeachXDisp[80] = { 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0,  };
static const uint8 kSpr07C_PrincessPeach_PeachYDisp[80] = { 0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0x10, 0x10,  };
static const uint8 kSpr07C_PrincessPeach_PeachTiles[80] = { 0x5, 0x6, 0x15, 0x16, 0x9d, 0x9e, 0x4e, 0xae, 0x6, 0x5, 0x16, 0x15, 0x9e, 0x9d, 0xae, 0x4e, 0x8a, 0x8b, 0xaa, 0x68, 0x83, 0x84, 0xaa, 0x68, 0x8a, 0x8b, 0x80, 0x81, 0x83, 0x84, 0x80, 0x81, 0x85, 0x86, 0xa5, 0xa6, 0x83, 0x84, 0xa5, 0xa6, 0x82, 0x83, 0xa2, 0xa3, 0x82, 0x83, 0xa2, 0xa3, 0x8a, 0x8b, 0xaa, 0x68, 0x83, 0x84, 0xaa, 0x68, 0x8a, 0x8b, 0x80, 0x81, 0x83, 0x84, 0x80, 0x81, 0x85, 0x86, 0xa5, 0xa6, 0x83, 0x84, 0xa5, 0xa6, 0x82, 0x83, 0xa2, 0xa3, 0x82, 0x83, 0xa2, 0xa3,  };
static const uint8 kSpr07C_PrincessPeach_PeachProp[80] = { 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x40, 0x40, 0x40, 0x40, 0x41, 0x41, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03AB15[2] = { 0x1, 0xff,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03AB17[2] = { 0x20, 0xe0,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03AB19[2] = { 0x2, 0xfe,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03AB1B[6] = { 0x20, 0xe0, 0x1, 0xff, 0x10, 0xf0,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03AB62[2] = { 0x10, 0xf0,  };
static const uint8 kSpr07C_PrincessPeach_BlushYDisp[2] = { 0x1, 0x11,  };
static const uint8 kSpr07C_PrincessPeach_BlushTiles[2] = { 0x6e, 0x88,  };
static const uint8 kSpr07C_PrincessPeach_XSpeed[4] = { 0x8, 0xf8, 0xf8, 0x8,  };
static const uint8 kSpr07C_PrincessPeach_DATA_03AE5B[84] = { 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x18, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x20, 0x8, 0x8, 0x8, 0x8, 0x8, 0x20, 0x8, 0x8, 0x10, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x20, 0x8, 0x8, 0x8, 0x8, 0x8, 0x20, 0x8, 0x4, 0x20, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x10, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x10, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x40,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03AF34[8] = { 0xf4, 0xff, 0xc, 0x19, 0x24, 0x19, 0xc, 0xff,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03AF3C[8] = { 0xfc, 0xf6, 0xf4, 0xf6, 0xfc, 0x2, 0x4, 0x2,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03AF44[8] = { 0x5, 0x5, 0x5, 0x5, 0x45, 0x45, 0x45, 0x45,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03AF4C[13] = { 0x34, 0x34, 0x34, 0x35, 0x35, 0x36, 0x36, 0x37, 0x38, 0x3a, 0x3e, 0x46, 0x54,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03B013[2] = { 0x0, 0x10,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03B015[2] = { 0x0, 0x0,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03B017[2] = { 0xf8, 0x8,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03B074[2] = { 0x40, 0xc0,  };
static const uint8 kSpr0A0_ActivateBowserBattle_DATA_03B076[2] = { 0x10, 0xf0,  };
static const uint8 kSpr0A1_BowserBowlingBall_XSpeed[2] = { 0x10, 0xf0,  };
static const uint8 kSpr0A1_BowserBowlingBall_XDisp[12] = { 0xf0, 0x0, 0x10, 0xf0, 0x0, 0x10, 0xf0, 0x0, 0x10, 0x0, 0x0, 0xf8,  };
static const uint8 kSpr0A1_BowserBowlingBall_YDisp[12] = { 0xe2, 0xe2, 0xe2, 0xf2, 0xf2, 0xf2, 0x2, 0x2, 0x2, 0x2, 0x2, 0xea,  };
static const uint8 kSpr0A1_BowserBowlingBall_Tiles[12] = { 0x45, 0x47, 0x45, 0x65, 0x66, 0x65, 0x45, 0x47, 0x45, 0x39, 0x38, 0x63,  };
static const uint8 kSpr0A1_BowserBowlingBall_Prop[12] = { 0xd, 0xd, 0x4d, 0xd, 0xd, 0x4d, 0x8d, 0x8d, 0xcd, 0xd, 0xd, 0xd,  };
static const uint8 kSpr0A1_BowserBowlingBall_TileSize[12] = { 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x0, 0x0, 0x2,  };
static const uint8 kSpr0A1_BowserBowlingBall_XDisp2[8] = { 0x4, 0xd, 0x10, 0xd, 0x4, 0xfb, 0xf8, 0xfb,  };
static const uint8 kSpr0A1_BowserBowlingBall_YDisp2[8] = { 0x0, 0xfd, 0xf4, 0xeb, 0xe8, 0xeb, 0xf4, 0xfd,  };
static const uint8 kSpr0A2_MechaKoopa_XSpeed[2] = { 0x8, 0xf8,  };
static const uint8 kSpr0A2_MechaKoopa_MechakoopaXDisp[8] = { 0xf8, 0x8, 0xf8, 0x0, 0x8, 0x0, 0x10, 0x0,  };
static const uint8 kSpr0A2_MechaKoopa_MechakoopaYDisp[24] = { 0xf8, 0xf8, 0x8, 0x0, 0xf9, 0xf9, 0x9, 0x0, 0xf8, 0xf8, 0x8, 0x0, 0xf9, 0xf9, 0x9, 0x0, 0xfd, 0x0, 0x5, 0x0, 0x0, 0x0, 0x8, 0x0,  };
static const uint8 kSpr0A2_MechaKoopa_MechakoopaTiles[24] = { 0x40, 0x42, 0x60, 0x51, 0x40, 0x42, 0x60, 0xa, 0x40, 0x42, 0x60, 0xc, 0x40, 0x42, 0x60, 0xe, 0x0, 0x2, 0x10, 0x1, 0x0, 0x2, 0x10, 0x1,  };
static const uint8 kSpr0A2_MechaKoopa_MechakoopaProp[8] = { 0x0, 0x0, 0x0, 0x0, 0x40, 0x40, 0x40, 0x40,  };
static const uint8 kSpr0A2_MechaKoopa_MechakoopaTileSize[4] = { 0x2, 0x0, 0x0, 0x2,  };
static const uint8 kSpr0A2_MechaKoopa_MechakoopaPalette[2] = { 0xb, 0x5,  };
static const uint8 kSpr0A2_MechaKoopa_KeyXDisp[2] = { 0xf9, 0xf,  };
static const uint8 kSpr0A2_MechaKoopa_KeyProp[2] = { 0x4d, 0xd,  };
static const uint8 kSpr0A2_MechaKoopa_KeyTiles[4] = { 0x70, 0x71, 0x72, 0x71,  };
static const uint8 kSpr0A0_ActivateBowserBattle_ItemBoxXPos[4] = { 0x70, 0x80, 0x70, 0x80,  };
static const uint8 kSpr0A0_ActivateBowserBattle_ItemBoxYPos[4] = { 0x7, 0x7, 0x17, 0x17,  };
static const uint8 kSpr0A0_ActivateBowserBattle_ItemBoxProp[4] = { 0x37, 0x77, 0xb7, 0xf7,  };
static const uint8 kSpr0A0_ActivateBowserBattle_RoofXPos[16] = { 0x0, 0x30, 0x60, 0x90, 0xc0, 0xf0, 0x0, 0x30, 0x40, 0x50, 0x60, 0x90, 0xa0, 0xb0, 0xc0, 0xf0,  };
static const uint8 kSpr0A0_ActivateBowserBattle_RoofYPos[16] = { 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xb0, 0xd0, 0xd0, 0xd0, 0xd0, 0xd0, 0xd0, 0xd0, 0xd0, 0xd0, 0xd0,  };
static const uint8 kStandardSpriteToSpriteCollisionChecks_SprClippingDispX[60] = { 0x2, 0x2, 0x10, 0x14, 0x0, 0x0, 0x1, 0x8, 0xf8, 0xfe, 0x3, 0x6, 0x1, 0x0, 0x6, 0x2, 0x0, 0xe8, 0xfc, 0xfc, 0x4, 0x0, 0xfc, 0x2, 0x2, 0x2, 0x2, 0x2, 0x0, 0x2, 0xe0, 0xf0, 0xfc, 0xfc, 0x0, 0xf8, 0xf4, 0xf2, 0x0, 0xfc, 0xf2, 0xf0, 0x2, 0x0, 0xf8, 0x4, 0x2, 0x2, 0x8, 0x0, 0x0, 0x0, 0xfc, 0x3, 0x8, 0x0, 0x8, 0x4, 0xf8, 0x0,  };
static const uint8 kStandardSpriteToSpriteCollisionChecks_SprClippingWidth[60] = { 0xc, 0xc, 0x10, 0x8, 0x30, 0x50, 0xe, 0x28, 0x20, 0x14, 0x1, 0x3, 0xd, 0xf, 0x14, 0x24, 0xf, 0x40, 0x8, 0x8, 0x18, 0xf, 0x18, 0xc, 0xc, 0xc, 0xc, 0xc, 0xa, 0x1c, 0x30, 0x30, 0x8, 0x8, 0x10, 0x20, 0x38, 0x3c, 0x20, 0x18, 0x1c, 0x20, 0xc, 0x10, 0x10, 0x8, 0x1c, 0x1c, 0x10, 0x30, 0x30, 0x40, 0x8, 0x12, 0x34, 0xf, 0x20, 0x8, 0x20, 0x10,  };
static const uint8 kStandardSpriteToSpriteCollisionChecks_SprClippingDispY[60] = { 0x3, 0x3, 0xfe, 0x8, 0xfe, 0xfe, 0x2, 0x8, 0xfe, 0x8, 0x7, 0x6, 0xfe, 0xfc, 0x6, 0xfe, 0xfe, 0xe8, 0x10, 0x10, 0x2, 0xfe, 0xf4, 0x8, 0x13, 0x23, 0x33, 0x43, 0xa, 0xfd, 0xf8, 0xfc, 0xe8, 0x10, 0x0, 0xe8, 0x20, 0x4, 0x58, 0xfc, 0xe8, 0xfc, 0xf8, 0x2, 0xf8, 0x4, 0xfe, 0xfe, 0xf2, 0xfe, 0xfe, 0xfe, 0xfc, 0x0, 0x8, 0xf8, 0x10, 0x3, 0x10, 0x0,  };
static const uint8 kStandardSpriteToSpriteCollisionChecks_SprClippingHeight[60] = { 0xa, 0x15, 0x12, 0x8, 0xe, 0xe, 0x18, 0x30, 0x10, 0x1e, 0x2, 0x3, 0x16, 0x10, 0x14, 0x12, 0x20, 0x40, 0x34, 0x74, 0xc, 0xe, 0x18, 0x45, 0x3a, 0x2a, 0x1a, 0xa, 0x30, 0x1b, 0x20, 0x12, 0x18, 0x18, 0x10, 0x20, 0x38, 0x14, 0x8, 0x18, 0x28, 0x1b, 0x13, 0x4c, 0x10, 0x4, 0x22, 0x20, 0x1c, 0x12, 0x12, 0x12, 0x8, 0x20, 0x2e, 0x14, 0x28, 0xa, 0x10, 0xd,  };
static const uint8 kStandardSpriteToSpriteCollisionChecks_MarioClipDispY[4] = { 0x6, 0x14, 0x10, 0x18,  };
static const uint8 kStandardSpriteToSpriteCollisionChecks_MarioClippingHeight[4] = { 0x1a, 0xc, 0x20, 0x18,  };
static const uint8 kGetDrawInfo_DATA_03B75C[2] = { 0xc, 0x1c,  };
static const uint8 kGetDrawInfo_DATA_03B75E[2] = { 0x1, 0x2,  };
static const uint8 kSpr0A1_BowserBowlingBall_BounceYSpeed[38] = { 0x0, 0x0, 0x0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf8, 0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xe8, 0xe8, 0xe8, 0xe8, 0x0, 0x0, 0x0, 0x0, 0xfe, 0xfc, 0xf8, 0xec, 0xec, 0xec, 0xe8, 0xe4, 0xe0, 0xdc, 0xd8, 0xd4, 0xd0, 0xcc, 0xc8,  };
static const uint8 kSubOffscreen_Bank03[2] = { 0x40, 0xb0,  };
static const uint8 kSubOffscreen_Bank03_DATA_03B83D[2] = { 0x1, 0xff,  };
static const uint8 kSubOffscreen_Bank03_DATA_03B83F[8] = { 0x30, 0xc0, 0xa0, 0x80, 0xa0, 0x40, 0x60, 0xb0,  };
static const uint8 kSubOffscreen_Bank03_DATA_03B847[8] = { 0x1, 0xff, 0x1, 0xff, 0x1, 0x0, 0x1, 0xff,  };
const uint16 kSpr01F_MagiKoopa_MagiKoopaFadePalettes[64] = { 0x7fff, 0x294a, 0x0, 0x1400, 0x2000, 0x7e92, 0xa, 0x2a, 0x7fff, 0x35ad, 0x0, 0x2400, 0x2c00, 0x722f, 0xd, 0xad, 0x7fff, 0x4210, 0x0, 0x3000, 0x3800, 0x65cc, 0x50, 0x110, 0x7fff, 0x4e73, 0x0, 0x3c00, 0x4441, 0x5969, 0xb3, 0x173, 0x7fff, 0x5ad6, 0x0, 0x4800, 0x50a4, 0x4d06, 0x116, 0x1d6, 0x7fff, 0x6739, 0x0, 0x5442, 0x5d07, 0x40a3, 0x179, 0x239, 0x7fff, 0x739c, 0x0, 0x60a5, 0x696a, 0x3440, 0x1dc, 0x29c, 0x7fff, 0x7fff, 0x0, 0x6d08, 0x75cd, 0x2800, 0x23f, 0x2ff,  };
static const uint16 kBooFadePalettes[64] = { 0x7fff, 0xc63, 0x0, 0xc00, 0xc00, 0xc00, 0xc00, 0x3, 0x7fff, 0x1ce7, 0x0, 0x1c00, 0x1c00, 0x1c20, 0x1c81, 0x7, 0x7fff, 0x2d6b, 0x0, 0x2c00, 0x2c40, 0x2ca2, 0x2d05, 0xb, 0x7fff, 0x3def, 0x0, 0x3c60, 0x3cc3, 0x3d26, 0x3d89, 0xf, 0x7fff, 0x4e73, 0x0, 0x4ce4, 0x4d47, 0x4daa, 0x4e0d, 0x1013, 0x7fff, 0x5ef7, 0x0, 0x5d68, 0x5dcb, 0x5e2e, 0x5e91, 0x2017, 0x7fff, 0x6f7b, 0x0, 0x6dec, 0x6e4f, 0x6eb2, 0x6f15, 0x301b, 0x7fff, 0x7fff, 0x0, 0x7e70, 0x7ed3, 0x7f36, 0x7f99, 0x401f,  };
static const uint8 kCheckIfBabyYoshiCanEatNormalSprite_ChangingItemSpriteType[4] = { 0x74, 0x75, 0x77, 0x76,  };
static const uint8 kGameMode14_InLevel_DATA_03C0B2[4] = { 0x68, 0x6a, 0x6c, 0x6e,  };
// oob
static const uint8 kGameMode14_InLevel_DATA_03C0B6[20] = { 0x0, 0x3, 0x1, 0x2, 0x4, 0x2, 0x0, 0x1, 0x0, 0x4, 0x0, 0x2, 0x0, 0x3, 0x4, 0x1,
0xa5, 0x9d, 0xd0, 0x03};
static const uint8 kGameMode14_InLevel_IggyPlatSpeed[4] = { 0xff, 0x1, 0xff, 0x1,  };
static const uint8 kGameMode14_InLevel_DATA_03C116[4] = { 0xff, 0x0, 0xff, 0x0,  };
static const uint8 kGameMode14_InLevel_IggyPlatBounds[4] = { 0xe7, 0x18, 0xd7, 0x28,  };
static const uint8 kHandleNormalSpriteLevelColl_DATA_03C1C6[2] = { 0x2, 0xfe,  };
static const uint8 kHandleNormalSpriteLevelColl_DATA_03C1C8[2] = { 0x0, 0xff,  };
static const uint8 kSpr0C8_LightSwitch_DATA_03C1EC[9] = { 0x0, 0x4, 0x7, 0x8, 0x8, 0x7, 0x4, 0x0, 0x0,  };
static const uint8 kSprXXX_LineGuided_MotorTiles[4] = { 0xe0, 0xc2, 0xc0, 0xc2,  };
static const uint8 kSprXXX_LineGuided_YDisp[2] = { 0xf2, 0xe,  };
static const uint8 kSprXXX_LineGuided_Prop[2] = { 0x33, 0xb3,  };
static const uint8 kSpr051_Ninji_YSpeed[4] = { 0xd0, 0xc0, 0xb0, 0xd0,  };
static const uint8 kSpr030_ThrowingDryBones_DryBonesTileXDisp[12] = { 0x0, 0x8, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x4, 0x0, 0x0, 0xfc, 0x0,  };
static const uint8 kSpr030_ThrowingDryBones_DryBonesGfxProp[6] = { 0x43, 0x43, 0x43, 0x3, 0x3, 0x3,  };
static const uint8 kSpr030_ThrowingDryBones_DryBonesTileYDisp[9] = { 0xf4, 0xf0, 0x0, 0xf4, 0xf1, 0x0, 0xf4, 0xf0, 0x0,  };
static const uint8 kSpr030_ThrowingDryBones_DryBonesTiles[9] = { 0x0, 0x64, 0x66, 0x0, 0x64, 0x68, 0x82, 0x64, 0xe6,  };
static const uint8 kSpr030_ThrowingDryBones_DATA_03C3D7[3] = { 0x0, 0x0, 0xff,  };
static const uint8 kSpr0C6_Spotlight_DATA_03C48F[2] = { 0x1, 0xff,  };
static const uint8 kSpr0C6_Spotlight_DATA_03C491[2] = { 0xff, 0x90,  };
static const uint8 kSpr0C6_Spotlight_Tiles[9] = { 0x80, 0x82, 0x84, 0x86, 0x88, 0x8c, 0xc0, 0xc2, 0xc2,  };
static const uint8 kSpr0C6_Spotlight_Prop[9] = { 0x31, 0x33, 0x35, 0x37, 0x31, 0x33, 0x35, 0x37, 0x39,  };
static const uint8 kSpr0C6_Spotlight_DATA_03C4D8[2] = { 0x10, 0x8c,  };
static const uint8 kSpr0C6_Spotlight_DATA_03C4DA[2] = { 0x42, 0x31,  };
static const uint8 kSpr07A_Fireworks_DATA_03C626[84] = { 0x14, 0x28, 0x38, 0x20, 0x30, 0x4c, 0x40, 0x34, 0x2c, 0x1c, 0x8, 0xc, 0x4, 0xc, 0x1c, 0x24, 0x2c, 0x38, 0x40, 0x48, 0x50, 0x5c, 0x5c, 0x6c, 0x4c, 0x58, 0x24, 0x78, 0x64, 0x70, 0x78, 0x7c, 0x70, 0x68, 0x58, 0x4c, 0x40, 0x34, 0x24, 0x4, 0x18, 0x2c, 0xc, 0xc, 0x14, 0x18, 0x1c, 0x24, 0x2c, 0x28, 0x24, 0x30, 0x30, 0x34, 0x38, 0x3c, 0x44, 0x54, 0x48, 0x5c, 0x68, 0x40, 0x4c, 0x40, 0x3c, 0x40, 0x50, 0x54, 0x60, 0x54, 0x4c, 0x5c, 0x5c, 0x68, 0x74, 0x6c, 0x7c, 0x78, 0x68, 0x80, 0x18, 0x48, 0x2c, 0x1c,  };
static const uint8 kSpr07A_Fireworks_DATA_03C67A[84] = { 0x1c, 0xc, 0x8, 0x1c, 0x14, 0x8, 0x14, 0x24, 0x28, 0x2c, 0x30, 0x3c, 0x44, 0x4c, 0x44, 0x34, 0x40, 0x34, 0x24, 0x1c, 0x10, 0xc, 0x18, 0x18, 0x2c, 0x28, 0x68, 0x28, 0x34, 0x34, 0x38, 0x40, 0x44, 0x44, 0x38, 0x3c, 0x44, 0x48, 0x4c, 0x5c, 0x5c, 0x54, 0x64, 0x74, 0x74, 0x88, 0x80, 0x94, 0x8c, 0x78, 0x6c, 0x64, 0x70, 0x7c, 0x8c, 0x98, 0x90, 0x98, 0x84, 0x84, 0x88, 0x78, 0x78, 0x6c, 0x5c, 0x50, 0x50, 0x48, 0x50, 0x5c, 0x64, 0x64, 0x74, 0x78, 0x74, 0x64, 0x60, 0x58, 0x54, 0x50, 0x50, 0x58, 0x30, 0x34,  };
static const uint8 kSpr07A_Fireworks_DATA_03C6CE[84] = { 0x20, 0x30, 0x39, 0x47, 0x50, 0x60, 0x70, 0x7c, 0x7b, 0x80, 0x7d, 0x78, 0x6e, 0x60, 0x4f, 0x47, 0x41, 0x38, 0x30, 0x2a, 0x20, 0x10, 0x4, 0x0, 0x0, 0x8, 0x10, 0x20, 0x1a, 0x10, 0xa, 0x6, 0xf, 0x17, 0x16, 0x1c, 0x1f, 0x21, 0x10, 0x18, 0x20, 0x2c, 0x2e, 0x3b, 0x30, 0x30, 0x2d, 0x2a, 0x34, 0x36, 0x3a, 0x3f, 0x45, 0x4d, 0x5f, 0x54, 0x4e, 0x67, 0x70, 0x67, 0x70, 0x5c, 0x4e, 0x40, 0x48, 0x56, 0x57, 0x5f, 0x68, 0x72, 0x77, 0x6f, 0x66, 0x60, 0x67, 0x5c, 0x57, 0x4b, 0x4d, 0x54, 0x48, 0x43, 0x3d, 0x3c,  };
static const uint8 kSpr07A_Fireworks_DATA_03C722[84] = { 0x18, 0x1e, 0x25, 0x22, 0x1a, 0x17, 0x20, 0x30, 0x41, 0x4f, 0x61, 0x70, 0x7f, 0x8c, 0x94, 0x92, 0xa0, 0x86, 0x93, 0x88, 0x88, 0x78, 0x66, 0x50, 0x40, 0x30, 0x22, 0x20, 0x2c, 0x30, 0x40, 0x4f, 0x59, 0x51, 0x3f, 0x39, 0x4c, 0x5f, 0x6a, 0x6f, 0x77, 0x7e, 0x6c, 0x60, 0x58, 0x48, 0x3d, 0x2f, 0x28, 0x38, 0x44, 0x30, 0x36, 0x27, 0x21, 0x2f, 0x39, 0x2a, 0x2f, 0x39, 0x40, 0x3f, 0x49, 0x50, 0x60, 0x59, 0x4c, 0x51, 0x48, 0x4f, 0x56, 0x67, 0x5b, 0x68, 0x75, 0x7d, 0x87, 0x8a, 0x7a, 0x6b, 0x70, 0x82, 0x73, 0x92,  };
static const uint8 kSpr07C_PrincessPeach_InitialXLo[4] = { 0x60, 0xb0, 0x40, 0x80,  };
static const uint8 kSpr07A_Fireworks_FireworkSounds[4] = { 0x26, 0x0, 0x26, 0x28,  };
static const uint8 kSpr07A_Fireworks_FireworkSounds_WhistleCh3[4] = { 0x0, 0x2b, 0x0, 0x0,  };
static const uint8 kSpr07A_Fireworks_FireworkSounds_BangCh1[4] = { 0x27, 0x0, 0x27, 0x29,  };
static const uint8 kSpr07A_Fireworks_FireworkSounds_BangCh3[4] = { 0x0, 0x2c, 0x0, 0x0,  };
static const uint8 kSpr07C_PrincessPeach_DATA_03C78A[4] = { 0x0, 0xaa, 0xff, 0xaa,  };
static const uint8 kSpr07C_PrincessPeach_DATA_03C78E[4] = { 0x0, 0x7e, 0x27, 0x7e,  };
static const uint8 kSpr07C_PrincessPeach_DATA_03C792[4] = { 0xc0, 0xc0, 0xff, 0xc0,  };
static const uint8 kSpr07A_Fireworks_YSpeed[4] = { 0xe4, 0xe6, 0xe4, 0xe2,  };
static const uint8 kSpr07A_Fireworks_DATA_03C83D[4] = { 0x14, 0xc, 0x10, 0x15,  };
static const uint8 kSpr07A_Fireworks_DATA_03C841[4] = { 0x8, 0x10, 0xc, 0x5,  };
static const uint8 kSpr07A_Fireworks_DATA_03C889[4] = { 0xff, 0x80, 0xc0, 0xff,  };
static const uint8 kSpr07A_Fireworks_DATA_03C8F1[80] = { 0x6, 0x5, 0x4, 0x3, 0x3, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2,  };
static const uint8 kSpr07A_Fireworks_DATA_03C969[4] = { 0xec, 0x8e, 0xec, 0xec,  };
static const uint8 kSpr07A_Fireworks_DATA_03C9B9[40] = { 0x36, 0x35, 0xc7, 0x34, 0x34, 0x34, 0x34, 0x24, 0x3, 0x3, 0x36, 0x35, 0xc7, 0x34, 0x34, 0x24, 0x24, 0x24, 0x24, 0x3, 0x36, 0x35, 0xc7, 0x34, 0x34, 0x34, 0x24, 0x24, 0x3, 0x24, 0x36, 0x35, 0xc7, 0x34, 0x24, 0x24, 0x24, 0x24, 0x24, 0x3,  };
static const uint8 kSpr07A_Fireworks_DATA_03C9E1[8] = { 0x0, 0x1, 0x1, 0x0, 0x0, 0xff, 0xff, 0x0,  };
static const uint8 kSpawnFootball_xlo[2] = { 0x14, 0xec,  };
static const uint8 kSpawnFootball_xhi[2] = { 0x0, 0xff,  };
static const uint8 kSpawnFootball_InitialXSpeed[2] = { 0x18, 0xe8,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_SpawningXPos[8] = { 0x18, 0x38, 0x58, 0x78, 0x98, 0xb8, 0xd8, 0x78,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_LemmySpawningYPos[8] = { 0x40, 0x50, 0x50, 0x40, 0x30, 0x40, 0x50, 0x40,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_DATA_03CC48[9] = { 0x50, 0x4a, 0x50, 0x4a, 0x4a, 0x40, 0x4a, 0x48, 0x4a,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_DATA_03CC51[9] = { 0x2, 0x4, 0x6, 0x8, 0xb, 0xc, 0xe, 0x10, 0x13,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_SpawningPositionIndexes[48] = { 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_DummyIDs[2] = { 0x10, 0x20,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_LemmyAndWendyAnimationFrames[144] = { 0x2, 0x2, 0x2, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x4, 0x5, 0x5, 0x4, 0x5, 0x5, 0x4, 0x5, 0x5, 0x4, 0x4, 0x4, 0x4, 0x6, 0x6, 0x6, 0x6, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x6, 0x6, 0x6, 0x6, 0x8, 0x8, 0x8, 0x8, 0x8, 0x9, 0x9, 0x8, 0x8, 0x9, 0x9, 0x8, 0x8, 0x8, 0x8, 0x8, 0xb, 0xb, 0xb, 0xb, 0xb, 0xa, 0xb, 0xa, 0xb, 0xa, 0xb, 0xa, 0xb, 0xb, 0xb, 0xb, 0xc, 0xc, 0xc, 0xc, 0xd, 0xc, 0xd, 0xc, 0xd, 0xc, 0xd, 0xc, 0xd, 0xd, 0xd, 0xd, 0xe, 0xe, 0xe, 0xe, 0xe, 0xf, 0xe, 0xf, 0xe, 0xf, 0xe, 0xf, 0xe, 0xe, 0xe, 0xe, 0x10, 0x10, 0x10, 0x10, 0x11, 0x12, 0x11, 0x10, 0x11, 0x12, 0x11, 0x10, 0x11, 0x11, 0x11, 0x11, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_DummyHurtFrames[4] = { 0x16, 0x16, 0x15, 0x14,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_LemmyXDisp[138] = { 0xf8, 0x8, 0xf8, 0x8, 0x0, 0x0, 0xf8, 0x8, 0xf8, 0x8, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfb, 0x0, 0xfb, 0x3, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x8, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x0, 0x8, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x6, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x2, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x4, 0x0, 0x8, 0xf8, 0x8, 0x0, 0x0, 0x8, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x8, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x8, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x8, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_WendyXDisp[138] = { 0xf8, 0x8, 0xf8, 0x8, 0x0, 0x0, 0xf8, 0x8, 0xf8, 0x8, 0x0, 0x0, 0xf8, 0x0, 0x8, 0x0, 0x0, 0x0, 0xfb, 0x0, 0xfb, 0x3, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x8, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x0, 0x8, 0x0, 0x0, 0x0, 0xf8, 0x0, 0x8, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x6, 0x0, 0x8, 0xf8, 0x8, 0x0, 0x2, 0x0, 0x8, 0xf8, 0x8, 0x0, 0x4, 0x0, 0x8, 0xf8, 0x8, 0x0, 0x0, 0x8, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x8, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x8, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x8, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xf8, 0x8, 0x0, 0x0, 0x0, 0x0,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_LemmyYDisp[138] = { 0x4, 0x4, 0x14, 0x14, 0x0, 0x0, 0x4, 0x4, 0x14, 0x14, 0x0, 0x0, 0x0, 0x8, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x8, 0xf8, 0xf8, 0x0, 0x0, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x5, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x5, 0x5, 0x0, 0xf8, 0x0, 0x0, 0x5, 0x5, 0x0, 0xf8, 0x0, 0x0, 0x5, 0x5, 0x0, 0xf, 0xf8, 0xf8, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x4, 0x4, 0x2, 0x0, 0x0, 0x0, 0x4, 0x4, 0x1, 0x0, 0x0, 0x0, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x5, 0x5, 0x0, 0x0, 0x0, 0x0, 0x5, 0x5, 0x3, 0x0, 0x0, 0x0, 0x5, 0x5, 0x4, 0x0, 0x0, 0x0,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_WendyYDisp[138] = { 0x4, 0x4, 0x14, 0x14, 0x0, 0x0, 0x4, 0x4, 0x14, 0x14, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xf8, 0xf8, 0x0, 0x0, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x5, 0x5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0x0, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x5, 0x5, 0x0, 0xf, 0xf8, 0xf8, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x4, 0x4, 0x2, 0x0, 0x0, 0x0, 0x4, 0x4, 0x1, 0x0, 0x0, 0x0, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x5, 0x5, 0x0, 0xf8, 0xf8, 0x0, 0x5, 0x5, 0x0, 0x0, 0x0, 0x0, 0x5, 0x5, 0x3, 0x0, 0x0, 0x0, 0x5, 0x5, 0x4, 0x0, 0x0, 0x0,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_LemmyTiles[138] = { 0x20, 0x20, 0x26, 0x26, 0x8, 0x0, 0x2e, 0x2e, 0x24, 0x24, 0x8, 0x0, 0x0, 0x28, 0x2, 0x0, 0x0, 0x0, 0x4, 0x28, 0x12, 0x12, 0x0, 0x0, 0x22, 0x22, 0x4, 0x12, 0x12, 0x0, 0x20, 0x20, 0x8, 0x0, 0x0, 0x0, 0x0, 0x28, 0x2, 0x0, 0x0, 0x0, 0xa, 0x28, 0x13, 0x0, 0x0, 0x0, 0x20, 0x20, 0xc, 0x2, 0x0, 0x0, 0x20, 0x20, 0xc, 0x2, 0x0, 0x0, 0x22, 0x22, 0x6, 0x3, 0x12, 0x12, 0x20, 0x20, 0x6, 0x12, 0x12, 0x0, 0x2a, 0x2a, 0x0, 0x0, 0x0, 0x0, 0x2c, 0x2c, 0x0, 0x0, 0x0, 0x0, 0x20, 0x20, 0x6, 0x12, 0x12, 0x0, 0x20, 0x20, 0x6, 0x12, 0x12, 0x0, 0x22, 0x22, 0x8, 0x0, 0x0, 0x0, 0x20, 0x20, 0x8, 0x0, 0x0, 0x0, 0x2e, 0x2e, 0x8, 0x0, 0x0, 0x0, 0x4e, 0x4e, 0x60, 0x43, 0x43, 0x0, 0x4e, 0x4e, 0x64, 0x0, 0x0, 0x0, 0x62, 0x62, 0x64, 0x0, 0x0, 0x0, 0x62, 0x62, 0x64, 0x0, 0x0, 0x0,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_WendyTiles[138] = { 0x20, 0x20, 0x26, 0x26, 0x48, 0x0, 0x2e, 0x2e, 0x24, 0x24, 0x48, 0x0, 0x40, 0x28, 0x42, 0x0, 0x0, 0x0, 0x44, 0x28, 0x52, 0x52, 0x0, 0x0, 0x22, 0x22, 0x44, 0x52, 0x52, 0x0, 0x20, 0x20, 0x48, 0x0, 0x0, 0x0, 0x40, 0x28, 0x42, 0x0, 0x0, 0x0, 0x4a, 0x28, 0x53, 0x0, 0x0, 0x0, 0x20, 0x20, 0x4c, 0x1e, 0x1f, 0x0, 0x20, 0x20, 0x4c, 0x1f, 0x1e, 0x0, 0x22, 0x22, 0x44, 0x3, 0x52, 0x52, 0x20, 0x20, 0x44, 0x52, 0x52, 0x0, 0x2a, 0x2a, 0x0, 0x0, 0x0, 0x0, 0x2c, 0x2c, 0x0, 0x0, 0x0, 0x0, 0x20, 0x20, 0x46, 0x52, 0x52, 0x0, 0x20, 0x20, 0x46, 0x52, 0x52, 0x0, 0x22, 0x22, 0x48, 0x0, 0x0, 0x0, 0x20, 0x20, 0x48, 0x0, 0x0, 0x0, 0x2e, 0x2e, 0x48, 0x0, 0x0, 0x0, 0x4e, 0x4e, 0x66, 0x68, 0x68, 0x0, 0x4e, 0x4e, 0x6a, 0x0, 0x0, 0x0, 0x62, 0x62, 0x6a, 0x0, 0x0, 0x0, 0x62, 0x62, 0x6a, 0x0, 0x0, 0x0,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_LemmyProp[138] = { 0x5, 0x45, 0x5, 0x45, 0x5, 0x0, 0x5, 0x45, 0x5, 0x45, 0x5, 0x0, 0x5, 0x5, 0x5, 0x0, 0x0, 0x0, 0x5, 0x5, 0x5, 0x45, 0x0, 0x0, 0x5, 0x45, 0x5, 0x5, 0x45, 0x0, 0x5, 0x45, 0x5, 0x0, 0x0, 0x0, 0x5, 0x5, 0x5, 0x0, 0x0, 0x0, 0x5, 0x5, 0x5, 0x0, 0x0, 0x0, 0x5, 0x45, 0x5, 0x5, 0x0, 0x0, 0x5, 0x45, 0x45, 0x45, 0x0, 0x0, 0x5, 0x45, 0x5, 0x5, 0x5, 0x45, 0x5, 0x45, 0x45, 0x5, 0x45, 0x0, 0x5, 0x45, 0x0, 0x0, 0x0, 0x0, 0x5, 0x45, 0x0, 0x0, 0x0, 0x0, 0x5, 0x45, 0x45, 0x5, 0x45, 0x0, 0x5, 0x45, 0x5, 0x5, 0x45, 0x0, 0x5, 0x45, 0x5, 0x0, 0x0, 0x0, 0x5, 0x45, 0x5, 0x0, 0x0, 0x0, 0x5, 0x45, 0x5, 0x0, 0x0, 0x0, 0x7, 0x47, 0x7, 0x7, 0x47, 0x0, 0x7, 0x47, 0x7, 0x0, 0x0, 0x0, 0x7, 0x47, 0x7, 0x0, 0x0, 0x0, 0x7, 0x47, 0x7, 0x0, 0x0, 0x0,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_WendyProp[138] = { 0x9, 0x49, 0x9, 0x49, 0x9, 0x0, 0x9, 0x49, 0x9, 0x49, 0x9, 0x0, 0x9, 0x9, 0x9, 0x0, 0x0, 0x0, 0x9, 0x9, 0x9, 0x49, 0x0, 0x0, 0x9, 0x49, 0x9, 0x9, 0x49, 0x0, 0x9, 0x49, 0x9, 0x0, 0x0, 0x0, 0x9, 0x9, 0x9, 0x0, 0x0, 0x0, 0x9, 0x9, 0x9, 0x0, 0x0, 0x0, 0x9, 0x49, 0x9, 0x9, 0x9, 0x0, 0x9, 0x49, 0x49, 0x49, 0x49, 0x0, 0x9, 0x49, 0x9, 0x9, 0x9, 0x49, 0x9, 0x49, 0x49, 0x9, 0x49, 0x0, 0x9, 0x49, 0x0, 0x0, 0x0, 0x0, 0x9, 0x49, 0x0, 0x0, 0x0, 0x0, 0x9, 0x49, 0x49, 0x9, 0x49, 0x0, 0x9, 0x49, 0x9, 0x9, 0x49, 0x0, 0x9, 0x49, 0x9, 0x0, 0x0, 0x0, 0x9, 0x49, 0x9, 0x0, 0x0, 0x0, 0x9, 0x49, 0x9, 0x0, 0x0, 0x0, 0x5, 0x45, 0x5, 0x5, 0x45, 0x0, 0x5, 0x45, 0x5, 0x0, 0x0, 0x0, 0x5, 0x45, 0x5, 0x0, 0x0, 0x0, 0x5, 0x45, 0x5, 0x0, 0x0, 0x0,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_LemmyTileSize[138] = { 0x2, 0x2, 0x2, 0x2, 0x2, 0x4, 0x2, 0x2, 0x2, 0x2, 0x2, 0x4, 0x2, 0x2, 0x0, 0x4, 0x4, 0x4, 0x2, 0x2, 0x0, 0x0, 0x4, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x0, 0x4, 0x4, 0x4, 0x2, 0x2, 0x0, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x0, 0x4, 0x4, 0x2, 0x2, 0x2, 0x0, 0x4, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x0, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x4, 0x4, 0x4, 0x4, 0x2, 0x2, 0x4, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_WendyTileSize[138] = { 0x2, 0x2, 0x2, 0x2, 0x2, 0x4, 0x2, 0x2, 0x2, 0x2, 0x2, 0x4, 0x2, 0x2, 0x0, 0x4, 0x4, 0x4, 0x2, 0x2, 0x0, 0x0, 0x4, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x0, 0x4, 0x4, 0x4, 0x2, 0x2, 0x0, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x0, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x4, 0x4, 0x4, 0x4, 0x2, 0x2, 0x4, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x0, 0x0, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_NumberOfTilesToDrawForLemmy[23] = { 0x4, 0x4, 0x2, 0x3, 0x4, 0x2, 0x2, 0x2, 0x3, 0x3, 0x5, 0x4, 0x1, 0x1, 0x4, 0x4, 0x2, 0x2, 0x2, 0x4, 0x2, 0x2, 0x2,  };
static const uint8 kSpr029_KoopaKid_WendyLemmy_NumberOfTilesToDrawForWendy[23] = { 0x4, 0x4, 0x2, 0x3, 0x4, 0x2, 0x2, 0x2, 0x4, 0x4, 0x5, 0x4, 0x1, 0x1, 0x4, 0x4, 0x2, 0x2, 0x2, 0x4, 0x2, 0x2, 0x2,  };
static const uint8 kSpr0A9_Reznor_DATA_03D700[12] = { 0xb0, 0xa0, 0x90, 0x80, 0x70, 0x60, 0x50, 0x40, 0x30, 0x20, 0x10, 0x0,  };
static const uint8 kGameMode12_PrepareLevel_IggyPlatformTiles[256] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 22, 23, 24, 23, 24, 23, 24, 23, 24, 25, 26, 0, 0, 0, 0, 1, 2, 3, 4, 3, 4, 3, 4, 3, 4, 5, 18, 0, 0, 0, 0, 0, 7, 4, 3, 4, 3, 4, 3, 4, 3, 8, 0, 0, 0, 0, 0, 0, 9, 10, 4, 3, 4, 3, 4, 3, 11, 12, 0, 0, 0, 0, 0, 0, 0, 13, 14, 4, 3, 4, 3, 15, 16, 0, 0, 0, 0, 0, 0, 0, 0, 17, 2, 3, 4, 3, 4, 5, 18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 4, 3, 4, 3, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 10, 4, 3, 11, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 3, 4, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  };
static const uint16 kGameMode12_PrepareLevel_DATA_03D8EC[54] = { 0xffff, 0xffff, 0xffff, 0x3424, 0xb25, 0x3626, 0x1b0e, 0x1c0c, 0x1d0d, 0x1e0e, 0x3929, 0x3a2a, 0x3b2b, 0x3826, 0x3020, 0x3121, 0x3727, 0x3828, 0xffff, 0x3222, 0x330e, 0x1c0c, 0x1d0d, 0x3c0e, 0x3d2d, 0xffff, 0x1707, 0x230e, 0x40e, 0x1c0c, 0x1d0d, 0x90e, 0x2c0e, 0x1a0a, 0xffff, 0x3424, 0x3b2b, 0xffff, 0x1707, 0x180e, 0x190e, 0x1a0a, 0x1202, 0x1303, 0x803, 0x503, 0x503, 0x1403, 0x1503, 0x503, 0x503, 0x803, 0x603, 0x1f0f,  };
static const uint8 kInitializeMode7TilemapsAndPalettes_GFXFile[5] = { 0xb, 0xb, 0xb, 0x21, 0x0,  };
static const uint8 kInitializeMode7TilemapsAndPalettes_DATA_03DE4E[64] = { 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x3f,  };
static const uint16 kUpdateMode7SpriteAnimations_DATA_03DEBB[2] = { 0x100, 0x110,  };
static const uint16 kUpdateMode7SpriteAnimations_DATA_03DEBF[4] = { 0x706e, 0x50ff, 0xfefe, 0x57ff,  };
static const uint16 kUpdateMode7SpriteAnimations_DATA_03DEC7[4] = { 0x7472, 0x5452, 0x3e3c, 0x5355,  };
static const uint16 kUpdateMode7SpriteAnimations_DATA_03DECF[4] = { 0x5676, 0xff56, 0xffff, 0xff51,  };
static const uint16 kUpdateMode7SpriteAnimations_DATA_03DED7[4] = { 0x320, 0x330, 0x340, 0x350,  };
static const uint8 kSpr0A0_ActivateBowserBattle_BowserPaletteTableIndex[8] = { 0x0, 0xe, 0x1c, 0x2a, 0x38, 0x46, 0x54, 0x62,  };

void Spr01B_Football(uint8 k) {  // 038012
  GenericGFXRtDraw1Tile16x16(k);
  if (flag_sprites_locked)
    return;
  SubOffscreen_Bank03_Entry1(k);
  CheckPlayerAndNormalSpriteCollisions(k);
  uint8 v1 = spr_decrementing_table1540[k];
  if (!v1)
    goto LABEL_5;
  if (v1 == 1) {
    SpawnContactEffectFromSide(k);
LABEL_5:
    HandleNormalSpriteGravity(k);
  }
  if ((spr_table1588[k] & 3) != 0)
    spr_xspeed[k] = -spr_xspeed[k];
  if ((spr_table1588[k] & 8) != 0)
    spr_yspeed[k] = 0;
  if ((spr_table1588[k] & 4) != 0 && !spr_decrementing_table1540[k]) {
    spr_table15f6[k] ^= 0x40;
    spr_yspeed[k] = kSpr01B_Football_DATA_03800E[GetRand() & 3];
    int8 v2 = spr_xspeed[k] + kSpr01B_Football_DATA_038007[(uint8)(spr_slope_surface_its_on[k] + 3)];
    if (v2 >= 0) {
      if ((uint8)v2 >= 0x20)
        v2 = 32;
    } else if ((uint8)v2 < 0xE0) {
      v2 = -32;
    }
    spr_xspeed[k] = v2;
  }
}

void Spr0C5_BigBooBoss(uint8 k) {  // 038087
  NormalSpriteBooDraw(k);
  FadingBooPaletteAnimation();
  uint8 v1 = spr_current_status[k];
  if (v1) {
    if (v1 == 8 && !flag_sprites_locked)
      kSpr0C5_BigBooBoss_BigBooBossPtrs[spr_table00c2[k]](k);
  } else {
    ++misc_currently_active_boss_end_cutscene;
    timer_end_level = -1;
    io_music_ch1 = 11;
  }
}

void Spr0C5_BigBooBoss_StoppedBeforeFadeIn(uint8 k) {  // 0380be
  spr_table1602[k] = 3;
  if (++spr_table1570[k] == 0x90) {
    spr_decrementing_table1540[k] = 8;
    ++spr_table00c2[k];
  }
}

void Spr0C5_BigBooBoss_FadingIn(uint8 k) {  // 0380d5
  if (!spr_decrementing_table1540[k]) {
    spr_decrementing_table1540[k] = 8;
    if (++sprites_big_boo_boss_palette_index == 2)
      io_sound_ch1 = 16;
    if (sprites_big_boo_boss_palette_index == 7) {
      ++spr_table00c2[k];
      spr_decrementing_table1540[k] = 64;
    }
  }
}

void Spr0C5_BigBooBoss_FloatingAroundWhileInvisible(uint8 k) {  // 038106
  if (!spr_decrementing_table1540[k]) {
    spr_table00c2[k] = 0;
    spr_table1570[k] = 64;
  }
  spr_table1602[k] = 3;
  Spr0C5_BigBooBoss_03811F(k);
}

void Spr0C5_BigBooBoss_FloatingAroundWhileVisible(uint8 k) {  // 038119
  spr_table1602[k] = 0;
  Spr0C5_BigBooBoss_0381E4(k);
  Spr0C5_BigBooBoss_03811F(k);
}

void Spr0C5_BigBooBoss_03811F(uint8 k) {  // 03811f
  uint8 v1 = spr_decrementing_table15ac[k];
  if (!v1) {
    if (CheckPlayerPositionRelativeToSprite_Bank23_X(k) == spr_table157c[k])
      goto LABEL_7;
    v1 = 31;
    spr_decrementing_table15ac[k] = 31;
  }
  if (v1 == 16) {
    spr_table157c[k] ^= 1;
    v1 = 16;
  }
  spr_table1602[k] = kSpr0C5_BigBooBoss_DATA_038102[v1 >> 3];
LABEL_7:
  if ((counter_local_frames & 7) == 0) {
    uint8 v2 = spr_table151c[k] & 1;
    uint8 v3 = kSpr0C5_BigBooBoss_XAcceleration[v2] + spr_xspeed[k];
    spr_xspeed[k] = v3;
    if (v3 == kSpr0C5_BigBooBoss_MaxXSpeed[v2])
      ++spr_table151c[k];
  }
  if ((counter_local_frames & 7) == 0) {
    uint8 v4 = spr_table1528[k] & 1;
    uint8 v5 = kSpr0C5_BigBooBoss_YAcceleration[v4] + spr_yspeed[k];
    spr_yspeed[k] = v5;
    if (v5 == kSpr0C5_BigBooBoss_MaxYSpeed[v4])
      ++spr_table1528[k];
  }
  UpdateNormalSpritePosition_X(k);
  UpdateNormalSpritePosition_Y(k);
}

void Spr0C5_BigBooBoss_Hurt(uint8 k) {  // 03818b
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    spr_table15f6[k] ^= v1 & 0xE;
    spr_table1602[k] = 3;
  } else {
    ++spr_table00c2[k];
    spr_decrementing_table1540[k] = 8;
    InitializeNormalSpriteRAMTables_YXPPCCCTAndPropertyTables(k);
    if (++spr_table1534[k] == 3) {
      spr_table00c2[k] = 6;
      DespawnNonBossSprites();
    }
  }
}

void Spr0C5_BigBooBoss_FadingOut(uint8 k) {  // 0381bc
  if (!spr_decrementing_table1540[k]) {
    spr_decrementing_table1540[k] = 8;
    if (!--sprites_big_boo_boss_palette_index) {
      ++spr_table00c2[k];
      spr_decrementing_table1540[k] = -64;
    }
  }
}

void Spr0C5_BigBooBoss_Dying(uint8 k) {  // 0381d3
  spr_current_status[k] = 2;
  spr_xspeed[k] = 0;
  spr_yspeed[k] = -48;
  io_sound_ch1 = 35;
}

void Spr0C5_BigBooBoss_0381E4(uint8 k) {  // 0381e4
  uint8 j = 11;
  CollInfo ci;
  while (1) {
    if (spr_current_status[j] == 9 || spr_current_status[j] == 10) {
      StandardSpriteToSpriteCollisionChecks_GetSpriteClippingB(j, &ci);
      StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k, &ci);
      if (StandardSpriteToSpriteCollisionChecks_CheckContact(&ci))
        break;
    }
    if ((--j & 0x80) != 0)
      return;
  }
  spr_table00c2[k] = 3;
  spr_decrementing_table1540[k] = 64;
  spr_current_status[j] = 0;
  blocks_xpos = GetSprXPos(j);
  blocks_ypos = GetSprYPos(j);
  SpawnBrickPieces(0xFF);
  io_sound_ch3 = 40;
}

void FadingBooPaletteAnimation() {  // 038239
  unsigned int v4;

  mirror_color_math_select_and_enable = 36;
  uint8 v0 = sprites_big_boo_boss_palette_index - 1;
  if (sprites_big_boo_boss_palette_index < 8) {
    mirror_color_math_select_and_enable = 52;
    v0 = sprites_big_boo_boss_palette_index;
  }
  uint8 v1 = 16 * v0;
  uint8 r0 = 0;
  uint8 v2 = palettes_dynamic_palette_upload_index;
  do {
    palettes_dynamic_palette_colors[v2++] = *((uint8 *)kBooFadePalettes + v1++);
    ++r0;
  } while (r0 != 16);
  uint8 v3 = palettes_dynamic_palette_upload_index;
  v4 = palettes_dynamic_palette_upload_index;
  *(&palettes_dynamic_palette_bytes_to_upload + palettes_dynamic_palette_upload_index) = 16;
  *(&palettes_dynamic_palette_cgramaddress + v4) = -16;
  palettes_dynamic_palette_colors[v3 + 16] = 0;
  palettes_dynamic_palette_upload_index = v3 + 18;
}

void NormalSpriteBooDraw(uint8 k) {  // 0383a0
  GetDrawInfoRes drt;

  if (spr_spriteid[k] == 55) {
    uint8 v1 = 0;
    if (spr_table00c2[k]) {
      v1 = 6;
      uint8 v2 = spr_decrementing_table1558[k];
      if (v2)
        v1 = ((uint8)(v2 & 4) >> 2) + 2;
    }
    spr_table1602[k] = v1;
    GenericGFXRtDraw1Tile16x16(k);
  } else {
    if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
      return;
    uint8 r6 = spr_table1602[k];
    uint8 r3 = 4 * r6;
    uint8 r2 = 4 * r6 + 16 * r6;
    uint8 r4 = spr_table157c[k];
    uint8 r5 = spr_table15f6[k];
    uint8 v4 = 0;
    do {
      uint8 v12 = v4;
      uint8 v5 = r2;
      OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
      oam[64].charnum = kNormalSpriteBooGFXRt_BigBooTiles[r2];
      uint8 a = r5 | kNormalSpriteBooGFXRt_BigBooProp[v5];
      if (!(r4 & 1))
        a ^= 0x40;
      oam[64].flags = sprites_tile_priority | a;
      uint8 v7 = kNormalSpriteBooGFXRt_BigBooXDisp[v5];
      if (!(r4 & 1))
        v7 = 40 - v7;
      oam[64].xpos = drt.x + v7;
      uint8 v8 = v12;
      if (r6 >= 3)
        v8 = v12 + 20;
      oam[64].ypos = kNormalSpriteBooGFXRt_BigBooYDisp[v8] + drt.y;
      drt.idx += 4;
      ++r2;
      v4 = v12 + 1;
    } while (v4 != 20);
    uint8 v9 = spr_current_slotid;
    if (spr_table1602[spr_current_slotid] == 3 && spr_decrementing_table1558[spr_current_slotid]) {
      OamEnt *v10 = get_OamEnt(oam_buf, spr_oamindex[spr_current_slotid]);
      int8 v11 = v10[64].ypos + 5;
      v10[64].ypos = v11;
      v10[65].ypos = v11;
    }
    FinishOAMWrite(v9, 2, 0x13);
  }
}

void Spr0C4_GreyFallingPlatform(uint8 k) {  // 038454
  Spr0C4_GreyFallingPlatform_Draw(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank03_Entry1(k);
    if (spr_yspeed[k]) {
      if (!spr_decrementing_table1540[k] && sign8(spr_yspeed[k] - 64))
        spr_yspeed[k] += 2;
      UpdateNormalSpritePosition_Y(k);
    }
    if (SolidSpriteBlock(k) & 1) {
      if (!spr_yspeed[k]) {
        spr_yspeed[k] = 3;
        spr_decrementing_table1540[k] = 24;
      }
    }
  }
}

void Spr0C4_GreyFallingPlatform_Draw(uint8 k) {  // 038492
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].xpos = kSpr0C4_GreyFallingPlatform_XDisp[i] + drt.x;
    oam[64].ypos = drt.y;
    oam[64].charnum = kSpr0C4_GreyFallingPlatform_Tiles[i];
    oam[64].flags = sprites_tile_priority | 3;
    drt.idx += 4;
  }
  FinishOAMWrite(k, 2, 3);
}

void Spr0C2_Blurp(uint8 k) {  // 0384ca
  GenericGFXRtDraw1Tile16x16(k);
  uint8 v1 = spr_oamindex[k];
  int8 v2 = -94;
  if ((spr_current_slotid + (counter_local_frames >> 3)) & 1)
    v2 = -20;
  get_OamEnt(oam_buf, v1)[64].charnum = v2;
  if (spr_current_status[k] == 8) {
    if (!flag_sprites_locked) {
      SubOffscreen_Bank03_Entry1(k);
      if ((counter_local_frames & 3) == 0) {
        uint8 v4 = spr_table00c2[k] & 1;
        uint8 v5 = kSpr0C2_Blurp_YAcceleration[v4] + spr_yspeed[k];
        spr_yspeed[k] = v5;
        if (v5 == kSpr0C2_Blurp_MaxYSpeed[v4])
          ++spr_table00c2[k];
      }
      spr_xspeed[k] = kSpr0C2_Blurp_XSpeed[spr_table157c[k]];
      UpdateNormalSpritePosition_X(k);
      UpdateNormalSpritePosition_Y(k);
      CheckPlayerAndNormalSpriteCollisions(k);
    }
  } else {
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam[64].flags |= 0x80;
  }
}

void Spr0C3_PorcuPuffer(uint8 k) {  // 03852f
  Spr0C3_PorcuPuffer_Draw(k);
  if (!flag_sprites_locked && spr_current_status[k] == 8) {
    SubOffscreen_Bank03_Entry1(k);
    CheckPlayerAndNormalSpriteCollisions(k);
    uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
    spr_table157c[k] = v1;
    if ((counter_local_frames & 3) == 0) {
      uint8 v2 = spr_xspeed[k];
      if (v2 != kSpr0C3_PorcuPuffer_PorcuPuffMaxSpeed[v1])
        spr_xspeed[k] = kSpr0C3_PorcuPuffer_PorcuPuffAccel[v1] + v2;
    }
    uint8 v4 = spr_xspeed[k];
    spr_xspeed[k] = v4 + 8 * misc_layer1_xdisp;
    UpdateNormalSpritePosition_X(k);
    spr_xspeed[k] = v4;
    HandleNormalSpriteLevelCollision(k);
    uint8 v3 = 4;
    if (spr_table164a[k])
      v3 = -4;
    spr_yspeed[k] = v3;
    UpdateNormalSpritePosition_Y(k);
  }
}

void Spr0C3_PorcuPuffer_Draw(uint8 k) {  // 0385a3
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r3 = counter_local_frames & 4;
  uint8 r2 = spr_table157c[k];
  uint8 v2 = 3;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].ypos = kSpr0C3_PorcuPuffer_PocruPufferDispY[v2] + drt.y;
    uint8 v4 = v2;
    if (!r2)
      v2 |= 4;
    oam[64].xpos = kSpr0C3_PorcuPuffer_PocruPufferDispX[v2] + drt.x;
    oam[64].flags = sprites_tile_priority | kSpr0C3_PorcuPuffer_PocruPufferGfxProp[v2];
    oam[64].charnum = kSpr0C3_PorcuPuffer_PocruPufferTiles[r3 | v4];
    drt.idx += 4;
    v2 = v4 - 1;
  } while ((int8)v2 >= 0);
  FinishOAMWrite(k, 2, 3);
}

void Spr0C1_WingedPlatform(uint8 k) {  // 0385f6
  Spr0C1_WingedPlatform_Draw(k);
  if (!flag_sprites_locked) {
    if (flag_active_fast_background_scroll_generator) {
      uint8 v1 = spr_table1534[k];
      spr_table1534[k] = v1 + 1;
      if ((v1 & 1) == 0 && --spr_table1602[k] == 0xFF) {
        spr_table1602[k] = -1;
        ++spr_table157c[k];
      }
      spr_yspeed[k] = kSpr0C1_WingedPlatform_FlyingBlockSpeedY[spr_table157c[k] & 1];
    }
    uint8 v3 = spr_yspeed[k];
    if (!spr_table151c[k])
      spr_yspeed[k] = -spr_yspeed[k];
    UpdateNormalSpritePosition_Y(k);
    spr_yspeed[k] = v3;
    spr_xspeed[k] = flag_active_fast_background_scroll_generator;
    spr_table1528[k] = UpdateNormalSpritePosition_X(k);
    if (SolidSpriteBlock(k) & 1) {
      if (!flag_active_fast_background_scroll_generator) {
        flag_active_fast_background_scroll_generator = 8;
        spr_table1602[k] = 127;
        uint8 v2 = 9;
        while (v2 == spr_current_slotid || spr_spriteid[v2] != 0xC1) {
          if ((--v2 & 0x80) != 0) {
            ++v2;
            break;
          }
        }
        spr_table1602[v2] = 127;
      }
    }
  }
}

void Spr0C1_WingedPlatform_Draw(uint8 k) {  // 0386a8
  GetDrawInfoRes drt;
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 v1 = spr_oamindex[k];
  uint8 v2 = (counter_local_frames >> 1) & 4;
  if (v2)
    ++v2;
  uint8 r2 = v2;
  uint8 v3 = 4;
  do {
    uint8 v4 = r2 + v3;
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam[64].xpos = kSpr0C1_WingedPlatform_XDisp[v4] + drt.x;
    oam[64].ypos = kSpr0C1_WingedPlatform_YDisp[v4] + drt.y;
    oam[64].charnum = kSpr0C1_WingedPlatform_Tiles[v4];
    oam[64].flags = kSpr0C1_WingedPlatform_Prop[v4];
    sprites_oamtile_size_buffer[(v1 >> 2) + 64] = kSpr0C1_WingedPlatform_TileSize[v4];
    v1 += 4;
    v3 = v3 - 1;
  } while ((int8)v3 >= 0);
  FinishOAMWrite(k, 0xFF, 4);
}

void Spr0C0_SinkingLavaPlatform(uint8 k) {  // 0386ff
  Spr0C0_SinkingLavaPlatform_Draw(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank03_Entry1(k);
    if (spr_decrementing_table1540[k] == 1) {
      sprites_load_status[spr_load_status_table_index[k]] = 0;
      spr_current_status[k] = 0;
    } else {
      UpdateNormalSpritePosition_Y(k);
      if (SolidSpriteBlock(k) & 1) {
        if (!spr_decrementing_table1540[k]) {
          spr_yspeed[k] = 6;
          spr_decrementing_table1540[k] = 64;
        }
      }
    }
  }
}

void Spr0C0_SinkingLavaPlatform_Draw(uint8 k) {  // 03873a
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  for (uint8 i = 2; (i & 0x80) == 0; --i) {
    uint8 v3 = drt.x;
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].xpos = drt.x;
    drt.x = v3 + 16;
    oam[64].ypos = drt.y;
    oam[64].charnum = kSpr0C0_SinkingLavaPlatform_LavaPlatTiles[i];
    oam[64].flags = sprites_tile_priority | kSpr0C0_SinkingLavaPlatform_DATA_038737[i];
    drt.idx += 4;
  }
  FinishOAMWrite(k, 2, 2);
}

void Spr0BF_MegaMole(uint8 k) {  // 038770
  Spr0BF_MegaMole_Draw(k);
  if (spr_current_status[k] == 8) {
    SubOffscreen_Bank03_Entry4(k);
    spr_xspeed[k] = kSpr0BF_MegaMole_MegaMoleSpeed[spr_table157c[k]];
    if (!flag_sprites_locked) {
      int8 v5 = spr_table1588[k] & 4;
      HandleNormalSpriteGravity(k);
      CheckNormalSpriteToNormalSpriteCollision(k);
      if ((spr_table1588[k] & 4) != 0) {
        spr_yspeed[k] = 0;
      } else {
        if (v5)
          spr_decrementing_table1540[k] = 10;
        if (spr_decrementing_table1540[k])
          spr_yspeed[k] = 0;
      }
      uint8 v1 = spr_decrementing_table15ac[k];
      if ((spr_table1588[k] & 3) != 0) {
        if (!v1)
          spr_decrementing_table15ac[k] = 16;
        spr_table157c[k] ^= 1;
      }
      if (!v1)
        spr_table151c[k] = spr_table157c[k];
      if (CheckPlayerToNormalSpriteCollision(k) & 1) {
        if (sign8(player_ypos - GetSprYPos(k) + 40)) {
          if ((player_yspeed & 0x80) == 0) {
            misc_player_on_solid_sprite = 1;
            spr_decrementing_table154c[k] = 6;
            player_yspeed = 0;
            player_ypos = GetSprYPos(k) + (player_riding_yoshi_flag ? -58 : -42);
            player_xpos += (int8)sprites_position_disp;
          }
        } else if (!(spr_table15d0[k] | spr_decrementing_table154c[k])) {
          DamagePlayer_Hurt();
        }
      }
    }
  }
}

void Spr0BF_MegaMole_Draw(uint8 k) {  // 03883f
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r2 = spr_table151c[k];
  uint8 r3 = 4 * ((spr_current_slotid + (counter_local_frames >> 2)) & 1);
  uint8 v2 = 3;
  do {
    uint8 v5 = v2;
    if (!r2)
      v2 += 4;
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].xpos = kSpr0BF_MegaMole_TileDispX[v2] + drt.x;
    oam[64].ypos = kSpr0BF_MegaMole_TileDispY[v5] + drt.y;
    oam[64].charnum = kSpr0BF_MegaMole_Tiles[(uint8)(r3 + v5)];
    int8 v4 = 1;
    if (!r2)
      v4 = 65;
    oam[64].flags = sprites_tile_priority | v4;
    drt.idx += 4;
    v2 = v5 - 1;
  } while ((int8)v2 >= 0);
  FinishOAMWrite(k, 2, 3);
}

void Spr0BE_Swooper(uint8 k) {  // 0388a3
  GenericGFXRtDraw1Tile16x16(k);
  uint8 v1 = spr_oamindex[k];
  get_OamEnt(oam_buf, v1)[64].charnum = kSpr0BE_Swooper_Tiles[spr_table1602[k]];
  if (spr_current_status[k] == 8) {
    if (!flag_sprites_locked) {
      SubOffscreen_Bank03_Entry1(k);
      CheckPlayerAndNormalSpriteCollisions(k);
      UpdateNormalSpritePosition_X(k);
      UpdateNormalSpritePosition_Y(k);
      kUnk_388d9[spr_table00c2[k]](k);
    }
  } else {
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam[64].flags |= 0x80;
  }
}

void Spr0BE_Swooper_Waiting(uint8 k) {  // 0388e4
  if (!spr_xoffscreen_flag[k]) {
    uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
    if ((uint8)(player_xpos - GetSprXPos(k) + 80) < 0xA0) {
      ++spr_table00c2[k];
      spr_table157c[k] = v1;
      spr_yspeed[k] = 32;
      io_sound_ch3 = 38;
    }
  }
}

void Spr0BE_Swooper_Swooping(uint8 k) {  // 038905
  if ((counter_global_frames & 3) == 0) {
    if (spr_yspeed[k]) {
      if (spr_yspeed[k]-- == 1)
        ++spr_table00c2[k];
    }
  }
  Spr0BE_Swooper_038915(k);
}

void Spr0BE_Swooper_038915(uint8 k) {  // 038915
  if ((counter_global_frames & 3) == 0) {
    uint8 v1 = spr_table157c[k];
    uint8 v2 = spr_xspeed[k];
    if (v2 != kSpr0BE_Swooper_MaxXSpeed[v1])
      spr_xspeed[k] = kSpr0BE_Swooper_XAcceleration[v1] + v2;
  }
  spr_table1602[k] = ((uint8)(counter_local_frames & 4) >> 2) + 1;
}

void Spr0BE_Swooper_FlyStraight(uint8 k) {  // 038936
  if ((counter_global_frames & 1) == 0) {
    uint8 v1 = spr_table151c[k] & 1;
    uint8 v2 = kSpr0C2_Blurp_YAcceleration[v1] + spr_yspeed[k];
    spr_yspeed[k] = v2;
    if (v2 == kSpr0C2_Blurp_MaxYSpeed[v1])
      ++spr_table151c[k];
  }
  Spr0BE_Swooper_038915(k);
}

void Spr0BD_SlidingNakedBlueKoopa(uint8 k) {  // 038958
  uint8 v1 = 0;
  int8 v2 = spr_xspeed[k];
  if (v2) {
    if (v2 < 0)
      v1 = 1;
    spr_table157c[k] = v1;
  }
  GenericGFXRtDraw1Tile16x16(k);
  uint8 v3 = spr_oamindex[k];
  uint8 v4 = spr_decrementing_table1558[k];
  bool v5 = v4 != 0;
  if (v4 == 1) {
    uint8 v14 = spr_table157c[k];
    spr_spriteid[k] = 2;
    InitializeNormalSpriteRAMTables(k);
    spr_table157c[k] = v14;
    v5 = 1;
  }
  int8 v6 = -122;
  if (v5)
    v6 = -32;
  get_OamEnt(oam_buf, v3)[64].charnum = v6;
  if (spr_current_status[k] == 8) {
    SubOffscreen_Bank03_Entry1(k);
    CheckPlayerAndNormalSpriteCollisions(k);
    if (!(spr_decrementing_table1558[k] | (uint8)(spr_decrementing_table1540[k] | flag_sprites_locked))) {
      HandleNormalSpriteGravity(k);
      if ((spr_table1588[k] & 4) != 0) {
        Spr0BD_SlidingNakedBlueKoopa_0389FF(k);
        uint8 v7 = 0;
        int8 v8 = spr_xspeed[k];
        if (v8) {
          if (v8 < 0)
            v8 = -v8;
          uint8 r0 = v8;
          uint8 v9 = spr_slope_surface_its_on[k];
          if (v9) {
            v7 = r0;
            if (((spr_xspeed[k] ^ v9) & 0x80) != 0)
              v7 = -48;
          }
        }
        spr_yspeed[k] = v7;
        if ((counter_global_frames & 1) == 0) {
          uint8 v10 = spr_slope_surface_its_on[k];
          if (v10) {
            uint8 v12 = (4 * v10 + __CFSHL__(v10, 1)) & 1;
            uint8 v13 = spr_xspeed[k];
            if (v13 != kSpr0BD_SlidingNakedBlueKoopa_MaxXSpeed[v12])
              spr_xspeed[k] = kSpr0BD_SlidingNakedBlueKoopa_XAcceleration[v12] + v13;
          } else {
            int8 v11 = spr_xspeed[k];
            if (v11) {
              if (v11 < 0) {
                ++spr_xspeed[k];
                ++spr_xspeed[k];
              }
              --spr_xspeed[k];
            } else {
              spr_decrementing_table1558[k] = 32;
            }
          }
        }
      }
    }
  }
}

void Spr0BD_SlidingNakedBlueKoopa_0389FF(uint8 k) {  // 0389ff
  if (spr_xspeed[k]) {
    if ((counter_global_frames & 3) == 0) {
      uint8 r0 = 4;
      uint8 r1 = 10;
      if (!CheckIfNormalSpriteOffScreen(k)) {
        uint8 v1 = 3;
        while (smoke_spr_spriteid[v1]) {
          if ((--v1 & 0x80) != 0)
            return;
        }
        smoke_spr_spriteid[v1] = 3;
        smoke_spr_xpos_lo[v1] = r0 + spr_xpos_lo[k];
        smoke_spr_ypos_lo[v1] = r1 + spr_ypos_lo[k];
        smoke_spr_timer[v1] = 19;
      }
    }
  }
}

void Spr0BC_BowserStatue(uint8 k) {  // 038a3c
  Spr0BC_BowserStatue_Draw(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank03_Entry1(k);
    uint8 v1 = spr_table00c2[k];
    if (!v1)
      goto LABEL_8;
    if (v1 == 1) {
LABEL_7:
      Spr0BC_BowserStatue_038ACB(k);
LABEL_8:
      SolidSpriteBlock(k);
      HandleNormalSpriteGravity(k);
      if ((spr_table1588[k] & 4) != 0)
        spr_yspeed[k] = 0;
      return;
    }
    if (v1 != 2) {
      if (v1 != 3) {
        Unreachable();
        return;
      }
      goto LABEL_7;
    }
    spr_property_bits167a[k] *= 2;
    spr_property_bits167a[k] >>= 1;
    CheckPlayerToNormalSpriteCollision(k);
    spr_table1602[k] = 0;
    if (sign8(spr_yspeed[k] - 16))
      ++spr_table1602[k];
    HandleNormalSpriteGravity(k);
    if ((spr_table1588[k] & 3) != 0) {
      spr_xspeed[k] = -spr_xspeed[k];
      spr_table157c[k] ^= 1;
    }
    if ((spr_table1588[k] & 4) != 0) {
      spr_yspeed[k] = 16;
      spr_xspeed[k] = 0;
      uint8 v2 = spr_decrementing_table1540[k];
      if (v2) {
        if (v2 == 1) {
          spr_yspeed[k] = -64;
          uint8 v3 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
          spr_table157c[k] = v3;
          spr_xspeed[k] = kSpr0BC_BowserStatue_XSpeed[v3];
        }
      } else {
        spr_decrementing_table1540[k] = 48;
      }
    }
  }
}

void Spr0BC_BowserStatue_038ACB(uint8 k) {  // 038acb
  if (((counter_global_frames + __CFSHL__(2 * k, 1) + 4 * k) & 0x7F) == 0) {
    uint8 j = FindFreeNormalSpriteSlot_HighPriority();
    if ((j & 0x80) == 0) {
      io_sound_ch3 = 23;
      spr_current_status[j] = 8;
      spr_spriteid[j] = -77;
      uint8 v2 = spr_table157c[k];
      SetSprXPos(j, GetSprXPos(k) + PAIR16(kSpr0BC_BowserStatue_FireSpawnXDispXHi[v2], kSpr0BC_BowserStatue_FireSpawnXDispXLo[v2]));
      InitializeNormalSpriteRAMTables(j);
      SetSprYPos(j, GetSprYPos(k) - 2);
      spr_table157c[j] = spr_table157c[k];
    }
  }
}

void Spr0BC_BowserStatue_Draw(uint8 k) {  // 038b3d
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r4 = spr_table1602[k];
  uint8 r3 = (r4 ^ 1) - 1;
  uint8 r5 = spr_table15f6[k];
  uint8 r2 = spr_table157c[k];
  uint8 v2 = 2;
  do {
    uint8 v5 = v2;
    if (!r2)
      v2 += 3;
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].xpos = kSpr0BC_BowserStatue_XDisp[v2] + drt.x;
    oam[64].flags = sprites_tile_priority | r5 | kSpr0BC_BowserStatue_Prop[v2];
    uint8 v4 = v5;
    oam[64].ypos = kSpr0BC_BowserStatue_YDisp[v5] + drt.y;
    if (r4)
      v4 = v5 + 3;
    oam[64].charnum = kSpr0BC_BowserStatue_Tiles[v4];
    sprites_oamtile_size_buffer[(drt.idx >> 2) + 64] = kSpr0BC_BowserStatue_TileSize[v5];
    drt.idx += 4;
    v2 = v5 - 1;
  } while (v2 != r3);
  FinishOAMWrite(k, 0xFF, 2);
}

void Spr0B8_CarrotTopLiftUpperLeft(uint8 k) {  // 038c2f
  CollInfo ci;

  Spr0B7_CarrotTopLiftUpperRight_Draw(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank03_Entry1(k);
    if (!spr_decrementing_table1540[k]) {
      ++spr_table00c2[k];
      spr_decrementing_table1540[k] = 0x80;
    }
    spr_xspeed[k] = kSpr0B7_CarrotTopLiftUpperRight_DATA_038C2A[spr_table00c2[k] & 3];
    uint8 v1 = spr_xspeed[k];
    if (spr_spriteid[k] != 0xB8)
      v1 = -v1;
    spr_yspeed[k] = v1;
    UpdateNormalSpritePosition_Y(k);
    spr_table151c[k] = spr_xpos_lo[k];
    UpdateNormalSpritePosition_X(k);
    Spr0B7_CarrotTopLiftUpperRight_038CE4(k, &ci);
    StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k, &ci);
    if (StandardSpriteToSpriteCollisionChecks_CheckContact(&ci) && (player_yspeed & 0x80) == 0) {
      uint8 v2 = player_xpos - spr_table151c[k] + 28;
      if (spr_spriteid[k] == 0xB8)
        v2 = player_xpos - spr_table151c[k] + 84;
      uint8 v3 = v2;
      uint8 v4 = player_riding_yoshi_flag ? 48 : 32;
      if (sign8(kSpr0B7_CarrotTopLiftUpperRight_DATA_038BAA[v3] + spr_ypos_lo[k] - (player_ypos + v4))) {
        uint8 r0 = v4 - 3;
        player_ypos = GetSprYPos(k) + kSpr0B7_CarrotTopLiftUpperRight_DATA_038BAA[v3] - r0;
        player_yspeed = 0;
        misc_player_on_solid_sprite = 1;
        player_xpos += (int8)sprites_position_disp;
      }
    }
  }
}

void Spr0B7_CarrotTopLiftUpperRight_038CE4(uint8 k, CollInfo *ci) {  // 038ce4
  SetHiLo(&ci->r8, &ci->r0, player_xpos + 4);
  ci->r2 = 8;
  ci->r3 = 8;
  uint8 v1 = player_riding_yoshi_flag ? 48 : 32;
  SetHiLo(&ci->r9, &ci->r1, player_ypos + v1);
}

void Spr0B7_CarrotTopLiftUpperRight_Draw(uint8 k) {  // 038d24
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  bool v2 = spr_spriteid[k] < 0xB8;
  uint8 v3 = 2;
  uint8 r2 = 2;
  if (!v2)
    v3 = 5;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].xpos = kSpr0B7_CarrotTopLiftUpperRight_XDisp[v3] + drt.x;
    oam[64].ypos = kSpr0B7_CarrotTopLiftUpperRight_YDisp[v3] + drt.y;
    oam[64].charnum = kSpr0B7_CarrotTopLiftUpperRight_Tiles[v3];
    oam[64].flags = sprites_tile_priority | kSpr0B7_CarrotTopLiftUpperRight_Prop[v3];
    drt.idx += 4;
    --v3;
    --r2;
  } while ((r2 & 0x80) == 0);
  FinishOAMWrite(k, 2, 2);
}

void Spr0B9_MessageBox(uint8 k) {  // 038d6f
  SolidSpriteBlock(k);
  SubOffscreen_Bank03_Entry1(k);
  if (spr_decrementing_table1558[k] == 1) {
    io_sound_ch3 = 34;
    spr_decrementing_table1558[k] = 0;
    spr_table00c2[k] = 0;
    // When confused, the below value defaults to the Yoshi save msg.
    misc_display_message = ((spr_xpos_lo[k] & 0x10) != 0) + 1;
  }
  uint8 v1 = spr_decrementing_table1558[k] >> 1;
  uint16 old_pos = mirror_current_layer1_ypos;
  mirror_current_layer1_ypos += kSpr0B9_MessageBox_DATA_038D66[v1];
  GenericGFXRtDraw1Tile16x16(k);
  get_OamEnt(oam_buf, spr_oamindex[k])[64].charnum = -64;
  mirror_current_layer1_ypos = old_pos;
}

void Spr0BA_TimedPlatform(uint8 k) {  // 038dbb
  Spr0BA_TimedPlatform_Draw(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank03_Entry1(k);
    if (spr_table00c2[k] && spr_table1570[k])
      --spr_table1570[k];
    if (spr_table1570[k]) {
      spr_table1528[k] = UpdateNormalSpritePosition_X(k);
      if (SolidSpriteBlock(k) & 1) {
        spr_xspeed[k] = 16;
        spr_table00c2[k] = 16;
      }
    } else {
      HandleNormalSpriteGravity(k);
      spr_table1528[k] = sprites_position_disp;
      SolidSpriteBlock(k);
    }
  }
}

void Spr0BA_TimedPlatform_Draw(uint8 k) {  // 038e12
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 v5 = spr_table1570[k];
  uint8 r2 = kSpr0BA_TimedPlatform_NumberTiles[v5 >> 6];
  uint8 v2 = 2;
  if (v5 < 8)
    v2 = 1;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].xpos = kSpr0BA_TimedPlatform_XDisp[v2] + drt.x;
    oam[64].ypos = kSpr0BA_TimedPlatform_YDisp[v2] + drt.y;
    uint8 v4 = kSpr0BA_TimedPlatform_PlatformTiles[v2];
    if (v2 == 2)
      v4 = r2;
    oam[64].charnum = v4;
    oam[64].flags = sprites_tile_priority | kSpr0BA_TimedPlatform_Prop[v2];
    sprites_oamtile_size_buffer[(drt.idx >> 2) + 64] = kSpr0BA_TimedPlatform_TileSize[v2];
    drt.idx += 4;
    --v2;
  } while ((v2 & 0x80) == 0);
  FinishOAMWrite(k, 0xFF, 2);
}

void Spr0BB_MovingCastleStone(uint8 k) {  // 038e79
  Spr0BB_MovingCastleStone_Draw(k);
  if (!flag_sprites_locked) {
    if (!spr_decrementing_table1540[k])
      spr_decrementing_table1540[k] = kSpr0BB_MovingCastleStone_MovementTiming[++spr_table00c2[k] & 3];
    spr_xspeed[k] = kSpr0BB_MovingCastleStone_XSpeed[spr_table00c2[k] & 3];
    spr_table1528[k] = UpdateNormalSpritePosition_X(k);
    SolidSpriteBlock(k);
  }
}

void Spr0BB_MovingCastleStone_Draw(uint8 k) {  // 038eb4
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].xpos = kSpr0BB_MovingCastleStone_XDisp[i] + drt.x;
    oam[64].ypos = kSpr0BB_MovingCastleStone_YDisp[i] + drt.y;
    oam[64].charnum = kSpr0BB_MovingCastleStone_Tiles[i];
    oam[64].flags = sprites_tile_priority | 3;
    drt.idx += 4;
  }
  FinishOAMWrite(k, 2, 3);
}

void Spr0B3_BowserStatueFire(uint8 k) {  // 038eec
  Spr0B3_BowserStatueFire_Draw(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank03_Entry1(k);
    CheckPlayerToNormalSpriteCollision(k);
    spr_xspeed[k] = kSpr0B3_BowserStatueFire_XSpeed[spr_table157c[k]];
    UpdateNormalSpritePosition_X(k);
  }
}

void Spr0B3_BowserStatueFire_Draw(uint8 k) {  // 038f1b
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r2 = 2 * spr_table157c[k];
  uint8 r3 = 2 * ((counter_local_frames >> 1) & 3);
  int8 v2 = 1;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].ypos = drt.y;
    int8 v6 = v2;
    oam[64].xpos = kSpr0B3_BowserStatueFire_XDisp[(uint8)(r2 | v2)] + drt.x;
    uint8 v4 = r3 | v2;
    oam[64].charnum = kSpr0B3_BowserStatueFire_Tiles[v4];
    uint8 v5 = kSpr0B3_BowserStatueFire_Prop[v4];
    if (!r2)
      v5 ^= 0x40;
    oam[64].flags = sprites_tile_priority | v5;
    drt.idx += 4;
    v2 = v6 - 1;
  } while ((int8)v2 >= 0);
  FinishOAMWrite(k, 0, 1);
}

void SprXXX_ReflectingEnemy_ReflectingPodobooEntry(uint8 k) {  // 038f75
  SprXXX_ReflectingEnemy_ReflectingPodobooDraw(k);
  SprXXX_ReflectingEnemy_038FA4(k);
}

void SprXXX_ReflectingEnemy_ReflectingBooBuddiesEntry(uint8 k) {  // 038f7a
  spr_table157c[k] = (spr_xspeed[k] & 0x80) != 0;
  GenericGFXRtDraw1Tile16x16(k);
  uint8 v1 = spr_oamindex[k];
  uint8 r0 = (counter_local_frames & 0x10) != 0;
  get_OamEnt(oam_buf, v1)[64].charnum = kSprXXX_ReflectingEnemy_BooStreamTiles[(uint8)(r0 | (2 * (k & 3)))];
  SprXXX_ReflectingEnemy_038FA4(k);
}

void SprXXX_ReflectingEnemy_038FA4(uint8 k) {  // 038fa4
  if (spr_current_status[k] == 8 && !flag_sprites_locked) {
    if (!(spr_yoffscreen_flag[k] | (counter_local_frames ^ k) & 7) && spr_spriteid[k] == 0xB0)
      SprXXX_ReflectingEnemy_SpawnTrailingBoo(k);
    UpdateNormalSpritePosition_Y(k);
    UpdateNormalSpritePosition_X(k);
    HandleNormalSpriteLevelCollision(k);
    if ((spr_table1588[k] & 3) != 0)
      spr_xspeed[k] = -spr_xspeed[k];
    if ((spr_table1588[k] & 0xC) != 0)
      spr_yspeed[k] = -spr_yspeed[k];
    CheckPlayerToNormalSpriteCollision(k);
    SubOffscreen_Bank03_Entry1(k);
  }
}

void SprXXX_ReflectingEnemy_ReflectingPodobooDraw(uint8 k) {  // 038ff2
  GenericGFXRtDraw1Tile16x16(k);
  uint8 v1 = 4;
  if ((counter_local_frames & 2) != 0)
    v1 = 8;
  if ((spr_xspeed[k] & 0x80) != 0)
    v1 ^= 0x40;
  if ((spr_yspeed[k] & 0x80) == 0)
    v1 ^= 0x80;
  uint8 r0 = v1;
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  oam[64].charnum = -84;
  oam[64].flags = r0 | oam[64].flags & 0x31;
}

void SprXXX_ReflectingEnemy_SpawnTrailingBoo(uint8 k) {  // 039020
  uint8 v1 = 11;
  while (mextspr_spriteid[v1]) {
    if ((--v1 & 0x80) != 0) {
      if ((--mextspr_slot_to_overwrite_when_slots_full & 0x80) != 0)
        mextspr_slot_to_overwrite_when_slots_full = 11;
      v1 = mextspr_slot_to_overwrite_when_slots_full;
      break;
    }
  }
  mextspr_spriteid[v1] = 10;
  SetHiLo(&mextspr_xpos_hi[v1], &mextspr_xpos_lo[v1], GetSprXPos(k));
  SetHiLo(&mextspr_ypos_hi[v1], &mextspr_ypos_lo[v1], GetSprYPos(k));
  mextspr_timer[v1] = 48;
  mextspr_xspeed[v1] = spr_xspeed[k];
}

void Spr0AE_FishinBoo(uint8 k) {  // 039065
  Spr0AE_FishinBoo_Draw(k);
  if (!flag_sprites_locked) {
    CheckPlayerToNormalSpriteCollision(k);
    uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
    spr_table1602[k] = 0;
    uint8 v2 = spr_decrementing_table15ac[k];
    if (v2) {
      ++spr_table1602[k];
      if (v2 == 16)
        spr_table157c[k] = v1;
    }
    if (!(spr_decrementing_table15ac[k] | (counter_global_frames + __CFSHL__(8 * k, 1) + 16 * k) & 0x3F))
      spr_decrementing_table15ac[k] = 32;
    if (timer_disappearing_sprite)
      v1 ^= 1;
    uint8 v3 = spr_xspeed[k];
    if (v3 != kSpr0AE_FishinBoo_MaxXSpeed[v1])
      spr_xspeed[k] = kSpr0AE_FishinBoo_XAcceleration[v1] + v3;
    if ((counter_global_frames & 1) == 0) {
      uint8 v4 = spr_table00c2[k] & 1;
      uint8 v5 = kSpr0AE_FishinBoo_YAcceleration[v4] + spr_yspeed[k];
      spr_yspeed[k] = v5;
      if (v5 == kSpr0AE_FishinBoo_MaxYSpeed[v4])
        ++spr_table00c2[k];
    }
    uint8 v6 = spr_xspeed[k];
    if (!timer_disappearing_sprite)
      spr_xspeed[k] += 8 * misc_layer1_xdisp;
    UpdateNormalSpritePosition_X(k);
    spr_xspeed[k] = v6;
    UpdateNormalSpritePosition_Y(k);
    Spr0AE_FishinBoo_0390F3(k);
  }
}

void Spr0AE_FishinBoo_0390F3(uint8 k) {  // 0390f3
  int v1 = 3 * spr_table157c[k];
  CollInfo ci;
  SetHiLo(&ci.r10, &ci.r4, GetSprXPos(k) + PAIR16(kSpr0AE_FishinBoo_DATA_0390EF[v1], kSpr0AE_FishinBoo_DATA_0390EB[v1]));
  ci.r6 = 4;
  ci.r7 = 4;
  SetHiLo(&ci.r11, &ci.r5, GetSprYPos(k) + 71);
  StandardSpriteToSpriteCollisionChecks_GetMarioClipping(&ci);
  if (StandardSpriteToSpriteCollisionChecks_CheckContact(&ci))
    DamagePlayer_Hurt();
}

void Spr0AE_FishinBoo_Draw(uint8 k) {  // 039180
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r4 = spr_table1602[k];
  uint8 r2 = spr_table157c[k];
  uint8 v9 = drt.idx;
  uint8 v2 = 9;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].ypos = kSpr0AE_FishinBoo_YDisp[v2] + drt.y;
    uint8 r3 = 0;
    uint8 v4 = kSpr0AE_FishinBoo_Tiles1[v2];
    if (v2 == 9) {
      uint8 v5 = (counter_local_frames >> 2) & 3;
      r3 = kSpr0AE_FishinBoo_DATA_039178[v5];
      v4 = kSpr0AE_FishinBoo_Tiles2[v5];
      v2 = 9;
    }
    oam[64].charnum = v4;
    uint8 a = sprites_tile_priority | r3 ^ kSpr0AE_FishinBoo_Prop[v2];
    if (r2 == 0)
      a ^= 0x40;
    oam[64].flags = a;
    uint8 v8 = v2;
    if (r4)
      v2 += 10;
    if (!r2)
      v2 += 20;
    oam[64].xpos = kSpr0AE_FishinBoo_XDisp[v2] + drt.x;
    drt.idx += 4;
    v2 = v8 - 1;
  } while ((int8)v2 >= 0);
  OamEnt *v6 = get_OamEnt(oam_buf, v9);
  int8 v7 = v6[68].flags ^ kSpr0AE_FishinBoo_DATA_03917C[(counter_local_frames >> 3) & 3];
  v6[68].flags = v7;
  v6[73].flags = v7;
  v7 ^= 0xC0;
  v6[69].flags = v7;
  v6[72].flags = v7;
  FinishOAMWrite(k, 2, 9);
}

void Spr0B2_FallingSpike(uint8 k) {  // 039214
  GenericGFXRtDraw1Tile16x16(k);
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  oam[64].charnum = -32;
  --oam[64].ypos;
  uint8 v2 = spr_decrementing_table1540[k];
  if (v2)
    oam[64].xpos += (v2 & 4) != 0;
  if (flag_sprites_locked) {
LABEL_12:
    spr_yspeed[k] = 0;
    return;
  }
  SubOffscreen_Bank03_Entry1(k);
  HandleNormalSpriteGravity(k);
  uint8 v3 = spr_table00c2[k];
  if (v3) {
    if (v3 != 1) {
      Unreachable();
      return;
    }
    if (!spr_decrementing_table1540[k]) {
      CheckPlayerToNormalSpriteCollision(k);
      return;
    }
    goto LABEL_12;
  }
  spr_yspeed[k] = 0;
  if ((uint8)(player_xpos - GetSprXPos(k) + 64) < 0x80) {
    ++spr_table00c2[k];
    spr_decrementing_table1540[k] = 64;
  }
}

void Spr0B1_CreateEatBlock(uint8 k) {  // 039284
  GenericGFXRtDraw1Tile16x16(k);
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  --oam[64].ypos;
  oam[64].charnum = 46;
  oam[64].flags &= 0x3F;
  FinishOAMWrite(k, 2, 0);
  uint8 v2 = 4;
  if (flag_active_create_eat_block != 0xFF) {
    if (!(flag_sprites_locked | counter_global_frames & 3))
      io_sound_ch2 = 4;
    v2 = spr_table157c[k];
  }
  if (!flag_sprites_locked) {
    spr_xspeed[k] = kSpr0B1_CreateEatBlock_XSpeed[v2];
    spr_yspeed[k] = kSpr0B1_CreateEatBlock_YSpeed[v2];
    UpdateNormalSpritePosition_Y(k);
    UpdateNormalSpritePosition_X(k);
    spr_table1528[k] = 0;
    SolidSpriteBlock(k);
    if (flag_active_create_eat_block != 0xFF && ((spr_xpos_lo[k] | spr_ypos_lo[k]) & 0xF) == 0) {
      if (spr_table151c[k]) {
        Spr0B1_CreateEatBlock_GenTileFromSpr1(k, 2);
        spr_xspeed[k] = 1;
        spr_yspeed[k] = 1;
        HandleNormalSpriteLevelCollision(k);
        uint8 v11 = spr_table1588[k];
        spr_xspeed[k] = -1;
        spr_yspeed[k] = -1;

        uint16 old_x = GetSprXPos(k), old_y = GetSprYPos(k);
        AddSprXYPos(k, -1, -1);
        HandleNormalSpriteLevelCollision(k);
        SetSprXPos(k, old_x);
        SetSprYPos(k, old_y);
        if (spr_table1588[k] | v11) {
          spr_table157c[k] = kSpr0B1_CreateEatBlock_DATA_039279[spr_table1588[k] | v11];
          return;
        }
      } else {
        bool v3 = spr_table1570[k] == 1;
        bool v4 = (--spr_table1570[k] & 0x80) != 0;
        if (v4 || v3) {
          uint8 v5 = spr_table1534[k];
          spr_table1534[k] = v5 + 1;
          uint8 v6 = kSpr0B1_CreateEatBlock_SubmapMovementData[v5];
          if (!ow_players_map[player_current_character])
            v6 = kSpr0B1_CreateEatBlock_MainMapMovementData[v5];
          spr_table1602[k] = v6;
          spr_table1570[k] = v6 >> 4;
          spr_table157c[k] = v6 & 3;
        }
        Spr0B1_CreateEatBlock_GenTileFromSpr1(k, 0xD);
        if (spr_table1602[k] != 0xFF)
          return;
      }
      spr_current_status[k] = 0;
    }
  }
}

void Spr0B1_CreateEatBlock_GenTileFromSpr1(uint8 k, uint8 a) {  // 03938b
  blocks_map16_to_generate = a;
  blocks_xpos = GetSprXPos(k);
  blocks_ypos = GetSprYPos(k);
  GenerateTile();
}

void Spr0AC_DownFirstWoodenSpike(uint8 k) {  // 039423
  Spr0AC_DownFirstWoodenSpike_Draw(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank03_Entry1(k);
    Spr0AC_DownFirstWoodenSpike_039488(k);
    int8 v1 = spr_table00c2[k] & 3;
    switch (v1) {
    case 0:
      if (spr_decrementing_table1540[k]) {
        Spr0AC_DownFirstWoodenSpike_039475(k, 0xF0);
        return;
      }
      uint8 v2 = 48;
      goto LABEL_16;
    case 1:
      if (!spr_decrementing_table1540[k]) {
        v2 = 24;
LABEL_16:
        spr_decrementing_table1540[k] = v2;
        ++spr_table00c2[k];
      }
      break;
    case 2:
      if (spr_decrementing_table1540[k]) {
        Spr0AC_DownFirstWoodenSpike_039475(k, 0x20);
        return;
      }
      v2 = 48;
      goto LABEL_16;
    default:
      if (!spr_decrementing_table1540[k]) {
        v2 = 47;
        goto LABEL_16;
      }
      break;
    }
  }
}

void Spr0AC_DownFirstWoodenSpike_039475(uint8 k, uint8 a) {  // 039475
  if (spr_table151c[k])
    a = -a;
  spr_yspeed[k] = a;
  UpdateNormalSpritePosition_Y(k);
}

void Spr0AC_DownFirstWoodenSpike_039488(uint8 k) {  // 039488
  if (CheckPlayerToNormalSpriteCollision(k) & 1) {
    uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
    if ((uint8)(player_xpos - GetSprXPos(k) + 4) >= 8) {
      player_xpos += PAIR16(kSpr0AC_DownFirstWoodenSpike_DATA_039486[v1], kSpr0AC_DownFirstWoodenSpike_DATA_039484[v1]);
      player_xspeed = 0;
    } else {
      DamagePlayer_Hurt();
    }
  }
}

void Spr0AC_DownFirstWoodenSpike_Draw(uint8 k) {  // 0394cf
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r2 = 0;
  if (spr_spriteid[k] == 0xAD)
    r2 = 5;
  int8 v2 = 4;
  do {
    int8 v5 = v2;
    uint8 v3 = r2 + v2;
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].xpos = drt.x;
    oam[64].ypos = kSpr0AC_DownFirstWoodenSpike_YDisp[v3] + drt.y;
    oam[64].charnum = kSpr0AC_DownFirstWoodenSpike_Tiles[v3];
    oam[64].flags = kSpr0AC_DownFirstWoodenSpike_Prop[v3];
    drt.idx += 4;
    v2 = v5 - 1;
  } while ((int8)v2 >= 0);
  FinishOAMWrite(k, 2, 4);
}

void Spr0AB_Rex(uint8 k) {  // 039517
  Spr0AB_Rex_Draw(k);
  if (spr_current_status[k] == 8 && !flag_sprites_locked) {
    uint8 v1 = spr_decrementing_table1558[k];
    if (v1) {
      spr_table15d0[k] = v1;
      if (v1 == 1)
        spr_current_status[k] = 0;
    } else {
      SubOffscreen_Bank03_Entry1(k);
      ++spr_table1570[k];
      uint8 v2;
      if (spr_table00c2[k])
        v2 = ((spr_table1570[k] & 4) != 0) + 3;
      else
        v2 = ((spr_table1570[k] >> 2) & 2) != 0;
      spr_table1602[k] = v2;
      if ((spr_table1588[k] & 4) != 0) {
        spr_yspeed[k] = 16;
        uint8 v3 = spr_table157c[k];
        if (spr_table00c2[k])
          v3 += 2;
        spr_xspeed[k] = kSpr0AB_Rex_XSpeed[v3];
      }
      if (!spr_decrementing_table1fe2[k])
        HandleNormalSpriteGravity(k);
      if ((spr_table1588[k] & 3) != 0)
        spr_table157c[k] ^= 1;
      CheckNormalSpriteToNormalSpriteCollision(k);
      if (CheckPlayerToNormalSpriteCollision(k) & 1) {
        if (timer_star_power) {
          spr_current_status[k] = 2;
          spr_yspeed[k] = -48;
          spr_xspeed[k] = kSpr0AB_Rex_RexKilledSpeed[CheckPlayerPositionRelativeToSprite_Bank23_X(k)];
          uint8 v4 = ++player_star_kill_count;
          if (player_star_kill_count >= 8) {
            v4 = 8;
            player_star_kill_count = 8;
          }
          GivePoints(k, v4);
          if (player_star_kill_count < 8)
            io_sound_ch1 = kSpr0AB_Rex_StompSounds[player_star_kill_count - 1];
        } else if (!spr_decrementing_table154c[k]) {
          spr_decrementing_table154c[k] = 8;
          if (sign8(player_yspeed - 16)) {
            if (!(player_riding_yoshi_flag | timer_player_hurt)) {
              spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
              DamagePlayer_Hurt();
            }
          } else {
            Spr0AB_Rex_RexPoints(k);
            BoostMarioSpeed();
            SpawnContactEffectFromAbove(k);
            if (player_riding_yoshi_flag | player_spin_jump_flag) {
              spr_current_status[k] = 4;
              spr_decrementing_table1540[k] = 31;
              SpawnSpinJumpStars(k);
              io_sound_ch1 = 8;
            } else if (++spr_table00c2[k] == 2) {
              spr_decrementing_table1558[k] = 32;
            } else {
              spr_decrementing_table1fe2[k] = 12;
              spr_property_bits1662[k] = 0;
            }
          }
        }
      }
    }
  }
}

void Spr0AB_Rex_RexPoints(uint8 k) {  // 039628
  int8 v1 = spr_table1626[k] + counter_consecutive_enemies_stomped++;
  uint8 v2 = v1 + 1;
  if ((uint8)(v1 + 1) < 8)
    io_sound_ch1 = kSpr0AB_Rex_StompSounds[v2 - 1];
  uint8 v3 = v1 + 1;
  if (v2 >= 8)
    v3 = 8;
  GivePoints(k, v3);
}

void Spr0AB_Rex_Draw(uint8 k) {  // 03967e
  GetDrawInfoRes drt;

  if (spr_decrementing_table1558[k])
    spr_table1602[k] = 5;
  if (spr_decrementing_table1fe2[k])
    spr_table1602[k] = 2;
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r3 = 2 * spr_table1602[k];
  uint8 r2 = spr_table157c[k];
  int8 v2 = 1;
  do {
    int8 v7 = v2;
    uint8 v3 = r3 | v2;
    uint8 v6 = r3 | v2;
    if (!r2)
      v3 += 12;
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].xpos = kSpr0AB_Rex_XDisp[v3] + drt.x;
    oam[64].ypos = kSpr0AB_Rex_YDisp[v6] + drt.y;
    oam[64].charnum = kSpr0AB_Rex_Tiles[v6];
    oam[64].flags = sprites_tile_priority | kSpr0AB_Rex_Prop[r2];
    uint8 v5 = 0;
    if (r3 < 0xA)
      v5 = 2;
    sprites_oamtile_size_buffer[(drt.idx >> 2) + 64] = v5;
    drt.idx += 4;
    --v2;
  } while ((int8)v2 >= 0);
  FinishOAMWrite(k, 0xFF, 1);
}

void Spr0AA_Fishbone(uint8 k) {  // 0396f6
  Spr0AA_Fishbone_Draw(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank03_Entry1(k);
    CheckPlayerToNormalSpriteCollision(k);
    UpdateNormalSpritePosition_X(k);
    if (((counter_global_frames + __CFSHL__(8 * k, 1) + 16 * k) & 0x7F) == 0 && (GetRand() & 1) == 0)
      spr_decrementing_table1558[k] = 12;
    uint8 v1 = spr_table00c2[k];
    if (v1) {
      if (v1 == 1) {
        spr_table1602[k] = 0;
        uint8 v5 = spr_decrementing_table1540[k];
        if (v5) {
          if ((v5 & 3) == 0) {
            int8 v6 = spr_xspeed[k];
            if (v6) {
              if (v6 >= 0)
                --spr_xspeed[k];
              else
                ++spr_xspeed[k];
            }
          }
        } else {
          spr_table00c2[k] = 0;
          spr_decrementing_table1540[k] = 48;
        }
      } else {
        Unreachable();
      }
    } else {
      spr_table1602[k] = (++spr_table1570[k] & 2) != 0;
      uint8 v2 = spr_decrementing_table1540[k];
      if (v2) {
        if ((v2 & 1) == 0) {
          uint8 v3 = spr_table157c[k];
          uint8 v4 = spr_xspeed[k];
          if (v4 != kSpr0AA_Fishbone_MaxXSpeed[v3])
            spr_xspeed[k] = kSpr0AA_Fishbone_XAcceleration[v3] + v4;
        }
      } else {
        ++spr_table00c2[k];
        spr_decrementing_table1540[k] = 48;
      }
    }
  }
}

void Spr0AA_Fishbone_Draw(uint8 k) {  // 03978c
  GenericGFXRtDraw1Tile16x16(k);
  int8 v1 = -90;
  if (spr_decrementing_table1558[k])
    v1 = -88;
  get_OamEnt(oam_buf, spr_oamindex[k])[64].charnum = v1;
  GetDrawInfoRes drt;
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r2 = 2 * spr_table157c[k];
  uint8 r3 = 2 * spr_table1602[k];
  uint8 v2 = spr_oamindex[k] + 4;
  spr_oamindex[k] = v2;
  uint8 v3 = v2;
  for (int8 i = 1; i >= 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, v3);
    oam[64].ypos = kSpr0AA_Fishbone_YDisp[(uint8)i] + drt.y;
    int v6 = (uint8)(r2 | i);
    oam[64].xpos = kSpr0AA_Fishbone_XDisp[(uint8)(r2 | i)] + drt.x;
    oam[64].flags = sprites_tile_priority | kSpr0AA_Fishbone_Prop[v6];
    oam[64].charnum = kSpr0AA_Fishbone_TailTiles[(uint8)(r3 | i)];
    v3 += 4;
  }
  FinishOAMWrite(k, 0, 2);
}

void Spr0A9_Reznor_Init(uint8 k) {  // 039872
  if (k == 7) {
    spr_table00c2[7] = 4;
    InitializeMode7TilemapsAndPalettes(7);
  }
  spr_table1570[k] = GetRand();
}

void Spr0A9_Reznor(uint8 k) {  // 039890
  ++flag_reznor_room_oamindex_timer;
  if (!flag_sprites_locked) {
    if (k == 7) {
      Spr0A9_Reznor_BreakReznorBridge();
      mirror_m7_center_xpos = 128;
      SetSprXYPos(0, 0xc0, 0xb2);
      misc_mode7_tilemap_index = 44;
      UpdateMode7SpriteAnimations(0);
      k = 7;
      misc_m7_rotation = (misc_m7_rotation + 1) & 0x1FF;
      uint8 v1 = spr_decrementing_table163e[7];
      if (v1) {
        if (v1 == 1) {
          --misc_currently_active_boss_end_cutscene;
          timer_end_level = -1;
          io_music_ch1 = 11;
          return;
        }
      } else if (spr_table151c[4] + spr_table151c[5] + spr_table151c[6] + spr_table151c[7] == 4) {
        spr_decrementing_table163e[7] = -112;
        DespawnNonBossSprites();
        for (int8 i = 7; i >= 0; --i)
          ext_spr_spriteid[(uint8)i] = 0;
      }
    }
    if (spr_current_status[k] == 8) {
      uint16 r0w = (misc_m7_rotation + PAIR16(kSpr0A9_Reznor_ReznorStartPosHi[k & 3], kSpr0A9_Reznor_ReznorStartPosLo[k & 3])) & 0x1ff;
      r0w = (r0w ^ 0x1FF) + 1;
      uint16 r2w = (r0w + 128) & 0x1FF;
      uint16 r4 = kCircleCoordinates[(uint8)r0w];
      uint16 r6 = kCircleCoordinates[(uint8)(r0w + 0x80)];
      uint8 v4 = 56;
      if (r4 < 256) {
        uint16 mult = Mult8x8(r4, v4);
        uint8 t = (uint8)mult >> 7;
        v4 = (mult >> 8) + t;
      }
      uint8 v3 = (r0w >> 8) & 1;
      if (v3)
        v4 = -v4;
      uint8 v6 = 56;
      if (r6 < 256) {
        uint16 mult = Mult8x8(r6, v6);
        uint8 t = (uint8)mult >> 7;
        v6 = (mult >> 8) + t;
      }
      v3 = (r2w >> 8) & 1;
      if (v3)
        v6 = -v6;
      k = spr_current_slotid;
      uint8 v13 = spr_xpos_lo[k];
      uint16 xpos = mirror_m7_center_xpos + (int8)v4 + 64;
      SetSprXPos(k, xpos);
      spr_table1528[k] = spr_xpos_lo[k] - v13;

      SetSprYPos(k, mirror_m7_center_ypos + (int8)v6 + 32);

      if (spr_table151c[k]) {
        SolidSpriteBlock(k);
      } else {
        if (!spr_decrementing_table15ac[k] && !++spr_table1570[k]) {
          spr_table1570[k] = 0;
          spr_decrementing_table1558[k] = 64;
        }
        if (!(spr_decrementing_table15ac[k] | spr_decrementing_table1558[k] |
              (counter_local_frames + __CFSHL__(8 * k, 1) + 16 * k) & 0x3F)) {
          uint8 v14 = spr_table157c[k];
          spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
          if (v14 != spr_table157c[k])
            spr_decrementing_table15ac[k] = 10;
        }
        if (!spr_decrementing_table154c[k] && CheckPlayerToNormalSpriteCollision(k)) {
          spr_decrementing_table154c[k] = 8;
          if (sign8(player_ypos - spr_ypos_lo[k] + 19)) {
            DamagePlayer_Hurt();
          } else if (sign8(player_ypos - spr_ypos_lo[k] + 14) || (player_yspeed & 0x80) == 0) {
            player_xspeed = kSpr0A9_Reznor_ReboundSpeedX[CheckPlayerPositionRelativeToSprite_Bank23_X(k)];
          } else {
            spr_property_bits1662[k] = 41;
            spr_decrementing_table1564[k] = 15;
            player_yspeed = 16;
            io_sound_ch1 = 1;
          }
        }
      }
    }
  }
  spr_table1602[k] = 0;
  uint8 v15 = spr_table157c[k];
  uint8 v10 = spr_decrementing_table15ac[k];
  if (v10) {
    if (v10 >= 5)
      spr_table157c[k] ^= 1;
    spr_table1602[k] = 2;
  }
  uint8 v11 = spr_decrementing_table1558[k];
  if (v11) {
    if (v11 == 32)
      Spr0A9_Reznor_ReznorFireRt(k);
    spr_table1602[k] = 1;
  }
  Spr0A9_Reznor_Draw(k);
  spr_table157c[k] = v15;
  if (!(spr_table151c[k] | flag_sprites_locked) && spr_decrementing_table1564[k] == 12) {
    io_sound_ch1 = 3;
    spr_decrementing_table1558[k] = 0;
    ++spr_table151c[k];
    uint8 j = FindFreeNormalSpriteSlot_HighPriority();
    if ((j & 0x80) == 0) {
      spr_current_status[j] = 2;
      spr_spriteid[j] = -87;
      SetSprXYPos(j, GetSprXPos(k), GetSprYPos(k));
      InitializeNormalSpriteRAMTables(j);
      spr_yspeed[j] = -64;
    }
  }
}

void Spr0A9_Reznor_ReznorFireRt(uint8 k) {  // 039af8
  uint8 j = 7;
  while (ext_spr_spriteid[j]) {
    if ((--j & 0x80) != 0)
      return;
  }
  io_sound_ch1 = 16;
  ext_spr_spriteid[j] = 2;
  uint16 xpos = GetSprXPos(k), ypos = GetSprYPos(k);
  SetHiLo(&ext_spr_xpos_hi[j], &ext_spr_xpos_lo[j], xpos - 8);
  SetHiLo(&ext_spr_ypos_hi[j], &ext_spr_ypos_lo[j], ypos - 20);
  SetSprXYPos(k, xpos - 8, ypos - 20);
  PointU8 pt = AimTowardsPlayer_Bank23(k, 0x10);
  SetSprXYPos(k, xpos, ypos);
  ext_spr_yspeed[j] = pt.y;
  ext_spr_xspeed[j] = pt.x;
}

void Spr0A9_Reznor_Draw(uint8 k) {  // 039b75
  GetDrawInfoRes drt;

  if (spr_table151c[k])
    goto LABEL_10;
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r3 = 4 * spr_table1602[k];
  uint8 r2 = 4 * spr_table157c[k];
  uint8 ka = k;
  uint8 v2 = 3;
  do {
    uint8 v6 = v2;
    if (r3 < 8)
      v2 |= r2;
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].xpos = kSpr0A9_Reznor_XDisp[v2] + drt.x;
    oam[64].ypos = kSpr0A9_Reznor_YDisp[v6] + drt.y;
    uint8 v4 = r3 | v6;
    oam[64].charnum = kSpr0A9_Reznor_Tiles[r3 | v6];
    uint8 v5 = kSpr0A9_Reznor_Prop[v4];
    if (v4 < 8 && !r2)
      v5 ^= 0x40;
    oam[64].flags = v5;
    drt.idx += 4;
    v2 = v6 - 1;
  } while ((int8)v2 >= 0);
  k = ka;
  FinishOAMWrite(ka, 2, 3);
  if (spr_current_status[ka] != 2)
LABEL_10:
    Spr0A9_Reznor_PlatformDraw(k);
}

void Spr0A9_Reznor_PlatformDraw(uint8 k) {  // 039beb
  GetDrawInfoRes drt;

  spr_oamindex[k] += 16;
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r2 = kSpr0A9_Reznor_PlatformYDisp[spr_decrementing_table1564[k] >> 1];
  OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
  oam[65].xpos = drt.x;
  oam[64].xpos = drt.x - 16;
  int8 v4 = drt.y - r2;
  oam[64].ypos = drt.y - r2;
  oam[65].ypos = v4;
  oam[64].charnum = 78;
  oam[65].charnum = 78;
  oam[64].flags = 51;
  oam[65].flags = 115;
  FinishOAMWrite(k, 2, 1);
}

void Spr06F_DinoTorch(uint8 k) {  // 039c34
  if (spr_spriteid[k] == 109)
    SolidSpriteBlock(k);
  else
    Spr06F_DinoTorch2(k);
}

void Spr06F_DinoTorch2(uint8 k) {  // 039c47
  Spr06F_DinoTorch_Draw(k);
  if (!flag_sprites_locked && spr_current_status[k] == 8) {
    SubOffscreen_Bank03_Entry1(k);
    CheckPlayerToNormalSpriteCollision(k);
    HandleNormalSpriteGravity(k);
    uint8 v1 = spr_table00c2[k];
    if (v1) {
      if (v1 != 1 && v1 != 2) {
        if (v1 != 3) {
          Unreachable();
          return;
        }
        if ((spr_yspeed[k] & 0x80) == 0) {
          spr_table00c2[k] = 0;
          if ((spr_table1588[k] & 3) != 0)
            spr_table157c[k] ^= 1;
        }
        goto LABEL_11;
      }
      spr_xspeed[k] = 0;
      uint8 v6 = spr_decrementing_table1540[k];
      if (!v6) {
        spr_table00c2[k] = 0;
        spr_decrementing_table1540[k] = 64;
        v6 = 0;
      }
      if (v6 == 0xC0)
        io_sound_ch3 = 23;
      uint8 v7 = v6 >> 3;
      if (spr_table00c2[k] == 2)
        v7 += 32;
      uint8 v8 = kSpr06F_DinoTorch_DinoFlameTable[v7];
      spr_table1602[k] = v8 & 0xF;
      spr_table151c[k] = v8 >> 4;
      if (!(v8 >> 4) && spr_spriteid[k] != 110 && ((counter_global_frames ^ k) & 3) == 0) {
        CollInfo ci;
        Spr06F_DinoTorch_DinoFlameClipping(k, &ci);
        StandardSpriteToSpriteCollisionChecks_GetMarioClipping(&ci);
        if (StandardSpriteToSpriteCollisionChecks_CheckContact(&ci)) {
          if (!timer_star_power)
            DamagePlayer_Hurt();
        }
      }
    } else {
      if ((spr_table1588[k] & 4) == 0) {
LABEL_11:
        spr_table1602[k] = 0;
        uint8 v2 = spr_table1588[k] & 3;
        AddSprXPos(k, PAIR16(kSpr06F_DinoTorch_DATA_039C71[v2], kSpr06F_DinoTorch_DATA_039C6E[v2]));
        return;
      }
      if (!spr_decrementing_table1540[k] && spr_spriteid[k] != 110) {
        spr_decrementing_table1540[k] = -1;
        spr_table00c2[k] = (GetRand() & 1) + 1;
      }
      if (((counter_local_frames + __CFSHL__(8 * k, 1) + 16 * k) & 0x3F) == 0)
        spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
      spr_yspeed[k] = 16;
      uint8 v5 = spr_table157c[k];
      if (spr_spriteid[k] != 110)
        v5 += 2;
      spr_xspeed[k] = kSpr06F_DinoTorch_XSpeed[v5];
      Spr06F_DinoTorch_DinoSetGfxFrame(k);
      if ((spr_table1588[k] & 3) != 0) {
        spr_yspeed[k] = -64;
        spr_table00c2[k] = 3;
      }
    }
  }
}

void Spr06F_DinoTorch_DinoFlameClipping(uint8 k, CollInfo *ci) {  // 039db6
  uint8 j = spr_table1602[k] - 2;
  if (!spr_table157c[k])
    j = spr_table1602[k];
  SetHiLo(&ci->r10, &ci->r4, GetSprXPos(k) + PAIR16(kSpr06F_DinoTorch_DinoFlame2[j], kSpr06F_DinoTorch_DinoFlame1[j]));
  ci->r6 = kSpr06F_DinoTorch_DinoFlame3[j];
  SetHiLo(&ci->r11, &ci->r5, GetSprYPos(k) + PAIR16(kSpr06F_DinoTorch_DinoFlame5[j], kSpr06F_DinoTorch_DinoFlame4[j]));
  ci->r7 = kSpr06F_DinoTorch_DinoFlame6[j];
}

void Spr06F_DinoTorch_DinoSetGfxFrame(uint8 k) {  // 039def
  spr_table1602[k] = (uint8)(++spr_table1570[k] & 8) >> 3;
}

void Spr06F_DinoTorch_Draw(uint8 k) {  // 039e49
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r2 = spr_table157c[k];
  uint8 r4 = spr_table1602[k];
  if (spr_spriteid[k] == 111) {
    uint8 r3 = spr_table151c[k];
    r4 = spr_table1602[k];
    uint8 v4 = 32 * (counter_local_frames & 2);
    if (r4 != 3)
      v4 = (counter_local_frames & 2) << 6;
    uint8 r5 = v4;
    uint8 v5 = 4;
    do {
      uint8 r6 = v5;
      if (r4 == 3)
        v5 += 5;
      uint8 v6 = kSpr06F_DinoTorch_DinoTorchXDisp[v5];
      if (!r2)
        v6 = -v6;
      OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
      oam[64].xpos = drt.x + v6;
      oam[64].ypos = drt.y + kSpr06F_DinoTorch_DinoTorchYDisp[v5];
      uint8 v8;
      if (r6 == 4)
        v8 = kSpr06F_DinoTorch_DinoTorchTiles[r4];
      else
        v8 = kSpr06F_DinoTorch_DinoFlameTiles[v5];
      oam[64].charnum = v8;
      int8 v9 = 0;
      if (!r2)
        v9 = 64;
      uint8 v10 = r6;
      if (r6 != 4)
        v9 ^= r5;
      oam[64].flags = sprites_tile_priority | kSpr06F_DinoTorch_DinoTorchProp[r6] | v9;
      drt.idx += 4;
      v5 = v10 - 1;
    } while ((int8)(v5 - r3) >= 0);
    FinishOAMWrite(k, 2, kSpr06F_DinoTorch_DinoTilesWritten[spr_table151c[k]]);
  } else {
    uint8 v2 = 3;
    do {
      uint8 r15 = v2;
      if (!r2)
        v2 += 4;
      OamEnt *v3 = get_OamEnt(oam_buf, drt.idx);
      v3[64].flags = kSpr06F_DinoTorch_DinoRhinoProp[v2];
      v3[64].xpos = drt.x + kSpr06F_DinoTorch_DinoRhinoXDisp[v2];
      v3[64].ypos = drt.y + (r4 != 0) + kSpr06F_DinoTorch_DinoRhinoYDisp[r15];
      v3[64].charnum = kSpr06F_DinoTorch_DinoRhinoTiles[r15 + 4 * r4];
      drt.idx += 4;
      v2 = r15 - 1;
    } while ((int8)v2 >= 0);
    FinishOAMWrite(k, 2, 3);
  }
}

void Spr06F_DinoTorch_Return039F37() {  // 039f37
  ;
}

void Spr0A8_Blargg(uint8 k) {  // 039f38
  Spr0A8_Blargg_Draw(k);
  if (!flag_sprites_locked) {
    CheckPlayerToNormalSpriteCollision(k);
    SubOffscreen_Bank03_Entry1(k);
    uint8 v1 = spr_table00c2[k];
    if (v1) {
      switch (v1) {
      case 1:
        if (sign8(spr_yspeed[k] - 16)) {
          UpdateNormalSpritePosition_Y(k);
          spr_yspeed[k] += 2;
        } else {
          spr_decrementing_table1540[k] = 80;
          ++spr_table00c2[k];
          spr_yspeed[k] = 0;
        }
        break;
      case 2: {
        uint8 v2 = spr_decrementing_table1540[k];
        if (v2) {
          if (v2 >= 0x20) {
            if ((v2 & 0x1F) == 0)
              spr_table157c[k] ^= 1;
          } else {
            Spr0A8_Blargg_039FC0(k);
          }
        } else {
          ++spr_table00c2[k];
          spr_decrementing_table1540[k] = 10;
        }
        break;
      }
      case 3:
        if (spr_decrementing_table1540[k]) {
          spr_yspeed[k] = 32;
          UpdateNormalSpritePosition_Y(k);
        } else {
          spr_decrementing_table1540[k] = 32;
          spr_xspeed[k] = kSpr0A8_Blargg_XSpeed[spr_table157c[k]];
          spr_yspeed[k] = -30;
          Spr0A8_Blargg_03A045(k);
          ++spr_table00c2[k];
        }
        break;
      case 4:
        spr_table1602[k] = 0;
        uint8 v3 = spr_decrementing_table1540[k];
        if (v3) {
          if (v3 != 1) {
LABEL_31:
            if ((uint8)(spr_yspeed[k] + 6) < 0xC)
              ++spr_table1602[k];
            return;
          }
          io_sound_ch1 = 37;
          Spr0A8_Blargg_03A045(k);
        }
        UpdateNormalSpritePosition_X(k);
        UpdateNormalSpritePosition_Y(k);
        if (!sign8(++spr_yspeed[k] - 32)) {
          Spr0A8_Blargg_03A045(k);
          spr_table00c2[k] = 0;
          SetSprXPos(k, PAIR16(spr_table151c[k], spr_table1528[k]));
          SetSprYPos(k, PAIR16(spr_table1534[k], spr_table1594[k]));
          spr_decrementing_table1540[k] = 64;
        }
        goto LABEL_31;
      default: Unreachable(); return;
      }
    } else if (!(spr_decrementing_table1540[k] | spr_xoffscreen_flag[k])) {
      if ((uint8)(player_xpos - GetSprXPos(k) + 112) < 0xE0) {
        spr_yspeed[k] = -29;
        SetHiLo(&spr_table151c[k], &spr_table1528[k], GetSprXPos(k));
        SetHiLo(&spr_table1534[k], &spr_table1594[k], GetSprYPos(k));
        Spr0A8_Blargg_039FC0(k);
        ++spr_table00c2[k];
      }
    }
  }
}

void Spr0A8_Blargg_039FC0(uint8 k) {  // 039fc0
  spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
}

void Spr0A8_Blargg_03A045(uint8 k) {  // 03a045
  uint16 old_y = GetSprYPos(k);
  SetSprYPos(k, old_y - 12);
  SpawnLavaSplash(k);
  SetSprYPos(k, old_y);
}

void Spr0A8_Blargg_Draw(uint8 k) {  // 03a062
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 v2 = spr_table00c2[k];
  if (v2) {
    if (v2 == 4) {
      uint8 r3 = 5 * (spr_table1602[k] != 0); // out of bounds read
      uint8 r2 = spr_table157c[k];
      uint8 v4n = 4;
      do {
        uint8 v4 = v4n;
        uint8 v6 = v4;
        OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
        oam[64].ypos = kSpr0A8_Blargg_YDisp[v4] + drt.y;
        if (!r2)
          v4 += 5;
        oam[64].xpos = kSpr0A8_Blargg_XDisp[v4] + drt.x;
        oam[64].charnum = kSpr0A8_Blargg_Tiles[(uint8)(r3 + v6)];
        oam[64].flags = kSpr0A8_Blargg_Prop[r2];
        drt.idx += 4;
      } while ((int8)--v4n >= 0);
      FinishOAMWrite(k, 2, 4);
    } else {
      GenericGFXRtDraw1Tile16x16(k);
      OamEnt *v3 = get_OamEnt(oam_buf, spr_oamindex[k]);
      v3[64].charnum = -96;
      v3[64].flags &= 0xCF;
    }
  } else if ((uint8)(spr_yspeed[k] + 6) < 0xC) {
    ++spr_table1602[k];
  }
}

void Spr0A0_ActivateBowserBattle_Init(uint8 k) {  // 03a0f1
  InitializeNormalSpriteRAMTables(k);
  spr_xoffscreen_flag[k] = 0;
  SetSprXYPos(k, 0xd0, -0x80);
  spr_table187b[k] = 2;
  spr_table00c2[k] = 3;
  InitializeMode7TilemapsAndPalettes(k);
}

void HandleExtraSprites(uint8 k) {  // 03a118
  uint8 v1 = spr_spriteid[k];
  switch (v1) {
  case 0xC8: Spr0C8_LightSwitch(k); break;
  case 0xC7: Spr0C7_InvisibleMushroom(k); break;
  case 0x51: Spr051_Ninji(k); break;
  case 0x1B: Spr01B_Football(k); break;
  case 0xC6: Spr0C6_Spotlight(k); break;
  case 0x7A: Spr07A_Fireworks(k); break;
  case 0x7C: Spr07C_PrincessPeach(k); break;
  case 0xC5: Spr0C5_BigBooBoss(k); break;
  case 0xC4: Spr0C4_GreyFallingPlatform(k); break;
  case 0xC2: Spr0C2_Blurp(k); break;
  case 0xC3: Spr0C3_PorcuPuffer(k); break;
  case 0xC1: Spr0C1_WingedPlatform(k); break;
  case 0xC0: Spr0C0_SinkingLavaPlatform(k); break;
  case 0xBF: Spr0BF_MegaMole(k); break;
  case 0xBE: Spr0BE_Swooper(k); break;
  case 0xBD: Spr0BD_SlidingNakedBlueKoopa(k); break;
  case 0xBC: Spr0BC_BowserStatue(k); break;
  case 0xB8:
  case 0xB7: Spr0B8_CarrotTopLiftUpperLeft(k); break;
  case 0xB9: Spr0B9_MessageBox(k); break;
  case 0xBA: Spr0BA_TimedPlatform(k); break;
  case 0xBB: Spr0BB_MovingCastleStone(k); break;
  case 0xB3: Spr0B3_BowserStatueFire(k); break;
  case 0xB2: Spr0B2_FallingSpike(k); break;
  case 0xAE: Spr0AE_FishinBoo(k); break;
  case 0xB6: SprXXX_ReflectingEnemy_ReflectingPodobooEntry(k); break;
  case 0xB0: SprXXX_ReflectingEnemy_ReflectingBooBuddiesEntry(k); break;
  case 0xB1: Spr0B1_CreateEatBlock(k); break;
  case 0xAC:
  case 0xAD: Spr0AC_DownFirstWoodenSpike(k); break;
  case 0xAB: Spr0AB_Rex(k); break;
  case 0xAA: Spr0AA_Fishbone(k); break;
  case 0xA9: Spr0A9_Reznor(k); break;
  case 0xA8: Spr0A8_Blargg(k); break;
  case 0xA1: Spr0A1_BowserBowlingBall(k); break;
  case 0xA2: Spr0A2_MechaKoopa(k); break;
  default:
    Spr0A0_ActivateBowserBattle_UpdatePaletteAndLightningAnimation();
    Spr0A0_ActivateBowserBattle_Sub(k);
    Spr0A0_ActivateBowserBattle_Draw();
    break;
  }
}

void Spr0A0_ActivateBowserBattle_Sub(uint8 k) {  // 03a279
  spra0_bowser_palette_index = kSpr0A0_ActivateBowserBattle_DATA_03A265[(uint8)misc_m7_angle >> 3];
  misc_mode7_tilemap_index = spr_table157c[k] | (spr_table1570[k] + 30);
  spra0_bowser_propeller_anim_frame_counter = (counter_local_frames >> 1) & 3;
  LOBYTE(mirror_m7_center_xpos) = -112;
  LOBYTE(mirror_m7_center_ypos) = -56;
  UpdateMode7SpriteAnimations(k);
  if (bowserbattle_var14b5)
    Spr0A0_ActivateBowserBattle_03AF59(k);
  if (spr_decrementing_table1564[k])
    Spr0A0_ActivateBowserBattle_SmokeDraw(k);
  uint8 v1 = spr_table1594[k];
  if (v1) {
    uint8 v2 = (uint8)(v1 - 1) >> 3;
    uint8 r2 = kSpr0A0_ActivateBowserBattle_DATA_03A8BE[v2];
    uint8 r3 = ((uint8)(v1 - 1) >> 2) & 3;
    Spr07C_PrincessPeach_GFXRt_DrawHELP(k, v2, r2, r3);
  }
  if (!flag_sprites_locked) {
    spr_table1594[k] = 0;
    sprites_tile_priority = 48;
    if ((uint8)misc_m7_angle < 0x20)
      sprites_tile_priority = 0;
    if (Spr0A0_ActivateBowserBattle_ReturnsTwice_03A661(k))
      return;
    if (bowserbattle_var14b0 && (counter_global_frames & 3) == 0)
      --bowserbattle_var14b0;
    if ((counter_global_frames & 0x7F) == 0 && (GetRand() & 1) == 0)
      spr_decrementing_table1558[k] = 12;
    Spr0A0_ActivateBowserBattle_03B078(k);
    if (spr_table151c[k] != 9) {
      spra0_bowser_clown_car_face_anim_frame = 0;
      if (spr_decrementing_table1558[k])
        ++spra0_bowser_clown_car_face_anim_frame;
    }
    if (Spr0A0_ActivateBowserBattle_ReturnsTwice_03A5AD(k))
      return;
    UpdateNormalSpritePosition_X(k);
    UpdateNormalSpritePosition_Y(k);
    kUnk_3a32c[spr_table151c[k]](k);
  }
}

void Spr0A0_ActivateBowserBattle_SmokeDraw(uint8 k) {  // 03a3e2
  GetDrawInfoRes drt;
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r3 = (uint8)(spr_decrementing_table1564[k] - 1) >> 1;
  uint8 r2 = 8 * r3;
  spr_oamindex[k] = 112;
  uint8 v1 = 112;
  uint8 v2 = 7;
  do {
    uint8 v3 = r2 | v2;
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam[64].xpos = kSpr0A0_ActivateBowserBattle_SmokeXDisp[v3] + drt.x + 8;
    oam[64].ypos = kSpr0A0_ActivateBowserBattle_SmokeYDisp[v3] + drt.y + 48;
    oam[64].charnum = kSpr0A0_ActivateBowserBattle_SmokeTiles[r3];
    oam[64].flags = kSpr0A0_ActivateBowserBattle_SmokeProp[v2];
    v1 += 4;
  } while ((int8)--v2 >= 0);
  FinishOAMWrite(k, 2, 7);
}

void Spr0A0_ActivateBowserBattle_State00_InitialDescent(uint8 k) {  // 03a441
  uint8 v1 = spr_decrementing_table154c[k];
  if (v1) {
    if (v1 == 1) {
      spr_table151c[k] = 7;
      bowserbattle_var14b0 = 120;
    }
  } else {
    uint8 v2 = spr_decrementing_table1540[k];
    if (v2) {
      spr_yspeed[k] = 0;
      spr_xspeed[k] = 0;
      if (v2 == 1) {
        spr_decrementing_table154c[k] = 36;
      } else if (v2 < 0x40) {
        spr_table1570[k] = kSpr0A0_ActivateBowserBattle_DuckingAnimationFrames[v2 >> 3];
      }
    } else {
      spr_table1570[k] = 14;
      spr_yspeed[k] = 4;
      spr_xspeed[k] = 0;
      if (spr_ypos_lo[k] - (uint8)mirror_current_layer1_ypos == 16)
        spr_decrementing_table1540[k] = -92;
    }
  }
}

void Spr0A0_ActivateBowserBattle_State07_Phase1(uint8 k) {  // 03a49c
  Spr0A0_ActivateBowserBattle_03A4D2(k);
  Spr0A0_ActivateBowserBattle_03A4FD(k);
  Spr0A0_ActivateBowserBattle_03A4ED(k);
  uint8 v1 = spr_table1528[k] & 1;
  uint8 v2 = kSpr0A0_ActivateBowserBattle_DATA_03A490[v1] + spr_xspeed[k];
  spr_xspeed[k] = v2;
  if (v2 == kSpr0A0_ActivateBowserBattle_DATA_03A492[v1])
    ++spr_table1528[k];
  uint8 v3 = spr_table1534[k] & 1;
  uint8 v4 = kSpr0A0_ActivateBowserBattle_DATA_03A494[v3] + spr_yspeed[k];
  spr_yspeed[k] = v4;
  if (v4 == kSpr0A0_ActivateBowserBattle_DATA_03A496[v3])
    ++spr_table1534[k];
}

void Spr0A0_ActivateBowserBattle_03A4D2(uint8 k) {  // 03a4d2
  uint8 v1 = 0;
  if ((counter_global_frames & 0xE0) == 0)
    v1 = kSpr0A0_ActivateBowserBattle_DATA_03A498[(uint8)(counter_global_frames & 0x18) >> 3];
  spr_table1570[k] = v1;
}

void Spr0A0_ActivateBowserBattle_03A4ED(uint8 k) {  // 03a4ed
  if ((counter_global_frames & 0x1F) == 0)
    spr_table157c[k] = kSpr0A0_ActivateBowserBattle_DATA_03A4EB[CheckPlayerPositionRelativeToSprite_Bank23_X(k)];
}

void Spr0A0_ActivateBowserBattle_03A4FD(uint8 k) {  // 03a4fd
  if (!bowserbattle_var14b0) {
    if (spr_table151c[k] != 8 || (++bowserbattle_var14b8, bowserbattle_var14b8 == 3)) {
      bowserbattle_var14b8 = 0;
      if (!spr_current_status[0] || !spr_current_status[1])
        bowserbattle_var14b1 = -1;
    } else {
      bowserbattle_var14b6 = -1;
    }
  }
}

uint8 Spr0A0_ActivateBowserBattle_ReturnsTwice_03A5AD(uint8 k) {  // 03a5ad
  uint8 v1 = bowserbattle_var14b1;
  if (bowserbattle_var14b1) {
    if (--bowserbattle_var14b1) {
      spr_table1570[k] = kSpr0A0_ActivateBowserBattle_DATA_03A52D[v1 >> 2];
      if (bowserbattle_var14b1 == 0x80) {
        Spr0A0_ActivateBowserBattle_03B019(k);
        io_sound_ch3 = 8;
      }
      return true;
    } else {
      bowserbattle_var14b0 = 84;
    }
  } else {
    uint8 v2 = bowserbattle_var14b6;
    if (bowserbattle_var14b6) {
      if (--bowserbattle_var14b6) {
        spr_table1570[k] = kSpr0A0_ActivateBowserBattle_DATA_03A52D[v2 >> 2];
        uint8 v3 = kSpr0A0_ActivateBowserBattle_DATA_03A56D[v2 >> 2];
        misc_m7_rotation = v3;
        if (v3 == 0xFF) {
          LOBYTE(misc_m7_rotation) = 0;
          ++HIBYTE(misc_m7_rotation);
          sprites_tile_priority = 0;
        }
        if (bowserbattle_var14b6 == 0x80) {
          io_sound_ch3 = 9;
          Spr0A0_ActivateBowserBattle_03A61D(k);
        }
        return true;
      } else {
        bowserbattle_var14b0 = (bowserbattle_var14b8 != 2) ? 32 : 96;
      }
    }
  }
  return false;
}

void Spr0A0_ActivateBowserBattle_03A61D(uint8 k) {  // 03a61d
  spr_current_status[8] = 8;
  spr_spriteid[8] = -95;
  SetSprXYPos(8, GetSprXPos(k) + 8, GetSprYPos(k) + 64);
  InitializeNormalSpriteRAMTables(8);
}

uint8 Spr0A0_ActivateBowserBattle_ReturnsTwice_03A661(uint8 k) {  // 03a661
  uint8 res = false;
  uint8 v1 = bowserbattle_var14b5;
  if (bowserbattle_var14b5) {
    bowserbattle_var14b1 = 0;
    bowserbattle_var14b6 = 0;
    if (!--bowserbattle_var14b5) {
      v1 = 80;
      bowserbattle_var14b0 = 80;
      if (spr_table187b[k]-- == 1) {
        if (spr_table151c[k] == 9) {
          spr_table151c[k] = 4;
          spr_xspeed[k] = 0;
          return res;
        }
        spr_table187b[k] = 2;
        spr_table151c[k] = 1;
        v1 = 0x80;
        spr_decrementing_table1540[k] = 0x80;
      }
    }
    res = true;
    uint8 v4 = v1;
    int8 v3 = kSpr0A0_ActivateBowserBattle_DATA_03A64D[bowserbattle_var14b5 >> 2];
    misc_m7_rotation = (uint8)v3;
    if (v3 < 0)
      ++HIBYTE(misc_m7_rotation);
    if (v4 >= 0x40) {
      spr_table1570[k] = 12;
      spra0_bowser_clown_car_face_anim_frame = 2;
    } else {
      Spr0A0_ActivateBowserBattle_03A6AC(k);
    }
  }
  return res;
}

void Spr0A0_ActivateBowserBattle_03A6AC(uint8 k) {  // 03a6ac
  uint8 v1 = 16;
  if ((counter_global_frames & 4) != 0)
    v1 = 18;
  spr_table1570[k] = v1;
  spra0_bowser_clown_car_face_anim_frame = 2;
}

void DespawnNonBossSprites() {  // 03a6c8
  for (uint8 i = 9; (i & 0x80) == 0; --i) {
    if (spr_current_status[i]) {
      uint8 v1 = spr_spriteid[i];
      if (v1 != 0xA9 && v1 != 41 && v1 != 0xA0 && v1 != 0xC5) {
        spr_current_status[i] = 4;
        spr_decrementing_table1540[i] = 31;
      }
    }
  }
}

void Spr0A0_ActivateBowserBattle_State01_SwoopOut(uint8 k) {  // 03a6f8
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    if (v1 == 1)
      io_music_ch1 = 23;
    spr_table1570[k] = kSpr0A0_ActivateBowserBattle_DATA_03A6F0[v1 >> 4];
    spr_xspeed[k] = 0;
    spr_yspeed[k] = 0;
    spr_table1528[k] = 0;
    spr_table1534[k] = 0;
    bowserbattle_var14b2 = 0;
  } else {
    uint8 v2 = spr_table1528[k];
    if (v2 < 2 && (kSpr0A0_ActivateBowserBattle_DATA_03A723[v2] & counter_global_frames) == 0) {
      spr_xspeed[k] += kSpr0A0_ActivateBowserBattle_DATA_03A71F[v2];
      if (spr_xspeed[k] == kSpr0A0_ActivateBowserBattle_DATA_03A721[v2])
        ++spr_table1528[k];
    }
    uint8 v4 = spr_table1534[k];
    if (v4 < 2 && (kSpr0A0_ActivateBowserBattle_DATA_03A72B[v4] & counter_global_frames) == 0) {
      spr_yspeed[k] += kSpr0A0_ActivateBowserBattle_DATA_03A725[v4];
      if (spr_yspeed[k] == kSpr0A0_ActivateBowserBattle_DATA_03A727[v4])
        ++spr_table1534[k];
    }
    if (bowserbattle_var14b2 == 2)
      goto LABEL_18;
    if ((kSpr0A0_ActivateBowserBattle_DATA_03A72F[bowserbattle_var14b2] & counter_global_frames) == 0) {
      LOBYTE(misc_m7_angle) = kSpr0A0_ActivateBowserBattle_DATA_03A729[bowserbattle_var14b2] + misc_m7_angle;
      HIBYTE(misc_m7_angle) = misc_m7_angle;
      if ((uint8)misc_m7_angle == kSpr0A0_ActivateBowserBattle_DATA_03A72D[bowserbattle_var14b2])
        ++bowserbattle_var14b2;
    }
    if (spr_xpos_hi[k] == 0xFE) {
LABEL_18:
      spr_table151c[k] = 3;
      bowserbattle_var14b0 = 0x80;
      bowserbattle_var14b7 = GetRand() & 0xF0;
      io_music_ch1 = 29;
    }
  }
}

void Spr0A0_ActivateBowserBattle_State03_DropFireballs(uint8 k) {  // 03a7ad
  misc_m7_angle = 0x6060;
  SetSprXPos(k, -160);
  if (bowserbattle_var14b0) {
    if (bowserbattle_var14b0 < 0x60 && (counter_global_frames & 0x1F) == 0) {
      uint8 j = 7;
      while (spr_current_status[j]) {
        if (--j == 1)
          return;
      }
      io_sound_ch3 = 23;
      spr_current_status[j] = 8;
      spr_spriteid[j] = 51;
      uint8 v3 = bowserbattle_var14b7;
      bowserbattle_var14b7 = v3 + 32;
      SetSprXYPos(j, v3, 0);
      InitializeNormalSpriteRAMTables(j);
      ++spr_table00c2[j];
      spr_property_bits1686[j] &= ~0x80;
      spr_property_bits1662[j] = 57;
      io_sound_ch3 = kSpr0A0_ActivateBowserBattle_RainingFireSounds[v3 >> 5];
    }
  } else {
    io_music_ch1 = 24;
    spr_table151c[k] = 2;
    SetSprYPos(k, 24);
    misc_m7_angle = 0x808;
    spr_xspeed[k] = 100;
  }
}

void Spr0A0_ActivateBowserBattle_State02_SwoopIn(uint8 k) {  // 03a84b
  spr_yspeed[k] = 0;
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    if (v1 == 0xA0) {
      Spr0A0_ActivateBowserBattle_03A8D6(k);
      v1 = -96;
    }
    spr_xspeed[k] = 0;
    spr_yspeed[k] = 0;
    if (v1 == 1) {
      spr_table151c[k] = bowserbattle_var14b4 + 1;
      spr_xspeed[k] = 0;
      spr_yspeed[k] = 0;
      bowserbattle_var14b0 = 0x80;
    } else if (v1 >= 0x40) {
      if (v1 == 0xE8)
        io_sound_ch1 = 42;
      spr_table1594[k] = v1 - 63;
    } else {
      if (v1 == 63)
        io_music_ch1 = kSpr0A0_ActivateBowserBattle_RainingFireSounds[bowserbattle_var14b4 + 1];
      spr_table1570[k] = kSpr0A0_ActivateBowserBattle_DuckingAnimationFrames[v1 >> 3];
    }
  } else {
    if (spr_xspeed[k])
      --spr_xspeed[k];
    if ((counter_global_frames & 3) == 0) {
      LOBYTE(misc_m7_angle) = misc_m7_angle + 1;
      ++HIBYTE(misc_m7_angle);
      if ((uint8)misc_m7_angle == 32)
        spr_decrementing_table1540[k] = -1;
    }
  }
}

void Spr0A0_ActivateBowserBattle_03A8D6(uint8 k) {  // 03a8d6
  uint8 j = 7;
  while (spr_current_status[j]) {
    if (--j == 1)
      return;
  }
  io_sound_ch1 = 16;
  spr_current_status[j] = 8;
  spr_spriteid[j] = 116;
  SetSprXPos(j, GetSprXPos(k) + 4);
  SetSprYPos(j, GetSprYPos(k) + 24);
  InitializeNormalSpriteRAMTables(j);
  spr_yspeed[j] = -64;
  spr_table157c[j] = 0;
  uint8 v5 = 12;
  if ((spr_xpos_lo[j] & 0x80) != 0) {
    v5 = -12;
    ++spr_table157c[j];
  }
  spr_xspeed[j] = v5;
}

void Spr07C_PrincessPeach_GFXRt_DrawHELP(uint8 k, uint8 j, uint8 r2, uint8 r3) {  // 03aa6e
  uint8 r0 = spr_xpos_lo[k] + 4 - mirror_current_layer1_xpos;
  uint8 r1 = spr_ypos_lo[k] + 32 - r2 - mirror_current_layer1_ypos;
  if (j >= 8 && j < 0x10) {
    int8 v2 = r0 - 4;
    OamEnt *oam = get_OamEnt(oam_buf, 0);
    oam[40].xpos = r0 - 4;
    oam[41].xpos = v2 + 16;
    int8 v4 = r1 - 24;
    oam[40].ypos = r1 - 24;
    oam[41].ypos = v4;
    oam[40].charnum = 32;
    oam[41].charnum = 34;
    int8 v5 = ((counter_local_frames >> 1) & 6) + 3;
    oam[40].flags = v5;
    oam[41].flags = v5;
    sprites_oamtile_size_buffer[40] = 2;
    sprites_oamtile_size_buffer[41] = 2;
  }
  Spr07C_PrincessPeach_GFXRt_DrawPeach(k, 0x70, (PointU8) { .x = r0, .y = r1 }, r3);
}

void Spr07C_PrincessPeach_GFXRt_DrawPeach(uint8 k, uint8 j, PointU8 pt, uint8 r3) {  // 03aac8
  uint8 r4 = 4 * r3;
  int8 v2 = 3;
  do {
    int8 v6 = v2;
    uint8 v3 = r4 + v2;
    OamEnt *oam = get_OamEnt(oam_buf, j);
    oam[64].xpos = kSpr07C_PrincessPeach_PeachXDisp[v3] + pt.x;
    oam[64].ypos = kSpr07C_PrincessPeach_PeachYDisp[v3] + pt.y;
    oam[64].charnum = kSpr07C_PrincessPeach_PeachTiles[v3];
    uint8 v5 = kSpr07C_PrincessPeach_PeachProp[v3];
    if (spr_current_slotid != 9)
      v5 |= 0x30;
    oam[64].flags = v5;
    sprites_oamtile_size_buffer[(j >> 2) + 64] = 2;
    j += 4;
    v2 = v6 - 1;
  } while ((int8)v2 >= 0);
}

void Spr0A0_ActivateBowserBattle_State08_Phase2(uint8 k) {  // 03ab21
  Spr0A0_ActivateBowserBattle_03A4FD(k);
  Spr0A0_ActivateBowserBattle_03A4D2(k);
  Spr0A0_ActivateBowserBattle_03A4ED(k);

  bool v1 = (int16)(GetSprXPos(k) - player_xpos) >= 0;
  if (spr_xspeed[k] != kSpr0A0_ActivateBowserBattle_DATA_03AB17[v1])
    spr_xspeed[k] += kSpr0A0_ActivateBowserBattle_DATA_03AB15[v1];
  bool v3 = sign8(spr_ypos_lo[k] - 16) == 0;
  if (spr_yspeed[k] != kSpr0A0_ActivateBowserBattle_DATA_03AB1B[v3])
    spr_yspeed[k] += kSpr0A0_ActivateBowserBattle_DATA_03AB19[v3];
}

void Spr0A0_ActivateBowserBattle_State09_Phase3(uint8 k) {  // 03ab64
  spra0_bowser_clown_car_face_anim_frame = 3;
  Spr0A0_ActivateBowserBattle_03A4FD(k);
  Spr0A0_ActivateBowserBattle_03A4D2(k);
  Spr0A0_ActivateBowserBattle_03A4ED(k);
  spr_yspeed[k] += 3;
  if (spr_ypos_lo[k] >= 0x64 && (spr_ypos_hi[k] & 0x80) == 0) {
    spr_ypos_lo[k] = 100;
    spr_yspeed[k] = -96;
    io_sound_ch3 = 9;
    spr_xspeed[k] = kSpr0A0_ActivateBowserBattle_DATA_03AB62[CheckPlayerPositionRelativeToSprite_Bank23_X(k)];
    timer_shake_layer1 = 32;
  }
}

void Spr0A0_ActivateBowserBattle_State04_RiseUpToDie(uint8 k) {  // 03ab9f
  Spr0A0_ActivateBowserBattle_03A6AC(k);
  if (GetSprYPos(k) < 0x10) {
    spr_table151c[k] = 5;
    spr_decrementing_table1540[k] = 96;
  }
  spr_yspeed[k] = -8;
}

void Spr0A0_ActivateBowserBattle_State05_ClownCarMalfunction(uint8 k) {  // 03abbe
  Spr0A0_ActivateBowserBattle_03A6AC(k);
  spr_xspeed[k] = 0;
  spr_yspeed[k] = 0;
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    if (v1 >= 0x40) {
      if (v1 == 94)
        io_music_ch1 = 27;
      if (!spr_decrementing_table1564[k])
        spr_decrementing_table1564[k] = 18;
    }
  } else {
    misc_m7_rotation += 10;
    if (HIBYTE(misc_m7_rotation)) {
      LOBYTE(misc_m7_rotation) = 0;
      spr_decrementing_table154c[k] = 32;
      spr_decrementing_table1540[k] = 96;
      spr_table151c[k] = 6;
    }
  }
}

void Spr0A0_ActivateBowserBattle_State06_DropPeachAndFlyOff(uint8 k) {  // 03ac03
  Spr0A0_ActivateBowserBattle_03A6AC(k);
  if (spr_decrementing_table154c[k] == 1) {
    player_current_state = 11;
    ++spra0_bowser_end_of_battle_flag;
    palettes_background_color = 0;
    player_current_layer_priority = 3;
    Spr0A0_ActivateBowserBattle_03AC63(k);
  }
  if (!spr_decrementing_table1540[k]) {
    spr_xspeed[k] = -6;
    spr_yspeed[k] = -4;
    misc_m7_rotation += 5;
    if ((counter_global_frames & 3) == 0) {
      if ((uint8)misc_m7_angle >= 0x80) {
        if (!spr_table164a[k]) {
          io_music_ch1 = 28;
          ++spr_table164a[k];
        }
        spr_xpos_hi[k] = -2;
        spr_ypos_hi[k] = -2;
      } else {
        LOBYTE(misc_m7_angle) = misc_m7_angle + 1;
        ++HIBYTE(misc_m7_angle);
      }
    }
  }
}

void Spr0A0_ActivateBowserBattle_03AC63(uint8 k) {  // 03ac63
  spr_current_status[8] = 8;
  spr_spriteid[8] = 124;
  SetSprXPos(8, GetSprXPos(k) + 8);
  SetSprYPos(8, GetSprYPos(k) + 71);
  InitializeNormalSpriteRAMTables(8);
}

void Spr07C_PrincessPeach(uint8 k) {  // 03ac97
  uint8 r0 = spr_xpos_lo[k] - mirror_current_layer1_xpos;
  uint8 r1 = spr_ypos_lo[k] - mirror_current_layer1_ypos;
  if ((counter_global_frames & 0x7F) == 0 && (GetRand() & 7) == 0)
    spr_decrementing_table154c[k] = 12;
  uint8 v1 = spr_table1602[k];
  if (spr_decrementing_table154c[k])
    ++v1;
  if (!spr_table157c[k])
    v1 += 8;
  uint8 r3 = v1;
  spr_oamindex[k] = -48;
  Spr07C_PrincessPeach_GFXRt_DrawPeach(k, 0xD0, (PointU8) { .x = r0, .y = r1 }, r3);
  FinishOAMWrite(k, 2, 3);
  if (spr_decrementing_table1558[k]) {
    uint8 ka = k;
    bool v2 = player_current_power_up == 0;
    OamEnt *oam = get_OamEnt(oam_buf, 0x4C);
    oam[64].xpos = player_on_screen_pos_x;
    oam[64].ypos = kSpr07C_PrincessPeach_BlushYDisp[v2] + player_on_screen_pos_y;
    oam[64].charnum = kSpr07C_PrincessPeach_BlushTiles[v2];
    k = ka;
    int8 v4 = 49;
    if (player_facing_direction)
      v4 = 113;
    oam[64].flags = v4;
    sprites_oamtile_size_buffer[83] = 2;
  }
  spr_xspeed[k] = 0;
  player_xspeed = 0;
  spr_table1602[k] = 4;
  kSpr07C_PrincessPeach_PrincessPeachPtrs[spr_table00c2[k]](k);
}

void Spr07C_PrincessPeach_FloatingDown(uint8 k) {  // 03ad37
  spr_table1602[k] = 6;
  UpdateNormalSpritePosition_Y(k);
  if (spr_yspeed[k] < 8)
    ++spr_yspeed[k];
  if ((spr_ypos_hi[k] & 0x80) == 0 && spr_ypos_lo[k] >= 0xA0) {
    spr_ypos_lo[k] = -96;
    spr_yspeed[k] = 0;
    spr_decrementing_table1540[k] = -96;
    ++spr_table00c2[k];
  }
  if ((counter_global_frames & 7) == 0) {
    uint8 j = 11;
    while (mextspr_spriteid[j]) {
      if ((--j & 0x80) != 0)
        return;
    }
    mextspr_spriteid[j] = 5;
    uint8 r = GetRand();
    SetHiLo(&mextspr_xpos_hi[j], &mextspr_xpos_lo[j], GetSprXPos(k) + (r & 0x1F) - 8);
    SetHiLo(&mextspr_ypos_hi[j], &mextspr_ypos_lo[j], GetSprYPos(k) + (misc_random_byte2 & 0x1F));
    mextspr_yspeed[j] = 0;
    mextspr_timer[j] = 23;
  }
}

void Spr07C_PrincessPeach_WaitAfterFall(uint8 k) {  // 03adb3
  if (!spr_decrementing_table1540[k]) {
    ++spr_table00c2[k];
    if (Spr07C_PrincessPeach_03ADCC(k) & 1)
      ++spr_table151c[k];
  }
  uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
  spr_table157c[k] = v1;
  player_facing_direction = v1;
}

uint8 Spr07C_PrincessPeach_03ADCC(uint8 k) {  // 03adcc
  CollInfo ci;
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k, &ci);
  StandardSpriteToSpriteCollisionChecks_GetMarioClipping(&ci);
  return StandardSpriteToSpriteCollisionChecks_CheckContact(&ci);
}

void Spr07C_PrincessPeach_WalkTowardsBro(uint8 k) {  // 03addd
  if ((counter_local_frames & 8) == 0)
    spr_table1602[k] = 8;
  uint8 peach = Spr07C_PrincessPeach_03ADCC(k);
  uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
  if (spr_table151c[k]) {
    if (peach) {
      v1 ^= 1;
LABEL_8:;
      uint8 v2 = kSpr07C_PrincessPeach_XSpeed[v1];
      spr_xspeed[k] = v2;
      player_xspeed = -v2;
      spr_table157c[k] = v1;
      player_facing_direction = v1;
      UpdateNormalSpritePosition_X(k);
      return;
    }
  } else if (!peach) {
    goto LABEL_8;
  }
  uint8 v3 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
  spr_table157c[k] = v3;
  player_facing_direction = v3;
  ++spr_table00c2[k];
  spr_decrementing_table1540[k] = 96;
}

void Spr07C_PrincessPeach_StandByBro(uint8 k) {  // 03ae25
  if (!spr_decrementing_table1540[k]) {
    ++spr_table00c2[k];
    spr_decrementing_table1540[k] = -96;
  }
}

void Spr07C_PrincessPeach_KissBro(uint8 k) {  // 03ae32
  uint8 v1 = spr_decrementing_table1540[k];
  if (!v1) {
    ++spr_table00c2[k];
    unusedram_7e188a = 0;
    player_relative_yposition_during_screen_shake = 0;
  }
  if (v1 >= 0x50) {
    if (v1 == 0x50)
      spr_decrementing_table154c[k] = 0x14;
    spr_table1602[k] = 10;
    if (v1 == 104)
      spr_decrementing_table1558[k] = 0x80;
  }
}

void Spr07C_PrincessPeach_DisplayMessage(uint8 k) {  // 03aeaf
  Spr07C_PrincessPeach_DisplayPeachRescueMessage();
  if (!spr_decrementing_table1540[k]) {
    uint8 v1 = spr7c_princess_peach_current_letter;
    if ((uint8)spr7c_princess_peach_current_letter == 84) {
      ++spr_table00c2[k];
      spr_decrementing_table1540[k] = 64;
    } else {
      LOBYTE(spr7c_princess_peach_current_letter) = spr7c_princess_peach_current_letter + 1;
      spr_decrementing_table1540[k] = kSpr07C_PrincessPeach_DATA_03AE5B[v1];
    }
  }
}

void Spr07C_PrincessPeach_03AED0(uint8 k) {  // 03aed0
  ++spr_table00c2[k];
  spr7c_princess_peach_spawn_fireworks_timer = 0x80;
}

void Spr07C_PrincessPeach_FadeText(uint8 k) {  // 03aee8
  unsigned int v3;

  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    uint16 r0w = v1 >> 1;
    r0w |= 32 * r0w;
    r0w |= 32 * r0w;
    uint8 v2 = palettes_dynamic_palette_upload_index;
    v3 = palettes_dynamic_palette_upload_index;
    *(&palettes_dynamic_palette_bytes_to_upload + palettes_dynamic_palette_upload_index) = 2;
    *(&palettes_dynamic_palette_cgramaddress + v3) = -15;
    palettes_dynamic_palette_colors[v2] = r0w;
    palettes_dynamic_palette_colors[v2 + 1] = r0w >> 8;
    palettes_dynamic_palette_colors[v2 + 2] = 0;
    palettes_dynamic_palette_upload_index = v2 + 4;
    Spr07C_PrincessPeach_DisplayPeachRescueMessage();
  } else {
    Spr07C_PrincessPeach_03AED0(k);
  }
}

void Spr0A0_ActivateBowserBattle_03AF59(uint8 k) {  // 03af59
  GetDrawInfoRes drt;
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r4 = spr_table157c[k];
  uint8 r2 = (counter_local_frames >> 2) & 7;
  spr_oamindex[k] = -20;
  uint8 v1 = -20;
  int8 v2 = 3;
  do {
    uint8 v3 = (r2 + __CFSHL__(2 * v2, 1) + 4 * v2) & 7;
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam[64].xpos = kSpr0A0_ActivateBowserBattle_DATA_03AF34[v3] + drt.x;
    oam[64].ypos = kSpr0A0_ActivateBowserBattle_DATA_03AF3C[v3] + drt.y;
    oam[64].charnum = 89;
    oam[64].flags = sprites_tile_priority | kSpr0A0_ActivateBowserBattle_DATA_03AF44[v3];
    v1 += 4;
  } while ((int8)--v2 >= 0);
  uint8 v5 = bowserbattle_var14b3++;
  uint8 v6 = v5 >> 3;
  if (v6 < 0xD) {
    OamEnt *v7 = get_OamEnt(oam_buf, 0xFC);
    v7[64].xpos = drt.x + __CFSHL__(4 * (4 * r4 + __CFSHL__(r4, 1)), 1) + 8 * (4 * r4 + __CFSHL__(r4, 1)) + 21;
    v7[64].ypos = kSpr0A0_ActivateBowserBattle_DATA_03AF4C[v6] + drt.y;
    v7[64].charnum = 73;
    v7[64].flags = sprites_tile_priority | 7;
  }
  FinishOAMWrite(k, 0, 4);
  uint8 v8 = spr_oamindex[k];
  for (int8 i = 4; i >= 0; --i) {
    OamEnt *v10 = get_OamEnt(oam_buf, v8);
    *v10 = v10[64];
    sprites_oamtile_size_buffer[v8 >> 2] = sprites_oamtile_size_buffer[(v8 >> 2) + 64];
    v8 += 4;
  }
}

void Spr0A0_ActivateBowserBattle_03B019(uint8 k) {  // 03b019
  Spr0A0_ActivateBowserBattle_03B020(k, 0);
  Spr0A0_ActivateBowserBattle_03B020(k, 1);
}

void Spr0A0_ActivateBowserBattle_03B020(uint8 k, uint8 r2) {  // 03b020
  uint8 j = 1;
  while (spr_current_status[j]) {
    if ((--j & 0x80) != 0)
      return;
  }
  spr_current_status[j] = 8;
  spr_spriteid[j] = -94;
  SetSprYPos(j, GetSprYPos(k) + 16);
  SetSprXPos(j, GetSprXPos(k) + PAIR16(kSpr0A0_ActivateBowserBattle_DATA_03B015[r2], kSpr0A0_ActivateBowserBattle_DATA_03B013[r2]));
  InitializeNormalSpriteRAMTables(j);
  spr_xspeed[j] = kSpr0A0_ActivateBowserBattle_DATA_03B017[r2];
  spr_yspeed[j] = -64;
}

void Spr0A0_ActivateBowserBattle_03B078(uint8 k) {  // 03b078
  if ((uint8)misc_m7_angle == 32 && spr_table151c[k] >= 7 && !misc_m7_rotation) {
    Spr0A0_ActivateBowserBattle_03B0DC(k);
    if (!spr_decrementing_table154c[k]) {
      spr_property_bits1662[k] = 36;
      if (CheckPlayerToNormalSpriteCollision(k) & 1) {
        Spr0A0_ActivateBowserBattle_03B0D6(k);
        player_yspeed = 0;
        uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
        uint8 v2;
        if (bowserbattle_var14b6 | bowserbattle_var14b1)
          v2 = kSpr0A0_ActivateBowserBattle_DATA_03B076[v1];
        else
          v2 = kSpr0A0_ActivateBowserBattle_DATA_03B074[v1];
        player_xspeed = v2;
        io_sound_ch1 = 1;
      }
      ++spr_property_bits1662[k];
      if (CheckPlayerToNormalSpriteCollision(k) & 1)
        Spr0A0_ActivateBowserBattle_03B0D2(k);
      ++spr_property_bits1662[k];
      if (CheckPlayerToNormalSpriteCollision(k) & 1)
        Spr0A0_ActivateBowserBattle_03B0D2(k);
    }
  }
}

void Spr0A0_ActivateBowserBattle_03B0D2(uint8 k) {  // 03b0d2
  DamagePlayer_Hurt();
  Spr0A0_ActivateBowserBattle_03B0D6(k);
}

void Spr0A0_ActivateBowserBattle_03B0D6(uint8 k) {  // 03b0d6
  spr_decrementing_table154c[k] = 32;
}

void Spr0A0_ActivateBowserBattle_03B0DC(uint8 k) {  // 03b0dc
  uint8 v1 = 1;
  do {
    if (spr_current_status[v1] == 9 && !spr_xoffscreen_flag[v1])
      Spr0A0_ActivateBowserBattle_03B0F3(k, v1);
  } while ((int8)--v1 >= 0);
}

void Spr0A0_ActivateBowserBattle_03B0F3(uint8 k, uint8 j) {  // 03b0f3
  CollInfo ci;
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingB(j, &ci);
  spr_property_bits1662[k] = 36;
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k, &ci);
  if (!(StandardSpriteToSpriteCollisionChecks_CheckContact(&ci))) {
    ++spr_property_bits1662[k];
    StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k, &ci);
    if (!(StandardSpriteToSpriteCollisionChecks_CheckContact(&ci)) || bowserbattle_var14b5)
      return;
    bowserbattle_var14b5 = 76;
    bowserbattle_var14b3 = 0;
    bowserbattle_var14b4 = spr_table151c[k];
    io_sound_ch3 = 40;
    if (spr_table151c[k] == 9 && spr_table187b[k] == 1)
      DespawnNonBossSprites();
  }
  spr_xspeed[j] = 0;
  spr_yspeed[j] = ((spr_yspeed[j] & 0x80) == 0) ? -48 : 16;
  spr_current_status[j] = 2;
  SpawnContactEffectFromSide(j);
}

void Spr0A1_BowserBowlingBall(uint8 k) {  // 03b163
  Spr0A1_BowserBowlingBall_Draw(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank03_Entry1(k);
    CheckPlayerToNormalSpriteCollision(k);
    UpdateNormalSpritePosition_X(k);
    UpdateNormalSpritePosition_Y(k);
    if (sign8(spr_yspeed[k] - 64))
      spr_yspeed[k] += 3;
    else
      spr_yspeed[k] = 64;
    if ((spr_yspeed[k] & 0x80) == 0 && (spr_ypos_hi[k] & 0x80) == 0 && spr_ypos_lo[k] >= 0xB0) {
      spr_ypos_lo[k] = -80;
      uint8 v1 = spr_yspeed[k];
      if (v1 >= 0x3E) {
        io_sound_ch3 = 37;
        timer_shake_layer1 = 32;
      }
      if (v1 >= 8)
        io_sound_ch1 = 1;
      Spr0A1_BowserBowlingBall_MakeBallBounce(k);
      if (!spr_xspeed[k])
        spr_xspeed[k] = kSpr0A1_BowserBowlingBall_XSpeed[CheckPlayerPositionRelativeToSprite_Bank23_X(k)];
    }
    int8 v2 = spr_xspeed[k];
    if (v2)
      spr_table1570[k] += (v2 >= 0) ? -1 : 1;
  }
}

void Spr0A1_BowserBowlingBall_Draw(uint8 k) {  // 03b221
  GetDrawInfoRes drt;

  spr_oamindex[k] = 112;
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  for (uint8 i = 11; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
    oam[64].xpos = kSpr0A1_BowserBowlingBall_XDisp[i] + drt.x;
    oam[64].ypos = kSpr0A1_BowserBowlingBall_YDisp[i] + drt.y;
    oam[64].charnum = kSpr0A1_BowserBowlingBall_Tiles[i];
    oam[64].flags = sprites_tile_priority | kSpr0A1_BowserBowlingBall_Prop[i];
    sprites_oamtile_size_buffer[(drt.idx >> 2) + 64] = kSpr0A1_BowserBowlingBall_TileSize[i];
    drt.idx += 4;
  }
  uint8 v6 = (spr_table1570[k] >> 3) & 7;
  OamEnt *v4 = get_OamEnt(oam_buf, spr_oamindex[k]);
  v4[65].xpos += kSpr0A1_BowserBowlingBall_XDisp2[v6];
  v4[65].ypos += kSpr0A1_BowserBowlingBall_YDisp2[v6];
  uint8 v5 = (v6 + 2) & 7;
  v4[66].xpos += kSpr0A1_BowserBowlingBall_XDisp2[v5];
  v4[66].ypos += kSpr0A1_BowserBowlingBall_YDisp2[v5];
  FinishOAMWrite(k, 0xFF, 0xB);
}

void Spr0A2_MechaKoopa(uint8 k) {  // 03b2a9
  Spr0A2_MechaKoopa_Draw(k);
  if (spr_current_status[k] == 8 && !flag_sprites_locked) {
    SubOffscreen_Bank03_Entry1(k);
    CheckPlayerAndNormalSpriteCollisions(k);
    HandleNormalSpriteGravity(k);
    if ((spr_table1588[k] & 4) != 0) {
      spr_yspeed[k] = 0;
      spr_xspeed[k] = kSpr0A2_MechaKoopa_XSpeed[spr_table157c[k]];
      uint8 v1 = spr_table00c2[k];
      spr_table00c2[k] = v1 + 1;
      if ((v1 & 0x3F) == 0)
        spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
    }
    if ((spr_table1588[k] & 3) != 0) {
      spr_xspeed[k] = -spr_xspeed[k];
      spr_table157c[k] ^= 1;
    }
    spr_table1602[k] = (uint8)(++spr_table1570[k] & 0xC) >> 2;
  }
}

void Spr0A2_MechaKoopa_Draw(uint8 k) {  // 03b307
  Spr0A2_MechaKoopa_MechakoopaDraw(k);
}

void Spr0A2_MechaKoopa_MechakoopaDraw(uint8 k) {  // 03b355
  GetDrawInfoRes drt;

  spr_table15f6[k] = 11;
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    uint8 v2 = 5;
    if (v1 < 5 || v1 >= 0xFA)
      v2 = 4;
    spr_table1602[k] = v2;
    if (spr_decrementing_table1540[k] < 0x30)
      spr_table15f6[k] = kSpr0A2_MechaKoopa_MechakoopaPalette[spr_decrementing_table1540[k] & 1];
  }
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r4 = spr_table15f6[k];
  uint8 v4 = drt.idx + 12;
  uint8 r3 = 4 * spr_table1602[k];
  uint8 r2 = (4 * spr_table157c[k]) ^ 4;
  uint8 v5 = 3;
  do {
    uint8 v9 = v5;
    sprites_oamtile_size_buffer[(v4 >> 2) + 64] = kSpr0A2_MechaKoopa_MechakoopaTileSize[v5];
    uint8 v6 = r2 + v5;
    OamEnt *oam = get_OamEnt(oam_buf, v4);
    oam[64].xpos = kSpr0A2_MechaKoopa_MechakoopaXDisp[v6] + drt.x;
    oam[64].flags = sprites_tile_priority | r4 | kSpr0A2_MechaKoopa_MechakoopaProp[v6];
    uint8 v8 = r3 + v9;
    oam[64].charnum = kSpr0A2_MechaKoopa_MechakoopaTiles[(uint8)(r3 + v9)];
    oam[64].ypos = kSpr0A2_MechaKoopa_MechakoopaYDisp[v8] + drt.y;
    v4 -= 4;
    v5 = v9 - 1;
  } while ((int8)v5 >= 0);
  FinishOAMWrite(k, 0xFF, 3);
  Spr0A2_MechaKoopa_KeyDraw(k);
}

void Spr0A2_MechaKoopa_KeyDraw(uint8 k) {  // 03b3f7
  GetDrawInfoRes drt;

  spr_oamindex[k] += 16;
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r2 = (spr_table1570[k] >> 2) & 3;
  uint8 v2 = spr_table157c[k];
  OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
  oam[64].xpos = kSpr0A2_MechaKoopa_KeyXDisp[v2] + drt.x;
  oam[64].ypos = drt.y;
  oam[64].flags = sprites_tile_priority | kSpr0A2_MechaKoopa_KeyProp[v2];
  oam[64].charnum = kSpr0A2_MechaKoopa_KeyTiles[r2];
  FinishOAMWrite(k, 0, 0);
}

void Spr0A0_ActivateBowserBattle_Draw() {  // 03b43c
  Spr0A0_ActivateBowserBattle_DrawItemBox();
  Spr0A0_ActivateBowserBattle_DrawCastleRoof();
}

void Spr0A0_ActivateBowserBattle_DrawItemBox() {  // 03b44f
  if (spra0_bowser_end_of_battle_flag)
    player_current_item_box = 0;
  if (player_current_item_box) {
    uint8 v0 = 3;
    uint8 v1 = 4;
    do {
      OamEnt *oam = get_OamEnt(oam_buf, v1);
      oam->xpos = kSpr0A0_ActivateBowserBattle_ItemBoxXPos[v0];
      oam->ypos = kSpr0A0_ActivateBowserBattle_ItemBoxYPos[v0];
      oam->charnum = 67;
      oam->flags = kSpr0A0_ActivateBowserBattle_ItemBoxProp[v0];
      sprites_oamtile_size_buffer[v1 >> 2] = 2;
      v1 += 4;
      --v0;
    } while ((v0 & 0x80) == 0);
  }
}

void Spr0A0_ActivateBowserBattle_DrawCastleRoof() {  // 03b4ac
  uint8 v0 = -68;
  uint8 r1 = 0;
  uint8 r15 = spra0_bowser_end_of_battle_flag;
  int8 v1 = 16;
  if (spra0_bowser_end_of_battle_flag) {
    v0 = -112;
    v1 = 15;
  }
  do {
    OamEnt *oam = get_OamEnt(oam_buf, v0);
    oam[64].ypos = -64 - mirror_current_layer1_ypos;
    int8 v3 = r1 - mirror_current_layer1_xpos;
    oam[64].xpos = r1 - mirror_current_layer1_xpos;
    r1 = v3 + 16;
    oam[64].charnum = 8;
    oam[64].flags = sprites_tile_priority | 0xD;
    sprites_oamtile_size_buffer[(v0 >> 2) + 64] = 2;
    v0 += 4;
    --v1;
  } while (v1 >= 0);
  uint8 v4 = 15;
  if (r15) {
    uint8 v8 = 80;
    do {
      OamEnt *v9 = get_OamEnt(oam_buf, v8);
      v9[64].xpos = kSpr0A0_ActivateBowserBattle_RoofXPos[v4] - mirror_current_layer1_xpos;
      v9[64].ypos = kSpr0A0_ActivateBowserBattle_RoofYPos[v4] - mirror_current_layer1_ypos;
      int8 v10 = 8;
      if (v4 < 6)
        v10 = 3;
      v9[64].charnum = v10;
      v9[64].flags = sprites_tile_priority | 0xD;
      sprites_oamtile_size_buffer[(v8 >> 2) + 64] = 2;
      v8 += 4;
      --v4;
    } while ((v4 & 0x80) == 0);
  } else {
    uint8 v5 = 20;
    do {
      OamEnt *v6 = get_OamEnt(oam_buf, v5);
      v6->xpos = kSpr0A0_ActivateBowserBattle_RoofXPos[v4] - mirror_current_layer1_xpos;
      v6->ypos = kSpr0A0_ActivateBowserBattle_RoofYPos[v4] - mirror_current_layer1_ypos;
      int8 v7 = 8;
      if (v4 < 6)
        v7 = 3;
      v6->charnum = v7;
      v6->flags = sprites_tile_priority | 0xD;
      sprites_oamtile_size_buffer[v5 >> 2] = 2;
      v5 += 4;
      --v4;
    } while ((v4 & 0x80) == 0);
  }
}

void StandardSpriteToSpriteCollisionChecks_GetMarioClipping(CollInfo *ci) {  // 03b664
  SetHiLo(&ci->r8, &ci->r0, player_xpos + 2);
  ci->r2 = 12;
  uint8 v0 = 0;
  if (player_ducking_flag || !player_current_power_up)
    v0 = 1;
  if (player_riding_yoshi_flag)
    v0 += 2;
  ci->r3 = kStandardSpriteToSpriteCollisionChecks_MarioClippingHeight[v0];
  SetHiLo(&ci->r9, &ci->r1, player_ypos + kStandardSpriteToSpriteCollisionChecks_MarioClipDispY[v0]);
}

void StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(uint8 k, CollInfo *ci) {  // 03b69f
  uint8 v2 = spr_property_bits1662[k] & 0x3F;
  SetHiLo(&ci->r10, &ci->r4, GetSprXPos(k) + (int8)kStandardSpriteToSpriteCollisionChecks_SprClippingDispX[v2]);
  ci->r6 = kStandardSpriteToSpriteCollisionChecks_SprClippingWidth[v2];
  SetHiLo(&ci->r11, &ci->r5, GetSprYPos(k) + (int8)kStandardSpriteToSpriteCollisionChecks_SprClippingDispY[v2]);
  ci->r7 = kStandardSpriteToSpriteCollisionChecks_SprClippingHeight[v2];
}

void StandardSpriteToSpriteCollisionChecks_GetSpriteClippingB(uint8 k, CollInfo *ci) {  // 03b6e5
  uint8 v2 = spr_property_bits1662[k] & 0x3F;
  SetHiLo(&ci->r8, &ci->r0, GetSprXPos(k) + (int8)kStandardSpriteToSpriteCollisionChecks_SprClippingDispX[v2]);
  ci->r2 = kStandardSpriteToSpriteCollisionChecks_SprClippingWidth[v2];
  SetHiLo(&ci->r9, &ci->r1, GetSprYPos(k) + (int8)kStandardSpriteToSpriteCollisionChecks_SprClippingDispY[v2]);
  ci->r3 = kStandardSpriteToSpriteCollisionChecks_SprClippingHeight[v2];
}


uint8 StandardSpriteToSpriteCollisionChecks_CheckContact(CollInfo *ci) {  // 03b72b
  for (uint8 i = 1; (i & 0x80) == 0; --i) {
    uint8 r0 = *(&ci->r0 + i);
    uint8 v4 = r0 - *(&ci->r4 + i);
    uint8 r12 = *(&ci->r8 + i) - (r0 < *(&ci->r4 + i)) - *(&ci->r10 + i);
    uint16 t = r12 + ((v4 + 0x80) >> 8);
    if ((uint8)t)
      return false;
    uint8 r15 = *(&ci->r6 + i) + *(&ci->r4 + i) - *(&ci->r0 + i);
    if ((uint8)(*(&ci->r6 + i) + *(&ci->r2 + i)) < r15)
      return false;
  }
  return true;
}

void Spr0A1_BowserBowlingBall_MakeBallBounce(uint8 k) {  // 03b7f8
  uint8 v2 = spr_yspeed[k];
  spr_yspeed[k] = 0;
  uint8 v1 = v2 >> 2;
  if (spr_spriteid[k] == 0xA1)
    v1 += 19;
  if ((spr_table1588[k] & 0x80) == 0)
    spr_yspeed[k] = kSpr0A1_BowserBowlingBall_BounceYSpeed[v1];
}

void SubOffscreen_Bank03_Entry4(uint8 k) {  // 03b84f
  SubOffscreen_Bank03_03B85F(k, 6);
}

void SubOffscreen_Bank03_Entry1(uint8 k) {  // 03b85d
  SubOffscreen_Bank03_03B85F(k, 0);
}

void SubOffscreen_Bank03_03B85F(uint8 k, uint8 r3) {  // 03b85f
  if (!CheckIfNormalSpriteOffScreen(k))
    return;
  if ((misc_level_layout_flags & 1) != 0) {
    if ((spr_property_bits167a[k] & 4) == 0 && !(counter_global_frames & 1)) {
      bool v1 = (counter_global_frames & 2) != 0;
      uint8 r1 = v1;
      uint16 ypos = PAIR16(kSubOffscreen_Bank03_DATA_03B83D[v1], kSubOffscreen_Bank03[v1]) + mirror_current_layer1_ypos - GetSprYPos(k);
      uint8 r0 = ypos >> 8;
      if ((counter_global_frames & 2) != 0)
        r0 ^= 0x80;
      if ((r0 & 0x80) != 0)
        goto LABEL_8;
    }
  } else {
    uint16 y = GetSprYPos(k);
    bool want_erase = g_lunar_magic ? LmHook_WantEraseSprite(k, y) : !sign8(((y + 80) >> 8) - 2);
    if (want_erase)
      goto LABEL_8;
    if ((spr_property_bits167a[k] & 4) == 0) {
      uint8 r1 = r3 | counter_global_frames & 1;
      uint16 xpos =
          PAIR16(kSubOffscreen_Bank03_DATA_03B847[r1], kSubOffscreen_Bank03_DATA_03B83F[r1]) + mirror_current_layer1_xpos - GetSprXPos(k);
      uint8 r0 = xpos >> 8;
      if (r1 & 1)
        r0 ^= 0x80;
      if ((r0 & 0x80) != 0) {
LABEL_8:
        if (spr_current_status[k] >= 8) {
          uint8 v4 = spr_load_status_table_index[k];
          if (v4 != 0xFF)
            sprites_load_status[v4] = 0;
        }
        spr_current_status[k] = 0;
      }
    }
  }
}

void Spr054_ClimbingNetDoor_UpdateClimbingNetDoorTiles(uint8 k, uint8 a) {  // 03c000
  blocks_map16_to_generate = a;
  blocks_xpos = GetSprXPos(k) - 8;
  blocks_ypos = GetSprYPos(k) + 8;
  GenerateTile();
}

void CheckIfBabyYoshiCanEatNormalSprite1(uint8 k) {  // 03c02f
  uint8 v1 = spr_table160e[k];
  spr_current_status[v1] = 0;
  io_sound_ch1 = 6;
  if (!spr_table160e[v1]) {
    uint8 v2 = spr_spriteid[v1];
    if (v2 == 0x81)
      v2 = kCheckIfBabyYoshiCanEatNormalSprite_ChangingItemSpriteType[(counter_local_frames >> 4) & 3];
    if (v2 >= 0x74) {
      bool v3 = v2 >= 0x78;
      if (v2 < 0x78)
        goto LABEL_6;
    }
  }
  uint8 v5 = ++spr_table1570[k];
  bool v3 = v5 >= 5;
  if (v5 == 5) {
LABEL_6:
    yoshi_swallow_timer = 0;
    yoshi_yoshi_has_wings = 0;
    spr_spriteid[k] = 53;
    spr_current_status[k] = 8;
    io_sound_ch3 = 31;
    SetSprYPos(k, GetSprYPos(k) - 16);
    uint8 v6 = spr_table15f6[k];
    InitializeNormalSpriteRAMTables(k);
    spr_table15f6[k] = v6 & 0xFE;
    spr_table1602[k] = 12;
    --spr_table160e[k];
    growing_yoshi_timer = 64;
  } else {
    GiveCoins_OneCoin();
    GivePoints(k, 1);
  }
}

void GameMode14_InLevel_03C0C6() {  // 03c0c6
  if (!flag_sprites_locked)
    GameMode14_InLevel_03C11E();
  uint8 r0 = 0;
  uint8 v0 = 19;
  uint8 v1 = -80;
  do {
//    r2 = v0;
    uint8 v2 = r0;
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam[64].xpos = r0;
    r0 = v2 + 16;
    oam[64].ypos = -60;
    oam[64].flags = sprites_tile_priority | 9;
    oam[64].charnum = kGameMode14_InLevel_DATA_03C0B2[(kGameMode14_InLevel_DATA_03C0B6[v0] + (counter_local_frames >> 3)) & 3];
    sprites_oamtile_size_buffer[(v1 >> 2) + 64] = 2;
    v1 += 4;
    --v0;
  } while ((v0 & 0x80) == 0);
}

void GameMode14_InLevel_03C11E() {  // 03c11e
  if (!(timer_end_level | flag_sprites_locked)) {
    if (timer_wait_before_next_tilting_platform_phase)
      --timer_wait_before_next_tilting_platform_phase;
    if (!(timer_wait_before_next_tilting_platform_phase | counter_global_frames & 1)) {
      uint8 v0 = counter_direction_to_tilt_platform & 1;
      if (counter_tilting_platform_phase >= 4)
        v0 += 2;
      misc_m7_rotation = misc_m7_rotation + PAIR16(kGameMode14_InLevel_DATA_03C116[v0], kGameMode14_InLevel_IggyPlatSpeed[v0]) & 0x1ff;
      if ((uint8)misc_m7_rotation == kGameMode14_InLevel_IggyPlatBounds[v0]) {
        ++counter_direction_to_tilt_platform;
        timer_wait_before_next_tilting_platform_phase = 64;
        if (++counter_tilting_platform_phase == 6)
          counter_tilting_platform_phase = 0;
      }
    }
  }
}

void HandleNormalSpriteLevelColl_03C1CA(uint8 k) {  // 03c1ca
  uint8 j = (spr_slope_surface_its_on[k] & 0x80) != 0;
  AddSprXPos(k, PAIR16(kHandleNormalSpriteLevelColl_DATA_03C1C8[j], kHandleNormalSpriteLevelColl_DATA_03C1C6[j]));
  spr_yspeed[k] = 24;
}

void Spr0C8_LightSwitch(uint8 k) {  // 03c1f5
  if (!flag_sprites_locked) {
    SolidSpriteBlock(k);
    SubOffscreen_Bank03_Entry1(k);
    if (spr_decrementing_table1558[k] == 5) {
      spr_table00c2[k] = 0;
      io_sound_ch1 = 11;
      for (uint8 i = 9; (i & 0x80) == 0; --i) {
        if (spr_current_status[i] == 8 && spr_spriteid[i] == 0xC6)
          spr_table00c2[i] ^= 1;
      }
    }
  }
  uint8 v2 = spr_decrementing_table1558[k] >> 1;
  uint16 old_pos = mirror_current_layer1_ypos;
  mirror_current_layer1_ypos += kSpr0C8_LightSwitch_DATA_03C1EC[v2];
  GenericGFXRtDraw1Tile16x16(k);
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  oam[64].charnum = 42;
  oam[64].flags &= ~0x40;
  mirror_current_layer1_ypos = old_pos;
}

void SprXXX_LineGuided_ChainsawDraw(uint8 k) {  // 03c26b
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 v2 = spr_spriteid[k] - 101;
  uint8 r3 = kSprXXX_LineGuided_YDisp[v2];
  uint8 r4 = kSprXXX_LineGuided_Prop[v2];
  uint8 r2 = counter_local_frames & 2;
  int8 v3 = drt.x - 8;
  OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
  oam[64].xpos = drt.x - 8;
  oam[65].xpos = v3;
  oam[66].xpos = v3;
  int8 v5 = drt.y - 8;
  oam[64].ypos = drt.y - 8;
  int8 v6 = r2 + r3 + v5;
  oam[65].ypos = v6;
  oam[66].ypos = r3 + v6;
  oam[64].charnum = kSprXXX_LineGuided_MotorTiles[(counter_local_frames >> 2) & 3];
  oam[65].charnum = -82;
  oam[66].charnum = -114;
  oam[64].flags = 55;
  uint8 v7 = r4;
  oam[65].flags = r4;
  oam[66].flags = v7;
  FinishOAMWrite(k, 2, 2);
}

void TriggerHidden1up() {  // 03c2d9
  uint8 j = 11;
  while (spr_current_status[j]) {
    if ((--j & 0x80) != 0)
      return;
  }
  spr_current_status[j] = 8;
  spr_spriteid[j] = 120;
  SetSprXYPos(j, player_xpos, player_ypos);
  InitializeNormalSpriteRAMTables(j);
  spr_decrementing_table154c[j] = 16;
  Spr0C7_InvisibleMushroom_PopupMushroom(j);
}

void Spr0C7_InvisibleMushroom(uint8 k) {  // 03c30f
  GetDrawInfoRes drt;
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  if (CheckPlayerToNormalSpriteCollision(k) & 1) {
    spr_spriteid[k] = 116;
    InitializeNormalSpriteRAMTables(k);
    spr_decrementing_table154c[k] = 32;
    AddSprYPos(k, -15);
    Spr0C7_InvisibleMushroom_PopupMushroom(k);
  }
}

void Spr0C7_InvisibleMushroom_PopupMushroom(uint8 k) {  // 03c334
  spr_table157c[k] = (player_xspeed & 0x80) != 0;
  spr_yspeed[k] = -64;
  io_sound_ch3 = 2;
}

void Spr051_Ninji(uint8 k) {  // 03c34c
  GenericGFXRtDraw1Tile16x16(k);
  if (!flag_sprites_locked) {
    spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
    SubOffscreen_Bank03_Entry1(k);
    CheckPlayerAndNormalSpriteCollisions(k);
    HandleNormalSpriteGravity(k);
    if ((spr_table1588[k] & 4) != 0) {
      spr_yspeed[k] = 0;
      if (!spr_decrementing_table1540[k]) {
        spr_decrementing_table1540[k] = 96;
        spr_yspeed[k] = kSpr051_Ninji_YSpeed[++spr_table00c2[k] & 3];
      }
    }
    spr_table1602[k] = (spr_yspeed[k] & 0x80) == 0;
  }
}

void Spr030_ThrowingDryBones_DryBonesAndBonyBeetleDraw(uint8 k) {  // 03c390
  uint8 v1 = spr_table157c[k];
  if (spr_decrementing_table15ac[k] >= 5)
    spr_table157c[k] ^= 1;
  Spr030_ThrowingDryBones_03C3DA(k);
  spr_table157c[k] = v1;
}

void Spr030_ThrowingDryBones_03C3DA(uint8 k) {  // 03c3da
  GetDrawInfoRes drt;

  if (spr_spriteid[k] == 49) {
    GenericGFXRtDraw1Tile16x16(k);
  } else {
    if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
      return;
    uint8 r5 = spr_decrementing_table15ac[k];
    uint8 r2 = 3 * spr_table157c[k];
    uint8 r3 = 3 * spr_table1602[k];
    uint8 r4 = kSpr030_ThrowingDryBones_DATA_03C3D7[spr_table1602[k]];
    uint8 v2 = 2;
    do {
      uint8 v8 = v2;
      uint8 v3 = r2 + v2;
      uint8 v6 = v3;
      if (r5)
        v3 += 6;
      OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
      oam[64].xpos = kSpr030_ThrowingDryBones_DryBonesTileXDisp[v3] + drt.x;
      oam[64].flags = sprites_tile_priority | kSpr030_ThrowingDryBones_DryBonesGfxProp[v6];
      uint8 v5 = r3 + v8;
      oam[64].ypos = kSpr030_ThrowingDryBones_DryBonesTileYDisp[(uint8)(r3 + v8)] + drt.y;
      oam[64].charnum = kSpr030_ThrowingDryBones_DryBonesTiles[v5];
      drt.idx += 4;
      v2 = v8 - 1;
    } while (v2 != r4);
    FinishOAMWrite(k, 2, 2);
  }
}

void Spr030_ThrowingDryBones_SpawnDryBonesBone(uint8 k) {  // 03c44e
  if (!(spr_yoffscreen_flag[k] | spr_xoffscreen_flag[k])) {
    uint8 v1 = 7;
    while (ext_spr_spriteid[v1]) {
      if ((--v1 & 0x80) != 0)
        return;
    }
    ext_spr_spriteid[v1] = 6;
    SetHiLo(&ext_spr_ypos_hi[v1], &ext_spr_ypos_lo[v1], GetSprYPos(k) - 16);
    SetHiLo(&ext_spr_xpos_hi[v1], &ext_spr_xpos_lo[v1], GetSprXPos(k));
    ext_spr_xspeed[v1] = (spr_table157c[k] & 1) ? -24 : 24;
  }
}

void Spr0C6_Spotlight_Draw(uint8 k) {  // 03c4a5
  uint8 v1 = spr_oamindex[k];
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam[64].xpos = 120;
  oam[64].ypos = 40;
  uint8 v3 = spr_table00c2[k];
  uint8 v4 = 8;
  if ((v3 & 1) != 0)
    v4 = (counter_global_frames >> 1) & 7;
  oam[64].charnum = kSpr0C6_Spotlight_Tiles[v4];
  oam[64].flags = kSpr0C6_Spotlight_Prop[v4];
  sprites_oamtile_size_buffer[(v1 >> 2) + 64] = 2;
}

void Spr0C6_Spotlight(uint8 k) {  // 03c4dc
  if (!spr_table1534[k]) {
    for (uint8 i = 9; (i & 0x80) == 0; --i) {
      if (i != spr_current_slotid && spr_current_status[i] == 8 && spr_spriteid[i] == 0xC6) {
        spr_current_status[k] = 0;
        return;
      }
    }
    ++spr_table1534[k];
  }
  Spr0C6_Spotlight_Draw(k);
  mirror_color_math_select_and_enable = -1;
  mirror_color_math_initial_settings = 32;
  mirror_object_and_color_window_settings = 32;
  mirror_hdmaenable = 0x80;
  uint8 v2 = spr_table00c2[k] & 1;
  palettes_background_color = PAIR16(kSpr0C6_Spotlight_DATA_03C4DA[v2], kSpr0C6_Spotlight_DATA_03C4D8[v2]);
  if (!flag_sprites_locked) {
    if (!flag_skip_spotlight_init) {
      sprc6_spotlight_left_bottom_x = 0;
      sprc6_spotlight_right_bottom_x = -112;
      sprc6_spotlight_left_top_x = 120;
      sprc6_spotlight_right_top_x = -121;
      unusedram_7e1486[0] = 1;
      sprc6_spotlight_dir = 0;
      ++flag_skip_spotlight_init;
    }
    sprc6_spotlight_left_bottom_x += kSpr0C6_Spotlight_DATA_03C48F[sprc6_spotlight_dir];
    sprc6_spotlight_right_bottom_x += kSpr0C6_Spotlight_DATA_03C48F[sprc6_spotlight_dir];
    if (sprc6_spotlight_right_bottom_x == kSpr0C6_Spotlight_DATA_03C491[sprc6_spotlight_dir])
      sprc6_spotlight_dir = (sprc6_spotlight_dir + 1) & 1;
    if ((counter_global_frames & 3) == 0) {
      uint8 v3 = 0;
      sprc6_spotlight_left_scanline_x = sprc6_spotlight_left_top_x;
      uint8 v4 = sprc6_spotlight_left_top_x - sprc6_spotlight_left_bottom_x;
      if (sprc6_spotlight_left_top_x < sprc6_spotlight_left_bottom_x) {
        v3 = 1;
        v4 = sprc6_spotlight_left_bottom_x - sprc6_spotlight_left_top_x;
      }
      sprc6_spotlight_left_side_w = v4;
      sprc6_spotlight_bottom_left_window_pos_relative_to_top = v3;
      sprc6_spotlight_shift_left = 0;
      uint8 v5 = 0;
      sprc6_spotlight_right_scanline_x = sprc6_spotlight_right_top_x;
      uint8 v6 = sprc6_spotlight_right_top_x - sprc6_spotlight_right_bottom_x;
      if (sprc6_spotlight_right_top_x < sprc6_spotlight_right_bottom_x) {
        v5 = 1;
        v6 = sprc6_spotlight_right_bottom_x - sprc6_spotlight_right_top_x;
      }
      sprc6_spotlight_width_right_side_w = v6;
      sprc6_spotlight_bottom_right_window_pos_relative_to_top = v5;
      sprc6_spotlight_shift_right = 0;
      uint8 r15 = spr_table00c2[k];
      for (uint16 j = 0; j != 448; j += 2) {
        if (j < 0x5F)
          goto LABEL_31;
        uint16 t = sprc6_spotlight_left_side_w + sprc6_spotlight_shift_left;
        sprc6_spotlight_shift_left += sprc6_spotlight_left_side_w;
        if (t >= 0xcf) {
          sprc6_spotlight_shift_left = t - 0xcf;
          ++sprc6_spotlight_left_scanline_x;
          if (!sprc6_spotlight_bottom_left_window_pos_relative_to_top)
            sprc6_spotlight_left_scanline_x -= 2;
        }
        uint16 v11 = sprc6_spotlight_width_right_side_w + sprc6_spotlight_shift_right;
        sprc6_spotlight_shift_right += sprc6_spotlight_width_right_side_w;
        if (v11 >= 0xcf) {
          sprc6_spotlight_shift_right = v11 - 0xcf;
          ++sprc6_spotlight_right_scanline_x;
          if (!sprc6_spotlight_bottom_right_window_pos_relative_to_top)
            sprc6_spotlight_right_scanline_x -= 2;
        }
        if (r15) {
          misc_hdmawindow_effect_table[j] = sprc6_spotlight_left_scanline_x;
          misc_hdmawindow_effect_table[j + 1] = sprc6_spotlight_right_scanline_x;
        } else LABEL_31: {
          misc_hdmawindow_effect_table[j] = 1;
          misc_hdmawindow_effect_table[j + 1] = 0;
        }
      }
    }
  }
}

void Spr07C_PrincessPeach_Fireworks(uint8 k) {  // 03c796
  uint8 v1 = spr_decrementing_table1564[k];
  if (v1) {
    if (v1 == 1) {
      ++misc_currently_active_boss_end_cutscene;
      timer_end_level = -1;
    }
  } else {
    palettes_background_color = PAIR16(kSpr07C_PrincessPeach_DATA_03C78E[spr_decrementing_table1564[9] & 3],
                                       kSpr07C_PrincessPeach_DATA_03C78A[spr_decrementing_table1564[9] & 3]);
    if (!spr7c_princess_peach_spawn_fireworks_timer) {
      if (spr_table1534[k] == 4) {
        spr_decrementing_table1564[k] = 112;
      } else {
        uint8 j = 1;
        while (spr_current_status[j]) {
          if ((--j & 0x80) != 0)
            return;
        }
        spr_current_status[j] = 8;
        spr_spriteid[j] = 122;
        spr_xpos_hi[j] = 0;
        SetSprYPos(j, mirror_current_layer1_ypos + 0xA8);
        InitializeNormalSpriteRAMTables(j);
        uint8 v4 = spr_table1534[k] & 3;
        spr_table1534[j] = v4;
        spr7c_princess_peach_spawn_fireworks_timer = kSpr07C_PrincessPeach_DATA_03C792[v4];
        spr_xpos_lo[j] = kSpr07C_PrincessPeach_InitialXLo[v4];
        ++spr_table1534[k];
      }
    }
  }
}

void Spr07A_Fireworks(uint8 k) {  // 03c816
  kSpr07A_Fireworks_FireworkPtrs[spr_table00c2[k]](k);
}

void Spr07A_Fireworks_InitialFire(uint8 k) {  // 03c828
  spr_yspeed[k] = kSpr07A_Fireworks_YSpeed[spr_table1534[k]];
  io_sound_ch3 = 37;
  spr_decrementing_table1564[k] = 16;
  ++spr_table00c2[k];
}

void Spr07A_Fireworks_ShootUp(uint8 k) {  // 03c845
  if (spr_decrementing_table1564[k] == 1) {
    uint8 v1 = spr_table1534[k];
    io_sound_ch1 = kSpr07A_Fireworks_FireworkSounds[v1];
    io_sound_ch3 = kSpr07A_Fireworks_FireworkSounds_WhistleCh3[v1];
  }
  UpdateNormalSpritePosition_Y(k);
  if ((++spr_xspeed[k] & 3) == 0)
    ++spr_yspeed[k];
  if (spr_yspeed[k] == 0xFC) {
    ++spr_table00c2[k];
    uint8 v2 = spr_table1534[k];
    spr_table151c[k] = kSpr07A_Fireworks_DATA_03C83D[v2];
    spr_decrementing_table15ac[k] = kSpr07A_Fireworks_DATA_03C841[v2];
    spr_decrementing_table1564[9] = 8;
  }
  Spr07A_Fireworks_03C96D(k);
}

void Spr07A_Fireworks_Explode(uint8 k) {  // 03c88d
  if (spr_decrementing_table15ac[k] == 1) {
    uint8 v1 = spr_table1534[k];
    io_sound_ch1 = kSpr07A_Fireworks_FireworkSounds_BangCh1[v1];
    io_sound_ch3 = kSpr07A_Fireworks_FireworkSounds_BangCh3[v1];
  }
  Spr07A_Fireworks_03C8B1(k);
  if (spr_table00c2[k] == 2)
    Spr07A_Fireworks_03C8B1(k);
  Spr07A_Fireworks_03C9E9(k);
}

void Spr07A_Fireworks_03C8B1(uint8 k) {  // 03c8b1
  uint16 v4 = spr_table151c[k] + spr_table1570[k];
  spr_table1570[k] = v4 < 256 ? v4 : 255;
  if (v4 >= kSpr07A_Fireworks_DATA_03C889[spr_table1534[k]]) {
    spr_table00c2[k]++;
    spr_yspeed[k] = 0;
    goto LABEL_8;
  }
  uint8 v5 = spr_table151c[k];
  if (v5 < 2 || (spr_table151c[k] = v5 - 1, v5 == 0))
    spr_table151c[k] = 1;
LABEL_8:
  spr_table1602[k] = kSpr07A_Fireworks_DATA_03C8F1[spr_table151c[k]];
}

void Spr07A_Fireworks_FadeAway(uint8 k) {  // 03c941
  if ((counter_global_frames & 7) == 0)
    ++spr_yspeed[k];
  UpdateNormalSpritePosition_Y(k);
  uint8 v1 = 7;
  uint8 v2 = spr_yspeed[k];
  if (v2 == 8)
    spr_current_status[k] = 0;
  if (v2 >= 3) {
    v1 = (v2 >= 5) ? 9 : 8;
  }
  spr_table1602[k] = v1;
  Spr07A_Fireworks_03C9E9(k);
}

void Spr07A_Fireworks_03C96D(uint8 k) {  // 03c96d
  if (((counter_global_frames ^ k) & 3) == 0) {
    GetDrawInfoRes drt;
    if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
      return;
    OamEnt *oam = get_OamEnt(oam_buf, 0);
    oam[64].xpos = drt.x;
    oam[65].xpos = drt.x;
    oam[64].ypos = drt.y;
    oam[64].charnum = kSpr07A_Fireworks_DATA_03C969[spr_table1534[k]] + ((uint8)((counter_global_frames >> 2) & 2) >> 1);
    uint8 r2 = (2 * counter_global_frames) & 0xE;
    oam[64].flags = r2 | (16 * counter_global_frames) & 0x40 | 0x31;
    sprites_oamtile_size_buffer[64] = 0;
  }
}

void Spr07A_Fireworks_03C9E9(uint8 k) {  // 03c9e9
  uint8 r5 = counter_global_frames ^ k;
  uint8 r6 = spr_table1570[k];
  uint8 r7 = spr_table1602[k];
  uint8 r8 = spr_xpos_lo[k];
  uint8 r9 = spr_ypos_lo[k] - mirror_current_layer1_ypos;
  uint8 r10 = spr_table1534[k];
  uint8 v1 = 63;
  uint8 v2 = 0;
  do {
    uint8 r4 = v1;
    uint8 v3 = kSpr07A_Fireworks_DATA_03C626[v1];
    if (r10 >= 3)
      v3 = kSpr07A_Fireworks_DATA_03C6CE[v1];
    uint8 r0 = v3 - 64;
    uint8 v30 = v2;
    uint8 v4 = kSpr07A_Fireworks_DATA_03C67A[v1];
    if (r10 >= 3)
      v4 = kSpr07A_Fireworks_DATA_03C722[v1];
    uint8 r1 = v4 - 80;
    uint8 v5 = r0;
    if ((r0 & 0x80) != 0)
      v5 = -r0;
    uint8 Reg = Mult8x8(v5, r6) >> 8;
    uint8 v7 = Reg;
    if ((r0 & 0x80) != 0)
      v7 = -Reg;
    uint8 r2 = v7;
    uint8 v8 = r1;
    if ((r1 & 0x80) != 0)
      v8 = -r1;
    uint8 v9 = Mult8x8(v8, r6) >> 8;
    uint8 v10 = v9;
    if ((r1 & 0x80) != 0)
      v10 = -v9;
    uint8 r3 = v10;
    uint8 v11 = 0;
    if (r7 >= 6)
      v11 = ((uint8)(r4 + r5) >> 2) & 7;
    uint8 v12 = kSpr07A_Fireworks_DATA_03C9E1[v11];
    uint8 v13 = v30;
    OamEnt *oam = get_OamEnt(oam_buf, v30);
    oam->xpos = r8 + r2 + v12;
    oam->ypos = r9 + r3;
    uint8 v31 = v1;
    oam->charnum = kSpr07A_Fireworks_DATA_03C9B9[(uint8)(r7 + 10 * (r5 & 3))];
    int8 v15 = r5 >> 1;
    if (r10 != 3)
      v15 ^= r4;
    oam->flags = v15 & 0xE | 0x31;
    sprites_oamtile_size_buffer[v13 >> 2] = 0;
    v2 = v13 + 4;
    --v1;
  } while ((int8)v1 >= 0);
  uint8 v16 = 83;
  do {
    uint8 r4 = v16;
    uint8 v17 = kSpr07A_Fireworks_DATA_03C626[v16];
    if (r10 >= 3)
      v17 = kSpr07A_Fireworks_DATA_03C6CE[v16];
    uint8 r0 = v17 - 64;
    uint8 v18 = kSpr07A_Fireworks_DATA_03C67A[v16];
    if (r10 >= 3)
      v18 = kSpr07A_Fireworks_DATA_03C722[v16];
    uint8 r1 = v18 - 80;
    uint8 v32 = v2;
    uint8 v19 = r0;
    if ((r0 & 0x80) != 0)
      v19 = -r0;
    uint8 v20 = Mult8x8(r6, v19) >> 8;
    uint8 v21 = v20;
    if ((r0 & 0x80) != 0)
      v21 = -v20;
    uint8 r2 = v21;
    uint8 v22 = r1;
    if ((r1 & 0x80) != 0)
      v22 = -r1;
    uint8 v23 = Mult8x8(v22, r6) >> 8;
    uint8 v24 = v23;
    if ((r1 & 0x80) != 0)
      v24 = -v23;
    uint8 r3 = v24;
    uint8 v25 = 0;
    if (r7 >= 6)
      v25 = ((uint8)(r4 + r5) >> 2) & 7;
    uint8 v26 = kSpr07A_Fireworks_DATA_03C9E1[v25];
    uint8 v27 = v32;
    OamEnt *v28 = get_OamEnt(oam_buf, v32);
    v28[64].xpos = r8 + r2 + v26;
    v28[64].ypos = r9 + r3;
    v28[64].charnum = kSpr07A_Fireworks_DATA_03C9B9[r7 + 10 * (r5 & 3)];
    int8 v29 = r5 >> 1;
    if (r10 != 3)
      v29 ^= r4;
    v28[64].flags = v29 & 0xE | 0x31;
    sprites_oamtile_size_buffer[(v27 >> 2) + 64] = 0;
    v2 = v27 + 4;
  } while (v16-- != 64);
}

void SpawnFootball(uint8 k) {  // 03cbb3
  uint8 j = FindFreeNormalSpriteSlot_HighPriority();
  if ((j & 0x80) == 0) {
    spr_spriteid[j] = 27;
    InitializeNormalSpriteRAMTables(j);
    spr_current_status[j] = 8;
    SetSprYPos(j, GetSprYPos(k));
    uint8 v2 = spr_table157c[k];
    SetSprXPos(j, GetSprXPos(k) + PAIR16(kSpawnFootball_xhi[v2], kSpawnFootball_xlo[v2]));
    spr_xspeed[j] = kSpawnFootball_InitialXSpeed[v2];
    spr_yspeed[j] = -32;
    spr_decrementing_table1540[j] = 16;
  }
}

void Spr029_KoopaKid_WendyLemmy(uint8 k) {  // 03cc09
  spr_property_bits1662[k] = 0;
  Spr029_KoopaKid_WendyLemmy_Sub(k);
}

void Spr029_KoopaKid_WendyLemmy_Sub(uint8 k) {  // 03cc14
  Spr029_KoopaKid_WendyLemmy_Draw(k);
  if (spr_current_status[k] == 8 && !flag_sprites_locked)
    kUnk_3cc29[spr_table151c[k]](k);
}

void Spr029_KoopaKid_WendyLemmy_State00_InPipe(uint8 k) {  // 03cc8a
  if (!spr_decrementing_table1540[k]) {
    if (!spr_table1570[k])
      spr_table160e[k] = GetRand() & 0xF;
    uint8 v1 = kSpr029_KoopaKid_WendyLemmy_SpawningPositionIndexes[spr_table1570[k] | spr_table160e[k]];
    spr_xpos_lo[k] = kSpr029_KoopaKid_WendyLemmy_SpawningXPos[v1];
    uint8 v2 = kSpr029_KoopaKid_WendyLemmy_LemmySpawningYPos[v1];
    if (spr_table00c2[k] >= 6)
      v2 = 80;
    spr_ypos_lo[k] = v2;
    uint8 v3 = 8;
    if (!spr_table1570[k]) {
      Spr029_KoopaKid_WendyLemmy_03CCE2(k);
      v3 = (GetRand() >> 2) & 7;
    }
    spr_table1528[k] = v3;
    spr_decrementing_table1540[k] = kSpr029_KoopaKid_WendyLemmy_DATA_03CC48[v3];
    ++spr_table151c[k];
    spr_table1602[k] = kSpr029_KoopaKid_WendyLemmy_DATA_03CC51[v3];
  }
}

void Spr029_KoopaKid_WendyLemmy_03CCE2(uint8 k) {  // 03cce2
  Spr029_KoopaKid_WendyLemmy_03CCE8(k, 1);
  Spr029_KoopaKid_WendyLemmy_03CCE8(k, 0);
}

void Spr029_KoopaKid_WendyLemmy_03CCE8(uint8 k, uint8 j) {  // 03cce8
  spr_current_status[j] = 8;
  spr_spriteid[j] = 41;
  InitializeNormalSpriteRAMTables(j);
  spr_table1570[j] = kSpr029_KoopaKid_WendyLemmy_DummyIDs[j];
  spr_table00c2[j] = spr_table00c2[k];
  spr_table160e[j] = spr_table160e[k];
  SetSprXPos(j, GetSprXPos(k));
  SetSprYPos(j, GetSprYPos(k));
}

void Spr029_KoopaKid_WendyLemmy_State01_Rising(uint8 k) {  // 03cd21
  if (!spr_decrementing_table1540[k]) {
    spr_decrementing_table1540[k] = 64;
    ++spr_table151c[k];
  }
  spr_yspeed[k] = -8;
  UpdateNormalSpritePosition_Y(k);
}

void Spr029_KoopaKid_WendyLemmy_State02_OutOfPipe(uint8 k) {  // 03cdc7
  Spr029_KoopaKid_WendyLemmy_CheckMarioStomp(k);
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1)
    sub_3CDDA(k, v1);
  else
    Spr029_KoopaKid_WendyLemmy_03CDCF(k);
}

void Spr029_KoopaKid_WendyLemmy_03CDCF(uint8 k) {  // 03cdcf
  spr_decrementing_table1540[k] = 36;
  spr_table151c[k] = 3;
}

void sub_3CDDA(uint8 k, uint8 a) {  // 03cdda
  spr_table1602[k] = kSpr029_KoopaKid_WendyLemmy_LemmyAndWendyAnimationFrames[(uint8)((a >> 2) | (16 * spr_table1528[k]))];
}

void Spr029_KoopaKid_WendyLemmy_State03_Descending(uint8 k) {  // 03cdef
  if (!spr_decrementing_table1540[k]) {
    if (spr_table1570[k]) {
      spr_current_status[k] = 0;
      return;
    }
    spr_table151c[k] = 0;
    spr_decrementing_table1540[k] = 48;
  }
  spr_yspeed[k] = 16;
  UpdateNormalSpritePosition_Y(k);
}

void Spr029_KoopaKid_WendyLemmy_State04_Hurt(uint8 k) {  // 03ce0e
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    if (spr_table1570[k]) {
      if (v1 == 16)
        io_sound_ch3 = 42;
      spr_table1602[k] = kSpr029_KoopaKid_WendyLemmy_DummyHurtFrames[v1 >> 3];
    } else {
      if (v1 == 36)
        io_sound_ch3 = 41;
      spr_table1602[k] = (counter_local_frames & 4) != 0;
    }
  } else if (++spr_table1534[k] == 3) {
    spr_table151c[k] = 5;
    spr_yspeed[k] = 0;
    io_sound_ch1 = 35;
  } else {
    Spr029_KoopaKid_WendyLemmy_03CDCF(k);
  }
}

void Spr029_KoopaKid_WendyLemmy_State05_Falling(uint8 k) {  // 03ce5a
  UpdateNormalSpritePosition_Y(k);
  if (sign8(spr_yspeed[k] - 64))
    spr_yspeed[k] += 3;
  uint8 v1 = spr_ypos_hi[k];
  if (v1) {
    v1 = spr_ypos_lo[k];
    if (v1 >= 0x85) {
      spr_table151c[k] = 6;
      spr_decrementing_table1540[k] = 0x80;
      io_sound_ch3 = 32;
      SpawnLavaSplash(k);
    }
  }
  if (v1 == 36)
    io_sound_ch3 = 41;
  spr_table1602[k] = (counter_local_frames & 4) != 0;
}

void Spr029_KoopaKid_WendyLemmy_State06_SinkingInLava(uint8 k) {  // 03ce89
  if (!spr_decrementing_table1540[k]) {
    spr_current_status[k] = 0;
    ++misc_currently_active_boss_end_cutscene;
    timer_end_level = -1;
    io_music_ch1 = 11;
  }
  spr_yspeed[k] = 4;
  UpdateNormalSpritePosition_Y(k);
}

void Spr029_KoopaKid_WendyLemmy_CheckMarioStomp(uint8 k) {  // 03cea7
  if (CheckPlayerToNormalSpriteCollision(k) & 1) {
    if (sign8(player_yspeed - 16)) {
      DamagePlayer_Hurt();
    } else {
      SpawnContactEffectFromAbove(k);
      GivePoints(k, 2);
      BoostMarioSpeed();
      io_sound_ch1 = 2;
      if (!spr_table1570[k]) {
        io_sound_ch3 = 40;
        if (spr_table1534[k] == 2)
          DespawnNonBossSprites();
      }
      spr_table151c[k] = 4;
      uint8 v1 = 80;
      if (spr_table1570[k])
        v1 = 31;
      spr_decrementing_table1540[k] = v1;
    }
  }
}

void Spr029_KoopaKid_WendyLemmy_Draw(uint8 k) {  // 03d484
  GetDrawInfoRes drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)).idx == 0xff)
    return;
  uint8 r2 = 6 * spr_table1602[k];
  if (spr_table00c2[k] == 6) {
    uint8 v5 = kSpr029_KoopaKid_WendyLemmy_NumberOfTilesToDrawForWendy[spr_table1602[k]];
    do {
      uint8 v9 = v5;
      uint8 v6 = r2 + v5;
      OamEnt *oam = get_OamEnt(oam_buf, drt.idx);
      oam[64].xpos = kSpr029_KoopaKid_WendyLemmy_WendyXDisp[v6] + drt.x;
      oam[64].ypos = kSpr029_KoopaKid_WendyLemmy_WendyYDisp[v6] + drt.y;
      oam[64].charnum = kSpr029_KoopaKid_WendyLemmy_WendyTiles[v6];
      oam[64].flags = kSpr029_KoopaKid_WendyLemmy_WendyProp[v6] | 0x10;
      sprites_oamtile_size_buffer[(drt.idx >> 2) + 64] = kSpr029_KoopaKid_WendyLemmy_WendyTileSize[v6];
      drt.idx += 4;
      v5 = v9 - 1;
    } while ((int8)v5 >= 0);
  } else {
    uint8 v2 = kSpr029_KoopaKid_WendyLemmy_NumberOfTilesToDrawForLemmy[spr_table1602[k]];
    do {
      uint8 v8 = v2;
      uint8 v3 = r2 + v2;
      OamEnt *v4 = get_OamEnt(oam_buf, drt.idx);
      v4[64].xpos = kSpr029_KoopaKid_WendyLemmy_LemmyXDisp[v3] + drt.x;
      v4[64].ypos = kSpr029_KoopaKid_WendyLemmy_LemmyYDisp[v3] + drt.y;
      v4[64].charnum = kSpr029_KoopaKid_WendyLemmy_LemmyTiles[v3];
      v4[64].flags = kSpr029_KoopaKid_WendyLemmy_LemmyProp[v3] | 0x10;
      sprites_oamtile_size_buffer[(drt.idx >> 2) + 64] = kSpr029_KoopaKid_WendyLemmy_LemmyTileSize[v3];
      drt.idx += 4;
      v2 = v8 - 1;
    } while ((int8)v2 >= 0);
  }
}

static const uint16 kSpr07C_PrincessPeach_MessageData[168] = { 0x2018, 0xea1, 0x2020, 0xe88, 0x2028, 0xeab, 0x2030, 0xe99, 0x2038, 0xea8, 0x2040, 0xebf, 0x2048, 0xeac, 0x2058, 0xe88, 0x2060, 0xe8b, 0x2068, 0xeaf, 0x2070, 0xe8c, 0x2078, 0xe9e, 0x2080, 0xead, 0x2088, 0xeae, 0x2090, 0xeab, 0x2098, 0xe8c, 0x20a8, 0xe99, 0x20b0, 0xeac, 0x20c0, 0xea8, 0x20c8, 0xeaf, 0x20d0, 0xe8c, 0x20d8, 0xeab, 0x20e0, 0xebd, 0x3018, 0xea1, 0x3020, 0xe88, 0x3028, 0xeab, 0x3030, 0xe99, 0x3038, 0xea8, 0x3040, 0xebe, 0x3048, 0xead, 0x3050, 0xe98, 0x3058, 0xe8c, 0x3068, 0xea0, 0x3070, 0xeab, 0x3078, 0xe99, 0x3080, 0xe9e, 0x3088, 0xe8a, 0x3090, 0xe8c, 0x3098, 0xeac, 0x30a0, 0xeac, 0x30a8, 0xebe, 0x30b0, 0xeb0, 0x30b8, 0xea8, 0x30c0, 0xeac, 0x30c8, 0xe98, 0x30d0, 0xe99, 0x30d8, 0xebe, 0x4018, 0xe88, 0x4020, 0xe9e, 0x4028, 0xe8b, 0x4038, 0xe98, 0x4040, 0xe99, 0x4048, 0xeac, 0x4058, 0xe8d, 0x4060, 0xeab, 0x4068, 0xe99, 0x4070, 0xe8c, 0x4078, 0xe9e, 0x4080, 0xe8b, 0x4088, 0xeac, 0x4098, 0xe88, 0x40a0, 0xeab, 0x40a8, 0xe8c, 0x40b8, 0xe8e, 0x40c0, 0xea8, 0x40c8, 0xe99, 0x40d0, 0xe9e, 0x40d8, 0xe8e, 0x5018, 0xead, 0x5020, 0xea8, 0x5030, 0xead, 0x5038, 0xe88, 0x5040, 0xe9b, 0x5048, 0xe8c, 0x5058, 0xe88, 0x5068, 0xeaf, 0x5070, 0xe88, 0x5078, 0xe8a, 0x5080, 0xe88, 0x5088, 0xead, 0x5090, 0xe99, 0x5098, 0xea8, 0x50a0, 0xe9e, 0x50a8, 0xebd,  };

void Spr07C_PrincessPeach_DisplayPeachRescueMessage() {  // 03d674
  if (spr7c_princess_peach_current_letter) {
    int16 v0 = spr7c_princess_peach_current_letter - 1;
    uint16 v1 = 0;
    do {
      int v2 = (uint16)(4 * v0) >> 1;
      OamEnt *oam = get_OamEnt(oam_buf, v1);
      *(uint16 *)&oam->xpos = kSpr07C_PrincessPeach_MessageData[v2];
      *(uint16 *)&oam->charnum = kSpr07C_PrincessPeach_MessageData[v2 + 1];
      sprites_oamtile_size_buffer[v1 >> 2] = 0;
      v1 += 4;
      --v0;
    } while (v0 >= 0);
  }
}

void Spr0A9_Reznor_BreakReznorBridge() {  // 03d70c
  if ((uint8)(spr_table151c[7] + spr_table151c[6] + spr_table151c[5] + spr_table151c[4]) >= 2 &&
      counter_number_of_broken_reznor_bridge_tiles < 0xC) {
    blocks_xpos = kSpr0A9_Reznor_DATA_03D700[counter_number_of_broken_reznor_bridge_tiles];
    blocks_ypos = 176;
    if (timer_reznor_bridge_breaking) {
      if (timer_reznor_bridge_breaking == 60) {
        Spr0A9_Reznor_03D77F();
        Spr0A9_Reznor_03D759();
        Spr0A9_Reznor_03D77F();
        ++counter_number_of_broken_reznor_bridge_tiles;
      }
    } else {
      Spr0A9_Reznor_03D766();
      timer_reznor_bridge_breaking = 64;
      io_sound_ch3 = 7;
    }
  }
}

void Spr0A9_Reznor_03D759() {  // 03d759
  blocks_xpos = 368 - blocks_xpos;
}

void Spr0A9_Reznor_03D766() {  // 03d766
  Spr0A9_Reznor_03D76C();
  Spr0A9_Reznor_03D759();
  Spr0A9_Reznor_03D76C();
}

void Spr0A9_Reznor_03D76C() {  // 03d76c
  if ((uint16)(blocks_xpos - mirror_current_layer1_xpos) < 0x100)
    SpawnSmokePuff();
}

void Spr0A9_Reznor_03D77F() {  // 03d77f
  uint8 r1 = (uint8)blocks_xpos >> 3;
  uint16 v0 = (uint8)(blocks_ypos | ((uint8)blocks_xpos >> 4));
  uint8 v1 = HIBYTE(blocks_xpos);
  if (HIBYTE(blocks_xpos)) {
    v0 += 432;
    v1 = 4;
  }
  uint8 r0 = v1;
  uint16 r0w = r1 << 8 | r0;
  blocks_map16_table_lo[v0] = 37;
  blocks_map16_table_hi[v0] = 0;
  uint16 v2 = stripe_image_upload;
  uint16 v3 = r0w + 0xc05a;
  int v4 = stripe_image_upload;
  *(uint16 *)&stripe_image_upload_data[stripe_image_upload] = r0w + 0xc05a;
  *(uint16 *)&stripe_image_upload_data[v4 + 6] = v3 | 0x2000;
  *(uint16 *)&stripe_image_upload_data[v2 + 2] = 576;
  *(uint16 *)&stripe_image_upload_data[v2 + 8] = 576;
  *(uint16 *)&stripe_image_upload_data[v2 + 4] = 0x38fc;
  *(uint16 *)&stripe_image_upload_data[v2 + 10] = 0x38fc;
  *(uint16 *)&stripe_image_upload_data[v2 + 12] = 255;
  stripe_image_upload = v2 + 12;
}

void GameMode12_PrepareLevel_UploadTiltingPlatformTilemap() {  // 03d958
  uint16 *dst = RtlGetVramAddr();
  for (int i = 0; i < 0x4000; i++)
    LOBYTE(dst[i]) = 0xff;
  if ((misc_nmito_use_flag & 0x40) == 0) {
    GameMode12_PrepareLevel_03D991(kGameMode12_PrepareLevel_IggyPlatformTiles, 0x810);
  }
}

void GameMode12_PrepareLevel_03D991(const uint8 *p5, uint16 r0w) {  // 03d991
  uint8 v0 = 0;
  do {
    uint8 r2 = v0, r3;
    uint8 v1 = 0;
    do {
      r3 = v1;
      uint16 *dst = RtlGetVramAddr() + r0w;
      v0 = r2;
      uint8 n = 16;
      do {
        uint8 v3 = p5[v0];
        sprites_cutscene_sprite_table_0AF6[v0] = v3;
        uint8 v4 = r3 | (4 * v3);
        LOBYTE(dst[0]) = *((uint8 *)kGameMode12_PrepareLevel_DATA_03D8EC + v4);
        LOBYTE(dst[1]) = *((uint8 *)&kGameMode12_PrepareLevel_DATA_03D8EC[1] + v4);
        dst += 2;
        ++v0;
        --n;
      } while (n);
      r0w += 0x80;
      v1 = r3 ^ 1;
    } while (r3 != 1);
  } while (v0);
}

static const uint16 kInitializeMode7TilemapsAndPalettes_Pals[5][6] = {
  {0x0, 0x1e0, 0x2e0, 0x3e0, 0xb7, 0x23f},
  {0x0, 0x6d08, 0x6dad, 0x7e31, 0xb7, 0x23f},
  {0x0, 0x1ff, 0x31f, 0x3ff, 0xb7, 0x23f},
  {0x0, 0x2940, 0x3de0, 0x5280, 0xb7, 0x23f},
  {0x2e32, 0x4a0d, 0x1088, 0x214a, 0x296d, 0x3dcf},
};

void InitializeMode7TilemapsAndPalettes(uint8 k) {  // 03dd7d
  misc_currently_active_boss = spr_table00c2[k];
  if (misc_currently_active_boss == 4) {
    InitializeMode7TilemapsAndPalettes_BufferReznorWallTilemap();
    LOBYTE(mirror_m7_center_ypos) = 72;
    misc_m7_angle = 0x1414;
  }
  misc_screens_in_lvl = -1;
  camera_last_screen_horiz = 0;
  uint8 v1 = kInitializeMode7TilemapsAndPalettes_GFXFile[misc_currently_active_boss];
  const uint8 *p0 = (const uint8 *)kInitializeMode7TilemapsAndPalettes_Pals[misc_currently_active_boss];
  for (uint8 i = 11; (i & 0x80) == 0; --i)
    *((uint8 *)&palettes_palette_mirror[2] + i) = p0[i];
  uint16 *dst = RtlGetVramAddr();
  if (v1) {
    const uint8 *pp = LmHook_GraphicsDecompress(v1);
    uint8 r3 = 0x80;
    do {
      pp = InitializeMode7TilemapsAndPalettes_BufferTilemap(&dst, pp);
      --r3;
    } while (r3);
  }
  for (int8 j = 95; j >= 0; --j)
    misc_mode7_boss_tilemap[(uint8)j] = -1;
}

const uint8 *InitializeMode7TilemapsAndPalettes_BufferTilemap(uint16 **dstp, const uint8 *p0) {  // 03dde5
  uint16 *dst = *dstp;
  uint8 v3;
  uint8 v8;
  uint8 v9;

  uint8 v1 = 0;
  uint8 v2 = 0;
  uint8 n = 8;
  do {
    uint8 v12 = InitializeMode7TilemapsAndPalettes_03DE39(v1, v2, p0);
    InitializeMode7TilemapsAndPalettes_03DE3C(v1, (v12 >> 1) + 15, p0);
    int8 v4 = 8;
    do {
      uint16 v7 = v1;
      uint16 v0;
      uint8 v5 = graphics_mode7_tile_buffer[v1];
      bool v6 = __CFSHL__(v5, 1);
      v3 = 2 * v5;
      v7 = 1;
      v0 = 0;
      if (v6)
        v0 = v7;
      v6 = __CFSHL__(v3, 1);
      v3 = 2 * v3;
      v8 = v3 + v0;
      v7 = 1;
      v0 = 0;
      if (v6)
        v0 = v7;
      v6 = __CFSHL__(v8, 1);
      v8 = 2 * v8;
      v9 = v8 + v0;
      v7 = 1;
      v0 = 0;
      if (v6)
        v0 = v7;
      v9 = 2 * v9;
      v3 = v9 + v0;
      v3 = v3 & 7;
      graphics_mode7_tile_buffer[v1] = v3;
      HIBYTE(*dst++) = v3;
      ++v1;
      --v4;
    } while (v4);
    v2 = v12;
    --n;
  } while (n);
  for (uint8 i = 7; (uint8)i < 0x40; i += 8) {
    uint8 v11 = i;
    n = 8;
    do {
      HIBYTE(*dst++) = graphics_mode7_tile_buffer[v11--];
      --n;
    } while (n);
  }
  p0 += 24;
  *dstp = dst;
  return p0;
}

uint8 InitializeMode7TilemapsAndPalettes_03DE39(uint8 k, uint8 j, const uint8 *p0) {  // 03de39
  uint8 v2 = InitializeMode7TilemapsAndPalettes_03DE3C(k, j, p0);
  return InitializeMode7TilemapsAndPalettes_03DE3C(k, v2, p0);
}

uint8 InitializeMode7TilemapsAndPalettes_03DE3C(uint8 k, uint8 j, const uint8 *p0) {  // 03de3c
  uint8 v2 = p0[j];
  int8 v3 = 8;
  do {
    bool v4 = __CFSHL__(v2, 1);
    v2 *= 2;
    int8 v5 = 0;
    if (v4)
      v5 = 0x80;
    graphics_mode7_tile_buffer[k] = (graphics_mode7_tile_buffer[k] >> 1) + v5;
    ++k;
    --v3;
  } while (v3);
  return j + 1;
}

void InitializeMode7TilemapsAndPalettes_BufferReznorWallTilemap() {  // 03de8e
  uint16 r0w = 0xa1c;
  uint8 v0 = 0;
  do {
    r0w += 128;
    uint16 *dst = RtlGetVramAddr() + r0w;
    int8 v1 = 8;
    do {
      LOBYTE(dst[0]) = kInitializeMode7TilemapsAndPalettes_DATA_03DE4E[v0++];
      dst++;
      --v1;
    } while (v1);
  } while (v0 < 0x40);
}

void UpdateMode7SpriteAnimations(uint8 k_in) {  // 03dedf
  uint16 k = k_in;

  UpdateMode7SpriteAnimations_03DFAE(0, GetSprXPos(k));
  UpdateMode7SpriteAnimations_03DFAE(2, GetSprYPos(k));
  uint16 r6 = 0;
  uint16 v1 = 3;
  uint16 v2 = *(uint16 *)&misc_nmito_use_flag >> 1;
  if (misc_nmito_use_flag & 1) {
    int v3 = (uint16)(2 * (spra0_bowser_propeller_anim_frame_counter & 3)) >> 1;
    *(uint16 *)&misc_mode7_boss_tilemap[1] = kUpdateMode7SpriteAnimations_DATA_03DEBF[v3];
    *(uint16 *)&misc_mode7_boss_tilemap[3] = kUpdateMode7SpriteAnimations_DATA_03DEC7[v3];
    *(uint16 *)&misc_mode7_boss_tilemap[5] = kUpdateMode7SpriteAnimations_DATA_03DECF[v3];
    r6 = 8;
    int16 v4 = 896;
    if ((misc_mode7_tilemap_index & 0x7F) >= 0x2C)
      v4 = 904;
    v2 = v4;
    k = 10;
    v1 = 7;
  }
  uint16 r0w = v1;
  if (!(misc_nmito_use_flag & 1)) {
LABEL_6:
    v2 = 16 * (misc_mode7_tilemap_index & 0x7F);
    k = 3;
  }
  uint16 r2w;
  do {
    r2w = k;
    uint16 v8 = v2;
    if (*(int16 *)&blocks_screen_to_place_next_object < 0)
      v2 += r0w;
    uint16 v5 = v2;
    uint16 v6 = r6;
    uint8 r4 = r0w;
    do {
      uint8 v7 = kInitializeMode7TilemapsAndPalettes_TilemapData[v5++];
      if ((misc_mode7_tilemap_index & 0x80) != 0) {
        v7 ^= 1;
        v5 -= 2;
      }
      misc_mode7_boss_tilemap[v6++] = v7;
      --r4;
    } while ((r4 & 0x80) == 0);
    r6 = v6;
    v2 = r0w + v8 + 1;
    if (r2w == 4)
      goto LABEL_6;
    if (r2w == 8)
      v2 = 864;
    if (r2w == 10)
      v2 = kUpdateMode7SpriteAnimations_DATA_03DED7[(uint16)(2 * (spra0_bowser_clown_car_face_anim_frame & 3)) >> 1];
    k = r2w - 1;
  } while ((int16)(r2w - 1) >= 0);
}

void UpdateMode7SpriteAnimations_03DFAE(uint8 j, uint16 a) {  // 03dfae
  *(uint16 *)((int8 *)&mirror_m7_xpos + j) = *(uint16 *)((int8 *)&mirror_current_layer1_xpos + j) + kUpdateMode7SpriteAnimations_DATA_03DEBB[j >> 1] - a;
}

void Spr0A0_ActivateBowserBattle_UpdatePaletteAndLightningAnimation() {  // 03dfcc
  unsigned int v1;
  uint16 v4;

  uint8 v0 = palettes_dynamic_palette_upload_index;
  v1 = palettes_dynamic_palette_upload_index;
  *(&palettes_dynamic_palette_bytes_to_upload + palettes_dynamic_palette_upload_index) = 16;
  *(&palettes_dynamic_palette_cgramaddress + v1) = 0;
  palettes_dynamic_palette_colors[v0] = 0;
  palettes_dynamic_palette_colors[v0 + 1] = 0;
  uint8 v2 = v0;
  uint8 v3 = palettes_lightning_flash_color_index;
  if (palettes_lightning_flash_color_index)
    goto LABEL_7;
  if (spra0_bowser_end_of_battle_flag) {
    v4 = palettes_background_color;
LABEL_10:
    *(uint16 *)&palettes_dynamic_palette_colors[v2] = v4;
    goto LABEL_11;
  }
  if (counter_local_frames & 1) {
    if (!--timer_wait_before_next_lightning_flash) {
      uint8 v5 = kOverworldLightningAndRandomCloudSpawning[counter_local_frames >> 1] & 7;
      timer_wait_before_next_lightning_flash = kOverworldLightningAndRandomCloudSpawning_DATA_04F6F8[v5];
      palettes_lightning_flash_color_index = kOverworldLightningAndRandomCloudSpawning_DATA_04F700[v5];
      v3 = palettes_lightning_flash_color_index;
      timer_lightning_frame_duration = 8;
      io_sound_ch3 = 24;
LABEL_7:
      if ((--timer_lightning_frame_duration & 0x80) != 0) {
        --palettes_lightning_flash_color_index;
        timer_lightning_frame_duration = 4;
      }
      v4 = kGlobalPalettes_OW_Sprites[0x31 + v3];
      goto LABEL_10;
    }
  }
LABEL_11:;
  uint8 v6 = kSpr0A0_ActivateBowserBattle_BowserPaletteTableIndex[spra0_bowser_palette_index];
  uint8 r0 = 14;
  do {
    palettes_dynamic_palette_colors[v2++ + 2] = *((uint8 *)kGlobalPalettes_Bowser + v6++);
    --r0;
  } while (r0);
  palettes_dynamic_palette_colors[v2 + 2] = 0;
  palettes_dynamic_palette_upload_index = v2 + 4;
}
