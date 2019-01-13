template<unsigned PORTSIZE>
struct Port 
{
	using value_type = llstd::fixed_width_unsigned_t<PORTSIZE>;
	llstd::uint16_t portNumber;
	
	explicit Port(llstd::uint16_t port)
		: portNumber(port)
	{
		static_assert(in_list_v<PORTSIZE, 8, 16, 32>,
			"Intel architecture does not support not 8, 16 or 32 bits ports.");
	}

	void write(value_type value) const noexcept
	{
		if constexpr (PORTSIZE == 8)
			asm volatile ("outb %0, %1" : : "a"(value), "Nd"(portNumber));
		else if constexpr (PORTSIZE == 16)
			asm volatile ("outw %0, %1" : : "a"(value), "Nd"(portNumber));
		else if constexpr (PORTSIZE == 32)
			asm volatile ("outl %0, %1" : : "a"(value), "Nd"(portNumber));
	}

	value_type read() const noexcept
	{
		value_type readData;

		if constexpr (PORTSIZE == 8)
			asm volatile ("inb %1, %0" : : "=a"(readData), "Nd"(portNumber));
		else if constexpr (PORTSIZE == 16)
			asm volatile ("inw %1, %0" : : "=a"(readData), "Nd"(portNumber));
		else if constexpr (PORTSIZE == 32)
			asm volatile ("inl %1, %0" : : "a"(readData), "Nd"(portNumber));
	
		return readData;
	}
};
