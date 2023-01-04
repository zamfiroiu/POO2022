//#include<iostream>
//#include<string>
//#include<fstream>
//
//using namespace std;
//
////functii virtual pure
////interfete - clase abstracte
////scriere in fisier
////vector de piointeri - reference type
//
//class Writer {
//public:
//	virtual void scrieInFisierTxt(ofstream& file) = 0;
//
//
//};
//
//
//class Angajat:public Writer
//
//{
//	
//private:
//	string nume;
//	float salariu;
//	int zileLucrate;
//	int* oreLucratePeZi;
//	static int normaPeSaptamana;
//	static int contor;
//	const int marca;
//public:
//
//	void scrieInFisierTxt(ofstream& file) {
//		file <<  endl<< this->marca<<","<<this->nume<<",";
//		file << this->zileLucrate << "," << this->normaPeSaptamana;
//
//	}
//
//
//
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
//	float getSalariu()const
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
//class Manager : public Angajat
//{ //Manager - nrSubalterni, sporConducere, subalterni
//private: 
//	int nrSubalterni;
//	float sporConducere;
//	Angajat**subalterni;
//public:
//	void scrieInFisierTxt(ofstream& file) {
//		Angajat::scrieInFisierTxt(file);
//		file << "," << this->nrSubalterni << "," << this->sporConducere;
//
//	}
//
//	Manager() :Angajat()
//	{
//		this->nrSubalterni=0;
//		this->sporConducere = 0;
//		this->subalterni = NULL;
//
//	}
//	Manager(int nrSubalterni, float sporConducere, Angajat** subalterni, string nume, float salariu, int zileLucrate, const int* oreLucratePeZi):Angajat( nume,  salariu,  zileLucrate,  oreLucratePeZi)
//	{
//		this->nrSubalterni = nrSubalterni;
//		this->sporConducere = sporConducere;
//		this->subalterni = new Angajat * [nrSubalterni];
//		for (int i=0; i < this->nrSubalterni; i++)
//		{   
//			this->subalterni[i] = new Angajat ( *subalterni[i]);
//		
//		}
//	}
//	~Manager() {
//		if (this->subalterni != NULL)
//		{
//			for (int i=0; i< this->nrSubalterni;i ++)
//			{
//				if (this->subalterni[i] != NULL)
//					delete this->subalterni[i];
//			}
//			delete[]this->subalterni;
//		}
//
//
//	}
//	Manager(const Manager& m) :Angajat(m) {
//		this->nrSubalterni = m.nrSubalterni;
//		this->sporConducere = m.sporConducere;
//		this->subalterni = new Angajat * [nrSubalterni];
//		for (int i = 0; i < this->nrSubalterni; i++)
//		{
//			this->subalterni[i] = new Angajat(*(m.subalterni[i]));
//
//		}
//
//	}
//
//	Manager& operator=(const Manager& m) {
//		if (this != &m) {
//			Angajat::operator=(m);
//			this->nrSubalterni = m.nrSubalterni;
//			this->sporConducere = m.sporConducere;
//			if (this->subalterni != NULL)
//			{
//				for (int i = 0; i < this->nrSubalterni; i++)
//				{
//					if (this->subalterni[i] != NULL)
//						delete this->subalterni[i];
//				}
//				delete[]this->subalterni;
//			}
//			this->subalterni = new Angajat * [nrSubalterni];
//			for (int i = 0; i < this->nrSubalterni; i++)
//			{
//				this->subalterni[i] = new Angajat(*(m.subalterni[i]));
//
//			}
//		}
//		return (*this);
//	}
//
//	friend ostream& operator<<(ostream& out, const Manager& m) {
//		out << (Angajat)m;
//		out << "Numar subalterni: " << m.nrSubalterni << endl;
//		out << "Spor conducere: " << m.sporConducere << endl;
//		out << "Venit manager: " << m.getSalariuTotal() << endl;
//		if (m.nrSubalterni > 0) {
//			out << "Subalterni: "<<endl;
//			for (int i = 0; i < m.nrSubalterni; i++)
//			{
//				
//				out << *m.subalterni[i]<<endl ;
//			}
//		}
//
//		out << endl;
//		return out;
//	}
//
//	float getSalariuTotal() const
//	{
//		float salariuTotal;
//		salariuTotal = getSalariu() + (sporConducere / 100 * getSalariu());
//		return salariuTotal;
//	}
//
//
//};
//
//void main() {
//
//	Manager m1;
//	int* x = new int[2] {10, 9};
//	Angajat** vpang = new Angajat * [3];
//	vpang[0] = new Angajat("vlad", 3000);
//	vpang[1] = new Angajat("Ionut", 4000);
//	vpang[2] = new Angajat("Maria", 5000, 2, x);
//	Manager m2(3, 10,vpang,"Ion",6000,2,x);
//	cout << m2;
//	m1 = m2;
//	cout << m1;
//	Manager m3(m2);
//	cout << m3;
//
//	
//
//	Angajat** v = new Angajat*[5];
//	v[0] = &m3;
//	v[1] = vpang[0];
//	v[2] = vpang[1];
//	v[3] = &m2;
//	v[4] = vpang[2];
//
//	ofstream f("fisier.csv", ios::app);
//
//	for (int i = 0; i < 5; i++)
//	{
//		v[i]->scrieInFisierTxt(f);
//	}
//
//	f.close();
//
//	for (int i = 0; i < 3; i++)
//	{
//		delete vpang[i];
//	}
//	delete[]vpang;
//	delete[]x;
//
//	delete[] v;
//}