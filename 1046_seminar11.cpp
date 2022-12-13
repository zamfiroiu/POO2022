#include<iostream>
#include <string>
#include<fstream>
using namespace std;

enum TipCafea { expresso, machiatto, latte, capuccino };
//
// bistro - produsAlimentar, preturi
// CafeneaVegana
// CafeneaToGo
// CafeneaFranciza - franciza, pretulFrancizei
// CafeneaCuPisici
//
class Cafenea {
	string nume;
	int nrProduse;
	float* preturi;
	TipCafea* tipuri;
	int nrClientiZi;
	static int TVA;
	const int anInfiintare;

	static string getNumeTip(TipCafea tip) {

		if (tip == expresso)
			return "expresso";
		if (tip == machiatto)
			return "machiatto";
		if (tip == latte)
			return "latte";
		if (tip == capuccino)
			return "capuccino";
	}


public:


	float operator()() {
		float suma = 0;
		for (int i = 0; i < this->nrProduse; i++) {
			suma += (float)TVA * 0.01 * this->preturi[i];
		}
		return suma;
	}

	string getNume() {
		return this->nume;
	}

	Cafenea() : anInfiintare(2022) {
		this->nume = "Teds";
		this->nrProduse = 5;
		this->preturi = new float[nrProduse];
		this->tipuri = new TipCafea[nrProduse];
		preturi[0] = 10;
		preturi[1] = 8;
		preturi[2] = 6;
		preturi[3] = 7;
		preturi[4] = 9;
		tipuri[0] = expresso;
		tipuri[1] = latte;
		tipuri[2] = latte;
		tipuri[3] = capuccino;
		tipuri[4] = machiatto;
		this->nrClientiZi = 10;


	}

	Cafenea(const Cafenea& c) :anInfiintare(c.anInfiintare) {
		this->nume = c.nume;
		this->nrClientiZi = c.nrClientiZi;
		this->nrProduse = c.nrProduse;
		if (this->nrProduse > 0) {
			this->preturi = new float[nrProduse];
			this->tipuri = new TipCafea[nrProduse];
			for (int i = 0; i < nrProduse; i++) {
				this->preturi[i] = c.preturi[i];
				this->tipuri[i] = c.tipuri[i];
			}
		}
		else
		{
			this->preturi = NULL;
			this->tipuri = NULL;
		}




	}

	Cafenea& operator=(const Cafenea& c)
	{
		if (this != &c) { //verificare de autoasignare
			this->nume = c.nume;
			this->nrClientiZi = c.nrClientiZi;
			this->nrProduse = c.nrProduse;
			if (this->preturi != NULL) {
				delete[]this->preturi;
			}
			if (this->tipuri != NULL) {
				delete[]this->tipuri;
			}
			this->preturi = new float[nrProduse];
			this->tipuri = new TipCafea[nrProduse];
			for (int i = 0; i < nrProduse; i++)
			{
				this->preturi[i] = c.preturi[i];
				this->tipuri[i] = c.tipuri[i];
			}
		}
		return *this;

	}



	Cafenea(string nume,
		int nrProduse,
		float* preturi,
		TipCafea* tipuri,
		int nrClientiZi,
		int anNou) :anInfiintare(anNou) {

		this->nume = nume;
		this->nrProduse = nrProduse;
		this->preturi = new float[nrProduse];
		this->tipuri = new TipCafea[nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->preturi[i] = preturi[i];
			this->tipuri[i] = tipuri[i];
		}
		this->nrClientiZi = nrClientiZi;


	}
	Cafenea(string nume, int nrClientiZi) :anInfiintare(2010)
	{
		this->nume = nume;
		this->nrProduse = 0;
		this->preturi = NULL;
		this->tipuri = NULL;
		this->nrClientiZi = nrClientiZi;

	}

	//i:-
	//o:int
	int getNrClientiZi()
	{
		return nrClientiZi;
	}
	void setNrClientiZi(int nrClientiZi)
	{
		if (nrClientiZi >= 0)
		{
			this->nrClientiZi = nrClientiZi;
		}

	}


	void afisareCafenea() {
		cout << " nume: " << this->nume
			<< "Numar produse: " << this->nrProduse << endl;

		for (int i = 0; i < this->nrProduse; i++) {
			cout << preturi[i] << "-";
			cout << getNumeTip(tipuri[i]) << ",";

		}
		cout << this->nrClientiZi;
		cout << endl;
	}

	~Cafenea() {
		if (this->preturi != NULL) {
			delete[] this->preturi;
		}
		if (this->tipuri != NULL) {
			delete[]this->tipuri;
		}
	}

	int getNrProduse() {
		return nrProduse;
	}

	void setNrProduse(int nrProduse, float* preturi, TipCafea* tipcafea) {
		if (nrProduse > 0) {
			this->nrProduse = nrProduse;
			if (this->preturi != NULL) {
				delete[] this->preturi;
			}
			if (this->tipuri != NULL) {
				delete[]this->tipuri;
			}
			this->preturi = new float[nrProduse];
			this->tipuri = new TipCafea[nrProduse];
			for (int i = 0; i < this->nrProduse; i++) {
				this->preturi[i] = preturi[i];
				this->tipuri[i] = tipuri[i];
			}
		}
	}

	float* getPreturi() {
		return this->preturi;
	}

	Cafenea operator+(const Cafenea& c) {
		Cafenea aux = *this;
		aux.nrClientiZi = this->nrClientiZi + c.nrClientiZi;
		return aux;
	}

	Cafenea operator+(int nrClienti) {
		Cafenea aux = *this;
		aux.nrClientiZi += nrClienti;
		return aux;
	}

	Cafenea operator+=(int nrClienti) {
		this->nrClientiZi += nrClienti;
		return *this;;
	}


	friend ostream& operator<<(ostream& out, const Cafenea& c) {
		out << " nume: " << c.nume << endl;
		out << "Numar produse: " << c.nrProduse << endl;

		for (int i = 0; i < c.nrProduse; i++) {
			out << c.preturi[i] << "-";
			out << getNumeTip(c.tipuri[i]) << ",";

		}
		out << c.nrClientiZi;
		out << endl;
		return out;
	}

	friend istream& operator>>(istream& iStream, Cafenea& c) {
		cout << "Nume: ";
		iStream >> c.nume;
		cout << "Nr. produse: ";
		iStream >> c.nrProduse;
		if (c.preturi != NULL)
			delete[] c.preturi;

		if (c.tipuri != NULL)
			delete[] c.tipuri;

		c.preturi = new float[c.nrProduse];
		c.tipuri = new TipCafea[c.nrProduse];

		for (int i = 0; i < c.nrProduse; i++) {
			iStream >> c.preturi[i];

			int a;
			cout << "{expresso = 1, machiatto = 2, latte = 3, capuccino = 4}";
			iStream >> a;
			if (a == 1)
				c.tipuri[i] = expresso;
			if (a == 2)
				c.tipuri[i] = machiatto;
			if (a == 3)
				c.tipuri[i] = latte;
			if (a == 4)
				c.tipuri[i] = capuccino;

		}
		iStream >> c.nrClientiZi;
		return iStream;

	}



	bool operator<= (const Cafenea& c) {
		if (this->nrClientiZi <= c.nrClientiZi)
			return true;
		else {
			return false;
		}

	}

	bool operator==(const Cafenea& c) {
		if (this->nrClientiZi == c.nrClientiZi) {
			if (this->nrProduse == c.nrProduse) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}


	}
	Cafenea& operator++()
	{
		this->nrClientiZi = this->nrClientiZi + 1;
		return *this;
	}
	Cafenea operator++(int a)
	{
		Cafenea aux;
		aux = *this;
		this->nrClientiZi = this->nrClientiZi + 1;
		return aux;
	}


};
int Cafenea::TVA = 5;


class CafeneaFranciza :public Cafenea {
	char* numeFranciza;
	float pretFranciza;
public:
	CafeneaFranciza() :Cafenea() {
		this->numeFranciza = NULL;
		this->pretFranciza = 0;
	}
	CafeneaFranciza(const char* numeFranciza, float pretFranciza, string nume,
		int nrProduse,
		float* preturi,
		TipCafea* tipuri,
		int nrClientiZi,
		int anNou):Cafenea( nume,nrProduse,preturi, tipuri,nrClientiZi, anNou)
	{
		this->numeFranciza = new char[strlen(numeFranciza) + 1];
		strcpy_s(this->numeFranciza, strlen(numeFranciza) + 1, numeFranciza);
		this->pretFranciza = pretFranciza;
	}

	~CafeneaFranciza() {
		if (this->numeFranciza != NULL)
			delete[]this->numeFranciza;
	}

	CafeneaFranciza operator=(const CafeneaFranciza& c) {
		if (this != &c) {
			Cafenea::operator=(c);
			if (this->numeFranciza != NULL)
				delete[]this->numeFranciza;
			this->numeFranciza = new char[strlen(c.numeFranciza) + 1];
			strcpy_s(this->numeFranciza, strlen(c.numeFranciza) + 1, c.numeFranciza);
			this->pretFranciza = c.pretFranciza;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, CafeneaFranciza c) {
		out << (Cafenea)c;
		out << "numele Francizei este " << c.numeFranciza << endl
			<< "pretul Francizei este " << c.pretFranciza<<endl;
		return out;
 }
	friend ofstream& operator<<(ofstream& out, const CafeneaFranciza& c) {
		out << c.numeFranciza << ',';
		out << c.pretFranciza << endl;
		return out;
	}



	CafeneaFranciza(const CafeneaFranciza& copie):Cafenea(copie) {
		this->numeFranciza = new char[strlen(copie.numeFranciza) + 1];
		strcpy_s(this->numeFranciza, strlen(copie.numeFranciza) + 1, copie.numeFranciza);
		this->pretFranciza = copie.pretFranciza;
	}

	float getNumarSeturi()
	{
		float suma = 0;
		float rezultat = 0;
		for (int i = 0; i <this->getNrProduse(); i++)
		{
			suma += this->getPreturi()[i];
		}
		rezultat = this->pretFranciza / suma;

		return rezultat;
	}

};

void main() {
	CafeneaFranciza c1;
	
	float* preturi = new float[2] {25, 13};
	TipCafea* tipuri = new TipCafea[2]{ expresso,latte };
	
	CafeneaFranciza c2("StarbucksRomania", 1200, "Starbucks", 2, preturi, tipuri, 10, 2010);
	CafeneaFranciza c4("5ToGoRomana", 1200, "5ToGo", 2, preturi, tipuri, 10, 2010);

	c1 = c2;

	CafeneaFranciza c3(c2);
	cout << c3;

	cout << "Cafeneaua trebuie sa vanda " << c2.getNumarSeturi() << " seturi";
	
	ofstream f("fisier.csv", ios::app);
	f << "Nume Franciza, Pret franciza"<<endl;
	f << c3;
	f << c4 << c2;
	f.close();
}