#include "../include/Ponto.hpp"

//Contrutor do TAD Ponto que recebe como parâmetro as coordenadas x e y do ponto.
Ponto::Ponto(int n, int m){
    x = n;
    y = m;
}

//Construtor padrão do TAD Ponto que define valores arbitrários para x e y.
Ponto::Ponto(){
    x=1000;
    y=-1000;
}

//Função que retorna a coordenada x do ponto.
int Ponto::Getx(){
    return x;
}

//Função que retorna a coordenada y do ponto.
int Ponto::Gety(){
    return y;
}

//Função que define n como a coordenada x do ponto.
void Ponto::Setx(int n){
    x = n;
}

//Função que define n como a coordenada y do ponto.
void Ponto::Sety(int n){
    y = n;
}

//Função auxiliar que imprime as coordenadas do ponto.
void Ponto::Imprime(){
    std::cout << "(" << x << "," << y << ")" << std::endl;
    
}

//Função que retorna a distância entre o próprio ponto e o ponto p.
float Ponto::Distancia(Ponto p){
    int a = pow(p.Getx() - x, 2);
    int b = pow(p.Gety() - y, 2);
    return sqrt(a + b);
}

//Função que retorna o Produto Escalar do próprio vetor e do vetor p (Vetor que é representado pela classe Ponto, já que os vetores também são representados por coordenadas, assim como os pontos).
int Ponto::ProdutoEscalar(Ponto p){
    return this->Getx() * p.Getx() + this->Gety() * p.Gety();
}

//Função que retorna o ângulo formado pelo próprio ponto e a linha da coordenada x do ponto b
double Ponto::Angulo(Ponto b){
    double ang = 0;
    Ponto a(this->Getx(), this->Gety());
    Ponto c(b.Getx() + 1, b.Gety());
    Ponto ba(a.Getx() - b.Getx(), a.Gety() - b.Gety());
    Ponto bc(c.Getx() - b.Getx(), c.Gety() - b.Gety());
    if(b.Distancia(a) > 0)
        ang = acos(ba.ProdutoEscalar(bc) / b.Distancia(a));
    return ang * 180 / 3.141592;
}