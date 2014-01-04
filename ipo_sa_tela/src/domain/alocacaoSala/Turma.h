#ifndef TURMA_H
#define TURMA_H

#include <src/enum/DiaSemana.h>

class Turma
{
public:
    Turma();
    virtual ~Turma();

    int demanda() const;
    void setDemanda(int demanda);

    DiaSemana diaSemana() const;
    void setDiaSemana(const DiaSemana &diaSemana);

    int horario() const;
    void setHorario(int horario);

    bool operator==(const Turma& outro );

    int codigoTurma() const;
    void setCodigoTurma(int codigoTurma);

private:
    // codigo da turma
    int m_codigoTurma;

    // demanda da turma ( tamanho )
    int m_demanda;

    // dia da semana da turma
    DiaSemana m_diaSemana;

    // campo dinamico, representa horario, exemplo: 1 = 07:00, 2 = 07:50, 3 = 08:40
    int m_horario;
};

#endif // TURMA_H
