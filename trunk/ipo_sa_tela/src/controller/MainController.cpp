#include "MainController.h"

#include<string>
#include <algorithm>
#include<src/sa/alocacaoSala/SimulatedAnnelingAlocacaoSala.h>
#include<src/sa/factory/SimulatedAnnelingFactory.h>

MainController::MainController()
{
    // simulalted anneling default
    m_simulatedAnneling = new SimulatedAnnelingAlocacaoSala();
}

MainController::~MainController()
{
    delete m_simulatedAnneling;
}

bool MainController::carregarDadosEntrada(const std::string &nomeArquivo)
{
    return m_simulatedAnneling->carregarDadosEntrada( nomeArquivo  );
}

void MainController::clear()
{
    m_simulatedAnneling->clear();
}

std::string MainController::executar()
{
    ISolucaoSa* solucao = m_simulatedAnneling->simulatedAnneling();

    return solucao->toString();
}

void MainController::setTipoSimulatedAnneling(std::string tipoSa)
{
    std::transform(tipoSa.begin(), tipoSa.end(), tipoSa.begin(), ::tolower);
    if( tipoSa == "alocacao sala")
        m_simulatedAnneling =  SimulatedAnnelingFactory::getInstance()->getSimulatedAnneling( ALOCACAO_SALAS );
}

int MainController::numeroIteracoes() const
{
    if( m_simulatedAnneling != 0 )
        return m_simulatedAnneling->numeroIteracoes();
    else
        return -1;
}

void MainController::setNumeroIteracoes(int numeroIteracoes)
{
    if( m_simulatedAnneling != 0 )
        m_simulatedAnneling->setNumeroIteracoes( numeroIteracoes );
}

float MainController::temperaturaInicial() const
{
    if( m_simulatedAnneling != 0 )
        return m_simulatedAnneling->temperaturaInicial();
    else
        return -1;
}

void MainController::setTemperaturaInicial(float temperaturaInicial)
{
    if( m_simulatedAnneling != 0 )
        m_simulatedAnneling->setTemperaturaInicial( temperaturaInicial );
}

float MainController::taxaResfriamento() const
{
    if( m_simulatedAnneling != 0 )
        return m_simulatedAnneling->taxaResfriamento();
    else
        return -1;
}

void MainController::setTaxaResfriamento(float taxaResfriamento)
{
    if( m_simulatedAnneling != 0 )
        m_simulatedAnneling->setTaxaResfriamento( taxaResfriamento );
}
