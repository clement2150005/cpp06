#include <iostream>
#include "ScalarConverter.hpp"
#include <iomanip>

static const char* typeName(ScalarConverter::eType type) {
	switch (type) {
		case ScalarConverter::CHAR: return "CHAR";
		case ScalarConverter::INT: return "INT";
		case ScalarConverter::FLOAT: return "FLOAT";
		case ScalarConverter::DOUBLE: return "DOUBLE";
		case ScalarConverter::SPECIAL: return "SPECIAL";
		case ScalarConverter::INVALID: return "INVALID";
		default: return "UNKNOWN";
	}
}

static void testType(const std::string &input, ScalarConverter::eType expected) {
	static int testNumber = 1;

	ScalarConverter::eType actual = ScalarConverter::getType(input);

	std::string displayInput = input;
	if (displayInput.length() > 10)
		displayInput = input.substr(0, 9) + ".";

	std::cout << std::left
	          << "[" << std::setw(3) << testNumber++ << "] "
	          << std::setw(13) << ("\"" + displayInput + "\"")
	          << "exp: " << std::setw(8) << typeName(expected)
	          << "got: " << std::setw(8) << typeName(actual)
	          << "| ";

	if (actual == expected)
		std::cout << "\033[32mOK\033[0m";
	else
		std::cout << "\033[31mKO\033[0m";

	std::cout << std::endl;
}

int main() {
	testType("2147483648", ScalarConverter::INVALID); // INT overflow
	testType("-2147483649", ScalarConverter::INVALID); // INT underflow
	testType("340282350000000000000000000000000000000", ScalarConverter::INVALID); // FLOAT overflow
	testType("-340282350000000000000000000000000000000", ScalarConverter::INVALID); // FLOAT underflow
	testType("179769313486231570000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", ScalarConverter::INVALID); // DOUBLE overflow
	testType("-179769313486231570000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000.0", ScalarConverter::INVALID); // DOUBLE underflow
    testType("a", ScalarConverter::CHAR);
    testType("@", ScalarConverter::CHAR);
    testType("~", ScalarConverter::CHAR);
    testType(" ", ScalarConverter::CHAR);
    testType("0", ScalarConverter::INT);
    testType("42", ScalarConverter::INT);
    testType("-1", ScalarConverter::INT);
    testType("+100", ScalarConverter::INT);
    testType("-2147483648", ScalarConverter::INT);
    testType("2147483647", ScalarConverter::INT);
    testType("0.0f", ScalarConverter::FLOAT);
    testType("-0.1f", ScalarConverter::FLOAT);
    testType("3.4028235e+38f", ScalarConverter::INVALID);
    testType("1.17549435e-38f", ScalarConverter::INVALID);
    testType("-3.4028235e+38f", ScalarConverter::INVALID);
    testType("+0.000001f", ScalarConverter::FLOAT);
    testType("0.0", ScalarConverter::DOUBLE);
    testType("-0.1", ScalarConverter::DOUBLE);
    testType("1.7976931348623157e+308", ScalarConverter::INVALID);
    testType("2.2250738585072014e-308", ScalarConverter::INVALID);
    testType("-1.7976931348623157e+308", ScalarConverter::INVALID);
    testType("+0.00000000001", ScalarConverter::DOUBLE);
    testType("nan", ScalarConverter::SPECIAL);
    testType("+inf", ScalarConverter::SPECIAL);
    testType("-inf", ScalarConverter::SPECIAL);
    testType("nanf", ScalarConverter::SPECIAL);
    testType("+inff", ScalarConverter::SPECIAL);
    testType("-inff", ScalarConverter::SPECIAL);
    testType("", ScalarConverter::INVALID);
    testType(".", ScalarConverter::CHAR);
    testType("-", ScalarConverter::CHAR);
    testType("+", ScalarConverter::CHAR);
    testType("f", ScalarConverter::CHAR);
    testType("--1", ScalarConverter::INVALID);
    testType("++1", ScalarConverter::INVALID);
    testType("1.1.1", ScalarConverter::INVALID);
    testType("1f1", ScalarConverter::INVALID);
    testType("4.2.0f", ScalarConverter::INVALID);
    testType("2147483648", ScalarConverter::INVALID);
    testType("-2147483649", ScalarConverter::INVALID);
    testType("3.5e+38f", ScalarConverter::INVALID);
    testType("1e+309", ScalarConverter::INVALID);
    testType("1.0ff", ScalarConverter::INVALID);
    testType("4f.2", ScalarConverter::INVALID);
    testType("0.f", ScalarConverter::INVALID);
    testType("..1", ScalarConverter::INVALID);
    testType("1..", ScalarConverter::INVALID);
    testType("--", ScalarConverter::INVALID);
    testType("1ff", ScalarConverter::INVALID);
    testType("nanff", ScalarConverter::INVALID);
    testType("inf", ScalarConverter::INVALID);
    return 0;
}