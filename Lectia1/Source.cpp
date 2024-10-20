#include<iostream>
#include<string>

using namespace std;

class Masina {
public:
	string marca;
	int anFabricatie;
	float pret;
	char* culoare;

	//constructor fara parametri

	Masina() {
		this->marca = "";
		this->anFabricatie = 0;
		this->pret = 0.0f;
		this->culoare = new char[strlen("culoare") + 1];
		strcpy_s(this->culoare, strlen("culoare") + 1, "culoare");

	}

	//metoda afiare
	void afisare() {
		cout << "Marca:" << this->marca << endl;
		cout << "Anul Fabricatiei: " << this->anFabricatie << endl;
		cout << "Pret: " << this->pret << endl;
		cout << "Culoare: " << this->culoare << endl;

	}

};

void main() {
	Masina masina1;
	masina1.marca = "Honda";
	masina1.anFabricatie = 2016;
	masina1.pret = 20.5;
	masina1.culoare = new char[strlen("Neagra") + 1];
	strcpy_s(masina1.culoare, strlen("Neagra") + 1, "Neagra");

	masina1.afisare();

}