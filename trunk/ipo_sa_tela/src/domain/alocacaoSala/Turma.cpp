#include "Turma.h"

Turma::Turma()
    : m_codigoTruma( -1 ), m_demanda( -1 ), m_diaSemana( DIA_INVALIDO ), m_horario( -1 )
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

bool Turma::operator ==(const Turma &outro)
{
    if( m_codigoTruma == outro.codigoTruma() ){
        if( m_demanda == outro.demanda() ){
            if( m_diaSemana == outro.diaSemana() ){
                if( m_horario == outro.horario() )
                    return true;
            }
        }
    }

    return false;
}

DiaSemana Turma::diaSemana() const
{
    return m_diaSemana;
}

void Turma::setDiaSemana(const DiaSemana &diaSemana)
{
    m_diaSemana = diaSemana;
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
