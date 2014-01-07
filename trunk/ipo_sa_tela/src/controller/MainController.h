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
    void clear();
    std::string executar();

    int numeroIteracoes() const;
    void setNumeroIteracoes(int numeroIteracoes);

    float temperaturaInicial() const;
    void setTemperaturaInicial(float temperaturaInicial);

    float taxaResfriamento() const;
    void setTaxaResfriamento(float taxaResfriamento);

private:
    ISimulatedAnneling* m_simulatedAnneling;
};

#endif // MAINCONTROLLER_H
