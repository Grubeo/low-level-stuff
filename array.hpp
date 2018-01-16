#include "fixed_ints.hpp"
#include "type_traits.hpp"

namespace llstd
{
    template<typename T, llstd::size_t N>
    class array 
    {
        T memory[N];
    public:
        using value_type = T;
        using size_type = llstd::size_t;
        using difference_type = llstd::ptrdiff_t;
        using reference = T&;
        using const_reference = const T&;
        using iterator = T*; 

        constexpr array() = default;
        constexpr array(const array&) = default;
        constexpr array(array&&) = default;
        ~array() = default;

        constexpr array& operator=(const array&) = default;
        constexpr array& operator=(array&&) = default;

        template<typename ...Types>
        constexpr array(Types && ... values)
            : memory{std::move(values)...} {}

        constexpr reference front() { return *memory; }
        constexpr const_reference front() const { return *memory; }

        constexpr reference back() { return memory[N-1]; }
        constexpr const_reference back() const { return memory[N-1]; }
    
        constexpr reference operator[](llstd::size_t n) {
            return memory[n];
        }

        constexpr const_reference operator[](llstd::size_t n) const {
            return memory[n];
        }

        constexpr bool empty() const { return N == 0; }
        constexpr size_type size() const { return N; }
        constexpr size_type max_size() const { return N; }


        constexpr iterator begin() { return memory; }
        constexpr iterator end() { return memory + N; }
        
        constexpr void fill(const T& v) {
            for (auto &e : memory)
                e = v;
        }
    };

    template<typename ...T>
    array(T&&...) -> array<llstd::common_type_t<T...>, sizeof...(T)>;
}
