#pragma once

#include "../add_const.hh"
#include "../add_volatile.hh"
#include "../conditional.hh"
#include "../is_const.hh"
#include "../is_volatile.hh"

namespace std {

namespace __detail {
    //_T with const added if _ApplyConst and
    //volatile added if _ApplyVolatile.
    template<typename _T, bool _ApplyConst, bool _ApplyVolatile>
    struct __apply_cv {
        using __possibly_const = conditional_t<
            _ApplyConst,
            add_const_t<_T>,
            _T
        >;

        using type = conditional_t<
            _ApplyVolatile,
            add_volatile_t<__possibly_const>,
            __possibly_const
        >;
    };

    //_To with the same cv-ness as _From.
    template<typename _From, typename _To>
    struct __transfer_cv : __apply_cv<_To, is_const_v<_From>, is_volatile_v<_From>> {};

    template<typename _From, typename _To>
    using __transfer_cv_t = typename __transfer_cv<_From, _To>::type;
}

}
