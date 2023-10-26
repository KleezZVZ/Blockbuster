#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;
struct Peliculas{
    string nombre, genero, director, fecha_de_salida, rent_to, rent_on, estado, id, duracion;
};
int flag=0, consulta_peliculas, id[1000], search_id[1000];
int main(){
    string line, word;
    int count=0, nline=0;
    Peliculas pelicula[2000];
    ifstream in_file ("movies.csv", ifstream::in);
    ofstream out_file ("movies.csv", ofstream::out | ios_base::app);
    fstream file_bin ("clientes.bin", fstream::in | fstream::out | fstream::binary | ios_base::app);
    if(!in_file.is_open()){
        cout<<"Archivo no encontrado";
        return 0;
    }
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
                case 6: pelicula[nline].rent_to=word; break;
                case 7: pelicula[nline].rent_on=word; break;
                case 8: pelicula[nline].estado=word; break;
            }
            count++;
        }
        count=0;
        nline++;
    }
    in_file.close();
    for(int i=0; i<1000; i++){
        id[i]=stoi(pelicula[i].id);
    }
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
            case 3:
            do{
                cout<<"Bienvenido a la seccion de rentas de Blockbuster, a continuacion se les dara las siguientes opciones:\n1)Rentar una pelicula.\n2)Consultar el estado de una pelicula.\n3)Volver al menu principal.\nElija una opcion: "; cin>>flag;
                system("cls");
                switch(flag){
                    case 2:
                    cout<<"Ingrese la id de la pelicula a verificar su disponibilidad: "; cin>>consulta_peliculas;
                    system("cls");
                    if(pelicula[consulta_peliculas].estado.length()!=0){
                        cout<<"La pelicula ya se encuentra rentada, lo sentimos"<<endl;
                        system("pause");
                        system("cls");
                    }else{
                        cout<<"La pelicula se encuentra disponible, vaya a la opcion de rentarla"<<endl;
                        system("pause");
                        system("cls");
                    }
                }
            }while(flag!=3);
            break;
        }
    }while(flag!=6);
    system("cls");
    cout<<"Muchas gracias por su confianza, vuelva pronto!"<<endl;
    system("pause");
    return 0;
}