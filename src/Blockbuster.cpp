#include <Windows.h>
#include "view/view.h"
using namespace std;
//int flag=0, consulta_peliculas, search_id[1000], numero_de_clientes=0, search_ci, search_cliente_2=1000, orden;
//string search_cliente;
int main(){
    system("color 4f");
    menu_principal();
    system("pause");
    /*
    do{
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
                ofstream write_file("../data/movies.csv", ofstream::ios_base::app);
                pelicula[nline].estado="Disponible";
                write_file<<endl<<pelicula[nline].id<<","<<pelicula[nline].nombre<<","<<pelicula[nline].genero<<","<<pelicula[nline].duracion<<","<<pelicula[nline].director<<","<<pelicula[nline].fecha_de_salida<<","<<pelicula[nline].rent_to<<","<<pelicula[nline].rent_on<<","<<pelicula[nline].estado<<","<<pelicula[nline].rent_back;
                nline++;
                cout<<"Su registro se ha llevado con exito! Usted ha agregado la pelicula numero: "<<nline<<endl;
                system("pause");
                system("cls");
                break;
            }
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
    ofstream out_file ("../data/movies.csv", ofstream::out);
    for(int i=0; i<nline; i++){
        out_file<<pelicula[i].id<<","<<pelicula[i].nombre<<","<<pelicula[i].genero<<","<<pelicula[i].duracion<<","<<pelicula[i].director<<","<<pelicula[i].fecha_de_salida<<","<<pelicula[i].rent_to<<","<<pelicula[i].rent_on<<","<<pelicula[i].estado<<","<<pelicula[i].rent_back<<endl;
    }
    out_file.close();*/
    return 0;
}