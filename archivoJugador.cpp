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

int archivoJugador::getCantidadRegistros()
{
    FILE *pFile;

    pFile = fopen(_nombreArchivoJugador.c_str(), "rb");

    if(pFile==nullptr)
    {
        return 0;
    }

    fseek(pFile, 0, SEEK_END);

    int total = ftell(pFile);

    int cantidad = total / sizeof(jugador);

    fclose(pFile);

    return cantidad;
}

jugador archivoJugador::leerJugador(int posicion)
{
    FILE* pFile;
    jugador reg;

    pFile = fopen(_nombreArchivoJugador.c_str(), "rb");

    if(pFile==nullptr)
    {
        return reg;
    }

    fseek(pFile, sizeof(jugador)*posicion, SEEK_SET);

    fread(&reg, sizeof(jugador), 1, pFile);

    fclose(pFile);

    return reg;
}


