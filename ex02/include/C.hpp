#include "Base.hpp"

class C: public Base
{
private:
	
public:

	C();
	C(const C &other);
	C &operator=(const C &other);
	~C();

};
