#ifndef _TYPE_TRAITS_HPP
#define _TYPE_TRAITS_HPP

#include "fixed_ints.hpp"

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

        template<typename...> struct type_or;
    template<class T> struct type_or<T> : llstd::type_is<T> {};
    
    template<class T, class... Rest>
    struct type_or<T, Rest...> 
        : llstd::type_if_t<bool(T::value), T, llstd::type_or<Rest...>>  { };

    template<typename ...T>
    constexpr auto type_or_v = type_or<T...>::value;

    template<typename T>
    struct is_array : llstd::false_type {};

    template<typename T>
    struct is_array<T[]> : llstd::true_type {};

    template<typename T, llstd::size_t N> 
    struct is_array<T[N]> : llstd::true_type {};

    template<typename T>
    constexpr auto is_array_v = llstd::is_array<T>::value;

    template<typename T>
    struct remove_extent : type_is<T> {};

    template<typename T>
    struct remove_extent<T[]> : type_is<T> {};

    template<typename T, llstd::size_t N>
    struct remove_extent<T[N]> : type_is<T> {};

    template<typename T>
    using remove_extent_t = typename llstd::remove_extent<T>::type;

    template<typename T1, typename T2> struct is_same : llstd::false_type {};
    template<typename T> struct is_same<T, T> : llstd::true_type {};
    template<typename ...T> constexpr auto is_same_v = llstd::is_same<T...>::value;

    template<typename T> struct remove_reference 
        : llstd::type_is<T> {};

    template<typename T> struct remove_reference<T&> 
        : llstd::type_is<T> {};

    template<typename T> struct remove_reference<T&&> 
        : llstd::type_is<T> {};

    template<typename T>
    using remove_reference_t = typename llstd::remove_reference<T>::type;

    template<typename T>
    struct remove_volatile : type_is<T> {};

    template<typename T>
    struct remove_volatile<volatile T> : type_is<T> {};

    template<typename T>
    using remove_volatile_t = typename remove_volatile<T>::type;

    template<typename T>
    struct remove_const : type_is<T> {};

    template<typename T>
    struct remove_const<const T> : type_is<T> {};

    template<typename T>
    using remove_const_t = typename remove_const<T>::type;    

    template<typename T>
    struct remove_cv : type_is<
        llstd::remove_volatile_t<
            llstd::remove_const_t<T>
        >
    > {};

    template<typename T>
    using remove_cv_t = typename remove_cv<T>::type;

    template<typename T>
    struct add_pointer : type_is<T*> {};

    template<typename T>
    using add_pointer_t = typename add_pointer<T>::type;

    template<typename T> T&& declval();

#include "is_function.hpp"

    template<typename T>
    struct decay {
    private:
        using U = typename llstd::remove_reference<T>::type;
    public:
        using type = llstd::type_if_t<
            llstd::is_array<U>::value,
            llstd::remove_extent<U>::type*,
            llstd::type_if_t<
                llstd::is_function<U>::value,
                llstd::add_pointer_t<U>,
                llstd::remove_cv<U>::type
            >
        >;
    };

    template<typename ...>
    struct common_type {};

    template<typename T>
    struct common_type<T> : llstd::common_type<T, T> {};


    template<typename T1, typename T2>
    struct common_type<T1, T2> : llstd::type_is<
        llstd::type_if_t<
            llstd::type_or<
                llstd::is_same<std::decay_t<T1>, T1>, 
                llstd::is_same<std::decay_t<T2>, T2>>{},
            typename common_type<std::decay_t<T1>, llstd::decay_t<T2>>::type,
            std::decay_t<decltype(false ? llstd::declval<T1>() : llstd::declval<T2>())>
        >
    > {};

    template<typename T1, typename T2, typename ...Rest>
    struct common_type<T1, T2, Rest...> : llstd::type_is<
        typename llstd::common_type<
            typename llstd::common_type<T1, T2>::type, Rest...
        >::type
    > {};

    template<typename ...T>
    using common_type_t = typename llstd::common_type<T...>::type;
    
    template<llstd::size_t N, typename First, typename ...Rest>
    struct get_n { using type = typename get_n<N-1, Rest...>::type; };

    template<typename First, typename ...Rest>
    struct get_n<0, First, Rest...> { using type = First; };

    template<llstd::size_t N, typename ...T>
    using get_n_t = typename get_n<N, T...>::type;
}

#endif
