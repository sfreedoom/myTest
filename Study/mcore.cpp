#include <iostream>
#include "mcore.h"

void Core::f()
{
	for (int i = 0; i < 100; ++i)
	{
		Core* p = new Core();
	}
	throw std::bad_alloc();
}
