#ifndef SOLUCAOSAALOCACAOSALATEST_H
#define SOLUCAOSAALOCACAOSALATEST_H

#include <src/domain/alocacaoSala/SolucaoSaAlocacaoSala.h>
#include <vector>
#include <cassert>

void testeGeraMatrizInicialOk(){
    SolucaoSaAlocacaoSala sa;
    std::vector<Sala> vetorSala(10);

    std::vector<Turma> vetorTurma;
    Turma turma;
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(0);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(1);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(2);
    vetorTurma.push_back( turma );

    sa.setListaSala( vetorSala );
    sa.setListaTurma( vetorTurma );
    sa.gerarMatrizInicial();

    std::vector< std::vector<int> > matrizHorarioPorSala = sa.matrizHorarioPorSala();

    // varre vetor de horarios
    for( unsigned int i = 0; i < matrizHorarioPorSala.size(); ++i ){

        // todas as linhas tem que ter 10 colunas, 10 salas!
        assert( matrizHorarioPorSala.at(i).size() == 10 );

        std::vector<int>* temp = &matrizHorarioPorSala.at(i);
        // todos os elementos do vetor de sala devem ter valor -1
        for( unsigned int j = 0; j < temp->size(); ++j ){
            assert( temp->at(j) == -1 );
        }
    }
}

void testeGetSalaVaziaComCapacidadeOk(){
    SolucaoSaAlocacaoSala sa;

    std::vector<Sala> vetorSala;
    Sala sala;
    sala.setCapacidade( 50 );
    vetorSala.push_back( sala );
    sala.setCapacidade( 50 );
    vetorSala.push_back( sala );
    sala.setCapacidade( 40 );
    vetorSala.push_back( sala );

    std::vector<Turma> vetorTurma;
    Turma turma;
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(0);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(1);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(2);
    vetorTurma.push_back( turma );

    sa.setListaTurma( vetorTurma );
    sa.setListaSala( vetorSala );
    sa.gerarMatrizInicial();

    int indiceSala = sa.getSalaVaziaComCapacidade( vetorTurma[0] );
    assert( indiceSala == 0 );
    sa.setHorarioPorSala( vetorTurma[0], indiceSala );

    indiceSala = sa.getSalaVaziaComCapacidade( vetorTurma[1] );
    assert( indiceSala == 1 );
    sa.setHorarioPorSala( vetorTurma[1], indiceSala );

    assert( sa.getSalaVaziaComCapacidade( vetorTurma[2] ) == -1 );
}

void testeMontarMatrizOk(){
    SolucaoSaAlocacaoSala sa;

    std::vector<Sala> vetorSala;
    Sala sala;
    sala.setCapacidade( 50 );
    vetorSala.push_back( sala );
    sala.setCapacidade( 50 );
    vetorSala.push_back( sala );
    sala.setCapacidade( 40 );
    vetorSala.push_back( sala );

    std::vector<Turma> vetorTurma;
    Turma turma;
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(0);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(1);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(2);
    vetorTurma.push_back( turma );

    sa.setListaTurma( vetorTurma );
    sa.setListaSala( vetorSala );
    sa.gerarMatrizInicial();
    sa.montarMatriz();

    std::vector< std::vector<int> > matrizHorarioPorSala = sa.matrizHorarioPorSala();

    assert( sa.qtdeSalaVirtual() == 1 );
    assert( matrizHorarioPorSala[0][0] == 0);
    assert( matrizHorarioPorSala[0][1] == 1);
    assert( matrizHorarioPorSala[0][2] == -1);
}

void testeGerarVizinhoSalaVirtualOk(){
    SolucaoSaAlocacaoSala sa;

    std::vector<Sala> vetorSala;
    Sala sala;
    sala.setCapacidade( 50 );
    vetorSala.push_back( sala );
    sala.setCapacidade( 50 );
    vetorSala.push_back( sala );
    sala.setCapacidade( 40 );
    vetorSala.push_back( sala );

    std::vector<Turma> vetorTurma;
    Turma turma;
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(0);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(1);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 1 );
    turma.setCodigoTurma(2);
    vetorTurma.push_back( turma );

    sa.setListaTurma( vetorTurma );
    sa.setListaSala( vetorSala );
    sa.gerarMatrizInicial();

    std::list<Turma> listaTurma;
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(0);
    listaTurma.push_back( turma );

    sa.setTurmasSalaVirtual( listaTurma );
    sa.setQtdeSalaVirtual( listaTurma.size() );
    assert( sa.gerarVizinhoPorSalaVirtual() == true );

    std::vector< std::vector<int> > matrizHorarioPorSala = sa.matrizHorarioPorSala();

    assert( sa.qtdeSalaVirtual() == 0 );
    assert( matrizHorarioPorSala[0][0] == 0);
    assert( matrizHorarioPorSala[0][1] == -1);
    assert( matrizHorarioPorSala[0][2] == -1);

    assert( matrizHorarioPorSala[1][0] == -1);
    assert( matrizHorarioPorSala[1][1] == -1);
    assert( matrizHorarioPorSala[1][2] == -1);
}

void testeArmazenarMaiorHorarioMatrizOk(){
    SolucaoSaAlocacaoSala sa;

    std::vector<Turma> vetorTurma;
    Turma turma;
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(0);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(1);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 3 );
    turma.setCodigoTurma(2);
    vetorTurma.push_back( turma );

    sa.setListaTurma( vetorTurma );
    sa.armazenarMaiorHorarioMatriz();

    assert( sa.maiorHorarioTurmas() == 3 );
}

void testeBuscarTurmaCodigoOk(){
    SolucaoSaAlocacaoSala sa;

    std::vector<Turma> vetorTurma;
    Turma turma;
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(0);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 0 );
    turma.setCodigoTurma(1);
    vetorTurma.push_back( turma );
    turma.setDemanda(50);
    turma.setHorario( 3 );
    turma.setCodigoTurma(2);
    vetorTurma.push_back( turma );

    sa.setListaTurma( vetorTurma );


    Turma* temp = sa.buscarTurmaPorCodigo( 2 );

    assert( temp->demanda() == 50 );
    assert( temp->horario() == 3 );
    assert( temp->codigoTurma() == 2 );
}


#endif // SOLUCAOSAALOCACAOSALATEST_H
