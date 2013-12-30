#include "ISimulatedAnneling.h"
#include <src/domain/ISolucaoSa.h>
#include <src/util/MathUtil.h>
#include <cstring> // memcpy

ISimulatedAnneling::ISimulatedAnneling()
    : m_numeroIteracoes( -1 ), m_taxaResfriamento( 0.0f ), m_temperaturaInicial( 0 )
{
}

ISolucaoSa *ISimulatedAnneling::simulatedAnneling()
{
    ISolucaoSa* solucaoAtual = geraSolucaoInicial();
    ISolucaoSa* melhorSolucao = 0;
    ISolucaoSa* vizinho = 0;

    copiaSolucaoSa( melhorSolucao, solucaoAtual );

    int numeroIteracoesAtual = 0;
    float temperatura = m_temperaturaInicial;

    while( temperatura > 0 ){
        while( numeroIteracoesAtual < m_numeroIteracoes ){
            numeroIteracoesAtual++;

            gerarVizinho( vizinho, solucaoAtual );
            int delta =  vizinho->funcaoObjAtual() -
                    solucaoAtual->funcaoObjAtual();

            if( delta < 0 ){
                copiaSolucaoSa( solucaoAtual, vizinho );
                if( solucaoAtual->funcaoObjAtual() <
                        melhorSolucao->funcaoObjAtual() ){
                    copiaSolucaoSa( melhorSolucao, solucaoAtual );
                }
            }
            else {//if( ){
                double x = MathUtil::randomEntre0e1();
                if( x < MathUtil::potenciaBaseNeperianda( -delta/temperatura ) )
                   copiaSolucaoSa( solucaoAtual, vizinho );
            }
        }

        temperatura = m_taxaResfriamento * temperatura;
        numeroIteracoesAtual = 0;
    }

    return melhorSolucao;
}

void ISimulatedAnneling::copiaSolucaoSa(ISolucaoSa *dest, const ISolucaoSa *origem) const
{
    if( dest == 0 )
        dest = alocaSolucao();

    memcpy( dest, origem, tamanhoSolucaoSa() );
}

int ISimulatedAnneling::numeroIteracoes() const
{
    return m_numeroIteracoes;
}

void ISimulatedAnneling::setNumeroIteracoes(int numeroIteracoes)
{
    m_numeroIteracoes = numeroIteracoes;
}

float ISimulatedAnneling::temperaturaInicial() const
{
    return m_temperaturaInicial;
}

void ISimulatedAnneling::setTemperaturaInicial(float temperaturaInicial)
{
    m_temperaturaInicial = temperaturaInicial;
}

float ISimulatedAnneling::taxaResfriamento() const
{
    return m_taxaResfriamento;
}

void ISimulatedAnneling::setTaxaResfriamento(float taxaResfriamento)
{
    m_taxaResfriamento = taxaResfriamento;
}
