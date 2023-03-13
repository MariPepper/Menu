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

void porOrdem();
float funcMedia(float, float);
int novoMenu();

int main () {
	bool ciclo = true;
	do {
		novoMenu();
	} while(ciclo!=true);

}

int novoMenu() {
	struct myAluno a[20];
	int num_Alunos = 0;
	int j, opcao;
	int i = 0;
	puts("\n");
	puts("1. Adicionar aluno"); // add student
	puts("2. Alterar aluno"); // edit student info
	puts("3. Eliminar aluno 1"); // reset to 0 for editing
	puts("4. Eliminar aluno 2"); // delete the students
	puts("5. Mostrar 1 aluno"); // display one student
	puts("6. Visualizar lista para corrigir"); // display full list for editing
	puts("7. Visualizar lista corrigida"); // display list with editing
	puts("8. Sair"); // exit program
	puts("\n");
	while(1) {
		puts("\n");
		printf("Escolha uma opcao: ");
		scanf("%d", &opcao);
		// Part 1 is ready to go.
		if(opcao == 1) {
			if(num_Alunos>=20) {
				printf("\nNúmero máximo de alunos alcançado.");
			} else {
				printf("Insira o ID do aluno: ");
				scanf("%d", &a[i].idAluno);
				printf("Insira o nome do aluno: ");
				scanf("%s", a[i].nome);
				printf("Insira a idade do aluno: ");
				scanf("%d", &a[i].idade);
				printf("Insira a nota (1) do aluno: ");
				scanf("%f", &a[i].nota1);
				printf("Insira a nota (2) do aluno: ");
				scanf("%f", &a[i].nota2);
				a[i].media = funcMedia(a[i].nota1, a[i].nota2);
				printf("%d Nome: %s\t Idade: %d\t Nota (1): %f\t Nota (2): %f\t Media: %f\n", a[i].idAluno, a[i].nome, a[i].idade, a[i].nota1, a[i].nota2, a[i].media);
				num_Alunos++;
			}
			// Part 2 is ready to go.
		} else if (opcao == 2) {
			printf("\nInsira o ID do aluno: ");
			scanf("%d", &j);
			for(int i=0; i < num_Alunos; i++) {
				if(a[i].idAluno==j) {
					printf("Insira o Novo ID do aluno: ");
					scanf("%d", &a[i].idAluno);
					printf("Insira o nome do aluno: ");
					scanf("%s", a[i].nome);
					printf("Insira a idade do aluno: ");
					scanf("%d", &a[i].idade);
					printf("Insira a nota (1) do aluno: ");
					scanf("%f", &a[i].nota1);
					printf("Insira a nota (2) do aluno: ");
					scanf("%f", &a[i].nota2);
					a[i].media = funcMedia(a[i].nota1, a[i].nota2);
					printf("%d Nome: %s\t Idade: %d\t Nota (1): %f\t Nota (2): %f\t Media: %f\n", a[i].idAluno, a[i].nome, a[i].idade, a[i].nota1, a[i].nota2, a[i].media);
					break;
				}
			}
			// Part 3 is ready to go.
		} else if (opcao == 3) {
			int found = 0;
			printf("Insira o ID do aluno: ");
			scanf("%d", &j);
			for (int i = 0; i < num_Alunos; i++) {
				if (a[i].idAluno==j) {
					a[i].idAluno = 0;
					a[i].nome[i] = 0;
					a[i].idade = 0;
					a[i].nota1 = 0;
					a[i].nota2 = 0;
					a[i].media = 0;
					found = 1;
					printf("\nAluno removido com sucesso.\n");
					break;
				}
			}
			if (!found) {
				printf("\nID do aluno não encontrado.");
				// Part 4 is ready to go.
			}
		} else if (opcao==4) {
			int k = 0;
			printf("\nInsira o ID do aluno: ");
			scanf("%d", &j);
			printf("\n------------------------------------------------------------------------------------------------\n");
			for (int i = k; i < num_Alunos-1; i++) {
				if (a[i].idAluno==j) {
					a[i].idAluno = a[i-i].idAluno;
					a[i] = a[i+1];
					printf("%d Nome: %s\t Idade: %d\t Nota (1): %f\t Nota (2): %f\t Media: %f\n", a[i].idAluno, a[i].nome, a[i].idade, a[i].nota1, a[i].nota2, a[i].media);
				}
			}
			num_Alunos--;
			// Part 5 is ready to go.
		} else if (opcao == 5) {
			printf("\nInsira o ID do aluno: ");
			scanf("%d", &j);
			for(i=0; i < num_Alunos; i++) {
				if(a[i].idAluno==j) {
					printf("\n------------------------------------------------------------------------------------------------\n");
					printf("%d Nome: %s\t Idade: %d\t Nota (1): %f\t Nota (2): %f\t Media: %f\n", a[i].idAluno, a[i].nome, a[i].idade, a[i].nota1, a[i].nota2, a[i].media);
				}
			}
			// Part 6 is ready to go.
		} else if (opcao == 6) {
			porOrdem(a, num_Alunos);
			printf("\n------------------------------------------------------------------------------------------------\n");
			for(i=0; i < num_Alunos; i++) {
				printf("%d Nome: %s\t Idade: %d\t Nota (1): %f\t Nota (2): %f\t Media: %f\n", a[i].idAluno, a[i].nome, a[i].idade, a[i].nota1, a[i].nota2, a[i].media);
			}
			// Part 7 is ready to go.
		} else if (opcao == 7) {
			int idUsado[20] = {0};
			printf("\nLista de alunos:\n");
			printf("\n------------------------------------------------------------------------------------------------\n");
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
			// Part 8 is ready to go.
		} else if (opcao == 8) {
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

void porOrdem(struct myAluno a[20], int num_Alunos) {
	struct myAluno b;
	for(int i=0; i < num_Alunos; i++) {
		for(int j=0; j < num_Alunos-i-1; j++) {
			if(a[j+1].idAluno < a[j].idAluno) {
				b = a[j];
				a[j] = a[j+1];
				a[j+1] = b;
			}
		}
	}
}



