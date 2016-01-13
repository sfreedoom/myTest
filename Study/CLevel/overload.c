#include <stdio.h>

int add(int lhs, int rhs)
{
	return lhs + rhs; 
}

double add(double lhs, double rhs)
{
	return lhs + rhs;
}


/////////////////////   C overload   //////////////////////
//typedef struct IntParam
//{
//	int lhs;
//	int rhs;
//}IntParam;
//
//typedef struct DoubleParam
//{
//	double lhs;
//	double rhs;
//}DoubleParam;
//
//void* intAdd(void* param)
//{
//	IntParam* tmp = (IntParam*)param;
//	int R = (tmp->lhs + tmp->rhs);
//	return (void*)&R;
//}
//
//void* doubleAdd(void* param)
//{
//	DoubleParam* tmp = (DoubleParam*)param;
//	double R = (tmp->lhs + tmp->rhs);
//	return (void*)&R;
//}
//
//typedef void*(*pFunc)(void*);
//
//void* AddFunc(pFunc f, void* param)
//{
//	return f(param);
//}

int main()
{
	int i = 10, j = 20;
	printf("Add() %d \n", add(i, j));

	double di =10.44, dj =20.44;
	printf("Add() %F \n", add(di, dj));

	//C overload //
	//IntParam intParam = {10, 20};
	//DoubleParam doubleParam = {10.44, 20.44};

	//printf("AddFunc : %d \n", *((int*)(AddFunc(intAdd, &intParam))));
	//printf("AddFunc : %f \n", *((double*)(AddFunc(doubleAdd, &doubleParam))));
	return 0;
}
