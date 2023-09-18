#include "../include/MetOrd.hpp"

// Função que retorna a orientação de três pontos (p, q, r).
// A função tem os seguintes retornos:
// 0 --> p, q e r são colineares
// 1 --> Sentido Horário
// 2 --> Sentido Anti-Horário
int orientation(Ponto p, Ponto q, Ponto r){

	int val = (q.Gety() - p.Gety()) * (r.Getx() - q.Getx()) -
			(q.Getx() - p.Getx()) * (r.Gety() - q.Gety());

	if (val == 0) return 0; // colinear
	return (val > 0)? 1: 2; // Sentido Horário ou Anti-Horário
}

//Função auxiliar que troca dois pontos
void swap(Ponto &p1, Ponto &p2)
{
	Ponto temp = p1;
	p1 = p2;
	p2 = temp;
}

// Dado um vetor de pontos v e um inteiro n >= 0, ordena o vetor v[0..n-1] de acordo com a orientação dos pontos.
void Mergesort(Ponto *v, int n, Ponto p) {

  Ponto * b = new Ponto[n];
  sort(v, b, 1, n - 1, p);
  delete b;
}

/*
  Dado um vetor v e três inteiros i, m e f, sendo v[i..m] e v[m+1..f] vetores ordenados,
  coloca os elementos destes vetores, ordenadamente, no vetor em v[i..f].
*/
void merge(Ponto *v, Ponto *b, int i, int m, int f, Ponto p) {
  int z,
      iv = i, ib = m + 1;

  for (z = i; z <= f; z++){
    b[z] = v[z];
  } 

  z = i;

  while (iv <= m && ib <= f) {
    if (orientation(p, b[iv], b[ib]) > 1 || (orientation(p, b[iv], b[ib]) == 0 && p.Distancia(b[iv]) < p.Distancia(b[ib]))){
      v[z++] = b[iv++];
    }
    else {
      v[z++] = b[ib++];
    }
  }

  while (iv <= m){
    v[z++] = b[iv++];
  }

  while (ib <= f){
    v[z++] = b[ib++];
  }
}

/*
  Dado um vetor de pontos v e dois inteiros i e f, ordena o vetor v[i..f] de acordo com a orientação dos pontos.
  O vetor b é utilizado internamente durante a ordenação.
*/
void sort(Ponto *v, Ponto *b, int i, int f, Ponto p) {

  if (i >= f) return;

  int m = (i + f) / 2;

  sort(v, b, i, m, p);
  sort(v, b, m + 1, f, p);

  if (orientation(p, v[m], v[m+1]) > 1) {
    return;
  }
  merge(v, b, i, m, f, p);
}

//Função que ordena um vetor pelo método de Inserção, ordenando de acordo, inicialmente, com a orientação dos pontos, e se os pontos forem colineares, ordena em relação à distância entre os pontos.
void Insercao(Ponto *v, int n, Ponto p) {
  int i,j;
  Ponto aux;
  for (i = 1; i < n; i++) {
    aux = v[i];
    j = i - 1;
    while (( j >= 1 ) && ((orientation(p, aux, v[j]) > 1) || (orientation(p, aux, v[j]) == 0 && p.Distancia(aux) < p.Distancia(v[j]))) ) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = aux;
  }
}

//Função que ordena um vetor de pontos pelo método Bucket Sort, na qual os pontos são divididos em listas encadeadas, de acordo com o ângulo que possuem em relação ao ponto p. Os pontos do vetor são inseridos ordenadamente nas listas e após serem divididos, voltam ao vetor original.
void Bucket(Ponto *v, int len, Ponto p){
  Lista entre0e30(p);
  Lista entre30e60(p);
  Lista entre60e90(p);
  Lista entre90e120(p);
  Lista entre120e150(p);
  Lista entre150e180(p);

  for(int i=0; i<len; i++){
    if(v[i].Angulo(p) <= 30)
      entre0e30.Insere(v[i]);
    else if(v[i].Angulo(p) > 30 || v[i].Angulo(p) <= 60)
      entre30e60.Insere(v[i]);
    else if(v[i].Angulo(p) > 60 || v[i].Angulo(p) <= 90)
      entre60e90.Insere(v[i]);
    else if(v[i].Angulo(p) > 90 || v[i].Angulo(p) <= 120)
      entre90e120.Insere(v[i]);
    else if(v[i].Angulo(p) > 120 || v[i].Angulo(p) <= 150)
      entre30e60.Insere(v[i]); 
    else
      entre150e180.Insere(v[i]);
  }

  int t = 0;
  entre0e30.PreencheVetor(v, t, len);
  t += entre0e30.GetTamanho();
  entre30e60.PreencheVetor(v, t, len);
  t += entre30e60.GetTamanho();
  entre60e90.PreencheVetor(v, t, len);
  t += entre60e90.GetTamanho();
  entre90e120.PreencheVetor(v, t, len);
  t += entre90e120.GetTamanho();
  entre120e150.PreencheVetor(v, t, len);
  t += entre120e150.GetTamanho();
  entre0e30.PreencheVetor(v, t, len);
}