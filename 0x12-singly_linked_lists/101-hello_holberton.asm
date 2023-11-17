section .data
    hello db "Hello, Holberton", 0

section .text
    global main
    extern printf

main:
    sub rsp, 8           ; Align the stack
    mov rdi, hello       ; Format string address
    call printf          ; Call printf function
    add rsp, 8           ; Restore the stack
    mov eax, 0           ; Return 0
    ret
