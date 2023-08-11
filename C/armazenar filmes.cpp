#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct filme{
	char nome[10];
	char gen[10];
	int ano;
	int codigo = 10; //Por algum motivo tá dando erro aqui
	char diretor[10];
} movie;

void exibir_filme(movie *p);
void cadastro(movie *p, int codigo);
void exibir_filmes(movie *filmes);
void exibir_menu();
void excluir_filme(movie *filmes, int cod);

int main(){
	
	int opcao, next, cod;
	next=0;
	movie p[10];
	setlocale(LC_ALL, "Portuguese");
	
	
	do{
		exibir_menu();
		scanf ("%d", &opcao);
		switch(opcao){
			case 1:
				if(next < 10){
					cadastro(&p[next], next);
					next++;
				}
				else{
					printf ("\n\nO volume máximo de filmes cadastrados foi atingido.\n\n");
					system("pause");
				}
				
				break;
			case 2:	
				printf("\n\nInforme o código: ");
				scanf("%d", &cod);
				exibir_filme(&p[cod]);
				break;
			case 3:
				exibir_filmes(p);
				break;
			case 4:
				printf("\n\nDigite o código de 0 a 9 para informar o filme que deseja excluir: ");
				scanf("%d",&cod);
				excluir_filme(p, cod);
				break;
		}
	} while(opcao != 5);
	
	return 0;
}

void exibir_menu(){
	system("cls");
	printf("Olá!\nSeja bem vindo a nossa locadora!");
	printf("\n\nPor favor, escolha uma dessas opções abaixo e digite o seu número:\n\n");
	printf("    1 - Cadastrar filmes\n");
	printf("    2 - Exibir filme\n");
	printf("    3 - Exibir todos os filmes\n");
	printf("    4 - Excluir filme\n");
	printf("    5 - Sair\n\n");
	printf("O número escolhido: ");
}
void cadastro(movie *p, int codigo){
	system("cls");
	fflush(stdin);
	printf ("Informe o nome do filme: ");
	gets ((*p).nome);
	printf ("Gênero do filme: ");
	gets (p->gen);
	printf("Ano: ");
	scanf ("%d",&(*p).ano);
	printf("Nome do diretor: ");
	fflush(stdin);
	gets(p->diretor);
	p->codigo = codigo;
}
void exibir_filme(movie *p){
	system("cls");
	printf("Insira o código: %d",p->codigo);
	system("cls");
	printf("Nome do filme: \n");
	puts (p->nome);	
	printf("\nGênero: \n");
	puts (p->gen);
	printf("\nAno: \n%d\n", p->ano);
	printf("\nNome do diretor: \n");
	puts (p->diretor);
	system("pause");	
}
void exibir_filmes(movie *p){

	system("cls");
	
	for(int cont=0; cont < 10; cont ++){
		if (p[cont].codigo < 10){
			exibir_filme(&p[cont]);
		}
	}
}
void excluir_filme(movie *p, int cod){
	system("cls");
	while(cod < 9){
		strcpy(p[cod].nome, p[cod+1].nome);
		strcpy(p[cod].gen, p[cod+1].gen);
		p[cod].ano = p[cod+1].ano;
		strcpy(p[cod].diretor, p[cod+1].diretor);
		if(p[cod+2].codigo == 10){
			p[cod+1].codigo = 10;
		}
		cod ++;
	}
	printf("Esse espaço está disponível!\n\n");
	system("pause");
}
