#include<iostream>
#include<string>
#include<iomanip> 

using namespace std;

class Masina {
private:
	static int nrMasini;
	int anFabricatie;
	const int id;
	float* pret;

public:
	string marca;
	int nrUsi;
	char* culoare;


	
	//comstructor fara parametrii
	Masina() :id(++nrMasini){
		this->marca = "";
		this->nrUsi = 0;
		this->culoare = new char[strlen("") + 1];
		strcpy_s(this->culoare, strlen("") + 1, "");
		this->pret = nullptr;

	}

	//constructor cu un parametru
	Masina(string marca) :id(++nrMasini) {
		this->marca = marca;
		this->nrUsi = 4;
		this->culoare = new char[strlen("Neagra") + 1];
		strcpy_s(this->culoare, strlen("Neagra") + 1, "Neagra");
		this->pret = new float[nrUsi];
		for (int i = 0; i < nrUsi; i++) {
			this->pret[i] = 8.9;

		}

	}

	//construtor cu toti parametrii
	Masina(string marca, int nrUsi,const char* culoare, const float* pret) :id(++nrMasini) {
		this->marca = marca;
		this->nrUsi = nrUsi;
		this->culoare = new char[strlen(culoare) + 1];
		strcpy_s(this->culoare, strlen(culoare) + 1, culoare);
		this->pret = new float[nrUsi];
		for (int i = 0; i < nrUsi; i++) {
			this->pret[i] = pret[i];
		}
		
	}

	//Destructor
	~Masina() {
		if (this->culoare != NULL) {
			delete[] this->culoare;
		}
		if (this->pret != nullptr) {
			delete[] this->pret;
		}
	}

	void afisare() {
		cout << "ID: " << this->id << endl;
		cout << "Marca: " << this->marca << endl;
		cout << "Nr Usi: " << this->nrUsi << endl;
		cout << "Culoare: " << this->culoare << endl;

		if (this->pret != nullptr) { // Verificăm dacă prețurile sunt disponibile
			cout << "Preturi: ";
			for (int i = 0; i < this->nrUsi; i++) {
				cout << this->pret[i] << " ";
			}
			cout << endl;
		}
		else {
			cout << "Preturi: Nu sunt disponibile" << endl;
		}
	}


};

//cand avem static difinim in afara clasei;
//este o variabilă care își păstrează valoarea între apelurile funcțiilor și are o durată de viață extinsă,
// adică este alocată o singură dată și există pe toată durata execuției programului
int Masina::nrMasini = 0;

void main() {
	//apelare constructor fara parametri
	Masina masina1;
	masina1.afisare();

	//apelare constructor cu 1 parametru
	Masina masina2("Dacia");
	masina2.afisare();

	float preturi[] = { 10800,11500,50000,12000, 23000};

	Masina masina3("Honda", 5, "Verde", preturi);
	masina3.afisare();


}