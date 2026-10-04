#ifndef DURACION_H
#define DURACION_H

class Duracion {
private:
    int minutos;
    int segundos;

public:
    Duracion(int min, int seg);

    int getMinutos() const;
    int getSegundos() const;

    int totalSegundos() const;
    void imprimir() const; // <-- Revisa que esta línea esté presente
};

#endif

    // Pregunta: ¿qué significa el const al final de estos métodos?
