#include <string.h>

auto memset(void* const buffer_v, const int value, size_t bytes) -> void* {
	const auto buffer{static_cast<unsigned char* const>(buffer_v)};

	for (size_t i{0}; i < bytes; ++i) {
		buffer[i] = value;
	}

	return buffer_v;
}