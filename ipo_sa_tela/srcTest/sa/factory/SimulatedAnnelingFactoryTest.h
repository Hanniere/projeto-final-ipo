#ifndef SIMULATEDANNELINGFACTORYTEST_H
#define SIMULATEDANNELINGFACTORYTEST_H

#include <cassert>
#include <src/sa/factory/SimulatedAnnelingFactory.h>
#include <src/sa/alocacaoSala/SimulatedAnnelingAlocacaoSala.h>

void instanciaSimulatedAnnelingAlocacaoSalaOk(){
    ISimulatedAnneling* sa = SimulatedAnnelingFactory::getInstance()->getSimulatedAnneling( ALOCACAO_SALAS );

    SimulatedAnnelingAlocacaoSala* saNovo = dynamic_cast<SimulatedAnnelingAlocacaoSala*>(sa);
    assert( saNovo != 0 );

    delete sa;
}

void instanciaSimulatedAnnelingNULL(){
    ISimulatedAnneling* sa = SimulatedAnnelingFactory::getInstance()->getSimulatedAnneling( SIMULATED_ANNELING_INVALIDO );
    assert( sa == 0 );
}

#endif // SIMULATEDANNELINGFACTORYTEST_H
