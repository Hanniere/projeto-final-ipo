#include "Sala.h"

Sala::Sala()
    : m_codigoSala( -1 ), m_capacidade( -1 )
{
}

Sala::~Sala()
{
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

std::string Sala::descricaoSala() const
{
    return m_descricaoSala;
}

void Sala::setDescricaoSala(const std::string &descricaoSala)
{
    m_descricaoSala = descricaoSala;
}
