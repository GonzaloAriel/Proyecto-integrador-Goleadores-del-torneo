#pragma once
#include "jugador.h"

class ligaManager
{
public:
    void inscripcionJugador();
    void listarRegistros();
    void modificarJugadores();
    void actualizarDatos(jugador &registroJugador);
};
