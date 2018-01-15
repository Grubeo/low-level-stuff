#include "fixed_ints.hpp"

template<unsigned PORTSIZE>
struct Port {
    llstd::uint16_t port;
    
    explicit Port(llstd::uint16_t port)
        : port(port) {}

    using value_type = llstd::fixed_width_unsigned_t<PORTSIZE>;
    
    void write(value_type value) {
        if constexpr (PORTSIZE == 8)
            asm volatile ("outb %0, %1" : : "a"(value), "Nd"(port));
        else if constexpr (PORTSIZE == 16)
            asm volatile ("outw %0, %1" : : "a"(value), "Nd"(port));
        else if constexpr (PORTSIZE == 32)
            asm volatile ("outl %0, %1" : : "a"(value), "Nd"(port));
        else 
            asm ("ud2");
    }

    value_type read() {
        value_type retval;

        if constexpr (PORTSIZE == 8)
            asm volatile ("inb %1, %0" : : "=a"(retval), "Nd"(port));
        else if constexpr (PORTSIZE == 16)
            asm volatile ("inw %1, %0" : : "=a"(retval), "Nd"(port));
        else if constexpr (PORTSIZE == 32)
            asm volatile ("inl %1, %0" : : "a"(retval), "Nd"(port));
        else 
            asm ("ud2");
    }
};
