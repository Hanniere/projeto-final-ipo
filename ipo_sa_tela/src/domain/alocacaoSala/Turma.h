#ifndef TURMA_H
#define TURMA_H

#include <src/enum/DiaSemana.h>

class Turma
{
public:
    Turma();
    virtual ~Turma();

    int codigoTruma() const;
    void setCodigoTruma(int codigoTruma);

    int demanda() const;
    void setDemanda(int demanda);

    DiaSemana diaSemanda() const;
    void setDiaSemanda(const DiaSemana &diaSemanda);

    int horario() const;
    void setHorario(int horario);

private:
    // codigo da turma
    int m_codigoTruma;

    // demanda da turma ( tamanho )
    int m_demanda;

    // dia da semana da turma
    DiaSemana m_diaSemanda;

    // campo dinamico, representa horario, exemplo: 1 = 07:00, 2 = 07:50, 3 = 08:40
    int m_horario;
};

#endif // TURMA_H
