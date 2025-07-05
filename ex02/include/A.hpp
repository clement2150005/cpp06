#include "Base.hpp"

class A: public Base
{
private:
	
public:
	A();
	A(const A &other);
	A &operator=(const A &other);
	~A();
};
