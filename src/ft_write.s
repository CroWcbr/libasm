extern __errno_location
section .text
	global ft_write

ft_write:
	mov		rax, 1
	syscall
	test	rax, rax
	js		.error
	ret

.error:
	neg		rax
	mov		rdx, rax
	call	__errno_location wrt ..plt
	mov		[rax], rdx
	mov		rax, -1
	ret
