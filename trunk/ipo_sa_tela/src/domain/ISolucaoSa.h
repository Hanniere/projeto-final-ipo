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

    int qtdeSalaVirtual() const;
    void setQtdeSalaVirtual(int qtdeSalaVirtual);

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

    // salar virtuais, salas utilizadas principalmente para solucao inicial
    /*
     *
     *Capacidade salas     capacidade turma     Resultado
     *  50                      50                  Alocado
     *  50                      50                  Alocado
     *  40                      50                  virtual
     */
    int m_qtdeSalaVirtual;
};

#endif // ISOLUCAOSA_H
