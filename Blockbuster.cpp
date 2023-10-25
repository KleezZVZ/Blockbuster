#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;
struct Peliculas{
    string nombre, genero, director, fecha_de_salida, id, duracion;
};
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
    for(int i=0; i<1000; i++){
        cout<<pelicula[i].id<<endl;
        cout<<pelicula[i].nombre<<endl;
        cout<<pelicula[i].genero<<endl;
        cout<<pelicula[i].duracion<<endl;
        cout<<pelicula[i].director<<endl;
        cout<<pelicula[i].fecha_de_salida<<endl;
    }
    system("pause");
    return 0;
}