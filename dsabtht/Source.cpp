#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Infix.h"

int FoundSpace(string str)
{
	for(int i=0; i< str.length(); i++)
		if(str[i] == ' ')
			return i;
	return -1;
}

void DeleteSpace(string &str) 
{
	int spacePos;

	while((spacePos = FoundSpace(str)) != -1)
		str.erase(spacePos,1);
}

void ParseInput(string Input, vector<string> &M) 
{
	int length = Input.length();
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (Input[i] >= '0' && Input[i] <= '9')
		{
			if(i < length - 1)
			{
				for(int j = i + 1; j< length; j++)
					if(
						Input[j] == ')' ||
						Input[j] == '*' || 
						Input[j] == '/' ||
						Input[j] == '+' || 
						Input[j] <= '-' || 
						Input[j] == '%' ||
						Input[j] == '^')
					{
						M.push_back(Input.substr(i, j-i));
						i=j-1;
						break;
					}
			}
			else
			{
				M.push_back(Input.substr(i, length-1));
				break;
			}
		}
		else if (
			Input[i] == '(' ||
			Input[i] == ')' ||
			Input[i] == '*' || 
			Input[i] == '/' ||
			Input[i] == '+' ||
			Input[i] == '-' ||
			Input[i] == '%' || 
			Input[i]=='^'
			)
		{
			string temp(1, Input[i]);
			M.push_back(temp);
		}
	}
}

void main()
{
	string Input;
	cout << "\nEnter:  ";
	getline(cin, Input);

	DeleteSpace(Input);

	Infix* infix = new Infix();
	vector<string> M;
	ParseInput(Input, M);
	cout << "Equal: " << infix->calculateValue(M) << endl;
}