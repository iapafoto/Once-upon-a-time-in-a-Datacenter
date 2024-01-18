#ifndef _CONFIG_H_
#define _CONFIG_H_

#define CLEANDESTROY       // -25 octets si commenté   // destroy stuff (windows, glContext, ...)
#ifdef DEBUG
#define XRES 1280// 800
#define YRES 1024 //600
#else
#define XRES 1280
#define YRES 720
#endif

//  Alignement des membres de la structures 1 octet (3964) => default

//#define DESESPERATE   // -39 octets

//#define SOUND_DISABLED // -504 octets

/*
If USE_SOUND_THREAD is defined, 4klang plays music in realtime.
Otherwise music is prerendered and opening the intro takes longer.
*/
//#define USE_SOUND_THREAD

#endif