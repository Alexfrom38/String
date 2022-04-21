#pragma once
class SetOfArray
{
public:
	SetOfArray();
	~SetOfArray();

	void AddString(char* string);
	void Print();
	
	char* GetString();
private:
	int CountOfString;
	char** Set;
	void Print(char** Set ,int CountOfString);

};