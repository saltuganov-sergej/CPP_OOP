// Lab00_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int SumDigits(int i)
{
	int sum = 0;
	// цикл продолжается до тех пор, пока число не станет равным 0
	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}


int main(int argc, char* argv[])
{
	int i;
	for (i = 1; i <= 1000; ++i)
	{
		if (i % SumDigits(i) == 0)
		{
			printf("%d", i);
			if (i != 1000)
			{
				printf(", ");
			}
		}
	}
	printf("\n");
    return 0;
}