#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void exibirConteudoArquivo(const char* filename) {
    FILE* file_ptr = fopen(filename, "r");
    if (file_ptr == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", filename);
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file_ptr)) {
        printf("%s", buffer);
    }

    fclose(file_ptr);
}

void apagarConteudoArquivo(const char* filename) {
    FILE* file_ptr = fopen(filename, "w"); 
    if (file_ptr == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", filename);
        return;
    }
    fclose(file_ptr);
    printf("Conteúdo do arquivo %s apagado com sucesso\n", filename);
}

void inserirNovoConteudo(const char* filename) {
    char novo_conteudo[BUFFER_SIZE];
    printf("\nDigite o novo conteúdo:\n");
    scanf(" %[^\n]s", novo_conteudo);

    FILE* file_ptr = fopen(filename, "w");
    if (file_ptr == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", filename);
        return;
    }

    fprintf(file_ptr, "%s", novo_conteudo);
    fclose(file_ptr);

    printf("Novo conteúdo inserido no arquivo %s.\n", filename);
}

int main() {
    char filename[100];
    char escolha;

    printf("Digite o nome do arquivo: ");
    scanf("%s", filename);

    while (1) {
        printf("\n----- Menu CRUD -----\n");
        printf("1. Exibir Conteúdo do Arquivo\n");
        printf("2. Apagar Conteúdo do Arquivo\n");
        printf("3. Inserir Novo Conteúdo\n");
        printf("4. Sair\n");
        printf("Digite sua escolha (1-4): ");
        scanf(" %c", &escolha);

        switch (escolha) {
            case '1':
                printf("\nConteúdo do Arquivo:\n");
                exibirConteudoArquivo(filename);
                break;
            case '2':
                printf("\nDeseja apagar o conteúdo do arquivo? (s/n): ");
                scanf(" %c", &escolha);
                if (escolha == 's' || escolha == 'S') {
                    apagarConteudoArquivo(filename);
                } else {
                    printf("Cancelado. O conteúdo do arquivo não foi apagado.\n");
                }
                break;
            case '3':
                inserirNovoConteudo(filename);
                break;
            case '4':
                printf("Encerrando...\n");
                return 0;
            default:
                printf("Escolha inválida. Por favor, digite uma opção válida (1-4).\n");
                break;
        }
    }

    return 0;
}
