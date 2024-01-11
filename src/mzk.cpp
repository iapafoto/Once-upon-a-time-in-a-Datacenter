//--------------------------------------------------------------------------//
// iq / rgba  .  tiny codes  .  2008/2021                                   //
//--------------------------------------------------------------------------//

#include <math.h>
#include "mzk.h"
#include "system.h"

float clamp(float a, float n, float x) {
    return a < n ? n : a > x ? x : a;
}

float fract(float a) {
    return a-(float)floorf(a);
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
        float t = fract(4.0f * time);//*2.0f);
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
    float y = 0.0f;
    float s = 1.0f;
    float o = 0.0f;
    for (int i = 0; i < 5; i++)
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
        buffer[2 * i + 0] = f2i(fl * 32767.0f);
        buffer[2 * i + 1] = f2i(fl * 32767.0f);
    }
}
