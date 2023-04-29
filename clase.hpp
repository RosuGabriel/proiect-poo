#ifndef clase_hpp
#define clase_hpp

#include "structuri.hpp"
#include <exception>
#include <vector>
#include <string>

using namespace std;


//---------------------------------------------------------------


class MyException : public std::exception {
private:
    string message;
public:
    MyException(const string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};


//---------------------------------------------------------------


class Bilet {
    int pret;
    string persoana;// copil student adult etc
public:
    Bilet(const char* p = "invalid") {
        pret = 0;
        try {
            if (p == "invalid")
                throw MyException("Bilet invalid!");
            persoana = p;
            pret = 0;
            if (p == "adult") {
                pret = 30;
            }
            else
                if (p == "copil" || p == "pensionar" || p == "student" || p == "elev") {
                    pret = 17;
                }
        }
        catch(const MyException& e){
            cerr << "Eroare: " << e.what() << " - Nu este specificat tipul de bilet! - A fost selectat default bilet adult.\n";
            pret = 30;
            persoana = "adult";
        }
    }

    string cine() {
        return persoana;
    }

    int cost() {
        return pret;
    };
};


//---------------------------------------------------------------


class Animal {
protected:
    int varsta;
    MyString nume;
    MyString specie;

public:
    Animal(int v = 0, const char* spc = "none", const char* num = "no name") {
        varsta = v;
        specie = spc;
        nume = num;
    }

    friend ostream& operator << (ostream& out, const Animal& a);

    MyString who() {
        return nume;
    };

};

ostream& operator << (ostream& out, const Animal& a) {
    out << "Specie: " << a.specie << "    nume: " << a.nume << "    age: " << a.varsta << "\n";
    return out;
}


//---------------------------------------------------------------


class AnimalCarnivor : public Animal {
public:
    AnimalCarnivor(int v = 0, const char* spc = "none", const char* num = "no name") : Animal(v, spc, num) {};
};


//---------------------------------------------------------------


class AnimalErbivor : public Animal {
public:
    AnimalErbivor(int v = 0, const char* spc = "none", const char* num = "no name") : Animal(v, spc, num) {};
    
};


//---------------------------------------------------------------


class Angajat {
protected:
    int varsta;
    string nume;
    string prenume;
public:
    Angajat(int v = 18, const char* num = "no name", const char* pre = "no name") {
        if (v < 18)
            throw logic_error("Angajatul trebuie sa fie major");
        varsta = v;
        prenume = pre;
        nume = num;
    };

    virtual void prezentare() = 0;

    virtual ~Angajat() { cout << nume << " destructor angajat\n"; }
};


//---------------------------------------------------------------


class Ingrijitor : public Angajat
{

public:

    Ingrijitor(int v = 18, const char* num = "no name", const char* pre = "no name") : Angajat(v, num, pre) {};

    void prezentare() override {
        cout << "Ingrijitorul " << nume << " " << prenume << " are " << varsta << " ani\n";
    }

    ~Ingrijitor()  { cout << nume << " Ingrijitorul si-a incheiat tura\n"; }
};


//---------------------------------------------------------------


class Casier : public Angajat
{
public:
    Casier(int v = 18, const char* num = "no name", const char* pre = "no name") : Angajat(v, num, pre) {};

    void prezentare() override {
        cout << "Casierul " << nume << " " << prenume << " are " << varsta << " ani\n";
    };

    ~Casier()  { cout << nume << " Casierul si-a incheiat tura\n"; }
};


//---------------------------------------------------------------


class FoodMarket
{
public:
    virtual void buy_mancare(double p) = 0;
};


//---------------------------------------------------------------


class HR
{
public:
    virtual void angajare(Ingrijitor &x) = 0;
    virtual void angajare(Casier &x) = 0;
};


//---------------------------------------------------------------


class Zoo : public FoodMarket, public HR {
    static int NrZoo;
    static int BileteVandute;
    int nr_animale, nr_vizitatori, nr_ingrijitori, nr_casieri;
    double profit_bilete, hrana;
    MyString nume;
    Vector<Animal> a;
    vector<Angajat*> angajati;
public:

    Zoo(const char* num = "no name") {
        NrZoo++;
        hrana = 30; //kg
        nr_animale = 0;
        nr_vizitatori = 0;
        profit_bilete = 0;
        nr_ingrijitori = 0;
        nr_casieri = 0;
        nume = num;
        cout << '\n' << nume << " s-a deschis\n\n";
    };

    static int getNrZoo()
    {
        return NrZoo;
    }

    static int getNrBilete()
    {
        return BileteVandute;
    }

    friend ostream& operator << (ostream& out, const Zoo& z);
    friend istream& operator >> (istream& in, Zoo& z);

    void add_animal(Animal x) {
        a.push(x);
        cout << x.who() << " a venit la " << nume << '\n';
        nr_animale++;
    };

    ~Zoo() {
        cout << '\n' << nume << " s-a inchis\n";
    }

    void feed_animals() {
        try
        {
            if (hrana < a.ASKsize() * 10)
                throw MyException("Nu este suficienta hrana pentru animalele din gradina zoologica!");
            if (nr_ingrijitori == 0)
                throw MyException("Nu exista niciun ingrijitor in gradina zoo!");
            cout << nume << " - Animalele au fost hranite!\n";
        }
        catch (const MyException& e)
        {
            std::cerr << "Eroare: " << nume << " - " << e.what() << '\n';
            try {
                if (e.what()[4]=='s' && (nr_ingrijitori == 0))
                    throw MyException("Nu exista niciun ingrijitor in gradina zoo!");
                if (e.what()[4]=='x' && hrana < a.ASKsize() * 10)
                    throw MyException("Nu este suficienta hrana pentru animalele din gradina zoologica!");
            }
            catch (const MyException& x) {
                std::cerr << "Inca o Eroare: " << nume << " - " << x.what() << '\n';
            }
        }
    }

    void buy_mancare(double p) {
        try
        {
            if (p > profit_bilete)
                throw MyException("Nu sunt fonduri pentru mancare!");
            profit_bilete -= p;
            hrana += p / 2;
            cout << '\n' << nume << " a cumparat " << p / 2 << "kg de mancare\n";
        }
        catch (const MyException& e)
        {
            std::cerr << "Eroare: " << nume << " - " << e.what() << '\n';
        }

    }

    void buy_bilet(Bilet y, int n) {
        if (n == 0)
            throw MyException("Trebuie cumparat minim un bilet");
       
        if (y.cine()[0] != 'i') {
            BileteVandute += n;
            nr_vizitatori = nr_vizitatori + n;
            profit_bilete = profit_bilete + n * y.cost();
        }
    }

    void angajare(Ingrijitor &j) override {
        angajati.push_back(&j);
        nr_ingrijitori++;
    }

    void angajare(Casier &j) override {
        angajati.push_back(&j);
        nr_casieri++;
    }
    
    void PrezentareAngajati() { 
        cout << '\n' << nume << " are urmatorii angajati:\n";
        for (int i = 0; i < angajati.size(); i++) {
            angajati[i]->prezentare();
        };
    }

    void PrimulCasier() {
        for (int i = 0; i < angajati.size(); i++) {
            Casier* c = dynamic_cast<Casier*>(angajati[i]);
            if (c != nullptr) {
                std::cout << "Downcasting successful!" << '\n' << "Primul casier angajat la " << nume << " este: ";
                c->prezentare();
                break;
            }
            else {
                std::cout << "Downcasting failed!" << '\n';
            }
        };
    }

    void PrimulIngrijitor() {
        for (int i = 0; i < angajati.size(); i++) {
            Ingrijitor* c = dynamic_cast<Ingrijitor*>(angajati[i]);
            if (c != nullptr) {
                std::cout << "Downcasting successful!" << '\n' << "Primul ingrijitor angajat la " << nume << " este: ";
                c->prezentare();
                break;
            }
            else {
                std::cout << "Downcasting failed!" << '\n';
            }
        };
    }
};

int Zoo::NrZoo = 0;
int Zoo::BileteVandute = 0;

ostream& operator << (ostream& out, const Zoo& z) {
    out << "Nume Zoo: " << z.nume << '\n';
    out << "Ingrijitori: " << z.nr_ingrijitori << '\n';
    out << "Casieri: " << z.nr_casieri << '\n';
    out << "Nr. vizitatori: " << z.nr_vizitatori << '\n';
    out << "Cantitate mancare: " << z.hrana << " kg\n";
    out << "Bani din bilete : " << z.profit_bilete << " lei\n";
    out << "Nr.animale: " << z.nr_animale << '\n';
    out << "Animale:\n" << z.a;
    return out;
};

istream& operator >> (istream& in, Zoo& z) {
    cout << "Adaugare bani la " << z.nume << ": ";
    int x;
    cin >> x;
    z.profit_bilete = z.profit_bilete + x;
    cout << "Adaugare mancare la " << z.nume << ": ";
    cin >> x;
    z.hrana = z.hrana + x;
    return in;
};


#endif