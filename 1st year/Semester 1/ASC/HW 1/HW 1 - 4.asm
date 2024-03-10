;   Multiplications, divisions
; 4.–a*a + 2*(b-1) – d

bits 32 


global start        

extern exit               
import exit msvcrt.dll    

segment data use32 class=data
    a db 4
    b db 12
    d db 6
segment code use32 class=code
    start:
      mov al, [a]
      mul al
      neg ax
      mov cx, ax
      mov al, [b]
      sub al, 1
      mov bl, 2
      mul bl        ;ax = al*bl => ax = 2*(b-1)
      add ax, cx
      mov cl, [d]
      mov ch, 0
      add ax, cx
      
        push    dword 0      
        call    [exit]