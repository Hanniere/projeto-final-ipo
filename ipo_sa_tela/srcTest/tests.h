#ifndef TESTS_H
#define TESTS_H

#include <srcTest/sa/parser/alocacaoSala/ParserSimulatedAnnelingAlocacaoSalaArquivoTest.h>
#include <srcTest/sa/factory/SimulatedAnnelingFactoryTest.h>
#include <srcTest/sa/alocacaoSala/SimulatedAnnelingAlocacaoSalaTest.h>
#include <srcTest/domain/functor/DemandaTurmaFunctorTest.h>
#include <srcTest/domain/functor/CapacidadeSalaFunctorTest.h>
#include <srcTest/util/MathUtilTest.h>
#include <srcTest/domain/alocacaoSala/SolucaoSaAlocacaoSalaTest.h>
#include <srcTest/domain/functor/CodigoTurmaFunctorTest.h>

void mainTestes(){
    // ParserSimulatedAnnelingAlocacaoSalaArquivoTest
    parseDadosEntradaArquivoTxtOk();
    parseDadosEntradaArquivoTxtNOkDiaInvalido();
    parseDadosEntradaArquivoTxtNOkDiaMaiorDomingo();

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
    randomMaiorZeroMenorUm();
    ramdomLimitadoZero();

    // SolucaoSaAlocacaoSalaTest
    testeGeraMatrizInicialOk();
    testeGetSalaVaziaComCapacidadeOk();
    testeMontarMatrizOk();
    testeGerarVizinhoSalaVirtualOk();
    testeArmazenarMaiorHorarioMatrizOk();
    testeBuscarTurmaCodigoOk();

    // CodigoTurmaFunctorTest
    ordenaCoridgoTurmaCrescenteOK();
    ordenaCoridgoTurmaDecrescenteOK();
}

#endif // TESTS_H
