#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Data	*test = new Data;

	test->string = "Hello, World!";

	uintptr_t	testPtr = Serializer::serialize(test);
	Data		*testCopy = Serializer::deSerialize(testPtr);

	std::cout << "Original\t" << test << "\t" << test->string << std::endl;
	std::cout << "Copy\t\t" << testCopy << "\t" << testCopy->string << std::endl;

	delete test;
	return (0);
}