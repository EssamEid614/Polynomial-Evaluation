#include <iostream>
#include <string>
#include <math.h>
#include <list>
using namespace std;

class polynomial
{
private:
	list<double> PolyCoeff;
	int order;
public:
	void SetOrder(int x)
	{
		order = x;
	}
	int GetOrder()
	{
		return order;
	}
	void SetCoeff(double x)
	{
		PolyCoeff.push_back(x);
	}
	double GetCoeffWithOrder(int order)

	{
		int counter = 0;
		for (list<double>::iterator i=PolyCoeff.begin(); i != PolyCoeff.end(); ++i)
		{
			if (counter == order)
			{
				return *i;
			}
			counter++;
		}
		// handle not found case
	}
	void PrintPolynomial()
	{
		int CurrentPower = order;
		string ToPrint;
		for (list<double>::reverse_iterator i=PolyCoeff.rbegin(); i != PolyCoeff.rend(); i++)
		{
			
			if (CurrentPower == 0)
			{
				//cout i only
				if (*i < 0)
				{
					ToPrint = ToPrint + to_string(*i);
				}
				else
				{
					//cout << " + " << *i << endl;
					ToPrint = ToPrint +" + "+ to_string(*i);
				}
			}
			else
			{
				//cout the value of power
				if (*i < 0)
				{
					//cout << *i << "*x^" << CurrentPower;
					ToPrint = ToPrint + to_string(*i) + "*x^" + to_string(CurrentPower);
				}
				else
				{
					//cout << " + " << *i << "*x^" << CurrentPower;
					ToPrint = ToPrint + " + " + to_string(*i) + "*x^" + to_string(CurrentPower);
				}
				CurrentPower--;
			}
		}

		
		ToPrint.erase(0, 3);
		cout <<"the Polynomial is:"<< ToPrint<<endl;

	}

	void EvaluatePolynomial(int ValueOfX)
	{
		int CurrentPower = order;
		double value = 0;
		for (list<double>::reverse_iterator i = PolyCoeff.rbegin(); i != PolyCoeff.rend(); i++)
		{
			value = value + *i *pow(ValueOfX,CurrentPower);
			CurrentPower--;
		}
		cout << "The Value of Polynomial is"<<value;
	}

	void DiffrentiatePolynomial()
	{
		int CurrentPower = order;
		string DiffrentiatedString;
		double value;
		for (list<double>::reverse_iterator i = PolyCoeff.rbegin(); i != PolyCoeff.rend(); i++)
		{
			 if (CurrentPower - 1 == 0)
			{
				value = *i *CurrentPower;
				DiffrentiatedString = DiffrentiatedString + to_string(value);
				break;
			}

			else if (CurrentPower > 0)
			{
				value = *i *CurrentPower;
				DiffrentiatedString = DiffrentiatedString + to_string(value) + "*x^" + to_string(CurrentPower - 1) + " + ";
				CurrentPower--;
			}
			
		}
		cout << "Diffrentiated String is:" << DiffrentiatedString << endl;
	}
	void MultiplyPolynomial(list<double> SecondPolynomial,int SecondPolynomialOrder)
	{
		list<double> Result;
		double ValueToPush=0;
		int StartPushFrom = 0;
		list<double>::iterator ResultListIterator;
		//intialize list to zeroes
		for (int counter = 0; counter <= SecondPolynomialOrder + order; counter++)
		{
			Result.push_back(0);
		}
		//

		for (list<double>::iterator FirstListIterator = PolyCoeff.begin(); FirstListIterator != PolyCoeff.end(); ++FirstListIterator)
		{
			ResultListIterator = Result.begin();
			advance(ResultListIterator, StartPushFrom);
			for (list<double>::iterator SecondListIterator = SecondPolynomial.begin(); SecondListIterator != SecondPolynomial.end(); ++SecondListIterator)
			{
				ValueToPush =*FirstListIterator * *SecondListIterator ;
				*ResultListIterator = *ResultListIterator+ValueToPush;
				ResultListIterator++;
			}
			StartPushFrom++;
		}
	}
};