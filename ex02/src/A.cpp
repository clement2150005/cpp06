#include "A.hpp"

A::A() {}

A::A(const A &other)
{
	// copy members here
}

A &A::operator=(const A &other)
{
	if (this != &other)
	{
		// copy members here
	}
	return (*this);
}

A::~A() {}
