#ifndef SIMULATEDANNELINGALOCACAOSALATEST_H
#define SIMULATEDANNELINGALOCACAOSALATEST_H

#include <src/sa/alocacaoSala/SimulatedAnnelingAlocacaoSala.h>
#include <src/domain/alocacaoSala/SolucaoSaAlocacaoSala.h>
#include <cassert>

void testeAlocacaoSolucaoOK(){
    SimulatedAnnelingAlocacaoSala sa;
    SolucaoSaAlocacaoSala* solucao = (SolucaoSaAlocacaoSala*)sa.alocaSolucao();
    assert( solucao != 0 );
    assert( solucao->funcaoObjAnterior() == - 1 );
    assert( solucao->funcaoObjAtual() == - 1 );
    assert( solucao->qtdeSalaVirtual() == - 1 );
    assert( solucao->listaSala().size() == 0 );
    assert( solucao->turmasSalaVirtual().size() == 0 );
    assert( solucao->matrizHorarioPorSala().size() == 0 );

    delete solucao;
}

#endif // SIMULATEDANNELINGALOCACAOSALATEST_H
