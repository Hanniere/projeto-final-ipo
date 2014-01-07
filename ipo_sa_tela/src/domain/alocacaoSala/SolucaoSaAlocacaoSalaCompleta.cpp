#include "SolucaoSaAlocacaoSalaCompleta.h"

#include <sstream>

SolucaoSaAlocacaoSalaCompleta::SolucaoSaAlocacaoSalaCompleta()
{
    m_turmaPorDia = std::vector< std::vector<Turma> >( DOMINGO );
    m_solucoes = std::vector< ISolucaoSa* >( DOMINGO );
}

void SolucaoSaAlocacaoSalaCompleta::addSala(const Sala &sala)
{
    m_listaSala.push_back( sala );
}

void SolucaoSaAlocacaoSalaCompleta::addTumarNoDia(const Turma &turma, const DiaSemana &dia)
{
  m_turmaPorDia.at(dia-1).push_back( turma );
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
    std::ostringstream retorno;
    for( unsigned int i = 0; i < m_solucoes.size(); ++i ){
        ISolucaoSa* temp = m_solucoes.at(i);
        if( temp->tempoExecucao() != 0 ){
            retorno << "Tempo Execucao: ";
            retorno << temp->tempoExecucao();
            retorno << std::endl;
            retorno << std::endl;
            retorno << temp->toString();
        }
    }

    return retorno.str();
}

void SolucaoSaAlocacaoSalaCompleta::clear()
{
    *this = SolucaoSaAlocacaoSalaCompleta();
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
    SolucaoSaAlocacaoSalaCompleta* temp = (SolucaoSaAlocacaoSalaCompleta*) &solucao;
    *this = *temp;
}

long SolucaoSaAlocacaoSalaCompleta::gerarCusto()
{
    m_custo = 0;
    for( unsigned int i = 0; i < m_solucoes.size(); i++ ){
        m_custo += m_solucoes[i]->gerarCusto();
    }

    return m_custo;
}
