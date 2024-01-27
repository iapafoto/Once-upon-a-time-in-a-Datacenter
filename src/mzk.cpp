//--------------------------------------------------------------------------//
// iq / rgba  .  tiny codes  .  2008/2021                                   //
//--------------------------------------------------------------------------//

#include <math.h>
#include "mzk.h"
#include "system.h"
#include "fp.h"


// https://karmafx.net/docs/karmafx_floattricks.pdf

#define ramp(x) clamp(x, p0d00) // -8 octets
#define mfloorf(x) (float)f2i(x - p0d50)

float fract(float a) {
    return a - mfloorf(a);
}

float hash(float x) {
    return fract(sinf(x * 43758.54f) );
}
/*
float clamp(float a, float n) {  //clamp(a,n,1)
    return a < n ? n : a > 1.f ? 1.f : a;
}
*/
float clamp(float x, float a) { // -3 octets
    return .5f * (fabs(x - a) + a + 1.f - fabs(x - 1.f));
}

//float smoothstep(float x) {  // ramp(0,1,x)  4079  + 5 en inline
//    x = x < 0.f ? 0.f : x > 1.f ? 1.f : x; //+3o
//    return x * x * (3.f - x-x);
//}

float ksinf(float x, float k) {  // + 5 en inline   
    k += .001f;
    return mfloorf(sinf(x) / k) * k;
}

float beat(float time) {
    float t = fract(time);
    float a = sinf(691.15f * mexpf(-4.f * t) * t);
    float v = clamp(a * 8.f, -1.f) * (mexpf(-10.f * t) + mexpf(-t));
    v += a * 10.f * mexpf(-t); 
    return v;// +.8f * a * mexpf(-3.f * t - p0d50);  // 4076
}

float melody(float time) {
   // const float f = 440.f;
    float im = 10.f + 9.f * sinf(1.57079f * time);
       // float v = sinf(6.2831f * f * time + im * ksinf(1.57079f * f * time, ramp((time-95.f)/30.f)));
    float v = sinf(2764.564f * time + im * ksinf(691.1476f * time, ramp((time - 96.f) / 30.f)));
    return v * mexpf(-2.f * fract(8.f * time));
}


void mzk_init(short* buffer) {
    for (int i = 0; i < MZK_NUMSAMPLES; i++) {
        float t = (float)i / (float)MZK_RATE;
        float tb = t + mexpf(.0025f * t);
        float sm = ramp((t - 25.f) / 60.f);
        float y = /*p0d30 */ melody(tb) * sm;
        y += (p0d60 - p0d60 * ramp(fabs(t - 67.4f)/p0d20) * ramp(fabs(t - 79.9f)/p0d40)) * melody(tb * 80.f); // decalé de 1s ?
        y += .5f*(p1d00 - sm) * (sinf(5.f * t + hash(t)) + beat(tb+p0d30) + p0d60 * beat(tb));
        buffer[i] = f2i(y * 1e3f);
    }
}
