#include "Numbers.h"
#include "exceptionHandler.h"

Numbers::Numbers()
{

	
}

void Numbers::printOutMap()
{
	for (int i = 0; i < 101; i++) {
		cout << setprecision(9) << fixed;
		double decNum = sqrt(i);
		string num = to_string(i);
		string str = "sqrt ";
		string toMap = str + num;
		cout << toMap << " = " << decNum << endl;
		squareRootsList.emplace(decNum, toMap);
		cout << squareRootsList.at(decNum) << endl;
	}
}

void Numbers::addNumTranslation(double num)
{
	string userInput;
	cout << "\nyou are translating the number\n" << num
		<< " to your desired string enter symbolic link now\n>";
	getline(cin, userInput);
	squareRootsList.emplace(num, userInput);	
}

double Numbers::checkSquareRoot(double num)
{
	double temp = num * num;
	if (fmod(temp, 1) == 0 && fmod(temp, 2) != 0)
	{
		cout << "results: Odd" << endl;
	}
	else
		cout << "results: Even" << endl;
	/*
	int test = static_cast<int>(temp) % 2;
	if (temp / 2 == 0)
		cout << "\neven root" << endl;
	else
		cout << "\nodd root" << endl;
		*/
	return num * num;
}
void Numbers::checkDecimal(double num)
{
	cout << setprecision(9) << fixed;
	cout << squareRootsList.at(num) << endl;
}
double Numbers::squareLoop(int min, int max)
{
	double totalLoop = 0;
	cout << "the square roots of the numbers from " << min
		<< " to " << max << endl;
	for (int i = min; i < max; i++) {
		cout << "Sqrt of # " << i << " is equal to: " << sqrt(i) << endl;
		totalLoop += sqrt(i);
	}
	cout << "the total of all your square roots added up are: " << totalLoop;
	return totalLoop;
}