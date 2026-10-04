// Implementación de la clase Duracion.

#include "Duracion.h"

#include <iomanip>
#include <iostream>

Duracion::Duracion(int min, int seg) : minutos(min), segundos(seg) {
    // Si min o seg son negativos, la duración queda en 0:00.
    // Si seg es mayor a 59, convierte el excedente en minutos.
    if (min < 0 || seg < 0) {
        minutos = 0;
        segundos = 0;
    } else {
        minutos = min + (seg / 60);
        segundos = seg % 60;
    }
}

int Duracion::getMinutos() const { 
    return minutos; 
}

int Duracion::getSegundos() const { 
    return segundos; 
}

// Devuelve la duración completa expresada en segundos.
int Duracion::totalSegundos() const {
    return (minutos * 60) + segundos;
}

// Imprime con el formato m:ss (por ejemplo 3:05, no 3:5).
void Duracion::imprimir() const {
    std::cout << minutos << ":" 
              << std::setw(2) << std::setfill('0') << segundos;
}