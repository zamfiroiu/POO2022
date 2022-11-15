//#include<iostream>
//#include<string>
//using std::string;
//using  std::cout;
//using  std::cin;
//using  std::endl;
//using std::ostream;
//using std::istream;
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
//	Angajat() :marca(contor)
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
//	Angajat(string nume, float salariu, int zileLucrate, const int* oreLucratePeZi) :marca(contor++) {
//		this->nume = nume;
//		this->salariu = salariu;
//		this->zileLucrate = zileLucrate;
//		this->oreLucratePeZi = new int[this->zileLucrate];
//		for (int i = 0; i < this->zileLucrate; i++)
//		{
//			this->oreLucratePeZi[i] = oreLucratePeZi[i]; //deep copy 
//		}
//	}
//	Angajat(string nume, float salariu) :marca(contor++)
//	{
//		this->nume = nume;
//		this->salariu = salariu;
//		this->zileLucrate = 0;
//		this->oreLucratePeZi = NULL;
//	}
//
//	string getNume()
//	{
//		return nume;
//	}
//
//	void setNume(string nume)
//	{
//		if (nume.length() > 2)
//			this->nume = nume;
//	}
//
//	float getSalariu()
//	{
//		return salariu;
//	}
//
//	void setSalariu(float salariu)
//	{
//		if (salariu > 0)
//			this->salariu = salariu;
//	}
//
//	int getZileLucrate()
//	{
//		return zileLucrate;
//	}
//
//	void setZileLucrate(int zileLucrate, int* oreLucratePeZi)
//	{
//		if (zileLucrate >= 0) {
//			this->zileLucrate = zileLucrate;
//			if (this->oreLucratePeZi != NULL)
//				delete[] this->oreLucratePeZi;
//			this->oreLucratePeZi = new int[zileLucrate];
//			for (int i = 0; i < zileLucrate; i++)
//				this->oreLucratePeZi[i] = oreLucratePeZi[i];
//		}
//	}
//	int* getOreLucratePeZi()
//	{
//		return this->oreLucratePeZi;
//	}
//
//	~Angajat()
//	{
//		if (this->oreLucratePeZi != NULL)
//		{
//			delete[]this->oreLucratePeZi;
//		}
//	}
//
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
//	}
//	 Angajat(const Angajat &angajat):  marca(contor)
//	 {
//		 contor=contor+1;
//		 
//		 this->nume = angajat.nume;
//		 this->salariu = angajat.salariu;
//		 this->zileLucrate = angajat.zileLucrate;
//		 this->oreLucratePeZi = new int[this->zileLucrate];
//		 for (int i = 0; i < zileLucrate; i++)
//		 {
//			 this->oreLucratePeZi[i]=angajat.oreLucratePeZi[i];
//
//		 }
//	}
//
//	 Angajat& operator=(const Angajat& angajat) {
//		 if (this != &angajat) { //verificare de autoasignare
//			 this->nume = angajat.nume;
//			 this->salariu = angajat.salariu;
//			 this->zileLucrate = angajat.zileLucrate;
//			 if (this->oreLucratePeZi != NULL)
//				 delete[]this->oreLucratePeZi;
//			 this->oreLucratePeZi = new int[this->zileLucrate];
//			 for (int i = 0; i < this->zileLucrate; i++)
//				 this->oreLucratePeZi[i] = angajat.oreLucratePeZi[i];
//		 }
//		 return *this;
//	 }
//
//	 friend ostream& operator<<(ostream& consola, const Angajat& a) {
//		 consola << "Marca: " << a.marca << endl;
//		 consola << "Nume: " << a.nume << endl;
//		 consola << "Salariu: " << a.salariu << endl;
//		 consola << "Zile lucrate: " << a.zileLucrate << endl;
//		 consola << "Ore lucrate pe zi: ";
//		 for (int i = 0; i < a.zileLucrate; i++) {
//			 consola << a.oreLucratePeZi[i] << ",";
//		 }
//		 consola << endl;
//		 consola << "Norma pe saptamana: " << a.normaPeSaptamana << endl;
//
//		 return consola;
//	 }
//
//	 friend istream& operator>>(istream& input, Angajat& angajat)
//	 {
//		 cout << "introduceti numele:";
//		 input >> angajat.nume;
//		 cout << "salariu:";
//		 input >> angajat.salariu;
//		 cout << "zile lucrate:";
//		 input >> angajat.zileLucrate;
//		 if (angajat.oreLucratePeZi)
//			 delete[] angajat.oreLucratePeZi;
//		 //alocam spatiu pt oreLucratePeZi;
//		 angajat.oreLucratePeZi = new int[angajat.zileLucrate];
//		 cout << "cate ore a lucrat pe zi:";
//		 for (int i = 0; i < angajat.zileLucrate; i++)
//		 {
//			 input >> angajat.oreLucratePeZi[i];
//		 }
//		 return input;
//	 }
//
//	 bool operator<(const Angajat& a) {
//		 if (this->salariu < a.salariu)
//			 return true;
//		 else
//			 return false;
//	 }
//	 bool operator==(const Angajat& a) {
//		 return this->salariu == a.salariu && this->zileLucrate == a.zileLucrate;
//	 }
//
//	 Angajat operator+(const Angajat& a) {
//		 Angajat aux=*this;
//		 aux.salariu = this->salariu + a.salariu;
//		 return aux;
//	 }
//	 Angajat operator+=(int j)
//	 {
//		 int* aux = new int[zileLucrate + 1];
//		 for (int i = 0; i < zileLucrate; i++)
//			 aux[i] = oreLucratePeZi[i];
//		 aux[zileLucrate] = j;
//		 zileLucrate++;
//		 delete[] oreLucratePeZi;
//		 oreLucratePeZi = aux;
//		 return *this;
//
//	 }
//
//	 int operator[]( unsigned int i)
//	 {
//		 if(i<zileLucrate)
//		 return oreLucratePeZi[i];
//	 }
//
//	 Angajat operator++()
//	 {
//		salariu = salariu + 100;
//		return *this;
//	 }
//
//	 Angajat operator++(int i)
//	 {
//		 Angajat a;
//		 a = *this;
//		 salariu=salariu+100;
//		 return a;
//	 }
//};
//
//int Angajat::contor = 100;
//int Angajat::normaPeSaptamana = 40;
//
//
//void main() {
//	//Angajat angajat1 = Angajat();
//	//angajat1.afisareAngajat();
//
//
//	//Angajat angajat2;
//	//angajat2.afisareAngajat();
//
//	//
//
//	//int* vector;
//	//int nrZile = 30;
//	//vector = new int[nrZile];
//	//for (int i = 0; i < nrZile; i++)
//	//{
//	//	vector[i] = i + 2;
//	//}
//	//Angajat angajat3("Ionescu", 4000, nrZile, vector);
//	//angajat3.afisareAngajat();
//
//	////Angajat angajat4("Vasilescu", 3000, 4, new int[4] {8, 7, 9, 6});
//	////angajat4.afisareAngajat();
//
//	//Angajat angajat5("Georgescu", 3500);
//	//angajat5.afisareAngajat();
//	//angajat5.setNume("Ion");
//	//cout << angajat5.getNume() << endl;
//	//if (angajat5.getNume().length() > 1)
//	//{
//	//	Angajat angajat6;
//	//}
//
//	//Angajat angajat6("Popescu", 5000);
//	//angajat6.setSalariu(6000);
//	//cout << angajat6.getSalariu() << endl;
//
//	//int* vector1;
//	//vector1 = new int[7] {4, 6, 2, 8, 9, 4, 5};
//	//angajat6.setZileLucrate(7, vector1);
//	//cout << angajat6.getZileLucrate() << endl;
//	//int* v = angajat6.getOreLucratePeZi();
//	//for (int i = 0; i < angajat6.getZileLucrate(); i++)
//	//{
//	//	cout << v[i] << ' ';
//	//}
//
//	//Angajat a7 = angajat2;
//	//
//	//a7 = angajat2;
//	//a7.afisareAngajat();
//	//a7 = angajat2 = angajat6;
//	//cout << "Look here" << endl;
//	//a7 = a7;
//	//a7.afisareAngajat();
//
//
//
//
//	//delete[]vector;
//	//delete[]vector1;
//	Angajat a1("Georgescu", 3500);
//	int* vector = new int[4] {8, 7, 9, 6};
//	Angajat a2("Vasilescu", 3000, 4, vector);
//
//	/*Angajat a3 = a1 + a2;
//	cout << "SALARIUL ESTE:" << a3.getSalariu();
//	int a = 6;
//	int b = 8;
//	int c = a + b;*/
//
//	a2.afisareAngajat();
//	cout << a2;
//	//cin >> a2;
//	cout << a2;
//
//	if (a1 < a2) {
//		cout << a1.getNume() << " are salariul mai mic." << endl;
//	}
//	else {
//		cout << a2.getNume() << " are salariul mai mic." << endl;
//	}
//	if (a1 == a2)
//		cout << a1.getNume() << " este identic cu " << a2.getNume();
//	else {
//		cout << a1.getNume() << " este diferit de " << a2.getNume();
//	}
//	cout << endl;
//
//	cout << a2.getNume() << " a lucrat " << a2[1] << " ore in a doua zi de munca." << endl;
//
//
//	cout << a2;
//	//ADAUGAREA UNEI NOI ZILE CU UN NUMAR DE ORE DAT
//	a2 += 8;
//	cout << a2;
//
//	a2++;
//
//	cout << a2;
//
//	delete[]vector;
//}