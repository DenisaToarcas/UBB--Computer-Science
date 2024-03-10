;   Multiplications, divisions
; 4.(a-c)*3+b*b

bits 32 


global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    a db 4
    b db 5
    c db 2
segment code use32 class=code
    start:
      mov al, [a]
      sub al, [c]
      mov bl, 3
      mul bl
      mov cx, ax
      mov al, [b]
      mul al
      add cx, ax
      push    dword 0      
        call    [exit]