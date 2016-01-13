#ifndef __MVIRTUAL_HH
#define __MVIRTUAL_HH

#include <iostream>

class _Base1
{
	public:
		virtual void TmpA1() = 0;
		virtual void TmpA2() = 0;

		virtual ~_Base1(){};
};

class _Base2
{
	public:
		virtual void TmpB1() = 0;
		virtual void TmpB2() = 0;
		virtual void TmpB3() = 0;

		virtual ~_Base2(){};
};

class _Base3
{
	public:
		virtual void TmpC1() = 0;
		virtual void TmpC2() = 0;
		virtual void TmpC3() = 0;
		virtual void TmpC4() = 0;

		virtual ~_Base3(){};
};

class One: public _Base1
{
	public:
		One();
		//~One();
	private:
		virtual void TmpA1();
		virtual void TmpA2();
		virtual int Tmp_One (int i);
};

class Two : public _Base1, _Base2
{
	//public:
	private:
		virtual void TmpA1(){	std::cout << " Two::TmpA1()" << std::endl;	}
		virtual void TmpA2(){	std::cout << " Two::TmpA2()" << std::endl;	}

		virtual void TmpB1(){	std::cout << " Two::TmpB1()" << std::endl;	}
		virtual void TmpB2(){	std::cout << " Two::TmpB2()" << std::endl;	}
		virtual void TmpB3(){	std::cout << " Two::TmpB3()" << std::endl;	}

		virtual int Tmp_Two (int i){ std::cout << " Two::Tmp_Two() " << std::endl; return i;}
};

class Three : public _Base1, _Base2, _Base3
{
	private:
	//public:
		virtual void TmpA1(){	std::cout << " Three::TmpA1()" << std::endl;	}
		virtual void TmpA2(){	std::cout << " Three::TmpA2()" << std::endl;	}

		virtual void TmpB1(){	std::cout << " Three::TmpB1()" << std::endl;	}
		virtual void TmpB2(){	std::cout << " Three::TmpB2()" << std::endl;	}
		virtual void TmpB3(){	std::cout << " Three::TmpB3()" << std::endl;	}

		virtual void TmpC1(){	std::cout << " Three::TmpC1()" << std::endl;	}
		virtual void TmpC2(){	std::cout << " Three::TmpC2()" << std::endl;	}
		virtual void TmpC3(){	std::cout << " Three::TmpC3()" << std::endl;	}
		virtual void TmpC4(){	std::cout << " Three::TmpC4()" << std::endl;	}

		virtual int Tmp_Three (int i){ std::cout << " Three::Tmp_Three() " << std::endl; return i;}
};

class Ch : public One, Two, public Three
{
	public:
		void TmpA1(){	std::cout << " Ch::TmpA1()" << std::endl;	}
		
		int Tmp_Three (int i){	std::cout << " Ch::Tmp_Three() " << std::endl; return i;	}
		virtual void Afunc(){	std::cout << " Ch::Afunc() " << std::endl;	};
};

#endif //__MVIRTUAL_HH
