;extern _error
section .text
	global ft_write

ft_write:
	xor		rax, rax
	mov		rax, 1
	syscall
	test	rax, rax
	js		.error
	ret

.error:
;	push	rax
;	call	_error
;	mov		rbx, rax
;	pop		rax
;	mov		[rbx], rax
	mov		rax, -1
	ret
