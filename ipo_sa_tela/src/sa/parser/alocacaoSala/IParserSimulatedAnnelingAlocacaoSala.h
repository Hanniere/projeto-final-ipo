#ifndef IPARSERSIMULATEDANNELINGALOCACAOSALA_H
#define IPARSERSIMULATEDANNELINGALOCACAOSALA_H

#include <sa/parser/IParserSimulatedAnneling.h>
#include <domain/alocacaoSala/Sala.h>
#include <domain/alocacaoSala/Turma.h>
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
