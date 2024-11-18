#include<iostream>

using namespace std;

class Nava {
private:
	const int idNava;
	const int nrBucati;
	string marca;
	float*  pret;
	static int id;
	char* culoare;

public:

	//constructor implictit cu constant si static
	Nava() :idNava(++id), nrBucati(0){
		this->marca = "";
		this->culoare = new char[strlen("") + 1];
		strcpy_s(this->culoare, strlen("") + 1, "");
		this->pret = nullptr;
	}

	//constructor cu un parametru, un constant si un static
	//in acest caz valoarea pretului trebuie hardcodata aici, in definirea 
	Nava(int nrBucati) :idNava(++id), nrBucati(nrBucati) {
		this->marca = "Honda";
		this->culoare = new char[strlen("Alb") + 1];
		strcpy_s(this->culoare, strlen("Alb") + 1, "Alb");
		this->pret = new float[nrBucati];
		for (int i = 0; i < nrBucati; i++) {
			this->pret[i] = 20500.0f;
		}
	}

	//constructor cu 2 parametri dintre care unul este pret, in acest caz putem face la initialiare un array de valori ce pot fi atribuite pretului
	Nava(int nrBucati, float* pret) :idNava(++id), nrBucati(nrBucati){
		this->marca = "Dacia";
		this->culoare = new char[strlen("Negru") + 1];
		strcpy_s(this->culoare, strlen("Negru") + 1, "Negru");
		this -> pret = new float[nrBucati];
		for (int i = 0; i < nrBucati; i++) {
			this->pret[i] = pret[i];
		}
	}

	//constructor cu 2 parametrii fara pret;
	Nava(int nrBucati, string marca) :idNava(++id), nrBucati(nrBucati) {
		this->marca = marca;
		this->culoare = new char[strlen("Verde") + 1];
		strcpy_s(this->culoare, strlen("Verde") + 1, "Verde");
		this->pret = new float[nrBucati];
		for (int i = 0; i < nrBucati; i++) {
			this->pret[i] = 54000.0f;
		}
	}

	~Nava() {
		if (this->culoare != nullptr) {
			delete[] this->culoare;
		}
		if (this->pret != nullptr) {
			delete[] this->pret;
		}
	}




	void afisare() {
		cout << "Numar bucati: " << this->nrBucati << endl;
		cout << "Marca: " << this->marca << endl;
		cout << "Culoare: " << this->culoare << endl;
		cout << "ID Nava: " << this->idNava << endl;
		cout << "Nr Bucati: " << this->nrBucati << endl;
		if (this->pret != nullptr) {
			cout << "pret: ";
			for (int i = 0; i < this->nrBucati; i++) {
				cout << this->pret[i] << " ";
			}
			cout << endl;
		}
		else {
			cout << "Nu exista preturi" << endl;
		}
		cout << endl;
	}

	Nava(const Nava &otherNava):idNava(++id), nrBucati(otherNava.nrBucati) {
		this->culoare = new char[strlen(otherNava.culoare) + 1];
		strcpy_s(this->culoare, strlen(otherNava.culoare) + 1, otherNava.culoare);
		this->marca = otherNava.marca;
		if (otherNava.pret != nullptr) {
			this->pret = new float[this->nrBucati];
			for (int i = 0; i < nrBucati; i++) {
				this->pret[i] = otherNava.pret[i];
			}
		}
		else {
			this->pret = nullptr;
		}


	}

};

int Nava::id = 0;

void main() {
	Nava navaFaraParametru;
	navaFaraParametru.afisare();

	
	Nava navaUnParametru(1);
	navaUnParametru.afisare();

	float pret[] = { 20300.0f, 21600.0f};
	Nava nava2Parametri(2, pret);
	nava2Parametri.afisare();

	Nava nava2parametriFaraPret(1, "Hiundai");
	nava2parametriFaraPret.afisare();

	Nava nava3 = nava2parametriFaraPret;
	nava3.afisare();
}