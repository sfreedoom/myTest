#include <iostream>

class Singleton
{
pubilc:
	Singleton* getInstance();
	void releseInstance();
private:
	Singleton();
	static Singleton* my_Instance;
};
