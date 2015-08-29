#include <string.h>

size_t strlen(const char* sz) {
	size_t ret{};
	
	for (; *sz; ++sz) {
		++ret;
	}
	
	return ret;
}