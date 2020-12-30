		section	.text
		global	ft_read
		extern	__errno_location
ft_read:
		mov		rax, 0							;syscall read, rax = 0, rdi = fd, rsi = char*, rdx = num bytes
		syscall
		cmp		rax, -1							;error si syscall devuelve entre -1 y -4095
		jle		error
		ret
error:
		cmp		rax, -4095
		jge		errno
		ret
errno:
		push	rax
		call	__errno_location wrt ..plt		;compilar gcc con -no-pie tambien linkea position-independet, en lugar de wrt ..ptl
		mov		rdi, rax
		pop		rax
		mov		[rdi], eax						;copiar un int (32bits) a la memoria a la que apunta int *errno
		neg		dword[rdi]						;syscall devuelve un negativo entre -1 y -4095, que se corresponde con su num error positivo de 1 a 4095
		mov		rax, -1
		ret



























