#pragma once

#include <sys/cdefs.h>

#include <stddef.h>

extern "C" {
	auto memcmp(const void* range1, const void* range2, size_t bytes) -> int;
	auto memcpy(void* dest, const void* source, size_t bytes) -> void*;
	auto memmove(void* dest, const void* source, size_t bytes) -> void*;
	auto memset(void* buffer, int value, size_t count) -> void*;
	auto strlen(const char* sz) -> size_t;
}