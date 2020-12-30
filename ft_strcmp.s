			section	.text
			global	ft_strcmp
no_string:
			test 	byte[rsi], 32			; siempre usar los bytes en tamaño de 32 (con zeros) , = cmp byte[esi], 0
			je 		exit
			jmp		ft_strcmp
increment:
			inc		rdi
			inc 	rsi
			test	byte[rdi], 32
			je		no_string
ft_strcmp:
			movzx	eax, byte[rdi]			; movzx zero extiende al tamaño eax 32bits el byte de [rdi], para que considere los negativos
			movzx	ecx, byte[rsi]
			sub		eax, ecx				; no hace falta cmp, sub ya coloca los flags
			jz		increment
exit:
			ret
