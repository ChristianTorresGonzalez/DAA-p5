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
        Polinomio_(int , int );

        void set_grado(int );
        void set_polinomio(vector<Monomio_> );
        
        int get_grado(void) const;
        vector<Monomio_> get_polinomio(void) const;
        Monomio_ get_monomio(int );

        void copiar_polinomio(Polinomio_ &);

        Polinomio_ algoritmo_clasico(Polinomio_ &);
        Polinomio_ algoritmo_DyV(Polinomio_ & );

        Polinomio_ operator +(Polinomio_ & );
        Polinomio_ operator *(Polinomio_ & );
        
        friend ostream& operator <<(ostream &out, Polinomio_ &);
};

