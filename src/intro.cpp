#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

//#define DESESPERATE

#include <windows.h>
#include <GL/gl.h>
#include <windows.h>
#include <GL/gl.h>
#include "config.h"
#include "system.h"
// #include "vertex_shader.inl"
#include "fragment_shader.inl"
#include "fp.h"



static int   fsid;

int intro_init(void)
{
#ifdef DESESPERATE // 1k config but not sure sound is transmited
        ((PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram"))(
        ((PFNGLCREATESHADERPROGRAMVPROC)wglGetProcAddress("glCreateShaderProgramv"))(
            GL_FRAGMENT_SHADER, 1, &fsh));

#else

 //   int vsid = oglCreateShaderProgramv(GL_VERTEX_SHADER, 1, &vsh);
    fsid = oglCreateShaderProgramv(GL_FRAGMENT_SHADER, 1, &fsh);
    unsigned int pid;
    oglGenProgramPipelines(1, &pid);
    oglBindProgramPipeline(pid);
 //   oglUseProgramStages(pid, GL_VERTEX_SHADER_BIT, vsid);
    oglUseProgramStages(pid, GL_FRAGMENT_SHADER_BIT, fsid);

    #ifdef DEBUG
        int		result;
        char    info[1536];
      //  oglGetProgramiv(vsid, GL_LINK_STATUS, &result); 
      //  oglGetProgramInfoLog(vsid, 1024, NULL, (char*)info);  
      // if (!result) DebugBreak();
        oglGetProgramiv(fsid, GL_LINK_STATUS, &result); 
        oglGetProgramInfoLog(fsid, 1024, NULL, (char*)info); 
        if (!result) DebugBreak();
        oglGetProgramiv(pid, GL_LINK_STATUS, &result); 
        oglGetProgramInfoLog(pid, 1024, NULL, (char*)info); 
        if (!result) DebugBreak();
    #endif

#endif

    return 1;
}

void intro_do(long time) {
    oglProgramUniform1f(fsid, 0, ((float)time) / 1000.f);
	glRects(-1, -1, 1, 1); // Deprecated. Still seems to work though.
}