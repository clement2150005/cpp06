#include "Base.hpp"

Base::Base() {}

Base::Base(const Base &other)
{
	// copy members here
}

Base &Base::operator=(const Base &other)
{
	if (this != &other)
	{
		// copy members here
	}
	return (*this);
}

Base::~Base() {}
