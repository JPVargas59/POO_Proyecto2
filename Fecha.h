//
// Created by Cristian Ramirez on 09/03/18.
//

#ifndef PROYECTO_2_FECHA_H
#define PROYECTO_2_FECHA_H

#include <iostream>
#include <string>

using namespace std;

class Fecha{
public:
    //constructores
    Fecha();
    Fecha(int ,int,int);
    //métodos de acceso
    int getDia();
    int getMes();
    int getAnio();

    //métodos de modificicación
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    //métodos de operación
    string nombreMes();
    void muestra();
    friend Fecha operator + (Fecha f1, int dias);


private:
    int iDia;
    int iMes;
    int iAnio;
};

//constructores
Fecha::Fecha(){
    iDia=0;
    iMes=0;
    iAnio=0;
}
Fecha::Fecha(int dia,int mes,int anio){
    this->iDia=dia;
    this->iMes=mes;
    this->iAnio=anio;
}

//métodos de acceso
int Fecha::getDia(){
    return iDia;
}
int Fecha::getMes(){
    return iMes;
}
int Fecha::getAnio(){
    return iAnio;
}

//métodos de modificicación
void Fecha::setDia(int dia){
    this->iDia= dia;}
void Fecha::setMes(int mes){
    this->iMes=mes;}
void Fecha::setAnio(int anio){
    this->iAnio=anio;}

//métodos de operación
string Fecha::nombreMes(){
    switch (iMes){
        case 1:return "Enero";
            break;
        case 2:return "Febrero";
            break;
        case 3:return "Marzo";
            break;
        case 4:return "Abril";
            break;
        case 5:return "Mayo";
            break;
        case 6:return "Junio";
            break;
        case 7:return "Julio";
            break;
        case 8:return "Agosto";
            break;
        case 9:return "Septiembre";
            break;
        case 10:return "Octubre";
            break;
        case 11:return "Noviembre";
            break;
        case 12:return "Diciembre";
            break;
    }
}

bool esBisiesto(int iAnio){
    if (iAnio %4==0 && (iAnio % 100 != 0 || iAnio %400 ==0))
        return true;
    else
        return false;
}

void Fecha::muestra(){
    cout<<iDia<<"/"<<nombreMes()<<"/"<<iDia<<" ";
}

Fecha operator + (Fecha f1, int dias){
    Fecha res;
    res.iDia = f1.iDia + dias;
    res.iMes = f1.iMes;
    res.iAnio = f1.iAnio;

    if ((res.iMes == 1 || res.iMes == 3 || res.iMes == 5 || res.iMes == 7 || res.iMes == 8
         || res.iMes == 10 || res.iMes == 12) && res.iDia > 31){

        res.iMes += 1;
        res.iDia -= 31;

        if(res.iMes > 12){
            res.iAnio += 1;
            res.iMes -= 12;
        }
    }

    else if((res. iMes == 4|| res.iMes == 6 ||res.iMes == 9 ||res.iMes == 11) && res.iDia > 30){
        res.iMes += 1;
        res.iDia -= 30;

        if(res.iMes > 12){
            res.iAnio += 1;
            res.iMes -= 12;
        }
    }

    else if(res.iMes == 2 && res.iDia > 28){
        if (esBisiesto(res.iAnio) && res.iDia > 29){
            res.iMes += 1;
            res.iDia -= 29;

            if(res.iMes > 12){
                res.iAnio += 1;
                res.iMes -= 12;
            }
        }
        else{
            res.iMes += 1;
            res.iDia -= 28;

            if(res.iMes > 12){
                res.iAnio += 1;
                res.iMes -= 12;
            }
        }
    }

    return res;
}

#endif //PROYECTO_2_FECHA_H
