#include <iostream>
#include <vector>
#include <regex>

using namespace std;



int main()
{
	//Zad 1
	cout << "imie"<<endl;
	regex imie{ "^([A-Z][a-z]+)$" };
	smatch rezultat;
	string imie_podane,nazwisko_podane;
	cin >> imie_podane;
	if (regex_search(imie_podane, rezultat, imie))
	{
		cout << "imie \t\tok" << endl;
	}
	else
		cout << "imie nie zgadza sie" << endl;

	cout << "nazwisko" << endl;
	regex nazwisko{ "^(([A-Z][a-z]+)|([A-Z][a-z]+-[A-Z][a-z]+))$" };
	cin >> nazwisko_podane;
	if (regex_search(nazwisko_podane, rezultat, nazwisko))
	{
		cout << "nazwisko \t\tok" << endl;
	}
	else
		cout << "nazwisko nie zgadza sie" << endl;

	cout << "kod pocztowy" << endl;
	regex kodpocz{"[0-9][0-9]-[0-9][0-9][0-9]"};
	string kodpocztowy;
	cin >> kodpocztowy;
	if (regex_search(kodpocztowy, rezultat, kodpocz))
	{
		cout << "kod \t\tok" << endl;
	}
	else
		cout << "kod nie zgadza sie" << endl;

	cout << "numer telefonu" << endl;
	regex numertel{ "[0-9][0-9][0-9]-[0-9][0-9][0-9]-[0-9][0-9][0-9]" };
	string telefon;
	cin >> telefon;
	if (regex_search(telefon, rezultat, numertel))
	{
		cout << "numer \t\tok" << endl;
	}
	else
		cout << "numer nie zgadza sie" << endl;

	cout << "email" << endl;
	regex email{ "^(([0-9|a-z|A-Z|]+@gmail.com)|([0-9|a-z|A-Z|]+@onet.pl))$" };
	string mail;
	cin >> mail;
	if (regex_search(mail, rezultat, email))
	{
		cout << "mail \t\tok" << endl;
	}
	else
		cout << "mail nie zgadza sie" << endl;

	cout << "pesel" << endl;
	regex pesel{ "^([\\d]{2}([0][0-9]|[1][0-2])([0-2][\\d]|[3][0-1])[\\d]{5})$" };
	string pes;
	cin >> pes;
	if (regex_search(pes, rezultat, pesel))
	{
		cout << "pesel \t\tok" << endl;
	}
	else
		cout << "pesel nie zgadza sie" << endl;

	cout << "ulica" << endl;
	regex ulica{ "ul\\. ([A-Z][a-z]+) [\\d]+\\/[\\d]+$" };
	string adres;
	adres="ul. Plebansa 12/2";
	if (regex_search(adres, rezultat, ulica))
	{
		cout << "ulica \t\tok" << endl;
	}
	else
		cout << "ulica nie zgadza sie" << endl;
	cout << endl << endl;

	//Zad 2
	string tekst = "cesarz czesal czesarzowa";
	cout << tekst << endl;
	regex cesar("cesarz");
	string tekst2 = regex_replace(tekst, cesar, imie_podane);
	cout << tekst2 << endl;

	//zad 3
	int i = 1;
	cout << endl << endl;
	
	string tekst3 = "ciesze sie, ze sie cieszysz";
	cout << tekst3 << endl;
	regex podane("ciesz\\w*");
	if (regex_search(tekst3, rezultat, podane))
		cout << "Pierwsze wystapienie to '" << rezultat[0] << "' od " << rezultat[0].first - tekst3.begin() << " do " << rezultat[0].second - tekst3.begin() << endl;
	else
		cout << "Nic nie znaleziono" << endl;
	cout << endl << endl;
	//zad 4
	cout << "Wszystkie wystapienia:" << endl;
	while (regex_search(tekst3, rezultat, podane))
	{
		cout << "Wystapienie nr " << i << ": " << rezultat[0] << endl;
		tekst3 = rezultat.suffix().str();
		i++;
	}
	return 0;
}