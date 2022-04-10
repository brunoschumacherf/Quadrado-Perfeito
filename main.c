#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int N, **matriz, i, j, *vetor, contvetor = 1, soma = 0, result = 0, generated_number, total_matrix = 0, first_sum = 0, coluna, linha;
  matriz = malloc(N * sizeof(int *));
  vetor = malloc((N * 2 + 1) * sizeof(int));

  printf("Digite o tamanho da matriz: ");
  scanf("%i", &N);
  if (matriz == NULL){
    printf("Erro: Memoria insuficiente!!!\n");
    return 0;
  }
  for (i = 0; i < N; i++){
    matriz[i] = malloc(N * sizeof(int));
    if (matriz[i] == NULL){
    printf("Erro: Memoria insuficiente!!!\n");
    return 0;
    }
  }
  for (i = 0; i < N; i++){
    for (j = 0; j < N; j++){
      matriz[i][j] = 0;
    }
  }
  srand(time(NULL));
  for( i = 0; i < N; i++){
    do{
      generated_number = rand() % 10;
    }while(generated_number == 0);
    first_sum += generated_number;
    matriz[i][i] = generated_number;
    total_matrix++;
  }
  while (total_matrix != N * N){
    for(i = 0; i < N; i++){
      for (j = 0; j < N; j++){
        printf("%i ", matriz[i][j]);
      }
    printf("\n");
    }
    printf("A soma das linha deve ser %i\n", first_sum);

    printf("Digite a linha para adicionar o elemento: ");
    scanf("%i", &i);
    printf("Digite a coluna para adicionar o elemento: ");
    scanf("%i", &j);
    if (i >= N || j >= N){
    printf("Coluna o Linha não existe\n");
    }
    if (matriz[i][j] != 0){
      system("clear");
      printf("Local já preenchido. Tente Novamente\n");
    }else{
      printf("Digite o elemento: ");
      scanf("%i", &matriz[i][j]);
      total_matrix++;
      system("clear");
      printf("Elemento Adicionado\n");
    }
  }
  // For de teste para matriz grande
  // for (i = 0; i < N; i++){
  //   for ( j = 0; j < N; j++){
  //     matriz[i][j] = 2;
  //   }
  // }
  for (i = 0; i < N; i++){
    soma += matriz[i][i];
  }
  vetor[0] = soma;
  soma = 0;
  for( i = 0; i < N; i++, contvetor++){
    for (j = 0; j < N; j++){
      soma += matriz[i][j];
    }
    vetor[contvetor] = soma;
    soma = 0;
  }
  for (i = 0; i < N; i++, contvetor++){
    for (j = 0; j < N; j++){
      soma += matriz[j][j];
    }
    vetor[contvetor] = soma;
    soma = 0;
  }
  for (i = 0; i < N * 2; i++){
    if (vetor[i] == vetor[i + 1]){
      printf("%i", result);
      result++;
    }
  }
  if (result == N + N){
    printf("Quadrado Perfeito");
  }else{
    printf("Quadrado não Perfeito");
  }
  for(i = 0; i < N; i++){
    free(matriz[i]);
  }
  free(matriz);
  return 0;
}