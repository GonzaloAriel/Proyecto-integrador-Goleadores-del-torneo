#include "jugador.h"
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

jugador::jugador()
{
    _jugadorID = 0;
    _dni = 0;
    _codigoClub = 0;
    strcpy(_apellido, "");
    strcpy(_nombre, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    _fechaDeNacimiento = Fecha();
    _eliminado = true;
}

jugador::jugador(int jugadorID, int dni, int codigoClub, std::string nombre, std::string apellido,
                 std::string telefono, std::string email, Fecha fecha, bool eliminado)
{
    setJugadorID(jugadorID);
    setDni(dni);
    setCodigoClub(codigoClub);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setFechaNacimiento(fecha);
    setEliminado(eliminado);
}

//Setter:
void jugador::setJugadorID(int jugadorID)
{
    _jugadorID = jugadorID;
}
void jugador::setDni(int dni)
{
    _dni = dni;
}
void jugador::setCodigoClub (int codigoClub)
{
    _codigoClub = codigoClub;
}
void jugador::setNombre(std::string nombre)
{
    strcpy(_nombre, nombre.c_str());
}
void jugador::setApellido(std::string apellido)
{
    strcpy(_apellido, apellido.c_str());
}
void jugador::setTelefono(std::string telefono)
{
    strcpy(_telefono, telefono.c_str());
}
void jugador::setEmail(std::string email)
{
    strcpy(_email, email.c_str());
}
void jugador::setFechaNacimiento(Fecha fecha)
{
    _fechaDeNacimiento = fecha;
}
void jugador::setEliminado(bool eliminado)
{
    _eliminado = eliminado;
}


//Getter:
int jugador::getJugadorID()
{
    return _jugadorID;
}
int jugador::getDni()
{
    return _dni;
}
int jugador::getCodigoClub ()
{
    return _codigoClub;
}
std::string jugador::getNombre()
{
    return _nombre;
}
std::string jugador::getApellido()
{
    return _apellido;
}
std::string jugador::getTelefono()
{
    return _telefono;
}
std::string jugador::getEmail()
{
    return _email;
}
Fecha jugador::getFechaNacimiento()
{
    return _fechaDeNacimiento;
}
bool jugador::getEliminado()
{
    return _eliminado;
}



std::string jugador::leerRegistro()
{
    std::string str = "";

    str = to_string(_dni) + ",";
    str += to_string(_codigoClub) + ",";
    str += string(_apellido) + ",";
    str += string(_nombre) + ",";
    str += string(_telefono) + ",";
    str += string(_email) + ",";
    str += _fechaDeNacimiento.toString() + ",";
    str += to_string(_eliminado);
    return str;
}

void jugador::mostrarEnColumna()
{
    std::cout << std::left
              << std::setw(10) << _jugadorID
              << std::setw(15) << _dni
              << std::setw(12) << _codigoClub
              << std::setw(25) << _nombre
              << std::setw(25) << _apellido
              << std::setw(25) << _telefono
              << std::setw(25) << _email
              << std::setw(25) << _fechaDeNacimiento.toString()
              << std::endl<<endl;
}

void jugador::encabezados()
{
    std::cout << std::left
              << std::setw(10) << "ID"
              << std::setw(15) << "DNI"
              << std::setw(12) << "CodClub"
              << std::setw(25) << "Nombre"
              << std::setw(25) << "Apellido"
              << std::setw(25) << "Telefono"
              << std::setw(25) << "Email"
              << std::setw(25) << "F. Nacim."
              << std::endl;

    std::cout << std::string(130, '-') << std::endl;
}

