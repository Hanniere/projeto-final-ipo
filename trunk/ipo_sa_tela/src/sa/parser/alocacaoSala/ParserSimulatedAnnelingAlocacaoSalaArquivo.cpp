
#include "ParserSimulatedAnnelingAlocacaoSalaArquivo.h"

#include <fstream>

ParserSimulatedAnnelingAlocacaoSalaArquivo::ParserSimulatedAnnelingAlocacaoSalaArquivo()
{
}

ParserSimulatedAnnelingAlocacaoSalaArquivo::~ParserSimulatedAnnelingAlocacaoSalaArquivo()
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

        for( int i =0; i < qtdeSala; ++i ){
            Sala sala;
            int capacidade;
            std::string descricaoSala;
            arquivo >> capacidade >> descricaoSala;
            sala.setCapacidade( capacidade );
            sala.setCodigoSala( i );
            sala.setDescricaoSala( descricaoSala );
            m_vetorSala[i] = sala;
        }

        // turmas
        int qtdeTurma;
        arquivo >> qtdeTurma;

        m_vetorTurma = std::vector<Turma>( qtdeTurma );

        for( int i =0; i < qtdeTurma; ++i ){
            Turma turma;
            int demanda;
            int horario;
            int diaSemana;
            std::string descricaoMateria;
            arquivo >> demanda >> horario >> diaSemana >> descricaoMateria;

            if( diaSemana > DOMINGO || diaSemana == DIA_INVALIDO )
                return false;

            turma.setDiaSemana( (DiaSemana)diaSemana );
            turma.setCodigoTurma( i );
            turma.setDemanda( demanda );
            turma.setHorario( horario );
            turma.setDescricaoMateria( descricaoMateria );

            m_vetorTurma[i] = turma;
        }
        return true;
    }
    else
        return false;
}

void ParserSimulatedAnnelingAlocacaoSalaArquivo::clear()
{
    m_vetorSala.clear();
    m_vetorTurma.clear();
}
