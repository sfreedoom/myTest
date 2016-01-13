#include <iostream>
#include "mclass.h"

//********************  class Normal   **********************
Normal::Normal()
{
	std::cout << "Normal Default Constructor !" << std::endl;
};
Normal::~Normal()
{
	std::cout << "Normal Default Destructor!" << std::endl;
};
int Normal::m_tmp = 4;

//*********************  class Child_One  **********************
Child_One::Child_One()
{
	std::cout << "Child_One Default Constructor!" << std::endl;
};
Child_One::~Child_One()
{
	std::cout << "Child_One Default Destructor!" << std::endl;
};

int Child_One::TmpA(int)
{
	std::cout << "Child_One! -> TmpA" << std::endl;
	return 0;
};

//*********************  class Child_Two  **********************
Child_Two::Child_Two()
{
	std::cout << "Child_Two Default Constructor!" << std::endl;
};
Child_Two::~Child_Two()
{
	std::cout << "Child_Two Default Destructor!" << std::endl;
};

Child_Two::Child_Two(const char t_a, const char t_b, const short t_i, const int t_j)
{
	m_a = t_a;
	m_b = t_b;
	m_i = t_i;
	m_j = t_j;

	std::cout << "Child_Two Constructor with Param!" << std::endl;
};

int Child_Two::TmpA(int t_a)
{
	std::cout << " Child_Two -> TmpA()!" << std::endl;
	return 1;
};

//*********************  class Child_Three  **********************
Child_Three::Child_Three()
{
	std::cout << "Child_Three Default Constructor!" << std::endl;
};

Child_Three::~Child_Three()
{
	std::cout << "Child_Three Default Destructor!" << std::endl;
};

Child_Three::Child_Three(char t_a, char t_b, short t_i, int t_j):
			m_a(t_a),
			m_b(t_b),
			m_i(t_i),
			m_j(t_j)
{
	std::cout << "Child_Three Constructor with Param!" << std::endl;
};

int Child_Three::TmpA(int t_a)
{
	std::cout << "Child_Three! -> TmpA" << std::endl;
	return 2;
};

int Child_Three::TmpB1()
{
	std::cout << "Child_Three! -> TmpB1" << std::endl;
	return 3;
};

void Child_Three::TmpB2()
{
	std::cout << "Child_Three! -> TmpB2" << std::endl;
};

//*********************  class A  **********************
A::A(char t_a):
	m_a(t_a)
{
	std::cout << "A Constructor with Param!" << std::endl;
};

int A::TmpA(int t_a)
{
	std::cout << "A-> TmpA!" << std::endl;
	return 4;	
};

