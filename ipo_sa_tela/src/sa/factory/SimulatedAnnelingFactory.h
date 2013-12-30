#ifndef SIMULATEDANNELINGFACTORY_H
#define SIMULATEDANNELINGFACTORY_H

#include <src/sa/factory/ISimulatedAnnelingFactory.h>

class SimulatedAnnelingFactory : public ISimulatedAnnelingFactory
{
private:
    SimulatedAnnelingFactory();
    static SimulatedAnnelingFactory* sa;

public:
    ISimulatedAnneling* getSimulatedAnneling( const TipoSimulatedAnneling& tipo ) const;
    static ISimulatedAnnelingFactory* getInstance();
};

#endif // SIMULATEDANNELINGFACTORY_H
