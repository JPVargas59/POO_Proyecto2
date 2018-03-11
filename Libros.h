//
// Created by Cristian Ramirez on 09/03/18.
//

#ifndef PROYECTO_2_LIBROS_H
#define PROYECTO_2_LIBROS_H

#include <string>
#include "Fecha.h"

using namespace std;

class Libros{
public:
    // Constructores
    Libros();

    // Metodos de acceso
    Fecha getFecha();
    int getDiasPrestamo();
    string getTitulo();
    string getClaveBiblio();
    string getISBN();
    int getlistaAlumno(int);
    int getPrestados();

    // Metodos de modificacion
    void setFecha(Fecha);
    void setDiasPrestamo(int);
    void setTitulo(string);
    void setClaveBiblio(string);
    void setISBN(string);

    // Metodos de operacion
    Fecha calculaFechaFinPrestamo();
    bool prestamo(string, int);

private:
    Fecha Fecha_Prestamo;
    int diasPrestamo;
    string Titulo;
    string claveBiblio;
    string ISBN;
    int prestados;
    int listaAlumnos[10];
    int numAlumnos;

};

// Constructores
Libros :: Libros(){
    Fecha f;
    Fecha_Prestamo = f;
    diasPrestamo = 0;
    Titulo = "";
    claveBiblio = "";
    ISBN = "";
    prestados = 0;
    listaAlumnos[10] = {};
    numAlumnos = 0;

}

// Metodos de acceso
Fecha Libros :: getFecha(){
    return Fecha_Prestamo;
}
int Libros :: getDiasPrestamo(){
    return diasPrestamo;
}
string Libros :: getTitulo(){
    return Titulo;
}
string Libros :: getClaveBiblio(){
    return claveBiblio;
}
string Libros :: getISBN(){
    return ISBN;
}
int Libros :: getlistaAlumno(int index){
    return listaAlumnos[index];
}
int Libros :: getPrestados(){
    return prestados;
}

// Metodos de modificacion
void Libros :: setFecha(Fecha f){
    Fecha_Prestamo = f;
}
void Libros :: setDiasPrestamo(int dias){
    diasPrestamo = dias;
}
void Libros :: setTitulo(string t){
    Titulo = t;
}
void Libros :: setClaveBiblio(string clave){
    claveBiblio = clave;
}
void Libros :: setISBN(string i){
    ISBN = i;
}

// Metodos de operacion
Fecha Libros :: calculaFechaFinPrestamo(){
    Fecha fFinP;
    fFinP = Fecha_Prestamo + diasPrestamo;

    return fFinP;
}
bool Libros :: prestamo(string ISBN, int matricula){
    for (int i = 0; i < numAlumnos; i++){
        if (listaAlumnos[i] == matricula || this-> ISBN != ISBN){
            return false;
        }
    }

    if(numAlumnos < 10) {
        listaAlumnos[numAlumnos] = matricula;
        numAlumnos++;
        prestados++;

        return true;
    }
    else{
        return false;
    }

}

#endif //PROYECTO_2_LIBROS_H
