#pragma once

#include <limits>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <cerrno>

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
		CHAR    = 0,
		INT     = 1,
		FLOAT   = 2,
		DOUBLE  = 3,
		SPECIAL = 4,
		INVALID = -1
	};

	struct results
	{
		char	c;
		int		i;
		float	f;
		double	d;
		char	*cptr;
		int		*iptr;
		float	*fptr;
		double	*dptr;
	};
	

	typedef void (*ConvertFunc)(const std::string &);

	static ConvertFunc converters[];

	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter();

	static eType	getType(const std::string &input);

	static void	convertInt(const std::string &input);
	static void	convertChar(const std::string &input);
	static void	convertFloat(const std::string &input);
	static void	convertDouble(const std::string &input);
	static void	convertSpecial(const std::string &input);

	static void	printResults(char *c, int *i, float *f, double *d);

public:

	static void convert(const std::string &input);
};
