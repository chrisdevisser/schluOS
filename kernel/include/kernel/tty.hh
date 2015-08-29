#pragma once

#include <kernel/vga.hh>

namespace kernel {
namespace tty {

struct stream {
	stream();

	auto operator<<(char) -> stream&;
	
	auto clear() -> void;
	auto clear(int) -> void;
	auto write(const char* data, int size) -> void;

private:
	int x_;
	int y_;
	vga::color color_;

	auto cursor_down() -> void;
	auto cursor_right() -> void;
	auto write_at(char, int x, int y) -> void;
};

auto operator<<(stream& s, const char* sz) -> stream&;

}
}