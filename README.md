# Projeto de Estrutura de Dados em C: A Jornada do Herói

Este projeto acadêmico foi desenvolvido para a disciplina de Estrutura de Dados e demonstra a implementação e o uso de diferentes estruturas e algoritmos em C, com uma complexidade crescente. A jornada é dividida em três níveis: Novato, Aventureiro e Mestre.

## Visão Geral do Projeto

O objetivo principal é aplicar conceitos fundamentais de programação e estrutura de dados através de pequenos sistemas interativos via console. Cada "nível" representa um marco no aprendizado, introduzindo novas técnicas e aprimorando as anteriores.

- **Nível Novato:** Foco na manipulação básica de vetores (arrays).
- **Nível Aventureiro:** Introdução de listas encadeadas e comparação de performance com vetores, além da implementação de algoritmos de busca mais eficientes.
- **Nível Mestre:** Análise e comparação de diferentes algoritmos de ordenação (Bubble Sort, Insertion Sort, Selection Sort) e sua aplicação prática.

## Níveis de Dificuldade

### 🎒 Nível Novato (`NivelNovato.c`)

O ponto de partida da jornada. Este código implementa um sistema simples de gerenciamento de uma "mochila" de itens usando um **vetor** como estrutura de armazenamento.

**Funcionalidades:**
- **Inserir:** Adiciona um novo item (nome, tipo, quantidade) à mochila.
- **Remover:** Exclui um item da mochila pelo nome.
- **Listar:** Exibe todos os itens presentes na mochila.
- **Busca Sequencial:** Procura por um item específico pelo nome.

### 🗺️ Nível Aventureiro (`NivelAventureiro.c`)

Neste nível, o projeto evolui para comparar duas abordagens diferentes para o mesmo problema: o gerenciamento da mochila. Além do vetor, uma **lista encadeada** é implementada, permitindo uma análise comparativa entre as duas estruturas.

**Funcionalidades:**
- **Duas Estruturas:** O usuário pode escolher entre manipular os dados em um vetor ou em uma lista encadeada.
- **Operações CRUD:** Inserir, Remover e Listar itens estão disponíveis para ambas as estruturas.
- **Algoritmos de Busca:**
    - **Busca Sequencial:** Implementada tanto para o vetor quanto para a lista.
    - **Busca Binária:** Implementada para o vetor, exigindo que os dados estejam previamente ordenados.
- **Ordenação:** Uma função de ordenação (Bubble Sort) foi adicionada para o vetor, sendo um pré-requisito para a busca binária.
- **Contador de Comparações:** O código mede e exibe o número de comparações realizadas nas buscas, permitindo uma análise de eficiência.

### 🧙 Nível Mestre (`NivelMestre.c`)

O ápice da jornada, focado na análise de performance de diferentes **algoritmos de ordenação**. O sistema gerencia componentes de uma torre, que podem ser ordenados por diferentes critérios.

**Funcionalidades:**
- **Cadastro de Componentes:** O usuário pode cadastrar múltiplos componentes, cada um com nome, tipo e prioridade.
- **Algoritmos de Ordenação:**
    - **Bubble Sort:** Para ordenar os componentes pelo `nome`.
    - **Insertion Sort:** Para ordenar pelo `tipo`.
    - **Selection Sort:** Para ordenar pela `prioridade`.
- **Análise de Performance:** Para cada algoritmo de ordenação, o sistema calcula e exibe:
    - O número total de **comparações** realizadas.
    - O **tempo de execução** em segundos.
- **Busca Binária Avançada:** Após ordenar por nome usando o Bubble Sort, o usuário pode realizar uma busca binária para encontrar um componente.
