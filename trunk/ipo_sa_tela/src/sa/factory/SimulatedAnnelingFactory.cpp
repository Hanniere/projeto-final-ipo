#include "SimulatedAnnelingFactory.h"

#include <sa/SimulatedAnnelingAlocacaoSala.h>

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
