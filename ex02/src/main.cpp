#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void)
{
	static bool	seed = false;

	if (!seed)
	{
		std::srand(std::clock());
		seed = true;
	}
	switch (std::rand() % 3)	
	{
		case 0:		return (new A);
		case 1:		return (new B);
		case 2:		return (new C);
		default:	return (0);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unidentified type" << std::endl;
}

void identify(Base& p)
{
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	} catch (...) {}

	try 
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	} catch (...) {}

	try 
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	} catch (...) {}
	
	std::cout << "Unidentified type" << std::endl;
}

int	main(void)
{
	Base *random = generate();
	identify(random);
	identify(*random);
	delete random;
	return (0);
}