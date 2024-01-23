//--------------------------------------------------------------------------//
// iq / rgba  .  tiny codes  .  2008/2021                                   //
//--------------------------------------------------------------------------//

#include <math.h>
#include "mzk.h"
#include "system.h"
#include "fp.h"


// https://karmafx.net/docs/karmafx_floattricks.pdf


float fract(float a) {
    return a - floor(a);
}

float hash(float x) {
    return fract(sin(x * 43758.54) );
}

float clamp(float a, float n, float x) {
    return a < n ? n : a > x ? x : a;
}

float smoothstep(float e0, float e1, float x) {
    x = clamp((x - e0) / (e1 - e0), p0d00, p1d00);
    return x * x * (3.f - 2.f * x);
}

float beat(float time) {
    float t = fract(time);
    float f = 220.f * exp(-5.f * t);
    float a = sin(3.141592f * f * t);
    float v = clamp(a * 8.f, -1.f, 1.f) * (exp(-10.f * t) + exp(-t));
    v += a * 8.f * exp(-t);
    return v + .8f * a * exp(-3.f * t - p0d50);
}

float melody(float time) {
    float f = 440.f;
    float im = 10.f + 9.f * sin(1.57079f * time);
    float v = sin(6.2831f * f * time + im * sin(1.57079f * f * time));
   // v += .3f * sin(3.141592f * f * time  + 8.f * im * sin(3.141592f * f * time)); // cette ligne rajoute 50 octets !!!
    return v * exp(-2.f * fract(8.f * time));
}

void mzk_init(short* buffer) {
    for (int i = 0; i < MZK_NUMSAMPLES; i++) {
        float t = (float)i / (float)MZK_RATE;
        float tb = t+exp(.002f * t);
        float sm = smoothstep(35.f, 90.f, t);
        float y = p0d30 * melody(tb) * sm;
        y += (p1d00 - sm) * (p0d05 * (sin(5.f * t + hash(t)) + beat(tb)) + p0d10 * beat(tb - p0d70));// *(1.f - smoothstep(90.f, 120.f, t));
        buffer[i] = f2i(y*p0d15 * 32767.f);
    }
}
