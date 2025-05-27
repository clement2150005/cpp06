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

	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

public:

	enum eType // make it private
	{
		SPECIAL = 0,
		CHAR    = 1,
		INT     = 2,
		FLOAT   = 3,
		DOUBLE  = 4,
		INVALID = -1
	};

	static eType	getType(const std::string &input); // make it private
	static void convert(const std::string &input);
};
