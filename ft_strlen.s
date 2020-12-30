			section	.text
			global	ft_strlen
ft_strlen:										;(char *str) = rdi
			xor		rax, rax					;rax = 0;
loop:
			cmp		byte [rdi + rax], 0x0
			jz		exit						;when str[i] == 0, exit
			inc		rax
			jne 	loop
exit:
			ret
