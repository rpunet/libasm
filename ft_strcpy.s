			section	.text
			global	ft_strcpy
			mov		rax, rdi
ft_strcpy:
			cmp		byte[rsi], 0x0
			jz		exit
			movsb						; copia 1 byte de rdi a rsi, implícitos, incrementa (o decrementa según flag) los registros según el tamaño (1 en este caso)
			jmp	ft_strcpy
exit:
			mov byte[rdi], 0x0
			ret
