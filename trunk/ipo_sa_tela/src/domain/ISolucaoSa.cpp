#include "ISolucaoSa.h"

ISolucaoSa::ISolucaoSa()
    : m_custo( 0 ), m_tempoExecucao( 0.0 )
{
}

ISolucaoSa::~ISolucaoSa()
{
}

long ISolucaoSa::custo() const
{
    return m_custo;
}

float ISolucaoSa::tempoExecucao() const
{
    return m_tempoExecucao;
}

void ISolucaoSa::setTempoExecucao(float tempoExecucao)
{
    m_tempoExecucao = tempoExecucao;
}
