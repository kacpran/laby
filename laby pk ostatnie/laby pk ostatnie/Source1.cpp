#include <regex>
#include <iostream>
#include <vector>

using namespace std;



int main()
{
	cout << "Zadanie 1" << endl << endl;
	string imie = "Piotr";
	smatch wynik;
	regex rimie("^([A-Z][a-z]+)$");

	if (regex_search(imie, wynik, rimie))
	{
		cout << "Imie \t\tPoprawny" << endl;
	}
	else
		cout << "Imie nie zgadza sie z wzorcem" << endl;
	//--------------------------------------------------------
	string nazwisko1 = "Kowalski";
	string nazwisko2 = "Kowalska-Nowak";
	regex rnazwisko("^(([A-Z][a-z]+-[A-Z][a-z]+)|([A-Z][a-z]+))$");


	if (regex_search(nazwisko1, wynik, rnazwisko))
	{
		cout << "Nazwisko1 \tPoprawny" << endl;
	}
	else
		cout << "Nazwisko1 nie zgadza sie z wzorcem" << endl;

	if (regex_search(nazwisko2, wynik, rnazwisko))
	{
		cout << "Nazwisko2 \tPoprawny" << endl;
	}
	else
		cout << "Nazwisko2 nie zgadza sie z wzorcem" << endl;
	//------------------------------------------------------------
	string kodPocztowy = "44-777";
	regex rkodPocztowy("\\d{2}-\\d{3}$");
	if (regex_search(kodPocztowy, wynik, rkodPocztowy))
	{
		cout << "Kod pocz. \tPoprawny" << endl;
	}
	else
		cout << "Kod pocztowy nie zgadza sie z wzorcem" << endl;
	//----------------------------------------------------------
	string nrTelefonu = "123-456-789";
	regex rnrTelefonu("^(\\d{3}-\\d{3}-\\d{3})$");
	if (regex_search(nrTelefonu, wynik, rnrTelefonu))
	{
		cout << "Nr tel. \tPoprawny" << endl;
	}
	else
		cout << "Nr telefonu nie zgadza sie z wzorcem" << endl;
	//---------------------------------------------------------
	string adresemail = "jan.kowal_ski1@gmail.com";
	regex radresemail("^(([a-zA-Z0-9\._-])+@([a-zA-Z0-9\.])+\.([a-z])+)$");
	if (regex_search(adresemail, wynik, radresemail))
	{
		cout << "email \t\tPoprawny" << endl;
	}
	else
		cout << "Adres email nie zgadza sie z wzorcem" << endl;
	//------------------------------------------------------------------
	string pesel = "00102112345";
	regex rpesel("^([\\d]{2}([0][0-9]|[1][0-2])([0-2][\\d]|[3][0-1])[\\d]{5})$");
	if (regex_search(pesel, wynik, rpesel))
	{
		cout << "PESEL \t\tPoprawny" << endl;
	}
	else
		cout << "PESEL nie zgadza sie z wzorcem" << endl;
	//---------------------------------------------------------------------
	string ulica1 = "ul. Majowa 45";
	string ulica2 = "ul. Akademicka 9/15";
	regex rulica("ul\\. (([A-Z][a-z]+) [\\d]+\\/[\\d]+)$|ul\\. (([A-Z][a-z]+) [\\d]+)$");
	if (regex_search(ulica1, wynik, rulica))
	{
		cout << "Ulica1 \t\tPoprawny" << endl;
	}
	else
		cout << "Ulica1 nie zgadza sie z wzorcem" << endl;
	if (regex_search(ulica2, wynik, rulica))
	{
		cout << "Ulica2 \t\tPoprawny" << endl;
	}
	else
		cout << "Ulica2 nie zgadza sie z wzorcem" << endl;


	//zadanie 2
	cout << endl << endl;
	cout << "Zadanie 2" << endl << endl;
	string tekst2 = "cesarz czesal cesarzowa";
	cout << tekst2 << endl;
	regex c("cesarz");
	string twojeImie = "Michal";
	string poZamianie = regex_replace(tekst2, c, twojeImie);
	cout << "Po zamianie:\t" << poZamianie << endl;


	//zadanie 3
	int i = 1;
	cout << endl << endl;
	cout << "Zadanie 2" << endl << endl;
	string tekst3 = "ciesze sie, ze sie cieszysz";
	regex rtekst3("ciesz\\w*");

	if (regex_search(tekst3, wynik, rtekst3))
		cout << "Pierwsze wystapienie to '" << wynik[0] << "' od " << wynik[0].first - tekst3.begin() << " do " << wynik[0].second - tekst3.begin() << endl;
	else
		cout << "Nic nie znaleziono" << endl;

	cout << "Wszystkie wystapienia:" << endl;
	while (regex_search(tekst3, wynik, rtekst3))
	{
		cout << "Wystapienie nr " << i << ": " << wynik[0] << endl;
		tekst3 = wynik.suffix().str();
		i++;
	}


	return 0;
}