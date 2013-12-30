#ifndef SOLUCAOSAALOCACAOSALA_H
#define SOLUCAOSAALOCACAOSALA_H

#include <src/domain/ISolucaoSa.h>
#include <src/domain/alocacaoSala/Sala.h>
#include <vector>

class SolucaoSaAlocacaoSala : public ISolucaoSa
{
public:
    SolucaoSaAlocacaoSala();
    virtual ~SolucaoSaAlocacaoSala();

    std::vector<Sala> listaSala() const;
    void setListaSala(const std::vector<Sala> &listaSala);
    std::string toString();

// metodos virtuais
public:
    // resulta em uma solucao inicial usando GRASP
    void geraSolucaoInicial();

    // retorna sizeof da classe Solucao em questao
    int tamanhoSolucaoSa() const;

    // gera vizinho a partir da solucao atual
    ISolucaoSa* gerarVizinho() const;

    // copia os dados de uma solucao para outra
    void copia( const ISolucaoSa& solucao );

private:
    std::vector<Sala> m_listaSala;
};

#endif // SOLUCAOSAALOCACAOSALA_H
