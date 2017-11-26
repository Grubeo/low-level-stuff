namespace std
{
    template<bool B, typename, typename F>
    struct conditional { using type = F; };

    template<typename T, typename F>
    struct conditional<true, T, F> { using type = T; };

    template<bool B, typename T, typename F>
    using conditional_t = typename conditional<B, T, F>::type;

    template<typename T>
    struct make_unsigned { using type = T; };

    template<> struct make_unsigned<signed char> { using type = unsigned char; };
    template<> struct make_unsigned<signed short> { using type = unsigned short; };
    template<> struct make_unsigned<signed int> { using type = unsigned int; };
    template<> struct make_unsigned<signed long> { using type = unsigned long; };
    template<> struct make_unsigned<signed long long> { using type = unsigned long long; };

    template<typename T>
    using make_unsigned_t = typename make_unsigned<T>::type;
}
