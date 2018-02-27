// Lab01_1_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;


int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Use parameters: <input file> <output file>" << endl;
		return 1;
	}

	ifstream input(argv[1]);
	ofstream output(argv[2]);
	
	if (!input)
	{
		cout << "File " << argv[1] << " is not open" << endl;
		return 1;
	}
	
	char Ch;


	

	input.close();
	output.close();

    return 0;
}

