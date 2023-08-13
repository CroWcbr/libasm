section .text
	global ft_strcpy

ft_strcpy:
	xor		rax, rax

.loop:
	mov		bh, byte [rsi + rax]
	mov		byte [rdi + rax], bh
	test	bh, bh
	je		.end
	inc		rax
	jmp		.loop

.end:
	mov		rax, rdi
	ret
