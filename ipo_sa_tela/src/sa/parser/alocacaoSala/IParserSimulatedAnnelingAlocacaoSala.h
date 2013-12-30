#ifndef IPARSERSIMULATEDANNELINGALOCACAOSALA_H
#define IPARSERSIMULATEDANNELINGALOCACAOSALA_H

#include <src/sa/parser/IParserSimulatedAnneling.h>
#include <src/domain/alocacaoSala/Sala.h>
#include <src/domain/alocacaoSala/Turma.h>
#include <vector>

class IParserSimulatedAnnelingAlocacaoSala : public IParserSimulatedAnneling
{
public:
    IParserSimulatedAnnelingAlocacaoSala();

    std::vector<Sala> vetorSala() const;
    void setVetorSala(const std::vector<Sala> &vetorSala);

    std::vector<Turma> vetorTurma() const;
    void setVetorTurma(const std::vector<Turma> &vetorTurma);

protected:
    std::vector<Sala> m_vetorSala;
    std::vector<Turma> m_vetorTurma;
};

#endif // IPARSERSIMULATEDANNELINGALOCACAOSALA_H
