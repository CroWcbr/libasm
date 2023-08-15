section .text
	global ft_strcmp

ft_strcmp:
	xor		rax, rax

.loop:
	mov		bl, byte [rsi + rax]
	mov		cl, byte [rdi + rax]
	cmp		bl, cl
	jl		.end
	jg		.end
	test	bl, bl
	je		.end
	inc		rax
	jmp		.loop

.end:
	sub	cl, bl
	movsx	rax, cl	; move keeping the sign bytes
	ret
