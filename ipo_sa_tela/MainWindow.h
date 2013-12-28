#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

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
};

#endif // MAINWINDOW_H
