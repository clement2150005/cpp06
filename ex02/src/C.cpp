#include "C.hpp"

C::C() {}

C::C(const C &other)
{
	// copy members here
}

C &C::operator=(const C &other)
{
	if (this != &other)
	{
		// copy members here
	}
	return (*this);
}

C::~C() {}
