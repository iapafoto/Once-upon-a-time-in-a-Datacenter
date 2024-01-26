
#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#define WIN32_EXTRA_LEAN
#include <windows.h>
#include <GL/gl.h>
#include "glext.h"


extern void* myglfunc[];

#define oglCreateShaderProgramv         ((PFNGLCREATESHADERPROGRAMVPROC)myglfunc[0])
#define oglGenProgramPipelines          ((PFNGLGENPROGRAMPIPELINESPROC)myglfunc[1])
#define oglBindProgramPipeline          ((PFNGLBINDPROGRAMPIPELINEPROC)myglfunc[2])
#define oglUseProgramStages             ((PFNGLUSEPROGRAMSTAGESPROC)myglfunc[3])
#define oglProgramUniform1f            ((PFNGLPROGRAMUNIFORM1FPROC)myglfunc[4])


#ifdef DEBUG
#define oglGetProgramiv          ((PFNGLGETPROGRAMIVPROC)myglfunc[5])
#define oglGetProgramInfoLog     ((PFNGLGETPROGRAMINFOLOGPROC)myglfunc[6])
#endif



int   f2i(float x); // use this to convert float to int, or use /QIfist as additional compiler parameters
//float mfloorf(float x);
float mexpf(float x);

//float mpowf(float x, float y);
//float mfmodf(float x, float y);
//float m2xf(float x);


#endif
