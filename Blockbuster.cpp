#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;
struct Peliculas{
    int id, duracion;
    string nombre, genero, director, fecha_de_salida, rent_to, rent_on, estado, rent_back;
};
struct Clientes{
    string nombre;
    int ci;
};
int flag=0, consulta_peliculas, search_id[1000], numero_de_clientes=0, search_ci, search_cliente_2=1000, orden;
string search_cliente;
int main(){
    string line, word;
    int count=0, nline=0;
    Peliculas pelicula[2000];
    Clientes cliente[100];
    ifstream in_file ("movies.csv", ifstream::in);
    if(!in_file.is_open()){
        cout<<"Archivo no encontrado"<<endl;
        system("pause");
        return 0;
    }
    while(getline(in_file, line)){
        stringstream str(line);
        while(getline(str, word, ',')){
            switch(count){
                case 0: pelicula[nline].id=stoi(word); break;
                case 1: pelicula[nline].nombre=word; break;
                case 2: pelicula[nline].genero=word; break;
                case 3: pelicula[nline].duracion=stoi(word); break;
                case 4: pelicula[nline].director=word; break;
                case 5: pelicula[nline].fecha_de_salida=word; break;
                case 6: pelicula[nline].rent_to=word; break;
                case 7: pelicula[nline].rent_on=word; break;
                case 8: pelicula[nline].estado=word; break;
                case 9: pelicula[nline].rent_back=word; break;
            }
            count++;
        }
        count=0;
        nline++;
    }
    in_file.close();
    for(int i=0; i<nline; i++){
        if(pelicula[i].rent_on.compare(pelicula[i].rent_back)<0 && pelicula[i].rent_to.length()!=0){
            pelicula[i].estado="Rentado";
        }else if(pelicula[i].rent_on.compare(pelicula[i].rent_back)>0){
            pelicula[i].estado="Entrega atrasada";
        }
    }
    fstream file_bin ("clientes.bin", fstream::in | fstream::binary);
    if(!file_bin.is_open()){
        cout<<"Archivo no encontrado"<<endl;
        system("pause");
        return 0;
    }
    while(getline(file_bin, line)){
        stringstream str(line);
        while(getline(str, word, '|')){
            switch(count){
                case 0: cliente[numero_de_clientes].ci=stoi(word);
                case 1: cliente[numero_de_clientes].nombre=word;
            }
            count++;
        }
        count=0;
        numero_de_clientes++;
    }
    file_bin.close();
    do{
        cout<<"Bienvenido al programa de rentas de peliculas online de Blockbuster. A continuacion se le dara sus opciones:\n1)Consulta de peliculas.\n2)Buscador de peliculas.\n3)Rentar una pelicula.\n4)Agregar peliculas.\n5)Registrar cliente.\n6)Salir del programa.\nElija su opcion: "; cin>>flag;
        system("cls");
        switch(flag){
            case 1:
            cout<<"Bienvenido a la seccion de consultas de peliculas de Blockbuster.\nSe le recomienda de antemano tener la id de las peliculas a buscar ya anotadas, en caso contrario se le sugiere ir a la seccion de buscador de peliculas para encontrar las id.\nIngrese la cantidad de peliculas a consultar: "; cin>>consulta_peliculas;
            system("cls");
            for(int i=0; i<consulta_peliculas; i++){
                rewind(stdin);
                cout<<i+1<<"-Ingrese la id de la pelicula: "; cin>>search_id[i];
            }
            system("pause");
            system("cls");
            for(int i=0; i<consulta_peliculas; i++){
                cout<<i+1<<"-Nombre de la pelicula: "<<pelicula[search_id[i]-1].nombre<<endl;
                cout<<i+1<<"-Genero de la pelicula: "<<pelicula[search_id[i]-1].genero<<endl;
                cout<<i+1<<"-Duracion de la pelicula: "<<pelicula[search_id[i]-1].duracion<<endl;
                cout<<i+1<<"-Director de la pelicula: "<<pelicula[search_id[i]-1].director<<endl;
                cout<<i+1<<"-Fecha de salida de la pelicula: "<<pelicula[search_id[i]-1].fecha_de_salida<<endl;
            }
            system("pause");
            system("cls");
            break;
            case 2:
                do{
                    cout<<"Bienvenido a la seccion de busqueda de peliculas de Blockbuster.\nLa finalidad de esta seccion, es poder facilitarle a usted la id de una pelicula que le guste, para luego poder consultarla posteriormente.\nPara lograr este cometido, le ofrecemos varias metodos de filtrar las peliculas y poder buscarlas segun lo que elija, y son los siguientes:\n1)Genero de la pelicula.\n2)Duracion de la pelicula.\n3)Director de la pelicula.\n4)Fecha de lanzamiento de la pelicula.\nElija su opcion: "; cin>>flag;
                    system("cls");
                    switch(flag){
                        case 1:
                            for(int i=0; i<nline; i++){
                                int pos=i;
                                int aux=pelicula[i].id; string aux_2=pelicula[i].nombre; string aux_3=pelicula[i].genero; int aux_4=pelicula[i].duracion; string aux_5=pelicula[i].director; string aux_6=pelicula[i].fecha_de_salida; string aux_7=pelicula[i].rent_to; string aux_8=pelicula[i].rent_on; string aux_9=pelicula[i].estado; string aux_10=pelicula[i].rent_back;
                                
                                while(pos>0 && pelicula[pos-1].genero.compare(aux_3)>0){
                                    pelicula[pos].id=pelicula[pos-1].id;
                                    pelicula[pos].nombre=pelicula[pos-1].nombre;
                                    pelicula[pos].genero=pelicula[pos-1].genero;
                                    pelicula[pos].duracion=pelicula[pos-1].duracion;
                                    pelicula[pos].director=pelicula[pos-1].director;
                                    pelicula[pos].fecha_de_salida=pelicula[pos-1].fecha_de_salida;
                                    pelicula[pos].rent_to=pelicula[pos-1].rent_to;
                                    pelicula[pos].rent_on=pelicula[pos-1].rent_on;
                                    pelicula[pos].estado=pelicula[pos-1].estado;
                                    pelicula[pos].rent_back=pelicula[pos-1].rent_back;
                                    pos--;
                                }
                                pelicula[pos].id=aux;
                                pelicula[pos].nombre=aux_2;
                                pelicula[pos].genero=aux_3;
                                pelicula[pos].duracion=aux_4;
                                pelicula[pos].director=aux_5;
                                pelicula[pos].fecha_de_salida=aux_6;
                                pelicula[pos].rent_to=aux_7;
                                pelicula[pos].rent_on=aux_8;
                                pelicula[pos].estado=aux_9;
                                pelicula[pos].rent_back=aux_10;
                            }
                            cout<<"Ingrese la cantidad de peliculas a visualizar: "; cin>>consulta_peliculas;
                            system("cls");
                            cout<<"Elija el orden a visualizar las peliculas.\n1)Ascendente(A->Z).\n2)Descendente(Z->A)\nElija la opcion: "; cin>>orden;
                            system("cls");
                            if(orden==1){
                                for(int i=0; i<consulta_peliculas; i++){
                                    cout<<i+1<<"-El genero de la pelicula es: "<<pelicula[i].genero<<endl;
                                    cout<<i+1<<"-El nombre de la pelicula es: "<<pelicula[i].nombre<<endl;
                                    cout<<i+1<<"-El id de la pelicula es: "<<pelicula[i].id<<endl;
                                    if((i+1)%10==0){
                                        system("pause");
                                        system("cls");
                                    }
                                }
                                system("pause");
                                system("cls");
                            }else if(orden==2){
                                count=1;
                                for(int i=nline-1; i>=nline-consulta_peliculas; i--){
                                    cout<<count<<"-El genero de la pelicula es: "<<pelicula[i].genero<<endl;
                                    cout<<count<<"-El nombre de la pelicula es: "<<pelicula[i].nombre<<endl;
                                    cout<<count<<"-El id de la pelicula es: "<<pelicula[i].id<<endl;
                                    if((count)%10==0){
                                        system("pause");
                                        system("cls");
                                    }
                                    count++;
                                }
                                count=0;
                                system("pause");
                                system("cls");
                            }else{
                                cout<<"Por favor, ingrese una opcion valida."<<endl;
                                system("pause");
                                system("cls");
                            }
                            break;
                            case 2:
                                for(int i=0; i<nline; i++){
                                    int pos=i;
                                    int aux=pelicula[i].id; string aux_2=pelicula[i].nombre; string aux_3=pelicula[i].genero; int aux_4=pelicula[i].duracion; string aux_5=pelicula[i].director; string aux_6=pelicula[i].fecha_de_salida; string aux_7=pelicula[i].rent_to; string aux_8=pelicula[i].rent_on; string aux_9=pelicula[i].estado; string aux_10=pelicula[i].rent_back;
                                    
                                    while(pos>0 && pelicula[pos-1].duracion>aux_4){
                                        pelicula[pos].id=pelicula[pos-1].id;
                                        pelicula[pos].nombre=pelicula[pos-1].nombre;
                                        pelicula[pos].genero=pelicula[pos-1].genero;
                                        pelicula[pos].duracion=pelicula[pos-1].duracion;
                                        pelicula[pos].director=pelicula[pos-1].director;
                                        pelicula[pos].fecha_de_salida=pelicula[pos-1].fecha_de_salida;
                                        pelicula[pos].rent_to=pelicula[pos-1].rent_to;
                                        pelicula[pos].rent_on=pelicula[pos-1].rent_on;
                                        pelicula[pos].estado=pelicula[pos-1].estado;
                                        pelicula[pos].rent_back=pelicula[pos-1].rent_back;
                                        pos--;
                                    }
                                    pelicula[pos].id=aux;
                                    pelicula[pos].nombre=aux_2;
                                    pelicula[pos].genero=aux_3;
                                    pelicula[pos].duracion=aux_4;
                                    pelicula[pos].director=aux_5;
                                    pelicula[pos].fecha_de_salida=aux_6;
                                    pelicula[pos].rent_to=aux_7;
                                    pelicula[pos].rent_on=aux_8;
                                    pelicula[pos].estado=aux_9;
                                    pelicula[pos].rent_back=aux_10;
                                }
                                cout<<"Ingrese la cantidad de peliculas a visualizar: "; cin>>consulta_peliculas;
                                system("cls");
                                cout<<"Elija el orden a visualizar las peliculas.\n1)Ascendente(0->n).\n2)Descendente(n->0)\nElija la opcion: "; cin>>orden;
                                system("cls");
                                if(orden==1){
                                    for(int i=0; i<consulta_peliculas; i++){
                                        cout<<i+1<<"-La duracion de la pelicula es: "<<pelicula[i].duracion<<endl;
                                        cout<<i+1<<"-El nombre de la pelicula es: "<<pelicula[i].nombre<<endl;
                                        cout<<i+1<<"-El id de la pelicula es: "<<pelicula[i].id<<endl;
                                        if((i+1)%10==0){
                                            system("pause");
                                            system("cls");
                                        }
                                    }
                                    system("pause");
                                    system("cls");
                                }else if(orden==2){
                                    count=1;
                                    for(int i=nline-1; i>=nline-consulta_peliculas; i--){
                                        cout<<count<<"-La duracion de la pelicula es: "<<pelicula[i].duracion<<endl;
                                        cout<<count<<"-El nombre de la pelicula es: "<<pelicula[i].nombre<<endl;
                                        cout<<count<<"-El id de la pelicula es: "<<pelicula[i].id<<endl;
                                        if((count)%10==0){
                                            system("pause");
                                            system("cls");
                                        }
                                        count++;
                                    }
                                    count=0;
                                    system("pause");
                                    system("cls");
                                }else{
                                    cout<<"Por favor, ingrese una opcion valida."<<endl;
                                    system("pause");
                                    system("cls");
                                }
                                break;
                            case 3:
                                for(int i=0; i<nline; i++){
                                    int pos=i;
                                    int aux=pelicula[i].id; string aux_2=pelicula[i].nombre; string aux_3=pelicula[i].genero; int aux_4=pelicula[i].duracion; string aux_5=pelicula[i].director; string aux_6=pelicula[i].fecha_de_salida; string aux_7=pelicula[i].rent_to; string aux_8=pelicula[i].rent_on; string aux_9=pelicula[i].estado; string aux_10=pelicula[i].rent_back;
                                    while(pos>0 && pelicula[pos-1].director.compare(aux_5)>0){
                                        pelicula[pos].id=pelicula[pos-1].id;
                                        pelicula[pos].nombre=pelicula[pos-1].nombre;
                                        pelicula[pos].genero=pelicula[pos-1].genero;
                                        pelicula[pos].duracion=pelicula[pos-1].duracion;
                                        pelicula[pos].director=pelicula[pos-1].director;
                                        pelicula[pos].fecha_de_salida=pelicula[pos-1].fecha_de_salida;
                                        pelicula[pos].rent_to=pelicula[pos-1].rent_to;
                                        pelicula[pos].rent_on=pelicula[pos-1].rent_on;
                                        pelicula[pos].estado=pelicula[pos-1].estado;
                                        pelicula[pos].rent_back=pelicula[pos-1].rent_back;
                                        pos--;
                                    }
                                    pelicula[pos].id=aux;
                                    pelicula[pos].nombre=aux_2;
                                    pelicula[pos].genero=aux_3;
                                    pelicula[pos].duracion=aux_4;
                                    pelicula[pos].director=aux_5;
                                    pelicula[pos].fecha_de_salida=aux_6;
                                    pelicula[pos].rent_to=aux_7;
                                    pelicula[pos].rent_on=aux_8;
                                    pelicula[pos].estado=aux_9;
                                    pelicula[pos].rent_back=aux_10;
                                }
                                cout<<"Ingrese la cantidad de peliculas a visualizar: "; cin>>consulta_peliculas;
                                system("cls");
                                cout<<"Elija el orden a visualizar las peliculas.\n1)Ascendente(A->Z).\n2)Descendente(Z->A)\nElija la opcion: "; cin>>orden;
                                system("cls");
                                if(orden==1){
                                    for(int i=0; i<consulta_peliculas; i++){
                                        cout<<i+1<<"-El director de la pelicula es: "<<pelicula[i].director<<endl;
                                        cout<<i+1<<"-El nombre de la pelicula es: "<<pelicula[i].nombre<<endl;
                                        cout<<i+1<<"-El id de la pelicula es: "<<pelicula[i].id<<endl;
                                        if((i+1)%10==0){
                                            system("pause");
                                            system("cls");
                                        }
                                    }
                                    system("pause");
                                    system("cls");
                                }else if(orden==2){
                                    count=1;
                                    for(int i=nline-1; i>=nline-consulta_peliculas; i--){
                                        cout<<count<<"-El director de la pelicula es: "<<pelicula[i].director<<endl;
                                        cout<<count<<"-El nombre de la pelicula es: "<<pelicula[i].nombre<<endl;
                                        cout<<count<<"-El id de la pelicula es: "<<pelicula[i].id<<endl;
                                        if((count)%10==0){
                                            system("pause");
                                            system("cls");
                                        }
                                        count++;
                                    }
                                    count=0;
                                    system("pause");
                                    system("cls");
                                }else{
                                    cout<<"Por favor, ingrese una opcion valida."<<endl;
                                    system("pause");
                                    system("cls");
                                }
                                break;
                            case 4:
                                for(int i=0; i<nline; i++){
                                    int pos=i;
                                    int aux=pelicula[i].id; string aux_2=pelicula[i].nombre; string aux_3=pelicula[i].genero; int aux_4=pelicula[i].duracion; string aux_5=pelicula[i].director; string aux_6=pelicula[i].fecha_de_salida; string aux_7=pelicula[i].rent_to; string aux_8=pelicula[i].rent_on; string aux_9=pelicula[i].estado; string aux_10=pelicula[i].rent_back;
                                    
                                    while(pos>0 && pelicula[pos-1].fecha_de_salida.compare(aux_6)>0){
                                        pelicula[pos].id=pelicula[pos-1].id;
                                        pelicula[pos].nombre=pelicula[pos-1].nombre;
                                        pelicula[pos].genero=pelicula[pos-1].genero;
                                        pelicula[pos].duracion=pelicula[pos-1].duracion;
                                        pelicula[pos].director=pelicula[pos-1].director;
                                        pelicula[pos].fecha_de_salida=pelicula[pos-1].fecha_de_salida;
                                        pelicula[pos].rent_to=pelicula[pos-1].rent_to;
                                        pelicula[pos].rent_on=pelicula[pos-1].rent_on;
                                        pelicula[pos].estado=pelicula[pos-1].estado;
                                        pelicula[pos].rent_back=pelicula[pos-1].rent_back;
                                        pos--;
                                    }
                                    pelicula[pos].id=aux;
                                    pelicula[pos].nombre=aux_2;
                                    pelicula[pos].genero=aux_3;
                                    pelicula[pos].duracion=aux_4;
                                    pelicula[pos].director=aux_5;
                                    pelicula[pos].fecha_de_salida=aux_6;
                                    pelicula[pos].rent_to=aux_7;
                                    pelicula[pos].rent_on=aux_8;
                                    pelicula[pos].estado=aux_9;
                                    pelicula[pos].rent_back=aux_10;
                                }
                                cout<<"Ingrese la cantidad de peliculas a visualizar: "; cin>>consulta_peliculas;
                                system("cls");
                                cout<<"Elija el orden a visualizar las peliculas.\n1)Ascendente(0->n).\n2)Descendente(n->0)\nElija la opcion: "; cin>>orden;
                                system("cls");
                                if(orden==1){
                                    for(int i=0; i<consulta_peliculas; i++){
                                        cout<<i+1<<"-La fecha de lanzamiento de la pelicula es: "<<pelicula[i].fecha_de_salida<<endl;
                                        cout<<i+1<<"-El nombre de la pelicula es: "<<pelicula[i].nombre<<endl;
                                        cout<<i+1<<"-El id de la pelicula es: "<<pelicula[i].id<<endl;
                                        if((i+1)%10==0){
                                            system("pause");
                                            system("cls");
                                        }
                                    }
                                    system("pause");
                                    system("cls");
                                }else if(orden==2){
                                    count=1;
                                    for(int i=nline-1; i>=nline-consulta_peliculas; i--){
                                        cout<<count<<"-La fecha de lanzamiento de la pelicula es: "<<pelicula[i].fecha_de_salida<<endl;
                                        cout<<count<<"-El nombre de la pelicula es: "<<pelicula[i].nombre<<endl;
                                        cout<<count<<"-El id de la pelicula es: "<<pelicula[i].id<<endl;
                                        if((count)%10==0){
                                            system("pause");
                                            system("cls");
                                        }
                                        count++;
                                    }
                                    count=0;
                                    system("pause");
                                    system("cls");
                                }else{
                                    cout<<"Por favor, ingrese una opcion valida."<<endl;
                                    system("pause");
                                    system("cls");
                                }
                                break;
                            default:
                                cout<<"No ingreso una opcion valida."<<endl;
                                system("pause");
                                system("cls");
                                break;
                    }
                }while(flag<1 || flag>4);
                for(int i=0; i<nline; i++){
                    int pos=i;
                    int aux=pelicula[i].id; string aux_2=pelicula[i].nombre; string aux_3=pelicula[i].genero; int aux_4=pelicula[i].duracion; string aux_5=pelicula[i].director; string aux_6=pelicula[i].fecha_de_salida; string aux_7=pelicula[i].rent_to; string aux_8=pelicula[i].rent_on; string aux_9=pelicula[i].estado; string aux_10=pelicula[i].rent_back;
                    while(pos>0 && pelicula[pos-1].id>aux){
                        pelicula[pos].id=pelicula[pos-1].id;
                        pelicula[pos].nombre=pelicula[pos-1].nombre;
                        pelicula[pos].genero=pelicula[pos-1].genero;
                        pelicula[pos].duracion=pelicula[pos-1].duracion;
                        pelicula[pos].director=pelicula[pos-1].director;
                        pelicula[pos].fecha_de_salida=pelicula[pos-1].fecha_de_salida;
                        pelicula[pos].rent_to=pelicula[pos-1].rent_to;
                        pelicula[pos].rent_on=pelicula[pos-1].rent_on;
                        pelicula[pos].estado=pelicula[pos-1].estado;
                        pelicula[pos].rent_back=pelicula[pos-1].rent_back;
                        pos--;
                    }
                    pelicula[pos].id=aux;
                    pelicula[pos].nombre=aux_2;
                    pelicula[pos].genero=aux_3;
                    pelicula[pos].duracion=aux_4;
                    pelicula[pos].director=aux_5;
                    pelicula[pos].fecha_de_salida=aux_6;
                    pelicula[pos].rent_to=aux_7;
                    pelicula[pos].rent_on=aux_8;
                    pelicula[pos].estado=aux_9;
                    pelicula[pos].rent_back=aux_10;
                }
            break;
            case 3:
            do{
                cout<<"Bienvenido a la seccion de rentas de Blockbuster, a continuacion se les dara las siguientes opciones:\n1)Rentar una pelicula.\n2)Consultar el estado de una pelicula.\n3)Volver al menu principal.\nElija una opcion: "; cin>>flag;
                system("cls");
                switch(flag){
                    case 1:
                        cout<<"Bienvenido al sistema de rentas de Blockbuster. Previo a rentar una pelicula, necesita iniciar sesion.\nIngrese su numero de cedula: "; cin>>search_ci;
                        rewind(stdin);
                        system("cls");
                        cout<<"Ingrese su nombre y apellido: "; getline(cin, search_cliente);
                        rewind(stdin);
                        system("cls");
                        for(int i=0; i<numero_de_clientes; i++){
                            if(search_ci==cliente[i].ci){
                                search_ci=i;
                                break;
                            }
                        }for(int i=0; i<numero_de_clientes; i++){
                            if(search_cliente==cliente[i].nombre){
                                search_cliente_2=i;
                                break;
                            }
                        }if(search_ci!=search_cliente_2){
                            cout<<"Los datos ingresados no coinciden. Por favor, ingrese bien sus datos, o en caso contrario, registrese en nuestro sistema."<<endl;
                            system("pause");
                            system("cls");
                        }else{
                            cout<<"Bienvenido/a "<<cliente[search_ci].nombre<<", por favor, ingrese la id de la pelicula a rentar: "; cin>>search_id[0];
                            system("cls");
                            time_t ahora= time(0);
                            tm* fecha= localtime(&ahora);
                            char fecha_actual[11];
                            strftime(fecha_actual, sizeof(fecha_actual), "%F", fecha);
                            pelicula[search_id[0]-1].rent_on=fecha_actual;
                            ahora+=14*24*60*60;
                            fecha= localtime(&ahora);
                            char fecha_a_devolver[11];
                            strftime(fecha_a_devolver, sizeof(fecha_a_devolver), "%F", fecha);
                            pelicula[search_id[0]-1].rent_back=fecha_a_devolver;
                            pelicula[search_id[0]-1].estado="Rentado";
                            cout<<"La pelicula que usted eligio es: "<<pelicula[search_id[0]-1].nombre<<".\nUsted tiene 14 dias para devolver la pelicula, hasta la fecha: "<<pelicula[search_id[0]-1].rent_back<<", que disfrute!"<<endl;
                            pelicula[search_id[0]-1].rent_to=cliente[search_ci].nombre;
                            system("pause");
                            system("cls");
                        }
                    break;
                    case 2:
                    cout<<"Ingrese la id de la pelicula a verificar su disponibilidad: "; cin>>consulta_peliculas;
                    system("cls");
                    if(pelicula[consulta_peliculas-1].estado=="Rentado" || pelicula[consulta_peliculas-1].estado=="Entrega atrasada"){
                        cout<<"La pelicula "<<pelicula[consulta_peliculas-1].nombre<<" ya se encuentra rentada por "<<pelicula[consulta_peliculas-1].rent_to<<", lo sentimos"<<endl;
                        system("pause");
                        system("cls");
                    }else{
                        cout<<"La pelicula "<<pelicula[consulta_peliculas-1].nombre<<" se encuentra disponible, vaya a la opcion de rentarla"<<endl;
                        system("pause");
                        system("cls");
                    }
                }
            }while(flag!=3);
            break;
            case 4:{
                cout<<"Bienvenido a la seccion de agregar peliculas de Blockbuster.\nActualmente contamos con "<<nline<<" peliculas.\nPara poder agregar una pelicula le pediremos los siguientes datos:\n1)Nombre de la pelicula.\n2)Genero de la pelicula.\n3)Duracion de la pelicula.\n4)Director de la pelicula.\n5)Fecha de lanzamiento de la pelicula."<<endl;
                system("pause");
                system("cls");
                rewind(stdin);
                cout<<"Ingrese el nombre de la pelicula: "; string new_movie; getline(cin, new_movie);
                rewind(stdin);
                pelicula[nline].nombre=new_movie;
                system("cls");
                cout<<"Ingrese el genero de la pelicula: "; getline(cin, new_movie);
                rewind(stdin);
                pelicula[nline].genero=new_movie;
                system("cls");
                cout<<"Ingrese la duracion de la pelicula: "; getline(cin, new_movie);
                rewind(stdin);
                pelicula[nline].duracion=stoi(new_movie);
                system("cls");
                cout<<"Ingrese el director de la pelicula: "; getline(cin, new_movie);
                rewind(stdin);
                pelicula[nline].director=new_movie;
                system("cls");
                cout<<"Ingrese la fecha de lanzamiento de la pelicula (en el formato yy-mm-dd): "; getline(cin, new_movie);
                rewind(stdin);
                pelicula[nline].fecha_de_salida=new_movie;
                pelicula[nline].id=nline+1;
                system("cls");
                ofstream write_file("movies.csv", ofstream::ios_base::app);
                pelicula[nline].estado="Disponible";
                write_file<<endl<<pelicula[nline].id<<","<<pelicula[nline].nombre<<","<<pelicula[nline].genero<<","<<pelicula[nline].duracion<<","<<pelicula[nline].director<<","<<pelicula[nline].fecha_de_salida<<","<<pelicula[nline].rent_to<<","<<pelicula[nline].rent_on<<","<<pelicula[nline].estado<<","<<pelicula[nline].rent_back;
                nline++;
                cout<<"Su registro se ha llevado con exito! Usted ha agregado la pelicula numero: "<<nline<<endl;
                system("pause");
                system("cls");
                break;
            }
            case 5:{
                do{
                    cout<<"Bienvenido a la seccion de registro de clientes, a continuacion se le dara sus opciones:\n1)Registrarse.\n2)Busqueda de cliente.\n3)Volver al menu principal.\nElija su opcion: "; cin>>flag;
                    system("cls");
                    switch(flag){
                        case 1:{
                            cout<<"Bienvenido a la seccion de registro, los requisitos para poder registrarse son los siguientes: Su nombre y apellido, y su cedula de identidad.\nPor favor, ingrese su cedula: "; cin>>cliente[numero_de_clientes].ci;
                            rewind(stdin);
                            system("cls");
                            cout<<"Ingrese su nombre y apellido: "; getline(cin, cliente[numero_de_clientes].nombre);
                            rewind(stdin);
                            system("cls");
                            fstream write_bin ("clientes.bin", ios_base::app | fstream::binary);
                            write_bin<<cliente[numero_de_clientes].ci<<"|"<<cliente[numero_de_clientes].nombre<<endl;
                            write_bin.close();
                            cout<<"Su registro ha sido completado con exito!, ya puede rentar peliculas de nuestra franquicia."<<endl;
                            numero_de_clientes++;
                            system("pause");
                            system("cls");
                            }break;
                        case 2:
                            cout<<"Bienvenido a la seccion de busqueda de cliente. Aqui podra verificar si su registro fue exitoso y usted esta registrado en nuestro sistema.\nSeleccione que campo va a buscar, cedula [1] o nombre y apellido [2]:  "; cin>>search_ci;
                            system("cls");
                            if(search_ci==1){
                                cout<<"Ingrese su cedula: "; cin>>search_ci;
                                system("cls");
                                for(int i=0; i<numero_de_clientes; i++){
                                    if(search_ci==cliente[i].ci){
                                        cout<<"Usuario perteneciente al numero de cedula ingresado: "<<cliente[i].nombre<<". Usted ha sido encontrado con exito!"<<endl;
                                        system("pause");
                                        system("cls");
                                        break;
                                    }else if(search_ci!=cliente[i].ci && i==numero_de_clientes-1){
                                        cout<<"No se ha encontrado al usuario perteneciente a ese numero de cedula. Compruebe que lo haya ingresado bien, o registrese para poder disfrutar de nuestras peliculas!"<<endl;
                                        system("pause");
                                        system("cls");
                                    }
                                }
                            }else if(search_ci==2){
                                rewind(stdin);
                                cout<<"Ingrese su nombre y apellido: "; getline(cin, search_cliente);
                                system("cls");
                                for(int i=0; i<numero_de_clientes; i++){
                                    if(search_cliente==cliente[i].nombre){
                                        cout<<"La cedula perteneciente al usuario ingresado es: "<<cliente[i].ci<<". Usted ha sido encontrado con exito!"<<endl;
                                        system("pause");
                                        system("cls");
                                        break;
                                    }else if(search_ci!=cliente[i].ci && i==numero_de_clientes-1){
                                        cout<<"No se ha encontrado la cedula perteneciente al usuario ingresado. Compruebe que lo haya ingresado bien, o registrese para poder disfrutar de nuestras peliculas!"<<endl;
                                        system("pause");
                                        system("cls");
                                    }
                                }
                            }else{
                                cout<<"Ingrese una opcion valida"<<endl;
                                system("pause");
                                system("cls");
                            }
                            break;
                            
                    }
                }while(flag!=3);
                break;
            }
            break;
            case 6:
                cout<<"Muchas gracias por su confianza, vuelva pronto!"<<endl;
                system("pause");
                system("cls");
                break;
            default:
                cout<<"Ingrese una opcion valida."<<endl;
                system("pause");
                system("cls");
        }
    }while(flag!=6);
    ofstream out_file ("movies.csv", ofstream::out);
    for(int i=0; i<nline; i++){
        out_file<<pelicula[i].id<<","<<pelicula[i].nombre<<","<<pelicula[i].genero<<","<<pelicula[i].duracion<<","<<pelicula[i].director<<","<<pelicula[i].fecha_de_salida<<","<<pelicula[i].rent_to<<","<<pelicula[i].rent_on<<","<<pelicula[i].estado<<","<<pelicula[i].rent_back<<endl;
    }
    out_file.close();
    return 0;
}