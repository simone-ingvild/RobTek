#include "Vaerksted.h"

Vaerksted::Vaerksted() {}

Vaerksted::Vaerksted(std::string adresse, std::string ejer) : adressen(adresse), ejeren(ejer) {}

std::string Vaerksted::getAdresse() {
    return adressen;
}

std::string Vaerksted::getEjer() {
    return ejeren;
}

void Vaerksted::addBil(Bil& enB) {
    biler.push_back(enB);
}

void Vaerksted::addMekaniker(Mekaniker enM) {
    mekanikere.push_back(enM);
}

void Vaerksted::addArbejdsseddel(Arbejdsseddel& enA) {
    arbejdssedler.push_back(enA);
}

void Vaerksted::ingenRegning(){
    map<string, bool> ejereMedRegning;

    for(Arbejdsseddel& seddel : arbejdssedler){
        ejereMedRegning[seddel.getBil().getEjer()] = true;
    }
    for(Bil& bil : biler){
        if(ejereMedRegning.find(bil.getEjer()) == ejereMedRegning.end()){
            cout << bil.getEjer() << endl;
        }
    }
}

void Vaerksted::mekanikerTimer(){
    map<string, int> mekanikerTimerMap;

    for(Arbejdsseddel& seddel : arbejdssedler){
        mekanikerTimerMap[seddel.getMekaniker().getNavn()] += seddel.getTimer();
    }

    cout << "Mekanikere og deres arbejdstimer:" << endl;
    for(auto const& [navn, timer] : mekanikerTimerMap){
        cout << navn << ": " << timer << " timer" << endl;
    }
}

string Vaerksted::senesteArbejde(){
    int senesteDato = 0;
    for(Arbejdsseddel& seddel : arbejdssedler){
        if(seddel.getDato() > senesteDato){
            senesteDato = seddel.getDato();
        }
    }

    stringstream ss;
    ss << setw(2) << setfill('0') << senesteDato % 100 << "/"
       << setw(2) << setfill('0') << (senesteDato / 100) % 100 << "/"
       << senesteDato / 10000;
    return ss.str();
}

Vaerksted::~Vaerksted(){}