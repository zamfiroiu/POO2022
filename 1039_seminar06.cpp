#include<iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;

class Apartament {
private:
	int nrCamere;
	float* suprafeteCamere;
	string adresa;
	int nrLocatari;
	const int nrApartament;
	static float taxaCuratenie;
	static int contor;

public:

	float* getSuprafeteCamere() {
		return this->suprafeteCamere;
	}

	int getnrCamere()
	{
		return this->nrCamere;
	}
	void setNrCamere(int nrCamere, float* suprafeteCamere)
	{
		if (nrCamere > 0)
		{
			this->nrCamere = nrCamere;
			if (this->suprafeteCamere != NULL)
			{
				delete[]this->suprafeteCamere;
			}
			this->suprafeteCamere = new float[nrCamere];
			for (int i = 0; i < nrCamere; i++)
			{
				this->suprafeteCamere[i] = suprafeteCamere[i];
			}
		}
	}
	string getAdresa()
	{
		return this->adresa;
	}
	void setAdresa(string adresa)
	{
		if (adresa.length() > 5)
			this->adresa = adresa;
	}
	Apartament() :nrApartament(contor++) {
		nrCamere = 4;
		suprafeteCamere = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++)
			suprafeteCamere[i] = 2 * i + 8;
		adresa = "Piata Romana";
		nrLocatari = 6;
	}
	Apartament(int nrCamere, float* suprafeteCamere, string adresa, int nrLocatari) :nrApartament(contor++)
	{
		this->nrCamere = nrCamere;
		this->suprafeteCamere = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++)
		{
			this->suprafeteCamere[i] = suprafeteCamere[i];
		}
		this->adresa = adresa;
		this->nrLocatari = nrLocatari;
	}
	Apartament(string adresa, int nrlocatari) :nrApartament(contor++)
	{
		this->adresa = adresa;
		this->nrLocatari = nrLocatari;
		nrCamere = 0;
		suprafeteCamere = NULL;

	}

	Apartament(const Apartament& a) :nrApartament(contor++)
	{
		this->nrCamere = a.nrCamere;
		suprafeteCamere = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++)
		{
			this->suprafeteCamere[i] = a.suprafeteCamere[i];
		}
		this->adresa = a.adresa;
		this->nrLocatari = a.nrLocatari;
	}

	Apartament& operator=(const Apartament& ap) {
		if (this != &ap) { //verificare de autoasignare
			this->nrCamere = ap.nrCamere;
			this->adresa = ap.adresa;
			this->nrLocatari = ap.nrLocatari;
			if (this->suprafeteCamere != NULL)
				delete[] suprafeteCamere;
			this->suprafeteCamere = new float[nrCamere];
			for (int i = 0; i < nrCamere; i++)
			{
				this->suprafeteCamere[i] = ap.suprafeteCamere[i];
			}
		}
		return *this;
	}
	Apartament operator+(const Apartament& ap) {
		Apartament aux(*this);
		aux.nrLocatari = ap.nrLocatari + this->nrLocatari;
		return aux;
	}
	void afisareApartament() {
		cout << "Ap cu nr: " << nrApartament << endl;
		cout << "Nr camere: " << nrCamere << endl;
		cout << "Suprafete: ";
		for (int i = 0; i < nrCamere; i++)
		{
			cout << suprafeteCamere[i] << ", ";
		}
		cout << endl;
		cout << "Adresa: " << adresa << endl;
		cout << "Nr locatari: " << nrLocatari << endl;
		cout << "Taxa de curatenie: " << taxaCuratenie << endl;
		cout << endl;
	}
	~Apartament()
	{
		if (suprafeteCamere != NULL)
			delete[]suprafeteCamere;

	}
};
float Apartament::taxaCuratenie = 10;
int Apartament::contor = 1;

void f(Apartament a) {
	a.setAdresa("hgfjfg");
}

Apartament g() {
	Apartament a;
	return a;
}

void main() {
	Apartament ap1;
	Apartament ap2;
	ap1.afisareApartament();
	ap2.afisareApartament();
	int nrCamere = 3;
	float* suprafeteCamere;
	suprafeteCamere = new float[nrCamere];
	for (int i = 0; i < nrCamere; i++)
		suprafeteCamere[i] = 10 + i * 3;

	Apartament ap3(nrCamere, suprafeteCamere, "Splaiul Unirii", 3);
	ap3.afisareApartament();

	Apartament ap4 = ap3;
	Apartament ap5;
	ap5 = ap3 = ap4;
	//ap5= r

	Apartament ap6 = ap3 + ap4;
	ap6.afisareApartament();
	int x = 3;
	int y = 8;
	int z = x + y;

	ap4.getSuprafeteCamere()[0] = 11;
	ap3.getSuprafeteCamere()[0] = 89;
	cout << ap4.getSuprafeteCamere()[0];

	f(ap4);
	ap4=g();

	ap3 = ap3;

	delete[]suprafeteCamere;


}