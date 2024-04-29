#include <iostream>
#include "jugador.h"
#include "enemigo.h"
#include "item.h"
#include "mundo.h"

int main() {
    Mundo mundo;

    Jugador* jugador = new Jugador("Hero", 100, 10);
    Enemigo* enemigo = new Enemigo("Slime", 50, 5);
    Item* item = new Item("Poción de salud", 20);

    mundo.agregarJugador(jugador);
    mundo.agregarEnemigo(enemigo);
    mundo.agregarItem(item);

    mundo.mostrarEstado();

    mundo.simularTurno();

    mundo.mostrarEstado();

    delete jugador;
    delete enemigo;
    delete item;

    return 0;
}