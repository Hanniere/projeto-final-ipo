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
    QString nomeArquivo = QFileDialog::getOpenFileName(this,
        tr("Open file"), QDir::currentPath(), tr("txt Files (*.txt)"));

    if( nomeArquivo.isEmpty() == false ){
        m_mainController.clear();
        if( m_mainController.carregarDadosEntrada( nomeArquivo.toStdString() ) == true ) {
            nomeArquivo.append( " - OK" );
            ui->gbx_simulated_annealing->setEnabled( true );
        }
        else{
            nomeArquivo.append( " - Falhou" );
            ui->gbx_simulated_annealing->setEnabled( false );
        }

        ui->ln_saida_parser->setText( nomeArquivo );
    }
}

void MainWindow::on_pb_executar_clicked()
{
    //ui->pb_executar->setEnabled( false );

    m_mainController.setNumeroIteracoes( ui->ln_num_iteracoes->text().toInt() );
    m_mainController.setTaxaResfriamento( ui->ln_taxa_resfriamento->text().toFloat() );
    m_mainController.setTemperaturaInicial( ui->ln_temperatura_inicial->text().toFloat() );

    QString retorno( m_mainController.executar().c_str() );
    ui->txtEdit_resposta->setText( retorno );

    //ui->pb_executar->setEnabled( true );
}
