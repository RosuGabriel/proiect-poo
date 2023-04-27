#include <iostream>
#include "structuri.hpp"
#include "clase.hpp"


//class MyException : public std::exception
//{
//
//};

int main()
{
    
    //dynamic_cast<>


    Zoo z("Bio Parco di Roma");

    z.add_animal(AnimalErbivor(2, "panda", "Po"));
    //z.add_animal(AnimalErbivor(3, "capibara", "Gogu"));
    //z.add_animal(AnimalErbivor(90, "testoasa", "Mara"));
    z.add_animal(AnimalCarnivor(15, "crocodil", "Croc"));
    
  
    z.angajare(Ingrijitor(32, "Ciobotaru", "Mitica"));

    z.buy_bilet(Bilet("adult"), 2);
    //z.buy_bilet("student", 1);

    //z.buy_mancare(30);

    z.feed_animals();
    z.angajare(Casier(22, "Ciocan", "Marius"));

    Zoo x("Vienna ZOO");
    x.add_animal(AnimalErbivor(5, "strut", "Bubi"));
    x.angajare(Ingrijitor(54, "Ion", "Ionut"));
    x.feed_animals();

    std::cout << '\n' << z << x;

    return 0;
}

