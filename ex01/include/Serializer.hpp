#include "data.hpp"
#include <stdint.h>

class Serializer
{
private:

	Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);
	~Serializer();
	
public:

	static uintptr_t serialize(Data* ptr);
	static Data* deSerialize(uintptr_t raw);
};
