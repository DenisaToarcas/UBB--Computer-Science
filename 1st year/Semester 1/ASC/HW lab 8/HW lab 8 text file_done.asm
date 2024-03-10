bits 32 ; assembling for the 32 bits architecture

; LAB 8
;PROBLEM NO. 3:
;A text file is given. Read the content of the file, count the number of even digits and display the result on the screen. The name of text file is defined in the data segment.


; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fread, printf, fopen, perror, fclose             ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fread msvcrt.dll
import printf msvcrt.dll
import fopen msvcrt.dll
import perror msvcrt.dll
import fclose msvcrt.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    f_in db "input.txt", 0
    r db "r", 0
    fd_in dd 0
    s_format db "%s", 0
    err_msg db "ERROR", 0
    buf resb 100
    format db "%d", 0


; our code starts here
segment code use32 class=code
    start:
        
    ;open the files   
        push r
        push f_in
        call [fopen]
        add esp, 4*2
        cmp eax, 0
        je .error
        mov [fd_in], eax
        
        xor ebx, ebx
        
    ;read the content of the file
        .loop:
        push dword [fd_in]
        push 100
        push 1
        push buf
        call [fread]
        add esp, 4*4
        cmp eax, 0
        je .end
        mov ecx, eax
        jecxz .end
        mov esi, buf
        
        .parse:
        lodsb
        pushad
        cmp al, '0'
        je .even_digit
        cmp al, '2'
        je .even_digit
        cmp al, '4'
        je .even_digit
        cmp al, '6'
        je .even_digit
        cmp al, '8'
        je .even_digit
        jmp .not_even
        
        .even_digit:
        inc ebx
        
        .not_even:
        popad
        
        jmp .loop
        
        cmp ebx, 0
        jne .end
        jmp .end
        
        .error:
        push err_msg
        call [perror]
        add esp, 4*1
        
        .end:
        ;closing the file
        push dword [fd_in]
        call [fclose]
        add esp, 4*1
        
        ;printing on the screen the number of even digits
        push ebx
        push format
        call [printf]
        add esp, 4*2
        
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
