#ifndef PARSERSIMULATEDANNELINGALOCACAOSALAARQUIVOTEST_H
#define PARSERSIMULATEDANNELINGALOCACAOSALAARQUIVOTEST_H

#include <fstream>
#include <cassert>
#include <src/sa/parser/alocacaoSala/ParserSimulatedAnnelingAlocacaoSalaArquivo.h>

void parseDadosEntradaArquivoTxtOk(){
    std::ofstream arquivoSaida("temp.txt", std::ios_base::out );

    if( arquivoSaida.is_open() ){
         // quantide de salas
        arquivoSaida << 2 << std::endl;
        // capacidade 1
        arquivoSaida << 50 << std::endl;
        //capacidade 2
        arquivoSaida << 90 << std::endl;

        // quantide turma
        arquivoSaida << 3 << std::endl;

        // turma 1
        arquivoSaida << 50 << " " << 1 << " " << 1 << std::endl;
        // turma 2
        arquivoSaida << 60 << " " << 1 << " " << 1 << std::endl;
        // turma 3
        arquivoSaida << 30 << " " << 2 << " " << 1 << std::endl;

        arquivoSaida.close();

        ParserSimulatedAnnelingAlocacaoSalaArquivo parser;
        if( parser.parse( "temp.txt" ) ){
            std::vector<Sala> vetorSala = parser.vetorSala();

            assert( vetorSala.size() == 2 );
            Sala tempSala = vetorSala.at(0);
            assert( tempSala.capacidade() == 50 );
            assert( tempSala.codigoSala() == 0 );

            tempSala = vetorSala.at(1);
            assert( tempSala.capacidade() == 90 );
            assert( tempSala.codigoSala() == 1 );

            std::vector<Turma> vetorTurma = parser.vetorTurma();

            assert( vetorTurma.size() == 3 );
            Turma tempTurma = vetorTurma.at(0);
            assert( tempTurma.demanda() == 50 );
            assert( tempTurma.codigoTruma() == 0 );
            assert( tempTurma.diaSemana() == SEGUNDA_FEIRA );
            assert( tempTurma.horario() == 1 );

            tempTurma = vetorTurma.at(1);
            assert( tempTurma.demanda() == 60 );
            assert( tempTurma.codigoTruma() == 1 );
            assert( tempTurma.diaSemana() == SEGUNDA_FEIRA );
            assert( tempTurma.horario() == 1 );

            tempTurma = vetorTurma.at(2);
            assert( tempTurma.demanda() == 30 );
            assert( tempTurma.codigoTruma() == 2 );
            assert( tempTurma.diaSemana() == SEGUNDA_FEIRA );
            assert( tempTurma.horario() == 2 );
        }
        else
            assert( 0 );
    }
    else
        assert(0);
}


void parseDadosEntradaArquivoTxtNOkDiaInvalido(){
    std::ofstream arquivoSaida("temp.txt", std::ios_base::out );

    if( arquivoSaida.is_open() ){
         // quantide de salas
        arquivoSaida << 2 << std::endl;
        // capacidade 1
        arquivoSaida << 50 << std::endl;
        //capacidade 2
        arquivoSaida << 90 << std::endl;

        // quantide turma
        arquivoSaida << 1 << std::endl;

        // turma 1
        arquivoSaida << 50 << " " << 1 << " " << 0 << std::endl;

        arquivoSaida.close();

        ParserSimulatedAnnelingAlocacaoSalaArquivo parser;
        assert( parser.parse( "temp.txt" ) == false );
    }
    else
        assert(0);
}

void parseDadosEntradaArquivoTxtNOkDiaMAiorDomingo(){
    std::ofstream arquivoSaida("temp.txt", std::ios_base::out );

    if( arquivoSaida.is_open() ){
         // quantide de salas
        arquivoSaida << 2 << std::endl;
        // capacidade 1
        arquivoSaida << 50 << std::endl;
        //capacidade 2
        arquivoSaida << 90 << std::endl;

        // quantide turma
        arquivoSaida << 1 << std::endl;

        // turma 1
        arquivoSaida << 50 << " " << 1 << " " << 8 << std::endl;

        arquivoSaida.close();

        ParserSimulatedAnnelingAlocacaoSalaArquivo parser;
        assert( parser.parse( "temp.txt" ) == false );
    }
    else
        assert(0);
}

#endif // PARSERSIMULATEDANNELINGALOCACAOSALAARQUIVOTEST_H