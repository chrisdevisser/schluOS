#include <stdio.h>

#ifdef __schluOS_kernel
	#include <kernel/tty.hh>
	
	auto putchar(int c) -> int {
		kernel::tty::stream ttyout;
		ttyout << static_cast<char>(c);
		return c;
	}
#else
	//TODO: implement user mode printing
#endif

