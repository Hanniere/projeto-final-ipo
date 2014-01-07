#ifndef DIASEMANA_H
#define DIASEMANA_H

#include <string>

enum DiaSemana{
    DIA_INVALIDO = 0,
    SEGUNDA_FEIRA = 1,
    TERCA_FEIRA = 2,
    QUARTA_FERIA = 3,
    QUINTA_FEIRA = 4,
    SEXTA_FEIRA = 5,
    SABADO = 6,
    DOMINGO = 7
};

class DiaSemanaDescriptor
{
public:
    static std::string getDescricao( const DiaSemana& dia ){
        switch (dia) {
        case DIA_INVALIDO:
            return "Dia Invalido";
            break;

        case SEGUNDA_FEIRA:
            return "Segunda Feira";
            break;

        case TERCA_FEIRA:
            return "Terca Feira";
            break;

        case QUARTA_FERIA:
            return "Quarta Feira";
            break;

        case QUINTA_FEIRA:
            return "Quinta Feira";
            break;

        case SEXTA_FEIRA:
            return "Sexta Feira";
            break;

        case SABADO:
            return "Sabado";
            break;

        case DOMINGO:
            return "Domingo";
            break;
        }
    }
};



#endif // DIASEMANA_H
