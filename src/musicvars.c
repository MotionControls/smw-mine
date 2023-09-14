#include "musicvars.h"

/*  MF_LoadMusic(path, start, end, loop, doLoop);
    Loads a new song with the specified variables.
path            ;   Path to mp3.
start,end,loop  ;   Music positions, explained in musicvars.h.
doLoop          ;   Whether or not the current track should loop when finished.
*/
void MF_LoadMusic(const char* path, double start, double end, double loop, int doLoop){
    printf("Loading track: %s\n", path);
    gMusic_Main = Mix_LoadMUS(path);
    if(gMusic_Main == NULL)
        printf("Error loading track: %s\n", Mix_GetError());
    Mix_PlayMusic(gMusic_Main, doLoop);

    startPos = start;
    endPos = end;
    loopPos = loop;
    loopCurMusic = doLoop;
}

/*  MF_StepMusic();
    Processes the currently playing music.
*/
void MF_StepMusic(){
    // Get music position.
    if(Mix_PlayingMusic())
        musicPos = Mix_GetMusicPosition(gMusic_Main) * 1000;
    
    // Loop song.
    if(loopCurMusic && musicPos >= endPos)
        Mix_SetMusicPosition(loopPos / 1000);
}