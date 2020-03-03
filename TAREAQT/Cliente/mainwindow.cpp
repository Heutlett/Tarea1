#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "comunicarServer.h"
#include <string>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief Muestra el resultado del algoritmo dijkstra en un campo de texto
 */
void MainWindow::on_pushButton_clicked()
{

    string msg = obtenerDijkstra(ui->lineEdit->text().toStdString());

    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText(msg.c_str());

}

/**
 * @brief Actualiza el grafo en la tabla de la interfaz grafica
 */
void MainWindow::on_pushButton_2_clicked()
{
    string grafo = actualizarGrafo();
    int cantVertices = 0;
    int fila = 0;
    int columna = 0;
    QString tmp = "";

    for(int i = 0; i < grafo.size(); i++){

        if(grafo.at(i) == '\n'){
            cantVertices++;
        }
    }

    ui->tableWidget->setColumnCount(cantVertices);
    ui->tableWidget->setRowCount(cantVertices);

    for(int i = 0; i < grafo.size(); i++){

        if(grafo.at(i) == '\n'){
            fila++;
            tmp = "";
            columna = 0;
        }

        if(grafo.at(i) == ' ' ){
            ui->tableWidget->setItem(fila,columna, new QTableWidgetItem(tmp));
            columna++;
            tmp = "";
        }

        if(grafo.at(i) != ' ' && grafo.at(i) != '\n'){
           tmp += grafo.at(i);
        }
    }
}
