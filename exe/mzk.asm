; Listing generated by Microsoft (R) Optimizing Compiler Version 19.31.31107.0 

	TITLE	C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\bin\vc2015\Release\mzk.obj
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMT
INCLUDELIB OLDNAMES

PUBLIC	?mzk_init@@YGXPAF@Z				; mzk_init
PUBLIC	?clamp@@YGMMMM@Z				; clamp
PUBLIC	?fract@@YGMM@Z					; fract
PUBLIC	?base@@YGMM@Z					; base
PUBLIC	?mainSound@@YGMM@Z				; mainSound
PUBLIC	__real@00000000
PUBLIC	__real@0000000000000000
PUBLIC	__real@3f800000
PUBLIC	__real@3fb47ae140000000
PUBLIC	__real@3fc3333340000000
PUBLIC	__real@3fd0000000000000
PUBLIC	__real@3fd3333340000000
PUBLIC	__real@3fd99999a0000000
PUBLIC	__real@3fe0000000000000
PUBLIC	__real@3ff921e500000000
PUBLIC	__real@4010000000000000
PUBLIC	__real@401921e500000000
PUBLIC	__real@4020000000000000
PUBLIC	__real@4022000000000000
PUBLIC	__real@4024000000000000
PUBLIC	__real@406b800000000000
PUBLIC	__real@4074a00000000000
PUBLIC	__real@40859920cc000000
PUBLIC	__real@40959920cc000000
PUBLIC	__real@40a59920cc000000
PUBLIC	__real@40dfffc000000000
PUBLIC	__real@40e5888000000000
PUBLIC	__real@bf800000
PUBLIC	__real@bff0000000000000
PUBLIC	__real@c000000000000000
PUBLIC	__real@c014000000000000
PUBLIC	__real@c024000000000000
EXTRN	__CIexp:PROC
EXTRN	__CIsin:PROC
EXTRN	_floor:PROC
EXTRN	__fltused:DWORD
;	COMDAT __real@c024000000000000
CONST	SEGMENT
__real@c024000000000000 DQ 0c024000000000000r	; -10
CONST	ENDS
;	COMDAT __real@c014000000000000
CONST	SEGMENT
__real@c014000000000000 DQ 0c014000000000000r	; -5
CONST	ENDS
;	COMDAT __real@c000000000000000
CONST	SEGMENT
__real@c000000000000000 DQ 0c000000000000000r	; -2
CONST	ENDS
;	COMDAT __real@bff0000000000000
CONST	SEGMENT
__real@bff0000000000000 DQ 0bff0000000000000r	; -1
CONST	ENDS
;	COMDAT __real@bf800000
CONST	SEGMENT
__real@bf800000 DD 0bf800000r			; -1
CONST	ENDS
;	COMDAT __real@40e5888000000000
CONST	SEGMENT
__real@40e5888000000000 DQ 040e5888000000000r	; 44100
CONST	ENDS
;	COMDAT __real@40dfffc000000000
CONST	SEGMENT
__real@40dfffc000000000 DQ 040dfffc000000000r	; 32767
CONST	ENDS
;	COMDAT __real@40a59920cc000000
CONST	SEGMENT
__real@40a59920cc000000 DQ 040a59920cc000000r	; 2764.56
CONST	ENDS
;	COMDAT __real@40959920cc000000
CONST	SEGMENT
__real@40959920cc000000 DQ 040959920cc000000r	; 1382.28
CONST	ENDS
;	COMDAT __real@40859920cc000000
CONST	SEGMENT
__real@40859920cc000000 DQ 040859920cc000000r	; 691.141
CONST	ENDS
;	COMDAT __real@4074a00000000000
CONST	SEGMENT
__real@4074a00000000000 DQ 04074a00000000000r	; 330
CONST	ENDS
;	COMDAT __real@406b800000000000
CONST	SEGMENT
__real@406b800000000000 DQ 0406b800000000000r	; 220
CONST	ENDS
;	COMDAT __real@4024000000000000
CONST	SEGMENT
__real@4024000000000000 DQ 04024000000000000r	; 10
CONST	ENDS
;	COMDAT __real@4022000000000000
CONST	SEGMENT
__real@4022000000000000 DQ 04022000000000000r	; 9
CONST	ENDS
;	COMDAT __real@4020000000000000
CONST	SEGMENT
__real@4020000000000000 DQ 04020000000000000r	; 8
CONST	ENDS
;	COMDAT __real@401921e500000000
CONST	SEGMENT
__real@401921e500000000 DQ 0401921e500000000r	; 6.2831
CONST	ENDS
;	COMDAT __real@4010000000000000
CONST	SEGMENT
__real@4010000000000000 DQ 04010000000000000r	; 4
CONST	ENDS
;	COMDAT __real@3ff921e500000000
CONST	SEGMENT
__real@3ff921e500000000 DQ 03ff921e500000000r	; 1.57078
CONST	ENDS
;	COMDAT __real@3fe0000000000000
CONST	SEGMENT
__real@3fe0000000000000 DQ 03fe0000000000000r	; 0.5
CONST	ENDS
;	COMDAT __real@3fd99999a0000000
CONST	SEGMENT
__real@3fd99999a0000000 DQ 03fd99999a0000000r	; 0.4
CONST	ENDS
;	COMDAT __real@3fd3333340000000
CONST	SEGMENT
__real@3fd3333340000000 DQ 03fd3333340000000r	; 0.3
CONST	ENDS
;	COMDAT __real@3fd0000000000000
CONST	SEGMENT
__real@3fd0000000000000 DQ 03fd0000000000000r	; 0.25
CONST	ENDS
;	COMDAT __real@3fc3333340000000
CONST	SEGMENT
__real@3fc3333340000000 DQ 03fc3333340000000r	; 0.15
CONST	ENDS
;	COMDAT __real@3fb47ae140000000
CONST	SEGMENT
__real@3fb47ae140000000 DQ 03fb47ae140000000r	; 0.08
CONST	ENDS
;	COMDAT __real@3f800000
CONST	SEGMENT
__real@3f800000 DD 03f800000r			; 1
CONST	ENDS
;	COMDAT __real@0000000000000000
CONST	SEGMENT
__real@0000000000000000 DQ 00000000000000000r	; 0
CONST	ENDS
;	COMDAT __real@00000000
CONST	SEGMENT
__real@00000000 DD 000000000r			; 0
CONST	ENDS
; Function compile flags: /Ogspy
; File C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\src\mzk.cpp
;	COMDAT ?mainSound@@YGMM@Z
_TEXT	SEGMENT
tv182 = -24						; size = 8
tv201 = -16						; size = 4
_o$ = -16						; size = 4
tv180 = -12						; size = 8
_s$ = -8						; size = 4
_y$ = -4						; size = 4
tv190 = 8						; size = 4
_time$ = 8						; size = 4
?mainSound@@YGMM@Z PROC					; mainSound, COMDAT

; 53   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 24					; 00000018H

; 54   :     float y = 0.0f;

	fldz
	fst	DWORD PTR _y$[ebp]

; 55   :     float s = 1.0f;

	fld1
	fstp	DWORD PTR _s$[ebp]
	push	esi

; 56   :     float o = 0.0f;

	fstp	DWORD PTR _o$[ebp]
	fld	DWORD PTR _time$[ebp]
	push	5
	pop	esi
$LN4@mainSound:

; 57   :     for (int i = 0; i < 5; i++)
; 58   :     {
; 59   :         y += s * base(time - o);

	fld	DWORD PTR _o$[ebp]
	fst	QWORD PTR tv182[ebp]
	fld	DWORD PTR _s$[ebp]
	fstp	QWORD PTR tv180[ebp]
	push	ecx
	fsubp	ST(1), ST(0)
	fstp	DWORD PTR tv201[ebp]
	fld	DWORD PTR tv201[ebp]
	fstp	DWORD PTR [esp]
	call	?base@@YGMM@Z				; base
	fld	QWORD PTR tv180[ebp]
	fmul	ST(1), ST(0)
	fld	DWORD PTR _y$[ebp]
	faddp	ST(2), ST(0)
	fxch	ST(1)
	fstp	DWORD PTR _y$[ebp]

; 60   :         s *= 0.5f;

	fmul	QWORD PTR __real@3fe0000000000000
	fstp	DWORD PTR _s$[ebp]

; 61   :         o += 0.25f;

	fld	QWORD PTR tv182[ebp]
	fadd	QWORD PTR __real@3fd0000000000000
	fstp	DWORD PTR _o$[ebp]
	fld	DWORD PTR _time$[ebp]
	sub	esi, 1
	jne	SHORT $LN4@mainSound

; 62   :     }
; 63   :     return y * 0.15f;

	fstp	ST(0)
	fld	DWORD PTR _y$[ebp]
	fmul	QWORD PTR __real@3fc3333340000000
	pop	esi
	fstp	DWORD PTR tv190[ebp]
	fld	DWORD PTR tv190[ebp]

; 64   : }

	leave
	ret	4
?mainSound@@YGMM@Z ENDP					; mainSound
_TEXT	ENDS
; Function compile flags: /Ogspy
; File C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\src\mzk.cpp
;	COMDAT ?base@@YGMM@Z
_TEXT	SEGMENT
tv638 = -88						; size = 8
tv623 = -88						; size = 8
tv597 = -88						; size = 8
tv585 = -88						; size = 8
tv562 = -88						; size = 8
tv625 = -80						; size = 8
tv587 = -80						; size = 8
tv557 = -80						; size = 8
tv634 = -72						; size = 8
tv649 = -64						; size = 8
tv650 = -56						; size = 8
tv644 = -56						; size = 8
tv651 = -48						; size = 8
tv603 = -40						; size = 8
tv549 = -40						; size = 8
tv547 = -32						; size = 8
tv615 = -24						; size = 8
tv577 = -16						; size = 8
tv543 = -8						; size = 8
tv823 = 8						; size = 4
tv810 = 8						; size = 4
tv797 = 8						; size = 4
tv789 = 8						; size = 4
tv776 = 8						; size = 4
tv769 = 8						; size = 4
tv766 = 8						; size = 4
tv747 = 8						; size = 4
tv732 = 8						; size = 4
tv729 = 8						; size = 4
tv726 = 8						; size = 4
tv723 = 8						; size = 4
tv703 = 8						; size = 4
tv696 = 8						; size = 4
tv693 = 8						; size = 4
tv689 = 8						; size = 4
tv670 = 8						; size = 4
tv662 = 8						; size = 4
tv659 = 8						; size = 4
_time$ = 8						; size = 4
?base@@YGMM@Z PROC					; base, COMDAT

; 17   : float base(float time) {

	push	ebp
	mov	ebp, esp
	sub	esp, 88					; 00000058H

; 18   :     float y = 0.f;
; 19   :     {
; 20   :         float f = 440.f;//220.f;
; 21   :         float im = 10.f + 9.f * sin(0.25f * 6.2831f * time);

	fld	DWORD PTR _time$[ebp]
	fst	QWORD PTR tv543[ebp]

; 25   :         v *= exp(-2.f * fract(8.0f * time));
; 26   :         y += 0.3f * v;
; 27   :     }
; 28   :   
; 29   :     {
; 30   :         float t = fract(time);//*2.0f);

	push	ecx
	fstp	DWORD PTR [esp]
	call	?fract@@YGMM@Z				; fract

; 31   :         float f = 220.0f * exp(-5.0f * t);

	fstp	QWORD PTR tv577[ebp]

; 37   :     }
; 38   :     {
; 39   :         float t = fract(4.0f * time);//*2.0f);

	fld	QWORD PTR tv543[ebp]
	fmul	QWORD PTR __real@4010000000000000
	push	ecx
	fstp	DWORD PTR tv823[ebp]
	fld	DWORD PTR tv823[ebp]
	fstp	DWORD PTR [esp]
	call	?fract@@YGMM@Z				; fract

; 40   :         float f = 330.0f * exp(-5.0f * t);

	fstp	QWORD PTR tv615[ebp]
	fld	QWORD PTR tv543[ebp]
	fmul	QWORD PTR __real@3ff921e500000000
	call	__CIsin
	fmul	QWORD PTR __real@4022000000000000
	fadd	QWORD PTR __real@4024000000000000
	fstp	DWORD PTR tv810[ebp]
	fld	DWORD PTR tv810[ebp]
	fstp	QWORD PTR tv547[ebp]
	fld	QWORD PTR tv543[ebp]
	fmul	QWORD PTR __real@40a59920cc000000
	fstp	QWORD PTR tv549[ebp]
	fld	QWORD PTR tv577[ebp]
	fld	ST(0)
	fmul	QWORD PTR __real@bff0000000000000
	fstp	QWORD PTR tv651[ebp]
	fmul	QWORD PTR __real@c014000000000000
	call	__CIexp
	fmul	QWORD PTR __real@406b800000000000
	fstp	DWORD PTR tv797[ebp]
	fld	DWORD PTR tv797[ebp]
	fmul	QWORD PTR __real@401921e500000000
	fmul	QWORD PTR tv577[ebp]
	fmul	QWORD PTR __real@3fe0000000000000
	call	__CIsin
	fstp	DWORD PTR tv789[ebp]
	fld	DWORD PTR tv789[ebp]
	fmul	QWORD PTR __real@4020000000000000
	fstp	QWORD PTR tv650[ebp]

; 41   :         float a = sin(6.2831f * (f * t * 0.5f + .25f));
; 42   :         float v = 0.0f;
; 43   :         v += clamp(a * 8.0f, -1.0f, 1.0f) * (exp(-10.0f * t) + exp(-1.0f * t));

	fld	QWORD PTR tv615[ebp]
	fld	ST(0)
	fmul	QWORD PTR __real@bff0000000000000
	fstp	QWORD PTR tv649[ebp]
	fmul	QWORD PTR __real@c014000000000000
	call	__CIexp
	fmul	QWORD PTR __real@4074a00000000000
	fstp	DWORD PTR tv776[ebp]
	fld	DWORD PTR tv776[ebp]
	fmul	QWORD PTR tv615[ebp]
	fmul	QWORD PTR __real@3fe0000000000000
	fadd	QWORD PTR __real@3fd0000000000000
	fmul	QWORD PTR __real@401921e500000000
	call	__CIsin
	fstp	DWORD PTR tv769[ebp]
	fld	DWORD PTR tv769[ebp]
	fstp	QWORD PTR tv634[ebp]
	fld	QWORD PTR tv543[ebp]
	fmul	QWORD PTR __real@4020000000000000
	push	ecx
	fstp	DWORD PTR tv766[ebp]
	fld	DWORD PTR tv766[ebp]
	fstp	DWORD PTR [esp]
	call	?fract@@YGMM@Z				; fract
	fmul	QWORD PTR __real@c000000000000000
	call	__CIexp
	fstp	QWORD PTR tv562[ebp]
	fld	QWORD PTR tv543[ebp]
	fmul	QWORD PTR __real@40859920cc000000
	call	__CIsin
	fmul	QWORD PTR tv547[ebp]
	fadd	QWORD PTR tv549[ebp]
	call	__CIsin
	fldz
	faddp	ST(1), ST(0)
	fstp	DWORD PTR tv747[ebp]
	fld	DWORD PTR tv747[ebp]
	fstp	QWORD PTR tv557[ebp]
	fld	QWORD PTR tv543[ebp]

; 22   :         float v = 0.0f;
; 23   :         v += 1.0f * sin(6.2831f * f * time * 1.f + 1.f * im * sin(0.25f * 6.2831f * f * time));
; 24   :         v += 0.3f * sin(6.2831f * f * time * 0.5 + 8.0 * im * sin(0.5f * 6.2831f * f * time));

	fmul	QWORD PTR __real@40959920cc000000
	call	__CIsin
	fld	QWORD PTR tv547[ebp]
	fmul	QWORD PTR __real@4020000000000000
	fmulp	ST(1), ST(0)
	fld	QWORD PTR __real@3fe0000000000000
	fmul	QWORD PTR tv549[ebp]
	faddp	ST(1), ST(0)
	call	__CIsin
	fld	QWORD PTR __real@3fd3333340000000

; 32   :         float a = sin(6.2831f * f * t * 0.5f);
; 33   :         float v = 0.0f;
; 34   :         v += clamp(a * 8.0f, -1.0f, 1.0f) * (exp(-10.0f * t) + exp(-1.0f * t));

	sub	esp, 12					; 0000000cH
	fmul	ST(1), ST(0)
	fld	QWORD PTR tv557[ebp]
	faddp	ST(2), ST(0)
	fxch	ST(1)
	fstp	DWORD PTR tv732[ebp]
	fld	DWORD PTR tv732[ebp]
	fmul	QWORD PTR tv562[ebp]
	fstp	DWORD PTR tv729[ebp]
	fmul	DWORD PTR tv729[ebp]
	fldz
	faddp	ST(1), ST(0)
	fstp	DWORD PTR tv726[ebp]
	fld	DWORD PTR tv726[ebp]

; 35   :         v += a * 8.0f * exp(-1.0f * t);
; 36   :         y += 0.4f * v;

	fstp	QWORD PTR tv603[ebp]
	fld1
	fstp	DWORD PTR [esp+8]
	fld	DWORD PTR __real@bf800000
	fstp	DWORD PTR [esp+4]
	fld	QWORD PTR tv650[ebp]
	fstp	DWORD PTR tv723[ebp]
	fld	DWORD PTR tv723[ebp]
	fstp	DWORD PTR [esp]
	call	?clamp@@YGMMMM@Z			; clamp
	fstp	QWORD PTR tv587[ebp]
	fld	QWORD PTR __real@c024000000000000
	fmul	QWORD PTR tv577[ebp]
	call	__CIexp
	fstp	QWORD PTR tv585[ebp]
	fld	QWORD PTR tv651[ebp]
	call	__CIexp
	fadd	QWORD PTR tv585[ebp]
	fmul	QWORD PTR tv587[ebp]
	fldz
	faddp	ST(1), ST(0)
	fstp	DWORD PTR tv703[ebp]
	fld	DWORD PTR tv703[ebp]
	fstp	QWORD PTR tv597[ebp]
	fld	QWORD PTR tv651[ebp]
	call	__CIexp
	fmul	QWORD PTR tv650[ebp]

; 41   :         float a = sin(6.2831f * (f * t * 0.5f + .25f));
; 42   :         float v = 0.0f;
; 43   :         v += clamp(a * 8.0f, -1.0f, 1.0f) * (exp(-10.0f * t) + exp(-1.0f * t));

	sub	esp, 12					; 0000000cH
	fadd	QWORD PTR tv597[ebp]
	fstp	DWORD PTR tv696[ebp]
	fld	DWORD PTR tv696[ebp]
	fmul	QWORD PTR __real@3fd99999a0000000
	fadd	QWORD PTR tv603[ebp]
	fstp	DWORD PTR tv693[ebp]
	fld	DWORD PTR tv693[ebp]

; 45   :         y += 0.08f * v;

	fstp	QWORD PTR tv644[ebp]
	fld1
	fstp	DWORD PTR [esp+8]
	fld	DWORD PTR __real@bf800000
	fstp	DWORD PTR [esp+4]
	fld	QWORD PTR tv634[ebp]
	fmul	QWORD PTR __real@4020000000000000
	fstp	DWORD PTR tv689[ebp]
	fld	DWORD PTR tv689[ebp]
	fstp	DWORD PTR [esp]
	call	?clamp@@YGMMMM@Z			; clamp
	fstp	QWORD PTR tv625[ebp]
	fld	QWORD PTR __real@c024000000000000
	fmul	QWORD PTR tv615[ebp]
	call	__CIexp
	fstp	QWORD PTR tv623[ebp]
	fld	QWORD PTR tv649[ebp]
	call	__CIexp
	fadd	QWORD PTR tv623[ebp]
	fmul	QWORD PTR tv625[ebp]
	fldz
	faddp	ST(1), ST(0)

; 41   :         float a = sin(6.2831f * (f * t * 0.5f + .25f));
; 42   :         float v = 0.0f;
; 43   :         v += clamp(a * 8.0f, -1.0f, 1.0f) * (exp(-10.0f * t) + exp(-1.0f * t));

	fstp	DWORD PTR tv670[ebp]
	fld	DWORD PTR tv670[ebp]

; 44   :         v += a * 2.0f * exp(-1.0f * t);

	fstp	QWORD PTR tv638[ebp]
	fld	QWORD PTR tv649[ebp]
	call	__CIexp
	fld	QWORD PTR tv634[ebp]
	fadd	ST(0), ST(0)
	fmulp	ST(1), ST(0)
	fadd	QWORD PTR tv638[ebp]
	fstp	DWORD PTR tv662[ebp]
	fld	DWORD PTR tv662[ebp]

; 45   :         y += 0.08f * v;

	fmul	QWORD PTR __real@3fb47ae140000000
	fadd	QWORD PTR tv644[ebp]
	fstp	DWORD PTR tv659[ebp]
	fld	DWORD PTR tv659[ebp]

; 46   :     }
; 47   :     
; 48   :     return y;
; 49   : }

	leave
	ret	4
?base@@YGMM@Z ENDP					; base
_TEXT	ENDS
; Function compile flags: /Ogspy
; File C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\src\mzk.cpp
; File C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\corecrt_math.h
; File C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\src\mzk.cpp
; File C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\corecrt_math.h
; File C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\src\mzk.cpp
; File C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\corecrt_math.h
; File C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\src\mzk.cpp
;	COMDAT ?fract@@YGMM@Z
_TEXT	SEGMENT
tv79 = -8						; size = 8
tv135 = 8						; size = 4
tv132 = 8						; size = 4
_a$ = 8							; size = 4
?fract@@YGMM@Z PROC					; fract, COMDAT

; 13   : float fract(float a) {

	push	ebp
	mov	ebp, esp
	push	ecx
	push	ecx

; 14   :     return a-(float)floorf(a);

	fld	DWORD PTR _a$[ebp]
; File C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\corecrt_math.h

; 684  :             return (float)floor(_X);

	push	ecx
; File C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\src\mzk.cpp

; 14   :     return a-(float)floorf(a);

	fst	QWORD PTR tv79[ebp]
; File C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\corecrt_math.h

; 684  :             return (float)floor(_X);

	push	ecx
	fstp	QWORD PTR [esp]
	call	_floor
	fstp	DWORD PTR tv135[ebp]
	fld	DWORD PTR tv135[ebp]
; File C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\src\mzk.cpp

; 14   :     return a-(float)floorf(a);

	fsubr	QWORD PTR tv79[ebp]
; File C:\Program Files (x86)\Windows Kits\10\Include\10.0.19041.0\ucrt\corecrt_math.h

; 684  :             return (float)floor(_X);

	pop	ecx
	pop	ecx
; File C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\src\mzk.cpp

; 14   :     return a-(float)floorf(a);

	fstp	DWORD PTR tv132[ebp]
	fld	DWORD PTR tv132[ebp]

; 15   : }

	leave
	ret	4
?fract@@YGMM@Z ENDP					; fract
_TEXT	ENDS
; Function compile flags: /Ogspy
; File C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\src\mzk.cpp
;	COMDAT ?clamp@@YGMMMM@Z
_TEXT	SEGMENT
tv71 = 8						; size = 4
_a$ = 8							; size = 4
_n$ = 12						; size = 4
_x$ = 16						; size = 4
?clamp@@YGMMMM@Z PROC					; clamp, COMDAT

; 9    : float clamp(float a, float n, float x) {

	push	ebp
	mov	ebp, esp

; 10   :     return a < n ? n : a > x ? x : a;

	fld	DWORD PTR _a$[ebp]
	fld	ST(0)
	fld	DWORD PTR _n$[ebp]
	fcom	ST(1)
	fnstsw	ax
	test	ah, 65					; 00000041H
	jne	SHORT $LN8@clamp
	fstp	ST(2)
$LN11@clamp:
	fstp	ST(0)
$LN13@clamp:
	fstp	DWORD PTR tv71[ebp]
	fld	DWORD PTR tv71[ebp]

; 11   : }

	pop	ebp
	ret	12					; 0000000cH
$LN8@clamp:

; 10   :     return a < n ? n : a > x ? x : a;

	fstp	ST(0)
	fld	DWORD PTR _x$[ebp]
	fcom	ST(1)
	fnstsw	ax
	fstp	ST(1)
	test	ah, 5
	jp	SHORT $LN11@clamp
	fstp	ST(1)
	jmp	SHORT $LN13@clamp
?clamp@@YGMMMM@Z ENDP					; clamp
_TEXT	ENDS
; Function compile flags: /Ogspy
; File C:\Users\sebastien.durand\source\Intro-4Kbyte-Kelenian\i4k_Bibli1\src\mzk.cpp
;	COMDAT ?mzk_init@@YGXPAF@Z
_TEXT	SEGMENT
_tmp$1 = -12						; size = 4
_tmp$2 = -8						; size = 4
_x$ = -4						; size = 4
_i$3 = -4						; size = 4
tv227 = 8						; size = 4
tv207 = 8						; size = 4
tv169 = 8						; size = 4
_x$ = 8							; size = 4
_buffer$ = 8						; size = 4
?mzk_init@@YGXPAF@Z PROC				; mzk_init, COMDAT

; 67   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 12					; 0000000cH

; 68   :     for (int i = 0; i < MZK_NUMSAMPLES; i++) {

	fld	QWORD PTR __real@40e5888000000000
	push	esi
	xor	esi, esi
	push	edi
	mov	edi, DWORD PTR _buffer$[ebp]
	mov	DWORD PTR _i$3[ebp], esi
$LN4@mzk_init:

; 69   :         const float time = (float)i / (float)MZK_RATE;

	fild	DWORD PTR _i$3[ebp]

; 70   :         float fl = mainSound(time);

	push	ecx
	fstp	DWORD PTR tv227[ebp]
	fdivr	DWORD PTR tv227[ebp]
	fstp	DWORD PTR tv207[ebp]
	fld	DWORD PTR tv207[ebp]
	fstp	DWORD PTR [esp]
	call	?mainSound@@YGMM@Z			; mainSound

; 71   :         buffer[2 * i + 0] = f2i(fl * 32767.0f);

	fmul	QWORD PTR __real@40dfffc000000000
	fstp	DWORD PTR tv169[ebp]
	fld	DWORD PTR tv169[ebp]
	fstp	DWORD PTR _x$[ebp]
	fld	DWORD PTR _x$[ebp]
	fistp	DWORD PTR _tmp$2[ebp]
	mov	ax, WORD PTR _tmp$2[ebp]

; 72   :         buffer[2 * i + 1] = f2i(fl * 32767.0f);

	fld	DWORD PTR tv169[ebp]
	fstp	DWORD PTR _x$[ebp]
	mov	WORD PTR [edi+esi*4], ax
	fld	DWORD PTR _x$[ebp]
	fistp	DWORD PTR _tmp$1[ebp]
	mov	ax, WORD PTR _tmp$1[ebp]
	fld	QWORD PTR __real@40e5888000000000
	mov	WORD PTR [edi+esi*4+2], ax
	inc	esi
	mov	DWORD PTR _i$3[ebp], esi
	cmp	esi, 5292000				; 0050bfe0H
	jl	SHORT $LN4@mzk_init

; 73   :     }
; 74   : }

	pop	edi
	fstp	ST(0)
	pop	esi
	leave
	ret	4
?mzk_init@@YGXPAF@Z ENDP				; mzk_init
_TEXT	ENDS
END
