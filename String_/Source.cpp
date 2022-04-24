#include<iostream>
#include"String.h"

int main()
{
	
	char* qw = nullptr;
	TString A; int q = 0;
	A.SetConstString("abc_def_ghi");

	char** Set = nullptr;
	Set = A.Split('_', q);

	for (int i = 0; i < q; i++)
	{
		for (int w = 0; w < strlen(Set[i]); w++)
		{
			std::cout << Set[i][w];
		}
		std::cout << std::endl;
	}
	
	return 0;
}

