#pragma once
#include <string>

class jugador
{
private:
    int  _dni;
    int  _codigoClub;
    char _nombre [50];
    char _apellido [50];
    char _telefono [50];
    char _email [60];
    char _fechaNacimiento [30];

public:
    jugador();

    jugador(int dni, int codigoClub, std::string nombre, std::string apellido,
            std::string telefono, std::string email, std::string fechaNacimiento);

            void setDni(int dni);
            void setCodigoClub (int codigoClub);
            void setNombre(std::string nombre);
            void setApellido(std::string apellido);
            void setTelefono(std::string telefono);
            void setEmail(std::string email);
            void setFechaNacimiento(std::string fechaNacimiento);

            int getDni();
            int getCodigoClub ();
            std::string getNombre();
            std::string getApellido();
            std::string getTelefono();
            std::string getEmail();
            std::string getFechaNacimiento();

            std::string leerRegistro();

            void encabezados();
            void mostrarEnColumna();
};
