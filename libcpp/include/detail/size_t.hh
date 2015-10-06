#pragma once

//This gets its own file because of being defined in multiple headers.

namespace std {

///size_t - [support.types]/6
///Unsigned integer type large enough to contain the size in bytes of any object.
using size_t = decltype(sizeof 0);

}
