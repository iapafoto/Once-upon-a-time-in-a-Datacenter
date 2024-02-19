
//#version 430
//layout(location=0) uniform float iTime;layout(location=0) out vec4 cl;

#define iTime ((iMouse.x/iResolution.x)*150.)

float kr = 0.;
vec3 ph = vec3(0);
int sh = 0;

float sdBox(vec3 p, vec3 b, float e) {
    b = abs(p) - b;
    return min(max(b.x, max(b.y, b.z)), 0.) + length(max(b, 0.)) - kr * e;
}

void min2(inout vec2 a, vec2 b) {
    a = a.x < b.x ? a : b;
}

vec2 hash22(vec2 p) {
    return fract(sin(vec2(dot(p, vec2(127.1, 311.7)), dot(p, vec2(269.5, 183.3)))) * 43758.5453);
}

float n2D(vec2 p)
{
    vec2 i = floor(p);
    p -= i;
    p *= p * p * (p * p * 6. - p * 15. + 10.);
    return dot(mat2(fract(sin(mod(vec4(0, 1, 113, 114) + dot(i, vec2(1, 113)), 6.2832)) * 43758.5)) * vec2(1. - p.y, p.y), vec2(1. - p.x, p));
}

float fbm(vec2 p) {
    return n2D(p) * .533 + n2D(p * 2.) * .267 + n2D(p * 4.) * .133 + n2D(p * 8.) * .067;
}

float tex3D(vec3 p, vec3 n, int i) {
    if (i < 3)p[i] -= .001;
    n = max(n * n, .001);
    n /= n.x + n.y + n.z;
    return fbm(p.yz) * n.x + fbm(p.zx) * n.y + fbm(p.xy) * n.z;
}
void doBumpMap(inout vec3 n, vec3 p)
{
    p = (vec3(tex3D(p, n, 0), tex3D(p, n, 1), tex3D(p, n, 2)) - tex3D(p, n, 3)) / .002;
    n = normalize(n + (p - n * dot(n, p)) * .2);
}

mat2 rot(float a) {
    return mat2(cos(a - vec4(0, 1.57, 11, 0)));
}
vec3 txWood2(vec3 p0, int i) {
    p0[i] *= .1;
    vec3 p = sin(p0 * 4.3 + cos(p0.yzx * 6.7));
    float n = dot(p + sin(p * 13.) * .03, vec3(3)), g = 1. - abs(dot(sin(p0 * 120.5 + n * 6.283 + sin(p0.zxy * 121.3)), vec3(.333)));
    n = fract(n + fract(n * 4.) * .1);
    n = min(min(n, n * (1. - n) * 6.) * .85 + g * .2, 1.);
    return.3 + .7 * sqrt(mix(vec3(.5, .15, .025), vec3(.75, .3, .1) * 2., n * .75 + .25)) * (n * .6 + .4);
}

vec3 txWood(vec3 p) {
    vec2 size = vec2(6, .8), k;
    p.x += mod(round(p.z / .8), 2.) * 3.;
    k = size * round(p.xz / size);
    float r = hash22(k * 80. + 9600.).x;
    p.xz -= k;
    return txWood2((p + r) * .7, 0) * (.1 + .9 * smoothstep(0., -.02, sdBox(vec3(p.xz, 0), vec3(size.xy * .5, 49), 0.))) * (.5 + .5 * r);
}
float txInvader(vec2 v)
{
    ivec2 m = ivec2(v * 80.), x = m;
    m.y = (86 - m.y) % 8 + 1;
    return abs(x.x) < 33 && abs(x.y + 2) < 53 && (219 * (m.y > 4 ?
        614081 :
        4840434) & 1 << abs((m.x + 86) % 13 - 7) - m.y * 8) > 0 ?
        1. :
        1.5;
}
/*
vec3 txRev(vec2 o) {
    return vec3(1&int[](0,~0,124,0xC0F03C00,0xF7FBFF01,~0,0,0x8320D39F,~0,0x1F0010,0)
        [int(length(o)*2.)] >> int(5.*atan(o.y,o.x)));
}
*/
void sdBezier(inout vec2 r, vec3 p, vec3 b0, vec3 b1, vec3 b2)
{
    b0 -= p;
    b1 -= p;
    b2 -= p;
    vec3 b01 = cross(b0, b1), b12 = cross(b1, b2), b20 = cross(b2, b0), n = b01 + b12 + b20;
    float a = dot(b20, n), b = -dot(b01, n), d = -dot(b12, n);
    p = (d - b) * b1 + (b - a * .5) * b2 - (d - a * .5) * b0;
    a = clamp((b - .5 * (a * a * .25 - b * d) * dot(p, b0 - 2. * b1 + b2) / dot(p, p) - a * .5) / -dot(n, n), 0., 1.);
    min2(r, vec2(length(mix(mix(b0, b1, a), mix(b1, b2, a), a)) - .08, cos(60. * a) > .6 ?
        50 :
        25));
}
vec2 sdRobot(vec3 p0, float b)
{
    float d = length(p0), k2 = smoothstep(91., 1e2, iTime), k = smoothstep(68., 72., iTime);
    if (d > 3.1 && sh == 0)
        return vec2(d - 3., 10);
    vec3 p = p0, p00 = p0, pm;
    d = sdBox(p, vec3(.3, .6, .2), .1 + .1 * p.y);
    vec2 d2 = vec2(999);
    sdBezier(d2, p, vec3(0, .6, 0), vec3(0, 1.1, -.4), vec3(0, 1.6, .2));
    p.x = abs(p.x);
    p.zx *= rot(.2);
    d = min(d, sdBox(p - vec3(.4, -1.8, 1.3), vec3(.2, .12, .4), 0.));
    sdBezier(d2, p, vec3(.2, -.6, 0), vec3(.6, -.3, 1.5), vec3(.4, -1.8, 1));
    sdBezier(d2, p, vec3(.3 + .2 * kr, .6, 0), vec3(1. - .2 * b, -.8, -.2), vec3(.95 - .95 * b, -.07 - .1 * b, 1.3));
    p = p0 - vec3(0, 1.9, .5);
    p.xy *= rot(.4 * k2 - .2);
    p.zy *= rot(k - .5 - .5 * k2);
    p.zx *= rot(1.6 * k2);
    ph = p;
    min2(d2, vec2(sdBox(p, vec3(.9, .6, .5), 0.), 4));
    p.x = abs(p.x);
    min2(d2, vec2(length(p - vec3(.75, 0, 0)) - .3, 25));
    min2(d2, vec2(length(p - vec3(.3, -.05, .25)) - .3, -1. - b) // changment de la couleur des yeux
    );
    p0.z -= 1.4;
    p0.zy *= rot(.7);
    p0.x = abs(p0.x);
    p = p0;
    p.yx *= rot(1.26);
    pm = p - vec3(.2, 1.19 - b, -.18);
    pm.yx *= rot(.5);
    d = min(d, sdBox(pm, vec3(.15, .05, .1), .05));
    d = min(d, sdBox(pm - vec3(-.09, .03, .25), vec3(.07, .03, .16), .02));
    pm.yz *= rot(.5);
    d = min(d, sdBox(pm - vec3(.1, .08, .2), vec3(.07, .03, .16), .02));
    pm.xy *= rot(.3);
    pm.xz *= rot(1.);
    d = min(d, sdBox(pm - vec3(-.16, .05, .2), vec3(.06, .04, .12), .02));
    min2(d2, vec2(d, 5));
    if (iTime < 67. && sh == 0) {
        k2 = sdBox(p0 - vec3(0, -.1 - .03 * cos(9. * p0.x), 0), vec3(.2, .018, .8), .01);
        if (p00.y < .8)
            ph = p;
        k2 = min(k2, sdBox(p - vec3(.12, .5 + p.x * 1.256, 0), vec3(0, .5, .8), .018));
        p.y -= .5 + p.x * 1.256;
        min2(d2, vec2(k2, 48));
        min2(d2, vec2(.8 * sdBox(p - vec3(.01 + sin(p.y * 6.9 + 5.7) * .027 / (1. + p.y), 0, 0), vec3(.06, .48, .78), 0.), 7));
    }
    return d2;
}

void sdBook(inout vec2 r, vec3 p, float w, float h, float c) {
    // deplacement pour etre au milieu du livre
    p -= vec3(-w * .5, h + .07, 0);
    // 1/2 largeur - dw
    w = w * .5 - .015;
    // symetrie sur x
    p.x = abs(p.x);
    // premiere et derniere de couverture
    float d = sdBox(p - vec3(w, 0, 0), vec3(0, h, h * .7), .01);
    // aspect bombé du livre
    p.z -= kr * .04 * cos(p.x / w) - .004;
    // dessin des pages avec variations pseudo aleatoires
    min2(r, vec2(sdBox(p, vec3(w, h * .95 + .002 * cos(6e2 * p.x), h * .65), 0.), 15));
    // les 5 petites bosses sur les coutures
    p.z -= h * .7 - .011 - .02 * cos(2. * max(.9, cos(14. * p.y / h)));
    // arriere du livre
    min2(r, vec2(min(d, sdBox(p, vec3(w - .015, h, 0), .015)),
        // la couleur avec une distribution "rares exception"
        c * c * c * c));
}

vec2 sdMap(vec3 p0) {
    vec3 pl = p0, p = p0 - vec3(-20, 19.65, 3);
    p.xz *= rot(.4);
    float c, hall = sdBox(p0 - vec3(5, 31, 5), vec3(15, 30, 5), 0.),
        x = max(0., iTime - 80.),
        dr = length(p - vec3(0, 2, 0)) - 10. * smoothstep(0., 18., x) - 5.1 * max(0., x - 19.),
        b = clamp((80. - iTime) / 15., 0., 1.);
    b = pow(9., -15. * b) * cos(b * 30.);
    pl.y = mod(pl.y + 10., 17.5) - 10.;
    vec2 h,
        res0 = vec2(max(-hall, sdBox(pl - vec3(0, .1, 0), vec3(999, .1, 999), 0.)), 3),
        res = sdRobot(p, b);
    kr = smoothstep(-1., 1., dr);
    p = p0 - vec3(6.7, 0, 5);
    p.xy *= rot(.785);
    p.z = abs(p.z);
    p.y -= clamp(round(p.y), 0., 24.);
    p.yx *= rot(.785);
    min2(res0, vec2(min(sdBox(p, vec3(.45, .5, 3), .05), max(-hall, sdBox(pl - vec3(3. * round(pl.x / 3.), -.5, 0), vec3(.17, .45, 999), 0.))), 2.3));
    p = p0 - vec3(82, 0, -2.6);
    p.zy *= rot(-.2);
    p.x = abs(p.x);
    min2(res0, vec2(min(sdBox(p - vec3(0, clamp(round(p.y), 0., 8.), 0), vec3(.75, 0, 0), .04),
        sdBox(p - vec3(.75, 4.6, 0), vec3(.05, 4.4, .1), 0.)), .3));
    hall = sdBox(p0 - vec3(0, 15.25, 0), vec3(999, 2.2, 999), 0.);

    pl = p0;
    pl.y = pl.y / .25 + 1.; pl = round(pl * .1);

    p0.z -= pl.z / .1;

    p = p0;
    h = kr * (.2 + .1 * cos(2. * p.xy) + .2 * cos(.3 * p.xy));
    min2(res, vec2(sdBox(p - vec3(0, 15.8, 0), vec3(999, .85 - h.x, .65 - h.x), h.x), .99));
    p.z = abs(p.z) - 1.1;
    p.x = mod(p.x + 6., 12.) - 6.;
    min2(res, vec2(sdBox(p, vec3(.5), .2 - .2 * p.y), 9));
    min2(res, vec2(sdBox(p, vec3(.5 - h.y, 100, .5 - h.y), h.y), 1));
    min2(res, vec2(sdBox(p - vec3(0, 16.8, 0), vec3(.45, .45, 1e3), .2), 2));
    min2(res0, vec2(sdBox(p - vec3(0, 14.7, 0), vec3(.6, 0, 0), .05), 1.5));
    min2(res0, vec2(sdBox(p - vec3(0, 14.7, -.5), vec3(.2, .27, .6), .05), 2));
    p -= vec3(0, 15.5, 1.7);

    p.yz *= rot(-.72);
    min2(res0, vec2(sdBox(p, vec3(.17, .2, 2.5), .1), 1));
    p.z = abs(p.z);
    min2(res0, vec2(sdBox(p - vec3(0, 0, 2), vec3(.7, 0, 0), .05), 1.5));

    p = p0;
    p.z -= 2.5;
    p.x = mod(p.x + 30., 48.) - 11.;
    p.y = mod(p.y + 13., 17.5) - 13.;
    min2(res, vec2(sdBox(p - vec3(0, 1.4, 0), vec3(2.4, .04, .8), .06), .1));
    p.xz = abs(p.xz);
    p.xy *= rot(.1);
    min2(res0, vec2(sdBox(p - vec3(1.6, .6, .6), vec3(0, .7, 0), .1), 8));
    res0.x = max(res0.x, -dr);
    min2(res, res0);
    hall = min(hall, sdBox(p0 - vec3(18. + 72. * round(p0.x / 72.), 0, 0), vec3(6.01, 999, 999), 0.)); // couloir en travers

    p = p0;
    p.y = mod(p.y + .27, 2.5) - 1.25;
    min2(res, vec2(max(-hall, sdBox(p, vec3(1e3, .07, .7), 0.)), .99));
    p.y = mod(p0.y - 1., 2.5);
    c = floor(p.x);
    if (kr < .5 || iTime < 85.) {
        res0 = vec2(sh == 0 ?
            p.x - c > .5 ?
            sdBox(p - vec3(c + 11.5, .75, 0), vec3(10.48, .8, .7), 0.) :
            sdBox(p - vec3(c - 10.5, .8, 0), vec3(10.48, .8, .7), 0.) :
            999., 0);
        p.x -= c;
        for (x = .02; x <= .97;)
        {
            h = vec2(1. - .87 * kr, .38) + kr * vec2(.2, .3) * hash22(pl.zy + vec2(x, c));
            h.x = min(h.x, .98 - x);
            x += h.x;
            if (h.x > .12 + .5 * kr * b)
                sdBook(res0, p - vec3(x, 0, 0), h.x, h.y, 2. + hash22(h + c).x);
        }
        res0.x = max(max(res0.x, -hall), kr < .5 ? dr + .5 : 0.);
        min2(res, res0);
    }
    return res;
}

vec3 render(inout vec3 ro, inout vec3 rd, inout float md) {
    sh = 0;
    float sha = 1., edge, m, t = .1/*02*hash22(rd.xy+912.*rd.z).x*/, tt = .01;
    vec2 res = vec2(999);
    for (int i = 0; ++i<200 && res.x>t / 1e4 && t < md;) {
        res = sdMap(ro + rd * t);
        t += .9 * res.x;
    }
    m = res.y;
    if (m < .0) { // couleur des yeux
        rd *= 0.;
        return vec3(.7, .9, 1) * (m<-1.2 && m>-2. ? hash22(ro.xy + m).x - .5 : 1.);
    }

    ro += t * rd;
    vec3 ref = vec3(0, max(1e-4 * t, .05 - kr * .04), 0),
        lig = vec3(sdMap(ro - ref.yxx).x, sdMap(ro - ref.xyx).x, sdMap(ro - ref.xxy)),
        col = vec3(sdMap(ro + ref.yxx).x, sdMap(ro + ref.xyx).x, sdMap(ro + ref.xxy)),
        nor = col - lig + .001;
    nor = normalize(nor - max(.001, dot(nor, rd)) * rd);
    //  ref=reflect(rd,nor);
    col = 4. * abs(res.x - col - lig);
    edge = min(1., col.x + col.y + col.z);
    col = .5 + .3 * sin(vec3(.05, .08, .1) * (m - 1.));

    ph = m == 4. || m == 7. ?
        ph :
        ro;
    col = m < 3. ?
        fract(m + .99) * txWood2(ro, int(m)) :
        m == 3. ?
        .2 + txWood(ro).x * vec3(.4) ://(.4-.38*txRev(ro.xz-vec2(90,-5))):
        m == 4. || m == 5. ?
        mix(vec3(.01, .3, 1), vec3(.6, .3, .1), smoothstep(.6, .7, tex3D(ph * 2., nor, 3))) :
        m == 7. ?
        vec3(txInvader(ph.yz - vec2(.46, .05))) :
        col;
    ref = reflect(rd, nor);

    if (kr > 0.)
        doBumpMap(nor, 30. * ph);


    lig = vec3(.27, .6, .58);
    sh = 1;
    for (int i = 0; ++i < 28 && m>.001 && tt < 2.5;)
        m = sdMap(ro + lig * tt).x, sha = min(sha, 2. * m / tt), tt += clamp(m, .02, .1);

    tt = 1.05;
    m = 1.; // became ao
    for (float x = .02; x < .32; x += .06)
        m -= (x - sdMap(ro + nor * x).x) * (tt *= .95);
    lig = .1 + min(m, 1.) * dot(nor, lig) * max(sha, 0.) * vec3(1.3, 1, .6)
        + pow(max(dot(ref, lig), 0.), 12.) + .25 * pow(clamp(1. + dot(nor, rd), 0., 1.), 2.)
        + .12 * vec3(.2, 1, 2) * max(0., dot(rd, reflect(vec3(.97, 0, .24), nor)));

    rd = res.y == 3. || res.y == .1 ? ref : ref - ref;
    return mix(
        mix(vec3(1.5, .9, .75), vec3(.2, .3, .5), kr),
        mix(.2 + edge * (2. + cos(3. * iTime)) * vec3(.1, 1, 2), col, kr) * lig,
        md = smoothstep(md, md / 5., t));
}


//void main() {
//vec2 R=vec2(1280,720),q=gl_FragCoord.xy,
void mainImage(out vec4 cl, vec2 glFragCoord) {
    vec2 R = iResolution.xy, q = glFragCoord.xy,
        p = (q + q - R) / R.y;
    q /= R;
    int[18] an = int[18](0, 10, 10, 20, 20, 35, 20, 40, 20, 47, 30, 55, 55, 65, 92, 99, 99, 130);
    int[30] aro = int[30](95, 8, 80, 95, 5, -7, 110, 10, -5, 92, 16, -8, 94, 17, 2, 8, 5, 8, -10, 24, 4, -23, 24, 9, -4, 25, 7, 140, 4, 4),
        ata = int[30](80, 6, 28, 91, 5, -5, 113, 9, -12, 90, 15, -2, 92, 17, 8, 0, 6, 5, -16, 22, 5, -20, 21, 5, -10, 23, 7, 135, 3, 9);
    float t, t2 = 8.;
    vec3 a, col, ro = vec3(aro[0], aro[1], aro[2]), rd = vec3(ata[0], ata[1], ata[2]);
    for (int i = 0; ++i < 10;)
        t = smoothstep(float(an[i * 2 - 2]), float(an[i * 2 - 1]), iTime),
        ro = mix(ro, vec3(aro[i * 3], aro[i * 3 + 1], aro[i * 3 + 2]), t),
        rd = mix(rd, vec3(ata[i * 3], ata[i * 3 + 1], ata[i * 3 + 2]), t);
    t = .5 * cos(.2 * iTime);
    a = normalize(rd - ro);
    rd = normalize(cross(a, vec3(sin(t), cos(t), 0)));
    rd = mat3(rd, normalize(cross(rd, a)), a) * normalize(vec3(p + (iTime > 99. ?
        .01 * hash22(p - p + iTime).x :
        0.), 2));

    t = 50.;
    col = render(ro, rd, t);
    if (rd.x != 0.) {
        col += t * .1 * render(ro, rd, t2);
    }
    t = smoothstep(0., 7., iTime - 125.);
    cl = iTime == 0. ?
        vec4(1 & int[](0, ~0, 124, 3236969472, 4160487169, ~0, 0, 2199966623, ~0, 2031632, 0)[min(int(length(p * 20.)), 10)] >> int(5. * atan(p.y, p.x))) :
        vec4(pow(clamp(mix(col, vec3(.1, .5, 1), smoothstep(1., 1.3, fbm(2.5 * p) + t)) * (1. - t), 0., 1.), vec3(.7)) * 4. * sqrt(q.x * q.y * (1. - q.x) * (1. - q.y)), 1);
}