#include "archivoJugador.h"

archivoJugador::archivoJugador()
{
    _nombreArchivoJugador = "jugador.dat";
}
archivoJugador::archivoJugador(std::string nombreArchivoJugador)
{
    _nombreArchivoJugador = nombreArchivoJugador;
}

bool archivoJugador::guardarJugador(jugador registroJugador)
{
    FILE *pFile;
    bool resultado;

    pFile = fopen(_nombreArchivoJugador.c_str(), "ab");

    if(pFile==nullptr)
    {
        return false;
    }

    resultado = fwrite(&registroJugador, sizeof(jugador), 1, pFile);

    fclose(pFile);

    return resultado;
}

int getCantidadRegistros()
{

}


