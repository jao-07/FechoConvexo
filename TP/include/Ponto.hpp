#pragma once

#include <iostream>
#include <cmath>

//Classe que representa o ponto com coordenadas x e y
class Ponto {
    private:
        int x;
        int y;

    public:
        Ponto(int x, int y);
        Ponto();
        int Getx();
        int Gety();
        void Imprime();
        float Distancia(Ponto p);
        int ProdutoEscalar(Ponto p);
        double Angulo(Ponto b);
        void Setx(int n);
        void Sety(int n);
};