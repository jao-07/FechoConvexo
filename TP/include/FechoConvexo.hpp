#pragma once

#include <iostream>
#include <stdlib.h>
#include "MetOrd.hpp"
#include "Pilha.hpp"
#include "Ponto.hpp"
#include "Lista.hpp"

//Classe que representa o Fecho Convexo
class FechoConvexo{

    public:
        FechoConvexo(Ponto pontos[], int n);
        void Imprime();
        Pilha Graham(Ponto pontos[], int n, int tipo);
        Ponto * Jarvis(Ponto pontos[], int n);
    private: 
        Ponto * fecho;
        int tamanho;
};