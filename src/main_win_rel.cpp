#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#include <windows.h>
#include "config.h"
#ifndef SOUND_DISABLED
  #include <mmsystem.h>
    #include "mzk.h"
#endif

//#include "main.h"
#include <GL/gl.h>
//#include <windows.h>
#include "system.h"
#include "fragment_shader.inl"
//#include "fp.h"


#ifndef SOUND_DISABLED
static const int wavHeader[11] = {
    0x46464952,  MZK_NUMSAMPLES * 2 + 36,  0x45564157,  0x20746D66,  16,
    WAVE_FORMAT_PCM | (MZK_NUMCHANNELS << 16),  MZK_RATE, MZK_RATE * MZK_NUMCHANNELS * sizeof(short),
    (MZK_NUMCHANNELS * sizeof(short)) | ((8 * sizeof(short)) << 16),  0x61746164,  MZK_NUMSAMPLES * sizeof(short)
};
#endif

static const PIXELFORMATDESCRIPTOR pfd = {
    sizeof(PIXELFORMATDESCRIPTOR), 1, PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, PFD_TYPE_RGBA,
    32, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 32, 0, 0, PFD_MAIN_PLANE, 0, 0, 0, 0 };

static DEVMODE screenSettings = { {0},
    #if _MSC_VER < 1400
    0,0,148,0,0x001c0000,{0},0,0,0,0,0,0,0,0,0,{0},0,32,XRES,YRES,0,0,      // Visual C++ 6.0
    #else
    0,0,156,0,0x001c0000,{0},0,0,0,0,0,{0},0,32,XRES,YRES,{0}, 0,           // Visuatl Studio 2005
    #endif
    #if(WINVER >= 0x0400)
    0,0,0,0,0,0,
    #if (WINVER >= 0x0500) || (_WIN32_WINNT >= 0x0400)
    0,0
    #endif
    #endif
};

// si vraiment desesperé on doit pouvoir oublier les fct pipeline

static char* glFuncNames[] = {
    "glCreateShaderProgramv",
    "glGenProgramPipelines",
    "glBindProgramPipeline",
    "glUseProgramStages",
    "glProgramUniform1f" };


#ifdef __cplusplus
extern "C"
{
#endif
    int  _fltused = 0;
#ifdef __cplusplus
}
#endif


//----------------------------------------------------------------------------
#ifndef SOUND_DISABLED
static short myMuzik[MZK_NUMSAMPLESC + 22]; // initialise a l'exterieur car entrypoint a une limite de taille de pile
#endif

void entrypoint(void)
{
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);

    
 
    // 
    // create window
//#ifdef DESESPERATE
// 4054 mais pas de controle de la definition à l'ecran !
//    ShowCursor(0); // 5 octet
//    HDC hDC = GetDC(CreateWindow((LPCSTR)0xC018, 0, WS_POPUP | WS_VISIBLE | WS_MAXIMIZE, 0, 0, 0, 0, 0, 0, 0, 0));
//  SetPixelFormat(hDC, ChoosePixelFormat(hDC, &pfd), &pfd);

// 4081
    // 4088 avec show cursor
    ChangeDisplaySettings(&screenSettings, CDS_FULLSCREEN); // 20 octets a peu pres
    ShowCursor(0); // 5 octets
    HDC hDC = GetDC(CreateWindow((LPCSTR)0xC018, 0, WS_POPUP | WS_VISIBLE, 0, 0, XRES, YRES, 0, 0, 0, 0));
    SetPixelFormat(hDC, ChoosePixelFormat(hDC, &pfd), &pfd);
//#else

// 4100
 //   // full screen
 //   if (ChangeDisplaySettings(&screenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL) return;
 //   ShowCursor(0); // 5 octet
 //   HWND hWnd = CreateWindow((LPCSTR)0xC018, 0, WS_POPUP | WS_VISIBLE, 0, 0, XRES, YRES, 0, 0, 0, 0);
 //   if (!hWnd) return;
 //   HDC hDC = GetDC(hWnd);
 //   if (SetPixelFormat(hDC, ChoosePixelFormat(hDC, &pfd), &pfd)) return;
//#endif

    // initalize opengl
    wglMakeCurrent(hDC, wglCreateContext(hDC));

    void* myglfunc[5];
    for (int i = 0; i < 5; i++) {
        myglfunc[i] = wglGetProcAddress(glFuncNames[i]);
        if (!myglfunc[i])
            return;
    }

    int fsid = oglCreateShaderProgramv(GL_FRAGMENT_SHADER, 1, &fsh);
    unsigned int pid;
    oglGenProgramPipelines(1, &pid);
    oglBindProgramPipeline(pid);
    oglUseProgramStages(pid, GL_FRAGMENT_SHADER_BIT, fsid);


    // init mzk
    // si besoin synchro : https://github.com/vsariola/adam/blob/main/intro/main.c
#ifndef SOUND_DISABLED
    mzk_init(myMuzik + 22);
    memcpy(myMuzik, wavHeader, 44);
    sndPlaySound((const char*)&myMuzik, SND_ASYNC | SND_MEMORY);

#endif

    // play intro
    long t,to = timeGetTime();
    do {
        t = timeGetTime() - to;

        oglProgramUniform1f(fsid, 0, ((float)t) / 1000.f);
        glRects(-1, -1, 1, 1); // Deprecated. Still seems to work though.
        wglSwapLayerBuffers(hDC, WGL_SWAP_MAIN_PLANE); // SwapBuffers(hDC); => +2 octets

    } while (!GetAsyncKeyState(VK_ESCAPE) && t<140000);

#ifndef DESESPERATE
    #ifdef CLEANDESTROY
        #ifndef SOUND_DISABLED
            sndPlaySound(0, 0);
        #endif
        ChangeDisplaySettings(0, 0);
        ShowCursor(1);
    #endif
#endif

    ExitProcess(0);
}
