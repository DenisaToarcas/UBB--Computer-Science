;   Additions, subtractions
;   4. (a-b)+(c-b-d)+d

bits 32 


global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    a db 7          ;in a byte we can store up to 2^9 - 1
    b db 6
    c db 19
    d db 11
    
segment code use32 class=code
    start:
       mov al, [a]
       sub al, [b]
       mov [a], al
       mov al, [c]
       sub al, [b]
       sub al, [d]
       add [a], al
       mov al, [d]
       add [a], al
        push    dword 0      
        call    [exit]       
