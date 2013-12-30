#ifndef DEMANDATURMAFUNCTOR_H
#define DEMANDATURMAFUNCTOR_H

#include <src/domain/alocacaoSala/Turma.h>

struct DemandaTurmaCrescenteFunctor
{
    bool operator()( const Turma& turma1, const Turma& turma2 )
    {
        return (turma1.demanda() < turma2.demanda() );
    }
};

struct DemandaTurmaDecrescenteFunctor
{
    bool operator()( const Turma& turma1, const Turma& turma2 )
    {
        return (turma1.demanda() > turma2.demanda() );
    }
};

#endif // DEMANDATURMAFUNCTOR_H
