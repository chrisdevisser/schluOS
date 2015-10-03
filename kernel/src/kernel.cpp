#include <kernel/tty.hh>
#include <stdio.h>

extern "C"
auto _kernel_init() -> void {
    kernel::tty::stream ttyout;
    ttyout.clear();
}

extern "C"
auto _kernel_main() -> void {
    puts("Hello, kernel world!");
}
