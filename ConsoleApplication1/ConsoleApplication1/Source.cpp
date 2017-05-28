#include <iostream>
#include <string>
using namespace std;
string koduj(string co) {
	string alfabet = "abcdefghijklmnopqrstuwxyz";
	string haslo="";
	for (int i = 0; i <= co.length() - 1; i++) {
		haslo = haslo + co[i] + co[1 + i] + alfabet[i] + alfabet[1 + i];
	}
	return haslo;
}

int main(){
	
	string twoje = "aanbacndaesf";
	twoje = koduj(twoje);
	cout << twoje << endl;

	return 0;
}