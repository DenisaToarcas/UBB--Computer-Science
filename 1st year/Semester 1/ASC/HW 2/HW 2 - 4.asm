bits 32 

; Write a program in assembly language which computes one of the following arithmetic expressions, considering the following domains for the variables (in the unsigned and signed representation).

; Multiplications, divisions - signed 
; (8-a*b*100+c)/d+x
; a,b,d-byte; c-doubleword; x-qword


global start        

extern exit               
import exit msvcrt.dll    


segment data use32 class=data
   a db 2
   b db 1
   c dd 210
   d db 18
   x dq 7

segment code use32 class=code
    start:
        mov al, [a]
        mov bl, [b]
        imul bl      ;ax = a*b 
        
        mov bx, 100
        imul bx      ;dx : ax = a*b*100
        
        push dx
        push ax
        pop eax     ;eax = a*b*100
        
        mov ebx, [c]
        mov ecx, 8
        add ebx, ecx        ;ebx = c+8
        
        sbb ebx, eax  ;ebx = c+8-a*b*100
        
        mov al, [d]
        cbw
        cwde        ;eax = d
        
        cdq
        mov ecx, ebx
        mov ebx, eax
        mov eax, ecx    ;ebx = d && eax = c+8-a*b*100
        
        idiv ebx         ;edx : eax = (8-a*b*100+c)/d
        cdq
        
        mov ebx, dword [x]
        mov ecx, dword [x+4]
        
        add eax, ebx
        adc edx, ecx
        
        push    dword 0      
        call    [exit]       
