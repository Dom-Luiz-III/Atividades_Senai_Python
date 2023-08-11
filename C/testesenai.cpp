#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct filme{
	char nome[10];
	char gen[10];
	int ano;
	char diretor[10];
	int codigo = 10;
} movie;

void exibir_filme(movie *p);
void cadastro(movie *p, int codigo);
void exibir_filmes(movie *filmes);
void exibir_menu();
void excluir_filme(movie *filmes, int cod);

typedef struct usuario{
	char client[20];
	char end[20];
	char alugado[30];
	char data[30];
	char entrega[30];
	int codigo2 = 10;
} cliente;

void exibir_usuario(cliente *x);
void cadastrar(cliente *x, int code);
void exibir_usuarios(cliente *x);


int main(){
	
	int opcao, next, cod;
	int code, nextt;
	next=0;
	nextt=0;
	movie p[10];
	cliente x[10];
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
			case 5:
				if(nextt < 10){
					cadastrar(&x[nextt], nextt);
					nextt++;
				}
				else{
					printf("\n\nA quantidade de clientes foi excedida.\n\n");
					system("pause");
				}
			case 6:
				printf("\n\nInforme o código: ");
				scanf("%d", &code);
				exibir_usuario(&x[code]);
				break;
			case 7:
				exibir_usuarios(x);
				break;
				
				
				

		}
	} while(opcao != 8);
	
	return 0;
}

void exibir_menu(){
	system("cls");
	printf("---------------------Locadora SENAI---------------------\n\n");
	printf("    1 - Cadastrar filmes\n");
	printf("    2 - Exibir filme\n");
	printf("    3 - Exibir todos os filmes\n");
	printf("    4 - Excluir filme\n");
	printf("    5 - Cadastrar cliente \n");
	printf("    6 - Exibir cliente\n");
	printf("    7 - Exibir todos os clientes\n");
	printf("    8 - Sair\n");
		
	printf("Escolha uma opção: ");
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


void cadastrar(cliente *x, int code){
	system("cls");
	fflush(stdin);
	printf ("Informe o nome do cliente: ");
	gets (x->client);
	printf ("Informe o endereço do cliente: ");
	gets (x->end);
	printf("Filme alugado: ");
	gets (x->alugado);
	printf("Data de Aluguel: ");
	gets (x->data);
	printf("Data de Entrega: ");
	gets (x->entrega);
	
}
void exibir_usuario(cliente *x){
	system("cls");
	printf("Insira o código do cliente: %d", x->codigo2);
	system("cls");
	printf("Nome do cliente: \n");
	puts (x->client);	
	printf("\nEndereço do cliente: \n");
	puts (x->end);
	printf("\nFilme alugado: \n%s\n", x->alugado);
	printf("\nData de Aluguel: \n%s\n", x->data);
	printf("\nData de Entrega: \n%s\n", x->entrega);	
	system("pause");
}
void exibir_usuarios(cliente *x){
	system("cls");
	int j;	
	for(j=0; j < 10; j++){
		if (x[j].codigo2 < 10){
			exibir_usuario(&x[j]);
		}
	}
}

	

	








