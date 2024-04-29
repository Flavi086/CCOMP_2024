#include <string>
#include <vector>
#include <iostream>
#include "item.h"

class Enemigo; 

class Jugador {
public:
    Jugador(std::string nombre, int salud, int fuerza)
        : nombre(nombre), salud(salud), fuerza(fuerza) {}

    virtual void atacar(Enemigo &enemigo) {
        std::cout << nombre << " ataca a " << enemigo.getNombre() << "!" << std::endl;
        enemigo.recibirAtaque(fuerza);
    }

    virtual void recibirAtaque(int fuerzaAtaque) {
        salud -= fuerzaAtaque; 
        if (salud <= 0) {
            std::cout << nombre << " ha sido derrotado!" << std::endl;
        }
    }

    virtual void mostrarEstado() {
        std::cout << "Jugador: " << nombre << ", Salud: " << salud << ", Fuerza: " << fuerza << std::endl;
    }

    std::string getNombre() const { return nombre; }
    int getSalud() const { return salud; }
    int getFuerza() const { return fuerza; }
    std::vector<Item>& getInventario() { return inventario; }

    virtual ~Jugador() {}

protected:
    std::string nombre;
    int salud;
    int fuerza;
    std::vector<Item> inventario;
};


class Mago : public Jugador {
public:
    Mago(std::string nombre)
        : Jugador(nombre, 80, 15), mana(100) {}

    void usarHechizo(std::string hechizo) {
        std::cout << nombre << " lanza el hechizo " << hechizo << "!" << std::endl;
        mana -= 20;
    }

    void mostrarEstado() override {
        std::cout << "Mago: " << nombre << ", Salud: " << salud << ", Fuerza: " << fuerza << ", Mana: " << mana << std::endl;
    }

private:
    int mana;
};

class Tanque : public Jugador {
public:
    Tanque(std::string nombre)
        : Jugador(nombre, 150, 20), defensa(30) {}

    void aumentarDefensa(int cantidad) {
        defensa += cantidad;
        std::cout << nombre << " aumenta su defensa!" << std::endl;
    }

    void mostrarEstado() override {
        std::cout << "Tanque: " << nombre << ", Salud: " << salud << ", Fuerza: " << fuerza << ", Defensa: " << defensa << std::endl;
    }

private:
    int defensa;
};

class Sacerdote : public Jugador {
public:
    Sacerdote(std::string nombre)
        : Jugador(nombre, 120, 10), fe(80) {}

    void usarBendicion(Jugador& jugador) {
        std::cout << nombre << " bendice a " << jugador.getNombre() << "!" << std::endl;
        jugador.recibirBendicion(30);
    }

    void recibirAtaque(int fuerzaAtaque) override {
        salud -= (fuerzaAtaque - fe);
        if (salud <= 0) {
            std::cout << nombre << " ha sido derrotado!" << std::endl;
        }
    }

    void mostrarEstado() override {
        std::cout << "Sacerdote: " << nombre << ", Salud: " << salud << ", Fuerza: " << fuerza << ", Fe: " << fe << std::endl;
    }

private:
    int fe; 
};
