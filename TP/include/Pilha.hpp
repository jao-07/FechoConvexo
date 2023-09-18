#pragma once

#include "Celula.hpp"

//Estrutura utilizada para auxiliar na criação do Fecho Convexo
class Pilha {
    public:
        Pilha();
        virtual ~Pilha();
        void Empilha(Ponto p);
        Ponto Desempilha();
        void Limpa();
        bool Vazia();
        Ponto NextToTop();
        Celula* GetTopo();
        int GetTamanho();
    protected:
        Celula* topo;
        int tamanho;
};