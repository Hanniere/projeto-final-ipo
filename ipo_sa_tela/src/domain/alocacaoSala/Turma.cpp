#include "Turma.h"

Turma::Turma()
    : m_codigoTruma( -1 ), m_demanda( -1 ), m_diaSemanda( DIA_INVALIDO ), m_horario( -1 )
{
}

Turma::~Turma()
{
}

int Turma::horario() const
{
    return m_horario;
}

void Turma::setHorario(int horario)
{
    m_horario = horario;
}

DiaSemana Turma::diaSemanda() const
{
    return m_diaSemanda;
}

void Turma::setDiaSemanda(const DiaSemana &diaSemanda)
{
    m_diaSemanda = diaSemanda;
}

int Turma::demanda() const
{
    return m_demanda;
}

void Turma::setDemanda(int demanda)
{
    m_demanda = demanda;
}

int Turma::codigoTruma() const
{
    return m_codigoTruma;
}

void Turma::setCodigoTruma(int codigoTruma)
{
    m_codigoTruma = codigoTruma;
}
