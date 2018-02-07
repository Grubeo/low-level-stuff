template<class>
struct is_function : llstd::false_type { };
template<class Ret, class... Args>
struct is_function<Ret(Args...)> : llstd::true_type {};
template<class Ret, class... Args>
struct is_function<Ret(Args......)> : llstd::true_type {};
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
