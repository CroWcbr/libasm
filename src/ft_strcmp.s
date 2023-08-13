section .text
	global ft_strcmp

ft_strcmp:
	xor		rax, rax

.loop:
	mov		bh, byte [rsi + rax]
	mov		ch, byte [rdi + rax]
	cmp		bh, ch
	jl		.less
	jg		.greater
	test	bh, bh
	je		.equel
	inc		rax
	jmp		.loop

.less:
	mov		rax, 1
	jmp		.done

.greater:
	mov		rax, -1
	jmp		.done

.equel:
	xor		rax, rax
	jmp		.done

.done:
	ret
