#include<iostream>

using namespace std;

class Farmacie {
private:
	const int codUnic;
	static int id;
	char* adresa;
	float* pret;
	int produse;

public:

	Farmacie() :codUnic(++id) {
		this->produse = 0;
		this->adresa = new char[strlen("") + 1];
		strcpy_s(this->adresa, strlen("") + 1, "");
		this->pret = nullptr;
	}

	Farmacie(const char* adresa, float* pret, int produse) :codUnic(++id) {

		this->produse = produse;

		if (adresa == nullptr || strlen(adresa) == 0) {
			throw invalid_argument("Adresa nu poate fi nula sau goala.");
		}
		this->adresa = new char[strlen(adresa) + 1];
		strcpy_s(this->adresa, strlen(adresa) + 1, adresa);

		if (pret == nullptr && produse > 0) {
			throw invalid_argument("Vectorul de preturi nu poate fi nul daca exista medicamente.");
		}
		this->pret = new float[produse];
		for (int i = 0; i < produse; i++) {
			this->pret[i] = pret[i];
		}
	}



		int getProduse() {
			return this->produse;	
	}

		char* getAdresa()  {
			return this->adresa;
		}

		void setAdresa(char* nouaAdresa) {
			if (nouaAdresa == nullptr || strlen(nouaAdresa) == 0) {
				throw invalid_argument("Noua adresa nu poate fi nula sau goala.");
			}
			delete[] this->adresa;
			this->adresa = new char[strlen(nouaAdresa) + 1];
			strcpy_s(this->adresa, strlen(nouaAdresa) + 1, nouaAdresa);
		}

		int getCodUnic() {
			return this->codUnic;
		}

	~Farmacie() {
		if (this->adresa != nullptr) {
			delete[] this->adresa;
		}
		if (this->pret != 0) {
			delete[] this->pret;
		}
	}

	void afisare() {
		cout << "Id: " << this->codUnic << endl;
		cout << "Adresa: " << this->adresa << endl;
		cout << "Produse: " << this->produse << endl;
		if (this->pret != nullptr) {
			cout << "Preturi produse: ";
			for (int i = 0; i < produse; i++) {
				cout << this->pret[i];
				if (i < produse - 1) {
					cout << ", ";
				}
			}

			cout << endl;
		}
		else {
			cout << "Nu exista pret pentru aceste produse" << endl;
		}
		cout << endl;
	}

};

int Farmacie::id = 0;

void main() {
	Farmacie farmacieFaraParametru;
	farmacieFaraParametru.afisare();

	float pret[] = { 239.0f, 27.0f, 13.0f };
	Farmacie farCuParametru("Bucuresti", pret, 3);
	farCuParametru.afisare();

}