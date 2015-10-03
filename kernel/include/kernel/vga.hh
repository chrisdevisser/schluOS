#pragma once

#include <stdint.h>

namespace kernel {
namespace vga {

static constexpr int Width{80};
static constexpr int Height{25};
static uint16_t* const Memory{reinterpret_cast<uint16_t*>(0xB8000)};

enum class colors {
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

struct color {
    constexpr color(colors fg, colors bg);

    constexpr auto fg() const -> colors;
    constexpr auto bg() const -> colors;

private:
    const colors fg_;
    const colors bg_;
};

constexpr color::color(const colors fg, const colors bg)
    : fg_{fg}, bg_{bg} {}

constexpr auto color::fg() const -> colors {
    return fg_;
}

constexpr auto color::bg() const -> colors {
    return bg_;
}

//Forms a byte suitable for a VGA entry.
static constexpr auto to_byte(const color clr) {
    return (static_cast<int>(clr.bg()) << 4) | static_cast<int>(clr.fg());
}

//Forms a VGA entry suitable for writing to the buffer.
static constexpr auto make_entry(const char c, const color clr) -> uint16_t {
    return (to_byte(clr) << 8) | static_cast<unsigned char>(c); //the byte is promoted, so << 8 works
}

}
}
