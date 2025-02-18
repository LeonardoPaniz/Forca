#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARQUIVO "palavras.bin"

void carregarPalavras(char tabela[10][100]) {
    FILE *file = fopen(ARQUIVO, "rb");

    if (file == NULL) {
        printf("Arquivo de palavras não encontrado. Criando um novo arquivo...\n");
        file = fopen(ARQUIVO, "wb");
        fclose(file);
        return;
    }

    fread(tabela, sizeof(char), 10 * 100, file);
    fclose(file);
}

void salvarPalavras(char tabela[10][100]) {
    FILE *file = fopen(ARQUIVO, "wb");

    if (file == NULL) {
        printf("Erro ao salvar as palavras no arquivo.\n");
        return;
    }

    fwrite(tabela, sizeof(char), 10 * 100, file);
    fclose(file);
}

void cadastrarPalavra(char tabela[10][100]) {
    char palavra[100];
    int livre = -1;
    int haveNumbers = 0;

    printf("\n\n------------------------------------------------------------------------\n");
    printf("Vamos cadastrar a palavra:\n");
    printf("A palavra não pode ser repetida, deve conter mais de 5 letras.\n");
    printf("------------------------------------------------------------------------\n\n");
    printf("Insira a palavra: ");
    scanf(" %[^\n]s", palavra);

    for (int i = 0; palavra[i] != '\0'; i++) {
        palavra[i] = toupper(palavra[i]);
    }

    if (strlen(palavra) >= 5) {
        for (int i = 0; i < 10; i++) {
            if (strcmp(palavra, tabela[i]) == 0) {
                printf("Palavra Repetida Detectada = %s\n", palavra);
                return;
            }
            if (tabela[i][0] == '\0' && livre == -1) {
                livre = i;
            }
        }

        if (livre != -1) {
            for (int i = 0; i < strlen(palavra); i++) {
                if (!isalpha(palavra[i])) {
                    haveNumbers = 1;
                }
            }
            if (haveNumbers == 0) {
                strcpy(tabela[livre], palavra);
                salvarPalavras(tabela);
                printf("\nPalavra cadastrada com sucesso!\n");
            } else {
                printf("Palavra contém caracteres inválidos!\n");
            }
        } else {
            printf("A tabela está cheia!\n");
        }
    } else {
        printf("A palavra deve possuir mais de 5 caracteres.\n");
    }
}

void atualizarPalavra(char tabela[10][100]) {
    int option, haveNumbers = 0;
    char palavra[100];

    printf("\nSelecione a palavra para atualizar:\n");
    mostrarPalavras(tabela);
    printf("Digite o número da palavra a ser atualizada: ");
    scanf("%d", &option);

    if (option > 0 && option <= 10 && tabela[option - 1][0] != '\0') {
        printf("Digite a nova palavra: ");
        scanf(" %[^\n]s", palavra);

        if (strlen(palavra) >= 5) {
            for (int i = 0; i < 10; i++) {
                if (strcmp(palavra, tabela[i]) == 0) {
                    printf("Palavra Repetida Detectada = %s\n", palavra);
                    return;
                }
            }

            for (int i = 0; i < strlen(palavra); i++) {
                if (!isalpha(palavra[i])) {
                    haveNumbers = 1;
                }
            }

            if (haveNumbers == 0) {
                strcpy(tabela[option - 1], palavra);
                salvarPalavras(tabela);
                printf("Palavra Atualizada com sucesso!\n");
            } else {
                printf("Palavra contém caracteres inválidos!\n");
            }
        } else {
            printf("A palavra deve possuir mais de 5 caracteres.\n");
        }
    } else {
        printf("Opção inválida!\n");
    }
}

void apagarPalavra(char tabela[10][100]) {
    int option;
    printf("\nSelecione a palavra para exclusão:\n");
    mostrarPalavras(tabela);
    printf("Digite o número da palavra a ser apagada: ");
    scanf("%d", &option);

    if (option > 0 && option <= 10 && tabela[option - 1][0] != '\0') {
        tabela[option - 1][0] = '\0';
        salvarPalavras(tabela);
        printf("Palavra apagada com sucesso!\n");
    } else {
        printf("Opção inválida!\n");
    }
}

void mostrarPalavras(char tabela[10][100]) {
    printf("\nPalavras cadastradas:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < 10; i++) {
        if (tabela[i][0] != '\0') {
            printf("%d) %s\n", i + 1, tabela[i]);
        }
    }
    printf("----------------------------------------\n");
}
void subMenu(char tabela[10][100]) {
    int opcao;
    while (1) {
        printf("\n----------- SUBMENU -----------\n");
        printf("1) Jogar novamente\n");
        printf("2) Retornar ao menu principal\n");
        printf("3) Sair do jogo\n");
        printf("-------------------------------\n");
        printf("Escolha uma opção: ");
        scanf(" %d", &opcao);

        switch (opcao) {
        case 1:
            play(tabela);
            return;
        case 2:
            return;
        case 3:
            printf("\n\n=======================================\n");
            printf("Obrigado por jogar a forca! Até logo!\n");
            printf("=======================================\n");
            exit(0);
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
    }
}

void play(char tabela[10][100]) {
    int pontucao = 0, tentativas = 6, acertou = 0, ganhou = 0, palpiteIndex = 0;
    char palavra[100], palpite, arrayPalpites[26];

    srand(time(NULL));
    int randomNumber = rand() % 10;
    strcpy(palavra, tabela[randomNumber]);

    for (int i = 0; palavra[i] != '\0'; i++) {
        palavra[i] = toupper(palavra[i]);
    }

    int tamanho = strlen(palavra);
    char resposta[tamanho + 1];

    for (int i = 0; i < tamanho; i++) {
        resposta[i] = '_';
    }
    resposta[tamanho] = '\0';

    printf("Que bom te ver aqui, Vamos começar");
    printf("\n\n------------------------------------------------------------------------\n\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%c ", resposta[i]);
    }

    do {
        do {
            printf("\n\nDigite seu palpite (apenas uma letra): ");
            scanf(" %c", &palpite);

            palpite = toupper(palpite);

            if (!isalpha(palpite)) {
                printf("Entrada inválida! Por favor, insira apenas uma letra do alfabeto.\n");
                continue;
            }

            int repetido = 0;
            for (int i = 0; i < palpiteIndex; i++) {
                if (arrayPalpites[i] == palpite) {
                    printf("Você já usou essa letra! Tente outra.\n");
                    repetido = 1;
                    break;
                }
            }

            if (!repetido) {
                break;
            }

        } while (1);

        arrayPalpites[palpiteIndex] = palpite;
        palpiteIndex++;
        printf("\n\n------------------------------------------------------------------------\n\n\n\n");

        acertou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavra[i] == palpite) {
                acertou = 1;
                resposta[i] = palpite;
            }
        }

        for (int i = 0; i < tamanho; i++) {
            printf("%c ", resposta[i]);
        }

        if (palpiteIndex > 0) {
            printf("\n\n------------------------------------------------------------------------\n");
            printf("Palpites: ");
            for (int i = 0; i < palpiteIndex; i++) {
                printf("%c | ", arrayPalpites[i]);
            }
        }

        if (acertou == 1) {
            pontucao += 10;
            acertou = 0;
        } else {
            if (pontucao - 5 < 0) {
                pontucao = 0;
            } else {
                pontucao -= 5;
            }
            tentativas--;
        }
        printf("\nPontuação: %i  |  Suas tentativas restantes: %i\n", pontucao, tentativas);
        printf("\n------------------------------------------------------------------------\n\n");

        int validacao = strcmp(resposta, palavra);
        if (validacao == 0) {
            ganhou = 1;
        }

    } while (tentativas > 0 && ganhou == 0);

    if (tentativas == 0) {
        printf("Obrigado por jogar, espero nos ver em breve.\n\n");
    }
    if (ganhou == 1) {
        printf("Parabéns!!! Obrigado por jogar.\n\n");
    }
    printf("\n\n------------------------------------------------------------------------\n\n");
    printf("\nA palavra secreta era: %s\n", palavra);
    printf("Seu resultado final foi: %s", resposta);
    printf("\nPontuação: %i  |  Suas tentativas restantes: %i\n", pontucao, tentativas);
    printf("\n\n------------------------------------------------------------------------\n\n");

    subMenu(tabela);
}

int main() {
    int opcao = 0;
    char tabela[10][100] = {""};
    carregarPalavras(tabela);
    int palavrasDisponiveis = 0;

    printf("\n\n------------------------------------------------------------------------\n");
    printf("Seja bem-vindo ao Jogo da Forca.\n");
    printf("------------------------------------------------------------------------\n\n");

    do {
        printf("\n----------- MENU -----------\n");
        printf("1) Novo Jogo\n");
        printf("2) Cadastrar palavra\n");
        printf("3) Atualizar palavra\n");
        printf("4) Apagar palavra\n");
        printf("5) Mostrar palavras\n");
        printf("6) Sair\n");
        printf("-----------------------------\n");
        printf("Qual operação deseja realizar: ");
        scanf(" %d", &opcao);

        switch (opcao) {
        case 1:
            palavrasDisponiveis = 0;
            for (int i = 0; i < 10; i++) {
                if (tabela[i][0] == '\0') {
                    palavrasDisponiveis = 1;
                    break;
                }
            }
            if (!palavrasDisponiveis) {
                play(tabela);
            } else {
                printf("Não há palavras o suficientes. Cadastre 10 palavras!\n");
            }
            break;
        case 2:
            cadastrarPalavra(tabela);
            break;
        case 3:
            atualizarPalavra(tabela);
            break;
        case 4:
            apagarPalavra(tabela);
            break;
        case 5:
            mostrarPalavras(tabela);
            break;
        case 6:
            printf("=======================================\n");
            printf("Muito obrigado por jogar a forca!\n");
            printf("=======================================\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n\n");
        }
    } while (opcao != 6);

    return 0;
}
