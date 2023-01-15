#include<iostream>
#include<stdarg.h>
#include"colors.h"

using namespace std;
using namespace colors;

void AnyType(int count, bool changeType, ...) {
	int sumi{0};

	double sumd{0.0};

	va_list ptr;
	
	va_start(ptr, count);
	while (count--) 
	{
		if (changeType)
		{
			sumi += va_arg(ptr, int);
		}
		else
		{
			sumd += va_arg(ptr, double);
		}
	}

	if (changeType)
	{
		cout << RED << "Integer sum = " << sumi << RESET << endl;
	}
	else
	{
		cout << GREEN << "Double sum = " << sumd << RESET << endl;
	}
	va_end(ptr);
}
template<typename T>
void UnlimParamsFunc(int paramsCount, ...)   // Works good)))
{
	va_list ptr;
	va_start(ptr, paramsCount);

	while(paramsCount--)
	{
		cout << PURPLE << va_arg(ptr, T) << RESET << " ";
	}
	cout << endl;
	va_end(ptr);
}
template<typename T>
void StopOnZero(T args, ...)  //when used with CHAR type prints only first character( Don't know why!
{
	T* ptr = &args;
	while (*ptr)
	{
		cout << YELLOW_BOLD_BRIGHT << *ptr << " " << RESET;
		++ptr;
	}
	cout << endl;
}
int main()
{
	UnlimParamsFunc<int>(5, 1, 2, 3, 4, 5);
	AnyType(4, true, 3, 8, 9, 4);
	UnlimParamsFunc<char>(6, 'I', 'T', 's','t','e', 'p');
	AnyType(3, false, 2.5, 1.1, 3.6);
	UnlimParamsFunc<double>(3, 1.1, 2.2, 3.3);
	StopOnZero<int>(123, 456, 789, 0, 123);
	StopOnZero<double>(1.1, 2.2, 3.3, 0.0);
	return 0;
}