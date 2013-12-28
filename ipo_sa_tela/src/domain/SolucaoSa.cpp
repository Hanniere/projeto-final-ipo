#include "SolucaoSa.h"

SolucaoSa::SolucaoSa()
    : m_funcaoObjAtual( -1 ), m_funcaoObjAnterior( -1 ), m_qtdeSalaVirtual( -1 ), m_listaSala( std::vector<Sala>() )
{
}

std::vector<Sala> SolucaoSa::listaSala() const
{
    return m_listaSala;
}

void SolucaoSa::setListaSala(const std::vector<Sala> &listaSala)
{
    m_listaSala = listaSala;
}

int SolucaoSa::qtdeSalaVirtual() const
{
    return m_qtdeSalaVirtual;
}

void SolucaoSa::setQtdeSalaVirtual(int qtdeSalaVirtual)
{
    m_qtdeSalaVirtual = qtdeSalaVirtual;
}

int SolucaoSa::funcaoObjAnterior() const
{
    return m_funcaoObjAnterior;
}

void SolucaoSa::setFuncaoObjAnterior(int funcaoObjAnterior)
{
    m_funcaoObjAnterior = funcaoObjAnterior;
}

int SolucaoSa::funcaoObjAtual() const
{
    return m_funcaoObjAtual;
}

void SolucaoSa::setFuncaoObjAtual(int funcaoObjAtual)
{
    m_funcaoObjAtual = funcaoObjAtual;
}
