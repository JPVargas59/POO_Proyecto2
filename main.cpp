#include <iostream>
#include <fstream>
#include "Libros.h"
#include "Biblioteca.h"
#include "Alumno.h"

using namespace std;

void CargaBibliotecas(ifstream &ifBibliotecas, Biblioteca biblioteca[], int iMax) {

    string sNombreArchivo;
    string sLinea;
    string sDato;
    string sClave;
    string sClaveBiblio;
    int iPiso;
    int iEstante;
    int iIndex = 0;


    cout << "Escriba el nombre del archivo para cargar Bibliotecas  (incluyendo .txt)" << endl;
    cin >> sNombreArchivo;

    ifBibliotecas.open(sNombreArchivo.c_str());

    while(!ifBibliotecas.is_open()){

        cout << "Ocurrió un error, escriba de nuevo el nombre del archivo para cargar Bibliotecas  (incluyendo .txt)";
        cin >> sNombreArchivo;

        ifBibliotecas.open(sNombreArchivo.c_str());

    }

    while(!ifBibliotecas.eof()){
        ifBibliotecas >> sClave;
        ifBibliotecas >> iPiso;
        ifBibliotecas >> iEstante;
        ifBibliotecas >> sClaveBiblio;

        biblioteca[iIndex].setClave(sClave);
        biblioteca[iIndex].setPiso(iPiso);
        biblioteca[iIndex].setEstante(iEstante);
        biblioteca[iIndex].setClaveBiblio(sClaveBiblio);

        /*
        cout << biblioteca[iIndex].getClave() << " ";
        cout << biblioteca[iIndex].getPiso() << " ";
        cout << biblioteca[iIndex].getEstante() << " ";
        cout << biblioteca[iIndex].getClaveBiblio()<< endl;
        */

        iIndex++;

    }


}

void CargaAlumnos(ifstream &ifAlumnos, Alumno alumno[], int iMax) {

    string sNombreArchivo;
    string sLinea;
    string sDato;
    int iMatricula;
    string sCarrera;
    string sNombre;
    int iIndex = 0;


    cout << "Escriba el nombre del archivo para cargar Alumnos (incluyendo .txt)" << endl;
    cin >> sNombreArchivo;

    ifAlumnos.open(sNombreArchivo.c_str());

    while(!ifAlumnos.is_open()){

        cout << "Ocurrió un error, escriba de nuevo el nombre del archivo para cargar Alumnos  (incluyendo .txt)";
        cin >> sNombreArchivo;

        ifAlumnos.open(sNombreArchivo.c_str());

    }

    while(!ifAlumnos.eof()){
        ifAlumnos >> iMatricula;
        ifAlumnos >> sCarrera;
        getline(ifAlumnos, sNombre);

        alumno[iIndex].setMatricula(iMatricula);
        alumno[iIndex].setCarrera(sCarrera);
        alumno[iIndex].setNombre(sNombre);

        /*
        cout << alumno[iIndex].getMatricula() << " ";
        cout << alumno[iIndex].getCarrera() << " ";
        cout << alumno[iIndex].getNombre() << endl;
        */
        iIndex++;
    }

}

void AltaLibros(Libros libros[], int iLibros){

    string sTitulo;
    string sClaveBiblio;
    string sIsbn;

    for(int i = 0 ; i < iLibros ; i++) {
        cout << "Titulo del libro: ";
        cin >> sTitulo;
        libros[i].setTitulo(sTitulo);

        cout << "Titulo del libro: ";
        cin >> sClaveBiblio;
        libros[i].setClaveBiblio(sClaveBiblio);

        cout << "Titulo del libro: ";
        cin >> sIsbn;
        libros[i].setISBN(sIsbn);

    }

    cout << "________________________________________" << endl << endl;
    cout << iLibros << " dados de alta exitosamente" << endl;
    cout << "________________________________________" << endl;

}

int main() {
    int iMAXBIBLIOTECAS = 5;
    int iMAXALUMNOS = 15;
    int iMAXLIBROS = 10;
    int iLibros;
    int iOp;
    Biblioteca bibliotecas[iMAXBIBLIOTECAS];
    Alumno alumnos[iMAXALUMNOS];
    Libros libros[iMAXLIBROS];

    ifstream ifBibliotecas, ifAlumnos;

    CargaBibliotecas(ifBibliotecas,bibliotecas , iMAXBIBLIOTECAS);
    CargaAlumnos(ifAlumnos, alumnos, iMAXALUMNOS);

    cout << "Teclee la cantidad de libros a dar de alta" << endl;
    cin >> iLibros;

    while ( iLibros > iMAXLIBROS || iLibros < 0 ) {
        cout << "Cantidad de libros no valida, ingrese una nueva" << endl;
        cin >> iLibros;
    }

    AltaLibros(libros, iLibros);

    do{

        cout << endl << "Escoja una opción del menú" << endl;
        cout << "1- Consulta de todos los libros" << endl;
        cout << "2- Prestar un libro a un Alumno" << endl;
        cout << "3- Consultar prestamos a entregar en X fecha" << endl;
        cout << "4- Consulta ISBN por libro" << endl;
        cout << "5- Consulta de libros en una biblioteca" << endl;
        cout << "6- Consulta la lista de libros que ha solicitado a prestamo un Alumno" << endl;
        cout << "0- Salir" << endl;
        cout << endl;
        cin >> iOp;

        switch (iOp) {

            case 1:
                MostrarLibros(libros, iLibros);
                break;
            case 2:
                PrestarLibro(libros, alumnos);
                break;
            case 3:

                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;

            default: cout << "Esa no es una opción válida" << endl;
                break;
        }

    } while(iOp != 0);




    return 0;
}