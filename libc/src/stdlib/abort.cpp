#include <stdio.h>
#include <stdlib.h>

auto abort() -> void {
	//TODO: something better
	puts("Kernel panic: abort() called");
	for (;;) {}
}