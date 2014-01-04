#ifndef ISOLUCAOSA_H
#define ISOLUCAOSA_H

#include <string>

class ISolucaoSa
{
public:
    ISolucaoSa();
    virtual ~ISolucaoSa();

    long custo() const;

// metodos virtuais
public:

    // retorna sizeof da classe Solucao em questao
    virtual int tamanhoSolucaoSa() const = 0;
    // gera vizinho a partir da solucao atual
    virtual ISolucaoSa* gerarVizinho() const = 0;
    // copia os dados de uma solucao para outra
    virtual void copia( const ISolucaoSa& solucao ) = 0;

    // zera solucao
    virtual void clear() = 0;

    // to string da solucao
    virtual std::string toString() = 0;

    // calcula o custo e retorna o valor calculado
    virtual long int gerarCusto() = 0;

protected:
    long int m_custo;
};

#endif // ISOLUCAOSA_H
