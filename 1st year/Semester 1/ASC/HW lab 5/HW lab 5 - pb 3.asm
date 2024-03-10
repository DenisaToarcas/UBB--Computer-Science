bits 32 ; assembling for the 32 bits architecture

;   3. Two byte strings S1 and S2 are given. Obtain the string D by concatenating the elements of S1 from the left hand side to the right hand side and the elements of S2 from the right hand side to the left hand side.
;Example:
;S1: 1, 2, 3, 4
;S2: 5, 6, 7
;D: 1, 2, 3, 4, 7, 6, 5

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    s1 db '1','2','3','4'
    len_s1 equ $-s1
    
    s2 db '5','6','7'
    len_s2 equ $-s2
    
    result resb $-$$
    
; our code starts here
segment code use32 class=code
    start:
        
        mov esi, 0          
        mov ecx, len_s1         ;we put the length len_s1 in ECX in order to make the loop_1
        
        jecxz loop_2
        
        loop_1:
            mov al, [s1+esi]
            mov [result+esi], al
            inc esi
            
        loop loop_1
        
        mov esi, len_s2
        dec esi
        mov ecx, len_s2         ;we put the length len_s2 in ECX in order to make the loop_2
        mov ebx, 0
        
        jecxz end_of_program
        
        loop_2:
            mov al, [s2+esi]
            mov [result+len_s1+ebx], al
            dec esi
            inc ebx
            
        loop loop_2
       
        
        end_of_program:
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
