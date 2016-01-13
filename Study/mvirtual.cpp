#include "mvirtual.h"

//One
		One::One(){	std::cout << " One::One()" << std::endl; }
		//One::~One(){std::cout << " One::~One()" << std::endl; };
		void One::TmpA1(){	std::cout << " One::TmpA1()" << std::endl;	}
		void One::TmpA2(){	std::cout << " One::TmpA2()" << std::endl;	}
		int One::Tmp_One (int i)
		{ std::cout << " One::Tmp_One() " << std::endl; 
			return i;
		}

