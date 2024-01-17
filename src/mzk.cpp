//--------------------------------------------------------------------------//
// iq / rgba  .  tiny codes  .  2008/2021                                   //
//--------------------------------------------------------------------------//

#include <math.h>
#include "mzk.h"
#include "system.h"

// https://karmafx.net/docs/karmafx_floattricks.pdf
/*
__forceinline float my_floor(const float x) {
    float i = (float)(int)x;
    return x > 0.f ? i : (i - 1.f);
   // float r; _asm fld  dword ptr[x];
   // _asm fsin;
   // _asm fstp dword ptr[r];
  //  return r;
   // 
}
*/
/*
__forceinline float my_exp(float p) {
    int _i;
    float e = 1.44269504f * (float)0x00800000 * (p);
    _i = (int)e + 0x3F800000;
    e = *(float*)&_i;
    return e;
}
*/

float clamp(float a, float n, float x) {
    return a < n ? n : a > x ? x : a;
}

float fract(float a) {
    return a - floor(a);
}


float base(float time) {
    float y = 0.f;
    {
        float f = 440.f;//220.f;
        float im = 10.f + 9.f * sin(0.25f * 6.2831f * time);
        float v = 0.0f;
        v += 1.0f * sin(6.2831f * f * time * 1.f + 1.f * im * sin(0.25f * 6.2831f * f * time));
        v += 0.3f * sin(6.2831f * f * time * 0.5 + 8.0 * im * sin(0.5f * 6.2831f * f * time));
        v *= exp(-2.f * fract(8.0f * time));
        y += 0.3f * v;
    }
  
    {
        float t = fract(time);//*2.0f);
        float f = 220.0f * exp(-5.0f * t);
        float a = sin(6.2831f * f * t * 0.5f);
        float v = 0.0f;
        v += clamp(a * 8.0f, -1.0f, 1.0f) * (exp(-10.0f * t) + exp(-1.0f * t));
        v += a * 8.0f * exp(-1.0f * t);
        y += 0.4f * v;
    }
    {
        float t = fract(4.0f * time);
        float f = 330.0f * exp(-5.0f * t);
        float a = sin(6.2831f * (f * t * 0.5f + .25f));
        float v = 0.0f;
        v += clamp(a * 8.0f, -1.0f, 1.0f) * (exp(-10.0f * t) + exp(-1.0f * t));
        v += a * 2.0f * exp(-1.0f * t);
        y += 0.08f * v;
    }
    
    return y;
}


float mainSound(float time)
{
    float y = 0.0f,
     s = 1.0f,
     o = 0.0f;
    //for (int i = 0; i < 5; i++) // 4091 - 4128 => 37 octets
    {
        y += s * base(time - o);
        s *= 0.5f;
        o += 0.25f;
    }
    return y * 0.15f;
}

void mzk_init(short* buffer)
{
    for (int i = 0; i < MZK_NUMSAMPLES; i++) {
        const float time = (float)i / (float)MZK_RATE;
        float fl = mainSound(time);
        buffer[i] = f2i(fl * 32767.f);
     //   buffer[i*2 + 1] = //f2i(fl * 32767.0f);
    }
}
