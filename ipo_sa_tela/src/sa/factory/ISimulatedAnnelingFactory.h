#ifndef ISIMULATEDANNELINGFACTORY_H
#define ISIMULATEDANNELINGFACTORY_H

#include <src/enum/TipoSimulatedAnneling.h>

class ISimulatedAnneling;

class ISimulatedAnnelingFactory
{
public:
    ISimulatedAnnelingFactory();
    virtual ISimulatedAnneling* getSimulatedAnneling( const TipoSimulatedAnneling& tipo ) const = 0;
};

#endif // ISIMULATEDANNELINGFACTORY_H
