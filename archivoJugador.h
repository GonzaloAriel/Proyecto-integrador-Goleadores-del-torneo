#pragma once
#include <string>
#include "jugador.h"

class archivoJugador
{
private:
    std::string _nombreArchivoJugador;

public:
    archivoJugador();
    archivoJugador(std::string nombreArchivoJugador);

    bool guardarRegistro(jugador registroJugador);
    bool reescribirRegistro(int indice, jugador registroJugador);
    int getCantidadRegistros();
    jugador leerJugador(int posicion);
    int buscarPorID(int id);
};

