section .text
	global ft_strlen

ft_strlen:
	xor		rax, rax

.count:
	cmp		byte [rdi + rax], 0
	je		.end
	inc		rax
	jmp		.count

.end:
	ret
