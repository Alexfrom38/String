
#include <iostream>

#include "SetOfStrings.h"


SetOfArray::SetOfArray()
{
	CountOfString = 0;
	Set = nullptr;
}

SetOfArray::~SetOfArray()
{
	if (Set != nullptr)
		delete[] Set;
}

void SetOfArray::AddString(char* string)
{

	if (CountOfString == 0)
	{
		Set = new char * [1];
		CountOfString = 1;
		Set[0] = string;
	}
	else
	{
		char** temporary = new char* [CountOfString + 1];

		for (int q = 0; q < CountOfString; q++)
		{
			temporary[q] = Set[q];
		}
		//Print(temporary, CountOfString+1);

		delete[] Set;
		Set = temporary;
		Set[CountOfString] = string;
		CountOfString++;
	}
}
void SetOfArray::Print()
{
	char* str;
	for (int i = 0; i < CountOfString; i++)
	{
		str = Set[i];
		for (int j = 0; j < strlen(str); j++)
		{
			std::cout << str[j];
		}
		std::cout << std::endl;
	}
}

void SetOfArray::Print(char** Set, int CountOfString)
{
	char* str;
	for (int i = 0; i < CountOfString; i++)
	{
		str = Set[i];
		for (int j = 0; j < strlen(str); j++)
		{
			std::cout << str[j];
		}
		std::cout << std::endl;
	}
}

char* SetOfArray::GetString()
{
	char* string = nullptr;


	if (CountOfString == 0) throw "CountOfString equals 0";
	else if (CountOfString > 0)
	{
		string = Set[CountOfString - 1];
		
		char** temporary = new char* [CountOfString - 1];
		for (int q = 0; q < CountOfString-1; q++)
		{
			temporary[q] = Set[q];
		}
		delete Set;
		Set = temporary;
	
		CountOfString--;
	}

	return string;
	delete string;
}
