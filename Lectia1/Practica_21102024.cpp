#include<iostream>
#include<string>
#include<iomanip> 


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
		this->adresa = new char[strlen("Bucuresti") + 1];
		strcpy_s(this->adresa, strlen("Bucuresti") + 1, "Bucuresti");
		this->denumire = "";
		this->pret = 0.0f;


	}

	//constructor cu parametri
	Bloc(string denumire) {
		this->denumire = denumire;
		this->nrApartamente = 0;
		this->adresa = new char[strlen("Bucuresti") + 1];
		strcpy_s(this->adresa, strlen("Bucuresti") + 1, "Bucuresti");
		this->pret = 0.0f;
	}

	//constructor totii parametrii

	Bloc(string denumire, int nrApartamente, float pret, const char* adresa) {
		this->denumire = denumire;
		this->nrApartamente = nrApartamente;
		this->pret = pret;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);

	}

	//afisare

	void afisare() {
		cout << "Nume: " << this->denumire << endl;
		cout << "Nr Apartamente: " << this->nrApartamente << endl;
		cout << "Adresa: " << this->adresa << endl;
		cout << "Pret: " << this->pret << endl;
		cout << endl;
	}

};


void main() {
	//apelare constructor implicit
Bloc b1;
b1.afisare();

//apelare constructor 1 parametri
Bloc b2("Atena");
b2.afisare();

//Apelare constructor cu toti parametrii
Bloc b3("Atena", 50, 50.000f, "Iasi, nr 58");
b3.afisare();

}
