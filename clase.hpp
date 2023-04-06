#ifndef clase_hpp
#define clase_hpp

#include "structuri.hpp"
using namespace std;


//---------------------------------------------------------------


class Bilet {
    int pret;
    MyString persoana;// copil student adult etc
public:
    Bilet(const char* p = "invalid") {
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

    int cost() {
        return pret;
    };
};


//---------------------------------------------------------------


class Animal {
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

    MyString who() { //getter nume
        return nume;
    };


};

ostream& operator << (ostream& out, const Animal& a) {
    out << "Specie: " << a.specie << "    nume: " << a.nume << "    age: " << a.varsta << "\n";
    return out;
}


//---------------------------------------------------------------


class Ingrijitor {
    int varsta;
    MyString nume;
    MyString prenume;

public:

    Ingrijitor(int v = 18, const char* num = "no name", const char* pre = "no name") {
        varsta = v;
        prenume = pre;
        nume = num;
    };

    void prezentare() {
        cout << varsta << nume << prenume;
    };
};


//---------------------------------------------------------------


class Zoo {
    int nr_animale, nr_vizitatori, nr_ingrijitori;
    double profit_bilete, hrana;
    MyString nume;
    Vector<Animal> a;
    Vector<Ingrijitor> i;
public:

    Zoo(const char* num = "no name") {
        hrana = 30; //kg
        nr_animale = 0;
        nr_vizitatori = 0;
        profit_bilete = 0;
        nr_ingrijitori = 0;
        nume = num;
        cout << '\n' << nume << " s-a deschis\n\n";
    };

    friend ostream& operator << (ostream& out, const Zoo& z);

    void add_animal(Animal x) {
        a.push(x);
        cout << x.who() << " a venit la " << nume << '\n';
        nr_animale++;
    };

    ~Zoo() {
        cout << '\n' << nume << " s-a inchis\n";
    }

    void feed_animals() {
        if (hrana >= a.ASKsize() * 10 && nr_ingrijitori > 0) {
            cout << "la " << nume << ":\n";
            for (int i = 0; i < a.ASKsize(); i++) {
                cout << a.get(i).who() << " a fost hranit\n";
                hrana = hrana - 10;
            }
        }
        else {
            if (nr_ingrijitori > 0)
                cout << "Nu exista destula mancare pentru animale!\n";
            else
                cout << "Nu exista angajati care sa hraneasca animalele!\n";
        }
    }

    void buy_mancare(double p) {
        if (p > profit_bilete)
            cout << "Nu exista bani pentru hrana!\n";
        else
        {
            profit_bilete = profit_bilete - p;
            hrana = hrana + p * 0.5;
            cout << '\n' << nume << " a cumparat " << p * 0.5 << "kg de mancare\n";
        }

    }

    void buy_bilet(Bilet y, int n) {
        nr_vizitatori = nr_vizitatori + n;
        profit_bilete = profit_bilete + n * y.cost();
    }

    void angajare(Ingrijitor j) {
        i.push(j);
        nr_ingrijitori++;
    }
};

ostream& operator << (ostream& out, const Zoo& z) {
    out << "Nume Zoo: " << z.nume << '\n';
    out << "Ingrijitori: " << z.nr_ingrijitori << '\n';
    out << "Nr. vizitatori: " << z.nr_vizitatori << '\n';
    out << "Bani din bilete : " << z.profit_bilete << '\n';
    out << "Nr.animale: " << z.nr_animale << '\n';
    out << "Animale:\n" << z.a;
    return out;
};

#endif