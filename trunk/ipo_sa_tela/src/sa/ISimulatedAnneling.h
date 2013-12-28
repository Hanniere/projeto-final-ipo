#ifndef ISIMULATEDANNELING_H
#define ISIMULATEDANNELING_H

#include <string>

class ISimulatedAnneling
{
public:
    ISimulatedAnneling();
    virtual bool carregarDadosEntrada( const std::string& nomeArquivo ) = 0;
};

#endif // ISIMULATEDANNELING_H
