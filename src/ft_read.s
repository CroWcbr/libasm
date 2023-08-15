extern __errno_location
section .text
	global ft_read

ft_read:
	xor		rax, rax
	syscall
	test	rax, rax
	js		.error	; Jump if Sign
	ret

.error:
	neg		rax
	mov		rdx, rax
	call	__errno_location wrt ..plt
	mov		[rax], rdx
	mov		rax, -1
	ret
