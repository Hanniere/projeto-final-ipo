#ifndef TESTS_H
#define TESTS_H

#include <srcTest/sa/parser/alocacaoSala/ParserSimulatedAnnelingAlocacaoSalaArquivoTest.h>
#include <srcTest/sa/factory/SimulatedAnnelingFactoryTest.h>

void mainTestes(){
    // ParserSimulatedAnnelingAlocacaoSalaArquivoTest
    parseDadosEntradaArquivoTxtOk();
    parseDadosEntradaArquivoTxtNOkDiaInvalido();
    parseDadosEntradaArquivoTxtNOkDiaMAiorDomingo();

    // SimulatedAnnelingFactoryTest
    instanciaSimulatedAnnelingAlocacaoSalaOk();
    instanciaSimulatedAnnelingNULL();
}

#endif // TESTS_H
