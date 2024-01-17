#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN

#include <windows.h>
#ifndef SOUND_DISABLED
  #include <mmsystem.h>
    #include "mzk.h"
#endif
#include "intro.h"
#include "main.h"
#include "config.h"


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

#ifndef SOUND_DISABLED
static short myMuzik[MZK_NUMSAMPLESC + 22];
#endif

void* myglfunc[5];

//----------------------------------------------------------------------------

void entrypoint(void)
{
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);

    // full screen
    if (ChangeDisplaySettings(&screenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL) return;
   
    // create window
#ifdef DESESPERATE
    HDC hDC = GetDC(CreateWindow(".", 0, WS_POPUP | WS_VISIBLE | WS_MAXIMIZE, 0, 0, 0, 0, 0, 0, 0, 0));
    SetPixelFormat(hDC, ChoosePixelFormat(hDC, &pfd), &pfd);
#else
    ShowCursor(0);
    HWND hWnd = CreateWindow((LPCSTR)0xC018, 0, WS_POPUP | WS_VISIBLE, 0, 0, XRES, YRES, 0, 0, 0, 0);
    if (!hWnd) return;
    HDC hDC = GetDC(hWnd);
    if (!SetPixelFormat(hDC, ChoosePixelFormat(hDC, &pfd), &pfd)) return;
#endif

    // initalize opengl
    wglMakeCurrent(hDC, wglCreateContext(hDC));

    for (int i = 0; i < 5; i++) {
        myglfunc[i] = wglGetProcAddress(glFuncNames[i]);
        if (!myglfunc[i])
            return;
    }


    // init intro
    if (!intro_init()) return;

    // init mzk
#ifndef SOUND_DISABLED
    mzk_init(myMuzik + 22);
    memcpy(myMuzik, wavHeader, 44);
    sndPlaySound((const char*)&myMuzik, SND_ASYNC | SND_MEMORY);
#endif

  //  static WAVEHDR WaveHDR = {
  //  (LPSTR)sointu_buffer, SU_BUFFER_LENGTH * sizeof(SUsample), 0, 0, 0, 0, 0, 0
  //  };
  //  static MMTIME MMTime = { TIME_SAMPLES, 0 };

    // play intro
    long to = timeGetTime();
    do {
        // https://github.com/vsariola/adam/blob/main/intro/main.c
        //   waveOutGetPosition(hWaveOut, &MMTime, sizeof(MMTIME));
        //  ((PFNGLUNIFORM1FVPROC)wglGetProcAddress("glUniform1fv"))(0, 8, &syncBuf[((MMTime.u.sample + SYNC_DELAY) >> 8) * SU_NUMSYNCS]);

        intro_do(timeGetTime() - to);
        wglSwapLayerBuffers(hDC, WGL_SWAP_MAIN_PLANE); // SwapBuffers(hDC); => +2 octets

    } while (!GetAsyncKeyState(VK_ESCAPE));

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
