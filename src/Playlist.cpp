// Implementación de la clase Playlist.

#include "Playlist.h"
#include <iostream>

Playlist::Playlist(const std::string& nombre) : nombre(nombre) {}

bool Playlist::agregarCancion(Cancion* cancion) {
    if (cancion == nullptr) {
        return false;
    }

    for (const auto& c : canciones) {
        if (c == cancion) {
            return false;
        }
    }

    canciones.push_back(cancion);
    return true;
}

bool Playlist::agregarPodcast(Podcast* podcast) {
    if (podcast == nullptr) {
        return false;
    }

    for (const auto& p : podcasts) {
        if (p == podcast) {
            return false;
        }
    }

    podcasts.push_back(podcast);
    return true;
}

int Playlist::cantidadPistas() const {
    return static_cast<int>(canciones.size() + podcasts.size());
}

Duracion Playlist::duracionTotal() const {
    int acumuladoSegundos = 0;

    for (const auto& c : canciones) {
        acumuladoSegundos += c->getDuracion().totalSegundos();
    }

    for (const auto& p : podcasts) {
        acumuladoSegundos += p->getDuracion().totalSegundos();
    }

    return Duracion(0, acumuladoSegundos);
}

void Playlist::mostrar() const {
    std::cout << "========================================" << std::endl;
    std::cout << "Playlist: " << nombre << std::endl;
    std::cout << "========================================" << std::endl;

    std::cout << "--- Canciones (" << canciones.size() << ") ---" << std::endl;
    if (canciones.empty()) {
        std::cout << "  (Sin canciones)" << std::endl;
    } else {
        for (const auto& c : canciones) {
            std::cout << "  * ";
            c->mostrar();
        }
    }

    std::cout << "--- Podcasts (" << podcasts.size() << ") ---" << std::endl;
    if (podcasts.empty()) {
        std::cout << "  (Sin podcasts)" << std::endl;
    } else {
        for (const auto& p : podcasts) {
            std::cout << "  * ";
            p->mostrar();
        }
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Total de pistas: " << cantidadPistas() << " | Duración total: ";
    duracionTotal().imprimir();
    std::cout << "\n========================================\n" << std::endl;
}