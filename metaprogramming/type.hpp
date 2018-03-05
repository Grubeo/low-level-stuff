#pragma once

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
    
    template<typename...> struct type_or;
    template<class T> struct type_or<T> : llstd::type_is<T> {};
    
    template<class T, class... Rest>
    struct type_or<T, Rest...> : llstd::type_if_t<bool(T::value), T, llstd::type_or<Rest...>>  { };

    template<typename ...T>
    constexpr auto type_or_v = type_or<T...>::value;
}
