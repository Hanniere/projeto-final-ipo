#ifndef SOLUCAOSA_H
#define SOLUCAOSA_H

#include <vector>
#include <domain/alocacaoSala/Sala.h>

class SolucaoSa
{
public:
    SolucaoSa();

    int funcaoObjAtual() const;
    void setFuncaoObjAtual(int funcaoObjAtual);

    int funcaoObjAnterior() const;
    void setFuncaoObjAnterior(int funcaoObjAnterior);

    int qtdeSalaVirtual() const;
    void setQtdeSalaVirtual(int qtdeSalaVirtual);

    std::vector<Sala> listaSala() const;
    void setListaSala(const std::vector<Sala> &listaSala);

private:
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

    // Lista de salas com suas respectivas turmas
    std::vector<Sala> m_listaSala;
};

#endif // SOLUCAOSA_H
