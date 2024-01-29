// Generated with Shader Minifier 1.3.6 (https://github.com/laurentlb/Shader_Minifier/)
#ifndef SHADER_CODE_H_
# define SHADER_CODE_H_

const char* input =
"#version 430\n"
"layout(location=0) uniform float v;"
"layout(location=0) out vec4 r;"
"float m=0.;"
"vec3 g=vec3(0);"
"int i=0;"
"float s(vec3 v,vec3 r,float g)"
"{"
"r=abs(v)-r;"
"return min(max(r.r,max(r.g,r.b)),0.)+length(max(r,0.))-m*g;"
"}"
"void s(inout vec2 r,vec2 g)"
"{"
"r=r.r<g.r?"
"r:"
"g;"
"}"
"vec2 s(vec2 r)"
"{"
"return fract(sin(vec2(dot(r,vec2(127.1,311.7)),dot(r,vec2(269.5,183.3))))*43758.5453);"
"}"
"float t(vec2 v)"
"{"
"vec2 m=floor(v);"
"v-=m;"
"v*=v*v*(v*v*6.-v*15.+10.);"
"return dot(mat2(fract(sin(mod(vec4(0,1,113,114)+dot(m,vec2(1,113)),6.2832))*43758.5))*vec2(1.-v.g,v.g),vec2(1.-v.r,v));"
"}"
"float n(vec2 v)"
"{"
"return t(v)*.533+t(v*2.)*.267+t(v*4.)*.133+t(v*8.)*.067;"
"}"
"float n(vec3 v,vec3 m,int r)"
"{"
"if(r<3)"
"v[r]-=.001;"
"m=max(m*m,.001);"
"m/=m.r+m.g+m.b;"
"return n(v.gb)*m.r+n(v.br)*m.g+n(v.rg)*m.b;"
"}"
"void n(inout vec3 v,vec3 r)"
"{"
"r=(vec3(n(r,v,0),n(r,v,1),n(r,v,2))-n(r,v,3))/.002;"
"v=normalize(v+(r-v*dot(v,r))*.2);"
"}"
"mat2 x(float v)"
"{"
"return mat2(cos(v-vec4(0,1.57,11,0)));"
"}"
"vec3 t(vec3 v,int r)"
"{"
"v[r]*=.1;"
"vec3 g=sin(v*4.3+cos(v.gbr*6.7));"
"float m=dot(g+sin(g*13.)*.03,vec3(3)),s=1.-abs(dot(sin(v*120.5+m*6.283+sin(v.brg*121.3)),vec3(.333)));"
"m=fract(m+fract(m*4.)*.1);"
"m=min(min(m,m*(1.-m)*6.)*.85+s*.2,1.);"
"return.3+.7*sqrt(mix(vec3(.5,.15,.025),vec3(.75,.3,.1)*2.,m*.75+.25))*(m*.6+.4);"
"}"
"vec3 d(vec3 v)"
"{"
"vec2 m=vec2(6,.8),r;"
"v.r+=mod(round(v.b/.8),2.)*3.;"
"r=m*round(v.rb/m);"
"float g=s(r*80.+9600.).r;"
"v.rb-=r;"
"return t((v+g)*.7,0)*(.1+.9*smoothstep(0.,-.02,s(vec3(v.rb,0),vec3(m.rg*.5,49),0.)))*(.5+.5*g);"
"}"
"float p(vec2 v)"
"{"
"ivec2 m=ivec2(v*80.),r=m;"
"m.g=(86-m.g)%8+1;"
"return abs(r.r)<33&&abs(r.g+2)<53&&(219*(m.g>4?"
"614081:"
"4840434)&1<<abs((m.r+86)%13-7)-m.g*8)>0?"
"1.:"
"1.5;"
"}"
"void d(inout vec2 v,vec3 r,vec3 m,vec3 g,vec3 f)"
"{"
"m-=r;"
"g-=r;"
"f-=r;"
"vec3 i=cross(m,g),c=cross(g,f),d=cross(f,m),b=i+c+d;"
"float l=dot(d,b),n=-dot(i,b),p=-dot(c,b);"
"r=(p-n)*g+(n-l*.5)*f-(p-l*.5)*m;"
"l=clamp((n-.5*(l*l*.25-n*p)*dot(r,m-2.*g+f)/dot(r,r)-l*.5)/-dot(b,b),0.,1.);"
"s(v,vec2(length(mix(mix(m,g,l),mix(g,f,l),l))-.08,cos(60.*l)>.6?"
"50:"
"25));"
"}"
"vec2 d(vec3 r,float b)"
"{"
"float f=length(r),c=smoothstep(91.,1e2,v);"
"if(f>3.1&&i==0)"
"return vec2(f-3.,10);"
"vec3 l=r,n=r,p;"
"f=s(l,vec3(.3,.6,.2),.1+.1*l.g);"
"vec2 t=vec2(999);"
"d(t,l,vec3(0,.6,0),vec3(0,1.1,-.4),vec3(0,1.6,.2));"
"l.r=abs(l.r);"
"l.br*=x(.2);"
"f=min(f,s(l-vec3(.4,-1.8,1.3),vec3(.2,.12,.4),0.));"
"d(t,l,vec3(.2,-.6,0),vec3(.6,-.3,1.5),vec3(.4,-1.8,1));"
"d(t,l,vec3(.3+.2*m,.6,0),vec3(1.-.2*b,-.8,-.2),vec3(.95-.95*b,-.07-.1*b,1.3));"
"l=r-vec3(0,1.9,.5);"
"l.rg*=x(.4*c-.2);"
"l.bg*=x(smoothstep(68.,72.,v)-.5-.5*c);"
"l.br*=x(1.6*c);"
"g=l;"
"s(t,vec2(s(l,vec3(.9,.6,.5),0.),4));"
"l.r=abs(l.r);"
"s(t,vec2(length(l-vec3(.75,0,0))-.3,25));"
"s(t,vec2(length(l-vec3(.3,-.05,.25))-.3,-1.-b));"
"r.b-=1.4;"
"r.bg*=x(.7);"
"r.r=abs(r.r);"
"l=r;"
"l.gr*=x(1.26);"
"p=l-vec3(.2,1.19-b,-.18);"
"p.gr*=x(.5);"
"f=min(f,s(p,vec3(.15,.05,.1),.05));"
"f=min(f,s(p-vec3(-.09,.03,.25),vec3(.07,.03,.16),.02));"
"p.gb*=x(.5);"
"f=min(f,s(p-vec3(.1,.08,.2),vec3(.07,.03,.16),.02));"
"p.rg*=x(.3);"
"p.rb*=x(1.);"
"f=min(f,s(p-vec3(-.16,.05,.2),vec3(.06,.04,.12),.02));"
"s(t,vec2(f,5));"
"if(v<67.&&i==0)"
"{"
"c=s(r-vec3(0,-.1-.03*cos(9.*r.r),0),vec3(.2,.018,.8),.01);"
"if(n.g<.8)"
"g=l;"
"c=min(c,s(l-vec3(.12,.5+l.r*1.256,0),vec3(0,.5,.8),.018));"
"l.g-=.5+l.r*1.256;"
"s(t,vec2(c,48));"
"s(t,vec2(.8*s(l-vec3(.01+sin(l.g*6.9+5.7)*.027/(1.+l.g),0,0),vec3(.06,.48,.78),0.),7));"
"}"
"return t;"
"}"
"void n(inout vec2 v,vec3 r,float g,float b,float f)"
"{"
"r-=vec3(-g*.5,b+.07,0);"
"g=g*.5-.015;"
"r.r=abs(r.r);"
"float l=s(r-vec3(g,0,0),vec3(0,b,b*.7),.01);"
"r.b-=m*.04*cos(r.r/g)-.019;"
"s(v,vec2(s(r-vec3(0,0,.015),vec3(g,b*.95+.002*cos(6e2*r.r),b*.65),0.),15));"
"s(v,vec2(min(l,s(r-vec3(0,0,b*.7+.01-.02*(.3+cos(2.*max(.9,cos(14.*r.g/b))))),vec3(g-.015,b,0),.015)),f*f*f*f));"
"}"
"vec2 f(vec3 r)"
"{"
"vec3 l=r,f=r-vec3(-20,19.65,3);"
"f.rb*=x(.4);"
"float g,b=s(r-vec3(5,31,5),vec3(15,30,5),0.),c=max(0.,v-80.),p=length(f-vec3(0,2,0))-10.*smoothstep(0.,18.,c)-5.1*max(0.,c-19.),t=clamp((80.-v)/15.,0.,1.);"
"t=pow(9.,-15.*t)*cos(t*30.);"
"l.g=mod(l.g+10.,17.5)-10.;"
"vec2 a,C=vec2(max(-b,s(l-vec3(0,.1,0),vec3(999,.1,999),0.)),3),o=d(f,t);"
"m=smoothstep(-1.,1.,p);"
"f=r-vec3(6.7,0,5);"
"f.rg*=x(.785);"
"f.b=abs(f.b);"
"f.g-=clamp(round(f.g),0.,24.);"
"f.gr*=x(.785);"
"s(C,vec2(min(s(f,vec3(.45,.5,3),.05),max(-b,s(l-vec3(3.*round(l.r/3.),-.5,0),vec3(.17,.45,999),0.))),2.3));"
"f=r-vec3(82,0,-2.6);"
"f.bg*=x(-.2);"
"f.r=abs(f.r);"
"s(C,vec2(min(s(f-vec3(0,clamp(round(f.g),0.,8.),0),vec3(.75,0,0),.04),s(f-vec3(.75,4.6,0),vec3(.05,4.4,.1),0.)),.3));"
"b=s(r-vec3(0,15.25,0),vec3(999,2.2,999),0.);"
"l=r;"
"l.g=l.g/.25+1.;"
"l=round(l*.1);"
"r.b-=l.b/.1;"
"f=r;"
"a=m*(.2+.1*cos(2.*f.rg)+.2*cos(.3*f.rg));"
"s(o,vec2(s(f-vec3(0,15.8,0),vec3(999,.85-a.r,.65-a.r),a.r),.99));"
"f.b=abs(f.b)-1.1;"
"f.r=mod(f.r+6.,12.)-6.;"
"s(o,vec2(s(f,vec3(.5),.2-.2*f.g),9));"
"s(o,vec2(s(f,vec3(.5-a.g,100,.5-a.g),a.g),1));"
"s(o,vec2(s(f-vec3(0,16.8,0),vec3(.45,.45,1e3),.2),2));"
"s(C,vec2(s(f-vec3(0,14.7,0),vec3(.6,0,0),.05),1.5));"
"s(C,vec2(s(f-vec3(0,14.7,-.5),vec3(.2,.27,.6),.05),2));"
"f-=vec3(0,15.5,1.7);"
"f.gb*=x(-.72);"
"s(C,vec2(s(f,vec3(.17,.2,2.5),.1),1));"
"f.b=abs(f.b);"
"s(C,vec2(s(f-vec3(0,0,2),vec3(.7,0,0),.05),1.5));"
"f=r;"
"f.b-=2.5;"
"f.r=mod(f.r+30.,48.)-11.;"
"f.g=mod(f.g+13.,17.5)-13.;"
"s(o,vec2(s(f-vec3(0,1.4,0),vec3(2.4,.04,.8),.06),.1));"
"f.rb=abs(f.rb);"
"f.rg*=x(.1);"
"s(C,vec2(s(f-vec3(1.6,.6,.6),vec3(0,.7,0),.1),8));"
"C.r=max(C.r,-p);"
"s(o,C);"
"b=min(b,s(r-vec3(18.+72.*round(r.r/72.),0,0),vec3(6.01,999,999),0.));"
"f=r;"
"f.g=mod(f.g+.27,2.5)-1.25;"
"s(o,vec2(max(-b,s(f,vec3(1e3,.07,.7),0.)),.99));"
"f.g=mod(r.g-1.,2.5);"
"g=floor(f.r);"
"if(m<.5||v<85.)"
"{"
"C=vec2(i==0?"
"f.r-g>.5?"
"s(f-vec3(g+11.5,.75,0),vec3(10.48,.8,.7),0.):"
"s(f-vec3(g-10.5,.8,0),vec3(10.48,.8,.7),0.):"
"999.,0);"
"f.r-=g;"
"for(c=.02;c<=.97;)"
"{"
"a=vec2(1.-.87*m,.38)+m*vec2(.2,.3)*s(l.bg+vec2(c,g));"
"a.r=min(a.r,.98-c);"
"c+=a.r;"
"if(a.r>.12+.5*m*t)"
"n(C,f-vec3(c,0,0),a.r,a.g,2.+s(a+g).r);"
"}"
"C.r=max(max(C.r,-b),m<.5?"
"p+.5:"
"0.);"
"s(o,C);"
"}"
"return o;"
"}"
"vec3 d(inout vec3 r,inout vec3 l,inout float b)"
"{"
"i=0;"
"float c=1.,C,a,x=.1,o=.01;"
"vec2 u=vec2(999);"
"for(int D=0;++D<200&&u.r>x/1e4&&x<b;)"
"u=f(r+l*x),x+=.9*u.r;"
"a=u.g;"
"if(a<0.)"
"return l*=0.,vec3(.7,.9,1)*(a<-1.2&&a>-2.?"
"s(r.rg+a).r-.5:"
"1.);"
"r+=x*l;"
"vec3 F=vec3(0,max(1e-4*x,.05-m*.04),0),H=vec3(f(r-F.grr).r,f(r-F.rgr).r,f(r-F.rrg)),e=vec3(f(r+F.grr).r,f(r+F.rgr).r,f(r+F.rrg)),E=e-H+.001;"
"E=normalize(E-max(.001,dot(E,l))*l);"
"e=4.*abs(u.r-e-H);"
"C=min(1.,e.r+e.g+e.b);"
"e=.5+.3*sin(vec3(.05,.08,.1)*(a-1.));"
"g=a==4.||a==7.?"
"g:"
"r;"
"e=a<3.?"
"fract(a+.99)*t(r,int(a)):"
"a==3.?"
".2+d(r).r*vec3(.4):"
"a==4.||a==5.?"
"mix(vec3(.01,.3,1),vec3(.6,.3,.1),smoothstep(.6,.7,n(g*2.,E,3))):"
"a==7.?"
"vec3(p(g.gb-vec2(.46,.05))):"
"e;"
"F=reflect(l,E);"
"if(m>0.)"
"n(E,30.*g);"
"H=vec3(.27,.6,.58);"
"i=1;"
"for(int D=0;++D<28&&a>.001&&o<2.5;)"
"a=f(r+H*o).r,c=min(c,2.*a/o),o+=clamp(a,.02,.1);"
"o=1.05;"
"a=1.;"
"for(float D=.02;D<.32;D+=.06)"
"a-=(D-f(r+E*D).r)*(o*=.95);"
"H=.1+min(a,1.)*dot(E,H)*max(c,0.)*vec3(1.3,1,.6)+pow(max(dot(F,H),0.),12.)+.25*pow(clamp(1.+dot(E,l),0.,1.),2.)+.12*vec3(.2,1,2)*max(0.,dot(l,reflect(vec3(.97,0,.24),E)));"
"l=u.g==3.||u.g==.1?"
"F:"
"F-F;"
"return mix(mix(vec3(1.5,.9,.75),vec3(.2,.3,.5),m),mix(.2+C*(2.+cos(3.*v))*vec3(.1,1,2),e,m)*H,b=smoothstep(b,b/5.,x));"
"}"
"void main()"
"{"
//"vec2 m=vec2(1280,720),"
"vec2 m=vec2(1920,1080),"
"f=gl_FragCoord.rg,g=(f+f-m)/m.g;"
"f/=m;"
"int[18] l=int[18](0,10,10,20,20,35,20,40,20,47,30,55,55,65,92,99,99,130);"
"int[30] c=int[30](95,8,80,95,6,-7,110,13,-5,92,15,-8,94,17,2,8,5,8,-10,24,4,-23,24,9,-4,25,7,140,4,4),b=int[30](80,6,28,80,5,-7,113,9,-12,90,15,-5,92,17,8,0,6,5,-16,22,5,-20,21,5,-10,23,7,135,3,9);"
"float a,i=3.;"
"vec3 t,C,o=vec3(c[0],c[1],c[2]),p=vec3(b[0],b[1],b[2]);"
"for(int D=0;++D<10;)"
"a=smoothstep(float(l[D*2-2]),float(l[D*2-1]),v),o=mix(o,vec3(c[D*3],c[D*3+1],c[D*3+2]),a),p=mix(p,vec3(b[D*3],b[D*3+1],b[D*3+2]),a);"
"a=.5*cos(.2*v);"
"t=normalize(p-o);"
"p=normalize(cross(t,vec3(sin(a),cos(a),0)));"
"p=mat3(p,normalize(cross(p,t)),t)*normalize(vec3(g+(v>99.?"
".01*s(g-g+v).r:"
"0.),2));"
"a=50.;"
"C=d(o,p,a);"
"if(p.r!=0.)"
"C+=a*.2*d(o,p,i);"
"a=smoothstep(0.,7.,v-125.);"
"r=v==0.?"
"vec4(1&int[](0,~0,124,3236969472,4160487169,~0,0,2199966623,~0,2031632,0)[min(int(length(g*20.)),10)]>>int(5.*atan(g.g,g.r))):"
"vec4(pow(clamp(mix(C,vec3(.1,.5,1),smoothstep(1.,1.3,n(2.5*g)+a))*(1.-a),0.,1.),vec3(.7))*4.*sqrt(f.r*f.g*(1.-f.r)*(1.-f.g)),1);"
"}";

#endif // SHADER_CODE_H_
