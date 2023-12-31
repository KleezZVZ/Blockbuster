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
        cout<<"Bienvenido al programa de rentas de peliculas online de Blockbuster. A continuacion se le dara sus opciones:\n1)Consulta de peliculas.\n2)Buscador de peliculas.\n3)Rentar una pelicula.\n4)Agregar o eliminar peliculas.\n5)Clientes.\n6)Salir del programa.\nElija su opcion: "; cin>>flag;
        system("cls");
        switch(flag){
            case 1:
            menu_1();
            system("pause");
            system("cls");
            break;
            case 2:
            cout<<"Sin implementar"<<endl;
            system("pause");
            system("cls");
            break;
            case 3:
            menu_3();
            system("pause");
            system("cls");
            break;
            case 4:
            menu_4();
            system("pause");
            system("cls");
            break;
            case 5:
            menu_5();
            system("pause");
            system("cls");
            break;
            case 6:
            cout<<"Muchas gracias por su confianza, vuelva pronto!"<<endl;
            subir_informacion();
            break;
            default:
            cout<<"Elija una opcion valida"<<endl;
            system("pause");
            system("cls");
        }
    }while(flag!=6);
}
void menu_1(){
    int option;
    cout<<"Bienvenido a la seccion de consultas de peliculas, a continuacion se le dira sus opciones:\n1)Consulta por id.\n2)Consultar peliculas rentadas.\n3)Consultar peliculas no rentadas.\nElija su opcion: "; cin>>option;
    system("cls");
    switch(option){
        case 1:
        menu_1_1();
        break;
        case 2:
        menu_1_2();
        break;
        case 3:
        menu_1_3();
        break;
        defaut:
        cout<<"No ingreso una opcion valida";
    }
}
void menu_1_1(){
    int consulta_peliculas, id;
    cout<<"Bienvenido a la seccion de consultas por id de peliculas de Blockbuster.\nSe le recomienda de antemano tener la id de las peliculas a buscar ya anotadas, en caso contrario se le sugiere ir a la seccion de buscador de peliculas para encontrar las id.\nIngrese la cantidad de peliculas a consultar: "; cin>>consulta_peliculas;
    system("cls");
    crear_arreglo_dinamico(consulta_peliculas);
    for(int i=0; i<consulta_peliculas; i++){
        cout<<i+1<<"-Ingrese el id de la pelicula: "; cin>>id;
        llenar_arreglo_dinamico(id, i);
    }
    system("cls");
    mostrar_peliculas(consulta_peliculas);
}
void menu_1_2(){
    cout<<"Bienvenido/a, a continuacion se le hara una lista con las peliculas ya rentadas, solo id y nombre, para consultar mas informacion, vaya a las consultas por id."<<endl;
    system("pause");
    system("cls");
    mostrar_peliculas_rentadas();
}
void menu_1_3(){
    cout<<"Bienvenido/a, a continuacion se le hara una lista con las peliculas que no estan rentadas, solo id y nombre, para consultar mas informacion, vaya a las consultas por id."<<endl;
    system("pause");
    system("cls");
    mostrar_peliculas_no_rentadas();
}
void menu_5(){
    int flag;
    cout<<"Bienvenido a la seccion orientada a los clientes, a continuacion se le dara sus opciones:\n1)Registrarse.\n2)Busqueda de cliente.\n3)Ver peliculas rentadas por un mismo cliente.\n4)Eliminar registro de cliente.\nElija su opcion: "; cin>>flag;
    system("cls");
    switch(flag){
        case 1:
        menu_5_1();
        break;
        case 2:
        menu_5_2();
        break;
        case 3:
        menu_5_3();
        break;
        case 4:
        menu_5_4();
        break;
        default:
        cout<<"No ingreso una opcion valida"<<endl;
    }
}
void menu_5_1(){
    int ci;
    string cliente, telefono;
    cout<<"Bienvenido a la seccion de registro, los requisitos para poder registrarse son los siguientes: Su nombre y apellido, y su cedula de identidad.\nPor favor, ingrese su cedula: "; cin>>ci;
    system("cls");
    rewind(stdin);
    cout<<"Ingrese su nombre y apellido: "; getline(cin, cliente);
    system("cls");
    rewind(stdin);
    cout<<"Ingrese su numero de telefono: "; getline(cin, telefono);
    system("cls");
    rewind(stdin);
    crear_cliente(ci, cliente, telefono);
    cout<<"Su registro ha sido realizado con exito!"<<endl;
}
void menu_5_2(){
    int option, ci, search_ci;
    string name, cliente, telefono, search_tlf;
    cout<<"Bienvenido a la seccion de busqueda de cliente. Aqui podra verificar si su registro fue exitoso y usted esta registrado en nuestro sistema.\nSeleccione que campo va a buscar, cedula [1], nombre y apellido [2] o telefono [3]:  "; cin>>option;
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
    }else if(option==3){
        rewind(stdin);
        cout<<"Ingrese su numero de telefono: "; getline(cin, telefono);
        system("cls");
        search_tlf=busqueda_tlf(telefono);
        if(search_tlf=="-1"){
            cout<<"No se ha encontrado el telefono perteneciente al usuario ingresado. Compruebe que lo haya ingresado bien, o registrese para poder disfrutar de nuestras peliculas!"<<endl;
        }else{
            cout<<"El numero de telefono ingresado ha sido encontrado con exito, y le pertenece al cliente: "<<search_tlf<<endl;
        }
    }else{
        cout<<"No ingreso una opcion valida"<<endl;
    }
}
void menu_3(){
    int option, search_ci, verificacion, search_id;
    string search_cliente, pelicula;
    cout<<"Bienvenido a la seccion de rentas de Blockbuster, a continuacion se les dara las siguientes opciones:\n1)Rentar una pelicula.\n2)Consultar el estado de una pelicula.\nElija una opcion: "; cin>>option;
    system("cls");
    if(option==1){
        cout<<"Bienvenido al sistema de rentas de Blockbuster. Previo a rentar una pelicula, necesita iniciar sesion.\nIngrese su numero de cedula: "; cin>>search_ci;
        rewind(stdin);
        system("cls");
        cout<<"Ingrese su nombre y apellido: "; getline(cin, search_cliente);
        rewind(stdin);
        system("cls");
        verificacion=inicio_sesion(search_ci, search_cliente);
        if(verificacion==1){
            cout<<"Bienvenido/a, por favor ingrese el id de la pelicula a rentar: "; cin>>search_id;
            system("cls");
            pelicula=rentar_pelicula(search_cliente, search_id);
            if(pelicula=="-1"){
                cout<<"Lo sentimos, no pudo rentar esta pelicula, debido a que otro cliente ya la tiene rentada"<<endl;
            }else if(pelicula=="-2"){
                cout<<"Usted no puede rentar mas peliculas, porque tiene uno o mas peliculas que ya caduco la fecha de entrega. Hasta que no devuelva las peliculas previamente rentadas, no podra rentar mas."<<endl;
            }else{
                cout<<"La renta ha sido llevado con exito!, la pelicula que usted rento es: "<<pelicula<<". Tiene 14 dias para devolverla."<<endl;
            }
        }else{
            cout<<"Los datos ingresados no coinciden. Por favor, ingrese bien sus datos, o en caso contrario, registrese en nuestro sistema."<<endl;
        }
    }else if(option==2){
        cout<<"Ingrese la id de la pelicula a verificar su disponibilidad: "; cin>>search_id;
        system("cls");
        consulta_peliculas(search_id);
    }
}
void menu_4(){
    int option;
    cout<<"A continuacion, se le dira sus opciones:\n1)Agregar peliculas.\n2)Eliminar peliculas.\nElija una opcion: "; cin>>option;
    system("cls");
    switch(option){
        case 1:
        menu_4_1();
        break;
        case 2:
        menu_4_2();
        break;
        default:
        cout<<"No ingreso una opcion valida."<<endl;
    }
}
void menu_4_1(){
    string nombre, genero, director, fecha_de_lanzamiento;
    int duracion, cantidad;
    cout<<"Bienvenido a la seccion de agregar peliculas de Blockbuster.\nPara poder agregar una pelicula le pediremos los siguientes datos:\n1)Nombre de la pelicula.\n2)Genero de la pelicula.\n3)Duracion de la pelicula.\n4)Director de la pelicula.\n5)Fecha de lanzamiento de la pelicula."<<endl;
    system("pause");
    system("cls");
    rewind(stdin);
    cout<<"Ingrese el nombre de la pelicula: "; getline(cin, nombre);
    rewind(stdin);
    system("cls");
    cout<<"Ingrese el genero de la pelicula: "; getline(cin, genero);
    rewind(stdin);
    system("cls");
    cout<<"Ingrese la duracion de la pelicula: "; cin>>duracion;
    rewind(stdin);
    system("cls");
    cout<<"Ingrese el director de la pelicula: "; getline(cin, director);
    rewind(stdin);
    system("cls");
    cout<<"Ingrese la fecha de lanzamiento de la pelicula (en el formato yy-mm-dd): "; getline(cin, fecha_de_lanzamiento);
    rewind(stdin);
    system("cls");
    cantidad=agregar_pelicula(nombre,genero,duracion,director,fecha_de_lanzamiento);
    cout<<"Su registro se ha llevado con exito! Usted ha agregado la pelicula numero: "<<cantidad<<endl;
}
void menu_4_2(){
    string name;
    int ci, verificacion, search_id, contador;
    cout<<"Bienvenido/a, a la seccion de eliminar peliculas de Blockbuster. Primero debemos confirmar que usted es un cliente registrado en nuestro sistema, por favor, inicie sesion."<<endl;
    rewind(stdin);
    system("pause");
    system("cls");
    cout<<"Ingrese su nombre y apellido: "; getline(cin, name);
    rewind(stdin);
    system("cls");
    cout<<"Ingrese su numero de cedula: "; cin>>ci;
    rewind(stdin);
    system("cls");
    verificacion=inicio_sesion(ci, name);
    if(verificacion==1){
        cout<<"Ingrese el id de la pelicula a eliminar: "; cin>>search_id;
        system("cls");
        contador=eliminar_pelicula(search_id);
        if(contador==-1){
            cout<<"La pelicula no se puede eliminar, porque actualmente se encuentra rentada."<<endl;
        }else{
            cout<<"La pelicula ha sido eliminada con exito."<<endl;
        }
    }else{
        cout<<"Los datos ingresados no coinciden. Por favor, ingrese bien sus datos, o en caso contrario, registrese en nuestro sistema."<<endl;
    }
}
void menu_5_3(){
    string name;
    int ci, verificacion;
    cout<<"Bienvenido/a, a la seccion donde podra ver todas las peliculas rentadas por un mismo cliente.\nPrimero, debe iniciar sesion, antes de ver las peliculas rentadas."<<endl;
    rewind(stdin);
    system("pause");
    system("cls");
    cout<<"Ingrese su nombre y apellido: "; getline(cin, name);
    rewind(stdin);
    system("cls");
    cout<<"Ingrese su numero de cedula: "; cin>>ci;
    rewind(stdin);
    system("cls");
    verificacion=inicio_sesion(ci, name);
    if(verificacion==1){
        cout<<"A continuacion, todas las peliculas rentadas por usted, "<<name<<endl;
        peliculas_por_cliente(name);
    }else{
        cout<<"Los datos ingresados no coinciden. Por favor, ingrese bien sus datos, o en caso contrario, registrese en nuestro sistema."<<endl;
    }
}
void menu_5_4(){
    string name;
    int ci, verificacion;
    cout<<"Lamentamos mucho que quiera eliminar su registro como cliente de Blockbuster, para eliminar su informacion de nuestro sistema, primero debe iniciar sesion."<<endl;
    rewind(stdin);
    system("pause");
    system("cls");
    cout<<"Ingrese su nombre y apellido: "; getline(cin, name);
    rewind(stdin);
    system("cls");
    cout<<"Ingrese su numero de cedula: "; cin>>ci;
    rewind(stdin);
    system("cls");
    verificacion=inicio_sesion(ci, name);
    if(verificacion==1){
        eliminar_cliente(ci);
        cout<<"Se ha eliminado su registro exitosamente."<<endl;
    }else{
        cout<<"Los datos ingresados no coinciden. Por favor, ingrese bien sus datos, o en caso contrario, registrese en nuestro sistema."<<endl;
    }
}