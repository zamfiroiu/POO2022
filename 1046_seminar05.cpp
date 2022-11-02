#include<iostream>
using  std::string;
using std::cout;
using std::endl;
enum TipCafea { expresso, machiatto, latte, capuccino };
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

	Cafenea(string nume,
		int nrProduse,
		float* preturi,
		TipCafea* tipuri,
		int nrClientiZi, 
		int anNou):anInfiintare(anNou) {

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
	Cafenea(string nume, int nrClientiZi):anInfiintare(2010)
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
			<< "Numar produse: " << this->nrProduse<<endl;

		for (int i = 0; i < this->nrProduse; i++) {
			cout << preturi[i] << "-";
			cout << getNumeTip(tipuri[i]) << ",";

		}
		cout << this->nrClientiZi;
		cout << endl;
	}

	~Cafenea() {
		if (this->preturi != NULL) {
			delete [] this->preturi;
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
};

int Cafenea::TVA = 5;

void main() {
	int valoare;
	Cafenea cafenea;

	cafenea.afisareCafenea();

	float* preturiCafele = new float[3] {8.3, 5.5, 10.2};
	TipCafea* tipuriCafele = new TipCafea[3]{ expresso,capuccino,latte };

	Cafenea cafenea2("5toGO", 3, preturiCafele, tipuriCafele, 20, 2000);
	cout << endl;
	cafenea2.afisareCafenea();

	Cafenea cafenea3("Tucano", 30);
	cafenea3.afisareCafenea();

	cafenea3.setNrClientiZi(7);
	cout << cafenea3.getNrClientiZi()<< endl;

	float* preturi = new float[4] {2.5, 10, 11, 5};
	TipCafea* tipuri = new TipCafea[4]{ expresso,capuccino,latte,expresso };
	cafenea3.setNrProduse(4, preturi, tipuri);
	cout << cafenea3.getNrProduse();

	float* v = cafenea3.getPreturi();
	for(int i=0; i<cafenea3.getNrProduse(); i++) {
		cout << v[i] << endl;
	}

	delete[]preturiCafele;
	delete[]tipuriCafele;

	delete[]preturi;
	delete[]tipuri;

	
}