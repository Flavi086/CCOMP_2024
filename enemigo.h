#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <string>
#include <iostream>
#include "jugador.h"

class Enemigo {
public:
    Enemigo(std::string nombre, int salud, int fuerza)
        : nombre(nombre), salud(salud), fuerza(fuerza) {}

    void atacar(Jugador &jugador) {
        std::cout << nombre << " ataca a " << jugador.getNombre() << "!" << std::endl;
        jugador.recibirAtaque(fuerza);
    }

    void recibirAtaque(int fuerzaAtaque) {
        salud -= fuerzaAtaque; 
        if (salud <= 0) {
            std::cout << nombre << " ha sido derrotado!" << std::endl;
        }
    }

    void mostrarEstado() {
        std::cout << "Enemigo: " << nombre << ", Salud: " << salud << ", Fuerza: " << fuerza << std::endl;
    }

    std::string getNombre() const { return nombre; }
    int getSalud() const { return salud; }
    int getFuerza() const { return fuerza; }

private:
    std::string nombre;
    int salud;
    int fuerza;
};

#endif