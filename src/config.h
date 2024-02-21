#ifndef _CONFIG_H_
#define _CONFIG_H_

#define RES 1 // 0:1280, 1:1920, 2:2560

#if RES==1
	#define XRES 1920
	#define YRES 1080
#elif RES==2
	#define XRES 2560
	#define YRES 1440
#else
	#define XRES 1280
	#define YRES 720
#endif

#define FULLSCREEN
#define CLEANDESTROY  // -25 octets si commenté   // destroy stuff (windows, glContext, ...)
#define WITH_AA


#endif