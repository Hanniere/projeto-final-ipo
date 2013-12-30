#ifndef CAPACIDADESALAFUNCTOR_H
#define CAPACIDADESALAFUNCTOR_H

#include <src/domain/alocacaoSala/Sala.h>

struct CapacidadeSalaCrescenteFunctor
{
    bool operator()( const Sala& sala1, const Sala& sala2 )
    {
        return (sala1.capacidade() < sala2.capacidade() );
    }
};

struct CapacidadeSalaDecrescenteFunctor
{
    bool operator()( const Sala& sala1, const Sala& sala2 )
    {
        return (sala1.capacidade() > sala2.capacidade() );
    }
};

#endif // CAPACIDADESALAFUNCTOR_H
