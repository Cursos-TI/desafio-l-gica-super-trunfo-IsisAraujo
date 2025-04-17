#include <stdio.h>
#include <string.h>

struct Cidade {
    char estado[30];
    char codigo[10];
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
};

float densidade(struct Cidade c) {
    return c.populacao / c.area;
}

void exibir_menu() {
    printf("Atributos disponíveis para comparação:\n");
    printf("1 - População (maior vence)\n");
    printf("2 - Área (maior vence)\n");
    printf("3 - PIB (maior vence)\n");
    printf("4 - Pontos turísticos (maior vence)\n");
    printf("5 - Densidade populacional (menor vence)\n");
}

int comparar(struct Cidade c1, struct Cidade c2, int atributo) {
    switch (atributo) {
        case 1: return (c1.populacao > c2.populacao) ? 1 : (c1.populacao < c2.populacao) ? 2 : 0;
        case 2: return (c1.area > c2.area) ? 1 : (c1.area < c2.area) ? 2 : 0;
        case 3: return (c1.pib > c2.pib) ? 1 : (c1.pib < c2.pib) ? 2 : 0;
        case 4: return (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : (c1.pontos_turisticos < c2.pontos_turisticos) ? 2 : 0;
        case 5: {
            float d1 = densidade(c1);
            float d2 = densidade(c2);
            return (d1 < d2) ? 1 : (d2 < d1) ? 2 : 0;
        }
        default: return -1;
    }
}

int main() {
    struct Cidade carta1, carta2;
    int atr1, atr2;

    // Cadastro carta 1
    printf("Cadastro da primeira carta:\n");
    printf("Estado: "); scanf(" %[^\n]", carta1.estado);
    printf("Código da carta: "); scanf(" %s", carta1.codigo);
    printf("Nome da cidade: "); scanf(" %[^\n]", carta1.nome);
    printf("População: "); scanf("%d", &carta1.populacao);
    printf("Área (km²): "); scanf("%f", &carta1.area);
    printf("PIB (em bilhões): "); scanf("%f", &carta1.pib);
    printf("Número de pontos turísticos: "); scanf("%d", &carta1.pontos_turisticos);

    printf("\n");

    // Cadastro carta 2
    printf("Cadastro da segunda carta:\n");
    printf("Estado: "); scanf(" %[^\n]", carta2.estado);
    printf("Código da carta: "); scanf(" %s", carta2.codigo);
    printf("Nome da cidade: "); scanf(" %[^\n]", carta2.nome);
    printf("População: "); scanf("%d", &carta2.populacao);
    printf("Área (km²): "); scanf("%f", &carta2.area);
    printf("PIB (em bilhões): "); scanf("%f", &carta2.pib);
    printf("Número de pontos turísticos: "); scanf("%d", &carta2.pontos_turisticos);

    printf("\n--- Escolha dois atributos para comparação ---\n");
    exibir_menu();
    printf("Primeiro atributo: ");
    scanf("%d", &atr1);
    printf("Segundo atributo: ");
    scanf("%d", &atr2);

    // Comparações
    int resultado1 = comparar(carta1, carta2, atr1);
    int resultado2 = comparar(carta1, carta2, atr2);

    printf("\n--- Resultado ---\n");

    // Decisão final com base nos dois atributos
    if (resultado1 == resultado2 && resultado1 != 0) {
        // mesma carta venceu nos dois
        printf("Vencedora: %s (venceu nos dois critérios)\n", resultado1 == 1 ? carta1.nome : carta2.nome);
    } else if ((resultado1 == 1 && resultado2 == 0) || (resultado2 == 1 && resultado1 == 0)) {
        printf("Vencedora: %s (venceu em um critério, empate no outro)\n", carta1.nome);
    } else if ((resultado1 == 2 && resultado2 == 0) || (resultado2 == 2 && resultado1 == 0)) {
        printf("Vencedora: %s (venceu em um critério, empate no outro)\n", carta2.nome);
    } else if ((resultado1 == 1 && resultado2 != 2) || (resultado2 == 1 && resultado1 != 2)) {
        printf("Vencedora: %s (venceu em um critério e o outro foi empate ou mesmo vencedor)\n", carta1.nome);
    } else if ((resultado1 == 2 && resultado2 != 1) || (resultado2 == 2 && resultado1 != 1)) {
        printf("Vencedora: %s (venceu em um critério e o outro foi empate ou mesmo vencedor)\n", carta2.nome);
    } else if (resultado1 == 0 && resultado2 == 0) {
        printf("Empate total: nenhuma carta venceu\n");
    } else {
        // Cada carta venceu um critério
        printf("Empate técnico: cada cidade venceu em um critério\n");
    }

    return 0;
}
