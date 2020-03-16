#pragma once

#include <iostream>
#include <math.h>
#include <cassert>

using namespace std;

class Monomio_
{
    private:
        int coeficiente;
        int exponente;

    public:
        Monomio_(void);
        Monomio_(int , int );

        int evaluar(int );
        int get_coeficiente(void) const;
        int get_exponente(void) const;

        void set_coeficiente(int );
        void set_exponente(int );

        Monomio_ operator +(Monomio_);
        Monomio_ operator -(Monomio_);
        Monomio_ operator *(Monomio_);

        friend ostream& operator <<(ostream& sout, const Monomio_ );      
};