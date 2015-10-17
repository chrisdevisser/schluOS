Concepts are based on Eric Niebler's Ranges TS.
See https://github.com/ericniebler/stl2

#Extensions:

- Concepts are in the `std` namespace.
- `Object` is present and works like `is_object_v`.
- `Referenceable` is present and is satisfied iff a reference to the type can be taken (including references).
- `LvalueReference` is present and works like `is_lvalue_reference_v`.
- `RvalueReference` is present and works like `is_rvalue_reference_v`.
- `Reference` is present and works like `is_reference_v`.
