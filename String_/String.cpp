#include "String.h"
#include<iostream>
TString::TString()
{
	length = 0;
	string = nullptr;
}

TString::TString(int _length, char s)
{
	int q = 0;
	if (string == nullptr)
	{
		delete[] string;
		length = 0;
	}
	if (_length > 0)
	{
		string = new char[_length + 1];
		string[_length ] = '\0';
		for ( q = 0; q < _length; q++)
			string[q] = s;
		
	}
	if(string != nullptr) length = (int)strlen(string);
}

TString::TString(const TString& p)
{
	int q = 0;
	if (p.length <= 0) std::cout << "f" << std::endl;
	else if (p.length > 0 && p.string != nullptr)
	{
		length = p.length;
		if (string != nullptr) delete[] string;
		string = new char[length + 1];
		for ( q = 0; q < length; q++)
		{
			string[q] = p.string[q];
		}
	}
	
	string[length] = '\0';
}

int TString::GetLength()
{
	return length;
}

void TString::SetLength(int _length)
{
	length = _length;
}

void TString::SetString(char* _string)
{
	int TemporaryLength = 0;
	if (_string == nullptr) throw "Error in SetString func. Your string = nullptr";

	if (string != nullptr) delete[] string;
	string = new char[strlen(_string) + 1];
	string[strlen(_string)] = '\0';

	for (int q = 0; q < strlen(_string); q++)
	{
		string[q] = _string[q];
	}
	length = (int)strlen(_string);
}

void TString::SetConstString(const char* _string)
{
	int TemporaryLength = 0;
	if (_string == nullptr) throw "Error in SetString func. Your string = nullptr";

	if (string != nullptr) delete[] string;
	string = new char[strlen(_string) + 1];
	string[strlen(_string)] = '\0';

	for (int q = 0; q < strlen(_string); q++)
	{
		string[q] = _string[q];
	}
	length = (int)strlen(_string);
}

TString::~TString()
{
	if (string != nullptr)
		delete[] string;
}

char* TString::GetString()
{
	return string;
}

int TString::FindFirstSymb(char symb)
{
	if (string == nullptr) return -1;
	
	for (int q = 0; q < strlen(string); q++)
	{
		if (string[q] == symb) return q;
	}
	return -1;
}

int TString::FindFirstWord(char* _string)
{
	bool similar;
	if (_string == nullptr) return -1;

	for (int q = 0; q < strlen(string); q++)
	{
		if (_string[0] == string[q])
		{
			similar = true;
			for (int w = 1; w < strlen(_string); w++)
			{
				if (_string[w] != string[q+w]) similar = false;
			}

			if (similar == true) return q;
		}

	}

return -1;   

}
char** TString::Split(char symbol, int &EmptyCount)
{
	int CountOfString = 0;
	int index = 0;
	
	char** Set = nullptr;
	int low = 0;

	for (int q = 0; q < strlen(string); q++)
		if (string[q] == symbol) CountOfString++;

	if (CountOfString == 0)
	{
		char** Set = new char* [1];
		Set[0] = string;
		return Set;
	}

	Set = new char* [CountOfString++];
		
	for (int a = 0; a < strlen(string); a++)
	{
		if (string[a] == symbol)
		{
			Set[index] = new char[a - low+1];
			Set[index][a - low] = '\0';
			for (int i = low; i < a; i++)
			{
				Set[index][i-low] = string[i];
			}
			low = a+1;
			index++;
		}
	}
	if (CountOfString > 0)
	{
		Set[index] = new char[strlen(string) - low + 1];
		Set[index][strlen(string) - low] = '\0';
		for (int i = low; i < strlen(string); i++)
		{
			Set[index][i - low] = string[i];
		}
	}
	EmptyCount = CountOfString;
	return Set;
}

TString& TString::dublicate(int count)
{
	char* TemporaryString = new char[strlen(string) * count + 1];
	TemporaryString[strlen(string) * count] = '\0';
	for (int q = 0; q < strlen(string) * count; q = q+3)
	{
		for (int i = 0; i < strlen(string); i++)
		{
			TemporaryString[q+i] = string[i];
		}
	}
	delete[] string;
	string = TemporaryString;
	return *this;
}



