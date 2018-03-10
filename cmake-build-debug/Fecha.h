//
// Created by Cristian Ramirez on 09/03/18.
//

#ifndef PROYECTO_2_FECHA_H
#define PROYECTO_2_FECHA_H

#include <string>
#include <iostream>
using namespace std;

class Fecha {

public:
    Fecha();
    Fecha(int iDia, int iMes, int iAnio);

    string nombreMes();

    int getIDia() const;

    void setIDia(int iDia);

    int getIMes() const;

    void setIMes(int iMes);

    int getIAnio() const;

    void setIAnio(int iAnio);

private:
    int iDia;
    int iMes;
    int iAnio;

};

Fecha::Fecha() {}

Fecha::Fecha(int iDia, int iMes, int iAnio) {
    this->iDia = iDia;
    this->iMes = iMes;
    this->iAnio = iAnio;
}

string Fecha::nombreMes() {
    string iMes;
    switch(this->iMes){
        case 1:
            iMes = "Enero";
            break;
        case 2:
            iMes = "Febrero";
            break;
        case 3:
            iMes = "Marzo";
            break;
        case 4:
            iMes = "Abril";
            break;
        case 5:
            iMes = "Mayo";
            break;
        case 6:
            iMes = "Junio";
            break;
        case 7:
            iMes = "Julio";
            break;
        case 8:
            iMes = "Agosto";
            break;
        case 9:
            iMes = "Septiembre";
            break;
        case 10:
            iMes = "Octubre";
            break;
        case 11:
            iMes = "Noviembre";
            break;
        case 12:
            iMes = "Diciembre";
            break;
        default:
            break;
    }

    return iMes;
}

int Fecha::getIDia() const {
    return iDia;
}

void Fecha::setIDia(int iDia) {
    Fecha::iDia = iDia;
}

int Fecha::getIMes() const {
    return iMes;
}

void Fecha::setIMes(int iMes) {
    Fecha::iMes = iMes;
}

int Fecha::getIAnio() const {
    return iAnio;
}

void Fecha::setIAnio(int iAnio) {
    Fecha::iAnio = iAnio;
}

#endif //PROYECTO_2_FECHA_H
