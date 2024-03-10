bits 32 

; Write a program in assembly language which computes one of the following arithmetic expressions, considering the following domains for the variables (in the unsigned and signed representation).

; Additions, subtractions - signed
; 3. (b+b+d)-(c+a)

global start        


extern exit               
import exit msvcrt.dll    


segment data use32 class=data
    a db 2
    b dw 5
    c dd 3
    d dq 4

segment code use32 class=code
    start:
        
        mov ax, [b]
        add ax, [b]
        
        cwde            ;ax -> eax => eax = b+b
        
        mov edx, 0
        add eax, dword [d]
        adc edx, dword [d+4]    ;edx : eax = b+b+d
        
        mov ebx, eax
        mov ecx, edx            ;ecx : ebx = b+b+d
        
        mov al, [a]
        cbw             ;al -> ax => ax = a
        cwde            ;eax = a
        
        mov edx, [c]
        add eax, edx    ;eax = c+a
        
        mov edx, 0      ;edx : eax = c+a
        sub ebx, eax
        sbb ecx, edx        ;ecx : ebx = (b+b+d)-(c+a)
        
        mov eax, 0
        mov edx, 0
        mov eax, ebx
        mov edx, ecx
        
        push    dword 0      
        call    [exit]      