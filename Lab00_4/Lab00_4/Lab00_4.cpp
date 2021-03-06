// Lab00_4.cpp : Defines the entry point for the console application. 
// 

#include "stdafx.h" 
#include "stdlib.h" 
#include <iostream> 

using namespace std;

double StringToDouble(const char * str, bool & err, bool & act)
{
	char * pLastChar = NULL;
	double param = strtod(str, &pLastChar);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	act = ((*str == '+') || (*str == '-') || (*str == '*') || (*str == '/'));
	return param;
}

int main(int argc, char* argv[])
{
	bool isNotNumber = false;
	bool isDividedByZero = false;
	if (argc <= 1)
	{
		cout << "Program calculates sum of its command line arguments." << endl;
		return 0;
	}
	double result = 0;
	for (int i = 1; i < argc; ++i)
	{
		bool err;
		bool act;
		double param = StringToDouble(argv[i], err, act);
		if (err && !(act))
		{
			isNotNumber = true;
			cout << *argv[i];
			//continue;
		}
		if (act)
		{
			if (*argv[i] == '+')
				cout << " " << argv[i] << " ";
			if (*argv[i] == '-') 
				cout << " " << argv[i] << " ";
			if (*argv[i] == '*')
				cout << " " << argv[i] << " ";
			if (*argv[i] == '/')
				cout << " " << argv[i] << " ";
			continue;
		}
		else
			if (i == 1)
			{
				result = param;
				cout << param;
			}
			else
			{
				if (*argv[i - 1] == '+')
					result += param;
				else 
				{
					if (*argv[i - 1] == '-')
						result -= param;
					else
					{
						if (*argv[i - 1] == '*')
							result *= param;
						else
						{
							if ((*argv[i - 1] == '/') && (*argv[i] == 0))
							{
								isDividedByZero = true;
							}
							else
								result /= param;
						}
					}
				}
				cout << param;
			}
	}
	if (isDividedByZero)
	{
		cout<< endl << "Not possible to divide by 0\n";
	}
	if (isNotNumber)
	{
		cout<< endl << "One of parameters is neither number nor action\n";
	}
	else
	{
		cout.precision(3);
		cout.setf(std::ios::fixed);
		cout << " = " << result << endl;
	}
	return 0;
}