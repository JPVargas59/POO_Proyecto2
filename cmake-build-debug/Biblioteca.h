//
// Created by Cristian Ramirez on 09/03/18.
//

#ifndef PROYECTO_2_BIBLIOTECA_H
#define PROYECTO_2_BIBLIOTECA_H

#include <string>
#include <iostream>

using namespace std;

class Biblioteca{
public:
    // Constructor
    Biblioteca();
    Biblioteca(string, int, int, string);

    // Metodos de acceso
    string getClave();
    int getPiso();
    int getEstante();
    string getClaveBiblio();

    // Metodos de modificacion
    void setClave(string);
    void setPiso(int);
    void setEstante(int);
    void setClaveBiblio(string);

    // Metodos de operacion
    void muestra();

private:
    string sClave;
    int iPiso;
    int iEstante;
    string sClaveBiblio;
};

// Constructor
Biblioteca :: Biblioteca(){
    sClave = "";
    iPiso = 0;
    iEstante = 0;
    sClaveBiblio = "";

}

Biblioteca :: Biblioteca(string sC, int iP, int iE, string sCB) {
    sClave = sC;
    iPiso = iP;
    iEstante = iE;
    sClaveBiblio = sCB;
}

// Metodos de acceso
string Biblioteca :: getClave(){
    return sClave;
}
int Biblioteca :: getPiso(){
    return iPiso;
}
int Biblioteca :: getEstante(){
    return iEstante;
}
string Biblioteca :: getClaveBiblio(){
    return sClaveBiblio;
}

// Metodos de modificacion
void Biblioteca :: setClave(string sC){
    sClave = sC;
}
void Biblioteca :: setPiso(int iP){
    iPiso = iP;
}
void Biblioteca :: setEstante(int iE){
    iEstante = iE;
}
void Biblioteca :: setClaveBiblio(string sCB){
    sClaveBiblio = sCB;
}

// Metodos de operacion
void Biblioteca :: muestra(){
    cout << "Clave: " << sClave << " Piso: " << iPiso << " Estante: " << iEstante
         << " Clave Biblioteca: " << sClaveBiblio << endl;
}

#endif //PROYECTO_2_BIBLIOTECA_H
