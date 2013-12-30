#ifndef DEMANDATURMAFUNCTORTEST_H
#define DEMANDATURMAFUNCTORTEST_H

#include <src/domain/functor/DemandaTurmaFunctor.h>
#include <vector>
#include<algorithm>
#include <cassert>

void ordenaDemandaCrescenteOK(){
    std::vector<Turma> vetorTurma;
    Turma turmaAux;

    turmaAux.setDemanda(10);
    vetorTurma.push_back( turmaAux );

    turmaAux.setDemanda(90);
    vetorTurma.push_back( turmaAux );

    turmaAux.setDemanda(50);
    vetorTurma.push_back( turmaAux );

    turmaAux.setDemanda(40);
    vetorTurma.push_back( turmaAux );

    std::sort( vetorTurma.begin(), vetorTurma.end(),
               DemandaTurmaCrescenteFunctor() );

    assert( vetorTurma.at(0).demanda() == 10 );
    assert( vetorTurma.at(1).demanda() == 40 );
    assert( vetorTurma.at(2).demanda() == 50 );
    assert( vetorTurma.at(3).demanda() == 90 );
}

void ordenaDemandaDecrescenteOK(){
    std::vector<Turma> vetorTurma;
    Turma turmaAux;

    turmaAux.setDemanda(10);
    vetorTurma.push_back( turmaAux );

    turmaAux.setDemanda(90);
    vetorTurma.push_back( turmaAux );

    turmaAux.setDemanda(50);
    vetorTurma.push_back( turmaAux );

    turmaAux.setDemanda(40);
    vetorTurma.push_back( turmaAux );

    std::sort( vetorTurma.begin(), vetorTurma.end(),
               DemandaTurmaDecrescenteFunctor() );

    assert( vetorTurma.at(3).demanda() == 10 );
    assert( vetorTurma.at(2).demanda() == 40 );
    assert( vetorTurma.at(1).demanda() == 50 );
    assert( vetorTurma.at(0).demanda() == 90 );
}
#endif // DEMANDATURMAFUNCTORTEST_H
