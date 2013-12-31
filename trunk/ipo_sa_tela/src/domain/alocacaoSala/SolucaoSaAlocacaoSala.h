#ifndef SOLUCAOSAALOCACAOSALA_H
#define SOLUCAOSAALOCACAOSALA_H

#include <src/domain/ISolucaoSa.h>
#include <src/domain/alocacaoSala/Sala.h>
#include <vector>

class SolucaoSaAlocacaoSala : public ISolucaoSa
{
public:
    static const int QTDE_HORARIOS_DEFAULT = 20;

    SolucaoSaAlocacaoSala();
    virtual ~SolucaoSaAlocacaoSala();

    std::vector<Sala> listaSala() const;
    void setListaSala(const std::vector<Sala> &listaSala);

    std::vector<std::vector<int> > matrizHorarioPorSala() const;
    void setMatrizHorarioPorSala(const std::vector<std::vector<int> > &matrizHorarioPorSala);

    void gerarMatrizInicial();

    void gerarSolucaoInicial( const std::vector<Turma>& vetorTurma );

    int getSalaVaziaComCapacidade(const Turma &turma, const std::vector<Sala> vetorSala) const;

    void setHorarioPorSala( const Turma& turma, int indiceSala );

    void montarMatriz(std::vector<Sala> vetorSalaAux, std::vector<Turma> vetorTurmaAux);

// metodos virtuais
public:
    std::string toString();

    // retorna sizeof da classe Solucao em questao
    int tamanhoSolucaoSa() const;

    // gera vizinho a partir da solucao atual
    ISolucaoSa* gerarVizinho() const;

    // copia os dados de uma solucao para outra
    void copia( const ISolucaoSa& solucao );

    // zera solucao
    void clear();

private:
    std::vector<Sala> m_listaSala;
    std::vector< std::vector<int> > m_matrizHorarioPorSala;
};

#endif // SOLUCAOSAALOCACAOSALA_H
