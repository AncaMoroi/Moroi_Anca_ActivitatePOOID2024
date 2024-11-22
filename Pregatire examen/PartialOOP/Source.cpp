#include<iostream>

using namespace std;

class Masina {
private:
	int nrInventar;
	static int id;
	char* producator;
	int nrStoc;
	const int anFabricatie;
	float* pret;

public:
	Masina() :nrInventar(++id), anFabricatie(0) {
		this->nrStoc = 0;
		this->producator = new char[strlen("Necunoscut") + 1];
		strcpy_s(this->producator, strlen("Necunoscut") + 1, "Necunoscut");
		this->pret = nullptr;

	}

	Masina(const char* producator, int nrStoc, const float* pret) : nrInventar(++id), anFabricatie(2010) {
		this->nrStoc = nrStoc;
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
		if (nrStoc > 0) {
			this->pret = new float[nrStoc];
			for (int i = 0; i < nrStoc; i++) {
				this->pret[i] = pret[i];
			}
		}
		else {
			this->pret = nullptr;
		}
	}

	Masina(const Masina& masinaCopiata) :nrInventar(++id), anFabricatie(masinaCopiata.anFabricatie) {
		this->nrStoc = masinaCopiata.nrStoc;
		this->producator = new char[strlen(masinaCopiata.producator) + 1];
		strcpy_s(this->producator, strlen(masinaCopiata.producator) + 1, masinaCopiata.producator);
		if (masinaCopiata.nrStoc > 0) {
			this->pret = new float[masinaCopiata.nrStoc];
			for (int i = 0; i < masinaCopiata.nrStoc; i++) {
				this->pret[i] = masinaCopiata.pret[i];
			}
		}
		else {
			this->pret = nullptr;
		}

	}

	const char* getProducator() {
		return this->producator;
	}

	void setProducator(const char* producator) {
		if (this->producator != nullptr) {
			delete[] this->producator;
		}
		this->producator = new char[strlen(producator) + 1];
		strcpy_s(this->producator, strlen(producator) + 1, producator);
	}

	int getNrStoc() {
		return this->nrStoc;
	}

	void setNrStoc(int nrStoc) {
		if (this->pret != 0) {
			delete[] this->pret;
		}
		this->nrStoc = nrStoc;
	}

	const float* getPret() {
		return this->pret;
	}

	void setPret(const float* pret, int nrStoc) {
		this->nrStoc = nrStoc;
		if (pret && nrStoc > 0) {
			this->pret = new float[nrStoc];
			for (int i = 0; i < nrStoc; i++) {
				this->pret[i] = pret[i];
			}
		}
	}

	~Masina() {
		if (this->producator != nullptr) {
			delete[] this->producator;
		}
		if (this->pret != 0) {
			delete[] this->pret;
		}
	}

	friend ostream& operator<<(ostream& consola,const Masina& masina) {
		consola << "ID: " << masina.id << endl;
		consola << "Nr. Inventar: " << masina.nrInventar << endl;
		consola << "An Fabricatie: " << masina.anFabricatie << endl;
		consola << "Producator: ";
		if (masina.producator != nullptr) {
			consola << masina.producator << endl;
		}
		else {
			consola << "n/a" << endl;
		}
		consola << "stoc: " << masina.nrStoc << endl;
		consola << "Pret";
		if (masina.nrStoc > 0) {
			for (int i = 0; i < masina.nrStoc; i++) {
				consola << masina.pret[i] << ";";

			}
			consola << endl;
		}
		else {
			consola << 0 << endl;
		}
		consola << endl;
	    return consola;
	}
	
	
};

int Masina::id = 0;

void main() {
	Masina mfp;
	cout << mfp;

	float pret[] = { 5000.0f, 4000.0f,30000.0f };
	Masina m1p("Tesla", 3, pret);
	cout << m1p;


	float pretA[] = { 35000.0f };
	Masina mpc("Honda", 1, pretA);
	cout << mpc;

	m1p.setProducator("Volvo");
	cout << m1p;


	float pretNou[] = {450000.0f};
	mpc.setPret(pretNou,1);
	cout << mpc;

	Masina mpc2 = mpc;
	cout << mpc2;
}