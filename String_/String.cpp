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





