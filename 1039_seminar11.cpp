#include<iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ostream;
using std::istream;

//penthouse - nrEtaje, suprafataTerasa
//ApartamentInchiriat - chirie, perioadaContract
//ApartamentCumparat
//ApartamentSupraetajat - penthouse
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
	Apartament operator++() {
		this->nrLocatari++;
		return *this;
	}
	Apartament operator++(int) {
		Apartament aux;
		aux = *this;
		this->nrLocatari++;
		return aux;

	}
	friend ostream& operator<<(ostream& afis, const Apartament& ap) {
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

class Penthouse :public Apartament {
private:
	int nrEtaje;
	float* supPerEtaj;
	float supTerasa;
public:
	Penthouse() :Apartament() {
		this->nrEtaje = 0;
		this->supPerEtaj = NULL;
		this->supTerasa = 0;
	};
	Penthouse(int pNrEtaje, float* pSupPerEtaj, float pSupTerasa, int pNrCamere, float* pSupCamere, string pAdresa, int pNrLocatari) :Apartament(pNrCamere, pSupCamere, pAdresa, pNrLocatari) {
		this->nrEtaje = pNrEtaje;
		this->supPerEtaj = new float[pNrEtaje];
		for (int i = 0; i < pNrEtaje; i++) {
			this->supPerEtaj[i] = pSupPerEtaj[i];
		}
		this->supTerasa = pSupTerasa;


	};

	~Penthouse() {
		if (this->supPerEtaj != NULL) {
			delete[]this->supPerEtaj;
		}
	}

	Penthouse(const Penthouse& p) :Apartament(p) {
		this->nrEtaje = p.nrEtaje;
		this->supPerEtaj = new float[p.nrEtaje];
		for (int i = 0; i < p.nrEtaje; i++) {
			this->supPerEtaj[i] = p.supPerEtaj[i];
		}
		this->supTerasa = p.supTerasa;

	}

	Penthouse& operator=(const Penthouse& p) {
		if (this != &p) {
			(Apartament)*this = (Apartament)p;
			//Apartament::operator=(p);
			if (this->supPerEtaj != NULL) {
				delete[]this->supPerEtaj;
			}
			this->nrEtaje = p.nrEtaje;
			this->supPerEtaj = new float[p.nrEtaje];
			for (int i = 0; i < p.nrEtaje; i++) {
				this->supPerEtaj[i] = p.supPerEtaj[i];
			}
			this->supTerasa = p.supTerasa;

		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Penthouse& p){
		out << "Penthouse" << endl;
		out << "Nr etaje: " << p.nrEtaje << endl;
		out << "Suprafeta etaje: ";
		for (int i = 0; i < p.nrEtaje; i++) {
			out << p.supPerEtaj[i] << " ";
		}
		out << endl;
		out << "Suprafata terasa: " << p.supTerasa;
		out << endl;
		out << "Apartament" << endl;
		out << (Apartament)p;
		return out;
	}

	float getSuprafataConstr() {
		//this->supTerasa
		float rez=0;
		for (int i = 0; i < getnrCamere(); i++)
		{
			rez += this->getSuprafeteCamere()[i];
		}
		rez += this->supTerasa;
		return rez;
	}

};

void main() {
	Penthouse p;

	float* suprafeteEt=new float[2]{ 50.7f,24.8f};
	float* suprCamere = new float[3] {34.7, 76.9, 23.8};
	Penthouse p1(2, suprafeteEt, 38.9, 3, suprCamere, "Piata Unirii", 5);
	p = p1;
	Penthouse p2 = p1;
	cout << p1;

	cout << p2.getSuprafataConstr();
	

	cout << p.getnrCamere();

	Apartament ap;
	cout << ap.getnrCamere();

}