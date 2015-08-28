#ifdef __linux__
	#error "Does this look like it should be compiled for Linux?"
#endif

#ifndef __i386__
	#error "ix86-elf or bust"
#endif

#include <stddef.h>
#include <stdint.h>

enum class VgaColors {
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGrey = 7,
	DarkGrey = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

struct vga_terminal {
	//Initializes the terminal by clearing it.
	vga_terminal();

	vga_terminal(const vga_terminal&) = delete;
	vga_terminal& operator=(const vga_terminal&) = delete;

	//Clears the terminal with the current color.
	auto clear() -> void;

	//Writes a character to the terminal and advances the cursor.
	auto put(char c) -> void;

	//Writes a null-terminated string to the terminal and advances the cursor.
	auto put(const char* sz) -> void;

	//Writes a character at the given position in the current color.
	auto put_at(char c, int x, int y) -> void;

private:
	static uint16_t* const Buffer;
	static constexpr int Width{80};
	static constexpr int Height{25};

	int x_{};
	int y_{};
	VgaColors fg_color_{VgaColors::White};
	VgaColors bg_color_{VgaColors::Black};

	//VGA expects the color to be one byte.
	//If f = foreground, b = background:
	//	bbbbffff
	auto color8() const -> uint8_t;

	//Make an integer suitable for writing to the buffer.
	//If f = foreground, b = background, c = character:
	//	bbbbffffcccccccc
	auto make_entry(char c) const -> uint16_t;
	static auto make_entry(char c, uint8_t color) -> uint16_t;
};

uint16_t* const vga_terminal::Buffer{reinterpret_cast<uint16_t*>(0xB8000)};
constexpr int vga_terminal::Width;
constexpr int vga_terminal::Height;

vga_terminal::vga_terminal() {
	clear();
}

auto vga_terminal::clear() -> void {
	for (auto i{0}; i < Width*Height; ++i) {
		put(' ');
	}
}

auto vga_terminal::color8() const -> uint8_t {
	return (static_cast<int>(bg_color_) << 4) | static_cast<int>(fg_color_);
}

auto vga_terminal::make_entry(const char c) const -> uint16_t {
	return make_entry(c, color8());
}

auto vga_terminal::make_entry(const char c, const uint8_t color) -> uint16_t {
	return (color << 8) | static_cast<unsigned char>(c); //color is promoted, so << 8 is okay.
}

auto vga_terminal::put(const char c) -> void {
	put_at(c, x_, y_);

	x_ = (x_ + 1) % Width;
	if (x_ == 0) {
		y_ = (y_ + 1) % Height;
	}
}

auto vga_terminal::put(const char* sz) -> void {
	for (; *sz; ++sz) {
		put(*sz);
	}
}

auto vga_terminal::put_at(const char c, const int x, const int y) -> void {
	auto index{y*Width + x};
	Buffer[index] = make_entry(c);
}

extern "C" 
auto _kernel_main() -> void {
	vga_terminal vga_term;
	vga_term.clear(); 
	vga_term.put("Hello, kernel world!");
}