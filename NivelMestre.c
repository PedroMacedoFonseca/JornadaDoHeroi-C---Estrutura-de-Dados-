#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_COMP 20

// Estrutura do componente da torre
typedef struct {
    char nome[30];      // nome do componente
    char tipo[20];      // tipo (controle, suporte, etc.)
    int prioridade;     // prioridade (1 a 10)
} Componente;

// Função para mostrar os componentes na tela
void mostrarComponentes(Componente v[], int n) {
    printf("\n--- Componentes ---\n");
    for (int i = 0; i < n; i++) {
        printf("%s | %s | prioridade: %d\n",
               v[i].nome, v[i].tipo, v[i].prioridade);
    }
}

// Bubble Sort por nome (ordena strings)
int bubbleSortNome(Componente v[], int n) {
    int comp = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comp++;
            if (strcmp(v[j].nome, v[j+1].nome) > 0) {
                Componente tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
    return comp;
}

// Insertion Sort por tipo (ordena strings)
int insertionSortTipo(Componente v[], int n) {
    int comp = 0;
    for (int i = 1; i < n; i++) {
        Componente chave = v[i];
        int j = i - 1;
        while (j >= 0 && strcmp(v[j].tipo, chave.tipo) > 0) {
            comp++;
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = chave;
    }
    return comp;
}

// Selection Sort por prioridade (ordena inteiros)
int selectionSortPrioridade(Componente v[], int n) {
    int comp = 0;
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            comp++;
            if (v[j].prioridade < v[min].prioridade) {
                min = j;
            }
        }
        if (min != i) {
            Componente tmp = v[i];
            v[i] = v[min];
            v[min] = tmp;
        }
    }
    return comp;
}

// Busca binária por nome (só funciona se vetor já estiver ordenado por nome)
int buscaBinariaPorNome(Componente v[], int n, char alvo[]) {
    int ini = 0, fim = n - 1, comp = 0;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        comp++;
        int cmp = strcmp(alvo, v[meio].nome);
        if (cmp == 0) {
            printf("Componente encontrado: %s | %s | prioridade %d\n",
                   v[meio].nome, v[meio].tipo, v[meio].prioridade);
            printf("Comparacoes na busca binaria: %d\n", comp);
            return 1;
        } else if (cmp < 0) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    printf("Nao encontrado. Comparacoes: %d\n", comp);
    return 0;
}

int main() {
    Componente comp[MAX_COMP];
    int n, op;
    char busca[30];

    printf("Quantos componentes (max %d)? ", MAX_COMP);
    scanf("%d", &n);
    getchar(); // limpar buffer

    // Cadastro dos componentes
    for (int i = 0; i < n; i++) {
        printf("\nComponente %d\n", i+1);
        printf("Nome: ");
        fgets(comp[i].nome, sizeof(comp[i].nome), stdin);
        comp[i].nome[strcspn(comp[i].nome, "\n")] = 0;

        printf("Tipo: ");
        fgets(comp[i].tipo, sizeof(comp[i].tipo), stdin);
        comp[i].tipo[strcspn(comp[i].tipo, "\n")] = 0;

        printf("Prioridade (1 a 10): ");
        scanf("%d", &comp[i].prioridade);
        getchar();
    }

    // Menu
    do {
        printf("\n--- MENU ---\n");
        printf("1 - Bubble sort (nome)\n");
        printf("2 - Insertion sort (tipo)\n");
        printf("3 - Selection sort (prioridade)\n");
        printf("0 - Sair\n");
        scanf("%d", &op);

        int comparacoes = 0;
        clock_t inicio, fim;
        double tempo;

        switch (op) {
            case 1:
                inicio = clock();
                comparacoes = bubbleSortNome(comp, n);
                fim = clock();
                tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
                mostrarComponentes(comp, n);
                printf("Comparacoes: %d | Tempo: %.6f s\n", comparacoes, tempo);
                printf("Digite nome para busca binaria: ");
                getchar();
                fgets(busca, sizeof(busca), stdin);
                busca[strcspn(busca, "\n")] = 0;
                buscaBinariaPorNome(comp, n, busca);
                break;

            case 2:
                inicio = clock();
                comparacoes = insertionSortTipo(comp, n);
                fim = clock();
                tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
                mostrarComponentes(comp, n);
                printf("Comparacoes: %d | Tempo: %.6f s\n", comparacoes, tempo);
                break;

            case 3:
                inicio = clock();
                comparacoes = selectionSortPrioridade(comp, n);
                fim = clock();
                tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
                mostrarComponentes(comp, n);
                printf("Comparacoes: %d | Tempo: %.6f s\n", comparacoes, tempo);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (op != 0);

    return 0;
}
