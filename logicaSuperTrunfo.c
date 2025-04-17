#include <stdio.h>
#include <string.h>

// Estrutura que representa uma cidade/carta
struct Cidade {
    char estado[30];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

int main() {
    struct Cidade carta1, carta2;

    // Entrada de dados da primeira carta
    printf("Cadastro da primeira carta:\n");

    printf("Estado: ");
    scanf(" %[^\n]", carta1.estado);

    printf("Código da carta: ");
    scanf(" %s", carta1.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta1.nome);

    printf("População: ");
    scanf("%d", &carta1.populacao);

    printf("Área (km²): ");
    scanf("%f", &carta1.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta1.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta1.pontos_turisticos);

    printf("\n");

    // Entrada de dados da segunda carta
    printf("Cadastro da segunda carta:\n");

    printf("Estado: ");
    scanf(" %[^\n]", carta2.estado);

    printf("Código da carta: ");
    scanf(" %s", carta2.codigo);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", carta2.nome);

    printf("População: ");
    scanf("%d", &carta2.populacao);

    printf("Área (km²): ");
    scanf("%f", &carta2.area);

    printf("PIB (em bilhões): ");
    scanf("%f", &carta2.pib);

    printf("Número de pontos turísticos: ");
    scanf("%d", &carta2.pontos_turisticos);

    printf("\n--- Comparando Cartas ---\n");

    // Mostrando os dados das duas cartas
    printf("\nCarta 1: %s (%s) - PIB: %.2f\n", carta1.nome, carta1.estado, carta1.pib);
    printf("Carta 2: %s (%s) - PIB: %.2f\n", carta2.nome, carta2.estado, carta2.pib);

    // Comparação com base no PIB
    if (carta1.pib > carta2.pib) {
        printf("\nCarta vencedora: %s (maior PIB)\n", carta1.nome);
    } else if (carta2.pib > carta1.pib) {
        printf("\nCarta vencedora: %s (maior PIB)\n", carta2.nome);
    } else {
        printf("\nEmpate: ambas as cidades têm o mesmo PIB.\n");
    }

    return 0;
}
