#include "Pista.h"
#include <iostream>

Pista::Pista(const std::string& titulo, int min, int seg)
    : titulo(titulo), duracion(min, seg) {
    if (this->titulo.empty()) {
        this->titulo = "Sin título";
    }
}

std::string Pista::getTitulo() const { 
    return titulo; 
}

Duracion Pista::getDuracion() const { 
    return duracion; 
}

void Pista::setTitulo(const std::string& nuevoTitulo) {
    if (nuevoTitulo.empty()) {
        titulo = "Sin título";
    } else {
        titulo = nuevoTitulo;
    }
}

void Pista::mostrarInfo() const {
    std::cout << "Título: " << titulo << " | Duración: ";
    duracion.imprimir();
}