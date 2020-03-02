/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ManejoArchivos.h
 * Author: heutlett
 *
 * Created on March 1, 2020, 6:33 PM
 */

#ifndef MANEJOARCHIVOS_H
#define MANEJOARCHIVOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

class ManejoArchivos {
public:
    ManejoArchivos();

    string abrirGrafoTXT(string txt){

    fstream archivo;
    string texto;
    string texto2 = "";

    archivo.open(txt, ios::in);

    if(archivo.fail()){

        printf("No se pudo abrir el archivo");
        exit(1);

    }

    while(!archivo.eof()){

        getline(archivo, texto);
        texto2 += texto + "\n";

    }

    return texto2;

    }

private:

};

#endif /* MANEJOARCHIVOS_H */

