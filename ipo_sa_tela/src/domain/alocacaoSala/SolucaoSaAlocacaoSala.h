#ifndef SOLUCAOSAALOCACAOSALA_H
#define SOLUCAOSAALOCACAOSALA_H

#include <src/domain/ISolucaoSa.h>
#include <src/domain/alocacaoSala/Sala.h>
#include <vector>
#include <list>
#include <set>

class SolucaoSaAlocacaoSala : public ISolucaoSa
{
public:
    static const int FATOR_ALUNO_SALA_VIRTUAL = 500;
public:
    SolucaoSaAlocacaoSala();
    virtual ~SolucaoSaAlocacaoSala();

    int qtdeSalaVirtual() const;
    void setQtdeSalaVirtual(int qtdeSalaVirtual);

    std::vector<Sala> listaSala() const;
    void setListaSala(const std::vector<Sala> &listaSala);

    std::vector<std::vector<int> > matrizHorarioPorSala() const;
    void setMatrizHorarioPorSala(const std::vector<std::vector<int> > &matrizHorarioPorSala);

    std::list<Turma> turmasSalaVirtual() const;
    void setTurmasSalaVirtual(const std::list<Turma> &turmasSalaVirtual);

    std::vector<Turma> listaTurma() const;
    void setListaTurma(const std::vector<Turma> &listaTurma);

    int maiorHorarioTurmas() const;
    void setMaiorHorarioTurmas(int maiorHorarioTurmas);

    void gerarMatrizInicial();

    void gerarSolucaoInicial();

    int getSalaVaziaComCapacidade(const Turma &turma) const;

    void setHorarioPorSala( const Turma& turma, int indiceSala );

    void montarMatriz();

    bool gerarVizinhoPorSalaVirtual();

    bool adicionaTurmaDeSalaVirtual();

    bool trocaPorTurmaDeSalaVirtual();

    void armazenarMaiorHorarioMatriz();

    bool deveGerarVizinhoPelaTroca() const;

    bool gerarVizinhoPorTroca();

    bool gerarVizinhoPorRealocacao();

    void ordenarTurmaPorCodigoParaGeracaoDeVizinho();

    Turma *buscarTurmaPorCodigo( int codigoTurma );

    void incializaSetDeSalas();

    std::set<int>::iterator getIteratorDoInteiroNoSet( std::set<int> setEntrada, int posicao ) const;

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

    // calcula o custo e retorna o valor calculado
    long int gerarCusto();

private:

    // salar virtuais, salas utilizadas principalmente para solucao inicial
    /*
     *
     *Capacidade salas     capacidade turma     Resultado
     *  50                      50                  Alocado
     *  50                      50                  Alocado
     *  40                      50                  virtual
     */
    int m_qtdeSalaVirtual;

    // vetor de salas dessa solucao
    std::vector<Sala> m_listaSala;

    /*
     *matriz horarioXsala com o codigo da turma na sala que foi alocada em determinado
     *horario para certa turma
     */
    std::vector< std::vector<int> > m_matrizHorarioPorSala;

    /*
     *lista de turmas que estao na sala virtual
     *Usada na geracao de vizinho para ver se alguma turma em sala
     *virtual pode ser alocada em alguma sala na nova solucao
     */
    std::list<Turma> m_turmasSalaVirtual;

    /*
     *Armazena o maior horario que as turma de entrada podem atiginr
     *utilizado para gerar o numero randomico para gerar vizinhos
     */
    int m_maiorHorarioTurmas;

    // vetor de turmas dessa solucao
    std::vector<Turma> m_listaTurma;

    // set com as salas existente
    std::set<int> m_setSalas;
};

#endif // SOLUCAOSAALOCACAOSALA_H
