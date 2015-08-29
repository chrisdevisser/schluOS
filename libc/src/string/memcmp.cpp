#include <string.h>

auto memcmp(const void* const range1_v, const void* const range2_v, const size_t bytes) -> int {
	const auto range1{static_cast<const unsigned char*>(range1_v)};
	const auto range2{static_cast<const unsigned char*>(range2_v)};

	for (size_t i{0}; i < bytes; ++i) {
		if (range1[i] < range2[i]) {
			return -1;
		} else if (range1[i] > range2[i]) {
			return 1;
		}
	}

	return 0;
}