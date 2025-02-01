#pragma once
#include "hashes_meta.h"
#include <cstdint>

template <UnidirectionalIterator Iter>
    requires std::is_trivially_copyable_v<typename std::iterator_traits<Iter>::value_type>
inline constexpr uint32_t fnv1a_32(Iter first, Iter last)
{
    constexpr uint32_t prime_const = 0x01000193;
    uint32_t hash = 0x811c9dc5;

    auto begin_byte = make_byte_iterator(first);
    auto end_byte = make_byte_iterator(last);

    while (begin_byte != end_byte) {
        hash ^= *(begin_byte++);
        hash *= prime_const;
    }

    return hash;
}

template <UnidirectionalIterator Iter>
    requires std::is_trivially_copyable_v<typename std::iterator_traits<Iter>::value_type>
inline constexpr uint64_t fnv1a_64(Iter first, Iter last)
{
    constexpr uint64_t prime_const = 0x00000100000001b3;
    uint64_t hash = 0xcbf29ce484222325;

    auto begin_byte = make_byte_iterator(first);
    auto end_byte = make_byte_iterator(last);

    while (begin_byte != end_byte) {
        hash ^= *(begin_byte++);
        hash *= prime_const;
    }

    return hash;
}

template <UnidirectionalIterator Iter>
    requires std::is_trivially_copyable_v<typename std::iterator_traits<Iter>::value_type>
inline constexpr uint32_t djb2a_32(Iter first, Iter last)
{
    uint32_t hash = 5381;

    auto begin_byte = make_byte_iterator(first);
    auto end_byte = make_byte_iterator(last);

    while (begin_byte != end_byte) {
        hash = ((hash << 5) + hash) ^ *(begin_byte++);
    }

    return hash;
}

template <UnidirectionalIterator Iter>
    requires std::is_trivially_copyable_v<typename std::iterator_traits<Iter>::value_type>
inline constexpr uint64_t djb2a_64(Iter first, Iter last)
{
    uint64_t hash = 5381;

    auto begin_byte = make_byte_iterator(first);
    auto end_byte = make_byte_iterator(last);

    while (begin_byte != end_byte) {
        hash = ((hash << 5) + hash) ^ *(begin_byte++);
    }

    return hash;
}

template <UnidirectionalIterator Iter>
    requires std::is_trivially_copyable_v<typename std::iterator_traits<Iter>::value_type>
inline constexpr uint32_t sdbm_32(Iter first, Iter last)
{
    uint32_t hash = 5381;

    auto begin_byte = make_byte_iterator(first);
    auto end_byte = make_byte_iterator(last);

    while (begin_byte != end_byte) {
        hash = *(begin_byte++) + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}

template <UnidirectionalIterator Iter>
    requires std::is_trivially_copyable_v<typename std::iterator_traits<Iter>::value_type>
inline constexpr uint64_t sdbm_64(Iter first, Iter last)
{
    uint64_t hash = 5381;

    auto begin_byte = make_byte_iterator(first);
    auto end_byte = make_byte_iterator(last);

    while (begin_byte != end_byte) {
        hash = *(begin_byte++) + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}
