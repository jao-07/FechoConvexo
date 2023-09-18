#pragma once

#include "Ponto.hpp"
#include "Lista.hpp"

//Arquivo contendo as funções auxiliares utilizadas pelos métodos de ordenação e de obtenção do fecho convexo

int orientation(Ponto p, Ponto q, Ponto r);

void swap(Ponto &p1, Ponto &p2);

void Mergesort(Ponto *v, int n, Ponto p);

void sort(Ponto *v, Ponto *b, int i, int f, Ponto p);

void merge(Ponto *v, Ponto *b, int i, int m, int f, Ponto p);

void Insercao(Ponto *v, int n, Ponto p);

void Bucket(Ponto *v, int len, Ponto p);