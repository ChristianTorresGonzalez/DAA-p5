#pragma once

#include <iostream>
#include <vector>

#include "../include/monomio.h"

using namespace std;

class Polinomio_
{
    private:
        int grado;
        vector<Monomio_> polinomio;

    public:
        Polinomio_(void);
        Polinomio_(int );

        int get_grado(void) const;

        Polinomio_ algoritmo_clasico(Polinomio_ & );

        Monomio_ get_monomio(int );

        Polinomio_ operator +(Polinomio_ & );
        Polinomio_ operator *(Polinomio_ & );
        Polinomio_ operator =(Polinomio_ & );
        
        friend ostream& operator <<(ostream &out, Polinomio_ &);
};

