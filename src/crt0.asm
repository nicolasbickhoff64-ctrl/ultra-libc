bits 64
global _start
extern __libc_start_main

_start:
	mov rdi, [rsp]
        lea rsi, [rsp+8]
        sub rsp, 8
        call __libc_start_main
