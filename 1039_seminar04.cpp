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

	Apartament():nrApartament(contor++) {
		nrCamere = 4;
		suprafeteCamere = new float[nrCamere];
		for (int i = 0; i < nrCamere; i++)
			suprafeteCamere[i] = 2 * i + 8;
		adresa = "Piata Romana";
		nrLocatari = 6;
	}
	Apartament(int nrCamere, float* suprafeteCamere, string adresa, int nrLocatari):nrApartament(contor++)
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

	void afisareApartament() {
		cout << "Ap cu nr: " << nrApartament << endl;
		cout <<"Nr camere: " << nrCamere << endl;
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
};
float Apartament::taxaCuratenie = 10;
int Apartament::contor = 1;

void main() {
	Apartament ap1;
	Apartament ap2;
	ap1.afisareApartament();
	ap2.afisareApartament();
	int nrCamere=3;
	float* suprafeteCamere;
	suprafeteCamere = new float[nrCamere];
	for (int i = 0; i < nrCamere; i++)
		suprafeteCamere[i] = 10 + i * 3;
	
	Apartament ap3(nrCamere,suprafeteCamere,"Splaiul Unirii",3);
	ap3.afisareApartament();
	//Apartament ap4(2, new float[2] {14,25},"Bucuresti",4);
	//ap4.afisareApartament();

	delete[]suprafeteCamere;
}