#include <iostream>
#include <string>
#include <math.h>
#include <list>
#include "Polynomial.h"
using namespace std;
void main()
{
	polynomial Coeff;
	//input from smallest to highest
	//use push back
	int order = 0;
	cout << "enter the order of polynomial" << endl;
	cin >> order;
	Coeff.SetOrder(order);
	string PolyCoeff;
	cout << "enter the coeff. from the smallest the coeff to the highest coeff separated by space" << endl;
	cin.ignore();
	getline(cin, PolyCoeff);
	int counter = 0;
	//while(PolyCoeff.find(' ') == -1)
	for (int counter = 0; counter <= order; counter + PolyCoeff.find(' '))
	{
		if (PolyCoeff.find(' ') == -1)
		{
			break;
		}
		PolyCoeff.substr(counter, PolyCoeff.find(' ') + 1);
		Coeff.SetCoeff(stoi(PolyCoeff.substr(counter, PolyCoeff.find(' ') + 1)));
		PolyCoeff.erase(0, PolyCoeff.find(' ')+1);
	}
	Coeff.SetCoeff(stoi(PolyCoeff.substr(0, PolyCoeff.length())));
	//Coeff.DiffrentiatePolynomial();
	list<double> SecondPoylnomial;
	SecondPoylnomial.push_back(1);
	SecondPoylnomial.push_back(2);
	Coeff.MultiplyPolynomial(SecondPoylnomial,1);
	//Coeff.EvaluatePolynomial(2);
	//Coeff.PrintPolynomial();

}