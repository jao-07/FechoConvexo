#pragma once

#include "Celula.hpp"

//Estrutura que auxilia no método de ordenação Bucket Sort
class Lista {

    public:
        Lista(Ponto r);
        Lista();
        ~Lista();
        void Insere(Ponto e);
        void Limpa();
        void PreencheVetor(Ponto *v, int i, int len);
        int GetTamanho();
        Celula* GetUltimo();

    private:
        Celula* primeiro;
        Celula* ultimo;
        int tamanho;
        Ponto ref;
};