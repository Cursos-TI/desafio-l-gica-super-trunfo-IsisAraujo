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

int main() {
    struct Cidade carta1, carta2;
    int opcao;

    // Cadastro da primeira carta
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

    // Cadastro da segunda carta
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

    // Menu de comparação
    printf("\n--- Menu de Comparação ---\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade populacional (menor vence)\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    printf("\n--- Resultado ---\n");

    switch (opcao) {
        case 1:
            if (carta1.populacao > carta2.populacao)
                printf("Vencedora: %s (maior população)\n", carta1.nome);
            else if (carta2.populacao > carta1.populacao)
                printf("Vencedora: %s (maior população)\n", carta2.nome);
            else
                printf("Empate na população.\n");
            break;
        case 2:
            if (carta1.area > carta2.area)
                printf("Vencedora: %s (maior área)\n", carta1.nome);
            else if (carta2.area > carta1.area)
                printf("Vencedora: %s (maior área)\n", carta2.nome);
            else
                printf("Empate na área.\n");
            break;
        case 3:
            if (carta1.pib > carta2.pib)
                printf("Vencedora: %s (maior PIB)\n", carta1.nome);
            else if (carta2.pib > carta1.pib)
                printf("Vencedora: %s (maior PIB)\n", carta2.nome);
            else
                printf("Empate no PIB.\n");
            break;
        case 4:
            if (carta1.pontos_turisticos > carta2.pontos_turisticos)
                printf("Vencedora: %s (mais pontos turísticos)\n", carta1.nome);
            else if (carta2.pontos_turisticos > carta1.pontos_turisticos)
                printf("Vencedora: %s (mais pontos turísticos)\n", carta2.nome);
            else
                printf("Empate nos pontos turísticos.\n");
            break;
        case 5: {
            float densidade1 = carta1.populacao / carta1.area;
            float densidade2 = carta2.populacao / carta2.area;
            if (densidade1 < densidade2)
                printf("Vencedora: %s (menor densidade populacional)\n", carta1.nome);
            else if (densidade2 < densidade1)
                printf("Vencedora: %s (menor densidade populacional)\n", carta2.nome);
            else
                printf("Empate na densidade populacional.\n");
            break;
        }
        default:
            printf("Opção inválida.\n");
    }

    return 0;
}
