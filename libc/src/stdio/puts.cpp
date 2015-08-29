#include <stdio.h>

auto puts(const char* const sz) -> int {
	return printf("%s\n", sz);
}