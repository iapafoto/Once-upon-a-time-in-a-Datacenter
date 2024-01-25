//--------------------------------------------------------------------------//
// iq / rgba  .  tiny codes  .  2008/2021                                   //
//--------------------------------------------------------------------------//

#include <math.h>
#include "mzk.h"
#include "system.h"
#include "fp.h"


// https://karmafx.net/docs/karmafx_floattricks.pdf


float fract(float a) {
    return a - floorf(a);
}

float hash(float x) {
    return fract(sinf(x * 43758.54f) );
}

float clamp(float a, float n/*, float x*/) {  //clamp(a,n,1)
    return a < n ? n : a > 1.f ? 1.f : a;
}
// 4069 vs 4072
#define smoothstep(x) clamp(x, p0d00) // 4064 vs 4072 -> -8o

/*
float smoothstep(float x) {  // smoothstep(0,1,x)  4079  + 5 en inline
    //x = x < 0.f ? 0.f : x > 1.f ? 1.f : x; //+3o
    //return x * x * (3.f - x-x);
}
*/

float ksinf(float x, float k) {  // smoothstep(0,1,x)  4079  + 5 en inline   
    k += .001f;
    return floorf(sinf(x) / k) * k;
}

float beat(float time) {
    float t = fract(time);
    float f = 220.f * expf(-5.f * t);
    float a = sinf(3.141592f * f * t);
    float v = clamp(a * 8.f, -1.f) * (expf(-10.f * t) + expf(-t));
    v += a * 8.f * expf(-t); 
    return v + .8f * a * expf(- 3.f * t - p0d50);  // 4076
}

float melody(float time) {
    float f = 440.f;
    float im = 10.f + 9.f * sinf(1.57079f * time);
   // float v = sinf(6.2831f * f * time + im * sinf(1.57079f * f * time));
    float v = sinf(6.2831f * f * time + im * ksinf(1.57079f * f * time, smoothstep((time-100.f)/30.f)));
    //v += .3f * sinf(3.141592f * f * time); // cette ligne rajoute 17 octets
//    v += .3f * sinf(3.141592f * f * time  + 8.f * im * sinf(3.141592f * f * time)); // cette ligne rajoute 50 octets !!!
    return v * expf(-2.f * fract(8.f * time));
}
/*
float mix(float a, float b, float k) {
    return a + k * (b - a);
}

float Noise11(float x) {
    float p = floorf(x), f = fract(x);
    f = f * f * (3.f - 2.f * f);
    return mix(hash(p), hash(p + 1.f), f) - .5f;
}

//----------------------------------------------------------------------------------------
// Fractal Brownian Motion...
float wind(float x) { // 100 de trop !

    float r = 0.f, a = .6f;
    x = x * (Noise11(x * .4f) + 1900.f);
    for (int i = 0; i < 8; i++) {
        r += Noise11(x * a) / a;
        a += a;
    }
    return r;
}
*/

//4070
void mzk_init(short* buffer) {
    for (int i = 0; i < MZK_NUMSAMPLES; i++) {
        float t = (float)i / (float)MZK_RATE;
        float tb = t+expf(.0025f * t);
        float sm = smoothstep((t - 25.f) / 60.);
        float y = p0d30 * melody(tb)*sm;
        // voir avec sinf(x)/x -> plus leger que smoothstep peu etre
        y += .4f * (1.f - smoothstep(fabs(t - 67.4f)/p0d20) * smoothstep(fabs(t - 80.f)/p0d40)) * melody(tb * 80.f);
        y += (p1d00 - sm) * (p0d05 * (sinf(5.f * t + hash(t)) + beat(tb)) + p0d08 * beat(tb - p0d70));
        //y += wind(t);
        buffer[i] = f2i(y* 4915.f);
    }
}
