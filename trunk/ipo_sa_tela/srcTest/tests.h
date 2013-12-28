#ifndef TESTS_H
#define TESTS_H

#include <srcTest/sa/parser/alocacaoSala/ParserSimulatedAnnelingAlocacaoSalaArquivoTest.h>

void mainTestes(){
    parseDadosEntradaArquivoTxtOk();
    parseDadosEntradaArquivoTxtNOkDiaInvalido();
    parseDadosEntradaArquivoTxtNOkDiaMAiorDomingo();
}

#endif // TESTS_H
