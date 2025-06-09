#pragma once
#include <string>
#include "Country.h"
using namespace std;

class Coin { 
    public: 
        Coin(); 
        Coin(Country&, int  ,  int, string, int  ,  int  );    
        Country& getCountry(); 
        int getCatalogueNumber(); 
        int getYearIssued(); 
        string getMotive(); 
        int getFaceValue(); 
        int getValue(); 
        void changeValue(int);   //Kan ændre møntens værdi (attributten value) 
        
        ~Coin(); 
    
    private: 
        Country country; //Det land, som har udstedt mønten  
        int catalogueNumber; //Katalognummer til identifikation af mønten 
        int yearIssued; //Det år, mønten blev udstedt 
        string motive; //Møntens motiv  
        int faceValue; //Den værdi, der står på mønten i landets valuta 
        int value; //Katalogværdi, dvs. den værdi mønten kan handles i 
};