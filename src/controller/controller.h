#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
    void cargar_estructura();
    void cargar_estado_de_renta();
    void cargar_clientes();
    void crear_arreglo_dinamico(int );
    void llenar_arreglo_dinamico(int, int );
    void mostrar_peliculas(int );
    void crear_cliente(int, std::string, std::string);
    std::string busqueda_ci(int );
    int busqueda_cliente(std::string);
    std::string busqueda_tlf(std::string);
    int inicio_sesion(int, std::string);
    std::string rentar_pelicula(std::string, int);
    void consulta_peliculas(int );
    int agregar_pelicula(std::string, std::string, int, std::string, std::string);
    void subir_informacion();
    void peliculas_por_cliente(std::string);
    void eliminar_cliente(int);
#endif