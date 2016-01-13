#ifndef __MTESTH__
#define __MTESTH__

typedef void (*fvoid)();

class AB
{
	public:
		static void test()
		{
			std::cout << "AB::test()" << std::endl;
		}

		fvoid ptr;

		AB(){ ptr = AB::test; };
};

class B : public AB
{
	public:
		static void test()
		{
			std::cout << "B::test()" << std::endl;
		}

		B(){ ptr = B::test; };
};

#endif //__MTESTH__
