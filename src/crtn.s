.section .init
	/*crtend.o .init inserted here*/
	popl %ebp
	ret

.section .fini
	/*crtend.o .fini inserted here*/
	popl %ebp
	ret
