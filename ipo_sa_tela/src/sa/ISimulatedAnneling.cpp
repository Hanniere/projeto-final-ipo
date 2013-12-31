#include "ISimulatedAnneling.h"
#include <src/domain/ISolucaoSa.h>
#include <src/util/MathUtil.h>
#include <cstring> // memcpy

ISimulatedAnneling::ISimulatedAnneling()
    : m_numeroIteracoes( -1 ), m_taxaResfriamento( 0.0f ), m_temperaturaInicial( 0 )
{
}

ISimulatedAnneling::~ISimulatedAnneling()
{
}

ISolucaoSa *ISimulatedAnneling::simulatedAnneling( ISolucaoSa* solucaoAtual )
{
    ISolucaoSa* melhorSolucao = alocaSolucao();
    ISolucaoSa* vizinho = 0;

    melhorSolucao->copia( *solucaoAtual );

    int numeroIteracoesAtual = 0;
    float temperatura = m_temperaturaInicial;

    while( temperatura > 0 ){
        while( numeroIteracoesAtual < m_numeroIteracoes ){
            numeroIteracoesAtual++;

            vizinho = solucaoAtual->gerarVizinho();

            int delta =  vizinho->funcaoObjAtual() -
                    solucaoAtual->funcaoObjAtual();

            if( delta < 0 ){
                solucaoAtual->copia( *vizinho );

                // desaloca vizinho
                delete vizinho;

                if( solucaoAtual->funcaoObjAtual() <
                        melhorSolucao->funcaoObjAtual() ){

                    melhorSolucao->copia( *solucaoAtual );
                }
            }
            else {//if( ){
                double x = MathUtil::randomEntre0e1();
                if( x < MathUtil::potenciaBaseNeperianda( -delta/temperatura ) )
                   solucaoAtual->copia( *vizinho );
            }
        }

        temperatura = m_taxaResfriamento * temperatura;
        numeroIteracoesAtual = 0;
    }

    return melhorSolucao;
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
