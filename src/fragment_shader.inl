/* File generated with Shader Minifier 1.1.4
 * http://www.ctrl-alt-test.fr
 */
#ifndef FRAGMENT_SHADER_INL_
#define FRAGMENT_SHADER_INL_

const char* fsh =
"#version 430\n"
"layout(location=0) uniform float v;layout(location=0) out vec4 x;in vec2 i;\n"
"#define V(p,bx,by,bz,e)s(p,vec3(bx,by,bz),e)\n"
"#define W(p,x,y,z,bx,by,bz,e)s(p-vec3(x,y,z),vec3(bx,by,bz),e)\n"
"float m=0.;vec3 z=vec3(0);int b=0;float s(vec3 v,vec3 x,float z){x=abs(v)-x;return min(max(x.x,max(x.y,x.z)),0.)+length(max(x,0.))-m*z;}vec2 s(vec2 x,vec2 z){return x.x<z.x?x:z;}vec2 s(vec2 v){v=fract(v*vec2(5.398,5.443));v+=dot(v.yx,v+vec2(21.535,14.3137));return fract(v.x*v.y*vec2(95.434,97.597));}float t(vec2 v){vec2 x=floor(v);v-=x;v*=v*v*(v*v*6.-v*15.+10.);return dot(mat2(fract(sin(mod(vec4(0,1,113,114)+dot(x,vec2(1,113)),6.2832))*43758.5))*vec2(1.-v.y,v.y),vec2(1.-v.x,v));}float n(vec2 v){return t(v)*.533+t(v*2.)*.267+t(v*4.)*.133+t(v*8.)*.067;}float n(vec3 v,vec3 x){x=max(x*x,.001);x/=x.x+x.y+x.z;return n(v.yz)*x.x+n(v.zx)*x.y+n(v.xy)*x.z;}vec3 t(vec3 v,vec3 x){v=(vec3(n(vec3(v.x-.001,v.yz),x),n(vec3(v.x,v.y-.001,v.z),x),n(vec3(v.xy,v.z-.001),x))-n(v,x))/.002;return normalize(x+(v-x*dot(x,v))*.1);}mat2 p(float v){float x=cos(v),y=sin(v);return mat2(x,y,-y,x);}vec3 d(vec3 v){vec3 x=v;v=sin(v*4.3+cos(v.yzx*6.7));float y=dot(v+sin(v*13.)*.03,vec3(3)),b=1.-abs(dot(sin(x*120.5+y*6.283+sin(x.zxy*121.3)),vec3(.333)));y=fract(y+fract(y*4.)*.1);y=min(min(y,y*(1.-y)*6.)*.85+b*.2,1.);return.3+.7*sqrt(mix(vec3(.5,.15,.025),vec3(.75,.3,.1)*2.,y*.75+.25))*(y*.6+.4);}vec3 f(vec3 v){vec2 x=vec2(6,.8),m;v.z+=mod(round(v.x/.8),2.)*3.;m=x*round(v.zx/x);float z=s(m*80.+9600.).x;v.zx-=m;return d((v+z)*.7*vec3(1,1,.1))*(.1+.9*smoothstep(0.,-.02,V(vec3(v.zx,0),x.x*.5,x.y*.5,49,0.)))*(.5+.5*z);}vec2 d(vec3 v,vec3 x,vec3 y,vec3 m){x-=v;y-=v;m-=v;vec3 p=cross(x,y),b=cross(y,m),z=cross(m,x),r=p+b+z;float f,c=-dot(z,r),d=-dot(p,r),s=-dot(b,r);v=(s-d)*y+(d+c*.5)*m-(s+c*.5)*x;f=clamp((c*.5+d-.5*(c*c*.25-d*s)*dot(v,x-2.*y+m)/dot(v,v))/-dot(r,r),0.,1.);return vec2(length(mix(mix(x,y,f),mix(y,m,f),f)),f);}vec2 a(vec3 x){float y=length(x),r=smoothstep(91.,1e2,v);if(y>3.1&&b==0)return vec2(y-3.,10);vec3 f=x;y=V(f,.3,.6,.2,.1+.1*f.y);vec2 c=d(f,vec3(0,.6,0),vec3(0,1.1,-.4),vec3(0,1.6,.2));f.x=abs(f.x);f.xz*=p(-.2);y=min(y,W(f,.4,-1.8,1.3,.2,.12,.4,0.));c=s(c,d(f,vec3(.2,-.6,0),vec3(.6,-.3,1.5),vec3(.4,-1.8,1)));c=s(c,d(f,vec3(.3+.2*m,.6,0),vec3(1,-.8,-.2),vec3(.9,0,1.2)));c+=vec2(-.08,cos(60.*c.y)>.6?50.:25.);f=x-vec3(0,1.9,.5);f.xy*=p(.4*r-.2);f.zy*=p(smoothstep(80.,84.,v)-.5-.5*r);f.xz*=p(-1.6*r);z=f;c=s(c,vec2(V(f,.9,.6,.5,0.),50.5));f.x=abs(f.x);c=s(c,vec2(length(f-vec3(.75,0,0))-.3,25));c=s(c,vec2(length(f-vec3(.3,-.05,.25))-.3,-1));f=x+vec3(0,0,-1.4);f.yz*=p(-.7);f.x=abs(f.x);x=f;f.yx*=p(1.26);c=s(c,vec2(min(y,W(f,.1,1,-.2,.15,.2,.2,.05)),50));if(v<79.&&b==0)r=W(x,0,-.1-.03*cos(9.*x.x),0,.2,.018,.8,.01),r=min(r,W(f,.12,.5+f.x*1.256,0,0,.5,.8,.018)),x=f,f.y-=.5+f.x*1.256,c=s(c,s(vec2(r,48),vec2(.8*W(f,.01+sin(f.y*6.9+5.7)*.027/(1.+f.y),0,0,.06,.48,.78,0.),3)));return c;}float c(vec2 v){ivec2 f=ivec2(v*32.)-1;f.x=abs(f.x);return f.x<7&&f.y>-1&&f.y<8&&(219*(f.y>3?614081:4840434)&1<<f.x+f.y*8)>0?.5:2.;}vec2 a(vec3 v,float x,float y,float z){v.z*=-1.;v-=vec3(-x*.5,y+.07,0);x=x*.5-.015;v.x=abs(v.x);float f=W(v,x,0,0,0,y,y*.7,.01);v.z+=m*.03*cos(v.x/x)-.01;return s(vec2(W(v,0,0,-.015,x,y*.95+.002*cos(6e2*v.x),y*.65,0.),15),vec2(min(f,W(v,0,0,-y*.7-.01+.02*(.3+cos(2.*max(.9,cos(14.*v.y/y)))),x-.015,y,0,.015)),z*z*z*z));}vec2 r(vec3 x){vec3 f=x,y=x-vec3(-20,19.65,3);y.xz*=p(.4);vec2 c=vec2(999,0),r=a(y);float z=W(x,5,30,5,15,30,5,0.),d=length(y-vec3(0,2,0)),i=max(0.,v-80.);d-=5.*smoothstep(0.,18.,i)+5.1*max(0.,i-18.5);m=smoothstep(-1.,1.,d);f.y=mod(f.y+10.,17.5)-10.;c=s(c,vec2(max(-z,W(f,0,.1,0,999,.1,999,0.)),1));y=x-vec3(6.7,0,5);y.xy*=p(.785);y.z=abs(y.z);i=W(y,0,0,3,1.2,24,.05,0.);y.y-=clamp(round(y.y),0.,24.);y.yx*=p(.785);c=s(c,vec2(min(i,V(y,.45,.5,3,.05)),.37));f.x=mod(f.x+1.5,3.)-1.5;c=s(c,vec2(max(-z,W(f,0,-.5,0,.17,.45,999,0.)),.3));f=x-vec3(10,0,-2.5);f.xz=mod(f.xz+36.,72.)-36.;f.zy*=p(-.2);f.x-=18.;y=f;y.y-=clamp(round(y.y),0.,9.);y.x-=clamp(y.x,-.8,.8);f.x=abs(f.x)-.75;f.y-=clamp(f.y,0.,10.);c=s(c,vec2(min(length(y)-.07,length(f)-.1),.3));z=W(x,0,15.25,0,999,2.2,999,0.);x.z=mod(x.z+5.,10.)-5.;y=x;vec2 e,l=m*(.2+.1*cos(2.*y.xy)+.2*cos(.3*y.xy));r=s(r,vec2(W(y,0,15.8,0,999,.85-l.x,.65-l.x,l.x),.8));y.z=abs(y.z)-1.1;y.x=mod(y.x+6.,12.)-6.;r=s(r,vec2(V(y,.5-l.y,100,.5-l.y,l.y),.5));r=s(r,vec2(V(y,.5,.3,.5,.1+.05*cos(6.*y.y)),8.5));r=s(r,vec2(W(y,0,16.8,0,.45,.45,1e3,.2),.6));r=s(r,vec2(W(y,0,14.7,0,.7,0,0,.05),.3));c=s(c,vec2(W(y,0,14.7,-.5,.2,.27,.6,.05),.5));y-=vec3(0,15.5,1.7);y.zy*=p(.72);c=s(c,vec2(V(y,.17,.2,2.6,.1),.5));y.z=abs(y.z);c=s(c,vec2(W(y,0,0,2,.7,0,0,.05),.3));y=x;y.z-=2.5;y.x=mod(y.x+30.,48.)-11.;y.y=mod(y.y+13.,17.5)-13.;r=s(r,vec2(W(y,0,1.4,0,2.4,0,.8,.1),.3));y.xz=abs(y.xz);y.xy*=p(.1);c=s(c,vec2(W(y,1.6,.6,.6,0,.7,0,.1),4.5));y=x;y.x=mod(y.x+36.,72.)-36.;z=min(z,W(y,18,0,0,6.01,999,999,0.));y=x;y.y=mod(y.y+.27,2.5)-1.25;r=s(r,vec2(max(-z,V(y,1e3,.07,.7,0.)),.8));y.y=mod(x.y-1.,2.5);float n=floor(y.x),t=floor((x.y-.5)/2.5),B=.1+m*.5*smoothstep(65.,88.,v);e=vec2(999,0);if(m<.5||v<77.){if(b==0)e=vec2(y.x-n>.5?W(y,n+11.5,.75,0,10.485,.8,.7,0.):W(y,n-10.5,.8,0,10.485,.8,.7,0.),0);y.x-=n;for(i=0.;i<=.98;){l=vec2(.1+.9*(1.-m),.4)+m*vec2(.2,.3)*s(vec2(i,n+t));l.x=min(l.x,1.-i);i+=l.x;if(l.x>B)e=s(e,a(y-vec3(i,0,0),l.x,l.y,2.+s(l+n).x));}e.x=max(e.x,-z);e.x=m<.5?max(e.x,d+.5):e.x;}c.x=max(c.x,-d);return s(c,s(r,e));}vec3 a(vec3 y,vec3 x){float i=0.,e=1.,l,a,B=.3*s(x.xy+912.*x.z).x,g=.1;vec2 k;for(int o=0;o<128;o++){k=r(y+x*B);if(k.x<1e-4*B||B>50.)break;B+=.9*k.x;}a=k.y;if(a<-.5)return vec3(.7,.9,1);y+=B*x;vec3 o,C,D,A=vec3(0,max(8e-4*B,.03-m*.02),0);D=vec3(r(y-A.yxx).x,r(y-A.xyx).x,r(y-A.xxy));o=vec3(r(y+A.yxx).x,r(y+A.xyx).x,r(y+A.xxy));A=o-D;A=normalize(A-max(0.,dot(A,x))*x);C=reflect(x,A);o=15.*abs(k.x-.5*(o+D));l=min(1.,o.x+o.y+o.z);o=.5+.3*sin(vec3(.05,.08,.1)*(a-1.));if(a<.4)o=.15*d(y*vec3(.15,1.5,1.5));else if(a<.9)o=d((a==.8?y.zxy:a==.6?y.yzx:y)*vec3(.75,.075,.75));else if(a<1.5)o=.4+.6*vec3(f(y.zyx).x);else if(a==50.5||a==50.)o=mix(vec3(.01,.3,1),o,smoothstep(.6,.7,n((a==50.?y:z)*2.,A)));else if(a==3.)o*=c(.6*(y.xz-vec2(-20.9,4))*p(.5));A=m>0.?t(30.*y,A):A;D=normalize(vec3(.347,.78,.752)),b=1;for(int u=0;u<24;u++){a=r(y+D*g).x;e=min(e,2.*a/g);g+=clamp(a,.02,.1);if(a<.001||g>2.5)break;}g=1.05;for(int u=0;u<5;u++)a=.02+.06*float(u),a-=r(y+A*a).x,i+=a*(g*=.95);D=.1+(.5*clamp(1.-i,0.,1.)+.5)*dot(A,D)*clamp(e,0.,1.)*vec3(1.3,1,.6)+4.*pow(clamp(dot(C,D),0.,1.),46.)*vec3(1,.9,.7)+.25*pow(clamp(1.+dot(A,x),0.,1.),2.);D+=vec3(.05,.25,.5)*pow(max(0.,dot(x,reflect(normalize(vec3(.8,0,.2)),A))),5.);return mix(mix(.2+l*(2.+cos(3.*v))*vec3(.1,1,2),o,m)*D,mix(1.5*vec3(1,.6,.5),vec3(.2,.3,.5),m),smoothstep(10.,50.,B));}"
"void main(){vec2 y=vec2(1280,720),f=(2.*gl_FragCoord.xy-y)/y.y;int[18] c=int[18](0,10,10,20,20,35,20,40,20,47,30,55,55,65,92,99,99,135);int[30] r=int[30](158,8,85,162,4,-5,112,4,-8,92,16,-7,94,15,4,10,10,5,-10,24,4,-23,24,9,-4,25,7,165,1,4),m=int[30](158,4,30,170,5,-7,120,3,-7,90,15,-5,92,14,5,0,8,5,-16,21,5,-20,21,5,-10,22,5,159,5,8);float z;vec3 i,b=vec3(r[0],r[1],r[2]),e=vec3(m[0],m[1],m[2]);for(int o=0;o<9;o++)z=smoothstep(float(c[o*2]),float(c[o*2+1]),v),b=mix(b,vec3(r[o*3+3],r[o*3+4],r[o*3+5]),z),e=mix(e,vec3(m[o*3+3],m[o*3+4],m[o*3+5]),z);z=.5*cos(.2*v);i=normalize(e-b);e=normalize(cross(i,vec3(sin(z),cos(z),0)));if(v>99.)f+=.03*s(f-f+v);e=mat3(e,normalize(cross(e,i)),i)*normalize(vec3(f.xy,2));i=a(b,e);z=smoothstep(125.,135.,v);i=pow(clamp(mix(i,vec3(.1,1,2),.5*smoothstep(1.,1.3,n(2.5*f)+z))*(1.-z),0.,1.),vec3(.57));f=gl_FragCoord.xy/y;x=vec4(i*sqrt(16.*f.x*f.y*(1.-f.x)*(1.-f.y)),1);}";
#endif // FRAGMENT_SHADER_INL_

