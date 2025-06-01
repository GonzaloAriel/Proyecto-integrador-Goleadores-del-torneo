#pragma once
#include "jugador.h"

class ligaManager
{
public:
    void inscripcionJugador();
    void listarRegistros();
    void listarRegistrosDinamico();
    void modificarJugadores();
    void actualizarDatosJugador(jugador &registroJugador);
    void eliminarJugador();
};
