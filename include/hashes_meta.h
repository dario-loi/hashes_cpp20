#pragma once

#include <concepts>
#include <iterator>
#include <type_traits>

template <typename T>
concept UnidirectionalIterator = std::input_iterator<T> && requires(T i) {

    { i == i } -> std::same_as<bool>;
    { i != i } -> std::same_as<bool>;


    { ++i } -> std::same_as<T&>;
    { i++ } -> std::same_as<T>;

    requires std::is_reference_v<decltype(*i)> && std::convertible_to<std::remove_reference_t<decltype(*i)>, typename std::iterator_traits<T>::value_type>;


    requires std::copyable<T>;

    requires std::derived_from<
        typename std::iterator_traits<T>::iterator_category,
        std::input_iterator_tag>;
};

template <UnidirectionalIterator Iter>
class ByteIteratorConverter {
private:
    using value_type = typename std::iterator_traits<Iter>::value_type;

    Iter current_;
    std::size_t offset_ = 0;

public:
    using iterator_category = std::input_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type_bytes = unsigned char;
    using pointer = const unsigned char*;
    using reference = const unsigned char&;

    explicit ByteIteratorConverter(Iter iter)
        : current_(iter)
    {
    }

    pointer operator->() const
    {
        return reinterpret_cast<const unsigned char*>(std::addressof(*current_)) + offset_;
    }

    reference operator*() const
    {
        return *(this->operator->());
    }

    ByteIteratorConverter& operator++()
    {
        ++offset_;
        if (offset_ >= sizeof(value_type)) {
            offset_ = 0;
            ++current_;
        }
        return *this;
    }

    ByteIteratorConverter operator++(int)
    {
        ByteIteratorConverter tmp = *this;
        ++(*this);
        return tmp;
    }

    bool operator==(const ByteIteratorConverter& other) const
    {
        return current_ == other.current_ && offset_ == other.offset_;
    }

    bool operator!=(const ByteIteratorConverter& other) const
    {
        return !(*this == other);
    }

    pointer get_byte_ptr() const
    {
        return this->operator->();
    }

    std::size_t remaining_bytes() const
    {
        return sizeof(value_type) - offset_;
    }
};

template <UnidirectionalIterator Iter>
ByteIteratorConverter<Iter> make_byte_iterator(Iter iter)
{
    return ByteIteratorConverter<Iter>(iter);
}