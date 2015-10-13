`initializer_list` is compiler-dependent. Here is what I can gather is needed for GCC, which gives an error unless these are met:

- The first data member should be of iterator type.
- The second data member should be of type `std::size_t`.
- GCC will fill in these members directly.
