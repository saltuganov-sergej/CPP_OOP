// Lab00_3.cpp : Defines the entry point for the console application. 
// 

#include "stdafx.h" 
#include <limits.h> 
#include <iostream> 

using namespace std;

int Fibonacci(int b)
{
	bool isOverflow = false;
	int F1 = 0;
	int F2 = 1;
	cout << F1 << ", ";
	int j = 1;
	while (F1 + F2 <= b)
		{
			if (INT_MAX - F1 > F2) //Проверка на переполнение int
			{
				if (j != 4) //условие для вывода по пять чисел в строке
				{
					j += 1;
					cout << F2 << ", ";
				}
				else //перевод на новую строку
				{
					cout << F2 << ", " << endl;
					j = 0;
				}
				F2 = F2 + F1;
				F1 = F2 - F1;
			}
			else 
			{
				break;
			}
		}
	return F2;
}

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		cout << "Program shows Fibonacci numbers in range from 0 to N" << endl << "N is command line argument" << endl;
		return 0;
	}
	bool err;
	int N = StringToInt(argv[1], err);
	if (N < 0)
		cout << "Argument must be a positive number" << endl;
	else if (N == 0)
			cout << N << endl;
		else
			cout << Fibonacci(N) << endl;
		return 0;
}