#ifndef _CONFIG_H_
#define _CONFIG_H_

#define CLEANDESTROY       // -25 octets si commenté   // destroy stuff (windows, glContext, ...)
#ifdef DEBUG
#define XRES 800
#define YRES 600
#else
#define XRES 1280
#define YRES 1024
#endif


//#define DESESPERATE   // -39 octets

//#define SOUND_DISABLED // -504 octets

/*
If USE_SOUND_THREAD is defined, 4klang plays music in realtime.
Otherwise music is prerendered and opening the intro takes longer.
*/
//#define USE_SOUND_THREAD

#endif