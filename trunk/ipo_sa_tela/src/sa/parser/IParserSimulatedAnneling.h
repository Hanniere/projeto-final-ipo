#ifndef IPARSERSIMULATEDANNELING_H
#define IPARSERSIMULATEDANNELING_H

#include <string>

class IParserSimulatedAnneling
{
public:
    IParserSimulatedAnneling();

    virtual bool parse( const std::string& entrada ) = 0;
};

#endif // IPARSERSIMULATEDANNELING_H
