#ifndef CAPACIDADESALAFUNCTORTEST_H
#define CAPACIDADESALAFUNCTORTEST_H

#include <src/domain/functor/CapacidadeSalaFunctor.h>
#include <vector>
#include<algorithm>
#include <cassert>

void ordenaCapacidadeCrescenteOK(){
    std::vector<Sala> vetorSala;
    Sala salaAux;

    salaAux.setCapacidade(10);
    vetorSala.push_back( salaAux );

    salaAux.setCapacidade(90);
    vetorSala.push_back( salaAux );

    salaAux.setCapacidade(50);
    vetorSala.push_back( salaAux );

    salaAux.setCapacidade(40);
    vetorSala.push_back( salaAux );

    std::sort( vetorSala.begin(), vetorSala.end(),
               CapacidadeSalaCrescenteFunctor() );

    assert( vetorSala.at(0).capacidade() == 10 );
    assert( vetorSala.at(1).capacidade() == 40 );
    assert( vetorSala.at(2).capacidade() == 50 );
    assert( vetorSala.at(3).capacidade() == 90 );
}

void ordenaCapacidadeDecrescenteOK(){
    std::vector<Sala> vetorSala;
    Sala salaAux;

    salaAux.setCapacidade(10);
    vetorSala.push_back( salaAux );

    salaAux.setCapacidade(90);
    vetorSala.push_back( salaAux );

    salaAux.setCapacidade(50);
    vetorSala.push_back( salaAux );

    salaAux.setCapacidade(40);
    vetorSala.push_back( salaAux );

    std::sort( vetorSala.begin(), vetorSala.end(),
               CapacidadeSalaDecrescenteFunctor() );

    assert( vetorSala.at(3).capacidade() == 10 );
    assert( vetorSala.at(2).capacidade() == 40 );
    assert( vetorSala.at(1).capacidade() == 50 );
    assert( vetorSala.at(0).capacidade() == 90 );
}

#endif // CAPACIDADESALAFUNCTORTEST_H
