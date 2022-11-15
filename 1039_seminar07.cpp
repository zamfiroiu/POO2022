#include<iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ostream;
using std::istream;


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
	Apartament(string adresa, int nrLocatari) :nrApartament(contor++)
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
	Apartament operator++(){
		this->nrLocatari++;
		return *this;
	}
	Apartament operator++(int) {
		Apartament aux;
		aux = *this;
		this->nrLocatari++;
		return aux;

	}
	friend ostream& operator<<(ostream& afis,const Apartament& ap) {
		afis << "Ap cu nr: " << ap.nrApartament << endl;
		afis << "Nr camere: " << ap.nrCamere << endl;
		afis << "Suprafete: ";
		for (int i = 0; i < ap.nrCamere; i++)
		{
			afis << ap.suprafeteCamere[i] << ", ";
		}
		afis << endl;
		afis << "Adresa: " << ap.adresa << endl;
		afis << "Nr locatari: " << ap.nrLocatari << endl;
		afis << "Taxa de curatenie: " << ap.taxaCuratenie << endl;
		afis << endl;
		return afis;
	}
	friend istream& operator>>(istream& cit, Apartament& ap) {
		cout << "Nr de camere:";
		cit >> ap.nrCamere;
		cout << "Suprafata:";
		if (ap.suprafeteCamere != NULL)
			delete[]ap.suprafeteCamere;
		ap.suprafeteCamere = new float[ap.nrCamere];
		for (int i = 0; i < ap.nrCamere; i++)
		{
			cit >> ap.suprafeteCamere[i]; 
		}
		cout << "Adresa:";
		cit >> ap.adresa;
		cout << "Nr de locatari: ";
		cit >> ap.nrLocatari;
		return cit;
	}
	bool operator>(const Apartament& a)
	{
		return this->nrLocatari > a.nrLocatari;
	}
	bool operator==(const Apartament& a)
	{
		return (this->nrLocatari == a.nrLocatari) && (this->nrCamere == a.nrCamere);
	}

};
float Apartament::taxaCuratenie = 10;
int Apartament::contor = 1;


void main() {
	/*Apartament ap1;
	Apartament ap2;*/
	//ap1.afisareApartament();
	//ap2.afisareApartament();

	//ap3.afisareApartament();

	/*Apartament ap4 = ap3;
	Apartament ap5;
	ap5 = ap3 = ap4;*/
	//ap5= r

	//Apartament ap6 = ap3 + ap4;
	//ap6.afisareApartament();
	/*int x = 3;
	int y = 8;
	int z = x + y;*/

	/*ap4.getSuprafeteCamere()[0] = 11;
	ap3.getSuprafeteCamere()[0] = 89;
	cout << ap4.getSuprafeteCamere()[0];*/

	//f(ap4);
	//ap4 = g();

	//ap3 = ap3;
	int nrCamere = 3;
	float* suprafeteCamere;
	suprafeteCamere = new float[nrCamere];
	for (int i = 0; i < nrCamere; i++)
		suprafeteCamere[i] = 10 + i * 3;

	Apartament ap3(nrCamere, suprafeteCamere, "Splaiul Unirii", 3);
	Apartament ap4("Romana", 4);

	ap3.afisareApartament();
	cout << endl;
	cout << ap3<<endl;
	//rezultat___ << endl;
	//ostream&
	//cin >> ap3;
	//istream&
	cout << ap3;

	if (ap3 > ap4) {
		cout<<"Apartamentul din " << ap3.getAdresa() << " are mai multi locatari." << endl;
	}
	else
	{
		cout << "Apartamentul din " << ap4.getAdresa() << " are mai multi locatari." << endl;

	}

	cout << ap3<<endl;
	ap3++;
	cout << ap3;




	
	delete[]suprafeteCamere;


}