#ifndef _CONFIG_H_
#define _CONFIG_H_


#ifdef DEBUG
#define XRES 1280// 800
#define YRES 720 //600
#else
//#define XRES 1280
//#define YRES 720
#define XRES 1920
#define YRES 1080
#endif


#define CLEANDESTROY       // -25 octets si comment�   // destroy stuff (windows, glContext, ...)

#define DESESPERATE   // -39 octets

//#define SOUND_DISABLED // -504 octets

/*
If USE_SOUND_THREAD is defined, 4klang plays music in realtime.
Otherwise music is prerendered and opening the intro takes longer.
*/
//#define USE_SOUND_THREAD

#endif