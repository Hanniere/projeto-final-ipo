#ifndef SOLUCAOSAALOCACAOSALACOMPLETA_H
#define SOLUCAOSAALOCACAOSALACOMPLETA_H

#include <src/domain/ISolucaoSa.h>
#include <src/domain/alocacaoSala/Sala.h>
#include <vector>

class SolucaoSaAlocacaoSalaCompleta : public ISolucaoSa
{
public:
    SolucaoSaAlocacaoSalaCompleta();

    void addSala( const Sala& sala );
    void addTumarNoDia( const Turma& turma, const DiaSemana& dia );
    std::vector<Turma> getTurmasDia( const DiaSemana& dia ) const;

    std::vector<Sala> listaSala() const;
    void setListaSala(const std::vector<Sala> &listaSala);

    void addSolucaoNoDia( ISolucaoSa* solucao, const DiaSemana &dia );

// virtual
public:
    std::string toString();

    // zera solucao
    void clear();

    // retorna sizeof da classe Solucao em questao
    int tamanhoSolucaoSa() const;

    // gera vizinho a partir da solucao atual
    ISolucaoSa* gerarVizinho() const;

    // copia os dados de uma solucao para outra
    void copia( const ISolucaoSa& solucao );

    // calcula o custo e retorna o valor calculado
    long int gerarCusto();

private:
    // lista de salas
    std::vector<Sala> m_listaSala;
    // vetor das turmas por cada dia
    std::vector< std::vector<Turma> > m_turmaPorDia;
    // vetor de solucoes, um para cada dia
    std::vector< ISolucaoSa* > m_solucoes;
};

#endif // SOLUCAOSAALOCACAOSALACOMPLETA_H
