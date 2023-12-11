#include "controller.h"
#include "../model/model.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
using namespace std;
int nline=0, numero_de_clientes=0, *puntero=nullptr;
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
                    case 2: cliente[numero_de_clientes].telefono=word;
                }
                count++;
            }
            count=0;
            numero_de_clientes++;
        }
    }
    file_bin.close();
}
void crear_arreglo_dinamico(int n){
    puntero=new int[n];
}
void llenar_arreglo_dinamico(int valor, int i){
    *(puntero+i)=valor;
}
void mostrar_peliculas(int n){
    for(int i=0; i<n; i++){
        cout<<i+1<<"-Nombre de la pelicula: "<<pelicula[*(puntero+i)-1].nombre<<endl;
        cout<<i+1<<"-Genero de la pelicula: "<<pelicula[*(puntero+i)-1].genero<<endl;
        cout<<i+1<<"-Duracion de la pelicula: "<<pelicula[*(puntero+i)-1].duracion<<endl;
        cout<<i+1<<"-Director de la pelicula: "<<pelicula[*(puntero+i)-1].director<<endl;
        cout<<i+1<<"-Fecha de salida de la pelicula: "<<pelicula[*(puntero+i)-1].fecha_de_salida<<endl;
    }
    delete[] puntero;
    puntero=nullptr;
}
void crear_cliente(int ci, string nombre, string telefono){
    cliente[numero_de_clientes].ci=ci;
    cliente[numero_de_clientes].nombre=nombre;
    cliente[numero_de_clientes].telefono=telefono;
    fstream write_bin ("../data/clientes.bin", ios_base::app | fstream::binary);
    write_bin<<cliente[numero_de_clientes].ci<<";"<<cliente[numero_de_clientes].nombre<<";"<<cliente[numero_de_clientes].telefono<<endl;
    write_bin.close();
    numero_de_clientes++;
}
string busqueda_ci(int search_ci){
    for(int i=0; i<numero_de_clientes; i++){
        if(cliente[i].ci==search_ci){
            return cliente[i].nombre;
        }
    }
    return "-1";
}
string busqueda_tlf(string search_tlf){
    for(int i=0; i<numero_de_clientes; i++){
        if(cliente[i].telefono==search_tlf){
            return cliente[i].nombre;
        }
    }
    return "-1";
}
int busqueda_cliente(string search_nombre){
    for(int i=0; i<numero_de_clientes; i++){
        if(cliente[i].nombre==search_nombre){
            return cliente[i].ci;
        }
    }
    return -1;
}
int inicio_sesion(int search_ci, string search_cliente){
    for(int i=0; i<numero_de_clientes; i++){
        if(cliente[i].ci==search_ci && cliente[i].nombre==search_cliente){
            return 1;
        }
    }
    return -1;
}
string rentar_pelicula(string cliente, int search_id){
    time_t ahora= time(0);
    tm* fecha= localtime(&ahora);
    char fecha_actual[11];
    strftime(fecha_actual, sizeof(fecha_actual), "%F", fecha);
    pelicula[search_id-1].rent_on=fecha_actual;
    ahora+=14*24*60*60;
    fecha= localtime(&ahora);
    char fecha_a_devolver[11];
    strftime(fecha_a_devolver, sizeof(fecha_a_devolver), "%F", fecha);
    pelicula[search_id-1].rent_back=fecha_a_devolver;
    pelicula[search_id-1].estado="Rentado";
    pelicula[search_id-1].rent_to=cliente;
    return pelicula[search_id-1].nombre;
}
void consulta_peliculas(int search_id){
    if(pelicula[search_id-1].estado=="Rentado" || pelicula[search_id-1].estado=="Entrega atrasada"){
        cout<<"La pelicula "<<pelicula[search_id-1].nombre<<" ya se encuentra rentada por "<<pelicula[search_id-1].rent_to<<", lo sentimos"<<endl;
    }else{
        cout<<"La pelicula "<<pelicula[search_id-1].nombre<<" se encuentra disponible, vaya a la opcion de rentarla"<<endl;
    }
}
int agregar_pelicula(string nombre, string genero, int duracion, string director, string fecha_de_lanzamiento){
    pelicula[nline].nombre=nombre;
    pelicula[nline].genero=genero;
    pelicula[nline].duracion=duracion;
    pelicula[nline].director=director;
    pelicula[nline].fecha_de_salida=fecha_de_lanzamiento;
    pelicula[nline].id=nline+1;
    pelicula[nline].estado="Disponible";
    ofstream write_file("../data/movies.csv", ofstream::ios_base::app);
    write_file<<endl<<pelicula[nline].id<<","<<pelicula[nline].nombre<<","<<pelicula[nline].genero<<","<<pelicula[nline].duracion<<","<<pelicula[nline].director<<","<<pelicula[nline].fecha_de_salida<<","<<pelicula[nline].rent_to<<","<<pelicula[nline].rent_on<<","<<pelicula[nline].estado<<","<<pelicula[nline].rent_back;
    nline++;
    write_file.close();
    return nline;
}
void subir_informacion(){
    ofstream out_file ("../data/movies.csv", ofstream::out);
    for(int i=0; i<nline; i++){
        out_file<<pelicula[i].id<<","<<pelicula[i].nombre<<","<<pelicula[i].genero<<","<<pelicula[i].duracion<<","<<pelicula[i].director<<","<<pelicula[i].fecha_de_salida<<","<<pelicula[i].rent_to<<","<<pelicula[i].rent_on<<","<<pelicula[i].estado<<","<<pelicula[i].rent_back<<endl;
    }
    out_file.close();
}
void peliculas_por_cliente(string nombre){
    int contador=1;
    for(int i=0; i<nline; i++){
        if(pelicula[i].rent_to==nombre){
            cout<<contador<<"-"<<pelicula[i].nombre<<endl;
            contador++;
        }   
    }
}
