#pragma once

#include <sys/cdefs.h>

extern "C" {
	auto printf(const char* format, ...) -> int;
	auto putchar(int c) -> int;
	auto puts(const char* sz) -> int;
}