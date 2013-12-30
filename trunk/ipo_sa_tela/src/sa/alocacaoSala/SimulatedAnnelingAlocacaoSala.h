#ifndef SIMULATEDANNELINGALOCACAOSALA_H
#define SIMULATEDANNELINGALOCACAOSALA_H

#include <src/sa/ISimulatedAnneling.h>

class SimulatedAnnelingAlocacaoSala : public ISimulatedAnneling
{
public:
    SimulatedAnnelingAlocacaoSala();
    bool carregarDadosEntrada( const std::string& nomeArquivo );

private:
    //std::vector<
};

#endif // SIMULATEDANNELINGALOCACAOSALA_H
