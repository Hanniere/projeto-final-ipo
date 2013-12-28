#ifndef SIMULATEDANNELINGFACTORY_H
#define SIMULATEDANNELINGFACTORY_H

#include <sa/factory/ISimulatedAnnelingFactory.h>

class SimulatedAnnelingFactory : public ISimulatedAnnelingFactory
{
public:
    SimulatedAnnelingFactory();
    ISimulatedAnneling* getSimulatedAnneling( const TipoSimulatedAnneling& tipo ) const;
};

#endif // SIMULATEDANNELINGFACTORY_H
