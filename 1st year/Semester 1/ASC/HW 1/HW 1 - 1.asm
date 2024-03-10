;   Simple exercises
;   Compute and analyze the result:
;   4. 5-6

bits 32 


global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    a db 5
segment code use32 class=code
    start:
       
        mov al, [a]
        sub al, 6           ;al = a - 6
        push    dword 0      
        call    [exit]       

        