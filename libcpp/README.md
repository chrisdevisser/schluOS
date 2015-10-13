This is my implementation of the C++ standard library. See the doc directory for more information on individual headers.

Firstly, the libstdc++ implementation is an inspiration for both compiler intrinsics and other implementation details.

This implementation looks to the future. Both C++17 features that have been voted in and others that are in TSes are treated as if they were permanent.

To keep the main include directory clear, all other files are in the detail subdirectory. The directories within it reflect the different primary headers. I prefer many short files to few long files. Other parts of the library can then reference just what they need.

Some files are in detail directly. The contents of these files are required to be defined in more than one header.

#Overall Extensions

- New libraries (e.g., concepts) are placed directly into `std` and into the main include directory and header files within rather than an `experimental` subdirectory and namespace.

- Templates outside of type_traits are powered by concepts.
