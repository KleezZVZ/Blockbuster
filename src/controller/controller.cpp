#include "controller.h"
#include "../model/model.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
int nline=0, numero_de_clientes=0;
void cargar_estructura(){
    string line, word;
    int count=0;
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
}
void cargar_estado_de_renta(){
    for(int i=0; i<nline; i++){
        if(pelicula[i].rent_on.compare(pelicula[i].rent_back)<0 && pelicula[i].rent_to.length()!=0){
            pelicula[i].estado="Rentado";
        }else if(pelicula[i].rent_on.compare(pelicula[i].rent_back)>0){
            pelicula[i].estado="Entrega atrasada";
        }
    }
}
void cargar_clientes(){
    string line, word;
    int count;
    fstream file_bin ("../data/clientes.bin", fstream::in | fstream::binary);
    if(file_bin.is_open()){
        while(getline(file_bin, line)){
            stringstream str(line);
            while(getline(str, word, ';')){
                switch(count){
                    case 0: cliente[numero_de_clientes].ci=stoi(word);
                    case 1: cliente[numero_de_clientes].nombre=word;
                }
                count++;
            }
            count=0;
            numero_de_clientes++;
        }
    }
    file_bin.close();
}
