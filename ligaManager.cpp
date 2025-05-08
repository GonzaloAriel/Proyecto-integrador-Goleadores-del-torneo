/**/

#include <iostream>
#include "ligaManager.h"
#include "jugador.h"
#include "archivoJugador.h"

#include <string>

using namespace std;

void ligaManager::inscripcionJugador()
{
    int dni, codClub;
    string nombre, apellido, telefono, email, fechaNacimiento;
    jugador nuevoJugador;
    archivoJugador archJugador;



    cout<< "Ingrese DNI: ";
    cin>> dni;

    cout<< "Ingrese código que identifica al club: ";
    cin>> codClub;

    cout<< "Ingrese nombre: ";
    cin>> nombre;

    cout<< "Ingrese apellido: ";
    cin>> apellido;

    cout<< "Ingrese telefono: ";
    cin>> telefono;

    cout<< "Ingrese email: ";
    cin>> email;

    cout<< "Ingrese fecha de nacimiento: ";
    cin>> fechaNacimiento;

    nuevoJugador = jugador(dni, codClub, nombre, apellido, telefono, email, fechaNacimiento);

    if(archJugador.guardarJugador(nuevoJugador))
    {
        cout<<endl;
        cout<< "Se inscribio correctamente el jugador!!"<<endl;
    }
    else
    {
        cout<< "No se pudo guardar! Consultar a operario de sistema"<<endl;
    }

    cout<< nuevoJugador.leerRegistro()<<endl;
}

void ligaManager::listarRegistros()
{
    archivoJugador archJugador;
    jugador registro;

    int cantRegistros = archJugador.getCantidadRegistros();

    if(cantRegistros > 0)
    {
        registro.encabezados();
        for(int x=0; x<cantRegistros; x++)
        {
            registro = archJugador.leerJugador(x);
            registro.mostrarEnColumna();
        }
    }
    else
    {
        cout<< "No hay registros"<<endl;
    }
}
