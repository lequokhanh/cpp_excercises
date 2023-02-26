#include "Infix.h"
#include "Math.h"
using namespace std;

Infix::Infix()
{
}

Infix::~Infix()
{
}

int Infix::UT(string x)
{
	if(x == "sqrt" || x == "^")
		return 3;

	if (x == "*" || x == "/" || x == "%" || x == "^" || x == "sqrt")
		return 2;
	else if (x == "+" || x == "-")
		return 1;
	else if (x == "(")
		return 0;

	return -1;
}

int Infix::HT(string x)
{
	if (x == "*" || x == "/" || x == "%" || x == "+" || x == "-" || x == "^" || x == "sqrt")
		return 2;
	else
		return 1;
}

string Infix::calculateValue(string b, string x, string a)
{
	float fResult = 0;

	if(x == "sqrt")
		 fResult = int(sqrt(atof(a.c_str())));

	if(x == "^")
	{
		fResult = 1;

		for(int i = 1; i <= int(atof(a.c_str())); i++)
			fResult = fResult*atof(b.c_str());
	}

	if(x == "%")
		 fResult = int(atof(b.c_str())) % int(atof(a.c_str()));

	if (x == "*")
		fResult = atof(b.c_str()) * atof(a.c_str());
	else if (x == "/")
		fResult = atof(b.c_str()) / atof(a.c_str());
	else if (x == "+")
		fResult = atof(b.c_str()) + atof(a.c_str());
	else if (x == "-")
		fResult = atof(b.c_str()) - atof(a.c_str());

	string strResult = to_string(fResult);
	return strResult;
}

float Infix::calculateValue(vector<string> M)
{
	float fResult = 0;

	Stack* Sh = new Stack(); 
	Stack* St = new Stack(); 

	int iLength = M.size(); 

	for (int i = 0; i < iLength; i++)
	{
		if (HT(M[i]) == 1 && M[i] != "(" && M[i] != ")") 
			Sh->Push(M[i]); 

		if (M[i] == "(") 
			St->Push(M[i]); 

		if (HT(M[i]) == 2) 
		{
			while (!St->IsEmpty() && (UT(M[i]) <= UT(St->GetHead()->Info))) 
			{
				string a = "";
				Sh->Pop(a);       
				string x = "";
				St->Pop(x);       
				string b = "";
				Sh->Pop(b);      
				Sh->Push(this->calculateValue(b, x, a));   
			}
			St->Push(M[i]); 
		}

		if (M[i] == ")") 
		{
			while (St->GetHead()->Info != "(") 
			{

				string a = "";
				Sh->Pop(a);       
				string x = "";
				St->Pop(x);       
				string b = "";
				Sh->Pop(b);      
				Sh->Push(this->calculateValue(b, x, a));   
			}
			string c = "";
			St->Pop(c);   
		}
	}

	while (!St->IsEmpty())
	{	
		string a = "";
		Sh->Pop(a);      
		string x = "";
		St->Pop(x);      
		string b = "";
		Sh->Pop(b);      
		Sh->Push(this->calculateValue(b, x, a));   
	}

	string strResult = "";
	Sh->Pop(strResult); 
	fResult = atof(strResult.c_str());
	return fResult;
}