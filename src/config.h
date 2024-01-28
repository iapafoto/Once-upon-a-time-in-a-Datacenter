#ifndef _CONFIG_H_
#define _CONFIG_H_


#ifdef DEBUG
#define XRES 1280// 800
#define YRES 720 //600
#else
#define XRES 1920
#define YRES 1080
//#define XRES 1920
//#define YRES 1080
#endif


#define CLEANDESTROY       // -25 octets si commenté   // destroy stuff (windows, glContext, ...)
#define DESESPERATE   // -39 octets



#endif