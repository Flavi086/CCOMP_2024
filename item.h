#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {
public:
    Item(std::string nombre, int efecto)
        : nombre(nombre), efecto(efecto) {}

    void mostrarEstado() {
        std::cout << "Ítem: " << nombre << ", Efecto: " << efecto << std::endl;
    }

    std::string getNombre() const { return nombre; }
    int getEfecto() const { return efecto; }

private:
    std::string nombre;
    int efecto;
};

#endif