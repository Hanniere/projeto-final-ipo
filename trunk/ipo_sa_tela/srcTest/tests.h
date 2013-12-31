#ifndef TESTS_H
#define TESTS_H

#include <srcTest/sa/parser/alocacaoSala/ParserSimulatedAnnelingAlocacaoSalaArquivoTest.h>
#include <srcTest/sa/factory/SimulatedAnnelingFactoryTest.h>
#include <srcTest/sa/alocacaoSala/SimulatedAnnelingAlocacaoSalaTest.h>
#include <srcTest/domain/functor/DemandaTurmaFunctorTest.h>
#include <srcTest/domain/functor/CapacidadeSalaFunctorTest.h>
#include <srcTest/util/MathUtilTest.h>
#include <srcTest/domain/alocacaoSala/SolucaoSaAlocacaoSalaTest.h>

void mainTestes(){
    // ParserSimulatedAnnelingAlocacaoSalaArquivoTest
    parseDadosEntradaArquivoTxtOk();
    parseDadosEntradaArquivoTxtNOkDiaInvalido();
    parseDadosEntradaArquivoTxtNOkDiaMAiorDomingo();

    // SimulatedAnnelingFactoryTest
    instanciaSimulatedAnnelingAlocacaoSalaOk();
    instanciaSimulatedAnnelingNULL();

    // SimulatedAnnelingAlocacaoSalaTest
    testeAlocacaoSolucaoOK();

    // DemandaTurmaFunctorTest
    ordenaDemandaCrescenteOK();
    ordenaDemandaDecrescenteOK();

    // CapacidadeSalaFunctorTest
    ordenaCapacidadeCrescenteOK();
    ordenaCapacidadeDecrescenteOK();

    // MathUtilTest
    expZero();

    // SolucaoSaAlocacaoSalaTest
    testeGeraMatrizInicialOk();
    testeGetSalaVaziaComCapacidadeOk();
    testeMontarMatrizOk();
}

#endif // TESTS_H
