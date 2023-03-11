// The functions with return don't need the struct name for variables (i.e. structname.var).
// The float variables "%f" cannot have decimal places or nothing else will work, maybe a library is missing.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct myAluno {
	char nome[50];
	int idAluno;
	int idade;
	float media;
	float nota1;
	float nota2;

};

float funcMedia(float, float);
novoMenu();

int main () {
	bool ciclo = true;
	do {
		novoMenu();
	} while(ciclo!=true);

}

novoMenu() {
	struct myAluno a[20];
	int num_Alunos = 0;
	int *p = NULL;
	int j, opcao;
	int i = 0;
	puts("\n");
	puts("1. Adicionar aluno");
	puts("2. Alterar aluno");
	puts("3. Eliminar aluno");
	puts("4. Mostrar 1 aluno");
	puts("5. Visualizar lista para corrigir");
	puts("6. Visualizar lista corrigida");
	puts("7. Sair");
	puts("\n");
	while(1) {
		printf("\nEscolha uma opcao: \n");
		scanf("%d", &opcao);
		// Part 1 is ready to go.
		if(opcao == 1) {
			if(num_Alunos>=20) {
				printf("Número máximo de alunos alcançado.\n");
			} else {
				printf("Insira o ID do aluno: \n");
				scanf("%d", &a[i].idAluno);
				printf("Insira o nome do aluno: \n");
				scanf("%s", a[i].nome);
				printf("Insira a idade do aluno: \n");
				scanf("%d", &a[i].idade);
				printf("Insira a nota (1) do aluno: \n");
				scanf("%f", &a[i].nota1);
				printf("Insira a nota (2) do aluno: \n");
				scanf("%f", &a[i].nota2);
				a[i].media = funcMedia(a[i].nota1, a[i].nota2);
				printf("%d Nome: %s\t Idade: %d\t Nota (1): %f\t Nota (2): %f\t Media: %f\n", a[i].idAluno, a[i].nome, a[i].idade, a[i].nota1, a[i].nota2, a[i].media);
				num_Alunos++;
			}
			// Part 2 is ready to go.
		} else if (opcao == 2) {
			printf("Insira o ID do aluno: \n");
			scanf("%d", &j);
			for(int i=0; i < num_Alunos; i++) {
				if(a[i].idAluno==j) {
					printf("Insira o Novo ID do aluno: \n");
					scanf("%d", &a[i].idAluno);
					printf("Insira o nome do aluno: \n");
					scanf("%s", a[i].nome);
					printf("Insira a idade do aluno: \n");
					scanf("%d", &a[i].idade);
					printf("Insira a nota (1) do aluno: \n");
					scanf("%f", &a[i].nota1);
					printf("Insira a nota (2) do aluno: \n");
					scanf("%f", &a[i].nota2);
					a[i].media = funcMedia(a[i].nota1, a[i].nota2);
					printf("%d Nome: %s\t Idade: %d\t Nota (1): %f\t Nota (2): %f\t Media: %f\n", a[i].idAluno, a[i].nome, a[i].idade, a[i].nota1, a[i].nota2, a[i].media);
				}
			}
			// Part 3 is ready to go.
		} else if (opcao == 3) {
			int found = 0;
			printf("Insira o ID do aluno: \n");
			scanf("%d", &j);
			for (int i = 0; i < num_Alunos; i++) {
				if (a[i].idAluno==j) {
					a[i].idAluno = p;
					a[i].nome[i] = "\n";
					a[i].idade = p;
					a[i].nota1 = 0;
					a[i].nota2 = 0;
					a[i].media = 0;
					found = 1;
					printf("Aluno removido com sucesso.\n");
					break;
				}
			}
			if (found) {
				printf("ID do aluno não encontrado.\n");
			}
			// Part 4 is ready to go.
		} else if (opcao == 4) {
			printf("Insira o ID do aluno: \n");
			scanf("%d", &j);
			for(i=0; i < num_Alunos; i++) {
				if(a[i].idAluno==j) {
					printf("%d Nome: %s\t Idade: %d\t Nota (1): %f\t Nota (2): %f\t Media: %f\n", a[i].idAluno, a[i].nome, a[i].idade, a[i].nota1, a[i].nota2, a[i].media);
				}
			}
			// Part 5 is ready to go.
		} else if (opcao == 5) {
			for(i=0; i < num_Alunos; i++) {
				if(a[i].idAluno - 1 < a[i].idAluno) {
					printf("%d Nome: %s\t Idade: %d\t Nota (1): %f\t Nota (2): %f\t Media: %f\n", a[i].idAluno, a[i].nome, a[i].idade, a[i].nota1, a[i].nota2, a[i].media);
				}
			}
			// Part 6 is ready to go.
		} else if (opcao == 6) {
			int idUsado[20] = {0};
			printf("\nLista de alunos:\n");
			for (int i = 0; i < num_Alunos; i++) {
				int repetido = 0;
				for (int j = 0; j < num_Alunos; j++) {
					if (a[i].idAluno == idUsado[j]) {
						repetido = 1;
						break;
					}
				}
				if (!repetido) {
					printf("%d Nome: %s\t Idade: %d\t Nota (1): %f\t Nota (2): %f\t Media: %f\n", a[i].idAluno, a[i].nome, a[i].idade, a[i].nota1, a[i].nota2, a[i].media);
					idUsado[i] = a[i].idAluno;
				}
			}
			// Part 7 is ready to go.
		} else if (opcao == 7) {
			printf("Volte sempre!\n");
			break;
		} else {
			printf("Volte a tentar.\n");
		}
	}
	return 0;
}

float funcMedia(float nota1, float nota2) {

	return (((nota1 + nota2) / 2));
}
/* Escolha alternativa para a opção 3:
for (int i = j-1; i < num_Alunos-1; i++) {
if (a[i].idAluno==j) {
vai repetir a iteração que vem a seguir, por isso precisa de uma nova iteração.
it will repeat the input that comes next, so it needs the next input.
}
} */
