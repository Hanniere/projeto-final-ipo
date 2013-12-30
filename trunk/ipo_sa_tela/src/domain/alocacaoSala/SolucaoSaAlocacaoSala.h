#ifndef SOLUCAOSAALOCACAOSALA_H
#define SOLUCAOSAALOCACAOSALA_H

#include <src/domain/ISolucaoSa.h>
#include <src/domain/alocacaoSala/Sala.h>
#include <vector>

class SolucaoSaAlocacaoSala : public ISolucaoSa
{
public:
    SolucaoSaAlocacaoSala();
    std::vector<Sala> listaSala() const;
    void setListaSala(const std::vector<Sala> &listaSala);
    std::string toString();

private:
    std::vector<Sala> m_listaSala;
};

#endif // SOLUCAOSAALOCACAOSALA_H
