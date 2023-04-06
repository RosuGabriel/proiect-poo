#include <iostream>
#include "structuri.hpp"
#include "clase.hpp"


int main()
{
    Zoo z("Bio Parco di Roma");

    z.add_animal(Animal(2, "panda", "Po"));
    z.add_animal(Animal(3, "capibara", "Gogu"));
    z.add_animal(Animal(90, "testoasa", "Mara"));
    z.add_animal(Animal(15, "crocodil", "Croc"));
    std::cin >> z; // adauga bani si mancare gradinii
  
    z.angajare(Ingrijitor(32, "Ciobotaru", "Mitica"));

    z.buy_bilet("adult", 2);
    z.buy_bilet("student", 1);

    z.buy_mancare(30);

    z.feed_animals();

    Zoo x("Vienna ZOO");
    x.add_animal(Animal(5, "strut", "Bubi"));
    x.angajare(Ingrijitor(54, "Ion", "Ionut"));
    x.feed_animals();

    std::cout << '\n' << z << x;

    return 0;
}

