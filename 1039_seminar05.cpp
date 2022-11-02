#include<iostream>
#include <string>

using  std::cout;
using std::cin;
using std::string;
using std::endl;

//
//char* citire() {
//	char* sir;
//
//	char buffer[500];
//	cin.getline(buffer, 500);
//	sir = new char[strlen(buffer) + 1];
//	strcpy_s(sir, strlen(buffer) + 1, buffer);
//	return sir;
//}


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
		if(suprafeteCamere!=NULL)
			delete[]suprafeteCamere;

	}
};
float Apartament::taxaCuratenie = 10;
int Apartament::contor = 1;

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
	//Apartament ap4(2, new float[2] {14,25},"Bucuresti",4);
	//ap4.afisareApartament();
	Apartament ap5("Piata Romana", 3);
	ap5.afisareApartament();
	ap5.setAdresa("Piata Unirii");
	cout<<ap5.getAdresa();
	cout << endl;

	if (5 < 6)
	{
		Apartament ap6;
		cout << ap6.getAdresa();
	}
	float* sc;
	sc = new float[2] {10, 12};
	ap5.setNrCamere(2, sc);
	cout << endl;
	cout << ap5.getnrCamere() << endl;
	

	float* vSuprafete;
	vSuprafete = ap5.getSuprafeteCamere();


	for (int i = 0; i < ap5.getnrCamere(); i++)
	{
		cout << vSuprafete[i] << " ";
	}

	delete[]suprafeteCamere;
	delete[] sc;
}