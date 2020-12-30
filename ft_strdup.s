			section	.text
			global	ft_strdup
			extern	ft_strlen
			extern	malloc
			extern	ft_strcpy
			extern	__errno_location
ft_strdup:
			call	ft_strlen
			push	rdi
			mov		rdi, rax
			;inc		rdi
			call	malloc wrt ..plt
			cmp		rax, 0x0
			jz		error
			pop		rsi
			mov		rdi, rax
			call	ft_strcpy
			ret
error:
			pop 	rdi
			call	__errno_location wrt ..plt
			mov		dword[rax], 12
			mov		rax, 0x0
			ret
