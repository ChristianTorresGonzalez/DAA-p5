#include <iostream>

#include "../include/monomio.h"

    Monomio_::Monomio_(void):
        coeficiente(0),
        exponente(0)
        {}
    
    Monomio_::Monomio_(int a, int b):
        coeficiente(a),
        exponente(b)
        {}

    int Monomio_::evaluar(int x)
    {
        return (coeficiente * pow(x, exponente));
    }

    int Monomio_::get_coeficiente(void) const
    {
        return coeficiente;
    }

    int Monomio_::get_exponente(void) const
    {
        return exponente;
    }

    void Monomio_::set_coeficiente(int coefi)
    {
        coeficiente = coefi;
    }

    void Monomio_::set_exponente(int expo)
    {
        exponente = expo;
    }

    Monomio_ Monomio_::operator + (Monomio_ otro_monomio)
    {
        assert (this -> exponente == otro_monomio.get_exponente());
            Monomio_ auxiliar;
            auxiliar.set_coeficiente(this -> coeficiente + otro_monomio.get_coeficiente());
            auxiliar.set_exponente(this -> exponente);
            return auxiliar;
        
    }

    Monomio_ Monomio_::operator * (Monomio_ otro_monomio)
    {
            Monomio_ auxiliar;
            auxiliar.set_coeficiente(this -> coeficiente * otro_monomio.get_coeficiente());
            auxiliar.set_exponente(this -> exponente + otro_monomio.get_exponente());
            return auxiliar;
        
    }

    ostream& operator <<(ostream &sout, const Monomio_ monomio)
    {
        if (monomio.get_exponente() > 0)
            sout << monomio.get_coeficiente() << "x^" << monomio.get_exponente() << " + ";
        else
            sout << monomio.get_coeficiente() << endl;
        
        return sout;
    }
    

    // istream& Monomio_::operator >>(istream &sin)
    // {
    //     sin >> this -> set;
    // }