#include<iostream>
#include"String.h"
#include"SetOfStrings.h"

int main()
{
	SetOfArray set;
	char* qw = nullptr;
	TString A;
	TString B;

	B.SetConstString("cde");
	qw = B.GetString();
	set.AddString(qw);
	

	B.SetConstString("cde");
	qw = B.GetString();
	set.AddString(qw);
	//set.Print();
	//qw = nullptr;

	//qw = set.GetString();
	//qw = set.GetString();







	A.SetConstString("abc_cde_qra");
	//std::cout << A.FindFirstWord(qw) << std::endl;


	
	
	return 0;
}
