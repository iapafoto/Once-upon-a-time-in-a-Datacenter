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

float fract(const float a) {
    return a - mfloorf(a);
}

#define hash(x) fract(sinf(x * 43758.54f))

/*
float clamp(float a, float n) {  //clamp(a,n,1)
    return a < n ? n : a > 1.f ? 1.f : a;
}
*/

float clamp(const float x, const float a) { // -11 octets / -3 octets
    return p0d50 * (fabs(x - a) + a + 1.f - fabs(x - 1.f));
}

//float smoothstep(float x) {  // ramp(0,1,x)  4079  + 5 en inline
//    x = x < 0.f ? 0.f : x > 1.f ? 1.f : x; //+3o
//    return x * x * (3.f - x-x);
//}

float ksinf(const float x, float k) {  // + 5 en inline   
    k += .001f;
    return mfloorf(sinf(x) / k) * k;
}

float beat(const float time) {
    float t = fract(time);
    float a = sinf(691.15f * mexpf(-4.f * t) * t);
    float h = mexpf(-t);
    return clamp(a*8.f, -1.f) * (mexpf(-10.f * t) + h) + a*10.f*h; 
}

float melody(const float t) {
    const float v = sinf(2764.564f * t + (10.f + 9.f * sinf(1.57079f * t)) * ksinf(691.1476f * t, ramp((t - 96.f) / 30.f)));
    return v * mexpf(-2.f * fract(8.f * t));;
}

void mzk_init(short* buffer) {
    for (int i = 0; i < MZK_NUMSAMPLES; i++) {
        float t = (float)i / (float)(MZK_RATE);

        float tb = t + mexpf(.0025f * t);
        float sm = ramp((t - 25.f) / 60.f);
        float y = 1.f - ramp(fabs(t - 67.4f) / p0d20) * ramp(fabs(t - 79.9f) / p0d40);
        y *= melody(tb * 80.f);
        y += p0d30*(p1d00 - sm) * (sinf(5.f * t + hash(t)) + beat(tb+p0d30) + p0d60 * beat(tb));
        float m = melody(tb) * sm;
//        float k = .5f + .4f * cos(6.28f*tb);
        float k = fract(2.f*tb);
        buffer[i*2] = f2i((y+k*m) * 2e3f);
        buffer[i*2+1] = f2i((y+m-k*m) * 2e3f);
    }
}
