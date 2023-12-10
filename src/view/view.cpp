#include <iostream>
#include <string>
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
            case 5:
            menu_5();
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
void menu_5(){
    int flag;
    cout<<"Bienvenido a la seccion de registro de clientes, a continuacion se le dara sus opciones:\n1)Registrarse.\n2)Busqueda de cliente.\nElija su opcion: "; cin>>flag;
    system("cls");
    switch(flag){
        case 1:
        menu_5_1();
        break;
        case 2:
        menu_5_2();
        break;
        default:
        cout<<"No ingreso una opcion valida"<<endl;
    }
}
void menu_5_1(){
    int ci;
    string cliente;
    cout<<"Bienvenido a la seccion de registro, los requisitos para poder registrarse son los siguientes: Su nombre y apellido, y su cedula de identidad.\nPor favor, ingrese su cedula: "; cin>>ci;
    system("cls");
    rewind(stdin);
    cout<<"Ingrese su nombre y apellido: "; getline(cin, cliente);
    system("cls");
    rewind(stdin);
    crear_cliente(ci, cliente);
    cout<<"Su registro ha sido realizado con exito!";
    system("cls");
}
void menu_5_2(){
    int option, ci, search_ci;
    string name, cliente;
    cout<<"Bienvenido a la seccion de busqueda de cliente. Aqui podra verificar si su registro fue exitoso y usted esta registrado en nuestro sistema.\nSeleccione que campo va a buscar, cedula [1] o nombre y apellido [2]:  "; cin>>option;
    system("cls");
    if(option==1){
        cout<<"Ingrese su numero de cedula: "; cin>>ci;
        system("cls");
        name=busqueda_ci(ci);
        if(name=="-1"){
            cout<<"No se ha encontrado al usuario perteneciente a ese numero de cedula. Compruebe que lo haya ingresado bien, o registrese para poder disfrutar de nuestras peliculas!"<<endl;
        }else{
            cout<<"Usuario perteneciente al numero de cedula ingresado: "<<name<<". Usted ha sido encontrado con exito!"<<endl;
        }
    }else if(option==2){
        rewind(stdin);
        cout<<"Ingrese su nombre y apellido: "; getline(cin, cliente);
        system("cls");
        search_ci=busqueda_cliente(cliente);
        if(search_ci==-1){
            cout<<"No se ha encontrado la cedula perteneciente al usuario ingresado. Compruebe que lo haya ingresado bien, o registrese para poder disfrutar de nuestras peliculas!"<<endl;
        }else{
            cout<<"La cedula perteneciente al usuario ingresado es: "<<search_ci<<". Usted ha sido encontrado con exito!"<<endl;
        }
    }else{
        cout<<"No ingreso una opcion valida"<<endl;
    }
}