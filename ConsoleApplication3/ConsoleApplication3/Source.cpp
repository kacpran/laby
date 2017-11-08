#include <iostream>
#include <cmath>

using namespace std;

double silnia(double liczba);
double silnia(double liczba, int s);
double k_po_s(int k, int s);
double Dyskretyzacja(double a, double b, double tabX[], double tabY[], double wezly);
double wiel_grama(double q, int n, int k);
double WspolczynnikiC(double n, double tabY[], double j);
double WspolczynnikiS(double n, double j);
double wartA(double n, double tabY[], double j);
double Wartosc(double tabY[], double m, double a, double h, double x, double n);
long double blad(double liczba_wezlow, double m, double tabX[], double tabY[], double a, double h, double x,double n);

int main() {
	//funkcja: y = cos^2(x) * cos(2,5x)
	/*
	parametry:
	-przedzia³ (np. <-2;2>
	-liczba RÓWNOODLEG£YCH wêz³ów (np. 50)
	-stopieñ wielomianu aproksymuj¹cego (1-20)
	*/
	double a, b; //przedzia³ <a,b>
	double l_wezlow;        //liczba wêz³ów -> n+1 bo indeksujemy od 0
	double m;                    //stopieñ wielomianu
	double tabX[200];        //tablica wartoœci x punktów o odpowiadajacych indeksach
	double tabY[200];        //tablica wartoœci y punktów o odpowiadaj¹cych indeksach
	double h = 0;                //odleg³oœæ miêdzy s¹siednimi punktami (ich wartoœciami x) 
								 //wprowadzanie danych
	cout << "a: ";
	cin >> a;
	cout << "\nb: ";
	cin >> b;
	cout << "\nliczba wezlow: ";
	cin >> l_wezlow;
	cout << "\nm: ";
	cin >> m;
	cout << "\nkoniec danych" << endl;
	//dyskretyzacja
	h = Dyskretyzacja(a, b, tabX, tabY, l_wezlow);
	cout << "\n\nh = " << h;
	//wielomian gramma
	//wspóczynniki
	//wartoœæ
	double x, n;
	cout << "\nPodaj konkretny punkt X: ";
	cin >> x;
	cout << "\nPodaj parametr n: ";
	cin >> n;
	cout << "\nWartosc funkcji aproksymujacej dla podanych parametrow: ";
	cout << Wartosc(tabY, m, a, h, x, l_wezlow);
	//b³¹d
	cout << "\nWartosc bledu: ";
	cout << blad(l_wezlow, m, tabX, tabY, a, h, x, n);
	
	cout << "\n\n";
	system("PAUSE");
}

double silnia(double liczba) { //ok
	if (liczba == 0 || liczba == 1)
		return 1;
	else if (liczba < 0)
		return 1;
	else {
		double suma = 1;
		for (int i = liczba; i > 1; i--) {
			suma = suma * i;
		}
		return suma;
	}
}

double k_po_s(int k, int s) {//ok
	double wartosc = 0;

	wartosc = silnia(k) / (silnia(s)*silnia(k - s));

	return wartosc;
}

double Dyskretyzacja(double a, double b, double tabX[], double tabY[], double wezly) {//ok
	double pomoc = b - a;
	pomoc = pomoc / wezly;
	//cout << pomoc << endl;
	double h = pomoc;
	for (int i = 0; i<=wezly; i++) {
		tabX[i] = a + i*h;
		//cout << tabX[i] << endl;
	}
	cout << "\n\n\n";
	for (int i = 0; i<=wezly; i++) {
		pomoc = 2.5 * tabX[i];
		tabY[i] = pow(cos(tabX[i]), 2.0)* cos(pomoc);
	}
	return h;
}

double wiel_grama(double q, int n, int k) {//ok
	double wartosc = 0;
	double pomoc;
	for (int s = 0; s <= k; s++) {
		pomoc = pow(-1, s)*k_po_s(k, s)*k_po_s(k + s, s)*(silnia(q, s) / silnia(n, s));
		wartosc = wartosc + pomoc;
	}

	return wartosc;
}



double WspolczynnikiC(double n, double tabY[], double j) {
	double pomoc = 0;
	//C
	for (int q = 0; q <=n; q++) {
		pomoc = pomoc + (wiel_grama(q, n, j)*tabY[q]);
	}
	//cout << pomoc << endl;
	return pomoc;
}

double WspolczynnikiS(double n, double j) {
	double pomoc = 0;
	//S
	//cout << n << "    " << j << endl;
	for (int q = 0; q <=n; q++) {
		pomoc = pomoc + pow(wiel_grama(q, n, j), 2.0);
	}
	//cout << pomoc << endl;
	return pomoc;
}

double wartA(double n, double tabY[], double j) {//ok
	double pomoc;
	pomoc = WspolczynnikiC(n, tabY, j) / WspolczynnikiS(n, j);
	return pomoc;
}


double Wartosc(double tabY[], double m, double a, double h, double x, double n) {
	double pomoc = 0;
	for (int j = 0; j <= m; j++) {
		//cout << "\n" << (x - a) / h;
		pomoc = pomoc+(WspolczynnikiC(n, tabY, j) / WspolczynnikiS(n, j))*wiel_grama((x - a) / h, n, j);
		//cout << WspolczynnikiC(n, tabY, j) << endl;
	}
	return pomoc;
}

long double blad(double liczba_wezlow, double m, double tabX[], double tabY[], double a, double h, double x, double n) {
	long double delta = 0;
	long double pom = 0, pom2;
	for (int i = 0; i <= liczba_wezlow; i++) {        // < or <= ?    
		pom = Wartosc(tabY, m, a, h, x, liczba_wezlow) - tabY[i];
		pom2 = pow(pom, 2.0);
		delta = delta + pom2;
	}
	delta = delta / (liczba_wezlow + 1);
	delta = sqrt(delta);
	return delta;
}

double silnia(double liczba, int s) {//ok
	if (liczba == 0 || liczba == 1)
		return 1;
	else if (liczba < 0)
		return 1;
	else {
		if (s == 0)
			return 1;
		else {
			double suma = 1;
			for (int i = liczba; i >= (liczba - s + 1); i--) {
				suma = suma * i;
			}
			return suma;
		}
	}
}