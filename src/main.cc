#include <iostream>

#include "../include/monomio.h"
#include "../include/polinomio.h"

using namespace std;

int main(void)
{
    srand(time(NULL));

    // Monomio_ monomio1(5, 2);
    // cout << monomio1;
    // cout << monomio1.evaluar(3);
    // Monomio_ monomio2(10, 2);
    // cout << monomio2;
    // cout << monomio2.evaluar(3);
    // Monomio_ monomio3 = monomio1 * monomio2;
    // cout << monomio3;

    // Monomio_ suma;
    // suma = monomio1 + monomio2;
    // cout << suma.get_coeficiente() << "x^" << suma.get_exponente();
    // suma << (cout);

    Polinomio_ polinomio1(4);
    Polinomio_ polinomio2(4);
    
    cout << polinomio1;
    cout << polinomio2;
    
    polinomio1 * polinomio2;
}