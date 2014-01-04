#ifndef CODIGOTURMAFUNCTORTEST_H
#define CODIGOTURMAFUNCTORTEST_H

#include <src/domain/functor/CodigoTurmaFunctor.h>
#include <vector>
#include<algorithm>
#include <cassert>

void ordenaCoridgoTurmaCrescenteOK(){
    std::vector<Turma> vetorTurma;
    Turma turmaAux;

    turmaAux.setCodigoTurma(10);
    vetorTurma.push_back( turmaAux );

    turmaAux.setCodigoTurma(90);
    vetorTurma.push_back( turmaAux );

    turmaAux.setCodigoTurma(50);
    vetorTurma.push_back( turmaAux );

    turmaAux.setCodigoTurma(40);
    vetorTurma.push_back( turmaAux );

    std::sort( vetorTurma.begin(), vetorTurma.end(),
               CodigoTurmaCrescenteFunctor() );

    assert( vetorTurma.at(0).codigoTurma() == 10 );
    assert( vetorTurma.at(1).codigoTurma() == 40 );
    assert( vetorTurma.at(2).codigoTurma() == 50 );
    assert( vetorTurma.at(3).codigoTurma() == 90 );
}

void ordenaCoridgoTurmaDecrescenteOK(){
    std::vector<Turma> vetorTurma;
    Turma turmaAux;

    turmaAux.setCodigoTurma(10);
    vetorTurma.push_back( turmaAux );

    turmaAux.setCodigoTurma(90);
    vetorTurma.push_back( turmaAux );

    turmaAux.setCodigoTurma(50);
    vetorTurma.push_back( turmaAux );

    turmaAux.setCodigoTurma(40);
    vetorTurma.push_back( turmaAux );

    std::sort( vetorTurma.begin(), vetorTurma.end(),
               CodigoTurmaDecrescenteFunctor() );

    assert( vetorTurma.at(3).codigoTurma() == 10 );
    assert( vetorTurma.at(2).codigoTurma() == 40 );
    assert( vetorTurma.at(1).codigoTurma() == 50 );
    assert( vetorTurma.at(0).codigoTurma() == 90 );
}


#endif // CODIGOTURMAFUNCTORTEST_H
