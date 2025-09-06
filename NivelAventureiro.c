#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura do item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Estrutura do nó da lista encadeada
typedef struct No {
    Item dados;
    struct No* proximo;
} No;

// --- Mochila com vetor ---
Item mochilaVetor[MAX_ITENS];
int totalItensVetor = 0;

// --- Mochila com lista ---
No* mochilaLista = NULL;

// --- Contadores ---
int comparacoesSequencial = 0;
int comparacoesBinaria = 0;

// Funções do Vetor 

// Insere item no vetor
void inserirItemVetor(Item novo) {
    if (totalItensVetor >= MAX_ITENS) {
        printf("Mochila cheia (vetor)!\n");
        return;
    }
    mochilaVetor[totalItensVetor++] = novo;
    printf("Item inserido no vetor.\n");
}

// Remove item do vetor pelo nome
void removerItemVetor(char* nome) {
    for (int i = 0; i < totalItensVetor; i++) {
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            for (int j = i; j < totalItensVetor - 1; j++) {
                mochilaVetor[j] = mochilaVetor[j + 1];
            }
            totalItensVetor--;
            printf("Item removido do vetor.\n");
            return;
        }
    }
    printf("Item nao encontrado no vetor.\n");
}

// Lista itens no vetor
void listarItensVetor() {
    printf("\n--- Mochila (Vetor) ---\n");
    for (int i = 0; i < totalItensVetor; i++) {
        printf("%s | %s | %d\n",
               mochilaVetor[i].nome,
               mochilaVetor[i].tipo,
               mochilaVetor[i].quantidade);
    }
    if (totalItensVetor == 0) printf("Vazia.\n");
}

// Busca sequencial no vetor
void buscarSequencialVetor(char* nome) {
    comparacoesSequencial = 0;
    for (int i = 0; i < totalItensVetor; i++) {
        comparacoesSequencial++;
        if (strcmp(mochilaVetor[i].nome, nome) == 0) {
            printf("Encontrado: %s | %s | %d\n",
                   mochilaVetor[i].nome,
                   mochilaVetor[i].tipo,
                   mochilaVetor[i].quantidade);
            printf("Comparacoes (sequencial): %d\n", comparacoesSequencial);
            return;
        }
    }
    printf("Item nao encontrado. Comparacoes: %d\n", comparacoesSequencial);
}

// Ordena vetor por nome (Bubble Sort simples)
void ordenarVetor() {
    for (int i = 0; i < totalItensVetor - 1; i++) {
        for (int j = 0; j < totalItensVetor - i - 1; j++) {
            if (strcmp(mochilaVetor[j].nome, mochilaVetor[j+1].nome) > 0) {
                Item tmp = mochilaVetor[j];
                mochilaVetor[j] = mochilaVetor[j+1];
                mochilaVetor[j+1] = tmp;
            }
        }
    }
    printf("Vetor ordenado por nome.\n");
}

// Busca binária no vetor
void buscarBinariaVetor(char* nome) {
    comparacoesBinaria = 0;
    int ini = 0, fim = totalItensVetor - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        comparacoesBinaria++;
        int cmp = strcmp(nome, mochilaVetor[meio].nome);
        if (cmp == 0) {
            printf("Encontrado: %s | %s | %d\n",
                   mochilaVetor[meio].nome,
                   mochilaVetor[meio].tipo,
                   mochilaVetor[meio].quantidade);
            printf("Comparacoes (binaria): %d\n", comparacoesBinaria);
            return;
        } else if (cmp < 0) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    printf("Item nao encontrado. Comparacoes: %d\n", comparacoesBinaria);
}


// Funções da Lista     

// Insere item na lista
void inserirItemLista(Item novo) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->dados = novo;
    novoNo->proximo = mochilaLista;
    mochilaLista = novoNo;
    printf("Item inserido na lista.\n");
}

// Remove item da lista
void removerItemLista(char* nome) {
    No* atual = mochilaLista;
    No* anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->dados.nome, nome) == 0) {
            if (anterior == NULL) {
                mochilaLista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            printf("Item removido da lista.\n");
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Item nao encontrado na lista.\n");
}

// Lista itens da lista
void listarItensLista() {
    printf("\n--- Mochila (Lista) ---\n");
    No* atual = mochilaLista;
    if (!atual) {
        printf("Vazia.\n");
        return;
    }
    while (atual != NULL) {
        printf("%s | %s | %d\n",
               atual->dados.nome,
               atual->dados.tipo,
               atual->dados.quantidade);
        atual = atual->proximo;
    }
}

// Busca sequencial na lista
void buscarSequencialLista(char* nome) {
    comparacoesSequencial = 0;
    No* atual = mochilaLista;
    while (atual != NULL) {
        comparacoesSequencial++;
        if (strcmp(atual->dados.nome, nome) == 0) {
            printf("Encontrado: %s | %s | %d\n",
                   atual->dados.nome,
                   atual->dados.tipo,
                   atual->dados.quantidade);
            printf("Comparacoes (sequencial): %d\n", comparacoesSequencial);
            return;
        }
        atual = atual->proximo;
    }
    printf("Item nao encontrado na lista. Comparacoes: %d\n", comparacoesSequencial);
}

// Função principal    
int main() {
    int escolha, estrutura;
    Item novo;
    char nome[30];

    do {
        printf("\n=== Menu ===\n");
        printf("1 - Usar vetor\n");
        printf("2 - Usar lista\n");
        printf("0 - Sair\n");
        scanf("%d", &estrutura);

        if (estrutura == 1) {
            printf("\n--- Mochila com Vetor ---\n");
            printf("1 - Inserir\n2 - Remover\n3 - Listar\n4 - Buscar sequencial\n5 - Ordenar\n6 - Buscar binaria\n0 - Voltar\n");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    printf("Nome: "); scanf(" %[^\n]", novo.nome);
                    printf("Tipo: "); scanf(" %[^\n]", novo.tipo);
                    printf("Qtd: "); scanf("%d", &novo.quantidade);
                    inserirItemVetor(novo);
                    break;
                case 2:
                    printf("Nome para remover: "); scanf(" %[^\n]", nome);
                    removerItemVetor(nome);
                    break;
                case 3: listarItensVetor(); break;
                case 4:
                    printf("Nome para buscar: "); scanf(" %[^\n]", nome);
                    buscarSequencialVetor(nome);
                    break;
                case 5: ordenarVetor(); break;
                case 6:
                    printf("Nome para buscar (binaria): "); scanf(" %[^\n]", nome);
                    buscarBinariaVetor(nome);
                    break;
            }
        } else if (estrutura == 2) {
            printf("\n--- Mochila com Lista ---\n");
            printf("1 - Inserir\n2 - Remover\n3 - Listar\n4 - Buscar sequencial\n0 - Voltar\n");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                    printf("Nome: "); scanf(" %[^\n]", novo.nome);
                    printf("Tipo: "); scanf(" %[^\n]", novo.tipo);
                    printf("Qtd: "); scanf("%d", &novo.quantidade);
                    inserirItemLista(novo);
                    break;
                case 2:
                    printf("Nome para remover: "); scanf(" %[^\n]", nome);
                    removerItemLista(nome);
                    break;
                case 3: listarItensLista(); break;
                case 4:
                    printf("Nome para buscar: "); scanf(" %[^\n]", nome);
                    buscarSequencialLista(nome);
                    break;
            }
        }

    } while (estrutura != 0);

    printf("Encerrando...\n");
    return 0;
}
