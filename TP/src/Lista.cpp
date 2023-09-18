#include "../include/Lista.hpp"

//Construtor do TAD Lista que tem como parâmetro o Ponto que serve de referência para a ordenação da lista
Lista::Lista(Ponto r) {
    primeiro = new Celula();
    ultimo = primeiro;
    tamanho = 0;
    ref = r;
}

//Construtor do TAD Lista que não tem parâmetro e inicializa a lista com um ponto de referência (0,0), definido aleatóriamente
Lista::Lista() {
    primeiro = new Celula();
    ultimo = primeiro;
    tamanho = 0;
    Ponto p(0,0);
    ref = p;
}

//Destrutor do TAD Lista
Lista::~Lista() {
    Limpa();
    delete primeiro;
}

//Função auxiliar que insere um ponto na lista posicionando esse ponto de forma que os pontos tiverem um ângulo menor em relação ao ponto de referência fica antes dos pontos que tiverem ângulos maiores. Se os ângulos forem iguais, o que tiver a menor distância em relação ao ponto de referência fica antes.
void Lista::Insere(Ponto pnt){
    Celula *nova;
    Celula *p;
    nova = new Celula();
    nova->ponto = pnt;

    if(tamanho == 0){
        
        primeiro->prox = nova;
        ultimo = nova;
        tamanho++;
    }
    else{
        p = primeiro;
        while(p->prox != NULL){
            if((p->prox->ponto.Angulo(ref) < pnt.Angulo(ref)) || ((p->prox->ponto.Angulo(ref) == pnt.Angulo(ref)) && (pnt.Distancia(ref) > p->prox->ponto.Distancia(ref))))
                p = p->prox;
            else {
                break;
            } 
        }
        if(p == ultimo)
            ultimo = nova;

        nova->prox = p->prox;
        p->prox = nova;
        tamanho++;
    }
}

//Função que deleta todos os elementos da lista e auxilia o destrutor
void Lista::Limpa(){
    Celula *p;

    p = primeiro->prox;
    while (p!=NULL) {
        primeiro->prox = p->prox;
        delete p;
        p = primeiro->prox;
    }
    ultimo = primeiro;
    tamanho = 0;
}

//Função auxiliar que preenche o vetor v a partir da posição i com os pontos que estão armazenados na lista
void Lista::PreencheVetor(Ponto *v, int i, int len){
    Celula *p;
    p = primeiro->prox;
    if(tamanho > 0){
        while (p!=NULL && i != len) {
            v[i] = p->ponto;
            i++;
            p = p->prox;
        }
    }
}

//Função que retorna o tamanho da lista
int Lista::GetTamanho(){
    return tamanho;
}

//Função que retorna o ultimo elemento da lista
Celula* Lista::GetUltimo(){
    return ultimo;
}