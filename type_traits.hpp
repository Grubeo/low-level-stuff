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
    struct make_unsigned : type_is<T> {};

    template<> struct make_unsigned<signed char> : type_is<unsigned char> {};
    template<> struct make_unsigned<signed short> : type_is<unsigned short> {};
    template<> struct make_unsigned<signed int> : type_is<unsigned int> {};
    template<> struct make_unsigned<signed long> : type_is<unsigned long> {};
    template<> struct make_unsigned<signed long long> : type_is<unsigned long long> {};

    template<typename T>
    using make_unsigned_t = typename make_unsigned<T>::type;
    
    template<typename T>
    struct make_signed : type_is<T> {};
    
    template<> struct make_signed<unsigned char> : type_is<signed char> {};
    template<> struct make_signed<unsigned short> : type_is<signed short> {};
    template<> struct make_signed<unsigned int> : type_is<signed int> {};
    template<> struct make_signed<unsigned long> : type_is<signed long> {};
    template<> struct make_signed<unsigned long long> : type_is<signed long long> {};
    
    template<typename T>
    using make_signed_t = typename make_signed<T>::type;
}

#endif
