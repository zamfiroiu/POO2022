#include<iostream>
using  std::string;
using std::cout;
enum TipCafea{expresso, machiatto,latte,capuccino};
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
	Cafenea(): anInfiintare(2022) {
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



	void afisareCafenea() {
		cout << " nume: " << this->nume
			<< "Numar produse: " << this->nrProduse;
		
		for (int i = 0; i < this-> nrProduse; i++) {
			cout << preturi[i]<<"-";
			cout << getNumeTip(tipuri[i]) << ",";

		}
		cout << this->nrClientiZi;

	}

};

int Cafenea::TVA = 5;

void main() {
	int valoare;
	Cafenea cafenea;

	cafenea.afisareCafenea();
}