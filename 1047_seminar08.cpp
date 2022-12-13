//#include<iostream>
//#include<string>
//#include<fstream>
//using std::string;
//using  std::cout;
//using  std::cin;
//using  std::endl;
//using std::ostream;
//using std::istream;
//using std::ofstream;
//using std::ifstream;
//using std::ios;
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
//	 static void adaugaAngajatVector(Angajat* &vAngajati, const Angajat& angajatNou,int& n) {
//		 Angajat* vAux = new Angajat[n+1];
//		 for (int i = 0; i < n; i++)
//		 {
//			 vAux[i] = vAngajati[i];
//		 }
//		 vAux[n] = angajatNou;
//		 delete[]vAngajati;
//		 vAngajati = vAux;
//		 n = n + 1;
//
//	 }
//
//	 static void adaugaAngajatPointer(Angajat**& vAngajati,const Angajat& angajatNou, int& m) {
//		 Angajat** aux = new Angajat* [m+1];
//		 for (int i = 0; i < m; i++)
//		 {
//			 aux[i] = vAngajati[i]; //shallow copy
//
//		 }
//		 aux[m] = new Angajat(angajatNou);
//		 m++;
//		 
//		 delete[]vAngajati;
//		 vAngajati = aux;
//	 }
//
//};
//
//int Angajat::contor = 100;
//int Angajat::normaPeSaptamana = 40;
//
//
//void main() {
//	//*un vector de obiecte
//	//*un vector de pointeri
//	//*adaugare de obiect in vector
//	//*adaugare de pointer in vector
//	//fisiere
//
//	/*int n;
//	cout << "Introduceti numarul de angajati: ";
//	cin >> n;
//	Angajat* vAngajati = new Angajat[n];
//	for (int i = 0; i < n; i++)
//	{
//		cin >> vAngajati[i];
//	}
//
//
//	Angajat a1("Vlad", 3000);
//
//	Angajat::adaugaAngajatVector(vAngajati, a1, n);
//	for (int i = 0; i < n; i++)
//	{
//		cout << vAngajati[i];
//	}
//
//	delete[]vAngajati;*/
//
//	/*int m;
//	cout << "Introduceti numarul de angajati: ";
//	cin >> m;
//	Angajat** vPointeri = new Angajat* [m];
//
//	for (int i = 0; i < m; i++)
//	{
//		vPointeri[i] = new Angajat();
//		cin >> *(vPointeri[i]);
//	}
//	
//	
//
//	Angajat a1("Vlad", 3000);
//	Angajat::adaugaAngajatPointer(vPointeri, a1, m);
//	
//	for (int i = 0; i < m; i++)
//	{
//		cout << *(vPointeri[i]);
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		delete vPointeri[i];
//	}
//	delete[]vPointeri;*/
//
//	ofstream file("fisier.txt", ios::app);
//	
//	Angajat a2("Ionut", 6666);
//	file << a2;
//
//	file.close();
//	
//}