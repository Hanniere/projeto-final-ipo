#include "SimulatedAnnelingFactory.h"

#include <src/sa/alocacaoSala/SimulatedAnnelingAlocacaoSala.h>

SimulatedAnnelingFactory* SimulatedAnnelingFactory::sa = 0;

SimulatedAnnelingFactory::SimulatedAnnelingFactory()
{
}

ISimulatedAnneling *SimulatedAnnelingFactory::getSimulatedAnneling(const TipoSimulatedAnneling &tipo) const
{
    switch( tipo ){
        case ALOCACAO_SALAS:
            return new SimulatedAnnelingAlocacaoSala();
        break;
    }

    return 0;
}

ISimulatedAnnelingFactory *SimulatedAnnelingFactory::getInstance()
{
    if( sa == 0 )
        sa = new SimulatedAnnelingFactory();

    return sa;
}
