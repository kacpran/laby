#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;
//zad a
void FunkcjaA(double A[10][10], double B[10]) {
	ifstream plik;
	plik.open("DaneMacierz.txt");
	if (!plik.good())
		cout << "error" << endl;

	char znak;
	int i = 1;
	int j = 1;
	double liczba=0;
	bool ujemna=false;
	do {
		plik >> znak;
		if (znak == ',') {
			if (ujemna == true) {
				liczba = (-1)*liczba;
			}
			cout << liczba << ",";
			A[i][j] = liczba;
			i++;
			liczba = 0;
			ujemna = false;
		}
		else {
			if (znak == '-') {
				ujemna = true;
				if (znak < '9'&&znak > '0') {
					liczba = liczba * 10;
					liczba = znak - '0' + liczba;
				}
				else {
					j++;
					i = 1;
					cout << endl;
				}
			}
		}
	} while (znak != '*');

	do {
		plik >> znak;
		if (znak == ',') {
			B[i]= liczba;
			i++;
			liczba = 0;
		}
		else {
			if (znak>'9'&&znak<'0') {
				liczba = liczba * 10;
				liczba = znak - '0' + liczba;
			}
		}
	} while (znak != '*');
	plik.close();
	return;
}



//zad b
bool FunkcjaB(double A[10][10], double B[10], double alfa[10][10], double beta[10], int n) {
	double a_ii;

	for (int i = 1; i < n + 1; i++) {
		a_ii = A[i][i];

		//Sprawdzenie czy jest dzielenie przez 0
		if (a_ii == 0) {
			return false;
		}
		for (int j = 1; j < n + 1; j++) {
			if (i != j) {
				alfa[i][j] = -(A[i][j] / a_ii);
			}
			else {
				alfa[i][j] = 0;
			}
		}
		beta[i] = (B[i] / a_ii);
	}
	return true;
}

//zad c
double StopOblIt(double Xnowy[10], double Xstary[10], int n) {
	double norma3;
	double suma = 0;

	for (int i = 1; i < n + 1; i++) {
		suma = suma + pow((Xnowy[i] - Xstary[i]), 2);
	}

	norma3 = sqrt(suma / n);


	return norma3;
}

int FunkcjaC(double alfa[10][10], double beta[10], double epsylon, int n, int MLI, double Xnowy[10], double Xstary[10]) {
	int k_licznik = 0;//licznik iteracji
	double reszta = 0;
	for (int pomoc = 1; pomoc<n + 1; pomoc++) {
		Xnowy[pomoc] = beta[pomoc];
	}

	do {
		for (int pomoc = 1; pomoc<n + 1; pomoc++) {
			Xstary[pomoc] = Xnowy[pomoc];
		}
		k_licznik++;

		//wzor

		for (int i = 1; i < n + 1; i++) {
			reszta = 0;
			//if (i >= 2){
			for (int j = 1; j <= i - 1; j++) {
				reszta = reszta + (alfa[i][j] * Xnowy[j]);
			}

			//}
			for (int j = i + 1; j < n + 1; j++) {
				reszta = reszta + (alfa[i][j] * Xstary[j]);
			}
			Xnowy[i] = beta[i] + reszta;



		}
	} while (StopOblIt(Xnowy, Xstary, n)>epsylon && k_licznik<MLI);

	return k_licznik;
}



//zad d
void FunkcjaD(double alfa[10][10], double beta[10], double epsylon, int n, int MLI, double Xnowy[10], double Xstary[10], int liczba_iteracji, double A[10][10], double B[10]) {
	ofstream plik;
	plik.open("RaportMacierz.txt");
	plik <<"Epsylon" << endl;
	plik << epsylon << endl;
	plik << "MLI" << endl;
	plik << MLI << endl;

	plik << "Macierz A" << endl;
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			plik << A[i][j]<<",";
		}
		plik << endl;
	}
	plik << "Wektor B" << endl;
	for (int i = 1; i < 6; i++) {
		plik << B[i]<<",";
	}
	plik << endl;

	plik << "Iteracje" << endl;
	plik << liczba_iteracji << endl;
	plik << endl;

	plik << "Ostatnia iteracja" << endl;
	for (int pomoc = 1; pomoc<n + 1; pomoc++) {
		plik << Xnowy[pomoc] << ", ";
	}
	plik << endl;
	plik << "Przedostatnia iteracja" << endl;
	for (int pomoc = 1; pomoc<n + 1; pomoc++) {
		plik << Xstary[pomoc] << ", ";
	}
	plik << endl;
	
	plik << "Macierz alfa" << endl;
	for (int i = 1; i < 6; i++) {
		for (int j = 1; j < 6; j++) {
			plik << alfa[i][j] << ",";
		}
		plik << endl;
	}
	plik << "Wektor beta" << endl;
	for (int i = 1; i < 6; i++) {
		plik << beta[i] << ",";
	}
	plik << endl;

	return;
}



int main() {
	double A[10][10];
	double B[10];
	int MLI;
	double epsylon;
	double alfa[10][10];
	double beta[10];
	double Xnowy[10]; //ostatni
	double Xstary[10];//przedostatni
	int n;
	//czesc a
	FunkcjaA(A, B);
	//wczytujemy MLI, n, epsylon
	cout << "Podaj rzad macierzy: " << endl;
	cin >> n;
	cout << "Podaj maksymalna liczbe iteracji (MLI): " << endl;
	cin >> MLI;
	cout << "Podaj dokladnosc epsylon: " << endl;
	cin >> epsylon;
	//czesc b
	if (FunkcjaB(A, B, alfa, beta, n) == false) {
		cout << "Dzielenie przez 0" << endl;
	}
	//czesc c
	int liczba_iteracji = FunkcjaC(alfa, beta, epsylon, n, MLI, Xnowy, Xstary);
	//czesc d
	FunkcjaD(alfa,beta,epsylon,n,MLI,Xnowy,Xstary,liczba_iteracji,A,B);
	return 0;
}