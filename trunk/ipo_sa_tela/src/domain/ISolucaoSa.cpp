#include "ISolucaoSa.h"

ISolucaoSa::ISolucaoSa()
    : m_funcaoObjAtual( -1 ), m_funcaoObjAnterior( -1 )
{
}

ISolucaoSa::~ISolucaoSa()
{
}

int ISolucaoSa::funcaoObjAnterior() const
{
    return m_funcaoObjAnterior;
}

void ISolucaoSa::setFuncaoObjAnterior(int funcaoObjAnterior)
{
    m_funcaoObjAnterior = funcaoObjAnterior;
}

int ISolucaoSa::funcaoObjAtual() const
{
    return m_funcaoObjAtual;
}

void ISolucaoSa::setFuncaoObjAtual(int funcaoObjAtual)
{
    m_funcaoObjAtual = funcaoObjAtual;
}
