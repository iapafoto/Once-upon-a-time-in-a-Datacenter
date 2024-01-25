// Generated with Shader Minifier 1.3.6 (https://github.com/laurentlb/Shader_Minifier/)
#ifndef SHADER_CODE_H_
# define SHADER_CODE_H_
# define VAR_cl "f"
# define VAR_iTime "v"

const char* input =
"#version 430\n"
"layout(location=0) uniform float v;"
"layout(location=0) out vec4 f;"
"float x=0.;"
"vec3 y=vec3(0);"
"int m=0;"
"float s(vec3 v,vec3 s,float y)"
"{"
"s=abs(v)-s;"
"return min(max(s.x,max(s.y,s.z)),0.)+length(max(s,0.))-x*y;"
"}"
"void s(inout vec2 m,vec2 x)"
"{"
"m=m.x<x.x?"
"m:"
"x;"
"}"
"vec2 s(vec2 v)"
"{"
"return fract(sin(vec2(dot(v,vec2(127.1,311.7)),dot(v,vec2(269.5,183.3))))*43758.5453);"
"}"
"float t(vec2 v)"
"{"
"vec2 m=floor(v);"
"v-=m;"
"v*=v*v*(v*v*6.-v*15.+10.);"
"return dot(mat2(fract(sin(mod(vec4(0,1,113,114)+dot(m,vec2(1,113)),6.2832))*43758.5))*vec2(1.-v.y,v.y),vec2(1.-v.x,v));"
"}"
"float n(vec2 v)"
"{"
"return t(v)*.533+t(v*2.)*.267+t(v*4.)*.133+t(v*8.)*.067;"
"}"
"float n(vec3 v,vec3 m,int x)"
"{"
"if(x<3)"
"v[x]-=.001;"
"m=max(m*m,.001);"
"m/=m.x+m.y+m.z;"
"return n(v.yz)*m.x+n(v.zx)*m.y+n(v.xy)*m.z;"
"}"
"void n(inout vec3 v,vec3 x)"
"{"
"x=(vec3(n(x,v,0),n(x,v,1),n(x,v,2))-n(x,v,3))/.002;"
"v=normalize(v+(x-v*dot(v,x))*.2);"
"}"
"mat2 p(float v)"
"{"
"return mat2(cos(v-vec4(0,1.57,11,0)));"
"}"
"vec3 p(vec3 v,int x)"
"{"
"v[x]*=.1;"
"vec3 y=sin(v*4.3+cos(v.yzx*6.7));"
"float m=dot(y+sin(y*13.)*.03,vec3(3)),s=1.-abs(dot(sin(v*120.5+m*6.283+sin(v.zxy*121.3)),vec3(.333)));"
"m=fract(m+fract(m*4.)*.1);"
"m=min(min(m,m*(1.-m)*6.)*.85+s*.2,1.);"
"return.3+.7*sqrt(mix(vec3(.5,.15,.025),vec3(.75,.3,.1)*2.,m*.75+.25))*(m*.6+.4);"
"}"
"vec3 d(vec3 v)"
"{"
"vec2 m=vec2(6,.8),x;"
"v.x+=mod(round(v.z/.8),2.)*3.;"
"x=m*round(v.xz/m);"
"float y=s(x*80.+9600.).x;"
"v.xz-=x;"
"return p((v+y)*.7,0)*(.1+.9*smoothstep(0.,-.02,s(vec3(v.xz,0),vec3(m.xy*.5,49),0.)))*(.5+.5*y);"
"}"
"float r(vec2 v)"
"{"
"ivec2 m=ivec2(v*80.),s=m;"
"m.y=(86-m.y)%8+1;"
"return abs(s.x)<33&&abs(s.y+2)<53&&(219*(m.y>4?"
"614081:"
"4840434)&1<<abs((m.x+86)%13-7)-m.y*8)>0?"
"1.:"
"1.5;"
"}"
"void d(inout vec2 v,vec3 m,vec3 x,vec3 y,vec3 c)"
"{"
"x-=m;"
"y-=m;"
"c-=m;"
"vec3 p=cross(x,y),f=cross(y,c),i=cross(c,x),z=p+f+i;"
"float r=dot(i,z),d=-dot(p,z),l=-dot(f,z);"
"m=(l-d)*y+(d-r*.5)*c-(l-r*.5)*x;"
"r=clamp((d-.5*(r*r*.25-d*l)*dot(m,x-2.*y+c)/dot(m,m)-r*.5)/-dot(z,z),0.,1.);"
"s(v,vec2(length(mix(mix(x,y,r),mix(y,c,r),r))-.08,cos(60.*r)>.6?"
"50:"
"25));"
"}"
"vec2 d(vec3 c,float r)"
"{"
"float f=length(c),z=smoothstep(91.,1e2,v);"
"if(f>3.1&&m==0)"
"return vec2(f-3.,10);"
"vec3 i=c,l=c,n;"
"f=s(i,vec3(.3,.6,.2),.1+.1*i.y);"
"vec2 t=vec2(999);"
"d(t,i,vec3(0,.6,0),vec3(0,1.1,-.4),vec3(0,1.6,.2));"
"i.x=abs(i.x);"
"i.zx*=p(.2);"
"f=min(f,s(i-vec3(.4,-1.8,1.3),vec3(.2,.12,.4),0.));"
"d(t,i,vec3(.2,-.6,0),vec3(.6,-.3,1.5),vec3(.4,-1.8,1));"
"d(t,i,vec3(.3+.2*x,.6,0),vec3(1.-.2*r,-.8,-.2),vec3(.95-.95*r,-.07-.1*r,1.3));"
"i=c-vec3(0,1.9,.5);"
"i.xy*=p(.4*z-.2);"
"i.zy*=p(smoothstep(68.,72.,v)-.5-.5*z);"
"i.zx*=p(1.6*z);"
"y=i;"
"s(t,vec2(s(i,vec3(.9,.6,.5),0.),4));"
"i.x=abs(i.x);"
"s(t,vec2(length(i-vec3(.75,0,0))-.3,25));"
"s(t,vec2(length(i-vec3(.3,-.05,.25))-.3,-1.-r));"
"c.z-=1.4;"
"c.zy*=p(.7);"
"c.x=abs(c.x);"
"i=c;"
"i.yx*=p(1.26);"
"n=i-vec3(.2,1.19-r,-.18);"
"n.yx*=p(.5);"
"f=min(f,s(n,vec3(.15,.05,.1),.05));"
"f=min(f,s(n-vec3(-.09,.03,.25),vec3(.07,.03,.16),.02));"
"n.yz*=p(.5);"
"f=min(f,s(n-vec3(.1,.08,.2),vec3(.07,.03,.16),.02));"
"n.xy*=p(.3);"
"n.xz*=p(1.);"
"f=min(f,s(n-vec3(-.16,.05,.2),vec3(.06,.04,.12),.02));"
"s(t,vec2(f,5));"
"if(v<67.&&m==0)"
"{"
"z=s(c-vec3(0,-.1-.03*cos(9.*c.x),0),vec3(.2,.018,.8),.01);"
"if(l.y<.8)"
"y=i;"
"z=min(z,s(i-vec3(.12,.5+i.x*1.256,0),vec3(0,.5,.8),.018));"
"i.y-=.5+i.x*1.256;"
"s(t,vec2(z,48));"
"s(t,vec2(.8*s(i-vec3(.01+sin(i.y*6.9+5.7)*.027/(1.+i.y),0,0),vec3(.06,.48,.78),0.),7));"
"}"
"return t;"
"}"
"void n(inout vec2 v,vec3 m,float y,float z,float c)"
"{"
"m-=vec3(-y*.5,z+.07,0);"
"y=y*.5-.015;"
"m.x=abs(m.x);"
"float f=s(m-vec3(y,0,0),vec3(0,z,z*.7),.01);"
"m.z-=x*.04*cos(m.x/y)-.019;"
"s(v,vec2(s(m-vec3(0,0,.015),vec3(y,z*.95+.002*cos(6e2*m.x),z*.65),0.),15));"
"s(v,vec2(min(f,s(m-vec3(0,0,z*.7+.01-.02*(.3+cos(2.*max(.9,cos(14.*m.y/z))))),vec3(y-.015,z,0),.015)),c*c*c*c));"
"}"
"vec2 c(vec3 i)"
"{"
"vec3 y=i,f=i-vec3(-20,19.65,3);"
"f.xz*=p(.4);"
"float c,z=s(i-vec3(5,31,5),vec3(15,30,5),0.),r=max(0.,v-80.),l=length(f-vec3(0,2,0))-10.*smoothstep(0.,18.,r)-5.1*max(0.,r-19.),t=clamp((80.-v)/15.,0.,1.);"
"t=pow(9.,-15.*t)*cos(t*30.);"
"y.y=mod(y.y+10.,17.5)-10.;"
"vec2 a,C=vec2(max(-z,s(y-vec3(0,.1,0),vec3(999,.1,999),0.)),3),o=d(f,t);"
"x=smoothstep(-1.,1.,l);"
"f=i-vec3(6.7,0,5);"
"f.xy*=p(.785);"
"f.z=abs(f.z);"
"f.y-=clamp(round(f.y),0.,24.);"
"f.yx*=p(.785);"
"s(C,vec2(min(s(f,vec3(.45,.5,3),.05),max(-z,s(y-vec3(3.*round(y.x/3.),-.5,0),vec3(.17,.45,999),0.))),2.3));"
"f=i-vec3(82,0,-2.6);"
"f.zy*=p(-.2);"
"f.x=abs(f.x);"
"s(C,vec2(min(s(f-vec3(0,clamp(round(f.y),0.,8.),0),vec3(.75,0,0),.04),s(f-vec3(.75,4.6,0),vec3(.05,4.4,.1),0.)),.3));"
"z=s(i-vec3(0,15.25,0),vec3(999,2.2,999),0.);"
"y=i;"
"y.y=y.y/.25+1.;"
"y=round(y*.1);"
"i.z-=y.z/.1;"
"f=i;"
"a=x*(.2+.1*cos(2.*f.xy)+.2*cos(.3*f.xy));"
"s(o,vec2(s(f-vec3(0,15.8,0),vec3(999,.85-a.x,.65-a.x),a.x),.99));"
"f.z=abs(f.z)-1.1;"
"f.x=mod(f.x+6.,12.)-6.;"
"s(o,vec2(s(f,vec3(.5),.2-.2*f.y),9));"
"s(o,vec2(s(f,vec3(.5-a.y,100,.5-a.y),a.y),1));"
"s(o,vec2(s(f-vec3(0,16.8,0),vec3(.45,.45,1e3),.2),2));"
"s(C,vec2(s(f-vec3(0,14.7,0),vec3(.6,0,0),.05),1.5));"
"s(C,vec2(s(f-vec3(0,14.7,-.5),vec3(.2,.27,.6),.05),2));"
"f-=vec3(0,15.5,1.7);"
"f.yz*=p(-.72);"
"s(C,vec2(s(f,vec3(.17,.2,2.5),.1),1));"
"f.z=abs(f.z);"
"s(C,vec2(s(f-vec3(0,0,2),vec3(.7,0,0),.05),1.5));"
"f=i;"
"f.z-=2.5;"
"f.x=mod(f.x+30.,48.)-11.;"
"f.y=mod(f.y+13.,17.5)-13.;"
"s(o,vec2(s(f-vec3(0,1.4,0),vec3(2.4,0,.8),.1),.15));"
"f.xz=abs(f.xz);"
"f.xy*=p(.1);"
"s(C,vec2(s(f-vec3(1.6,.6,.6),vec3(0,.7,0),.1),8));"
"C.x=max(C.x,-l);"
"s(o,C);"
"z=min(z,s(i-vec3(18.+72.*round(i.x/72.),0,0),vec3(6.01,999,999),0.));"
"f=i;"
"f.y=mod(f.y+.27,2.5)-1.25;"
"s(o,vec2(max(-z,s(f,vec3(1e3,.07,.7),0.)),.99));"
"f.y=mod(i.y-1.,2.5);"
"c=floor(f.x);"
"if(x<.5||v<85.)"
"{"
"C=vec2(m==0?"
"f.x-c>.5?"
"s(f-vec3(c+11.5,.75,0),vec3(10.48,.8,.7),0.):"
"s(f-vec3(c-10.5,.8,0),vec3(10.48,.8,.7),0.):"
"999.,0);"
"f.x-=c;"
"for(r=.02;r<=.97;)"
"{"
"a=vec2(1.-.87*x,.38)+x*vec2(.2,.3)*s(y.zy+vec2(r,c));"
"a.x=min(a.x,.98-r);"
"r+=a.x;"
"if(a.x>.12+.5*x*t)"
"n(C,f-vec3(r,0,0),a.x,a.y,2.+s(a+c).x);"
"}"
"C.x=max(max(C.x,-z),x<.5?"
"l+.5:"
"0.);"
"s(o,C);"
"}"
"return o;"
"}"
"vec3 c(vec3 f,vec3 i)"
"{"
"float z=1.,t,C,a=.2*s(i.xy+912.*i.z).x,l=.01;"
"vec2 o=vec2(999);"
"for(int u=0;++u<200&&o.x>a/1e4&&a<50.;)"
"o=c(f+i*a),a+=.9*o.x;"
"C=o.y;"
"if(C<0.)"
"return vec3(.7,.9,1)*(C<-1.2&&C>-2.?"
"s(vec2(C)).x-.5:"
"1.);"
"f+=a*i;"
"vec3 u=vec3(0,max(1e-4*a,.03-x*.02),0),F=vec3(c(f-u.yxx).x,c(f-u.xyx).x,c(f-u.xxy)),e=vec3(c(f+u.yxx).x,c(f+u.xyx).x,c(f+u.xxy)),G=e-F+.001;"
"G=normalize(G-max(.001,dot(G,i))*i);"
"u=reflect(i,G);"
"e=15.*abs(o.x-.5*(e+F));"
"t=min(1.,e.x+e.y+e.z);"
"e=.5+.3*sin(vec3(.05,.08,.1)*(C-1.));"
"y=C==4.||C==7.?"
"y:"
"f;"
"e=C<3.?"
"fract(C+.99)*p(f,int(C)):"
"C==3.?"
".4+.6*vec3(d(f).x):"
"C==4.||C==5.?"
"mix(vec3(.01,.3,1),vec3(.6,.3,.1),smoothstep(.6,.7,n(y*2.,G,3))):"
"C==7.?"
"vec3(r(y.yz-vec2(.46,.05))):"
"e;"
"if(x>0.)"
"n(G,30.*y);"
"F=vec3(.27,.6,.58);"
"m=1;"
"for(int E=0;++E<28&&C>.001&&l<2.5;)"
"C=c(f+F*l).x,z=min(z,2.*C/l),l+=clamp(C,.02,.1);"
"l=1.05;"
"C=1.;"
"for(float E=.02;E<.32;E+=.06)"
"E-=(E-c(f+G*E).x)*(l*=.95);"
"F=.1+(.5*clamp(C,0.,1.)+.5)*dot(G,F)*clamp(z,0.,1.)*vec3(1.3,1,.6)+4.*pow(clamp(dot(u,F),0.,1.),46.)*vec3(1,.9,.7)+.25*pow(clamp(1.+dot(G,i),0.,1.),2.)+vec3(.025,.12,.25)*max(0.,dot(i,reflect(vec3(.97,0,.24),G)));"
"return mix(mix(.2+t*(2.+cos(3.*v))*vec3(.1,1,2),e,x)*F,mix(vec3(1.5,.9,.75),vec3(.2,.3,.5),x),smoothstep(10.,50.,a));"
"}"
"void main()"
"{"
"vec2 m=vec2(1280,720),i=gl_FragCoord.xy,x=(i+i-m)/m.y;"
"i/=m;"
"int[18] y=int[18](0,10,10,20,20,35,20,40,20,47,30,55,55,65,92,99,99,130);"
"int[30] z=int[30](95,8,80,95,6,-7,112,15,-5,92,15,-8,94,17,2,8,5,8,-10,24,4,-23,24,9,-4,25,7,140,4,4),C=int[30](80,6,28,80,5,-7,111,9,-12,90,15,-5,92,17,8,0,9,5,-16,21,5,-20,21,5,-10,23,7,135,3,9);"
"float r;"
"vec3 t,l=vec3(z[0],z[1],z[2]),o=vec3(C[0],C[1],C[2]);"
"for(int a=0;a<9;a++)"
"r=smoothstep(float(y[a*2]),float(y[a*2+1]),v),l=mix(l,vec3(z[a*3+3],z[a*3+4],z[a*3+5]),r),o=mix(o,vec3(C[a*3+3],C[a*3+4],C[a*3+5]),r);"
"r=.5*cos(.2*v);"
"t=normalize(o-l);"
"o=normalize(cross(t,vec3(sin(r),cos(r),0)));"
"o=mat3(o,normalize(cross(o,t)),t)*normalize(vec3(x+(v>99.?"
".01*s(x-x+v).x:"
"0.),2));"
"r=smoothstep(125.,132.,v);"
"f=vec4(pow(clamp(mix(c(l,o),vec3(.1,1,2),.5*smoothstep(1.,1.3,n(2.5*x)+r))*(1.-r),0.,1.),vec3(.6))*4.*sqrt(i.x*i.y*(1.-i.x)*(1.-i.y)),1);"
"}";

#endif // SHADER_CODE_H_
