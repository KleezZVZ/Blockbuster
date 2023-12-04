#include "controller.h"
#include "../model/model.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
void cargar_estructura(){
    string line, word;
    int count=0, nline=0;
    ifstream in_file ("../data/movies.csv", ifstream::in);
    if(!in_file.is_open()){
        cout<<"Archivo no encontrado"<<endl;
        system("pause");
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
        cout<<i+1<<"-"<<pelicula[i].id<<endl;
        cout<<i+1<<"-"<<pelicula[i].nombre<<endl;
        cout<<i+1<<"-"<<pelicula[i].genero<<endl;
        cout<<i+1<<"-"<<pelicula[i].duracion<<endl;
        cout<<i+1<<"-"<<pelicula[i].director<<endl;
        cout<<i+1<<"-"<<pelicula[i].fecha_de_salida<<endl;
        cout<<i+1<<"-"<<pelicula[i].rent_to<<endl;
        cout<<i+1<<"-"<<pelicula[i].rent_on<<endl;
        cout<<i+1<<"-"<<pelicula[i].estado<<endl;
        cout<<i+1<<"-"<<pelicula[i].rent_back<<endl;
    }
}
