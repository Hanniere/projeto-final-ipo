#ifndef ESTADOGERACAOVIZINHO_H
#define ESTADOGERACAOVIZINHO_H

enum EstadoGeracaoVizinho{
    ESTADO_GERACAO_VIZINHO_INICIAL = 0,
    FAZER_TROCA = 1,
    FAZER_REALOCACAO = 2,
    FALHA_TROCA = 3,
    FALHA_REALOCAO = 4,
    ESTADO_GERACAO_VIZINHO_FINAL
};

#endif // ESTADOGERACAOVIZINHO_H