#define WIN32_LEAN_AND_MEAN
#define WIN32_EXTRA_LEAN
#define VC_LEANMEAN
#define VC_EXTRALEAN

#include <windows.h>
#include "config.h"
#include <GL/gl.h>
#include "glext.h"
#include "system.h"
#include "fragment_shader.inl"
#include <mmsystem.h>
#include <mmreg.h>
#include "mzk.h"


static short myMuzik[MZK_NUMSAMPLESC];
static HWAVEOUT	hWaveOut;
static WAVEHDR WaveHDR = { (LPSTR)myMuzik, MZK_NUMSAMPLESC * sizeof(float), 0,0,0,0,0,0 };
static MMTIME MMTime = { TIME_SAMPLES, 0 };
static WAVEFORMATEX WaveFMT = {
#ifdef FLOAT_32BIT	
    WAVE_FORMAT_IEEE_FLOAT,
#else
    WAVE_FORMAT_PCM,
#endif		
    MZK_NUMCHANNELS, // channels
    MZK_RATE, // samples per sec
    MZK_RATE * sizeof(short) * MZK_NUMCHANNELS, // bytes per sec
    sizeof(short) * MZK_NUMCHANNELS, // block alignment;
    sizeof(short) * 8, // bits per sample
    0 // extension not needed
};



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


#ifdef __cplusplus
extern "C"
{
#endif
    int  _fltused = 0; // avoid injection of code for float or double
#ifdef __cplusplus
}
#endif

//----------------------------------------------------------------------------
int fsid;
HDC hDC;

void render() { //4032
    ((PFNGLPROGRAMUNIFORM1FPROC)wglGetProcAddress("glProgramUniform1f"))(fsid, 0, (float)(MMTime.u.sample) / (float)MZK_RATE);
    glRects(-1, -1, 1, 1); // Deprecated. Still seems to work though.
    wglSwapLayerBuffers(hDC, WGL_SWAP_MAIN_PLANE); // SwapBuffers(hDC); => +2 octets
}

void entrypoint(void)
{
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_SYSTEM_AWARE);
    ChangeDisplaySettings(&screenSettings, CDS_FULLSCREEN); // 20 octets a peu pres
    ShowCursor(0); // 5 octets
    hDC = GetDC(CreateWindow((LPCSTR)0xC018, 0, WS_POPUP | WS_VISIBLE, 0, 0, XRES, YRES, 0, 0, 0, 0));
    SetPixelFormat(hDC, ChoosePixelFormat(hDC, &pfd), &pfd);

 //------------------
    // full screen
//    if (ChangeDisplaySettings(&screenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL) return;
//    ShowCursor(0); // 5 octet
//    HWND hWnd = CreateWindow((LPCSTR)0xC018, 0, WS_POPUP | WS_VISIBLE, 0, 0, XRES, YRES, 0, 0, 0, 0);
//    if (!hWnd) return;
//    HDC hDC = GetDC(hWnd);
//    if (SetPixelFormat(hDC, ChoosePixelFormat(hDC, &pfd), &pfd)) return;

    // initalize opengl
    wglMakeCurrent(hDC, wglCreateContext(hDC));

    fsid = ((PFNGLCREATESHADERPROGRAMVPROC)wglGetProcAddress("glCreateShaderProgramv"))(GL_FRAGMENT_SHADER, 1, &input);
    ((PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram"))(fsid);
    render(); // Display waiting picture during music init (t==0)

    // init mzk
    mzk_init(myMuzik);
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &WaveFMT, NULL, 0, CALLBACK_NULL);
    waveOutPrepareHeader(hWaveOut, &WaveHDR, sizeof(WaveHDR));
    waveOutWrite(hWaveOut, &WaveHDR, sizeof(WaveHDR));

    // play intro
    do {
        waveOutGetPosition(hWaveOut, &MMTime, sizeof(MMTIME));
        render();
        PeekMessage(0,0,0,0,PM_REMOVE); // increase compatibility 3 octets

    } while (!GetAsyncKeyState(VK_ESCAPE) && MMTime.u.sample < MZK_NUMSAMPLES);

#ifndef CLEANDESTROY 
    ChangeDisplaySettings(0, 0);    // 5 octets ?
    sndPlaySound(0, SND_NODEFAULT); // 9 octets
    ShowCursor(1);                  // 5 octets ?
#endif
    ExitProcess(0);
}
