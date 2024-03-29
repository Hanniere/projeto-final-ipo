#include "Turma.h"

Turma::Turma()
    : m_codigoTurma( -1 ), m_demanda( -1 ), m_diaSemana( DIA_INVALIDO ), m_horario( -1 ), m_descricaoMateria("")
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
    if( m_codigoTurma == outro.codigoTurma() ){
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

int Turma::codigoTurma() const
{
    return m_codigoTurma;
}

void Turma::setCodigoTurma(int codigoTurma)
{
    m_codigoTurma = codigoTurma;
}

std::string Turma::descricaoMateria() const
{
    return m_descricaoMateria;
}

void Turma::setDescricaoMateria(const std::string &descricaoMateria)
{
    m_descricaoMateria = descricaoMateria;
}
