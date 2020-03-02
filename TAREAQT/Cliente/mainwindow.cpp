#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "comunicarServer.h"
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //iniciarCliente();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    //iniciarCliente();

    obtenerDijkstra(ui->lineEdit->text().toStdString());

    //ui->plainTextEdit->appendPlainText(msg.c_str());

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

//Actualizar grafo
void MainWindow::on_pushButton_2_clicked()
{
\
    actualizarGrafo();

    ui->plainTextEdit_2->clear();

    ui->plainTextEdit_2->appendPlainText(abrirGrafo("texto.txt").c_str());


}
