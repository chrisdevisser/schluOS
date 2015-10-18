#pragma once

#include <detail/type_traits/is_convertible.hh>

namespace std {

///ConvertibleTo - [concepts.lib.corelang.convertibleto]
///True iff is_convertible_v<_T> is true.
template<typename _From, typename _To>
concept bool ConvertibleTo() {
    return is_convertible_v<_From, _To>;
}

}
