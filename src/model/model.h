#ifndef MODEL_H
#define MODEL_H
#include <string>
    extern struct Peliculas{
        int id, duracion;
        std::string nombre, genero, director, fecha_de_salida, rent_to, rent_on, estado, rent_back;
    }pelicula[2000];
    extern struct Clientes{
        std::string nombre;
        int ci;
    }cliente[100];
#endif