

//#version 430
//layout(location=0) uniform float iTime;layout(location=0) out vec4 cl;in vec2 p;

#define V(p,bx,by,bz,e) sdBox(p,vec3(bx,by,bz),e)
#define W(p,x,y,z,bx,by,bz,e) sdBox(p-vec3(x,y,z),vec3(bx,by,bz),e)

#define iTime ((iMouse.x/iResolution.x)*140.)
//#define iTime (iTime+75.)

float kr = 0.;
vec3 ph = vec3(0);
int sh = 0;

float sdBox(vec3 p, vec3 b, float e) {
    b = abs(p) - b;
    return min(max(b.x, max(b.y, b.z)), 0.) + length(max(b, 0.)) - kr * e;
}
vec2 hash22(vec2 p) {
    p = fract(p * vec2(5.398, 5.443));
    p += dot(p.yx, p + vec2(21.535, 14.3137));
    return fract(p.x * p.y * vec2(95.434, 97.597));
}
float n2D(vec2 p) {
    vec2 i = floor(p);
    p -= i;
    p *= p * p * (p * p * 6. - p * 15. + 10.);
    return dot(mat2(fract(sin(mod(vec4(0, 1, 113, 114) + dot(i, vec2(1, 113)), 6.2832)) * 43758.5)) * vec2(1. - p.y, p.y), vec2(1. - p.x, p));
}
float fbm(vec2 p) {
    return n2D(p) * .533 + n2D(p * 2.) * .267 + n2D(p * 4.) * .133 + n2D(p * 8.) * .067;
}
float tex3D(vec3 p, vec3 n) {
    n = max(n * n, .001);
    n /= n.x + n.y + n.z;
    return fbm(p.yz) * n.x + fbm(p.zx) * n.y + fbm(p.xy) * n.z;
}

vec3 doBumpMap(vec3 p, vec3 n) {
    p = (vec3(tex3D(vec3(p.x - .001, p.yz), n), tex3D(vec3(p.x, p.y - .001, p.z), n), tex3D(vec3(p.xy, p.z - .001), n)) - tex3D(p, n)) / .002;
    return normalize(n + (p - n * dot(n, p)) * .1);
}

mat2 rot(float a) {
    float ca = cos(a), sa = sin(a);
    return mat2(ca, sa, -sa, ca);
}

vec3 texture_wood2(vec3 p) {
    vec3 p0 = p;
    p = sin(p * 4.3 + cos(p.yzx * 6.7));
    float n = dot(p + sin(p * 13.) * .03, vec3(3)), g = 1. - abs(dot(sin(p0 * 120.5 + n * 6.283 + sin(p0.zxy * 121.3)), vec3(.333)));
    n = fract(n + fract(n * 4.) * .1);
    n = min(min(n, n * (1. - n) * 6.) * .85 + g * .2, 1.);
    return .3 + .7 * sqrt(mix(vec3(.5, .15, .025), vec3(.75, .3, .1) * 2., n * .75 + .25)) * (n * .6 + .4);
}
vec3 texture_wood(vec3 p) {
    vec2 size = vec2(6, .8), k;
    p.z += mod(round(p.x / .8), 2.) * 3.;
    k = size * round(p.zx / size);
    float r = hash22((k + 120.) * 80.).x;
    p.zx -= k;
    return texture_wood2((p + r) * .7 * vec3(1, 1, .1)) *
        mix(.1, 1., smoothstep(0., -.02, V(vec3(p.zx, 0), size.x * .5, size.y * .5, 49, 0.))) * mix(.5, 1., r);
}
vec2 min2(vec2 a, vec2 b) {
    return a.x < b.x ? a : b;
}



vec2 sdBezier(vec3 p, vec3 b0, vec3 b1, vec3 b2) {
    b0 -= p;
    b1 -= p;
    b2 -= p;
    vec3 b01 = cross(b0, b1), b12 = cross(b1, b2), b20 = cross(b2, b0), n = b01 + b12 + b20;
    float t,
        a = -dot(b20, n),
        b = -dot(b01, n),
        d = -dot(b12, n);
    p = (d - b) * b1 + (b + a * .5) * b2 - (d + a * .5) * b0;
    t = clamp((a * .5 + b - .5 * (a * a * .25 - b * d) * dot(p, b0 - 2. * b1 + b2) / dot(p, p)) / -dot(n, n), 0., 1.);
    return vec2(length(mix(mix(b0, b1, t), mix(b1, b2, t), t)), t);
}

vec2 sdRobot(vec3 p0) {
    float d = length(p0), k2 = smoothstep(89., 103., iTime), de;
    if (d > 3.1 && sh == 0)
        return vec2(d - 3., 10);
    vec3 p = p0;
    d = V(p, .3, .6, .2, .1 + .1 * p.y);
    vec2 d2 = sdBezier(p, vec3(0, .6, 0), vec3(0, 1.1, -.4), vec3(0, 1.6, .2));
    p.x = abs(p.x);
    p.xz *= rot(-.2);
    d = min(d, W(p, .4, -1.8, 1.3, .2, .12, .4, 0.));
    d2 = min2(d2, sdBezier(p, vec3(.2, -.6, 0), vec3(.6, -.3, 1.5), vec3(.4, -1.8, 1)));
    d2 = min2(d2, sdBezier(p, vec3(.3 + .2 * kr, .6, 0), vec3(.9, -.3, -.5), vec3(.8, 0, 1.3)));
    d2 += vec2(-.08, cos(60. * d2.y) > .6 ? 50. : 25.);
    p = p0 - vec3(0, 1.9, .5);
    p.xy *= rot(.4 * k2 - .2);
    p.zy *= rot(smoothstep(80., 84., iTime) - .5 - .5 * k2);
    p.xz *= rot(-1.6 * k2);
    ph = p;
    d2 = min2(d2, vec2(V(p, .9, .6, .5, 0.), 50.5));
    p.x = abs(p.x);
    d2 = min2(d2, vec2(length(p - vec3(.75, 0, 0)) - .3, 25));

    de = length(p - vec3(.3, -.05, .25)) - .3;
    p = p0 + vec3(0, 0, -1.4);
    p.yz *= rot(-.7);
    if (iTime < 79.) {
        // book
        p0 = p;
        p0.xy *= rot(1.66);
        p0.y = abs(p0.y);
        p0.xy *= rot(1.26);
        p0.x -= .5 + p0.y * 1.256;
        p0.y -= .12;
        k2 = min(V(p0, .5, 0, .75, .018), W(p0, -.65, .02, -.02, .12, 0, .68, .018));
        p0.y -= .01 + sin(p0.x * 6.9 + 5.7) * .027 / (1. + p0.x) - .12;
        d2 = min2(d2, min2(vec2(k2, 70), vec2(.7 * V(p0, .48, .06, .73, 0.), 2)));
    }
    p.x = abs(p.x);
    p.xy *= rot(.2);
    return min2(min2(d2, vec2(min(d, W(p, 1, -.05, 0, .2, .15, .2, .05)), 50)), vec2(de, -1));
}

// bump bordure des livres 1.-cos(max(0,cos(x)))
vec2 book(vec3 p, float w, float h, float c) {
    p.xy *= rot(kr * (.05 - .2 * w));
    p -= vec3(-w * .5, h + .07, 0);
    w = w * .5 - .03;
    p.x = abs(p.x);

    float d = W(p, w, 0, 0, 0, h, h * .7, .01);

    p.z += .03 * cos(p.x / w) - .01;  // bombé

    return min2(
        vec2(W(p, 0, 0, -.015, w, h * .95 + .002 * cos(6e2 * p.x), h * .65, .0), 15),
        vec2(min(d, W(p, 0, 0, -h * .7 - .01 + .02 * (.3 + cos(2. * max(.9, cos(14. * p.y / h)))), w - .015, h, 0, .015)),
            c) // pages
    );

}


vec2 sdMap(vec3 p0) {

    vec3 pl = p0, p = p0 - vec3(-20, 19.65, 3);
    p.xz *= rot(.4);
    vec2 res0 = vec2(999, 0), // ce qui disparait avec kr
        res = sdRobot(p);
    float hall = W(p0, 5, 30, 5, 15, 30, 5, 0.),
        dr = length(p),
        x = max(0., iTime - 80.);

    dr -= 5. * smoothstep(0., 18., x) + 5.1 * max(0., x - 18.5);
    kr = smoothstep(-1., 1., dr);

    pl.y = mod(pl.y + 10., 17.5) - 10.;
    res0 = min2(res0, vec2(max(-hall, W(pl, 0, .1, 0, 999, .1, 999, 0.)), 1));

    // stair
    p = p0 - vec3(6.7, 0, 5);
    p.xy *= rot(.785);
    p.z = abs(p.z);
    x = W(p, 0, 0, 3, 1.2, 24, .05, 0.);
    p.y -= clamp(round(p.y), 0., 24.);
    p.yx *= rot(.785);
    res0 = min2(res0, vec2(min(x, V(p, .45, .5, 3, .05)), .37));

    pl.x = mod(pl.x + 1.5, 3.) - 1.5;
    res0 = min2(res0, vec2(max(-hall, W(pl, 0, -.5, 0, .17, .45, 999, 0.)), .3));
    pl = p0 - vec3(10, 0, -2.5);
    pl.xz = mod(pl.xz + 36., 72.) - 36.;
    pl.zy *= rot(-.2);
    pl.x -= 18.;

    // ladder
    p = pl;
    p.y -= clamp(round(p.y), 0., 9.);
    p.x -= clamp(p.x, -.8, .8);
    pl.x = abs(pl.x) - .75;
    pl.y -= clamp(pl.y, 0., 10.);
    res0 = min2(res0, vec2(min(length(p) - .07, length(pl) - .1), .3));

    hall = W(p0, 0, 15.25, 0, 999, 2.2, 999, 0.);

    p0.z = mod(p0.z + 5., 10.) - 5.;
    p = p0;
    vec2 d, h = kr * (.2 + .1 * cos(2. * p.xy) + .2 * cos(.3 * p.xy));
    res = min2(res, vec2(W(p, 0, 15.8, 0, 999, .85 - h.x, .65 - h.x, h.x), .8));
    p.z = abs(p.z) - 1.1;
    p.x = mod(p.x + 6., 12.) - 6.; //p.x-=12.*round(p.x/12.);
    res = min2(res, vec2(V(p, .5 - h.y, 100, .5 - h.y, h.y), .5));
    res = min2(res, vec2(V(p, .5, .3, .5, .1 + .05 * cos(6. * p.y)), 8.5));
    res = min2(res, vec2(W(p, 0, 16.8, 0, .45, .45, 1e3, .2), .6));
    res = min2(res, vec2(W(p, 0, 14.7, 0, .7, 0, 0, .05), .3));

    res0 = min2(res0, vec2(W(p, 0, 14.7, -.5, .2, .27, .6, .05), .5));
    p -= vec3(0, 15.5, 1.7);
    p.zy *= rot(.72);
    res0 = min2(res0, vec2(V(p, .17, .2, 2.6, .1), .5));
    p.z = abs(p.z);
    res0 = min2(res0, vec2(W(p, 0, 0, 2, .7, 0, 0, .05), .3));
    p = p0;
    p.z -= 2.5;
    p.x = mod(p.x + 30., 48.) - 11.;
    p.y = mod(p.y + 13., 17.5) - 13.;
    res = min2(res, vec2(W(p, 0, 1.4, 0, 2.4, 0, .8, .1), .3));
    p.xz = abs(p.xz);
    p.xy *= rot(.1);
    res0 = min2(res0, vec2(W(p, 1.6, .6, .6, 0, .7, 0, .1), 4.5)); // pied tabouret
    p = p0;
    p.x = mod(p.x + 36., 72.) - 36.;
    hall = min(hall, W(p, 18, 0, 0, 6.01, 999, 999, 0.));
    p = p0;
    p.y = mod(p.y + .3, 2.5) - 1.25;
    res = min2(res, vec2(max(-hall, V(p, 1e3, .1, .7, 0.)), .8));
    p = p0;
    p.y = mod(p.y - .5, 2.5) - .5;

    float c = floor(p.x),
        iy = floor(p0.y / 2.5),
        b = kr * .5 * smoothstep(65., 88., iTime);

    d = vec2(999, 0);

    if (kr < .5 || iTime < 77.) {
        d = vec2(p.x - c > .5 ? W(p, c + 11.5, .75, 0, 10.485, .8, .462, 0.) : W(p, c - 10.5, .8, 0, 10.485, .75, .462, 0.), 0);
        p.x -= c;
        for (x = 0.; x <= .98;) {
            h = vec2(.1 + .4 * (1. - kr), .4) + kr * vec2(.2, .2) * hash22(vec2(x, c + iy));
            h.x = min(h.x, 1. - x);
            x += h.x;
            if (h.x > b)
                d = min2(d, book(p - vec3(x, 0, 0), h.x, h.y, 2. + 250. * hash22(h + c).x));

        }
        d.x = max(d.x, -hall);
        d.x = kr < .5 ? max(d.x, dr + .5) : d.x;
    }

    res0.x = max(res0.x, -dr);
    return min2(res0, min2(res, d));
}

vec3 render(vec3 ro, vec3 rd) {

    float ao = 0., sha = 1., tt = .02, edge, m, t = .3 * hash22(rd.xy + 912. * rd.z).x;

    vec2 res;
    for (int i = 0; i < 128; i++) {
        res = sdMap(ro + rd * t);
        if (res.x < 1e-4 * t || t>50.)
            break;
        t += .9 * res.x;
    }

    m = res.y;

    if (m < -.5) return vec3(.7, .9, 1);
    // normal
    ro += t * rd; // ro devient la pos de contact

    vec3 col, ref, lig, nor = vec3(0., max(8e-4 * t, .03 - kr * .02), 0.);

    // normal
    lig = vec3(sdMap(ro - nor.yxx).x, sdMap(ro - nor.xyx).x, sdMap(ro - nor.xxy).x);
    col = vec3(sdMap(ro + nor.yxx).x, sdMap(ro + nor.xyx).x, sdMap(ro + nor.xxy).x);

    nor = col - lig;
    nor = normalize(nor - max(.0, dot(nor, rd)) * rd);
    ref = reflect(rd, nor);

    // edge
    col = 15. * abs(res.x - .5 * (col + lig));
    edge = min(1., col.x + col.y + col.z); //edge finder  

    // Color
    col = .5 + .3 * sin(vec3(.05, .08, .1) * (m - 1.));

    if (m < .4)
        col = .15 * texture_wood2(ro * vec3(.15, 1.5, 1.5));
    else if (m < .9)
        col = texture_wood2((m == .8 ? ro.zxy : m == .6 ? ro.yzx : ro) * .5 * vec3(1.5, .15, 1.5));
    else if (m < 1.5)
        col = texture_wood(ro.zyx);
    else if (m == 50.5 || m == 50.)
        col = mix(vec3(.01, .3, 1), col, smoothstep(.5, .6, tex3D((m == 50. ? ro : ph) * 2., nor)));

    nor = kr > 0. ? doBumpMap(30. * ro, nor) : nor;

    lig = normalize(vec3(.347, .78, -.752)),
        sh = 1;
    // shadow
 //   float ao=0.,sha=1.,tt=.02;//+.05*hash22(rd.xy+9123.*rd.z).x;
    for (int i = 0; i < 24; i++) {
        m = sdMap(ro + lig * tt).x;
        sha = min(sha, 2. * m / tt);
        tt += clamp(m, .02, .1);
        if (m < .001 || tt>2.5)
            break;
    }

    // ambiant occlusion
    tt = 1.05;
    for (int i = 0; i < 5; i++)
        m = .02 + .06 * float(i),
        m -= sdMap(ro + nor * m).x,
        ao += m * (tt *= .95);

    // shading
    lig = dot(nor, lig) * clamp(sha, 0., 1.) * vec3(1.3, 1, .7) +
        4. * pow(clamp(dot(ref, lig), 0., 1.), 46.) * vec3(1, .9, .7) +
        clamp(1. - ao, 0., 1.) * (
            .4 * clamp(.5 + .5 * nor.y, 0., 1.) +
            .5 * smoothstep(-.1, .1, ref.y)) * vec3(.4, .6, 1) +
        .25 * pow(clamp(1. + dot(nor, rd), 0., 1.), 2.);
    //   lig += .5*pow(max(.5, dot(rd, reflect(-normalize(vec3(.5, 0, .8)), nor))), 5.);
       // blur far
    col = mix(mix(.2 + edge * (2. + cos(3. * iTime)) * vec3(.1, 1, 2), col, kr) * lig, vec3(.8, .9, 1), smoothstep(10., 50., t));

    return col;
}

void mainImage(out vec4 cl, vec2 fragCoord) {

    vec2 R = iResolution.xy, p = (2. * fragCoord - R) / R.y;

    //void main() {
    int[18] an = int[18](0, 10, 10, 20, 20, 35, 20, 40, 20, 47, 30, 55, 55, 65, 92, 99, 99, 120);
    int[30] aro = int[30](162, 8, -85, 162, 4, -5, 112, 4, -8, 92, 16, -7, 94, 15, 4, 10, 10, 5, -10, 24, 8, -23, 24, 9, -4, 25, 7, 90, 1, 4),
        ata = int[30](162, 4, -30, 170, 5, -7, 120, 3, -7, 90, 15, -5, 92, 14, 5, 0, 8, 5, -20, 22, 5, -20, 22, 5, -10, 21, 5, 84, 5, 8);

    float t;

    // Camera
    vec3 col,
        ro = vec3(aro[0], aro[1], aro[2]),
        rd = vec3(ata[0], ata[1], ata[2]);

    for (int i = 0; i < 9; i++)
        t = smoothstep(float(an[i * 2]), float(an[i * 2 + 1]), iTime),
        ro = mix(ro, vec3(aro[i * 3 + 3], aro[i * 3 + 4], aro[i * 3 + 5]), t),
        rd = mix(rd, vec3(ata[i * 3 + 3], ata[i * 3 + 4], ata[i * 3 + 5]), t);

    t = .5 * cos(.2 * iTime);
    col = normalize(rd - ro);
    rd = normalize(cross(col, vec3(sin(t), cos(t), 0)));
    rd = mat3(rd, normalize(cross(rd, col)), col) * normalize(vec3(p.xy, 2));
    // Trace
    col = render(ro, rd);

    // end anim
    t = smoothstep(115., 125., iTime);
    //   col *= sdBox(col,rd,t);
    cl = vec4(pow(clamp(mix(
        col,
        vec3(.1, 1, 2), .5 * smoothstep(1., 1.3, fbm(2.5 * p) + t)) * (1. - t), 0., 1.),
        vec3(.57)), 1);
}