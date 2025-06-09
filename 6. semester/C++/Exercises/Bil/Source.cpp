#include "Dato.h"
#include "Person.h"
#include "PersonKartotek.h"
#include "Stak.h"
#include <iostream>
#include <iomanip> // For at manipulere outputformat

using namespace std;

int main() {
    // Dato-eksempel
    cout << "--- Dato Information ---" << endl;
    Dato dd(20250220);
    cout << "Dags dato: " << dd.getDatoen() << endl;
    cout << "År: " << dd.getAar() << endl;
    cout << "Kvartal: " << dd.getKvartal() << endl;
    cout << "Måned: " << dd.getMaaned() << endl;
    cout << "Dag: " << dd.getDag() << endl;
    cout << endl;

    // Person-eksempler
    cout << "--- Person Information ---" << endl;
    Person peter("Peter Hansen", "phdk@gmail.com", Dato(19521017));
    Person simone("Simone Lebech", "sileb@student.sdu.dk", Dato(19980904));

    cout << peter.getNavn() << " er født i: " << peter.getFDato().getAar() << endl;
    cout << simone.getNavn() << " er født i: " << simone.getFDato().getAar() << endl;
    cout << endl;

    // Bil-eksempel
    cout << "--- Bil Information ---" << endl;
    Bil b1("AB12345", 2010);
    peter.addBil(b1);
    cout << "Peters bil er fra år: " << peter.getBil().getAargang() << endl;
    cout << endl;

    // PersonKartotek-eksempel
    cout << "--- PersonKartotek Information ---" << endl;
    Person ole("Ole Olsen", "olsen@gmail.com", Dato(19530714));
    Person marianne("Marianne Madsen", "marma@gmail.com", Dato(20220902));

    PersonKartotek pK("Mit Kartotek");
    pK.addPerson(peter);
    pK.addPerson(simone);
    pK.addPerson(ole);
    pK.addPerson(marianne);

    cout << "Personer i kartoteket:" << endl;
    for (int i = 0; i < pK.getAntalPersoner(); i++) {
        cout << "- " << left << setw(20) << pK.getElement(i).getNavn() << " født i: " << pK.getElement(i).getFDato().getAar() << endl;
    }
    cout << endl;

    // Stak-eksempel
    cout << "--- Stak Operationer ---" << endl;
    Stak stak("Min stak");
    stak.push(peter);
    stak.push(simone);
    stak.push(ole);
    stak.push(marianne);

    cout << "Fjernede personer fra stakken:" << endl;
    for (int i = 0; i < 4; i++) {
        Person person = stak.pop();
        cout << "- " << person.getNavn() << endl;
    }

    return 0;
}