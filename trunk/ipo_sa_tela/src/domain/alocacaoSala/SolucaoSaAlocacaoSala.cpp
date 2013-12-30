#include "SolucaoSaAlocacaoSala.h"

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

void SolucaoSaAlocacaoSala::geraSolucaoInicial()
{
    // usa GRASP
    assert( 0 );
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

