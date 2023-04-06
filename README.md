Numele proiectului: RED ZOO P.O.O.

Tema aleasă: Gradina Zoo

 O listă cu clasele pe care le-ați implementat și o scurtă descriere a ce reprezintă fiecare
  in structuri.hpp:
  -Vector: template vector pe care il folosesc sa retin animalele si ingrijitorii in zoo
  -MyString: sir care stocheaza denumirile gradinii zoo, animalelor, ingrijitorilor etc
    
  in clase.hpp:
    -Zoo: gradina zoo care retine intr-un vector animalele, si in altul ingrijitorii. Mai contorizeaza vizitatorii si banii facuti din bilete.
    -Animale: animalele din gradina
    -Ingrijitor: persoanele de care e nevoie pentru hranirea animalelor din Zoo
    -Bilete: permit accesul vizitatorilor in schimbul unui pret
 
O listă cu funcționalitățile
  *in proiect.cpp este main-ul unde dau exemplu de functionalitati.
    -Zoo z("Bio Parco di Roma"); apeleeaza constructorul pentru zoo, ca paramentru are doar denumirea | toate se initializeaza cu 30kg de mancare si nici un animal.
    -z.add_animal(Animal(3, "capibara", "Gogu")); metoda din clasa Zoo cu constructorul de animal ca parametru | primeste varsta, specia si numele animalului pe care il baga in vectorul de animale gradinii respective.
    -z.angajare(Ingrijitor(32, "Ciobotaru", "Mitica")); metoda din clasa Zoo cu constructorul de animal ca parametru | primeste varsta, numele si prenumele angajatului pe care il baga in vectorul de ingrijitori gradinii respective.
    -z.buy_bilet("adult", 2); metoda din clasa Zoo cu constructorul de bilet si numarul de bilete cumparate ca parametrii | se inmulteste cantitatea cu pretul biletului si se adauga la profitul din clasa Zoo
    - z.buy_mancare(30); metoda din clasa Zoo care are ca parametru valoarea data pentru a genera mancare | functioneaza doar daca gradina zoo are destui bani ca sa achizitioneze mancarea, altfel afiseaza ca nu sunt bani | cu 1 (Ron) se cumpara jumatate de kg de mancare (se face inmultirea cu 0.5 si se adauga la mancarea gradinii)
    -std::cout << z; operator supraincarcat care arata toate detaliile gradini zoo
