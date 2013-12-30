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

void MainController::setTipoSimulatedAnneling(std::string tipoSa)
{
    std::transform(tipoSa.begin(), tipoSa.end(), tipoSa.begin(), ::tolower);
    if( tipoSa == "alocacao sala")
        m_simulatedAnneling =  SimulatedAnnelingFactory::getInstance()->getSimulatedAnneling( ALOCACAO_SALAS );
}
