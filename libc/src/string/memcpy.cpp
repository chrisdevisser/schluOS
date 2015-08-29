#include <string.h>

auto memcpy(void* const dest_v, const void* const source_v, const size_t bytes) -> void* {
	const auto dest{static_cast<unsigned char*>(dest_v)}; 
	const auto source{static_cast<const unsigned char*>(source_v)}; 

	for (size_t i{0}; i < bytes; ++i) {
		dest[i] = source[i];
	}

	return dest_v;
}