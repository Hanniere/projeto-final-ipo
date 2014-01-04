#ifndef CODIGOTURMAFUNCTOR_H
#define CODIGOTURMAFUNCTOR_H

#include <src/domain/alocacaoSala/Turma.h>
#include <functional>

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

class BuscaPorCodigoTurma:public std::unary_function< Turma, bool >
{
public:
    BuscaPorCodigoTurma(int id) : m_id(id) { }
    bool operator()(const Turma& turma)const
    {
        return (turma.codigoTurma() == m_id);
    }
private:
    int m_id;
};


#endif // CODIGOTURMAFUNCTOR_H
