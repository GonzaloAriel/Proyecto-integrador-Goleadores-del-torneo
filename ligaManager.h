#pragma once
#include "jugador.h"

class ligaManager
{
public:
    void inscripcionJugador();
    void listarRegistros();
    void modificarJugadores();
    void actualizarDatosJugador(jugador &registroJugador);
    void eliminarJugador();
};
