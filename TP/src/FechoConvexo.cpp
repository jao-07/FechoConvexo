#include "../include/FechoConvexo.hpp"

//Construtor do TAD FechoConvexo que chama a função Graham e armazena os pontos do fecho convexo no vetor fecho
FechoConvexo::FechoConvexo(Ponto pontos[], int n){
    Pilha aux = Graham(pontos, n, 0);
    tamanho = aux.GetTamanho();
    fecho = new Ponto[tamanho];
    int i=0;
    while(!aux.Vazia()){
        fecho[i] = aux.Desempilha();
        i++;
    }
}

//Função que imprime os pontos que formam o fecho convexo
void FechoConvexo::Imprime(){
    for(int i=0; i<tamanho; i++){
        fecho[i].Imprime();
    }
}

//Função que retorna uma pilha contendo os pontos que formam o fecho convexo de um vetor de pontos utilizando o Scan de Graham
Pilha FechoConvexo::Graham(Ponto pontos[], int n, int tipo) {
    Pilha S;
	// Encontra o ponto mais abaixo
	int ymin = pontos[0].Gety(), min = 0;
	for (int i = 1; i < n; i++) {
		int y = pontos[i].Gety();

		// Se houver mais de um ponto com a menor altura, seleciona o mais a esquerda
		if ((y < ymin) || (ymin == y && pontos[i].Getx() < pontos[min].Getx()))
			ymin = pontos[i].Gety(), min = i;
	}

	// Posiciona o ponto mais abaixo na primeira posição
	swap(pontos[0], pontos[min]);

	// Ordena n-1 pontos com relação ao primeiro ponto.
	// O ponto p1 vem antes do ponto p2 na ordenação se p2 tiver ângulo polar maior (no sentido anti-horário) do que p1
	// Utiliza o determinado tipo de ordenação de acordo com a variável Tipo:
	//Tipo = 0 -> Mergesort
	//Tipo = 1 -> Inserção
	//Tipo = 2 -> Bucket Sort
	if(tipo == 0)
		Mergesort(pontos, n, pontos[0]);
	else if(tipo == 1)
		Insercao(pontos, n, pontos[0]);
	else if(tipo == 2)
		Bucket(pontos, n, pontos[0]);
	else{
		std::cout << "Tipo de ordenação inválido!" << std::endl;
		return S;
	}

	// Se dois ou mais pontos tiverem o mesmo angulo que o ponto mais abaixo, remove todos menos o que tiver a maior distância
	int m = 1;
	for (int i=1; i<n; i++) {
		while (i < n-1 && orientation(pontos[0], pontos[i], pontos[i+1]) == 0)
			i++;

		pontos[m] = pontos[i];
		m++;
	}

	// Se o conjunto de pontos não tiver pelo menos 3 pontos com ângulos diferentes, não é possível fazer o fecho convexo
	if (m < 3){
		std::cout << "ERRO: IMPOSSÍVEL FAZER O FECHO COM MENOS DE 3 PONTOS!" << std::endl;
		return S;
	} 

	// Cria uma pilha vazia e insere os três primeiro elementos
	
	S.Empilha(pontos[0]);
	S.Empilha(pontos[1]);
	S.Empilha(pontos[2]);

	//Continua o processo com o resto dos n-3 pontos 
	for (int i = 3; i < m; i++)
	{
		// Remove os elementos do topo da pilha quando o elemento i, o elemento do topo e o abaixo do topo não fazem uma curva para a esquerda
		while (S.GetTamanho()>1 && orientation(S.NextToTop(), S.GetTopo()->GetPonto(), pontos[i]) != 2)
			S.Desempilha();  
		S.Empilha(pontos[i]);
	}

	// Agora a pilha possui os elementos do fecho, então imprime eles
	return S;
}

//Função que retorna uma pilha contendo os pontos que formam o fecho convexo de um vetor de pontos utilizando a Marchar de Jarvis
Ponto * FechoConvexo::Jarvis(Ponto pontos[], int n){
	// Inicializa o vetor resultante
		Ponto * hull = new Ponto[n];
	
	// Tem que haver pelo menos 3 pontos para fazer o fecho
	if (n < 3){
		std::cout << "ERRO: IMPOSSÍVEL FAZER O FECHO COM MENOS DE 3 PONTOS!" << std::endl;
		return hull;
	}
		

	// Encontra o ponto mais a esquerda
	int l = 0;
	for (int i = 1; i < n; i++)
		if (pontos[i].Getx() < pontos[l].Getx())
			l = i;

	// Começa do ponto mais a esquerda, mantem andando no sentido anti-horário até chegar no ponto de início.
	int p = l, q;
    int j = 0;
	do
	{
		// Adiciona o ponto no vetor
		hull[j] = pontos[p];

		// Procura por um ponto 'q' na qual a orientação (p, q, x) é anti-horária para todos os pontos 'x'. 
		//Se qualquer ponto 'i' estiver mais no sentido anti-horário do que 'q', então q é atualizado.
		q = (p+1)%n;
		for (int i = 0; i < n; i++) {
			if (orientation(pontos[p], pontos[i], pontos[q]) == 2)
				q = i;
		}

		// Agora q é o ponto mais no sentido anti-horário em relação a p
		// Define p como q para a próxima iteração, então q é adicionado ao vetor resultante
		p = q;
        j++;

	} while (p != l); // Repete-se o processo enquanto não chegar ao ponto inicial
    j--;

	if(j<3){
		std::cout << "ERRO: IMPOSSÍVEL FAZER O FECHO COM MENOS DE 3 PONTOS!" << std::endl;
		Ponto * v = new Ponto[n];
		return v;
	}
	return hull;
}