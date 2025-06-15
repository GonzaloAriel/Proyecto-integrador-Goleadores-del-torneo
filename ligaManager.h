#pragma once
#include "jugador.h"

class ligaManager
{
public:

    ///Manager Jugador

    void listarRegistros();
    void listarRegistrosDinamico();
    void modificarJugadores();
    void actualizarDatosJugador(jugador &registroJugador);
    void eliminarJugador();
    bool cargarDNI(int &dni);
};
