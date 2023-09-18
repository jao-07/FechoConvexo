#include "../include/FechoConvexo.hpp"
#include "../include/Lista.hpp"
#include <sys/resource.h>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

int main(int argc, char *argv[]){

    //Declaração e inicialização das variáveis
    struct rusage resources;
    double utime, stime, total_time, tempoT=0, auxT=0;
    int rc, i=0, j=0, numero=0, conta_linhas = 0;
    std::string linha, coord;
    std::fstream arquivo;
    arquivo.open(argv[1]);
    Ponto p;

    //Testa se o arquivo de leitura abriu corretamente, se sim, continua para o resto do programa.
    if(arquivo.is_open()){

        //Inicialmente le o arquivo para descobrir quantos pontos existem no arquivo
        while(getline(arquivo, linha))
            conta_linhas++;
        arquivo.close();

        //Após saber quantos são os pontos, cria-se um vetor com a quantidade de pontos e abre novamente o arquivo
        Ponto * vetor = new Ponto[conta_linhas];
        arquivo.open(argv[1]);

        //Lê os pontos de cada linha do arquivo e armazena eles no vetor 
        while(getline(arquivo, linha)){
           coord = "";
            for(i = 0; linha[i] != ' '; i++){
                coord = coord + linha[i];
            }
            numero = std::stoi(coord);
            p.Setx(numero);
            coord = linha.substr(i);
            numero = std::stoi(coord);
            p.Sety(numero);     

            vetor[j] = p;
            j++;
        }
        //Cria-se o FechoConvexo a partir do vetor de pontos
        FechoConvexo F(vetor, conta_linhas);
        //Imprime os pontos que formam o fecho
        std::cout << "FECHO CONVEXO:" << std::endl;
        F.Imprime();

        if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
            perror("getrusage failed");
        utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
        stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
        total_time = utime+stime;
        tempoT = (total_time - auxT);
        auxT = total_time;

        //Faz a chamada da função Graham com os 3 tipos de ordenação e da função Jarvis e em cada chamada, calcula o tempo gasto em cada uma e imprime na tela
        for(int o=0; o<4; o++){
            if(o==0)
                F.Graham(vetor, conta_linhas, 0);
            if(o==1)
                F.Graham(vetor, conta_linhas, 1);
            if(o==2)
                F.Graham(vetor, conta_linhas, 2);
            if(o==3)
                F.Jarvis(vetor, conta_linhas);

            if((rc = getrusage(RUSAGE_SELF, &resources)) != 0)
                perror("getrusage failed");
            utime = (double) resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
            stime = (double) resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
            total_time = utime+stime;

            tempoT = (total_time - auxT);
            auxT = total_time;
            if(o==0)
                std::cout << std::fixed << std::setprecision(6) << std::endl << "GRAHAM+MERGESORT: " << tempoT << "s" << std::endl;
            if(o==1)
                std::cout << "GRAHAM+INSERTIONSORT: " << tempoT << "s" << std::endl;
            if(o==2)
                std::cout << "GRAHAM+LINEAR: " << tempoT << "s" << std::endl;
            if(o==3)
                std::cout << "JARVIS: " << tempoT << "s" << std::endl;
        }

    } else //Se o arquivo não abrir corretamente, imprime uma mensagem de erro na tela.
        std::cout << "ERRO NA ABERTURA DO ARQUIVO!" << std::endl;

    return 0;
}