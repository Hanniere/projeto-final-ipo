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
    delete m_parser;
}

bool SimulatedAnnelingAlocacaoSala::carregarDadosEntrada(const std::string &nomeArquivo)
{
    if( m_parser->parse( nomeArquivo ) ){
        m_vetorSala  = m_parser->vetorSala();
        m_vetorTurma = m_parser->vetorTurma();

        m_solucaoSaAlocacaoSalaCompleta.setListaSala( m_vetorSala );
        for( unsigned int i = 0; i < m_vetorTurma.size(); i++ ){
            m_solucaoSaAlocacaoSalaCompleta.addTumarNoDia( m_vetorTurma[i], m_vetorTurma[i].diaSemana() );
        }

        m_vetorSala.clear();
        m_vetorTurma.clear();
        m_parser->clear();

        return true;
    }

    m_parser->clear();

    return false;
}

ISolucaoSa *SimulatedAnnelingAlocacaoSala::gerarSolucaoInicial() const
{
    SolucaoSaAlocacaoSala* solucao = new SolucaoSaAlocacaoSala();

    solucao->setListaSala( m_solucaoSaAlocacaoSalaCompleta.listaSala() );

    return solucao;
}

ISolucaoSa *SimulatedAnnelingAlocacaoSala::simulatedAnneling()
{
    // varrer a SolucaoCompleta gerando um solucaoInicial para cada dia
    return 0;
}

ISolucaoSa *SimulatedAnnelingAlocacaoSala::alocaSolucao() const
{
    return new SolucaoSaAlocacaoSala();
}
