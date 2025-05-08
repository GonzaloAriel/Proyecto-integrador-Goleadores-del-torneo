#include "jugador.h"
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>

using namespace std;

jugador::jugador()
{
    _dni = 0;
    _codigoClub = 0;
    strcpy(_apellido, "");
    strcpy(_nombre, "");
    strcpy(_telefono, "");
    strcpy(_email, "");
    strcpy(_fechaNacimiento, "");
}

jugador::jugador(int dni, int codigoClub, std::string nombre, std::string apellido,
                 std::string telefono, std::string email, std::string fechaNacimiento)
{
    setDni(dni);
    setCodigoClub(codigoClub);
    setNombre(nombre);
    setApellido(apellido);
    setTelefono(telefono);
    setEmail(email);
    setFechaNacimiento(fechaNacimiento);
}

//Setter:
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
void jugador::setFechaNacimiento(std::string fechaNacimiento)
{
    strcpy(_fechaNacimiento, fechaNacimiento.c_str());
}


//Getter:
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
std::string jugador::getFechaNacimiento()
{
    return _fechaNacimiento;
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
    str += string(_fechaNacimiento);

    return str;
}

void jugador::mostrarEnColumna()
{
    std::cout << std::left
              << std::setw(10) << _dni
              << std::setw(12) << _codigoClub
              << std::setw(15) << _nombre
              << std::setw(15) << _apellido
              << std::setw(15) << _telefono
              << std::setw(25) << _email
              << std::setw(15) << _fechaNacimiento
              << std::endl<<endl;
}

void jugador::encabezados()
{
    std::cout << std::left
              << std::setw(10) << "DNI"
              << std::setw(12) << "CodClub"
              << std::setw(15) << "Nombre"
              << std::setw(15) << "Apellido"
              << std::setw(15) << "Teléfono"
              << std::setw(25) << "Email"
              << std::setw(15) << "F. Nacim."
              << std::endl;

    std::cout << std::string(107, '-') << std::endl;
}

