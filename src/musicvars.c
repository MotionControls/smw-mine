#include "musicvars.h"

/*  MF_LoadMusic(mus);
    Loads a new song from the specified mus struct.
*/
void MF_LoadMusic(const char* path,double start, double end, double loop, int doLoop){
    printf("Loading track: \"%s\"\n", path);
    gMusic_Main = Mix_LoadMUS(path);
    if(gMusic_Main == NULL)
        printf("Error loading track: %s\n", Mix_GetError());
    Mix_PlayMusic(gMusic_Main, doLoop);

    musicStart = start;
    musicEnd = end;
    musicLoop = loop;
    musicDoLoop = doLoop;
}

/*  MF_StepMusic();
    Processes the currently playing music.
*/
void MF_StepMusic(){
    // Get music position.
    if(Mix_PlayingMusic())
        musicPos = Mix_GetMusicPosition(gMusic_Main) * 1000;
        
    // Loop song.
    if(musicDoLoop && musicPos >= musicEnd){
        //printf("Looping current track.\n");
        Mix_SetMusicPosition(musicLoop / 1000);
    }
}