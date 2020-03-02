#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "comunicarServer.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     ui->plainTextEdit_2->appendPlainText(abrirGrafo("texto.txt").c_str());

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    ui->plainTextEdit->appendPlainText(comuServer().c_str());


}

string MainWindow::abrirGrafo(string txt){

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

