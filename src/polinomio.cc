#include <iostream>

#include "../include/polinomio.h"

    Polinomio_::Polinomio_(void):
        grado(0),
        polinomio(0)
        {}

    Polinomio_::Polinomio_(int a):
        grado(a),
        polinomio(grado)
        {
            for (int i = grado; i >= 0; i--)
            {
                Monomio_ monomio(rand() % 10 + 0, i);
                polinomio[i] = monomio;
            }
        }

    int Polinomio_::get_grado(void) const
    {
        return grado;
    }

    Polinomio_ Polinomio_::algoritmo_clasico(Polinomio_ & otro_polinomio)
    {
        // Polinomio_ resultado(this -> grado + 1);
        // Polinomio_ resultado(this -> grado + otro_polinomio.get_grado() + 2);

        // for(int i = this -> grado; i >= 0; i--)
        // {
        //     int exponente_primer_polinomio = this -> polinomio[i].get_exponente();

        //     for(int j = 0; j < otro_polinomio.get_grado(); j++)
        //     {
        //         // int posicion = exponente_primer_polinomio + otro_polinomio.polinomio[j].get_exponente();
        //         // resultado.polinomio[posicion] = resultado.polinomio[posicion] + (this -> polinomio[i] * otro_polinomio.polinomio[j]);
        //         // cout << resultado.polinomio[posicion];
                // cout << this -> polinomio[i];
        //     }
        // }
    }

    Monomio_ Polinomio_::get_monomio(int posicion)
    {
        return polinomio[posicion];
    }

    Polinomio_ Polinomio_::operator +(Polinomio_ & otro_polinomio)
    {
        cout << this -> polinomio[0] + otro_polinomio.polinomio[0];
        // Polinomio_ polinomio1 = *this;
        // Polinomio_ resultado = this -> algoritmo_clasico(otro_polinomio);
        // return  resultado;
    }

    Polinomio_ Polinomio_::operator *(Polinomio_ & otro_polinomio)
    {
        // Polinomio_ polinomio1 = *this;
        Polinomio_ resultado = otro_polinomio;
        //  = ;
        cout << *this;
        return  resultado;
    }

    ostream& operator <<(ostream& out, Polinomio_ &otro_polinomio)
    {
        for(int i = otro_polinomio.get_grado(); i >= 0; i--)
        {
            Monomio_ monomio = otro_polinomio.get_monomio(i);
            out << monomio;
        }
    }