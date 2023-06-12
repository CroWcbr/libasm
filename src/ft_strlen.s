section .text
	global ft_strlen

ft_strlen:
	xor rax, rax
	cmp byte [rdi + rax], 0
	je end

count:
	inc rax
	cmp byte [rdi + rax], 0
	jne count

end:
	ret

