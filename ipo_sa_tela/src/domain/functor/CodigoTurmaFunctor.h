#ifndef CODIGOTURMAFUNCTOR_H
#define CODIGOTURMAFUNCTOR_H

#include <src/domain/alocacaoSala/Turma.h>

struct CodigoTurmaCrescenteFunctor
{
    bool operator()( const Turma& turma1, const Turma& turma2 )
    {
        return (turma1.codigoTurma() < turma2.codigoTurma() );
    }
};

struct CodigoTurmaDecrescenteFunctor
{
    bool operator()( const Turma& turma1, const Turma& turma2 )
    {
        return (turma1.codigoTurma() > turma2.codigoTurma() );
    }
};

#endif // CODIGOTURMAFUNCTOR_H
