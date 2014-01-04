#include "SolucaoSaAlocacaoSalaCompleta.h"

#include <cstring>
#include <cassert>

SolucaoSaAlocacaoSalaCompleta::SolucaoSaAlocacaoSalaCompleta()
{
    m_turmaPorDia = std::vector< std::vector<Turma> >( DOMINGO -1 );
    m_solucoes = std::vector< ISolucaoSa* >( DOMINGO -1 );
}

void SolucaoSaAlocacaoSalaCompleta::addSala(const Sala &sala)
{
    m_listaSala.push_back( sala );
}

void SolucaoSaAlocacaoSalaCompleta::addTumarNoDia(const Turma &turma, const DiaSemana &dia)
{
    m_turmaPorDia[dia-1].push_back( turma );
}

std::vector<Turma> SolucaoSaAlocacaoSalaCompleta::getTurmasDia(const DiaSemana &dia) const
{
    return m_turmaPorDia[dia-1];
}

std::vector<Sala> SolucaoSaAlocacaoSalaCompleta::listaSala() const
{
    return m_listaSala;
}

void SolucaoSaAlocacaoSalaCompleta::setListaSala(const std::vector<Sala> &listaSala)
{
    m_listaSala = listaSala;
}

void SolucaoSaAlocacaoSalaCompleta::addSolucaoNoDia(ISolucaoSa *solucao, const DiaSemana &dia)
{
    m_solucoes[dia-1] = solucao;
}

std::string SolucaoSaAlocacaoSalaCompleta::toString()
{
    assert( 0 );
}

void SolucaoSaAlocacaoSalaCompleta::clear()
{
    m_listaSala.clear();
    m_turmaPorDia.clear();
    m_solucoes.clear();
}

int SolucaoSaAlocacaoSalaCompleta::tamanhoSolucaoSa() const
{
    return sizeof( SolucaoSaAlocacaoSalaCompleta );
}

ISolucaoSa *SolucaoSaAlocacaoSalaCompleta::gerarVizinho() const
{
    return 0;
}

void SolucaoSaAlocacaoSalaCompleta::copia(const ISolucaoSa &solucao)
{
    memcpy( this, &solucao, sizeof( SolucaoSaAlocacaoSalaCompleta ) );
}

long SolucaoSaAlocacaoSalaCompleta::gerarCusto()
{
    m_custo = 0;
    for( unsigned int i = 0; i < m_solucoes.size(); i++ ){
        m_custo += m_solucoes[i]->gerarCusto();
    }

    return m_custo;
}


