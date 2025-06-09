#include "Husdyr.h"
#include "Hund.h"
#include "Kanin.h"
#include "Kat.h"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<Husdyr*> tabel;
	
    // Kaniner
	Kanin ka1("Peter Jensen", "66142909", "Hvid", 3);
    Kanin ka2("Peter Jensen", "66142909", "Broget", 2);

    // Katte
    Kat k1("Poul Svendsen", "66149131", "han", true);
	Kat k2("Preben Soerensen", "66182106", "hun", false);
    Kat k3("Poul Nielsen", "66149157", "han", true);
	Kat k4("Preben Holst", "66182206", "hun", false);

    // Hunde
	Hund h1("Peter Jensen", "66142909", "Boxer", 12);
	Hund h2("Peter Olsen", "66142910", "Terrier", 10);
	
    // Tabel
	tabel.push_back(&ka1);
	tabel.push_back(&ka2);
	tabel.push_back(&h1);
	tabel.push_back(&h2);
	tabel.push_back(&k1);
	tabel.push_back(&k2); 
	tabel.push_back(&k3);
	tabel.push_back(&k4);
    
	for (int i = 0; i < tabel.size(); i++)
		cout << tabel[i]->givLyd() << endl;
	 
	return 0;
}


