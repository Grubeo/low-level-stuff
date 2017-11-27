#include <type_traits>
#include <utility>

template<typename T> struct type_is { using type = T; };

template<typename First, typename ...Rest>
struct foreach_sizeof
{
    constexpr static auto value = sizeof(First) +
        foreach_sizeof<Rest...>::value;
};

template<typename T>
struct foreach_sizeof<T>
{
    constexpr static auto value = sizeof(T);
};

template<unsigned, unsigned, typename ...>
struct offsetof {
    constexpr static decltype(sizeof(0)) value = 0;
};

template<unsigned E, unsigned I, typename T, typename ...TR>
struct offsetof<E, I, T, TR...> {
    constexpr static auto value = E == I ? 0 : sizeof(T) + offsetof<E, I+1, TR...>::value;
};

template<unsigned, unsigned, typename ...>
struct get_n : type_is<void> {};

template<unsigned E, unsigned I, typename T, typename ...TR>
struct get_n<E,I,T,TR...> : type_is<std::conditional_t<E == I, T, typename get_n<E, I+1, TR...>::type>> {};


template<typename ...T>
class tuple 
{
    template<size_t N, size_t ...I>
    static constexpr void create_tuple(char (&array)[N], std::index_sequence<I...>)
    {
        (void)((new (array + offsetof<I, 0, T...>::value) typename get_n<I, 0, T...>::type, 0) + ...);
    }

    template<size_t N, size_t ...I>
    static constexpr void create_tuple(char (&array)[N], T&&...t)
    {
        unsigned offset = 0;
        (void)std::initializer_list<unsigned>{
            (new (array + offset) std::remove_reference_t<decltype(t)> {t}, offset += sizeof(t))...
        };
    }

public:
    char mem[foreach_sizeof<T...>::value];

    constexpr tuple() { create_tuple(mem, std::make_index_sequence<sizeof...(T)>{}); }
    constexpr tuple(T&& ...t) { create_tuple(mem, std::forward<T>(t)...); }

    ~tuple() { 
        // TODO
     }
};

template<unsigned I, typename ...Tuple>
constexpr auto get(tuple<Tuple...> &t) -> std::add_lvalue_reference_t<typename get_n<I, 0, Tuple...>::type>
{
    return *reinterpret_cast<std::add_pointer_t<typename get_n<I, 0, Tuple...>::type>>(
        t.mem + offsetof<I, 0, Tuple...>::value
    );
}

int main()
{
    tuple<int, int> t(10, 20);
    get<0>(t) = 15;
    return get<0>(t) + get<1>(t);
}
