#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(argv[1]);
		return 0;
	}

	const char* tests[] = {
		// valid ints
		"0", "1", "-1", "+42", "2147483647", "-2147483648",

		// invalid ints
		"2147483648", "-2147483649", "123abc", "++1", "--2",

		// valid chars
		"a", "Z", "!", "0",

		// invalid chars
		"\x01", "\x7f",

		// valid floats
		"0.0f", "1.0f", "-3.14f", "+.5f", "42.f", ".1f", "1.234567f",

		// float edge cases
		"340282346638528859811704183484516925440.0f", // FLT_MAX
		"3402824000.0f", // overflow float

		// valid doubles
		"0.0", "-1.0", "3.14", ".1", "1.", "-.5", "42.424242",

		// double edge cases
		"1e308", // DBL_MAX-ish
		"1e309", // overflow

		// special literals
		"nan", "+inf", "-inf", "inf", "nanf", "+inff", "-inff", "inff",

		// invalid input
		"abc", ".", "+.", "-.", "..", "4.2ff", "1.2.3", "", "+-1", "1+1", "f", "1f1", "1.0ff"
	};

	for (size_t i = 0; i < sizeof(tests) / sizeof(*tests); ++i)
	{
		std::cout << "=== " << tests[i] << " ===" << std::endl;
		ScalarConverter::convert(tests[i]);
		std::cout << std::endl;
	}

	return 0;
}
