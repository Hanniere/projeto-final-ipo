#ifndef ISIMULATEDANNELING_H
#define ISIMULATEDANNELING_H

#include <string>

class ISolucaoSa;

class ISimulatedAnneling
{
public:

    ISimulatedAnneling();
    virtual ~ISimulatedAnneling();

    virtual bool carregarDadosEntrada( const std::string& nomeArquivo ) = 0;
    virtual ISolucaoSa*simulatedAnneling() = 0;
    ISolucaoSa* simulatedAnneling( ISolucaoSa* solucaoAtual );

    int numeroIteracoes() const;
    void setNumeroIteracoes(int numeroIteracoes);

    float temperaturaInicial() const;
    void setTemperaturaInicial(float temperaturaInicial);

    float taxaResfriamento() const;
    void setTaxaResfriamento(float taxaResfriamento);

public:
    virtual ISolucaoSa* alocaSolucao() const = 0;

    virtual void clear() = 0;

protected:
    // numero de iteracoes na temperatura
    int m_numeroIteracoes;

    // representa o alpha do algoritmo, taxa de resfriamento da temperatura
    float m_taxaResfriamento;

    // temperatura inicial do algoritmo que sera resfriada
    float m_temperaturaInicial;
};

#endif // ISIMULATEDANNELING_H
