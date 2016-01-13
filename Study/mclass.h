#ifndef __MCLASS__HH
#define __MCLASS__HH

#pragma pack(push)
#pragma pack(8)

typedef union U_A 
{
	int i;
	double j;
	int A[11];
	char a;
}U_A;

class T_A
{
	int i;
	U_A m_UA;
	char c[9];
};

class _BaseA
{
	public:
	virtual int TmpA(int) = 0;	
	//virtual char Tmp2(int){};	
	//virtual short Tmp3(int){};	
	//virtual long long Tmp4(int){};	
	//virtual double Tmp5(int) = 0;	
	virtual ~_BaseA(){};
};

class _BaseB
{
	public:
	virtual int TmpB1() = 0;
	virtual void TmpB2() = 0;

	virtual ~_BaseB(){};
};

class Normal
{
	public:
		Normal();
		~Normal();
		static int m_tmp;
		void tmp (int){};
	private:
		int m_i;
};

class Child_One : public _BaseA
{
	public:
		Child_One ();
		~Child_One();
		int TmpA(int);
	private:
		char m_a;
		int m_i;
		short m_j;
		char m_b;
};

class Child_Two : public _BaseA
{
	public:
		Child_Two();
		Child_Two(const char t_a, const char t_b, const short t_i, const int t_j);
		~Child_Two();
		int TmpA(int t_a);

	private:
		char m_a;
		char m_b;
		short m_i;
		int m_j;
};

class Child_Three : public _BaseA, _BaseB
{
	public:
		Child_Three();
		virtual ~Child_Three();
		explicit Child_Three(char t_a, char t_b, short t_i, int t_j);
		virtual int TmpA(int t_a);
		virtual int TmpB1();
		virtual void TmpB2();
	private:
		char m_a;
		char m_b;
		short m_i;
		int m_j;
};

class A : public Child_Three
{
	public:
		explicit A(char t_a);
		~A(){};
		int TmpA(int t_a);
	private:
		char m_a;
};

#pragma pack(pop)
#endif //__MCLASS__HH
