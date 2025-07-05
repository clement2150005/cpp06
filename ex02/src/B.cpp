#include "B.hpp"

B::B() {}

B::B(const B &other)
{
	// copy members here
}

B &B::operator=(const B &other)
{
	if (this != &other)
	{
		// copy members here
	}
	return (*this);
}

B::~B() {}
