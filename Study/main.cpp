#include <iostream>
#include <stdio.h>
#include <stddef.h>
#include "mclass.h"
#include "mvirtual.h"
#include "mcore.h"
#include "mtest.h"

typedef long long*  __SIZE__;

void print_Sizeof()
{
	std::cout << "******************** sizeof(class) ******************\n" << std::endl;
	std::cout << "sizeof(_BaseA) = " << sizeof(_BaseA) << std::endl;
	std::cout << "sizeof(_BaseB) = " << sizeof(_BaseB) << std::endl;
	std::cout << "sizeof(Normal) = " << sizeof(Normal) << std::endl;
	std::cout << "sizeof(Child_One) = " << sizeof(Child_One) << std::endl;
	std::cout << "sizeof(Child_Two) = " << sizeof(Child_Two) << std::endl;
	std::cout << "sizeof(Child_Three) = " << sizeof(Child_Three) << std::endl;


	std::cout << "sizeof(U_A) = " << sizeof(U_A) << std::endl;
	std::cout << "sizeof(T_A) = " << sizeof(T_A) << std::endl;

};

void print_Polymorphism()
{
	std::cout << "\n******************** C++_Polypeptide ******************" << std::endl;

	std::cout << "\n^^^^^   _BaseA* ptr->new Child_Three()   ^^^^^" << std::endl;
	_BaseA* m_ptr[3];
	memset(m_ptr, 0, sizeof(_BaseA*) * 3);
	//m_ptr = new _BaseA();//抽象类不能实例化对象,只作为接口使用
	m_ptr[0] = new Child_One();
	m_ptr[1] = new Child_Two();
	m_ptr[2] = new Child_Three();

	delete m_ptr[0];
	delete m_ptr[1];
	delete m_ptr[2];
	
	std::cout << "\n^^^^^   _Child_Three* ptr->new A()   ^^^^^"<< std::endl;
	Child_Three* my_Ptr = NULL;
	//my_Ptr = new Child_Three(48, 65, 56, 89); //隐式转换，没有用explicit关键阻止隐式转换
	//my_Ptr = new Child_Three('7', '6', 56, 89);
	my_Ptr = new A(43);
	my_Ptr->TmpA(1);
	delete my_Ptr;
};

void print_VT()
{
	std::cout << "\n******************** Virtual-Table ******************" << std::endl;

	typedef void(*Func)(void);
	Func pFunc = NULL;
	typedef int(*Func2)(int);
	Func2 pFunc2 = NULL;

	Ch m_Three;	
	Ch m_Three2;	
	int myReturnValue = sizeof(Ch);
	std::cout << " sizeof(Ch) " << myReturnValue << std::endl;

	std::cout << " m_Three first vptr (&m_Three): " << (__SIZE__)(&m_Three) << std::endl;
	std::cout << " m_Three first vtable (*(&m_Three)): " << (__SIZE__)*(__SIZE__)(&m_Three) << std::endl;
	std::cout << " m_Three first function *(*(&m_Three)):  " << (__SIZE__)*(__SIZE__)*(__SIZE__)(&m_Three) << std::endl;

	printf("\n");
	std::cout << " m_Three  vptr1 (&m_Three): " << (__SIZE__)(&m_Three) << std::endl;
	std::cout << " m_Three  vptr2 (&m_Three): " << (__SIZE__)(&m_Three) + 1 << std::endl;
	std::cout << " m_Three  vptr3 (&m_Three): " << (__SIZE__)(&m_Three) + 2 << std::endl;
	std::cout << " m_Three  vptr4 (&m_Three): " << (__SIZE__)(&m_Three) + 3 << std::endl;
	std::cout << " m_Three  vptr5 (&m_Three): " << (__SIZE__)(&m_Three) + 4 << std::endl;
	std::cout << " m_Three  vptr6 (&m_Three): " << (__SIZE__)(&m_Three) + 5 << std::endl;

	std::cout << " \nV_T 1: " << std::endl;
	pFunc = (Func)*((__SIZE__)*(__SIZE__)(&m_Three));
	printf(" 1 addr: %p", pFunc);
	pFunc();
	pFunc = (Func)*((__SIZE__)*(__SIZE__)(&m_Three) + 1);
	printf(" 2 addr: %p", pFunc);
	pFunc();
	pFunc2 = (Func2)*((__SIZE__)*(__SIZE__)(&m_Three) + 2);
	printf(" 3 addr: %p", pFunc2);
	myReturnValue = pFunc2(67); 
	std::cout << " \n One ReturnValue: " << myReturnValue << std::endl;

	std::cout << " \nV_T 2: " << std::endl;
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three) + 1));
	printf(" 1 addr: %p", pFunc);
	pFunc();
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three) + 1) + 1);
	printf(" 2 addr: %p", pFunc);
	pFunc();
	pFunc2 = (Func2)*((__SIZE__)*((__SIZE__)(&m_Three) + 1) + 2);
	printf(" 3 addr: %p", pFunc2);
	myReturnValue = pFunc2(8); 
	std::cout << " \n Two ReturnValue: " << myReturnValue << std::endl;

	std::cout << " \nV_T 3: " << std::endl;
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three) + 2));
	printf(" 1 addr: %p", pFunc);
	pFunc();
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three)+ 2) + 1);
	printf(" 2 addr: %p", pFunc);
	pFunc();
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three)+ 2) + 2);
	printf(" 3 addr: %p", pFunc);
	pFunc();

	std::cout << " \nV_T 4: " << std::endl;
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three)+ 3));
	printf(" 1 addr: %p", pFunc);
	pFunc();
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three)+ 3) + 1);
	printf(" 2 addr: %p", pFunc);
	pFunc();
	pFunc2 = (Func2)*((__SIZE__)*((__SIZE__)(&m_Three)+ 3) + 2);
	printf(" 3 addr: %p", pFunc2);
	myReturnValue = pFunc2(69); 
	std::cout << "\n ReturnValue: " << myReturnValue << std::endl;

	std::cout << " \nV_T 5: " << std::endl;
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three)+ 4));
	printf(" 1 addr: %p", pFunc);
	pFunc();
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three)+ 4) + 1);
	printf(" 2 addr: %p", pFunc);
	pFunc();
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three)+ 4) + 2);
	printf(" 3 addr: %p", pFunc);
	pFunc();

	std::cout << " \nV_T 6: " << std::endl;
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three)+ 5));
	printf(" 1 addr: %p", pFunc);
	pFunc();
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three)+ 5) + 1);
	printf(" 2 addr: %p", pFunc);
	pFunc();
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three)+ 5) + 2);
	printf(" 3 addr: %p", pFunc);
	pFunc();
	pFunc = (Func)*((__SIZE__)*((__SIZE__)(&m_Three)+ 5) + 3);
	printf(" 4 addr: %p", pFunc);
	pFunc();

	//********************** Base* ptr-> Derive **************************
	Three *myThree = &m_Three;
	printf(" \n\n myThree addr: %p", myThree);
	//myThree->TmpA1();
	//myThree->Afunc();
	myThree = (Three*)(*((__SIZE__)*(__SIZE__)(myThree)));
	//myThree = dynamic_cast<Three*>(*((__SIZE__)*(__SIZE__)(myThree)));
	printf(" \n\n myThree addr: %p", myThree);
	((Func)myThree)();
	printf(" \n myThree addr: %p", myThree+1);
	printf(" \n myThree addr: %p", myThree+2);
	((Func)(myThree+2))();
	printf(" \n myThree addr: %p", myThree+3);
	printf(" \n myThree addr: %p", myThree+4);
	printf(" \n myThree addr: %p", myThree+5);
	printf(" \n myThree addr: %p", myThree+6);
	//(((Func2)*(&myThree + 1)))();
	//
	//myThree->tmp_Three();
	//myThree->AFunc(4);
};

void test_Core()
{
	Core myCore;
	myCore.f();
}

void print_Test()
{
	B theB;
	std::cout << " sizeof(theB): " << sizeof(theB) << std::endl;
	AB* ptrAB  = &theB;
	std::cout << " sizeof(ptrAB): " << sizeof(*ptrAB) << std::endl;
	ptrAB->test();
	ptrAB->ptr();
}

int main()
{
	//sizeof(class*)
	//print_Sizeof();

	//C++ Polypeptide
	//print_Polymorphism();
	
	//C++ VT
	print_VT();
	
	//Test CoreDump
	//test_Core();

	//Test ptr 
	//print_Test();	

	return 0;
}
