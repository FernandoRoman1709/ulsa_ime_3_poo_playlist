#include <iostream>
#include <string>
#include <vector>
#include <limits>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Playlist.h"
#include "Cancion.h"
#include "Podcast.h"

// Función auxiliar para limpiar el buffer de entrada de cin
void limpiarBuffer() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::string nombrePlaylist;
    std::cout << "=== SISTEMA DE GESTIÓN DE PLAYLISTS ===\n";
    std::cout << "Ingresa el nombre de tu nueva Playlist: ";
    std::getline(std::cin, nombrePlaylist);

    Playlist miPlaylist(nombrePlaylist);

    // Vectores para gestionar la memoria dinámica de las pistas creadas
    std::vector<Cancion*> cancionesCreadas;
    std::vector<Podcast*> podcastsCreados;

    int opcion = 0;
    do {
        std::cout << "\n----------------------------------------\n";
        std::cout << "MENÚ - PLAYLIST: " << nombrePlaylist << "\n";
        std::cout << "1. Agregar Canción (por título, artista, género, duración)\n";
        std::cout << "2. Agregar Podcast (por título, anfitrión, episodio, duración)\n";
        std::cout << "3. Ver Playlist completa\n";
        std::cout << "4. Salir\n";
        std::cout << "Selecciona una opción (1-4): ";
        
        if (!(std::cin >> opcion)) {
            std::cout << "Opción inválida. Intenta de nuevo.\n";
            std::cin.clear();
            limpiarBuffer();
            continue;
        }
        limpiarBuffer();

        if (opcion == 1) {
            std::string titulo, artista, genero;
            int min, seg;

            std::cout << "\n--- NUEVA CANCIÓN ---\n";
            std::cout << "Título de la canción: ";
            std::getline(std::cin, titulo);
            
            std::cout << "Nombre del artista: ";
            std::getline(std::cin, artista);

            std::cout << "Género musical: ";
            std::getline(std::cin, genero);

            std::cout << "Duración (minutos): ";
            std::cin >> min;
            std::cout << "Duración (segundos): ";
            std::cin >> seg;
            limpiarBuffer();

            // Reserva dinámica de la canción
            Cancion* nuevaCancion = new Cancion(titulo, min, seg, artista, genero);
            cancionesCreadas.push_back(nuevaCancion);

            if (miPlaylist.agregarCancion(nuevaCancion)) {
                std::cout << ">> ¡Canción '" << titulo << "' agregada con éxito!\n";
            } else {
                std::cout << ">> Error: La canción ya existe o el puntero es nulo.\n";
            }

        } else if (opcion == 2) {
            std::string titulo, anfitrion;
            int ep, min, seg;

            std::cout << "\n--- NUEVO PODCAST ---\n";
            std::cout << "Título del episodio: ";
            std::getline(std::cin, titulo);

            std::cout << "Nombre del anfitrión: ";
            std::getline(std::cin, anfitrion);

            std::cout << "Número de episodio: ";
            std::cin >> ep;

            std::cout << "Duración (minutos): ";
            std::cin >> min;
            std::cout << "Duración (segundos): ";
            std::cin >> seg;
            limpiarBuffer();

            // Reserva dinámica del podcast
            Podcast* nuevoPodcast = new Podcast(titulo, min, seg, anfitrion, ep);
            podcastsCreados.push_back(nuevoPodcast);

            if (miPlaylist.agregarPodcast(nuevoPodcast)) {
                std::cout << ">> ¡Podcast '" << titulo << "' agregado con éxito!\n";
            } else {
                std::cout << ">> Error: El podcast ya existe o el puntero es nulo.\n";
            }

        } else if (opcion == 3) {
            std::cout << "\n";
            miPlaylist.mostrar();

        } else if (opcion == 4) {
            std::cout << "\nSaliendo del programa...\n";
        } else {
            std::cout << "Opción no válida.\n";
        }

    } while (opcion != 4);

    // Liberación de memoria dinámica al finalizar
    for (auto c : cancionesCreadas) delete c;
    for (auto p : podcastsCreados) delete p;

    return 0;
}