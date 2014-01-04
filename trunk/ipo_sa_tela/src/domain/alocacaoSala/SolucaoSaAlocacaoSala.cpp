#include "SolucaoSaAlocacaoSala.h"

#include <src/domain/functor/CapacidadeSalaFunctor.h>
#include <src/domain/functor/DemandaTurmaFunctor.h>
#include <src/util/MathUtil.h>
#include <algorithm>
#include <cstring>
#include <set>
#include <cassert>

SolucaoSaAlocacaoSala::SolucaoSaAlocacaoSala()
    : m_qtdeSalaVirtual( -1 ), m_listaSala( std::vector<Sala>() ),
      m_matrizHorarioPorSala( std::vector< std::vector<int> >() ),
      m_turmasSalaVirtual( std::list<Turma>() ), m_listaTurma(  std::vector<Turma>() )
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

void SolucaoSaAlocacaoSala::gerarSolucaoInicial()
{
    gerarMatrizInicial();

    montarMatriz();

    armazenarMaiorHorarioMatriz();
}

int SolucaoSaAlocacaoSala::getSalaVaziaComCapacidade( const Turma& turma ) const
{
    for( unsigned int i = 0; i < m_listaSala.size(); i++ ){

        if( m_listaSala[i].capacidade() >= turma.demanda() ){
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

void SolucaoSaAlocacaoSala::montarMatriz()
{
    m_qtdeSalaVirtual = 0;

    std::sort( m_listaTurma.begin(), m_listaTurma.end(),
               DemandaTurmaDecrescenteFunctor() );

    std::sort( m_listaSala.begin(), m_listaSala.end(),
               CapacidadeSalaDecrescenteFunctor() );

    // varre turmas
    for( std::vector<Turma>::const_iterator it = m_listaTurma.begin(), end = m_listaTurma.end();
         it != end; ++it ){

        int salaVazia =  getSalaVaziaComCapacidade( *it );
        if( salaVazia != -1 ) {
            m_matrizHorarioPorSala[ (*it).horario() ][salaVazia] = (*it).codigoTruma();
        }
        else{
            m_qtdeSalaVirtual++;
            // adiciona na lista de turmas sem sala
            m_turmasSalaVirtual.push_back( *it );
        }
    }
}

bool SolucaoSaAlocacaoSala::gerarVizinhoPorSalaVirtual()
{
    if( qtdeSalaVirtual() > 0 ){

        // adiciona turma da sala virtual a solucao
        for( std::list<Turma>::const_iterator it = m_turmasSalaVirtual.begin(), end = m_turmasSalaVirtual.end();
             it != end; ++it ){

            int salaVazia =  getSalaVaziaComCapacidade( *it );
            if( salaVazia != -1 ) {
                m_matrizHorarioPorSala[ (*it).horario() ][salaVazia] = (*it).codigoTruma();

                m_qtdeSalaVirtual--;
                // adiciona na lista de turmas sem sala
                m_turmasSalaVirtual.remove( *it );

                return true;
            }
        }
    }

    return false;
}

void SolucaoSaAlocacaoSala::armazenarMaiorHorarioMatriz()
{
    m_maiorHorarioTurmas = -1;
    for( unsigned int i = 0; i < m_listaTurma.size(); i++ ){
        int temp = m_listaTurma.at(i).horario();
        if( temp > m_maiorHorarioTurmas )
            m_maiorHorarioTurmas = temp;
    }
}

bool SolucaoSaAlocacaoSala::deveGerarVizinhoPelaTroca() const
{
    int rand = MathUtil::random();
    if (rand & 1){
        return true;
    }

    return false;
}

void SolucaoSaAlocacaoSala::gerarVizinhoPorTroca()
{
    int linhaElemento1 = MathUtil::randomLimitado( m_maiorHorarioTurmas );
    int colunaElemento1 = MathUtil::randomLimitado( m_listaSala.size() );
    int linhaElemento2 = MathUtil::randomLimitado( m_maiorHorarioTurmas );
    int colunaElemento2 = MathUtil::randomLimitado( m_listaSala.size() );

    // garantir que nao troque -1 por -1 para gerar o vizinho
    while( m_matrizHorarioPorSala.at(linhaElemento1).at( colunaElemento1 ) == -1 ){
        linhaElemento1 = MathUtil::randomLimitado( m_maiorHorarioTurmas );
        colunaElemento1 = MathUtil::randomLimitado( m_listaSala.size() );
    }

    int temp = m_matrizHorarioPorSala.at(linhaElemento2).at( colunaElemento2 );
    m_matrizHorarioPorSala.at(linhaElemento2).at( colunaElemento2 ) =
             m_matrizHorarioPorSala.at(linhaElemento1).at( colunaElemento1 );

    m_matrizHorarioPorSala.at(linhaElemento1).at( colunaElemento1 ) = temp;
}

void SolucaoSaAlocacaoSala::gerarVizinhoPorRealocacao()
{
    int linhaElemento1 = MathUtil::randomLimitado( m_maiorHorarioTurmas );
    int colunaElemento1 = MathUtil::randomLimitado( m_listaSala.size() );
    int linhaElemento2, colunaElemento2;

    bool realocou = false;
    do{
        linhaElemento2 = MathUtil::randomLimitado( m_maiorHorarioTurmas );
        colunaElemento2 = MathUtil::randomLimitado( m_listaSala.size() );

        if( m_matrizHorarioPorSala.at(linhaElemento2).at( colunaElemento2 ) == -1 ){
            // realoca
            m_matrizHorarioPorSala.at(linhaElemento2).at( colunaElemento2 ) =
                    m_matrizHorarioPorSala.at(linhaElemento1).at( colunaElemento1 );

            m_matrizHorarioPorSala.at(linhaElemento1).at( colunaElemento1 ) = -1;

            realocou = true;
        }
    }while( realocou == false );
}

int SolucaoSaAlocacaoSala::tamanhoSolucaoSa() const
{
    return sizeof( SolucaoSaAlocacaoSala );
}

ISolucaoSa *SolucaoSaAlocacaoSala::gerarVizinho() const
{
    SolucaoSaAlocacaoSala* retorno = new SolucaoSaAlocacaoSala();

    memcpy( retorno, this, sizeof( SolucaoSaAlocacaoSala ) );

    if( retorno->gerarVizinhoPorSalaVirtual() == false ){

        if( retorno->deveGerarVizinhoPelaTroca() == true ) {
            retorno->gerarVizinhoPorTroca();
        }
        else{
            retorno->gerarVizinhoPorRealocacao();
        }
    }

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

std::list<Turma> SolucaoSaAlocacaoSala::turmasSalaVirtual() const
{
    return m_turmasSalaVirtual;
}

void SolucaoSaAlocacaoSala::setTurmasSalaVirtual(const std::list<Turma> &turmasSalaVirtual)
{
    m_turmasSalaVirtual = turmasSalaVirtual;
}

int SolucaoSaAlocacaoSala::qtdeSalaVirtual() const
{
    return m_qtdeSalaVirtual;
}

void SolucaoSaAlocacaoSala::setQtdeSalaVirtual(int qtdeSalaVirtual)
{
    m_qtdeSalaVirtual = qtdeSalaVirtual;
}

int SolucaoSaAlocacaoSala::maiorHorarioTurmas() const
{
    return m_maiorHorarioTurmas;
}

void SolucaoSaAlocacaoSala::setMaiorHorarioTurmas(int maiorHorarioTurmas)
{
    m_maiorHorarioTurmas = maiorHorarioTurmas;
}


std::vector<Turma> SolucaoSaAlocacaoSala::listaTurma() const
{
    return m_listaTurma;
}

void SolucaoSaAlocacaoSala::setListaTurma(const std::vector<Turma> &listaTurma)
{
    m_listaTurma = listaTurma;
}