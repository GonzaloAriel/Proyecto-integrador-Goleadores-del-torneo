/**/

#include <iostream>
#include "ligaManager.h"
#include "jugador.h"
#include "archivoJugador.h"

#include <string>

using namespace std;

void ligaManager::listarRegistros()
{
    archivoJugador archJugador;
    jugador registro;

    int cantRegistros = archJugador.getCantidadRegistros();

    if(cantRegistros > 0)
    {
        registro.encabezadosJugador();
        for(int x=0; x<cantRegistros; x++)
        {
            registro = archJugador.leerJugador(x);
            if(registro.getEliminado() != true)
            {
                registro.mostrar();
            }
        }
    }
    else
    {
        cout<< "No hay registros"<<endl;
    }
}

void ligaManager::listarRegistrosDinamico()
{
    int cantRegistros = archivoJugador().getCantidadRegistros();

    jugador *registros;

    registros = new jugador[cantRegistros];

    if(registros==nullptr)
    {
        cout<< "No se pudo pedir memoria!"<<endl;
        return;
    }

    archivoJugador().leerTodos(registros, cantRegistros);

    if(cantRegistros > 0)
    {
        jugador().encabezadosJugador();
        for(int x=0; x<cantRegistros; x++)
        {
            if(registros[x].getEliminado() != true)
            {
                registros[x].mostrar();
            }
        }
    }
    else
    {
        cout<< "No hay registros"<<endl;
    }

    delete []registros;
}

void ligaManager::modificarJugadores()
{
    int idJugador, indiceRegistro;
    jugador regJugador;
    archivoJugador archJugador;
    bool alta;

    cout<< "Ingrese ID del jugador a modificar: ";
    cin>> idJugador;
    cout<<endl;

    indiceRegistro = archJugador.buscarPorID(idJugador);

    if(indiceRegistro != -1)
    {
        regJugador = archJugador.leerJugador(indiceRegistro);
        cout<< regJugador.mostrarRegistroCSV()<<endl<<endl;

        if(regJugador.getEliminado()== true)
        {
            cout<< "Este jugador se encuentra dado de baja"<<endl<<endl;
            cout<< "Desea volver a dar el alta nuevamente?"<<endl;
            cout<< "Presione:   (1)SI / (0)NO"<<endl;
            cin>>alta;
            if(alta)
            {
                regJugador.setEliminado(0);
                if(archJugador.reescribirRegistro(indiceRegistro, regJugador))
                {
                    cout<< "Se habilito con exito el jugador"<<endl;
                }
                else
                {
                    cout<< "No se pudo habilitar jugador"<<endl;
                }
            }
        }
        else
        {
            actualizarDatosJugador(regJugador);

            if(archJugador.reescribirRegistro(indiceRegistro, regJugador))
            {
                cout<< "Se modifico con exito el jugador"<<endl;
            }
            else
            {
                cout<< "No se pudo modificar los datos del jugador"<<endl;
            }
        }
    }
    else
    {
        cout<< "No se encontro jugador con ese ID "<<endl<<endl;
    }

}

void ligaManager::eliminarJugador()
{
    int idJugador, indiceRegistro;
    bool eliminar=0;
    jugador regJugador;
    archivoJugador archJugador;

    cout<< "Ingrese ID del jugador a eliminar: ";
    cin>> idJugador;
    cout<<endl;

    indiceRegistro = archJugador.buscarPorID(idJugador);

    if(indiceRegistro != -1)
    {
        regJugador = archJugador.leerJugador(indiceRegistro);
        cout<< regJugador.mostrarRegistroCSV()<<endl<<endl;

        cout<< "¿Estas seguro que quiere eliminar el jugador?"<<endl;
        cout<< "1-Si  0-No"<<endl;
        cin>> eliminar;

        if(eliminar)
        {
            regJugador.setEliminado(eliminar);

            if(archJugador.reescribirRegistro(indiceRegistro, regJugador))
            {
                cout<< "Se elimino con exito!!"<<endl;
            }
            else
            {
                cout<< "No se pudo eliminar el jugador!"<<endl;
            }
        }
        else
        {
            cout<< "El jugador no se elimino!"<<endl;
        }

    }
    else
    {
        cout<< "No se encontro jugador con ese ID "<<endl<<endl;
    }
}

void ligaManager::actualizarDatosJugador(jugador &registroJugador)
{
    int dni, codClub, dia, mes, anio;
    string nombre, apellido, telefono, email;
    Fecha fechaDeNacimiento;

    cout<< "Ingrese DNI: ";
    cin>> dni;
    registroJugador.setDni(dni);

    cout<< "Ingrese codigo que identifica al club: ";
    cin>> codClub;
    registroJugador.setCodigoClub(codClub);

    cout<< "Ingrese nombre: ";
    cin.ignore();
    getline(cin, nombre);
    registroJugador.setNombre(nombre);

    cout<< "Ingrese apellido: ";
    getline(cin, apellido);
    registroJugador.setApellido(apellido);

    cout<< "Ingrese telefono: ";
    cin>> telefono;
    registroJugador.setTelefono(telefono);

    cout<< "Ingrese email: ";
    cin.ignore();
    getline(cin, email);
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

bool ligaManager::cargarDNI(int &dni)
{
    cout<< "Ingrese DNI: "<<endl;
    cin>> dni;
    cout<<endl;

    int cantRegistros = archivoJugador().getCantidadRegistros();

    jugador *registros;

    registros = new jugador[cantRegistros];

    if(registros==nullptr)
    {
        cout<< "No se pudo pedir memoria!"<<endl;
        return true;
    }

    archivoJugador().leerTodos(registros, cantRegistros);

    if(cantRegistros > 0)
    {
        for(int x=0; x<cantRegistros; x++)
        {
            if(registros[x].getDni() == dni)
            {
                cout<< "DNI ya registrado!!"<<endl<<endl;
                return true;
            }
        }
    }
    else
    {
        cout<< "No hay registros"<<endl;
    }

    delete []registros;

    return false;
}
