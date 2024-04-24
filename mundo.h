#ifndef MUNDO_H
#define MUNDO_H

#include <vector>
#include "jugador.h"
#include "enemigo.h"
#include "item.h"

class Mundo {
public:
    Mundo() {}

    void agregarJugador(Jugador* jugador) {
        jugadores.push_back(jugador);
    }

    void agregarEnemigo(Enemigo* enemigo) {
        enemigos.push_back(enemigo);
    }

    void agregarItem(Item* item) {
        items.push_back(item);
    }

    void simularTurno() {
        
        for (auto& enemigo : enemigos) {
            for (auto& jugador : jugadores) {
                enemigo->atacar(*jugador);
            }
        }
    }

    void mostrarEstado() {
        std::cout << "Estado del mundo:" << std::endl;
        std::cout << "Jugadores:" << std::endl;
        for (auto& jugador : jugadores) {
            jugador->mostrarEstado();
        }
        std::cout << "Enemigos:" << std::endl;
        for (auto& enemigo : enemigos) {
            enemigo->mostrarEstado();
        }
        std::cout << "Ítems:" << std::endl;
        for (auto& item : items) {
            item->mostrarEstado();
        }
    }

private:
    std::vector<Jugador*> jugadores;
    std::vector<Enemigo*> enemigos;
    std::vector<Item*> items;
};

#endif