#ifndef _TYPE_TRAITS_HPP
#define _TYPE_TRAITS_HPP

namespace llstd
{
    template<typename T>
    struct type_is { using type = T; };
    
    template<bool B, typename, typename F>
    struct type_if : type_is<T> {};

    template<typename T, typename F>
    struct type_if<true, T, F> : type_is<T> {};
    
    template<bool B, typename T, typename F>
    using type_if_t = typename type_if<B, T, F>::type;

    template<typename T>
    struct make_unsigned { using type = T; };

    template<> struct make_unsigned<signed char> : type_if<unsigned char> {};
    template<> struct make_unsigned<signed short> : type_if<unsigned short> {};
    template<> struct make_unsigned<signed int> : type_if<unsigned int> {};
    template<> struct make_unsigned<signed long> : type_if<unsigned long> {};
    template<> struct make_unsigned<signed long long> : type_if<unsigned long long> {};

    template<typename T>
    using make_unsigned_t = typename make_unsigned<T>::type;
}

#endif
