//--------------------------------------------------------------------------//
// iq / rgba  .  tiny codes  .  2008/2021                                   //
//--------------------------------------------------------------------------//
#include "fp.h"

#ifdef WINDOWS


int f2i(float x) // use this to convert float to int, or use /QIfist as additional compiler parameters
{
    int t;
    _asm fld dword ptr[x]
    _asm fistp dword ptr[t];
    return t;
}

/*
int f2i(float x) {
    const double MAGIC = 2251799813685248 + 4503599627370496; // 2^51+2^52
    double dtemp = x + MAGIC;
    return (*(int*)&dtemp);
}
*/

//float mfloorf(float x) // with rounding !
//{
   // x = x - 0.5f;
   // int t;
   // _asm fld x
   // _asm fistp t
//    return (float)f2i(x - p0d50);
//}

float mexpf(const float x) 
{
    float res;
    _asm fld     dword ptr[x]
        _asm fldl2e
    _asm fmulp   st(1), st(0)
    _asm fld1
    _asm fld     st(1)
    _asm fprem
    _asm f2xm1
    _asm faddp   st(1), st(0)
    _asm fscale
    _asm fxch    st(1)
    _asm fstp    st(0)
    _asm fstp    dword ptr[res]
        return res;
}

/* 4087
float mexpf(float p) { // approx + 5!
    float e = 1.44269504f * (float)0x00800000 * (p);
    int _i = f2i(e) + 0x3F800000;
    e = *(float*)&_i;
    return e;
}
*/

/*

static inline int f2i(float x) // use this to convert float to int, or use /QIfist as additional compiler parameters
{
    int tmp;
    _asm fld dword ptr[x]
        _asm fistp dword ptr[tmp];
    return tmp;
}

int mifloorf(float x)
{
    x = x - 0.5f;
    int t;
    _asm fld x
    _asm fistp t
    return t;
}

static short opc1 = 0x043f;     // floor
float mfloorf(float x)
{
    int res;
    short tmp;
    _asm fstcw   word  ptr[tmp]
    _asm fld     dword ptr[x]
    _asm fldcw   word  ptr[opc1]
    _asm fistp   dword ptr[res]
    _asm fldcw   word  ptr[tmp]
    return (float)res;
}

float mfmodf(float x, float y) {
    float res;
    _asm fld dword ptr[y]
        _asm fld dword ptr[x]
        _asm fprem
    _asm fstp st(1);
    _asm fstp dword ptr[res]
        return res;
}

float m2xf(float f) {
    _asm fld   dword ptr[f]
        _asm fld1
    _asm fld   st(1)
    _asm fprem
    _asm f2xm1
    _asm faddp st(1), st
    _asm fscale
    _asm fstp  st(1)
    _asm fstp  dword ptr[f]
        return f;
}

int mifloorf(float x)
{
    x = x - 0.5f;
    int t;
    _asm fld x
    _asm fistp t
    return t;
}
*/



/*
 
float fastpower(float f,int n) {
    long *lp,l;
    lp=(long*)(&f);
    l=*lp;l-=0x3F800000l;l<<=(n-1);l+=0x3F800000l;*lp=l;
    return f;
}

float fastroot(float f,int n) {
long *lp,l;
lp=(long*)(&f);
l=*lp;l-=0x3F800000l;l>>=(n-1);l+=0x3F800000l;
*lp=l;
return f;
 }
 float InvSqrt(float x) {
float xhalf = 0.5f*x;
int i = *(int*)&x; // get bits for floating value
i = 0x5f3759df - (i>>1); // gives initial guess y0
x = *(float*)&i; // convert bits back to float
x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
return x;
 }
 float FastRSQRT(float val) {
const float magicValue = 1597358720.0f;
float tmp = (float)*((uint*)&val);
tmp = (tmp * -0.5f) + magicValue;
uint tmp2 = (uint)tmp;
return *(float*)&tmp2;
 }

float mpowf(float a, float b)
{
    float res;
    _asm fld        dword ptr[b]
        _asm fld        dword ptr[a]
        _asm fyl2x
    _asm fld        st
    _asm frndint
    _asm fsub       st(1), st
    _asm fxch       st(1)
    _asm f2xm1
    _asm fld1
    _asm fadd
    _asm fscale
    _asm fstp       st(1)
    _asm fstp dword ptr[res]
        return res;
}
*/
/*
float msys_log2f(const float x){
    float res;
    _asm fld    dword ptr[x]
        _asm fld1
    _asm fxch   st(1)
    _asm fyl2x
    _asm fstp   dword ptr[res]
        return res;
}

float msys_fmodf(const float x, const float y)
{
    float res;

    _asm fld     dword ptr[y]
        _asm fld     dword ptr[x]
        _asm fprem
    _asm fxch    st(1)
    _asm fstp    st(0)
    _asm fstp    dword ptr[res]

     return res;
}
*/


/*
float msys_powf(const float x, const float y)
{
    float res;

    _asm fld     dword ptr[y]
        _asm fld     dword ptr[x]
        _asm fyl2x
    _asm fld1
    _asm fld     st(1)
    _asm fprem
    _asm f2xm1
    _asm faddp   st(1), st(0)
    _asm fscale
    _asm fxch
    _asm fstp    st(0)
    _asm fstp    dword ptr[res];

    return res;
}
*/


#endif