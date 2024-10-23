#include<iostream>
#include<string>

using namespace std;

class Bloc {
public:
	int nrApartamente;
	char* adresa;
	string denumire;
	float pret;

	//constructor fara parametrii
	Bloc() {
		this->nrApartamente = 0;
		this->adresa = new char[strlen("adresa") + 1];
		strcpy_s(this->adresa, strlen("culoare") + 1, "culoare");
		this->denumire = "";
		this->pret = 0.0f;


	}

	//constructor cu parametri
	Bloc(string denumire) {
		this->denumire = denumire;
		this->nrApartamente = 0;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
		this->pret = 0.0f;
	}

	//constructor totii parametrii


	//afisare

	void afisare() {
		cout << "Nume: " << this->denumire << endl;
		cout << "Nr Apartamente: " << this->nrApartamente << endl;
		cout << "Adresa: " << this->adresa << endl;
		cout << "Pret: " << this->pret << endl;
	}

};

void main() {
	Bloc b1;
	b1.denumire = "Atena";
	b1.adresa = new char[strlen("Bucuresti nr 19") + 1];
	strcpy_s(b1.adresa, strlen("Bucuresti nr 19") + 1, "Bucuresti nr 19");
	b1.nrApartamente = 80;
	b1.pret = 80.000f;

	b1.afisare();

}