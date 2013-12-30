#ifndef ISOLUCAOSA_H
#define ISOLUCAOSA_H

#include <string>

class ISolucaoSa
{
public:
    ISolucaoSa();
    virtual std::string toString() = 0;

    int funcaoObjAtual() const;
    void setFuncaoObjAtual(int funcaoObjAtual);

    int funcaoObjAnterior() const;
    void setFuncaoObjAnterior(int funcaoObjAnterior);

    int qtdeSalaVirtual() const;
    void setQtdeSalaVirtual(int qtdeSalaVirtual);

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
