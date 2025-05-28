#pragma once

#include <limits>
#include <iostream>

# define MIN_INT	std::numeric_limits<int>::min()
# define MAX_INT	std::numeric_limits<int>::max()
# define MIN_FLOAT	std::numeric_limits<float>::lowest()
# define MAX_FLOAT	std::numeric_limits<float>::max()
# define MIN_DOUBLE	std::numeric_limits<double>::lowest()
# define MAX_DOUBLE	std::numeric_limits<double>::max()

class ScalarConverter
{
private:

	enum eType
	{
		SPECIAL = 0,
		CHAR    = 1,
		INT     = 2,
		FLOAT   = 3,
		DOUBLE  = 4,
		INVALID = -1
	};

	typedef void (*ConvertFunc)(const std::string &);

	static ConvertFunc converters[];

	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static void	convertSpecial(const std::string &input);
	static void	convertInt(const std::string &input);
	static void	convertChar(const std::string &input);
	static void	convertFloat(const std::string &input);
	static void	convertDouble(const std::string &input);

	static eType	getType(const std::string &input);

public:

	static void convert(const std::string &input);
};
