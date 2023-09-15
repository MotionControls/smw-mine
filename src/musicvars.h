#pragma once

#include <SDL_mixer.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Music Path
/*  MUS
    Struct to contain music information.
path            ;   Path to mp3.
pos             ;   Where the track is in ms.
start,end,loop  ;   When the track start, ends, and loops in ms.
doLoop          ;   Whether or not the track should loop.
*/
typedef struct{
    const char* path;
    double pos,start,end,loop;
    int doLoop;
}MUS;

/* Music Paths */
// Overworld
MUS* gMusic_World1;
MUS* gMusic_World2_4_6;
MUS* gMusic_World3;
MUS* gMusic_World7;
MUS* gMusic_SpecialWorld;
MUS* gMusic_ForestOfIllusion;
MUS* gMusic_StarRoad;

// Levels

// Misc.

/* Init Music + SFX */
int musicPos;
MUS* gMusic_Playing;
Mix_Music* gMusic_Main;
Mix_Chunk* gSound_;
Mix_Chunk* gSound_HitHead;
Mix_Chunk* gSound_SpinJumpBounce; // ex. Bounce off of spiny.
Mix_Chunk* gSound_Kick;
Mix_Chunk* gSound_HurtOrPipe;
Mix_Chunk* gSound_Checkpoint;
Mix_Chunk* gSound_YoshiGulp;
Mix_Chunk* gSound_DryBonesBreak;
Mix_Chunk* gSound_SpinJumpKill;
Mix_Chunk* gSound_Fly;  // When the cape goes bewou.
Mix_Chunk* gSound_Powerup;
Mix_Chunk* gSound_SwitchBlock;
Mix_Chunk* gSound_ItemTransform;  // When an item is carried past the goal post.
Mix_Chunk* gSound_Cape;
Mix_Chunk* gSound_Swim;
Mix_Chunk* gSound_HurtWhileFlying;
Mix_Chunk* gSound_Magic;  // When Magikoopa does their thing.
Mix_Chunk* gSound_Pause;
Mix_Chunk* gSound_Unpause;
Mix_Chunk* gSound_EnemyStomp1;
Mix_Chunk* gSound_EnemyStomp2;
Mix_Chunk* gSound_EnemyStomp3;
Mix_Chunk* gSound_EnemyStomp4;
Mix_Chunk* gSound_EnemyStomp5;
Mix_Chunk* gSound_EnemyStomp6;
Mix_Chunk* gSound_EnemyStomp7;
//Mix_Chunk* gSound_GrinderLouder1;
//Mix_Chunk* gSound_GrinderLouder2;
Mix_Chunk* gSound_YoshiCoin;
Mix_Chunk* gSound_RunningOutOfTime;
Mix_Chunk* gSound_Balloon;
Mix_Chunk* gSound_KoopalingDefeat;
Mix_Chunk* gSound_YoshiSpit;
Mix_Chunk* gSound_ValleyOfBowserAppears; // Assuming this means the skull in the water.
Mix_Chunk* gSound_LemmyWendyFall;
Mix_Chunk* gSound_BlarggRoar;
Mix_Chunk* gSound_FireworkWhistle;
Mix_Chunk* gSound_FireworkWhistleLoud;
Mix_Chunk* gSound_FireworkBang;
Mix_Chunk* gSound_FireworkBangLoud;
Mix_Chunk* gSound_PeachEscapingClownCar;  // When she pops out and gives you a mushroom.
Mix_Chunk* gSound_Jump;
Mix_Chunk* gSound_Grinder;
Mix_Chunk* gSound_Dead;
Mix_Chunk* gSound_GameOver;
Mix_Chunk* gSound_BossDead;
Mix_Chunk* gSound_LevelCleared;
Mix_Chunk* gSound_Keyhole;
Mix_Chunk* gSound_ZoomIn;
Mix_Chunk* gSound_Welcome;  // ?
Mix_Chunk* gSound_BonusCleared;
Mix_Chunk* gSound_RescuedEgg;
Mix_Chunk* gSound_BowserZoomOut;
Mix_Chunk* gSound_BowserZoomIn;
Mix_Chunk* gSound_BowserDied;
Mix_Chunk* gSound_PrincessKiss;
Mix_Chunk* gSound_BowserInterlude;
Mix_Chunk* gSound_Coin;
Mix_Chunk* gSound_QuestionBlock;
Mix_Chunk* gSound_QuestionBlockWithVine;
Mix_Chunk* gSound_SpinJump;
Mix_Chunk* gSound_1UP;
Mix_Chunk* gSound_Fireball;
Mix_Chunk* gSound_BreakBlock;
Mix_Chunk* gSound_Spring;
Mix_Chunk* gSound_BulletBill;
Mix_Chunk* gSound_EggHatch;
Mix_Chunk* gSound_InReserveBox;
Mix_Chunk* gSound_OutReserveBox;
Mix_Chunk* gSound_Scroll; // When L or R is pressed.
Mix_Chunk* gSound_Door;
Mix_Chunk* gSound_DrumRollStart;  // ?
Mix_Chunk* gSound_DrumRollEnd;  // ?
Mix_Chunk* gSound_YoshiHit;
Mix_Chunk* gSound_OverworldTileRevealed;
Mix_Chunk* gSound_OverworldCastleDestroyed;
Mix_Chunk* gSound_YoshiFireball;
Mix_Chunk* gSound_Thunder;
Mix_Chunk* gSound_ChuckClap;
Mix_Chunk* gSound_Bomb;
Mix_Chunk* gSound_BombFuse;
Mix_Chunk* gSound_OverworldBlockSpill;  // When the blocks spill out of the switch palace
Mix_Chunk* gSound_ChuckWhistle;
Mix_Chunk* gSound_YoshiMount;
Mix_Chunk* gSound_LemmyWendyLava;
Mix_Chunk* gSound_YoshiTongue;
Mix_Chunk* gSound_SavePrompt;
Mix_Chunk* gSound_OverworldMoveToTile;  // When Mario moves on top of a tile.
Mix_Chunk* gSound_PswitchRunningOut;
Mix_Chunk* gSound_YoshiKillEnemy; // Yoshi stomps on an enemy.
Mix_Chunk* gSound_Swooper;  // The lava monsters?
Mix_Chunk* gSound_Podoboo;  // The fireball things
Mix_Chunk* gSound_EnemyStunned;
Mix_Chunk* gSound_BonusCorrect;
Mix_Chunk* gSound_BonusWrong;

/* Funcs */
MUS* MF_InitMusic(const char*,double,double,double,int);
//void MF_LoadMusic(const char*,double,double,double,int);
void MF_LoadMusic(MUS*);
void MF_StepMusic();