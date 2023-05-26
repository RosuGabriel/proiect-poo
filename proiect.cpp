#include <iostream>
#include <algorithm>
#include "structuri.hpp"
#include "clase.hpp"

int main()
{
    Zoo z("Bio Parco di Roma");

    z.add_animal(AnimalErbivor(2, "panda", "Po"));
    //z.add_animal(AnimalErbivor(3, "capibara", "Gogu"));
    //z.add_animal(AnimalErbivor(90, "testoasa", "Mara"));
    z.add_animal(AnimalCarnivor(15, "crocodil", "Croc"));
    
   
    
    Ingrijitor c(27, "Bogdan", "Dracea");
    z.angajare(c);
    
    Ingrijitor g(19, "Viorel", "Dragu");
    z.angajare(g);

    //z.buy_bilet(Bilet("adult"), 2);
    z.buy_bilet(Bilet(), 1);

    z.buy_mancare(300);

    z.feed_animals();

    Casier c2(36, "Alexandru", "Toma");
    z.angajare(c2);

    Ingrijitor g2(32, "Maria", "Popovici");
    z.angajare(g2);

    Zoo x("Vienna ZOO");
    x.add_animal(AnimalErbivor(5, "strut", "Bubi"));
    x.feed_animals();
    Casier c1(40, "Costel", "Bojog");
    x.angajare(c1);


    Ingrijitor g1(41, "Claudiu", "Teohari");
    x.angajare(g1);

    z.PrezentareAngajati();
    x.PrezentareAngajati();
    

    z.PrimulCasier();

    std::cout << "profitul mai mare:" << myMax(z.bani(), x.bani()) << '\n';

    z.sortAngajatiByVarsta();
   

    return 0;
}

