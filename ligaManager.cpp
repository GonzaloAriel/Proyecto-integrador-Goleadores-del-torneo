/**/

#include <iostream>
#include "ligaManager.h"
#include "jugador.h"
#include "archivoJugador.h"

#include <string>

using namespace std;

void ligaManager::inscripcionJugador()
{
    int jugadorID, dni, codClub, dia, mes, anio;
    string nombre, apellido, telefono, email;
    Fecha fechaDeNacimiento;
    jugador nuevoJugador;
    archivoJugador archJugador;



    cout<< "Ingrese ID del jugador: ";
    cin>> jugadorID;

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

    cout<< "Ingrese fecha de nacimiento: "<<endl;
    cout<< "Dia: ";
    cin>> dia;
    fechaDeNacimiento.setDia(dia);
    cout<< "Mes: ";
    cin>> mes;
    fechaDeNacimiento.setMes(mes);
    cout<< "Anio: ";
    cin>> anio;
    fechaDeNacimiento.setAnio(anio);

    nuevoJugador = jugador(jugadorID, dni, codClub, nombre, apellido, telefono, email, fechaDeNacimiento);

    if(archJugador.guardarRegistro(nuevoJugador))
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

void ligaManager::modificarJugadores()
{
    int idJugador, indiceRegistro;
    jugador regJugador;
    archivoJugador archJugador;

    cout<< "Ingrese ID del jugador a modificar: ";
    cin>> idJugador;
    cout<<endl;

    indiceRegistro = archJugador.buscarPorID(idJugador);

    if(indiceRegistro != -1)
    {
        regJugador = archJugador.leerJugador(indiceRegistro);
        cout<< regJugador.leerRegistro()<<endl<<endl;

        actualizarDatos(regJugador);

        if(archJugador.reescribirRegistro(indiceRegistro, regJugador))
        {
            cout<< "Se modifico con exito el jugador"<<endl;
        }
        else
        {
            cout<< "No se pudo modificar los datos del jugador"<<endl;
        }

    }
    else
    {
        cout<< "No se encontro jugador con ese ID "<<endl<<endl;
    }

}

void ligaManager::actualizarDatos(jugador &registroJugador)
{
    int dni, codClub, dia, mes, anio;
    string nombre, apellido, telefono, email;
    Fecha fechaDeNacimiento;

    cout<< "Ingrese DNI: ";
    cin>> dni;
    registroJugador.setDni(dni);

    cout<< "Ingrese código que identifica al club: ";
    cin>> codClub;
    registroJugador.setCodigoClub(codClub);

    cout<< "Ingrese nombre: ";
    cin>> nombre;
    registroJugador.setNombre(nombre);

    cout<< "Ingrese apellido: ";
    cin>> apellido;
    registroJugador.setApellido(apellido);

    cout<< "Ingrese telefono: ";
    cin>> telefono;
    registroJugador.setTelefono(telefono);

    cout<< "Ingrese email: ";
    cin>> email;
    registroJugador.setEmail(email);

    cout<< "Ingrese fecha de nacimiento: "<<endl;
    cout<< "Dia: ";
    cin>> dia;
    registroJugador.getFechaNacimiento().setDia(dia);
    cout<< "Mes: ";
    cin>> mes;
    registroJugador.getFechaNacimiento().setMes(mes);
    cout<< "Anio: ";
    cin>> anio;
    registroJugador.getFechaNacimiento().setAnio(anio);
}
