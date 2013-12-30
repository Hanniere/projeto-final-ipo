#include "SimulatedAnnelingFactory.h"

#include <src/sa/alocacaoSala/SimulatedAnnelingAlocacaoSala.h>

SimulatedAnnelingFactory* SimulatedAnnelingFactory::sa = 0;

SimulatedAnnelingFactory::SimulatedAnnelingFactory()
{
}

ISimulatedAnneling *SimulatedAnnelingFactory::getSimulatedAnneling(const TipoSimulatedAnneling &tipo) const
{
    ISimulatedAnneling* retorno;

    switch( tipo ){
        case ALOCACAO_SALAS:
            retorno = new SimulatedAnnelingAlocacaoSala();
        break;

        default:
            retorno = 0;
    }

    return retorno;
}

ISimulatedAnnelingFactory *SimulatedAnnelingFactory::getInstance()
{
    if( sa == 0 )
        sa = new SimulatedAnnelingFactory();

    return sa;
}
