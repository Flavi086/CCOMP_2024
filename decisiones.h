#include <iostream>

class Decisiones {
public:
    Decisiones() {}

    virtual void tomarDecision() {
        std::cout << "Estás en una encrucijada, ¿qué camino eliges?" << std::endl;
        mostrarOpciones();
        int opcion;
        std::cin >> opcion;
        switch (opcion) {
            case 1:
                opcionUno();
                break;
            case 2:
                opcionDos();
                break;
            default:
                std::cout << "Opción inválida. Por favor, selecciona una opción válida." << std::endl;
                break;
        }
    }

    virtual void mostrarOpciones() {
        std::cout << "1. Ir hacia la izquierda." << std::endl;
        std::cout << "2. Ir hacia la derecha." << std::endl;
    }

    virtual void opcionUno() {
        std::cout << "Has elegido ir hacia la izquierda." << std::endl;
    }

    virtual void opcionDos() {
        std::cout << "Has elegido ir hacia la derecha." << std::endl;
    }

    virtual ~Decisiones() {}
};
