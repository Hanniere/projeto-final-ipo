#include "IParserSimulatedAnnelingAlocacaoSala.h"

IParserSimulatedAnnelingAlocacaoSala::IParserSimulatedAnnelingAlocacaoSala()
{
}

std::vector<Sala> IParserSimulatedAnnelingAlocacaoSala::vetorSala() const
{
    return m_vetorSala;
}

void IParserSimulatedAnnelingAlocacaoSala::setVetorSala(const std::vector<Sala> &vetorSala)
{
    m_vetorSala = vetorSala;
}

std::vector<Turma> IParserSimulatedAnnelingAlocacaoSala::vetorTurma() const
{
    return m_vetorTurma;
}

void IParserSimulatedAnnelingAlocacaoSala::setVetorTurma(const std::vector<Turma> &vetorTurma)
{
    m_vetorTurma = vetorTurma;
}
