#include "SimulatedAnnelingAlocacaoSala.h"

#include<string>
#include<src/sa/parser/alocacaoSala/ParserSimulatedAnnelingAlocacaoSalaArquivo.h>
#include <src/domain/alocacaoSala/SolucaoSaAlocacaoSala.h>

#include<cassert>

SimulatedAnnelingAlocacaoSala::SimulatedAnnelingAlocacaoSala()
    : m_parser( new ParserSimulatedAnnelingAlocacaoSalaArquivo() )
{
    m_numeroIteracoes = NUM_ITERACOES_ALOCACAO_SALA_DEFAULT;
    m_taxaResfriamento = TAXA_RESFRIAMENTO_ALOCACAO_SALA_DEFAULT;
    m_temperaturaInicial = TEMPERATURA_INICIAL_ALOCACAO_SALA_DEFAULT;
}

SimulatedAnnelingAlocacaoSala::SimulatedAnnelingAlocacaoSala(const std::vector<Sala> &vetorSala, const std::vector<Turma> &vetorTurma)
{
    m_vetorSala  = vetorSala;
    m_vetorTurma = vetorTurma;
}

SimulatedAnnelingAlocacaoSala::~SimulatedAnnelingAlocacaoSala()
{
}

bool SimulatedAnnelingAlocacaoSala::carregarDadosEntrada(const std::string &nomeArquivo)
{
    if( m_parser->parse( nomeArquivo ) ){
        m_vetorSala  = m_parser->vetorSala();
        m_vetorTurma = m_parser->vetorTurma();


        m_parser->clear();

        return true;
    }

    m_parser->clear();

    return false;
}

ISolucaoSa *SimulatedAnnelingAlocacaoSala::alocaSolucao() const
{
    return new SolucaoSaAlocacaoSala();
}