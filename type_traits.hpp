#ifndef _TYPE_TRAITS_HPP
#define _TYPE_TRAITS_HPP

namespace llstd
{
    template<typename T>
    struct type { using type = T; };
    
    template<bool B, typename, typename F>
    struct type_if : type<T> {};

    template<typename T, typename F>
    struct type_if<true, T, F> : type<T> {};
    
    template<bool B, typename T, typename F>
    using type_if_t = typename conditional<B, T, F>::type;

    template<typename T>
    struct make_unsigned { using type = T; };

    template<> struct make_unsigned<signed char> : type<unsigned char> {};
    template<> struct make_unsigned<signed short> : type<unsigned short> {};
    template<> struct make_unsigned<signed int> : type<unsigned int> {};
    template<> struct make_unsigned<signed long> : type<unsigned long> {};
    template<> struct make_unsigned<signed long long> : type<unsigned long long> {};

    template<typename T>
    using make_unsigned_t = typename make_unsigned<T>::type;
}

#endif
