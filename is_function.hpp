template<class>
struct is_function : llstd::false_type { };
 
// specialization for regular functions
template<class Ret, class... Args>
struct is_function<Ret(Args...)> : llstd::true_type {};
 
// specialization for variadic functions such as llstd::printf
template<class Ret, class... Args>
struct is_function<Ret(Args......)> : llstd::true_type {};
 
// specialization for function types that have cv-qualifiers
template<class Ret, class... Args>
struct is_function<Ret(Args...) const> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) volatile> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const volatile> : llstd::true_type {};
 
// specialization for function types that have ref-qualifiers
template<class Ret, class... Args>
struct is_function<Ret(Args...) &> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const &> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile &> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile &> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) &> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const &> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) volatile &> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const volatile &> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) &&> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const &&> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile &&> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile &&> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) &&> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const &&> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) volatile &&> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const volatile &&> : llstd::true_type {};
 
// specializations for noexcept versions of all the above (C++17 and later)
 
template<class Ret, class... Args>
struct is_function<Ret(Args...) noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) volatile noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const volatile noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) & noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const & noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile & noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile & noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) & noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const & noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) volatile & noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const volatile & noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) && noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const && noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) volatile && noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args...) const volatile && noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) && noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const && noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) volatile && noexcept> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......) const volatile && noexcept> : llstd::true_type {};
