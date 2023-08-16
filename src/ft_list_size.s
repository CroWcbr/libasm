section .text
	global ft_list_size

ft_list_size:
	xor rax, rax

.count:
	test	rdi, rdi
	je		.end
	inc		rax
	mov		rdi, [rdi + 8]
	jmp		.count

.end:
	ret
