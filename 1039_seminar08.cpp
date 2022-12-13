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
	static void adaugaApartInVect(Apartament*& vector, Apartament obiect, int& nr) {
		Apartament* aux = new Apartament[nr+1];
		for (int i = 0; i < nr; i++) {
			aux[i] = vector[i];
		}
		aux[nr] = obiect;
		nr++;
		if(vector != NULL)
			delete[] vector;
		vector = aux;
	}
	static void adaugaApartInVectorP(Apartament**& v, const Apartament &a, int& n)
	{
		Apartament** aux = new Apartament * [n + 1];
		for (int i = 0; i < n; i++)
		{
			aux[i] = v[i];
		}
		aux[n] = new Apartament(a);
		n++;
		if (v != NULL)
			delete[]v;
		v = aux;
	}
};
float Apartament::taxaCuratenie = 10;
int Apartament::contor = 1;


void main() {
	//*vector de obiecte
	//*adaugare obiect in vector
	//vector de pointeri
	//adaugare pointer in vector
	//fisiere
	/*int n;
	cout << "Nr de apartamente: ";
	cin >> n;
	Apartament* vectorApart;
	vectorApart = new Apartament[n];
	for (int i = 0; i < n; i++)
	{
		cin >> vectorApart[i];
	}
	Apartament ap("Piata Romana", 20);
	Apartament::adaugaApartInVect(vectorApart, ap, n);
	for (int i = 0; i < n; i++)
	{
		cout << vectorApart[i];
	}
	delete[] vectorApart;*/

	Apartament** vectorP;
	cout << "numarul de apartamente: ";
	int n;
	cin >> n;
	vectorP = new Apartament * [n];
	for (int i = 0; i < n; i++)
	{
		vectorP[i] = new Apartament();
		cin >> *(vectorP[i]);
	}
	Apartament a("universitate", 3);
	Apartament::adaugaApartInVectorP(vectorP, a, n);
	for (int i = 0; i < n; i++)
	{
		cout << *(vectorP[i]);
	}
	for (int i = 0; i < n; i++)
	{
		delete vectorP[i];
	}
	delete[]vectorP;
}