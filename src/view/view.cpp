#include <iostream>
#include "view.h"
#include "../controller/controller.h"
using namespace std;
void menu_principal(){
     int flag;
     cargar_estructura();
     cargar_estado_de_renta();
     cargar_clientes();
    do{
        cout<<"Bienvenido al programa de rentas de peliculas online de Blockbuster. A continuacion se le dara sus opciones:\n1)Consulta de peliculas.\n2)Buscador de peliculas.\n3)Rentar una pelicula.\n4)Agregar peliculas.\n5)Registrar cliente.\n6)Salir del programa.\nElija su opcion: "; cin>>flag;
        system("cls");
        switch(flag){
            case 1:
            menu_1();
            system("pause");
            system("cls");
            break;
        }
    }while(flag!=6);
}
void menu_1(){
    int consulta_peliculas, id;
    cout<<"Bienvenido a la seccion de consultas de peliculas de Blockbuster.\nSe le recomienda de antemano tener la id de las peliculas a buscar ya anotadas, en caso contrario se le sugiere ir a la seccion de buscador de peliculas para encontrar las id.\nIngrese la cantidad de peliculas a consultar: "; cin>>consulta_peliculas;
    system("cls");
    crear_arreglo_dinamico(consulta_peliculas);
    for(int i=0; i<consulta_peliculas; i++){
        cout<<i+1<<"-Ingrese el id de la pelicula: "; cin>>id;
        llenar_arreglo_dinamico(id, i);
    }
    system("cls");
    mostrar_peliculas(consulta_peliculas);
}