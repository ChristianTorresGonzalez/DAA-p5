#include <iostream>

#include "../include/polinomio.h"

    Polinomio_::Polinomio_(void):
        grado(0)
        {}

    Polinomio_::Polinomio_(int a):
        grado(a)
        {
            for (int i = 0; i <= grado; i++)
            {
                Monomio_ monomio(rand() % 100 + 0, grado - i);
                polinomio.push_back(monomio);
            }
        }

    Polinomio_::Polinomio_(int a, int b):
        grado(a)
        {
            for (int i = 0; i <= grado; i++)
            {
                Monomio_ monomio(b, grado - i);
                polinomio.push_back(monomio);
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

    void Polinomio_::set_monomio(Monomio_ nuevo_monomio, int posicion)
    {
        polinomio[posicion] = nuevo_monomio;
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

        for (int i = polinomio.size() - 1; i >= 0; i--)
        {
            int exponente_primier_polinomio = polinomio[i].get_exponente();

            for(int j = otro_polinomio.get_polinomio().size() - 1; j >= 0; j--)
            {
                int posicion = resultado.polinomio.size() - 1 - (exponente_primier_polinomio + otro_polinomio.polinomio[j].get_exponente());
                resultado.polinomio[posicion] = resultado.polinomio[posicion] + (polinomio[i] * otro_polinomio.polinomio[j]);
            }
        }

        return resultado;
    }

    Polinomio_ Polinomio_::algoritmo_DyV(Polinomio_ &polinomio, Polinomio_ &otro_polinomio, Polinomio_ & resultado)
    {
        if (caso_minimo(polinomio) && caso_minimo(otro_polinomio))
        {
            Monomio_ monomio = polinomio.get_monomio(0) * otro_polinomio.get_monomio(0);
            Polinomio_ resultado(monomio.get_exponente(), 0);
            resultado.set_monomio(monomio, 0);
            return resultado;
        }
        else
        {
            int centro = (polinomio.get_polinomio().size() == 2 ? 0 : (polinomio.get_polinomio().size() / 2));

            Polinomio_ polinomio_izquierda(centro, 0);
            Polinomio_ polinomio_derecha;
            Polinomio_ otro_polinomio_izquierda(centro, 0);
            Polinomio_ otro_polinomio_derecha;
            
            
            polinomio_izquierda.copiar_polinomio(polinomio, 0, centro);
            polinomio_izquierda.modificar_exponente(centro);
            polinomio_derecha.copiar_polinomio_derecho(polinomio, centro + 1, polinomio.get_polinomio().size() - 1);
            
            centro = (otro_polinomio.get_polinomio().size() == 2 ? 0 : (otro_polinomio.get_polinomio().size() / 2));
            otro_polinomio_izquierda.copiar_polinomio(otro_polinomio, 0, centro);

            otro_polinomio_derecha.copiar_polinomio_derecho(otro_polinomio, centro + 1, otro_polinomio.get_polinomio().size() - 1);

            if (polinomio_derecha.get_polinomio().size() != polinomio_izquierda.get_polinomio().size())
            {
                Monomio_ blanco(0, polinomio_derecha.polinomio[0].get_exponente() + 1);
                polinomio_derecha.polinomio.insert(polinomio_derecha.polinomio.begin(), blanco) ;
            }

            otro_polinomio_izquierda.modificar_exponente(centro);
            if (otro_polinomio_derecha.get_polinomio().size() != otro_polinomio_izquierda.get_polinomio().size())
            {
                Monomio_ blanco(0, otro_polinomio_derecha.polinomio[0].get_exponente() + 1);
                otro_polinomio_derecha.polinomio.insert(otro_polinomio_derecha.polinomio.begin(), blanco) ;
            }
            
            Polinomio_ rh = algoritmo_DyV(polinomio_izquierda, otro_polinomio_izquierda, resultado);
            Polinomio_ rl = algoritmo_DyV(polinomio_derecha, otro_polinomio_derecha, resultado);
            Polinomio_ auxiliar1 = (polinomio_izquierda + polinomio_derecha);
            Polinomio_ auxiliar2 = (otro_polinomio_izquierda + otro_polinomio_derecha);
            Polinomio_ rm = algoritmo_DyV(auxiliar1, auxiliar2, resultado);

            Polinomio_ resta1 = rm - rh;
            Polinomio_ resta2 = resta1 - rl;

            resta2.rotar_posicion(polinomio.get_polinomio().size() / 2);
            resta2.rellenar_polinomio(resta2.get_grado());

            if (resta2.get_polinomio().size() > rh.get_polinomio().size())
                rh.rellenar_polinomio(resta2.get_grado());
            else if (rh.get_polinomio().size() > resta2.get_polinomio().size())
                resta2.rellenar_polinomio(rh.get_grado());

            Polinomio_ suma1 = resta2 + rh;

            rl.rotar_posicion(polinomio.get_polinomio().size());
            rl.rellenar_polinomio(rl.get_grado());
            
            if (suma1.get_grado() > rl.get_grado())
                rl.rellenar_polinomio(suma1.get_grado());
            else if (rl.get_grado() > suma1.get_grado())
                suma1.rellenar_polinomio(rl.get_grado());

            suma1.set_grado(suma1.polinomio[0].get_exponente());
            Polinomio_ suma2 = suma1 + rl;
            resultado.concatenar_polinomio(suma2);

            return resultado;
        }
    }

    void Polinomio_::concatenar_polinomio(Polinomio_ & otro_polinomio)
    {
        int j = 0;
        for (int i = 0; i < polinomio.size(); i++)
        {
            if (j < otro_polinomio.get_polinomio().size())
            {
                if (polinomio[i].get_exponente() == otro_polinomio.polinomio[j].get_exponente())
                {
                    polinomio[i] = polinomio[i] + otro_polinomio.polinomio[j];
                    j++;
                }
            }
        }
    }

    void Polinomio_::rellenar_polinomio(int max)
    {
        vector<Monomio_> auxiliar(max + 1);
        for (int i = 0; i < auxiliar.size(); i++)
            auxiliar[i].set_exponente(max - i);

        int j = 0;
        for (int i = 0; i < auxiliar.size(); i++)
        {
            if (j < polinomio.size())
            {
                if ((max - i) == polinomio[j].get_exponente())
                {
                    auxiliar[i] = auxiliar[i] + polinomio[j];
                    j++;
                }
                else
                {
                    auxiliar[i].set_exponente(max - i);
                }
            }
            else
            {
                auxiliar[i].set_exponente(max - i);
            }
        }

        polinomio = auxiliar;
    }

    void Polinomio_::modificar_exponente(int size)
    {
        for (int i = 0; i < polinomio.size(); i++)
            polinomio[i].set_exponente(grado - i);
    }

    bool Polinomio_::caso_minimo(Polinomio_ otro_polinomio)
    {
        return (otro_polinomio.get_polinomio().size() < 2);
    }

    void Polinomio_::rotar_posicion(int exponente)
    {
        for (int i = 0; i < polinomio.size(); i++)
            polinomio[i].set_exponente(polinomio[i].get_exponente() + exponente);

        grado = polinomio[0].get_exponente();
    }

//---------------------------------------------------------------------------------------
//---------------------- Sobrecarga de operadores ---------------------------------------
//---------------------------------------------------------------------------------------

    Polinomio_ Polinomio_::operator +(Polinomio_ & otro_polinomio)
    {
        Polinomio_ resultado(grado);
        for (int i = 0; i < polinomio.size(); i++)
            resultado.polinomio[i] = polinomio[i] + otro_polinomio.polinomio[i];

        return resultado;
    }

    Polinomio_ Polinomio_::operator -(Polinomio_ & otro_polinomio)
    {
        Polinomio_ resultado(grado);
        for (int i = 0; i < polinomio.size(); i++)
            resultado.polinomio[i] = polinomio[i] - otro_polinomio.polinomio[i];

        return resultado;
    }

    Polinomio_ Polinomio_::operator *(Polinomio_ & otro_polinomio)
    {
        Polinomio_ resultado(grado + otro_polinomio.get_grado(), 0);

        auto start1 = chrono::system_clock::now();
            resultado = algoritmo_clasico(otro_polinomio);
        auto end1 = chrono::system_clock::now();
        chrono::duration<float,milli> duration1 = end1 - start1;

        auto start = chrono::system_clock::now();
            algoritmo_DyV(*this, otro_polinomio, resultado);
        auto end = chrono::system_clock::now();
        chrono::duration<float,milli> duration = end - start;
        cout << endl << "Tiempo transcurrido con filas-columnas: " << duration1.count() << endl;
        cout << endl << "Tiempo transcurrido con columnas-filas: " << duration.count() << endl;
        return resultado;
    }

    ostream& operator <<(ostream& out, Polinomio_ otro_polinomio)
    {
        for(int i = 0; i < otro_polinomio.get_polinomio().size(); i++)
            out << otro_polinomio.get_monomio(i);
    }

    void Polinomio_::copiar_polinomio(Polinomio_ &otro_polinomio)
    {
        grado = otro_polinomio.get_grado();
        
        for (int i = 0; i < otro_polinomio.get_polinomio().size(); i++)
            polinomio[i] = otro_polinomio.get_monomio(i);
    }

    void Polinomio_::copiar_polinomio(Polinomio_ &otro_polinomio , int inicio, int fin)
    {
        int j = 0;
        for (int i = inicio; i <= fin; i++)
        {
            polinomio[j] = otro_polinomio.get_monomio(i);
            j++;
        }
    }

    void Polinomio_::copiar_polinomio_derecho(Polinomio_ &otro_polinomio , int inicio, int fin)
    {
        for (int i = inicio; i <= fin; i++)
            polinomio.push_back(otro_polinomio.get_monomio(i));
    }