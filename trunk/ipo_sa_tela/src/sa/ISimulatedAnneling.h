#ifndef ISIMULATEDANNELING_H
#define ISIMULATEDANNELING_H

#include <string>

class ISolucaoSa;

class ISimulatedAnneling
{
public:

    ISimulatedAnneling();
    virtual bool carregarDadosEntrada( const std::string& nomeArquivo ) = 0;
    ISolucaoSa* simulatedAnneling();

    int numeroIteracoes() const;
    void setNumeroIteracoes(int numeroIteracoes);

    float temperaturaInicial() const;
    void setTemperaturaInicial(float temperaturaInicial);

    float taxaResfriamento() const;
    void setTaxaResfriamento(float taxaResfriamento);

public:
    virtual ISolucaoSa* geraSolucaoInicial() = 0;

    // Manipulacao da solucao
    virtual ISolucaoSa* alocaSolucao() const = 0;
    virtual int tamanhoSolucaoSa() const = 0;

    // vizinho -> deve verificar se vizinho eh diferente de null para nao alocar novamente
    virtual void gerarVizinho( ISolucaoSa* vizinho, const ISolucaoSa* atual ) const = 0;

private:
    // aloca espaco de memoria para o tipo de solucao do problema e copia os dados
    void copiaSolucaoSa( ISolucaoSa* dest, const ISolucaoSa* origem ) const;

protected:
    // numero de iteracoes na temperatura
    int m_numeroIteracoes;

    // representa o alpha do algoritmo, taxa de resfriamento da temperatura
    float m_taxaResfriamento;

    // temperatura inicial do algoritmo que sera resfriada
    float m_temperaturaInicial;
};

#endif // ISIMULATEDANNELING_H
