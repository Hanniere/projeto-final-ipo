#include "SolucaoSaAlocacaoSala.h"

#include <src/domain/functor/CapacidadeSalaFunctor.h>
#include <src/domain/functor/DemandaTurmaFunctor.h>
#include <src/domain/functor/CodigoTurmaFunctor.h>
#include <src/enum/EstadoGeracaoVizinho.h>
#include <src/util/MathUtil.h>
#include <algorithm>
#include <set>
#include <sstream>

SolucaoSaAlocacaoSala::SolucaoSaAlocacaoSala()
    : m_qtdeSalaVirtual( -1 ), m_listaSala( std::vector<Sala>() ),
      m_matrizHorarioPorSala( std::vector< std::vector<int> >() ),
      m_turmasSalaVirtual( std::list<Turma>() ), m_listaTurma(  std::vector<Turma>() )
{
}

SolucaoSaAlocacaoSala::~SolucaoSaAlocacaoSala()
{
}

std::vector<Sala> SolucaoSaAlocacaoSala::listaSala() const
{
    return m_listaSala;
}

void SolucaoSaAlocacaoSala::setListaSala(const std::vector<Sala> &listaSala)
{
    m_listaSala = listaSala;
}

std::string SolucaoSaAlocacaoSala::toString()
{
    std::ostringstream retorno;
    retorno << "Custo: ";
    retorno << this->gerarCusto();
    retorno << std::endl;
    retorno << std::endl;

    retorno << "Turmas Sala Virtual: ";
    retorno << m_turmasSalaVirtual.size();
    retorno << std::endl;
    for( std::list<Turma>::const_iterator it = m_turmasSalaVirtual.begin(), end = m_turmasSalaVirtual.end();
         it != end; ++it ){
        retorno << "Codigo Turma: ";
        retorno << (*it).codigoTurma();
        retorno << std::endl;

        retorno << "Demanda Turma: ";
        retorno << (*it).demanda();
        retorno << std::endl;

        retorno << "Horario Turma: ";
        retorno << (*it).horario();
        retorno << std::endl;

        retorno << "Dia Semana Turma: ";
        retorno << (*it).diaSemana();
        retorno << std::endl;
        retorno << std::endl;
    }

    retorno << std::endl;
    retorno << "Salas Alocadas: ";
    retorno << std::endl;
    for( unsigned int i = 0; i < m_matrizHorarioPorSala.at(0).size(); ++i ){
        retorno << "Codigo Sala: ";
        retorno << m_listaSala.at(i).codigoSala();
        retorno << std::endl;

        retorno << "Capacidade Sala: ";
        retorno << m_listaSala.at(i).capacidade();
        retorno << std::endl;

        for( unsigned int j = 0; j < m_matrizHorarioPorSala.size(); ++j ){
            int codTurma = m_matrizHorarioPorSala.at(j).at(i);
            if( codTurma != -1 ){
                // tem turma alocada
                Turma* turma = buscarTurmaPorCodigo( codTurma );
                retorno << "Codigo Turma: ";
                retorno << turma->codigoTurma();
                retorno << std::endl;

                retorno << "Demanda Turma: ";
                retorno << turma->demanda();
                retorno << std::endl;

                retorno << "Horario Turma: ";
                retorno << turma->horario();
                retorno << std::endl;

                retorno << "Dia Semana Turma: ";
                retorno << turma->diaSemana();
                retorno << std::endl;
                retorno << std::endl;
            }

            retorno << std::endl;
        }
    }

    return retorno.str();
}

void SolucaoSaAlocacaoSala::gerarMatrizInicial(){

    armazenarMaiorHorarioMatriz();

    m_matrizHorarioPorSala = std::vector< std::vector<int> >( m_maiorHorarioTurmas +1 );
    for( int i = 0; i <= m_maiorHorarioTurmas; i++ ){
        m_matrizHorarioPorSala[i] = std::vector<int>( m_listaSala.size(), -1 );
    }
}

void SolucaoSaAlocacaoSala::gerarSolucaoInicial()
{
    gerarMatrizInicial();

    montarMatriz();

    ordenarTurmaPorCodigoParaGeracaoDeVizinho();

    incializaSetDeSalas();
}

int SolucaoSaAlocacaoSala::getSalaVaziaComCapacidade( const Turma& turma ) const
{
    for( unsigned int i = 0; i < m_listaSala.size(); i++ ){

        if( m_listaSala[i].capacidade() >= turma.demanda() ){
            if( m_matrizHorarioPorSala[ turma.horario() ][i] == -1 )
                return i;
        }
    }

    return -1;
}

void SolucaoSaAlocacaoSala::setHorarioPorSala(const Turma &turma, int indiceSala)
{
    m_matrizHorarioPorSala[ turma.horario() ][indiceSala] =  turma.codigoTurma();
}

void SolucaoSaAlocacaoSala::montarMatriz()
{
    m_qtdeSalaVirtual = 0;

    std::sort( m_listaTurma.begin(), m_listaTurma.end(),
               DemandaTurmaDecrescenteFunctor() );

    std::sort( m_listaSala.begin(), m_listaSala.end(),
               CapacidadeSalaDecrescenteFunctor() );

    // varre turmas
    for( std::vector<Turma>::const_iterator it = m_listaTurma.begin(), end = m_listaTurma.end();
         it != end; ++it ){

        int salaVazia =  getSalaVaziaComCapacidade( *it );
        if( salaVazia != -1 ) {
            m_matrizHorarioPorSala[ (*it).horario() ][salaVazia] = (*it).codigoTurma();
        }
        else{
            m_qtdeSalaVirtual++;
            // adiciona na lista de turmas sem sala
            m_turmasSalaVirtual.push_back( *it );
        }
    }
}

bool SolucaoSaAlocacaoSala::gerarVizinhoPorSalaVirtual()
{
    if( qtdeSalaVirtual() > 0 ){

        // adiciona turma da sala virtual a solucao
        for( std::list<Turma>::const_iterator it = m_turmasSalaVirtual.begin(), end = m_turmasSalaVirtual.end();
             it != end; ++it ){

            int salaVazia =  getSalaVaziaComCapacidade( *it );
            if( salaVazia != -1 ) {
                m_matrizHorarioPorSala[ (*it).horario() ][salaVazia] = (*it).codigoTurma();

                m_qtdeSalaVirtual--;
                // adiciona na lista de turmas sem sala
                m_turmasSalaVirtual.remove( *it );

                return true;
            }
        }
    }

    return false;
}

void SolucaoSaAlocacaoSala::armazenarMaiorHorarioMatriz()
{
    m_maiorHorarioTurmas = -1;
    for( unsigned int i = 0; i < m_listaTurma.size(); i++ ){
        int temp = m_listaTurma.at(i).horario();
        if( temp > m_maiorHorarioTurmas )
            m_maiorHorarioTurmas = temp;
    }
}

bool SolucaoSaAlocacaoSala::deveGerarVizinhoPelaTroca() const
{
    int rand = MathUtil::random();
    if (rand & 1){
        return true;
    }

    return false;
}

bool SolucaoSaAlocacaoSala::gerarVizinhoPorTroca()
{
    bool retorno = false;

    int horarioTurma = MathUtil::randomLimitado( m_maiorHorarioTurmas );
    int salaTurma1 = MathUtil::randomLimitado( m_listaSala.size() );
    int salaTurma2 = salaTurma1;

    // garantir que nao troque -1 por -1 para gerar o vizinho
    // armazena id para buscar turma no vetor e ter acesso a seus dados
    int idTurma = m_matrizHorarioPorSala.at(horarioTurma).at( salaTurma1 );
    while( idTurma == -1 ){
        horarioTurma = MathUtil::randomLimitado( m_maiorHorarioTurmas );
        salaTurma1 = MathUtil::randomLimitado( m_listaSala.size() );

        idTurma = m_matrizHorarioPorSala.at(horarioTurma).at( salaTurma1 );
    }

    Turma* turma1 = buscarTurmaPorCodigo( idTurma );

    /*
     * procurar uma sala ocupada no mesmo horario que caiba essa turma
     *e a que for substituida caiba na turma acima
     */

    std::set<int> setSalatTemp = m_setSalas;
    std::set<int>::iterator itSet;
    // limita o indice randomico a ser utilizado na geracao do vizinho
    int indiceMaxSala = setSalatTemp.size();

    do{
        salaTurma2 = MathUtil::randomLimitado( indiceMaxSala );

        itSet = getIteratorDoInteiroNoSet( setSalatTemp, salaTurma2 );
        if( *itSet == salaTurma1 ){
            // se for igual a turma 1 remove e continua
            setSalatTemp.erase( *itSet );
        }
        else{
            // se a capacidade for menor elimina os elementos em sequencia, pois esta ordenado
            if( m_listaSala.at( *itSet ).capacidade() < turma1->demanda() ){
                //setSalatTemp.erase( itSet, setSalatTemp.end() );
                setSalatTemp.erase( *itSet );
            }
            else{
                int temp = m_matrizHorarioPorSala.at(horarioTurma).at( salaTurma2 );
                if( temp == -1 ){
                    // remove do set, pois so podemos fazer troca
                    setSalatTemp.erase( *itSet );
                }else{
                    // realiza a troca, caso a turma dessa posicao puder ir para a antiga
                    Turma* turma2 = buscarTurmaPorCodigo( temp );
                    // pego a sala de turma1 e vejo se turma2 cabe
                    if( m_listaSala.at( salaTurma1 ).capacidade() >= turma2->demanda() ){
                        // pode trocar
                        m_matrizHorarioPorSala.at(horarioTurma).at( salaTurma2 ) =
                                 m_matrizHorarioPorSala.at(horarioTurma).at( salaTurma1 );

                        m_matrizHorarioPorSala.at(horarioTurma).at( salaTurma1 ) = temp;

                        retorno = true;

                        break;
                    }
                    else{
                        // remove do set, pois a troca nao eh possivel ja que a turma dois nao cabee na atual sala da turma1
                        setSalatTemp.erase( *itSet );
                    }
                }
            }
        }

        indiceMaxSala = setSalatTemp.size();

    }while( indiceMaxSala > 0 );

    return retorno;
}

bool SolucaoSaAlocacaoSala::gerarVizinhoPorRealocacao()
{
    bool retorno = false;

    int horarioTurma = MathUtil::randomLimitado( m_maiorHorarioTurmas );
    int salaTurma1 = MathUtil::randomLimitado( m_listaSala.size() );
    int novaSala;

    // garantir que nao realoque uma turma que nao exista ainda
    // armazena id para buscar turma no vetor e ter acesso a seus dados
    int idTurma = m_matrizHorarioPorSala.at(horarioTurma).at( salaTurma1 );
    while( idTurma == -1 ){
        horarioTurma = MathUtil::randomLimitado( m_maiorHorarioTurmas );
        salaTurma1 = MathUtil::randomLimitado( m_listaSala.size() );

        idTurma = m_matrizHorarioPorSala.at(horarioTurma).at( salaTurma1 );
    }

    Turma* turma1 = buscarTurmaPorCodigo( idTurma );

    /*
     * procurar por uma sala desocupada que caiba a turma1
     */

    std::set<int> setSalatTemp = m_setSalas;
    std::set<int>::iterator itSet;
    // limita o indice randomico a ser utilizado na geracao do vizinho
    setSalatTemp.erase( setSalatTemp.find( salaTurma1 ) ); // remove a sala da turma1 da busca
    int indiceMaxSala = setSalatTemp.size();

    do{
        novaSala = MathUtil::randomLimitado( indiceMaxSala );

        itSet = getIteratorDoInteiroNoSet( setSalatTemp, novaSala );

        // se a capacidade for menor elimina os elementos em sequencia, pois esta ordenado
        if( m_listaSala.at( *itSet ).capacidade() < turma1->demanda() ){
            //setSalatTemp.erase( itSet, setSalatTemp.end() );
            setSalatTemp.erase( *itSet );
        }
        else{
            int temp = m_matrizHorarioPorSala.at(horarioTurma).at( novaSala );
            if( temp != -1 ){
                // remove do set, pois so podemos fazer realocacao e como eh != -1 ja tem turma nessa sala
                setSalatTemp.erase( *itSet );
            }else{
                // realiza a realocacao
                m_matrizHorarioPorSala.at(horarioTurma).at( novaSala ) =
                         m_matrizHorarioPorSala.at(horarioTurma).at( salaTurma1 );

                m_matrizHorarioPorSala.at(horarioTurma).at( salaTurma1 ) = -1;

                retorno = true;

                break;
            }
        }

        indiceMaxSala = setSalatTemp.size();

    }while( indiceMaxSala > 0 );

    return retorno;
}

void SolucaoSaAlocacaoSala::ordenarTurmaPorCodigoParaGeracaoDeVizinho()
{
    std::sort( m_listaTurma.begin(), m_listaTurma.end(),
               CodigoTurmaCrescenteFunctor() );
}

Turma* SolucaoSaAlocacaoSala::buscarTurmaPorCodigo(int codigoTurma)
{
    std::vector<Turma>::iterator it =
            std::find_if( m_listaTurma.begin(), m_listaTurma.end(), BuscaPorCodigoTurma(codigoTurma) );

    return &*it;
}

void SolucaoSaAlocacaoSala::incializaSetDeSalas()
{
    for( unsigned int i = 0; i < m_listaSala.size(); i++ )
        m_setSalas.insert( i );
}

std::set<int>::iterator SolucaoSaAlocacaoSala::getIteratorDoInteiroNoSet(std::set<int> setEntrada, int posicao) const
{
    std::set<int>::iterator it = setEntrada.end();
    if( setEntrada.size() > (unsigned int) posicao ){
        it = setEntrada.begin();

        for( int i = 0; i < posicao; i++ )
            ++it;
    }

    return it;
}

int SolucaoSaAlocacaoSala::tamanhoSolucaoSa() const
{
    return sizeof( SolucaoSaAlocacaoSala );
}

ISolucaoSa *SolucaoSaAlocacaoSala::gerarVizinho() const
{
    SolucaoSaAlocacaoSala* retorno = new SolucaoSaAlocacaoSala();

    *retorno = *this;

    if( retorno->gerarVizinhoPorSalaVirtual() == false ){

        EstadoGeracaoVizinho estado;
        if( retorno->deveGerarVizinhoPelaTroca() == true ) {
            estado = FAZER_TROCA;
        }
        else{
            estado = FAZER_REALOCACAO;
        }

        do{
            switch (estado) {
            case FAZER_TROCA:
                if( retorno->gerarVizinhoPorTroca() == false )
                    estado = FALHA_TROCA;
                else
                    estado = ESTADO_GERACAO_VIZINHO_FINAL;

                break;

            case FALHA_TROCA:
                retorno->gerarVizinhoPorRealocacao();
                // deve sair de qualquer forma, pois falhou troca e tentou realocacao
                estado = ESTADO_GERACAO_VIZINHO_FINAL;

                break;

            case FAZER_REALOCACAO:
                if( retorno->gerarVizinhoPorRealocacao() == false )
                    estado = FALHA_REALOCAO;
                else
                    estado = ESTADO_GERACAO_VIZINHO_FINAL;

                break;

            case FALHA_REALOCAO:
                retorno->gerarVizinhoPorTroca();
                // deve sair de qualquer forma, pois falhou realocacao e tentou troca
                estado = ESTADO_GERACAO_VIZINHO_FINAL;

                break;

            default:
                break;
            }
        }while( estado != ESTADO_GERACAO_VIZINHO_FINAL );
    }

    return retorno;
}

void SolucaoSaAlocacaoSala::copia(const ISolucaoSa &solucao)
{
    // no futuro podemos validar o tipo de solucao vinda, mas o dynamic_cat<> eh mto custoso
    SolucaoSaAlocacaoSala* temp = (SolucaoSaAlocacaoSala*)&solucao;
    *this = *temp;
}

void SolucaoSaAlocacaoSala::clear()
{
    m_listaSala.clear();
    m_matrizHorarioPorSala.clear();
}

long SolucaoSaAlocacaoSala::gerarCusto()
{
    m_custo = 0;

    // fazer custo proporcional a quantidade de alunos em salas virtuais
    // priorizar o menor numero de alunos em sala virtual
    // eh mais facil arrumar lugar para menos alunos
    for( std::list<Turma>::const_iterator it = m_turmasSalaVirtual.begin(), end = m_turmasSalaVirtual.end();
         it != end; ++it ){
        m_custo += (*it).demanda() * FATOR_ALUNO_SALA_VIRTUAL;
    }

    // calcula a diferenca da capacidade por demanda e soma no custo
    for( unsigned int i = 0; i < m_matrizHorarioPorSala.size(); i++ ){
        std::vector<int>* temp = &m_matrizHorarioPorSala.at(i);
        for( unsigned int j = 0; j < temp->size(); j++ ){
            int codTurma = temp->at(j);
            if( codTurma != -1 ){
                // calcula custo
                Turma* turma = buscarTurmaPorCodigo( codTurma );
                m_custo += m_listaSala.at(j).capacidade() - turma->demanda();
            }
        }
    }

    return m_custo;
}

std::vector<std::vector<int> > SolucaoSaAlocacaoSala::matrizHorarioPorSala() const
{
    return m_matrizHorarioPorSala;
}

void SolucaoSaAlocacaoSala::setMatrizHorarioPorSala(const std::vector<std::vector<int> > &matrizHorarioPorSala)
{
    m_matrizHorarioPorSala = matrizHorarioPorSala;
}

std::list<Turma> SolucaoSaAlocacaoSala::turmasSalaVirtual() const
{
    return m_turmasSalaVirtual;
}

void SolucaoSaAlocacaoSala::setTurmasSalaVirtual(const std::list<Turma> &turmasSalaVirtual)
{
    m_turmasSalaVirtual = turmasSalaVirtual;
}

int SolucaoSaAlocacaoSala::qtdeSalaVirtual() const
{
    return m_qtdeSalaVirtual;
}

void SolucaoSaAlocacaoSala::setQtdeSalaVirtual(int qtdeSalaVirtual)
{
    m_qtdeSalaVirtual = qtdeSalaVirtual;
}

int SolucaoSaAlocacaoSala::maiorHorarioTurmas() const
{
    return m_maiorHorarioTurmas;
}

void SolucaoSaAlocacaoSala::setMaiorHorarioTurmas(int maiorHorarioTurmas)
{
    m_maiorHorarioTurmas = maiorHorarioTurmas;
}


std::vector<Turma> SolucaoSaAlocacaoSala::listaTurma() const
{
    return m_listaTurma;
}

void SolucaoSaAlocacaoSala::setListaTurma(const std::vector<Turma> &listaTurma)
{
    m_listaTurma = listaTurma;
}
