#pragma once

#include <cstddef>
#include "Ponto.hpp"

//Classe auxiliar à classe Pilha
class Celula {
    public:
        Celula(){
            ponto = Ponto(0,0);
            prox = NULL;
        };
        Ponto GetPonto(){
            return ponto;
        }
    private:
        Ponto ponto;
        Celula *prox;
        friend class Pilha;
        friend class Lista;
};