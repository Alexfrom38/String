#include"String.h"
#include <iostream>

char& TString::operator[](int i)
{
	char q = 3;
	if (length > 0 && string != nullptr && (i >= 0 && i <length))
	{
		return string[i];
	}
	else
		return q;
}

bool TString::operator==(const TString& p)
{
	int tmplen = strlen(string);
	int _tmplen = strlen(p.string);
	
	if (tmplen != _tmplen) return false;
	else
	{
		for (int q = 0; q < tmplen; q++)
		{
			if (string[q] != p.string[q]) return false;
		}
	}
	return true;
}
TString& TString::operator = (const TString& p)
{
	if (p.string != nullptr)
	{
		length = strlen(p.string);

		if (string == nullptr) delete[] string;
		string = new char[length + 1];
		string[length] = '\0';

		for (int q = 0; q < length; q++)
		{
			string[q] = p.string[q];
		}
	}
	return *this;
}

bool TString::operator < (const TString& p)
{
	int tmplen1 = 0;
	int tmplen2 = 0;

	if (p.string == nullptr && string == nullptr) throw "Exception in operator <";
	else
	{
			tmplen1 = strlen(string);
			tmplen2 = strlen(p.string);
			
			if (tmplen2 < tmplen1) tmplen2 = tmplen1;
			
			for (int q = 0; q < tmplen1; q++)
			{
				if (string[q] >= p.string[q]) return false;
			}
		
	}
	return true;
}

bool TString::operator > (const TString& p)
{
	int tmplen1 = 0;
	int tmplen2 = 0;

	if (p.string == nullptr && string == nullptr) throw "Exception in operator <";
	else
	{
		tmplen1 = strlen(string);
		tmplen2 = strlen(p.string);

		if (tmplen2 < tmplen1) tmplen2 = tmplen1;

		for (int q = 0; q < tmplen1; q++)
		{
			if (string[q] <= p.string[q]) return false;
		}

	}
	return true;
}

TString TString::operator + (const TString& p)
{
	int tmplength = 0; int p_tmplength = 0;
	TString result(*this);
	if (string == nullptr) throw "string of first object = nullptr";
	if (p.string == nullptr) throw "string of second object = nullptr";

	if (result.string == nullptr) delete[] result.string;
	result.string = new char[strlen(string) + strlen(p.string) + 1];
	result.string[strlen(string) + strlen(p.string)] = '\0';
	tmplength = strlen(string);
	p_tmplength = strlen(p.string);
	
	for (int i = 0; i < tmplength; i++)
	{
		result.string[i] = string[i];
	}
	for (int i = 0; i < p_tmplength; i++)
	{
		result.string[tmplength + i] = p.string[i];
	}
	result.length = strlen(result.string);
	return result;
	

}

std::istream& operator>>(std::istream& stream,  TString& p)
{
	int i = 0; 
	char tmp = 0;
	if (p.string != nullptr) delete[] p.string;
	char* tmpstring = nullptr;
	tmpstring = new char[255];

	for (int a = 0; a < 255; a++)
	{
		tmpstring[a] = '\0';
	}

	while (tmp != '0')
	{
		stream >> tmp;
		tmpstring[i] = tmp;
		i++;
	}

	p.string = new char[strlen(tmpstring)];
	p.string[strlen(tmpstring) - 1] = '\0';

	for (int q = 0; q < strlen(tmpstring) - 1; q++)
		p.string[q] = tmpstring[q];
	p.length = strlen(p.string);
	delete[] tmpstring;
	tmpstring = nullptr;
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const TString& p)
{
	for (int q = 0; q < strlen(p.string); q++)
	{
		stream << p.string[q];
	}
	stream << '\n';
	return stream;
}
