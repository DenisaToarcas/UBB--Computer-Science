;   Additions, subtractions
;   4.(b+b)-c-(a+d)
bits 32 


global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    a dw 50
    b dw 46
    c dw 17
    d dw 2
segment code use32 class=code
    start:
       mov ax, [b]
       add ax, [b]
       sub ax, [c]
       mov bx, [a]
       add bx, [d]
       sub ax, bx
        push    dword 0      
        call    [exit]       