#include "jugador.h"

#include <cstring>


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
    strcpy(_nombre, "");
}
void jugador::setApellido(std::string apellido)
{
    strcpy(_apellido, "");
}
void jugador::setTelefono(std::string telefono)
{
    strcpy(_telefono, "");
}
void jugador::setEmail(std::string email)
{
    strcpy(_email, "");
}
void jugador::setFechaNacimiento(std::string fechaNacimiento)
{
    strcpy(_fechaNacimiento, "");
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
