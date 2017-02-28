#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;


class geshenk {
public:
	virtual void rozpakuj() {
		cout << "ta daaa" << endl;
	}

	virtual void typ() {
		cout << typeid(*this).name() << endl;

	}
};

class schlapmyca : public geshenk {
public:
	void zaloz() {
		cout << "jest ciepla" << endl;
	}
};

class pieniadze : public geshenk {
public:
	void wydaj() {
		cout << "teraz juz nic nie masz" << endl;
	}
};

class czekolada : public geshenk {
public:
	void zjedz() {
		cout << "zjadles" << endl;
	}
};

int main() {

	geshenk * geshenki;
	vector<geshenk*> lista = {
		new schlapmyca,
		new pieniadze,
		new czekolada,
		new pieniadze
	};

	for (auto geshenk : lista) {

		if (czekolada* nowe = dynamic_cast<czekolada*>(geshenk)) {
			nowe->zjedz();
			nowe->typ();
			cout << endl;
		}

		if (pieniadze* nowe = dynamic_cast<pieniadze*>(geshenk)) {
			nowe->wydaj();
			nowe->typ();
			cout << endl;
		}

		if (schlapmyca* nowe = dynamic_cast<schlapmyca*>(geshenk)) {
			nowe->zaloz();
			nowe->typ();
			cout << endl;
		}
	}

	return 0;
}