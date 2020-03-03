/**
  * @file mainwindow.h
  * @date 3/2/2020
  * @author Carlos Adrian Araya Ramirez 2018319701
  * @title main del cliente
  * @brief Se controla lo que sucede en la interfaz
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:

    /**
     * @brief Muestra el resultado del algoritmo dijkstra en un campo de texto
     */
    void on_pushButton_clicked();
    /**
     * @brief Actualiza el grafo en la tabla de la interfaz grafica
     */
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui; /**< TODO: describe */
};
#endif // MAINWINDOW_H
