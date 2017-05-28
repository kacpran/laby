#include <iostream>
#include <string>
using namespace std;

double Dziel(double a, double b) {
	if (b == 0) {
		string wyjatek = "Dzielenie przez zero";
		throw wyjatek;
	}
	return a / b;
}

int main() {
	double a, b;
	cin >> a;
	cin >> b;

	try
	{
		Dziel(a, b);
	}
	catch (string w)
	{
		cout << w << endl;
	}
	

	return 0;
}