#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 1000

int Menu();
void Encerrar();
void BoasVindas();
void LimparTela();

void GerarDados(int v[]);
void ExibirDados(int v[]);

void BubbleSort(int v[]);
void SelectionSort(int v[]);
void InsertionSort(int v[]);

int BuscaSequencial(int v[], int item);
int BuscaBinaria(int v[], int item);
void RelatorioBusca(int v[], int busca);

int main() {
  setlocale(LC_ALL, "");

  int vet1[VECTOR_SIZE], vet2[VECTOR_SIZE], vet3[VECTOR_SIZE];
  int op, item;

  BoasVindas();

  do {
    op = Menu();

    switch (op) {
    case 0:
      break;

    case 1:
      GerarDados(vet1);
      break;

    case 2:
      GerarDados(vet2);
      break;

    case 3:
      GerarDados(vet3);
      break;

    case 4:
      ExibirDados(vet1);
      break;

    case 5:
      ExibirDados(vet2);
      break;

    case 6:
      ExibirDados(vet3);
      break;

    case 7:
      BubbleSort(vet1);
      break;

    case 8:
      SelectionSort(vet2);
      break;

    case 9:
      InsertionSort(vet3);
      break;

    case 10:
      RelatorioBusca(vet1, 0);
      break;

    case 11:
      RelatorioBusca(vet3, 1);
      break;

    default:
      printf("\n[ERRO] - Opção inválida!\n");
      break;
    }
  } while (op != 0);

  return 0;
}

int Menu() {
  int op;

  printf("+=================================================+\n");
  printf("|                                                 |\n");
  printf("| Menu:                                           |\n");
  printf("| [1] Popular vetor 1                             |\n");
  printf("| [2] Popular vetor 2                             |\n");
  printf("| [3] Popular vetor 3                             |\n");
  printf("| [4] Exibir vetor 1                              |\n");
  printf("| [5] Exibir vetor 2                              |\n");
  printf("| [6] Exibir vetor 3                              |\n");
  printf("| [7] Ordenar vetor 1 por trocas                  |\n");
  printf("| [8] Ordenar vetor 2 por seleção                 |\n");
  printf("| [9] Ordenar vetor 3 por insersão                |\n");
  printf("| [10] Busca Sequencial no vetor 1                |\n");
  printf("| [11] Busca Binária no vetor 3                   |\n");
  printf("|                                                 |\n");
  printf("| [0] Sair                                        |\n");
  printf("|                                                 |\n");
  printf("+=================================================+\n");

  scanf("%d", &op);

  return op;
}

void GerarDados(int v[]) {
  printf("\nGerando %d dados aleatórios\n", VECTOR_SIZE);
  int i;
  srand(time(NULL));

  for (i = 0; i < VECTOR_SIZE; i++) {
    v[i] = rand() % 9999;
  }
  printf("\npronto!\n");
}

void ExibirDados(int v[]) {
  int i, j, c = 0;
  printf("\nExibindo dados: \n");

  for (j = 0; j < VECTOR_SIZE; j++) {
    printf(" [%4d]", v[c]);
    c++;

    if ((j + 1) % 10 == 0)
      printf("\n");
  }
  printf("\nTotal number of data: %d \n", c);
}

void BoasVindas() {
  printf("Bem vindo ao menu da atividade 3\n");
  printf("Por favor escolha a opção desejada para começar\n");
}

void BubbleSort(int v[]) {
  int pass, i, temp, swapped = 1;
  for (pass = VECTOR_SIZE - 1; pass >= 0 && swapped; pass--) {
    swapped = 0;
    for (i = 0; i <= pass - 1; i++) {
      if (v[i] > v[i + 1]) {
        // swap
        temp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = temp;
        swapped = 1;
      }
    }
  }

  printf("\n Sorting by bubble method [done!]\n");
}

void SelectionSort(int v[]) {   
  int i, j, min, temp;
  for (i = 0; i < VECTOR_SIZE - 1; i++) {
    min = i;
    for (j = i + 1; j < VECTOR_SIZE; j++) {
      if (v[j] < v[min]) {
        min = j;
      }
    }
    // swap
    temp = v[min];
    v[min] = v[i];
    v[i] = temp;
  }
  printf("\n Sorting by selection method [done!]\n");
}

void InsertionSort(int v[]) {
  int i, j, x;
  for (i = 1; i <= VECTOR_SIZE - 1; i++) {
    x = v[i];
    j = i;
    while (v[j - 1] > x && j >= 1) {
      v[j] = v[j - 1];
      j--;
    }
    v[j] = x;
  }
  printf("\n Sorting by insertion method [done!]\n");
}

int BuscaSequencial(int v[], int item) {
  int i;
  for (i=0; i<VECTOR_SIZE; i++ )
  {
    if(item == v[i])
    {
      return i+1;
    }
  }
  return 0;

}

int BuscaBinaria(int v[], int item) {
  int i, f, m;
  i = 0;
  f = VECTOR_SIZE-1;

  while (i <= f) 
  {
    m = (i+f)/2;
    if (item == v[m]) return i+1;
    if (item < v[m]) f = m-1;
    else i = m+1;
  }
  return 0;

}

// busca sequexncial = 0, busca binária recursiva = 1
void RelatorioBusca(int v[], int busca){
  int item;
  printf("\nBuscar por: ");
  scanf("%d", &item);

  
  int encontrado = busca ? BuscaSequencial(v, item) : BuscaBinaria(v, item);

  if (encontrado) {
    printf("\n >> %d encontrado, %dº elemento do vetor \n", item, encontrado);
  } else {
    printf("\n >> %d não foi encontrado!\n", item);
  }
} 