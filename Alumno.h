//
// Created by Cristian Ramirez on 09/03/18.
//

#ifndef PROYECTO_2_ALUMNO_H
#define PROYECTO_2_ALUMNO_H

#include <string>
#include <iostream>

using namespace std;

class Alumno{

public:
    // Constructores
    Alumno();
    Alumno(int, string, string);

    // Metodos de acceso
    int getMatricula();
    string getCarrera();
    string getNombre();

    // Metodos de modificacion
    void setMatricula(int);
    void setCarrera(string);
    void setNombre(string);

    // Metodos de operacion
    void muestra();

private:
    int iMatricula;
    string sCarrera;
    string sNombre;

};

// Constructores
Alumno :: Alumno(){
    iMatricula = 0;
    sCarrera = "";
    sNombre = "";
}
Alumno :: Alumno(int iMat, string sCarrera, string sNombre){
    iMatricula = iMat;
    this -> sCarrera = sCarrera;
    this -> sNombre = sNombre;
}

// Metodos de acceso
int Alumno :: getMatricula(){
    return iMatricula;
}
string Alumno :: getCarrera(){
    return sCarrera;
}
string Alumno :: getNombre(){
    return sNombre;
}

// Metodos de modificacion
void Alumno :: setMatricula(int iMatr){
    iMatricula = iMatr;
}
void Alumno :: setCarrera(string c){
    sCarrera = c;
}
void Alumno :: setNombre(string n){
    sNombre = n;
}

// Metodos de operacion
void Alumno :: muestra(){
    cout << "Nombre: " << sNombre << " Matricula: " << iMatricula << " Carrera: " << sCarrera << endl;
}

#endif //PROYECTO_2_ALUMNO_H
