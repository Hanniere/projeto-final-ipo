#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <string>

class ISimulatedAnneling;

class MainController
{
public:
    MainController();
    virtual ~MainController();
    bool carregarDadosEntrada( const std::string& nomeArquivo );
    void setTipoSimulatedAnneling(std::string tipoSa );

private:
    ISimulatedAnneling* m_simulatedAnneling;
};

#endif // MAINCONTROLLER_H
