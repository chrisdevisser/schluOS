#constants
.set ALIGN, 	1 << 0 				#align loaded modules on page boundaries
.set MEMINFO, 	1 << 1 				#provide memory map
.set FLAGS,		ALIGN | MEMINFO		#multiboot flag field
.set MAGIC, 	0x1BADB002			#magic number for bootloader
.set CHECKSUM, 	-(MAGIC + FLAGS)	#checksum of above

#multiboot header so bootloader knows this is a multiboot kernel
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

#create our own stack of 16384 bytes
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384
stack_top:

#_start is the entry point to the kernel
.section .text
.global _start
.type _start, @function
_start:
	#set stack pointer to our stack
	movl $stack_top, %esp

	#call global constructors and other initialization tasks
	call _init

	#execute our C entry point, _kernel_main
	call _kernel_main

	#call global destructors and other deinitialization tasks
	call _fini

	#go into an infinite loop 
	cli #clear interrupts
	hlt #halt (until next interrupt)
.Lhang:
	jmp .Lhang

#set size of _start to current location minus label location
.size _start, . - _start
