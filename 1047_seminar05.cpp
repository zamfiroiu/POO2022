#include<iostream>
#include<string>
using std::string;
using  std::cout;
using  std::cin;
using  std::endl;

class Angajat
{
private:
	string nume;
	float salariu;
	int zileLucrate;
	int* oreLucratePeZi;
	static int normaPeSaptamana;
	static int contor;
	const int marca;
public:
	Angajat():marca(contor)
	{
		contor++;
		this->nume = "Popescu";
		this->salariu = 5000;
		this->zileLucrate = 10;
		this->oreLucratePeZi = new int[this->zileLucrate];
		for (int i = 0; i < this->zileLucrate; i++) {
			this->oreLucratePeZi[i] = i + 1;
		}
	}
	Angajat(string nume, float salariu, int zileLucrate, const int* oreLucratePeZi):marca(contor++) {
		this->nume = nume;
		this->salariu = salariu;
		this->zileLucrate = zileLucrate;
		this->oreLucratePeZi = new int[this->zileLucrate];
		for (int i = 0; i < this->zileLucrate; i++)
		{
			this->oreLucratePeZi[i] = oreLucratePeZi[i]; //deep copy 
		}
	}
	Angajat(string nume, float salariu) :marca(contor++)
	{
		this->nume = nume;
		this->salariu = salariu;
		this->zileLucrate = 0;
		this->oreLucratePeZi = NULL;
	}

	string getNume()
	{
		return nume;
	}

	void setNume(string nume)
	{
		if (nume.length() > 2)
			this->nume = nume;
	} 
	 
	float getSalariu()
	{
		return salariu;
	}
	 
	void setSalariu(float salariu)
	{
		if (salariu > 0)
			this->salariu = salariu;
	}

	int getZileLucrate()
	{
		return zileLucrate;
	}

	void setZileLucrate(int zileLucrate, int* oreLucratePeZi)
	{
		if (zileLucrate >= 0) {
			this->zileLucrate = zileLucrate;
			if (this->oreLucratePeZi != NULL)
				delete[] this->oreLucratePeZi;
			this->oreLucratePeZi = new int[zileLucrate];
			for (int i = 0; i < zileLucrate; i++)
				this->oreLucratePeZi[i] = oreLucratePeZi[i];
		}
	}
	int* getOreLucratePeZi()
	{
		return this->oreLucratePeZi;
	}

	~Angajat()
	{
		if (this->oreLucratePeZi != NULL)
		{
			delete[]this->oreLucratePeZi;
		}
	}

	void afisareAngajat()
	{
		cout << "Marca: " << this->marca << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Salariu: " << this->salariu << endl;
		cout << "Zile lucrate: " << this->zileLucrate << endl;
		cout << "Ore lucrate pe zi: ";
		for (int i = 0; i < zileLucrate; i++)
			cout << oreLucratePeZi[i] << ",";
		cout << endl;
		cout << "Norma pe saptamana: " << this->normaPeSaptamana << endl;

	}
	//void setNume (string )
};

int Angajat::contor = 100;
int Angajat::normaPeSaptamana = 40;


void main() {
	Angajat angajat1=Angajat();
	angajat1.afisareAngajat();


	Angajat angajat2;
	angajat2.afisareAngajat();

	int* vector;
	int nrZile=30;
	vector = new int[nrZile];
	for (int i = 0; i < nrZile; i++)
	{
		vector[i] = i + 2;
	}
	Angajat angajat3("Ionescu", 4000, nrZile, vector);
	angajat3.afisareAngajat();

	//Angajat angajat4("Vasilescu", 3000, 4, new int[4] {8, 7, 9, 6});
	//angajat4.afisareAngajat();

	Angajat angajat5("Georgescu",3500);
	angajat5.afisareAngajat();
	angajat5.setNume("Ion");
	cout << angajat5.getNume() << endl;
	if (angajat5.getNume().length() > 1)
	{
		Angajat angajat6;
	} 
	
	Angajat angajat6("Popescu", 5000);
	angajat6.setSalariu(6000);
	cout << angajat6.getSalariu() << endl;

	int* vector1;
	vector1 = new int[7] {4, 6, 2, 8, 9, 4, 5};
	angajat6.setZileLucrate(7,vector1);
	cout << angajat6.getZileLucrate() << endl;
    int* v=angajat6.getOreLucratePeZi() ;
	for(int i=0;i<angajat6.getZileLucrate(); i++)
	{
		cout << v[i] <<' ';
	}




	delete[]vector;
	delete[]vector1;
}