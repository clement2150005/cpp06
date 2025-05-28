#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {(void)other;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) { (void)other; return (*this); }
ScalarConverter::~ScalarConverter() {}

ScalarConverter::eType ScalarConverter::getType(const std::string &input)
{
	int			i = 0;
	int			dots = 0;
	int			len = input.length();

	if (input.empty())
		return (INVALID);

	if (len == 1)
	{
		if (std::isdigit(input[i]))
			return (INT);
		if (std::isprint(input[i]))
			return (CHAR);
		return (INVALID);
	}

	if(	input == "nanf" || input == "+inff" || input == "-inff" ||
		input == "nan"  || input == "+inf"  || input == "-inf")
		return (SPECIAL);

	if (!std::isdigit(input[i]))
	{
		if (input[i] != '-' && input[i] != '+')
			return (INVALID);
		i++;
	}

	while (i < len)
	{
		if (input[i] == '.')
		{
			dots++;
			if (dots > 1
				|| i == 0 || i == len - 1
				|| !std::isdigit(input[i - 1]) || !std::isdigit(input[i + 1]))
				return (INVALID);
			i++;
			continue ;
		}
		if (!std::isdigit(input[i]))
		{
			if (i != len -1 || input[i] != 'f')
				return (INVALID);
			return (FLOAT);
		}
		i++;
	}
	if (!dots)
		return (INT);
	if (len == 2)
		return (INVALID);
	return (DOUBLE);
}

void ScalarConverter::convert(const std::string &input)
{
	eType type = getType(input);
	if (type == INVALID)
		return (std::cout << "")
	ConvertFunc converters[] = {
		&convertSpecial,
		&convertChar,
		&convertInt,
		&convertFloat,
		&convertDouble
	};}
