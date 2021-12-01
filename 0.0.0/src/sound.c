/*
  sound.c
  
  Super Tux - Screen Functions
  
  by Bill Kendrick
  bill@newbreedsoftware.com
  http://www.newbreedsoftware.com/supertux/
  
  April 22, 2000 - April 23, 2000
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <SDL.h>
#include <SDL_image.h>

#ifndef NOSOUND
#include <SDL_mixer.h>
#endif

#ifdef LINUX
#include <pwd.h>
#include <sys/types.h>
#include <ctype.h>
#endif

#include "defines.h"
#include "globals.h"
#include "sound.h"
#include "setup.h"


/* --- LOAD A SOUND --- */

Mix_Chunk * load_sound(char * file)
{
  Mix_Chunk * snd;
  
  snd = Mix_LoadWAV(file);
  
  if (snd == NULL)
    st_abort("Can't load", file);
  
  return(snd);
}


/* --- PLAY A SOUND --- */

void playsound(Mix_Chunk * snd)
{
  Mix_PlayChannel(-1, snd, 0);
}

