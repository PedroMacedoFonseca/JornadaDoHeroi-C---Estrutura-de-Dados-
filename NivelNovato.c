#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura que representa cada item da mochila
typedef struct {
    char nome[30];     // nome do item (ex: "Pistola")
    char tipo[20];     // tipo do item (ex: "arma", "municao", "cura")
    int quantidade;    // quantidade do item
} Item;

// Vetor global para armazenar até 10 itens
Item mochila[MAX_ITENS];
int totalItens = 0; // contador de quantos itens estão cadastrados

// Função para cadastrar um novo item na mochila
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novo;

    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome); // lê até o final da linha

    printf("Tipo do item: ");
    scanf(" %[^\n]", novo.tipo);

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);

    // adiciona no vetor
    mochila[totalItens] = novo;
    totalItens++;

    printf("Item adicionado com sucesso!\n");
}

// Função para remover um item pelo nome
void removerItem() {
    char nomeRemover[30];
    printf("Digite o nome do item a ser removido: ");
    scanf(" %[^\n]", nomeRemover);

    int encontrado = -1;

    // busca o item pelo nome
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Item não encontrado.\n");
        return;
    }

    // desloca os itens para "apagar" o encontrado
    for (int i = encontrado; i < totalItens - 1; i++) {
        mochila[i] = mochila[i + 1];
    }

    totalItens--;
    printf("Item removido com sucesso!\n");
}

// Função para listar todos os itens da mochila
void listarItens() {
    if (totalItens == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n=== Itens na mochila ===\n");
    for (int i = 0; i < totalItens; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("========================\n");
}

// Função de busca sequencial por nome
void buscarItem() {
    char nomeBusca[30];
    printf("Digite o nome do item para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("Item encontrado: Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            return;
        }
    }

    printf("Item não encontrado.\n");
}

int main() {
    int opcao;

    do {
        printf("\n=== Menu da Mochila ===\n");
        printf("1 - Inserir item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItem(); break;
            case 0: printf("Saindo do sistema...\n"); break;
            default: printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
