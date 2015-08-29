#include <stdarg.h>
#include <stdio.h>
#include <string.h>

//TODO: finish implementing

namespace {
	auto print(const char c) -> void {
		putchar(static_cast<unsigned char>(c));
	}

	auto print(const char* const data, size_t bytes) -> void {
		for (size_t i{0}; i < bytes; ++i) {
			print(data[i]);
		}
	}
}

auto printf(const char* format, ...) -> int {
	va_list ellipsis;
	va_start(ellipsis, format);

	auto ret{0};

	while (*format) {
		//print literal text
		if (*format != '%') {
			print(*format);
			++ret;
			++format;
			continue;
		} 

		++format;

		switch (*format) {
		case '%': //%%
			print('%');
			++ret;
			break;

		case 'c': { //%c
			auto arg{static_cast<char>(va_arg(ellipsis, int))}; //arg is promoted to int
			print(arg);
			++ret;
			break;
		}

		case 's': { //%s
			auto arg{va_arg(ellipsis, const char*)};
			auto len{strlen(arg)};
			print(arg, len);
			ret += len;
			break;
		}

		default:
			return ret;
		}

		++format;
	}

	va_end(ellipsis);
	return ret;
}