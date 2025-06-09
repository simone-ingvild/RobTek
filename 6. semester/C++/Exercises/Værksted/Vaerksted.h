#pragma once
#ifndef VAERKSTED_H
#define VAERKSTED_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <sstream>

#include "Bil.h"
#include "Mekaniker.h"
#include "Arbejdsseddel.h"

using namespace std;

class Vaerksted{ 
    public: 
        Vaerksted();
        Vaerksted(string adresse, string ejer);  
        string getAdresse(); 
        string getEjer(); 
        void addBil(Bil &enB); 
        void addMekaniker(Mekaniker enM  );  
        void addArbejdsseddel(Arbejdsseddel & enA  );
        void ingenRegning();
        void mekanikerTimer();
        string senesteArbejde();  
        ~Vaerksted();
    
    private: 
        string adressen;
        string ejeren;
        vector<Bil> biler;
        vector<Mekaniker> mekanikere;
        vector<Arbejdsseddel> arbejdssedler; 
};
#endif