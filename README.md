# C++20 Header-Only Hashes

Very trivial header-only hash functions for C++20. 

Functions currently implemented are:
- `fnv1a` (Fowler-Noll-Vo hash)
- `sdbm_32` (SDBM hash)
- `djb2` (DJB2 hash)

## Features

- `constexpr` hash functions for compile-time hashing
- Templatized iterators so that you can hash any iterable container (with plain old data types)
- Concepts for better error messages (or so they say)