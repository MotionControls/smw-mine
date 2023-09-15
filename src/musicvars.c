#include "musicvars.h"

/*  MF_InitMusic(path,start,end,loop,doLoop);
    Inits a MUS struct.
Args explained in musicvars.h -> MUS.
*/
MUS* MF_InitMusic(const char* path, double start, double end, double loop, int doLoop){
    MUS* temp = malloc(sizeof(MUS));
    temp->pos = 0;
    temp->path = path;
    temp->start = start;
    temp->end = end;
    temp->loop = loop;
    temp->doLoop = doLoop;
    /*printf("New Values:\n\tpath: %s\n\tstart: %d\n\tend: %d\n\tloop: %d\n\tdoLoop: %i\n", temp->path, temp->start, temp->end, temp->loop, temp->doLoop);
    printf("Set Values:\n\tpath: %s\n\tstart: %d\n\tend: %d\n\tloop: %d\n\tdoLoop: %i\n", path, start, end, loop, doLoop);*/
    free(temp);
    return temp;
}

/*  MF_LoadMusic(mus);
    Loads a new song from the specified mus struct.
mus ;   Music file to load.
*/
void MF_LoadMusic(MUS* mus){
    printf("Loading track: \"%s\"\n", mus->path);
    gMusic_Main = Mix_LoadMUS(mus->path);
    if(gMusic_Main == NULL)
        printf("Error loading track: %s\n", Mix_GetError());
    Mix_PlayMusic(gMusic_Main, mus->doLoop);

    gMusic_Playing = mus;
}

/*  MF_StepMusic();
    Processes the currently playing music.
*/
void MF_StepMusic(){
    if(gMusic_Playing != NULL){
        // Get music position.
        if(Mix_PlayingMusic())
            gMusic_Playing->pos = Mix_GetMusicPosition(gMusic_Main) * 1000;
        
        //printf("Current muspos: %u / %u\n", gMusic_Playing->pos, gMusic_Playing->end);
        // Loop song.
        if(gMusic_Playing->doLoop && gMusic_Playing->pos >= gMusic_Playing->end){
            //printf("Looping current track.\n");
            Mix_SetMusicPosition(gMusic_Playing->loop / 1000);
        }
    }
}