#include "Sala.h"

Sala::Sala()
    : m_codigoSala( -1 ), m_capacidade( -1 ), m_listaTurma( std::vector<Turma>() )
{
}

std::vector<Turma> Sala::listaTurma() const
{
    return m_listaTurma;
}

void Sala::setListaTurma(const std::vector<Turma> &listaTurma)
{
    m_listaTurma = listaTurma;
}

int Sala::capacidade() const
{
    return m_capacidade;
}

void Sala::setCapacidade(int capacidade)
{
    m_capacidade = capacidade;
}

int Sala::codigoSala() const
{
    return m_codigoSala;
}

void Sala::setCodigoSala(int codigoSala)
{
    m_codigoSala = codigoSala;
}
