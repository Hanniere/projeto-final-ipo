#include "SolucaoSaAlocacaoSala.h"

#include <src/domain/functor/CapacidadeSalaFunctor.h>
#include <src/domain/functor/DemandaTurmaFunctor.h>
#include<algorithm>
#include <cstring>
#include <cassert>

SolucaoSaAlocacaoSala::SolucaoSaAlocacaoSala()
    : m_listaSala( std::vector<Sala>() )
{
}

SolucaoSaAlocacaoSala::~SolucaoSaAlocacaoSala()
{
}

std::vector<Sala> SolucaoSaAlocacaoSala::listaSala() const
{
    return m_listaSala;
}

void SolucaoSaAlocacaoSala::setListaSala(const std::vector<Sala> &listaSala)
{
    m_listaSala = listaSala;
}

std::string SolucaoSaAlocacaoSala::toString()
{
    assert( 0 );
}

void SolucaoSaAlocacaoSala::gerarMatrizInicial(){
    m_matrizHorarioPorSala = std::vector< std::vector<int> >( QTDE_HORARIOS_DEFAULT );
    for( int i = 0; i < QTDE_HORARIOS_DEFAULT; i++ ){
        m_matrizHorarioPorSala[i] = std::vector<int>( m_listaSala.size(), -1 );
    }
}

void SolucaoSaAlocacaoSala::gerarSolucaoInicial(const std::vector<Turma> &vetorTurma)
{
    gerarMatrizInicial();

    montarMatriz( m_listaSala, vetorTurma );
}

int SolucaoSaAlocacaoSala::getSalaVaziaComCapacidade( const Turma& turma, const std::vector<Sala> vetorSala ) const
{
    for( unsigned int i = 0; i < vetorSala.size(); i++ ){

        if( vetorSala[i].capacidade() >= turma.demanda() ){
            if( m_matrizHorarioPorSala[ turma.horario() ][i] == -1 )
                return i;
        }
    }

    return -1;
}

void SolucaoSaAlocacaoSala::setHorarioPorSala(const Turma &turma, int indiceSala)
{
    m_matrizHorarioPorSala[ turma.horario() ][indiceSala] =  turma.codigoTruma();
}

void SolucaoSaAlocacaoSala::montarMatriz(std::vector<Sala> vetorSalaAux, std::vector<Turma> vetorTurmaAux)
{
    m_qtdeSalaVirtual = 0;

    std::sort( vetorTurmaAux.begin(), vetorTurmaAux.end(),
               DemandaTurmaDecrescenteFunctor() );

    std::sort( vetorSalaAux.begin(), vetorSalaAux.end(),
               CapacidadeSalaDecrescenteFunctor() );

    // varre turmas
    for( unsigned int i = 0; i < vetorTurmaAux.size(); i++ ){
        Turma turma = vetorTurmaAux[i];

        int salaVazia =  getSalaVaziaComCapacidade( turma, vetorSalaAux );
        if( salaVazia != -1 ) {
            m_matrizHorarioPorSala[ turma.horario() ][salaVazia] = turma.codigoTruma();
        }
        else{
            m_qtdeSalaVirtual++;
        }
    }
}

int SolucaoSaAlocacaoSala::tamanhoSolucaoSa() const
{
    return sizeof( SolucaoSaAlocacaoSala );
}

ISolucaoSa *SolucaoSaAlocacaoSala::gerarVizinho() const
{
    ISolucaoSa* retorno = new SolucaoSaAlocacaoSala();

    // random para ver se faz troca ou realocacao
    assert( 0 );

    return retorno;
}

void SolucaoSaAlocacaoSala::copia(const ISolucaoSa &solucao)
{
    // no futuro podemos validar o tipo de solucao vinda, mas o dynamic_cat<> eh mto custoso
    memcpy( this, &solucao, sizeof( SolucaoSaAlocacaoSala ) );
}

void SolucaoSaAlocacaoSala::clear()
{
    m_listaSala.clear();
    m_matrizHorarioPorSala.clear();
}


std::vector<std::vector<int> > SolucaoSaAlocacaoSala::matrizHorarioPorSala() const
{
    return m_matrizHorarioPorSala;
}

void SolucaoSaAlocacaoSala::setMatrizHorarioPorSala(const std::vector<std::vector<int> > &matrizHorarioPorSala)
{
    m_matrizHorarioPorSala = matrizHorarioPorSala;
}
