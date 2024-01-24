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
    return fract(sin(x * 43758.54f) );
}

float clamp(float a, float n/*, float x*/) {  //clamp(a,n,1)
    return a < n ? n : a > 1.f ? 1.f : a;
}

float smoothstep(float x) {  // smoothstep(0,1,x)  4079  + 5 en inline
    x = clamp(x, p0d00);
    return x * x * (3.f - x-x);
}

float beat(float time) {
    float t = fract(time);
    float f = 220.f * exp(-5.f * t);
    float a = sin(3.141592f * f * t);
    float v = clamp(a * 8.f, -1.f) * (exp(-10.f * t) + exp(-t));
    v += a * 8.f * exp(-t); 
    return v + .8f * a * exp(- 3.f * t - p0d50);  // 4076
}

float melody(float time) {
    float f = 440.f;
    float im = 10.f + 9.f * sin(1.57079f * time);
    float v = sin(6.2831f * f * time + im * sin(1.57079f * f * time));
    //v += .3f * sin(3.141592f * f * time); // cette ligne rajoute 17 octets
//    v += .3f * sin(3.141592f * f * time  + 8.f * im * sin(3.141592f * f * time)); // cette ligne rajoute 50 octets !!!
    return v * exp(-2.f * fract(8.f * time));
}
//4071
void mzk_init(short* buffer) {
    for (int i = 0; i < MZK_NUMSAMPLES; i++) {
        float t = (float)i / (float)MZK_RATE;
        float tb = t+exp(.0025f * t);
        float sm = smoothstep((t - 25.f) / 60.);
        float y = p0d30 * melody(tb)*sm;
        // voir avec sin(x)/x -> plus leger que smoothstep peu etre
        y += .4f * (1.f - smoothstep(fabs(t - 67.4f)/p0d20) * smoothstep(fabs(t - 80.f)/p0d40)) * melody(tb * 80.f);
        y += (p1d00 - sm) * (p0d05 * (sin(5.f * t + hash(t)) + beat(tb)) + p0d08 * beat(tb - p0d70));
        buffer[i] = f2i(y* 4915.f);
    }
}
