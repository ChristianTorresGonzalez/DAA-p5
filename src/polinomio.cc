#include <iostream>

#include "../include/polinomio.h"

    Polinomio_::Polinomio_(void):
        grado(0),
        polinomio(1)
        {}

    Polinomio_::Polinomio_(int a):
        grado(a)
        {
            polinomio.resize(grado);

            for (int i = 0; i <= grado; i++)
            {
                Monomio_ monomio(rand() % 100 + 0, grado - i);
                polinomio[i] = monomio;
            }
        }

    Polinomio_::Polinomio_(int a, int b):
        grado(a)
        {
            polinomio.resize(grado);

            for (int i = 0; i <= grado; i++)
            {
                Monomio_ monomio(b, grado - i);
                polinomio[i] = monomio;
            }
        }

//---------------------------------------------------------------------------------------
//----------------------------- Getters y Setters ---------------------------------------
//---------------------------------------------------------------------------------------

    void Polinomio_::set_grado(int numero)
    {
        grado = numero;
    }

    void Polinomio_::set_polinomio(vector<Monomio_> nuevo_polinomio)
    {
        polinomio = nuevo_polinomio;
    }

    int Polinomio_::get_grado(void) const
    {
        return grado;
    }

    Monomio_ Polinomio_::get_monomio(int posicion)
    {
        return polinomio[posicion];
    }

    vector<Monomio_> Polinomio_::get_polinomio(void) const
    {
        return polinomio;
    }

//---------------------------------------------------------------------------------------
//--------------------------- Algoritmos de multiplicacion-------------------------------
//---------------------------------------------------------------------------------------

    Polinomio_ Polinomio_::algoritmo_clasico(Polinomio_ &otro_polinomio)
    {
        Polinomio_ resultado(grado + otro_polinomio.get_grado(), 0);

        for (int i = polinomio.size(); i >= 0; i--)
        {
            int exponente_primier_polinomio = polinomio[i].get_exponente();

            for(int j = otro_polinomio.get_grado(); j >= 0; j--)
            {
                int posicion = resultado.polinomio.size() - (exponente_primier_polinomio + otro_polinomio.polinomio[j].get_exponente());
                resultado.polinomio[posicion] = resultado.polinomio[posicion] + (polinomio[i] * otro_polinomio.polinomio[j]);
            }
        }

        cout << resultado;

        return resultado;
    }

    Polinomio_ Polinomio_::algoritmo_DyV(Polinomio_ &otro_polinomio)
    {
        
    }

//---------------------------------------------------------------------------------------
//---------------------- Sobrecarga de operadores ---------------------------------------
//---------------------------------------------------------------------------------------

    Polinomio_ Polinomio_::operator +(Polinomio_ & otro_polinomio)
    {
        cout << this -> polinomio[0] + otro_polinomio.polinomio[0];
    }

    Polinomio_ Polinomio_::operator *(Polinomio_ & otro_polinomio)
    {
        return this -> algoritmo_clasico(otro_polinomio);
    }

    ostream& operator <<(ostream& out, Polinomio_ &otro_polinomio)
    {
        for(int i = 0; i <= otro_polinomio.get_grado(); i++)
        {
            out << otro_polinomio.get_monomio(i);
        }
    }

    void Polinomio_::copiar_polinomio(Polinomio_ &otro_polinomio)
    {
        grado = otro_polinomio.get_grado();
        for (int i = 0; i <= otro_polinomio.get_grado(); i++)
            polinomio[i] = otro_polinomio.get_monomio(i);
    }