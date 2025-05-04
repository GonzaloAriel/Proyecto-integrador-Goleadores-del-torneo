#include "jugador.h"

#include <cstring>
#include <string>

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
