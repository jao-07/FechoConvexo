#include "../include/Pilha.hpp"

//Construtor da classe Pilha
Pilha::Pilha(){
    topo = NULL;
    tamanho = 0;
}

//Destrutor da classe Pilha
Pilha::~Pilha() {
    Limpa();
}

//Função que retorna se a Pilha está vazia ou não
bool Pilha::Vazia(){
    return tamanho == 0;
}

//Função que empilha um ponto na Pilha
void Pilha::Empilha(Ponto p){
    Celula *nova;
    nova = new Celula();
    nova->ponto = p;
    nova->prox = topo;
    topo = nova;
    tamanho++;
}

//Função que desempilha o ponto do topo e retorna esse nó
Ponto Pilha::Desempilha(){
    Ponto aux; Celula *p;
    if(tamanho != 0){
        aux = topo->ponto;
        p = topo;
        topo = topo->prox;
        delete p;
        tamanho--;
    }
    return aux;
};

//Função que apaga todos os pontos da Pilha
void Pilha::Limpa(){
    while(!Vazia())
    Desempilha();
}

// Função auxiliar que retorna o ponto abaixo do topo
Ponto Pilha::NextToTop(){
    Ponto a = Desempilha();
    Ponto b = Desempilha();
    Empilha(b);
    Empilha(a);
    return b;
}

//Função que retorna o topo da pilha
Celula* Pilha::GetTopo(){
    return topo;
}

//Função que retorna o tamanho da pilha
int Pilha::GetTamanho(){
    return tamanho;
}