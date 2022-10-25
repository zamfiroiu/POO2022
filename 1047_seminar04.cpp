//#include<iostream>
//#include<string>
//using std::string;
//using  std::cout;
//using  std::cin;
//using  std::endl;
//
//class Angajat
//{
//private:
//	string nume;
//	float salariu;
//	int zileLucrate;
//	int* oreLucratePeZi;
//	static int normaPeSaptamana;
//	static int contor;
//	const int marca;
//public:
//	Angajat():marca(contor)
//	{
//		contor++;
//		this->nume = "Popescu";
//		this->salariu = 5000;
//		this->zileLucrate = 10;
//		this->oreLucratePeZi = new int[this->zileLucrate];
//		for (int i = 0; i < this->zileLucrate; i++) {
//			this->oreLucratePeZi[i] = i + 1;
//		}
//	}
//	Angajat(string nume, float salariu, int zileLucrate, const int* oreLucratePeZi):marca(contor++) {
//		this->nume = nume;
//		this->salariu = salariu;
//		this->zileLucrate = zileLucrate;
//		this->oreLucratePeZi = new int[this->zileLucrate];
//		for (int i = 0; i < this->zileLucrate; i++)
//		{
//			this->oreLucratePeZi[i] = oreLucratePeZi[i]; //deep copy 
//		}
//	}
//	void afisareAngajat()
//	{
//		cout << "Marca: " << this->marca << endl;
//		cout << "Nume: " << this->nume << endl;
//		cout << "Salariu: " << this->salariu << endl;
//		cout << "Zile lucrate: " << this->zileLucrate << endl;
//		cout << "Ore lucrate pe zi: ";
//		for (int i = 0; i < zileLucrate; i++)
//			cout << oreLucratePeZi[i] << ",";
//		cout << endl;
//		cout << "Norma pe saptamana: " << this->normaPeSaptamana << endl;
//
//	}
//	//void setNume (string )
//};
//
//int Angajat::contor = 100;
//int Angajat::normaPeSaptamana = 40;
//
//
//void main() {
//	Angajat angajat1=Angajat();
//	angajat1.afisareAngajat();
//
//
//	Angajat angajat2;
//	angajat2.afisareAngajat();
//
//	int* vector;
//	int nrZile=30;
//	vector = new int[nrZile];
//	for (int i = 0; i < nrZile; i++)
//	{
//		vector[i] = i + 2;
//	}
//	Angajat angajat3("Ionescu", 4000, nrZile, vector);
//	angajat3.afisareAngajat();
//
//	//Angajat angajat4("Vasilescu", 3000, 4, new int[4] {8, 7, 9, 6});
//	//angajat4.afisareAngajat();
//
//	delete[]vector;
//}
