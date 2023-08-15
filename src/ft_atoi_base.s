extern __errno_location
extern malloc
extern ft_strlen

section .text
	global ft_atoi_base

base_error:
	test	rdi, rdi
	jz .null_pointer

ft_atoi_base:
	push	rbp
	mov		rbp, rsp

	call base_error

	pop rbp
