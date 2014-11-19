#include "Singleton.h"

Singleton* getInstance()
{
	//双重锁定来提高效率，不会每一次的线程都去进行锁定
	if(NULL == my_Instance) 
	{
		//add Lock;
		if(NULL == my_Instance)
		{
			my_Instance = new Singleton();
		}
		//remove Lock;
	}
	return my_Instance;
}

void releseInstance()
{
	if(NULL != my_Instance)
	{
		//add Lock;
		delete my_Instance;	
		//remove Lock;
	}
}
