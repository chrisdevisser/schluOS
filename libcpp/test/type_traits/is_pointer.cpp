#include <type_traits>

struct structure {};

static_assert(std::is_pointer_v<int*>);
static_assert(std::is_pointer_v<int* const>);
static_assert(std::is_pointer_v<int* volatile>);
static_assert(std::is_pointer_v<int* const volatile>);
static_assert(std::is_pointer_v<const int*>);
static_assert(std::is_pointer_v<volatile int*>);
static_assert(std::is_pointer_v<const volatile int*>);
static_assert(std::is_pointer_v<const volatile int* const volatile>);

static_assert(std::is_pointer_v<void(*)()>);
static_assert(std::is_pointer_v<int(*)[]>);
static_assert(std::is_pointer_v<int(*)[5]>);
static_assert(std::is_pointer_v<int(*)[5]>);

static_assert(not std::is_pointer_v<void>);
static_assert(not std::is_pointer_v<void()>);
static_assert(not std::is_pointer_v<int[]>);

static_assert(not std::is_pointer_v<void(structure::*)()>);
static_assert(not std::is_pointer_v<int structure::*>);
