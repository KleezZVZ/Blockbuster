#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;
struct Peliculas{
    string nombre, genero, director, fecha_de_salida, id, duracion;
};
int flag=0;
int main(){
    Peliculas pelicula[2000];
    ifstream in_file ("movies.csv", ifstream::in);
    if(!in_file.is_open()){
        cout<<"Archivo no encontrado";
        return 0;
    }
    string line, word;
    int count=0, nline=0;
    while(getline(in_file, line)){
        stringstream str(line);
        while(getline(str, word, ',')){
            switch(count){
                case 0: pelicula[nline].id=word; break;
                case 1: pelicula[nline].nombre=word; break;
                case 2: pelicula[nline].genero=word; break;
                case 3: pelicula[nline].duracion=word; break;
                case 4: pelicula[nline].director=word; break;
                case 5: pelicula[nline].fecha_de_salida=word; break;
            }
            count++;
        }
        count=0;
        nline++;
    }
    in_file.close();
    do{
        cout<<"Bienvenido al programa de rentas de peliculas online de Blockbuster. A continuacion se le dara sus opciones:\n1)Buscador de peliculas.\n2)Consulta de peliculas.\n3)Rentar una pelicula.\n4)Agregar peliculas.\n5)Inicio de sesion.\n6)Salir del programa.\nElija su opcion: "; cin>>flag;
        system("cls");
    }while(flag!=6);
    cout<<"Muchas gracias por su confianza, vuelva pronto!"<<endl;
    system("pause");
    return 0;
}