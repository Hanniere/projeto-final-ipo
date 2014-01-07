#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_selecionar_arquivo_entrada_clicked()
{
    m_nomeArquivo = QFileDialog::getOpenFileName(this,
        tr("Open file"), QDir::currentPath(), tr("txt Files (*.txt)"));

    if( m_nomeArquivo.isEmpty() == false ){
        m_mainController.clear();
        if( m_mainController.carregarDadosEntrada( m_nomeArquivo.toStdString() ) == true )
            m_mainController.executar();
    }
}
