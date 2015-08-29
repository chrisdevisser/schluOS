#include <string.h>

auto memmove(void* const dest_v, const void* const source_v, const size_t bytes) -> void* {
	const auto dest{static_cast<unsigned char*>(dest_v)};
	const auto source{static_cast<const unsigned char*>(source_v)};

	//The ranges can overlap, so dest being ahead of source requires backward copying.
	//Comparing unrelated pointers is also UB.
	if (reinterpret_cast<unsigned long>(dest) < reinterpret_cast<unsigned long>(source)) {
		for (size_t i{0}; i < bytes; ++i) {
			dest[i] = source[i];
		}
	} else {
		for (auto i{bytes}; i-- > 0;) {
			dest[i-1] = source[i-1];
		}
	}

	return dest_v;
}