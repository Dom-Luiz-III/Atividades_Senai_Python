#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

int i;

typedef struct materia
{
	char nomea[30];
	char professor[30];
	int ch;
	float nota;
} tipo_materia;

typedef struct aluno
{
	char nomeb[30];
	tipo_materia disciplinas[5];
} alu;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

int main ()
{
	alu estudante;
	i = 0;
	
	setlocale(LC_ALL,"Portuguese");
	
	fflush(stdin);
	printf("Informe o nome do aluno: ");
	gets(estudante.nomeb);
	
	for (i=0;i<5;i++)
	{
	fflush(stdin);
		printf("\nInforme o nome da Disciplina: ");
		gets(estudante.disciplinas[i].nomea);
		printf("Informe o nome do Professor: ");
		scanf("%s", &estudante.disciplinas[i].professor);
		printf("Informe a carga horaria das disciplinas: ");
		scanf("%d", &estudante.disciplinas[i].ch);
		printf("Informe a nota: ");
		scanf("%f", &estudante.disciplinas[i].nota);
	}
	printf("O nome do segundo professor é %s", estudante.disciplinas[1].professor);

	
	return 0;
}
