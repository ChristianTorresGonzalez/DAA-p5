#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>

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
        void set_monomio(Monomio_ , int );
        
        int get_grado(void) const;
        vector<Monomio_> get_polinomio(void) const;
        Monomio_ get_monomio(int );

        void copiar_polinomio(Polinomio_ &);
        void copiar_polinomio(Polinomio_ & , int , int );
        void copiar_polinomio_derecho(Polinomio_ & , int , int );

        Polinomio_ algoritmo_clasico(Polinomio_ &);
        Polinomio_ algoritmo_DyV(Polinomio_ & , Polinomio_ & , Polinomio_ & );
        bool caso_minimo(Polinomio_ );
        void rotar_posicion(int );
        void modificar_exponente(int );
        void rellenar_polinomio(int );
        void concatenar_polinomio(Polinomio_ & );

        Polinomio_ operator +(Polinomio_ & );
        Polinomio_ operator -(Polinomio_ & );
        Polinomio_ operator *(Polinomio_ & );
        friend ostream& operator <<(ostream &out, Polinomio_ );
};

