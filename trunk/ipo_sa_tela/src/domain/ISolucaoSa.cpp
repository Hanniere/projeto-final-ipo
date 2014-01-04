#include "ISolucaoSa.h"

ISolucaoSa::ISolucaoSa()
    : m_custo( 0 )
{
}

ISolucaoSa::~ISolucaoSa()
{
}

long ISolucaoSa::custo() const
{
    return m_custo;
}
