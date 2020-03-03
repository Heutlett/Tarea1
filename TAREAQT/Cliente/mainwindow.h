#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief
 *
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief
     *
     * @param parent
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief
     *
     */
    ~MainWindow();

private slots:
    /**
     * @brief
     *
     */
    void on_pushButton_clicked();

    /**
     * @brief
     *
     */
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui; /**< TODO: describe */
};
#endif // MAINWINDOW_H
