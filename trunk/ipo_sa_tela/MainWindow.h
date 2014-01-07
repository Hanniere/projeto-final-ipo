#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <src/controller/MainController.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_pb_selecionar_arquivo_entrada_clicked();

private:
    Ui::MainWindow *ui;

    QString m_nomeArquivo;
    MainController m_mainController;
};

#endif // MAINWINDOW_H
