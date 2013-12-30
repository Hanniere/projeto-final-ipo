#ifndef SALA_H
#define SALA_H

#include <vector>
#include <src/domain/alocacaoSala/Turma.h>

class Sala
{
public:
    Sala();
    virtual ~Sala();

    int codigoSala() const;
    void setCodigoSala(int codigoSala);

    int capacidade() const;
    void setCapacidade(int capacidade);

    std::vector<Turma> listaTurma() const;
    void setListaTurma(const std::vector<Turma> &listaTurma);

private:
    // codigo referente a sala
    int m_codigoSala;

    // capacidade da sala
    int m_capacidade;

    // lista de turmas associadas a essa sala
    std::vector<Turma> m_listaTurma;

    // valor da funcao objetivo
    //int m_valorFuncaoObj;
};

#endif // SALA_H
