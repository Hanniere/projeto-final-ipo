#ifndef ISOLUCAOSA_H
#define ISOLUCAOSA_H

#include <string>

class ISolucaoSa
{
public:
    ISolucaoSa();
    virtual ~ISolucaoSa();

    int funcaoObjAtual() const;
    void setFuncaoObjAtual(int funcaoObjAtual);

    int funcaoObjAnterior() const;
    void setFuncaoObjAnterior(int funcaoObjAnterior);

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

    virtual std::string toString() = 0;

protected:
    // funcao obj atual
    int m_funcaoObjAtual;

    // funcao obj anterior( corrente )
    int m_funcaoObjAnterior;
};

#endif // ISOLUCAOSA_H
