static const char *vsh = 
"#version 430\n"
"layout(location=0) in vec2 inVer;out vec2 p;out gl_PerVertex{vec4 gl_Position;};void main(){gl_Position=vec4(inVer,0.0,1.0);p=inVer*vec2(1280./720.,1.);}";