#include <stdint.h>
#include <string.h>

#include <kernel/tty.hh>
#include <kernel/vga.hh>

namespace kernel {
namespace tty {

stream::stream()
    : color_{vga::colors::White, vga::colors::Black} {}

auto stream::operator<<(const char c) -> stream& {
    write_at(c, x_, y_);

    if (c == '\n') {
        cursor_down();
        return *this;
    }

    cursor_right();
    if (x_ == 0) {
        cursor_down();
    }

    return *this;
}

auto stream::clear() -> void {
    for (auto i{0}; i < vga::Width*vga::Height; ++i) {
        *this << ' ';
    }

    x_ = y_ = 0;
}

auto stream::write(const char* const data, const int size) -> void {
    for (auto i{0}; i < size; ++i) {
        *this << data[i];
    }
}

auto stream::cursor_down() -> void {
    y_ = (y_ + 1) % vga::Height;
}

auto stream::cursor_right() -> void {
    x_ = (x_ + 1) % vga::Width;
}

auto stream::write_at(const char c, const int x, const int y) -> void {
    if (c == '\n') {
        write_at(' ', x, y);
        return;
    }

    auto index{y*vga::Width + x};
    vga::Memory[index] = vga::make_entry(c, color_);
}

auto operator<<(stream& s, const char* sz) -> stream& {
    s.write(sz, strlen(sz));
    return s;
}

}
}
