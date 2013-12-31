#ifndef SIMULATEDANNELINGALOCACAOSALA_H
#define SIMULATEDANNELINGALOCACAOSALA_H

#include <src/sa/ISimulatedAnneling.h>
#include <src/domain/alocacaoSala/Sala.h>
#include <src/domain/alocacaoSala/Turma.h>
#include <src/domain/alocacaoSala/SolucaoSaAlocacaoSalaCompleta.h>
#include <vector>

class IParserSimulatedAnnelingAlocacaoSala;

class SimulatedAnnelingAlocacaoSala : public ISimulatedAnneling
{
public:
    static const int NUM_ITERACOES_ALOCACAO_SALA_DEFAULT = 10000;
    static const float TAXA_RESFRIAMENTO_ALOCACAO_SALA_DEFAULT = 0.9f;
    static const int TEMPERATURA_INICIAL_ALOCACAO_SALA_DEFAULT = 100;

    SimulatedAnnelingAlocacaoSala();
    SimulatedAnnelingAlocacaoSala( const std::vector<Sala>& vetorSala, const std::vector<Turma>& vetorTurma );
    virtual ~SimulatedAnnelingAlocacaoSala();

    bool carregarDadosEntrada( const std::string& nomeArquivo );

// virtual
public:
    ISolucaoSa* gerarSolucaoInicial() const;
    ISolucaoSa*simulatedAnneling();
    ISolucaoSa* alocaSolucao() const;

private:
    IParserSimulatedAnnelingAlocacaoSala* m_parser;
    std::vector<Sala> m_vetorSala;
    std::vector<Turma> m_vetorTurma;
    SolucaoSaAlocacaoSalaCompleta m_solucaoSaAlocacaoSalaCompleta;
};

#endif // SIMULATEDANNELINGALOCACAOSALA_H
