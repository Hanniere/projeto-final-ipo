#include "ParserSimulatedAnnelingAlocacaoSalaArquivo.h"

#include <fstream>

ParserSimulatedAnnelingAlocacaoSalaArquivo::ParserSimulatedAnnelingAlocacaoSalaArquivo()
{
}


bool ParserSimulatedAnnelingAlocacaoSalaArquivo::parse(const std::string &entrada)
{
    std::ifstream arquivo(entrada.c_str(), std::ios_base::in);

    if( arquivo.is_open() ){

        // Salas
        int qtdeSala;
        arquivo >> qtdeSala;

        m_vetorSala = std::vector<Sala>( qtdeSala );

        for( int i =0; i < qtdeSala; i++ ){
            Sala sala;
            int capacidade;
            arquivo >> capacidade;
            sala.setCapacidade( capacidade );
            sala.setCodigoSala( i );
            m_vetorSala[i] = sala;
        }

        // turmas
        int qtdeTurma;
        arquivo >> qtdeTurma;

        m_vetorTurma = std::vector<Turma>( qtdeTurma );

        for( int i =0; i < qtdeTurma; i++ ){
            Turma turma;
            int demanda;
            int horario;
            int diaSemana;
            arquivo >> demanda >> horario >> diaSemana;

            if( diaSemana > DOMINGO || diaSemana == DIA_INVALIDO )
                return false;

            turma.setDiaSemanda( (DiaSemana)diaSemana );
            turma.setCodigoTruma( i );
            turma.setDemanda( demanda );
            turma.setHorario( horario );

            m_vetorTurma[i] = turma;
        }
        return true;
    }
    else
        return false;
}
