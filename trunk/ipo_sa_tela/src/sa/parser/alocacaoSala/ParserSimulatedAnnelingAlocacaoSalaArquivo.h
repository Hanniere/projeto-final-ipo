#ifndef PARSERSIMULATEDANNELINGALOCACAOSALA_H
#define PARSERSIMULATEDANNELINGALOCACAOSALA_H

#include <sa/parser/alocacaoSala/IParserSimulatedAnnelingAlocacaoSala.h>

/*
 *Entrada:
 *Qtde salas
 *capacidade Salas
 *
 *Qtde Turmas
 *Demandas Horario diaSemana
 *
 */

class ParserSimulatedAnnelingAlocacaoSalaArquivo : public IParserSimulatedAnnelingAlocacaoSala
{
public:
    ParserSimulatedAnnelingAlocacaoSalaArquivo();
    bool parse( const std::string& entrada );

};

#endif // PARSERSIMULATEDANNELINGALOCACAOSALA_H
