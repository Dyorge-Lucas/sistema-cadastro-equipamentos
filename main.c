
#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    char estado[30];
} Equipamento;

int main() {
    Equipamento equipamentos[100];
    int total = 0;
    int opcao;

    do {
        printf("\n=== SISTEMA DE EQUIPAMENTOS ===\n");
        printf("1 - Cadastrar equipamento\n");
        printf("2 - Listar equipamentos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            return 1;
        }

        getchar();

        switch (opcao) {
            case 1:
                if (total >= 100) {
                    printf("Limite de equipamentos atingido!\n");
                    break;
                }

                printf("Nome do equipamento: ");
                fgets(equipamentos[total].nome, 50, stdin);
                equipamentos[total].nome[
                    strcspn(equipamentos[total].nome, "\n")
                ] = '\0';

                printf("Estado do equipamento: ");
                fgets(equipamentos[total].estado, 30, stdin);
                equipamentos[total].estado[
                    strcspn(equipamentos[total].estado, "\n")
                ] = '\0';

                total++;
                printf("Equipamento cadastrado com sucesso!\n");
                break;

            case 2:
                if (total == 0) {
                    printf("Nenhum equipamento cadastrado.\n");
                } else {
                    printf("\n=== EQUIPAMENTOS CADASTRADOS ===\n");

                    for (int i = 0; i < total; i++) {
                        printf("\nEquipamento %d\n", i + 1);
                        printf("Nome: %s\n", equipamentos[i].nome);
                        printf("Estado: %s\n", equipamentos[i].estado);
                    }
                }
                break;

            case 0:
                printf("Encerrando o sistema. Ate mais!\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}

