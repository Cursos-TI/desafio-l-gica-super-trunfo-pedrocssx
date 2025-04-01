#include <stdio.h>

// Estrutura para armazenar os dados de uma cidade
typedef struct {
    char nome[50];
    char estado[3];
    int codigo;
    long populacao;
    float area;
    double pib;
    int pontos_turisticos;
} Cidade;

// Função para capturar os dados da cidade
void cadastrarCidade(Cidade *cidade) {
    printf("\nDigite o nome da cidade: ");
    scanf(" %49[^\n]", cidade->nome); // Ajuste para permitir espaços
    printf("Digite o estado (sigla): ");
    scanf(" %2s", cidade->estado);
    printf("Digite o código da cidade: ");
    scanf("%d", &cidade->codigo);
    printf("Digite a população: ");
    scanf("%ld", &cidade->populacao);
    printf("Digite a área (em km²): ");
    scanf("%f", &cidade->area);
    printf("Digite o PIB (em bilhões): ");
    scanf("%lf", &cidade->pib);
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);
}

// Função para comparar as cidades com base em um critério escolhido
void compararCidades(Cidade c1, Cidade c2, int criterio) {
    printf("\nComparação baseada em: ");
    switch (criterio) {
        case 1:
            printf("População\n");
            printf("Vencedor: %s\n", (c1.populacao > c2.populacao) ? c1.nome : c2.nome);
            break;
        case 2:
            printf("Área\n");
            printf("Vencedor: %s\n", (c1.area > c2.area) ? c1.nome : c2.nome);
            break;
        case 3:
            printf("PIB\n");
            printf("Vencedor: %s\n", (c1.pib > c2.pib) ? c1.nome : c2.nome);
            break;
        case 4:
            printf("Pontos turísticos\n");
            printf("Vencedor: %s\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? c1.nome : c2.nome);
            break;
        case 5:
            printf("Densidade populacional (menor valor vence)\n");
            printf("Vencedor: %s\n", ((c1.populacao / c1.area) < (c2.populacao / c2.area)) ? c1.nome : c2.nome);
            break;
        default:
            printf("Critério inválido.\n");
    }
}

int main() {
    Cidade cidade1, cidade2;
    int criterio;

    printf("Cadastro da primeira cidade:\n");
    cadastrarCidade(&cidade1);
    
    printf("\nCadastro da segunda cidade:\n");
    cadastrarCidade(&cidade2);
    
    printf("\nEscolha o critério de comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos turísticos\n5 - Densidade populacional\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &criterio);
    
    compararCidades(cidade1, cidade2, criterio);

    return 0;
}
