bits 32 ; assembling for the 32 bits architecture

; Write a program in assembly language which computes one of the following arithmetic expressions, considering the following domains for the variables (in the unsigned and signed representation).

;Addtions, subtractions - unsigned
; 3. (c+d)-(a+d)+b

global start        


extern exit               
import exit msvcrt.dll    
                          

segment data use32 class=data
    a db 5
    b dw 3
    c dd 7
    d dq 2
    

segment code use32 class=code
    start:
        mov eax, [c]        ;eax = c
        mov edx, 0          ;edx : eax = c
        add eax, dword [d]  
        adc edx, dword [d+4] ;edx : eax = c + d
        
        mov bl, [a]
        mov bh, 0
        mov cx, 0       ;cx : bx = a
        
        push cx
        push bx
        pop ebx         ;ebx = a
        
        mov ecx, 0
        add ebx, dword [d]
        adc ecx, dword [d+4]        ;ecx : ebx = a + d
        
        sub eax, ebx
        sbb edx, ecx            ;edx : eax - ecx : ebx = (c+d) - (a+d)
        
        mov bx, [b]
        mov cx, 0
        push cx
        push bx
        pop ebx         ;ebx = b
        mov ecx, 0      ;ecx : ebx = b
        add eax, ebx
        adc edx, ecx    ;edx : eax = (c+d)-(a+d)+b
        
        push    dword 0      
        call    [exit]   
        