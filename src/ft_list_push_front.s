extern malloc
section .text
	global ft_list_push_front

ft_list_push_front:

.count:
	push	rbp
	mov		rbp, rsp
	push	rdi
	push	rsi
	mov		rdi, 16
	call	malloc wrt ..plt
	cmp		rax, 0
	je		.end
	pop		rsi
	mov		[rax], rsi
	pop		rdi
	mov		rbx, [rdi]
	mov		[rax + 8], rbx
	mov		[rdi], rax

.end:
	mov		rsp, rbp
	pop		rbp
	ret
