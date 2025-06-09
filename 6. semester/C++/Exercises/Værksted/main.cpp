#include "Vaerksted.h"
#include "Bil.h"
#include "Mekaniker.h"
#include "Arbejdsseddel.h"

int main() {
    Vaerksted vS("Nymarken 104, 5330 Munkebo", "Lars Peter Hansen");
    Bil b1("MA39604", "Knud Pedersen");
    Bil b2("MH40136", "Lis Fugl");
    Bil b3("MA45647", "Herluf Jensen");
    vS.addBil(b1);
    vS.addBil(b2);
    vS.addBil(b3);

    Mekaniker m1("Poul");
    Mekaniker m2("Per");
    vS.addMekaniker(m1);
    vS.addMekaniker(m2);

    Arbejdsseddel a1(b1, m2, 7, 20200503);
    Arbejdsseddel a2(b3, m1, 4, 20200512);
    Arbejdsseddel a3(b3, m2, 3, 20200514);
    Arbejdsseddel a4(b1, m1, 5, 20200516);
    Arbejdsseddel a5(b3, m2, 2, 20200518);
    vS.addArbejdsseddel(a1);
    vS.addArbejdsseddel(a2);
    vS.addArbejdsseddel(a3);
    vS.addArbejdsseddel(a4);
    vS.addArbejdsseddel(a5);

    cout << "Bilejere uden regning:" << endl;
    vS.ingenRegning();

    cout << endl;
    vS.mekanikerTimer();

    cout << endl << "Seneste arbejdsdato: " << vS.senesteArbejde() << endl;

    return 0;
}