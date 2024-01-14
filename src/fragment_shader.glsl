#version 430
layout(location=0) uniform float iTime;
layout(location=0) out vec4 cl;
in vec2 p;

float kr = 0.;
vec3 ph=vec3(0);
int sh=0;

vec2 hash22(vec2 p){
    p=fract(p*vec2(5.398,5.443));
    p+=dot(p.yx,p+vec2(21.535,14.3137));
    return fract(p.x*p.y*vec2(95.434,97.597));
}
float n2D(vec2 p){
    vec2 i=floor(p);
    p-=i;
    p*=p*p*(p*p*6.-p*15.+10.);
    return dot(mat2(fract(sin(mod(vec4(0,1,113,114)+dot(i,vec2(1,113)),6.2832))*43758.5))*vec2(1.-p.y,p.y),vec2(1.-p.x,p));
}
float fbm(vec2 p){
    return n2D(p)*.533+n2D(p*2.)*.267+n2D(p*4.)*.133+n2D(p*8.)*.067;
}
float tex3D(vec3 p,vec3 n) {
    n=max(n*n,.001);
    n/=n.x+n.y+n.z;
    return fbm(p.yz)*n.x+fbm(p.zx)*n.y+fbm(p.xy)*n.z;
}

vec3 doBumpMap(vec3 p,vec3 n) {
    vec3 grad=vec3(tex3D(vec3(p.x-.001,p.yz),n),tex3D(vec3(p.x,p.y-.001,p.z),n),tex3D(vec3(p.xy,p.z-.001),n));
    grad=(grad-tex3D(p,n))/.002;
    grad-=n*dot(n,grad);
    return normalize(n+grad*.2);
}

mat2 rot(float a) {
    float ca=cos(a),sa=sin(a);
    return mat2(ca,sa,-sa,ca);
}
float sdLadder(vec3 p0) {
    vec3 p=p0;
    p.y-=clamp(round(p.y),0.,9.);
    p.x-=clamp(p.x,-.8,.8);
    p0.x=abs(p0.x)-.75;
    p0.y-=clamp(p0.y,0.,10.);
    return min(length(p)-.07,length(p0)-.1);
}
float sdBox(vec3 p,vec3 b) {
    vec3 d=abs(p)-b;
    return min(max(d.x,max(d.y,d.z)),0.)+length(max(d,0.));
}

float box0(vec3 p,float bx,float by,float bz,float e) {return sdBox(p,vec3(bx,by,bz))-kr*(e);}
//#define box(p,x,y,z,bx,by,bz,e) box0(p-vec3(x,y,z),bx,by,bz,e)
float box(vec3 p,float x,float y,float z,float bx,float by,float bz,float e) {return sdBox(p-vec3(x,y,z),vec3(bx,by,bz))-kr*(e);}

float sdStairs(vec3 p) {
    p.xy*=rot(.785);
    p.z=abs(p.z);
    float d=box(p,0.,0.,3.,1.2,24.,.05,0.);
    p.y-=clamp(round(p.y),0.,24.);
    p.yx*=rot(.785);
    return min(d,box0(p,.45,.5,3.,.05));
}
vec3 texture_wood2(vec3 p){
    vec3 p0=p;
    p=sin(p*4.3+cos(p.yzx*6.7));
    float n=dot(p+sin(p*13.)*.03,vec3(3)),g=1.-abs(dot(sin(p0*120.5+n*6.283+sin(p0.zxy*121.3)),vec3(.333)));
    n=fract(n+fract(n*4.)*.1);
    float w=min(min(n,n*(1.-n)*6.)*.85+g*.2,1.);
    return .3+.7*sqrt(mix(vec3(.5,.15,.025),vec3(.75,.3,.1)*2.,w*.75+.25))*(w*.6+.4);
}
vec3 texture_wood(vec3 p) {
  vec2 size=vec2(6,.8),c=floor((p.zx+size/2.)/size);
  p.z+=mod(c.y,2.)*size.x*.5;
  c=floor((p.zx+size/2.)/size);
  p.zx=size*(fract(p.zx/size+.5)-.5);
  c*=size;
  float r=hash22((c+120.)*80.).x;
  return texture_wood2((p+r)*.5*vec3(1.5,1.5,.15))*
      mix(.1,1.,smoothstep(0.,-.02,box0(vec3(p.zx,0),size.x*.5,size.y*.5,49.,0.)))*mix(.5,1.,r);
}
vec2 min2(vec2 a,vec2 b) {
  return a.x<b.x?a:b;
}
vec2 sdBook(vec3 p) {
  p.xy*=rot(1.66);
  p.y=abs(p.y);
  p.xy*=rot(1.26);
  p.x-=.5+p.y*1.256;
  p.y-=.12;
  float dC=min(box0(p,.5,0.,.75,.018),box(p,-.65,.02,-.02,.12,0.,.68,.018));
  p.y-=.01+sin(p.x*6.9+5.7)*.027/(1.+p.x)-.12;
  return min2(vec2(dC,70),vec2(.7*box0(p,.48,.06,.73,0.),2));
}
vec2 book(vec3 p0,float w,float h,float i,vec3 ik) {
  p0-=vec3(-w*.5,h,0);
  p0.xy*= rot(kr*(.01*i-.02));
  return min2(vec2(box0(p0,w*.45-.01,h-.01,h*.6,0.),15),
      vec2(max(box0(p0,w*.45-.03,h,h*.66,.03),-box(p0,0.,-.2,.05,w*.45-.06,h+.5,h*.66+.03,.03)),
      52.+50.*cos(112.*(5.*ik.z+10.*i+11.*ik.y+5.*cos(ik.x)))));
}

vec2 sdBezier(vec3 p,vec3 b0,vec3 b1,vec3 b2) {
  b0-=p;
  b1-=p;
  b2-=p;
  vec3 g,b01=cross(b0,b1),b12=cross(b1,b2),b20=cross(b2,b0),n=b01+b12+b20;
  float t,a=-dot(b20,n),b=-dot(b01,n),d=-dot(b12,n);
  g=(d-b)*b1+(b+a*.5)*b2+(-d-a*.5)*b0;
  t=clamp((a*.5+b-.5*(a*a*.25-b*d)*dot(g,b0-2.*b1+b2)/dot(g,g))/-dot(n,n),0.,1.);
  return vec2(length(mix(mix(b0,b1,t),mix(b1,b2,t),t)),t);
}

vec2 sdRobot(vec3 p0) {
    float d=length(p0),k2=smoothstep(89.,103.,iTime);
    if(d>3.1&&sh==0)
        return vec2(d-3.,10);
    vec3 p=p0;
    d=box0(p,.3,.6,.2,.1+.1*p.y);
    vec2 d2=sdBezier(p,vec3(0,.6,0),vec3(0,1.1,-.4),vec3(0,1.6,.2));
    p.x=abs(p.x);
    p.xz*=rot(-.2);
    d=min(d,box(p,.4,-1.8,1.3,.2,.12,.4,0.));
    d2=min2(d2,sdBezier(p,vec3(.2,-.6,0),vec3(.6,-.3,1.5),vec3(.4,-1.8,1)));
    d2=min2(d2,sdBezier(p,vec3(.3+.2*kr,.6,0),vec3(.9,-.3,-.5),vec3(.8,0,1.3)));
    d2+=vec2(-.08,cos(60.*d2.y)>.6?50.:25.);
    p=p0-vec3(0,1.9,.5);
    p.xy*=rot(.4*k2-.2);
    p.zy*=rot(smoothstep(80.,84.,iTime)-.5-.5*k2);
    p.xz*=rot(-1.6*k2);
    ph=p;
    vec2 res=vec2(box0(p,.9,.6,.5,0.),50.5);
    p.x=abs(p.x);
    d2=min2(d2,vec2(length(p-vec3(.75,0,0))-.3,25));
    
    float de=length(p-vec3(.3,-.05,.25))-.3;
    p=p0+vec3(0,0,-1.4);
    p.yz*=rot(-.7);
    if(iTime<79.)
        res=min2(res,sdBook(p));
    p.x=abs(p.x);
    p.xy*=rot(.2);
    return min2(min2(min2(res,vec2(min(d,box(p,1.,-.05,0.,.2,.15,.2,.05)),50)),vec2(de,-1)),d2);
}

vec2 sdMap(vec3 p0) {
    
    vec3 pl=p0,p00=p0,p=p0-vec3(-20,19.65,3);
    p.xz*=rot(.4);
    vec2 res0 = vec2(999,0), // ce qui disparait avec kr
         res=sdRobot(p);
    float hall=box(p0,5.,30.,5.,15.,30.,5.,0.),
          dr = length(p),
          tt = max(0.,iTime-80.);
    
    dr -= 5.*smoothstep(0.,18.,tt) + 5.1*max(0.,tt-18.5);
    kr = smoothstep(-1.,1.,dr);

    pl.y=mod(pl.y+10.,17.5)-10.;
    res0=min2(res0,vec2(max(-hall,box(pl,0.,.1,0.,999.,.1,999.,0.)),1));
    res0=min2(res0,vec2(sdStairs(p0-vec3(6.7,0,5)),.37));
    pl.x=mod(pl.x+1.5,3.)-1.5;
    res0=min2(res0,vec2(max(-hall,box(pl,0.,-.5,0.,.17,.45,999.,0.)),.3));
    pl=p0-vec3(10,0,-2.5);
    pl.xz=mod(pl.xz+36.,72.)-36.;
    pl.zy*=rot(-.2);
    pl.x-=18.;
    res0=min2(res0,vec2(sdLadder(pl),.3));

    p0.z=mod(p0.z+5.,10.)-5.;
    p=p0;
    vec2 k=kr*(.2+.1*cos(2.*p.xy)+.2*cos(.3*p.xy));
    res=min2(res,vec2(box(p,0.,15.8,0.,999.,.85-k.x,.65-k.x,k.x),.8));
    p.z=abs(p.z)-1.1;
    p.x=mod(p.x+6.,12.)-6.;
    res=min2(res,vec2(box0(p,.5-k.y,100.,.5-k.y,k.y),.5));
    res=min2(res,vec2(box0(p,.5,.3,.5,.1+.05*cos(6.*p.y)),8.5));
    res=min2(res,vec2(box(p,0.,16.8,0.,.45,.45,1e3,.2),.6));
    res0=min2(res0,vec2(box(p,0.,14.7,-.5,.2,.27,.6,.05),.5));
    res=min2(res,vec2(box(p,0.,14.7,0.,.7,0.,0.,.05),.3));
    p-=vec3(0,15.5,1.7);
    p.zy*=rot(.72);
    res0=min2(res0,vec2(box0(p,.17,.2,2.6,.1),.5));
    p.z=abs(p.z);
    res0=min2(res0,vec2(box(p,0.,0.,2.,.7,0.,0.,.05),.3));
    p=p0;
    p.z-=2.5;
    p.x=mod(p.x+30.,48.)-11.;
    p.y=mod(p.y+13.,17.5)-13.;
    res=min2(res,vec2(box(p,0.,1.4,0.,2.4,0.,.8,.1),.3));
    p.xz=abs(p.xz);
    p.xy*=rot(.1);
    res0=min2(res0,vec2(box(p,1.6,.6,.6,0.,.7,0.,.1),4.5)); // pied tabouret
    p=p0;
    p.x=mod(p.x+36.,72.)-36.;
    float dFloor=min(box(p,18.,0.,0.,6.01,1000.,1000.,0.), box(p00,0.,15.25,0.,1000.,2.2,1000.,0.));
    p=p0;
    p.y=mod(p.y+.3,2.5)-1.25;
    res=min2(res,vec2(max(-dFloor,box0(p,1e3,.1,.7,0.)),.8));
    p=p0;
    p.y=mod(p.y-.5,2.5)-.5;
    float c=floor(p.x),x=.04,
          iy=floor(p0.y/2.5),
          b=kr*.25*smoothstep(45.,90.,iTime);
    vec2 d=vec2(99,0),h;
    if(kr<.5 || iTime<77.) {
        for(float i=0.;i<7.;i++) {
            h = vec2(.1+.2*(1.-kr),.5)+kr*vec2(.1,.2)*hash22(vec2(i,c+10.*iy));
            if(x+h.x>=.98)
                break;
            x+=h.x;
            if(h.x>b)
                d=min2(d,book(p-vec3(c+x,0,0),h.x,h.y,i,vec3(c,iy,floor(p00.z+.5))));
        }
        d.x=max(min(d.x,p.x-c>.5?
        box(p,c+11.5,.7,0.,10.485,.7,.462,0.):
        box(p,c-10.5,.7,0.,10.485,.7,.462,0.)),-dFloor);
        d.x = kr<.5 ? max(d.x,dr+.5) : d.x;
    }

    res0.x = max(res0.x,-dr);
    return min2(res0, min2(res,d));
}


void main() {
  
  float[18] an=float[18](0.,10., 10.,20., 20.,35., 20.,40., 20.,47., 30.,55., 55.,65., 92.,99. ,99.,120.);
  float[30] aro=float[30](162.,8.,-85.,  162.,4.,-5.,  112.,4.,-8.,  92.,15.5,-7.,  94.,15.5,4., 10.,10.,5., -10.,24.,8., -23.,24.,9., -4.,25.,7.,  90.,1.2,4.5),
            ata=float[30](162.,4.5,-30.,170.,4.5,-7.,120.,3.5,-7.,90.,15.3,-5.,92.,14.,5.,0.,8.,5.,-20.,22.,5.,  -20.5,22.,5.,  -10.,21.,5., 84.,5.,8.);
 
  float t,
      m=.5*cos(.2*iTime);
 
  // Camera
  vec3 ro=vec3(aro[0],aro[1],aro[2]),
       ta=vec3(ata[0],ata[1],ata[2]);
       
  for(int j=1;j<10;j++)
      t=smoothstep(an[j*2-2],an[j*2-1],iTime),
      ro=mix(ro,vec3(aro[j*3],aro[j*3+1],aro[j*3+2]),t),
      ta=mix(ta,vec3(ata[j*3],ata[j*3+1],ata[j*3+2]),t);
  
  vec3 col = normalize(ta-ro),
       lig = normalize(cross(col,vec3(sin(m),cos(m),0))),
       rd = mat3(lig,normalize(cross(lig,col)),col)*normalize(vec3(p.xy,2));

  // Trace
    t=.3*hash22(rd.xy+9123.*rd.z).x;
    m=-1.;
    for(int i=0;i<128;i++){
        vec2 res=sdMap(ro+rd*t);
        if(res.x<1e-4*t||t>50.)
            break;
        t+=.9*res.x;
        m=res.y;
    }

    col=vec3(.7,.9,1);
    lig=normalize(vec3(-.4,.9,-.6));
       
    if(m>-.5) {
        // normal
        vec3 pos=ro+t*rd, ref, nor = vec3(0.,2.*max( .1 * t / 1270., .015 ),0.);

        float edge,
             d1=sdMap(pos-nor.yxx).x,d2=sdMap(pos+nor.yxx).x,
             d3=sdMap(pos-nor.xyx).x,d4=sdMap(pos+nor.xyx).x,
             d5=sdMap(pos-nor.xxy).x,d6=sdMap(pos+nor.xxy).x,
             d=sdMap(pos).x;
        nor = vec3(d2-d1,d4-d3,d6-d5);
        nor = normalize(nor - max(.0,dot(nor,rd))*rd); 
        ref = reflect(rd,nor);

        // edge
        edge=min(1.,15.*abs(d-.5*(d2+d1))+abs(d-.5*(d4+d3))+abs(d-.5*(d6+d5))); //edge finder

        // Color
        col=(.5+.3*sin(vec3(.05,.08,.1)*(m-1.)));

        if(m<.4)
            col=.15*texture_wood2(pos*vec3(.15,1.5,1.5));
        else if(m<.9)
            col=texture_wood2((m==.8? pos.zxy: m==.6? pos.yzx: pos)*.5*vec3(1.5,.15,1.5));
        else if(m<1.5)
            col=texture_wood(pos.zyx);
        else if(m==50.5||m==50.)
            ph=m==50.?pos:ph,
            col=mix(vec3(.01,.3,1),col,smoothstep(.5,.6,tex3D(ph*2.,nor)));
            
        nor=kr>0.?doBumpMap(30.*pos,nor):nor;

        sh=1;
        // shadow
        float h,ao=0.,sha=1.,tt=.02+.05*hash22(rd.xy+9123.*rd.z).x;
        for(int i=0;i<24;i++) {
          h=sdMap(pos+lig*tt).x;
          sha=min(sha,2.*h/tt);
          tt+=clamp(h,.02,.1);
          if(h<.001||tt>2.5)
            break;
        }
        
        // ambiant occlusion
        tt=1.;
        for(int i=0;i<5;i++)
            h=.02+.06*float(i),h-=sdMap(nor*h+pos).x,ao+=h*tt,tt*=.95;
            
        // shading
        lig = clamp(dot(nor,lig),0.,1.)*clamp(sha,0.,1.)*vec3(1.3,1,.7)+
                  pow(clamp(dot(ref,lig),0.,1.),16.)*vec3(1,.9,.7)+
                  clamp(1.-ao,0.,1.)*((
                      .4*clamp(.5+.5*nor.y,0.,1.)+
                      .5*smoothstep(-.1,.1,ref.y))*vec3(.4,.6,1)+
                  .25*pow(clamp(1.+dot(nor,rd),0.,1.),2.));
        // blur far
        col = mix(mix(edge*(6.+5.*cos(3.*iTime-length(pos-vec3(-20,19.65,3))))*vec3(.1,1,2)+.2, col, kr)*lig, vec3(.8,.9,1), smoothstep(10.,50.,t));
    }
    
    // end anim
    t=smoothstep(115.,125.,iTime);
    col=mix(clamp(col,0.,1.),vec3(.05,.5,1),.5*smoothstep(1.,1.3,fbm(2.5*p)+t));

    cl=vec4(pow(clamp(col*(1.-t),0.,1.),vec3(.57)),1);
}