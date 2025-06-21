#include "ScalarConverter.hpp"

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

	if (input == "nanf" || input == "+inff" || input == "inff" || input == "-inff")
		return (SPECIAL);
	if (input == "nan" || input == "+inf" || input == "inf"|| input == "-inf")
		return (SPECIAL);

	if (!std::isdigit(input[i]))
	{
		if (input[i] != '-' && input[i] != '+' && input[i] != '.')
			return (INVALID);
		if (input[i] == '.')
			dots++;
		i++;
	}

	while (i < len)
	{
		if (input[i] == '.')
		{
			dots++;
			if (dots > 1 || ((i == 0 || !std::isdigit(input[i - 1])) && (i + 1 >= len || !std::isdigit(input[i + 1]))))
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
	return (DOUBLE);
}

void	ScalarConverter::printResults(char *c, int *i, float *f, double *d)
{
	std::cout << "char:\t";
	if (!c)
		std::cout << "impossible";
	else if (!isprint(*c))
		std::cout << "Non displayable";
	else
		std::cout << "'" << *c << "'";
	std::cout << std::endl;

	std::cout << "int:\t";
	if (i)
		std::cout << *i << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float:\t";
	if (f)
	{
		if (std::floor(*f) == *f)
			std::cout << std::fixed << std::setprecision(1);
		std::cout << *f << "f";
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;

	std::cout << "double:\t";
	if (d)
	{
		if (std::floor(*d) == *d)
			std::cout << std::fixed << std::setprecision(1);
		std::cout << *d;
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;
}

void	ScalarConverter::convertInt(const std::string &input)
{
	results	r;

	long l = std::strtol(input.c_str(), NULL, 10);
	if (l > MAX_INT || l < MIN_INT)
		return (printResults(NULL, NULL, NULL, NULL));
	
	r.i = static_cast<int>(l);
	r.c = static_cast<char>(r.i);
	r.f = static_cast<float>(r.i);
	r.d = static_cast<double>(r.i);

	r.iptr = &r.i;
	if (r.i >= 0 && r.i <= 127)
		r.cptr = &r.c;
	else
		r.cptr = NULL;
	r.fptr = &r.f;
	r.dptr = &r.d;

	printResults(r.cptr, r.iptr, r.fptr, r.dptr);
}

void	ScalarConverter::convertChar(const std::string &input)
{
	results	r;

	r.c = input[0];
	r.i = static_cast<int>(r.c);
	r.f = static_cast<float>(r.c);
	r.d = static_cast<double>(r.c);

	r.cptr = &r.c;
	r.iptr = &r.i;
	r.fptr = &r.f;
	r.dptr = &r.d;

	printResults(r.cptr, r.iptr, r.fptr, r.dptr);
}

void	ScalarConverter::convertFloat(const std::string &input)
{
	results	r;
	errno = 0;
	std::cout << "ok" << std::endl;
	r.f = strtof(input.c_str(), NULL);
	if (errno == ERANGE)
		return (printResults(NULL, NULL, NULL, NULL));

	r.c = static_cast<char>(r.f);
	r.i = static_cast<int>(r.f);
	r.d = static_cast<double>(r.f);

	if (r.i >= 0 && r.i <= 127)
		r.cptr = &r.c;
	else
		r.cptr = NULL;
	if (r.f > MAX_INT || r.f < MIN_INT)
		r.iptr = NULL;
	else
		r.iptr = &r.i;
	r.fptr = &r.f;
	r.dptr = &r.d;
	printResults(r.cptr, r.iptr, r.fptr, r.dptr);
}

void	ScalarConverter::convertDouble(const std::string &input)
{
	results	r;
	errno = 0;

	r.d = strtod(input.c_str(), NULL);
	if (errno == ERANGE)
		return (printResults(NULL, NULL, NULL, NULL));

	r.c = static_cast<char>(r.d);
	r.i = static_cast<int>(r.d);
	r.f = static_cast<float>(r.d);
	if (r.i >= 0 && r.i <= 127)
		r.cptr = &r.c;
	else
		r.cptr = NULL;
	if (r.d > MAX_INT || r.d < MIN_INT)
		r.iptr = NULL;
	else
		r.iptr = &r.i;
	r.fptr = &r.f;
	r.dptr = &r.d;

	printResults(r.cptr, r.iptr, r.fptr, r.dptr);
}

void	ScalarConverter::convertSpecial(const std::string &input)
{
	results	r;

	r.d = strtod(input.c_str(), NULL);
	r.f = static_cast<float>(r.d);
	r.fptr = &r.f;
	r.dptr = &r.d;

	printResults(NULL, NULL, r.fptr, r.dptr);
}

void ScalarConverter::convert(const std::string &input)
{
	eType type = getType(input);
	std::cout << type << std::endl;
	if (type == INVALID)
	{
		printResults(NULL, NULL, NULL, NULL);
		return ;
	}
	ConvertFunc converters[] = {
		&convertChar,
		&convertInt,
		&convertFloat,
		&convertDouble,
		&convertSpecial
	};
	converters[type](input);
}
