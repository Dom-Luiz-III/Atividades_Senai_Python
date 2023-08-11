/*
	Locadora GeeksBR

	Esse é um programa que implementa uma locadora de filmes.
	Possui algumas funções, as atualizações de arquivos são feitas no momento
	que são alterados os dados.

	Os ID's dos filmes e dos clientes são gerados automaticamente.

	O código está todo comentado.

	Dúvidas? www.GeeksBR.com
*/
 
// testa se o sistema é Windows, pois o "cls" funciona somente no Windows,
// senão utiliza o "clear" que é o comando para limpar a tela no Linux
#ifdef __WIN32
#define limpar_tela "cls"
#else
#define limpar_tela "clear"
#endif
 
// inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// quantidade máxima de letras no nome do cliente e nome do filme
#define MAX 100
 
// definição da struct filme
typedef struct filme
{
	// campos da struct filme
	int id;
	int id_cliente;
	char nome[MAX];
	float preco;
} t_filme;
 
 
// definição da struct cliente
typedef struct cliente
{
	// campos da struct cliente
	int id;
	char nome[MAX];
} t_cliente;
 
 
// protótipos de funções
 
/**
 * Exibe o menu com todas as opções do programa
 * retorno: um caractere do número correspondente a opção
 */
char menu();
 
/**
 * Cadastro um cliente pedindo apenas o nome
 */
void cadastrar_cliente();
 
/**
 * Cadastra um filme com nome e preço
 */
void cadastrar_filme();
 
/**
 * Mostra todos os filmes cadastrados e as informações de aluguel
 */
void listar_filmes();
 
/**
 * Exibe todos os clientes cadastrados
 */
void listar_clientes();
 
/**
 * Procura um filme pelo id do filme
 *
 * Parâmetros:
 *   arq_filmes: ponteiro para um arquivo aberto
 *   id_filme: ID do filme que será buscado
 * retorno: um ponteiro para o filme encontrado ou NULL caso o ID não exista
 */
t_filme *obter_filme(FILE *arq_filmes, int id_filme);
 
/**
 * Procura um cliente pelo seu id
 *
 * Parâmetros:
 *   arq_clientes: ponteiro para um arquivo aberto
 *   id_cliente: ID do cliente que será buscado
 * retorno: um ponteiro para o cliente encontrado ou NULL caso o ID não exista
 */
t_cliente *obter_cliente(FILE *arq_clientes, int id_cliente);
 
/**
 * Pesquisa um filme e exibe suas informações
 */
void pesquisar_filme();
 
/**
 * Pesquisa um cliente e exibe suas informações
 */
void pesquisar_cliente();
 
/**
 * Procura um filme pelo seu id e informa se ele foi encontrado
 *
 * Parâmetros:
 *   arq_filmes: ponteiro para um arquivo aberto
 *   id_filme: ID do filme que será buscado
 * retorno: 1 para filme encontrado ou 0 caso o ID não exista
 */
int existe_filme(FILE *arq_filmes, int id_filme);
 
/**
 * Procura um cliente pelo seu id e informa se ele foi encontrado
 *
 * Parâmetros:
 *   arq_clientes: ponteiro para um arquivo aberto
 *   id_cliente: ID do cliente que será buscado
 * retorno: 1 se o cliente existe ou 0 caso o ID não exista
 */
int existe_cliente(FILE *arq_clientes, int id_cliente);
 
/**
 * Atualiza as informações do filme no arquivo
 *
 * Parâmetros:
 *   arq_filmes: ponteiro para um arquivo aberto
 *   filme_alugado: ponteiro para o filme que será atualizado
 */
void atualizar_filmes(FILE *arq_filmes, t_filme *filme_alugado);
 
/**
 * Aluga um filme e atualiza o arquivo
 */
void alugar_filme();
 
/**
 * Recebe um filme de um cliente e atualiza as informações no arquivo
 */
void entregar_filme();
 
/**
 * Exclui um filme do arquivo
 */
void excluir_filme();
 
/**
 * Informa se a string é um número
 *
 * Parâmetros:
 *   str: ponteiro para uma cadeia de caracteres
 * retorno: 1 se a string só conter números ou 0 caso contrário
 */
int str_somente_numeros(char str[]);
 
 
int main(int argc, char *argv[])
{
	char resp;
 
	// loop infinito do programa
	while(1)
	{
		// obtém a escolha do usuário
		resp = menu();
 
		// testa o valor de "resp"
		if(resp == '1')
			cadastrar_filme();
		else if(resp == '2')
			cadastrar_cliente();
		else if(resp == '3')
			listar_filmes();
		else if(resp == '4')
			listar_clientes();
		else if(resp == '5')
			pesquisar_filme();
		else if(resp == '6')
			pesquisar_cliente();
		else if(resp == '7')
			alugar_filme();
		else if(resp == '8')
			entregar_filme();
		else if(resp == '9')
			excluir_filme();
		else if(resp == '0') // se for igual a 0, então sai do loop while
			break;
		else
		{
			printf("\nOpcao invalida! Pressione <Enter> para continuar...");
			scanf("%*c");
			// uma forma de "limpar" o buffer de entrada
			fseek(stdin, 0, SEEK_END); // não recomendável o uso
		}
		system(limpar_tela);
	}
 
	printf("\nBye! Visite: www.GeeksBR.com ;-)\n");
	return 0;
}
 
 
// função que exibe o menu e retorna a opção escolhida pelo usuário
char menu()
{
	char resp[2];
 
	printf("------------------------------ Locadora GeeksBR ------------------------------");
	printf("\n\n1 - Cadastrar um filme\n");
	printf("2 - Cadastrar um cliente\n");
	printf("3 - Listar todos os filmes\n");
	printf("4 - Listar todos os clientes\n");
	printf("5 - Pesquisar por filme\n");
	printf("6 - Pesquisar por cliente\n");
	printf("7 - Alugar um filme\n");
	printf("8 - Entregar um filme\n");
	printf("9 - Excluir um filme\n");
	printf("0 - Sair\n");
	printf("Digite o numero da opcao: ");
	scanf("%1s%*c", resp); // o *c pega o Enter e descarta
 
	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
 
	// se chegou aqui, é porque a opção é válida
	return resp[0];
}
 
 
// função que verifica se uma string contém somente números
int str_somente_numeros(char str[])
{
	int i = 0;
	int len_str = strlen(str);
 
	for(i = 0; i < len_str; i++)
	{
		if(str[i] < '0' || str[i] > '9')
			return 0;
	}
	return 1;
}
 
 
// função para cadastrar cliente
void cadastrar_cliente()
{
	// abre o arquivo para escrita
	// a+b => acrescenta dados ao final do arquivo ou cria
	// um arquivo binária para leitura e escrita
	FILE *arq_clientes = fopen("clientes.bin", "a+b");
 
	// testa a abertura do arquivo
	if(arq_clientes == NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");
		exit(1); // aborta o programa
	}
	/*
		NÃO é interessante que o usuário digite o ID do cliente, esse
		ID tem que ser gerado automático, então temos que pegar o
		ID do último usuário cadastrado
	*/
	int cont_bytes = 0;
 
	// cont irá guardar o número total de bytes
	// seta o ponteiro do arquivo para o final do arquivo
	fseek(arq_clientes, 0, SEEK_END);
	// pegamos a quantidade de bytes com a função ftell
	cont_bytes = ftell(arq_clientes);
 
	t_cliente cliente;
 
	if(cont_bytes == 0)
	{
		// se for 0, então não existe cliente cadastrado
		// coloco o ID começando de 1
		cliente.id = 1;
	}
	else
	{
		t_cliente ultimo_cliente;
 
		// utilizo a função fseek para posicionar o arquivo
		// cont_bytes - sizeof(t_cliente) serve para posicionar
		// para que possamos pegar o último cliente cadastrado
		fseek(arq_clientes, cont_bytes - sizeof(t_cliente), SEEK_SET);
 
		// ler o cliente
		fread(&ultimo_cliente, sizeof(t_cliente), 1, arq_clientes);
 
		// o ID do cliente é o ID do último cliente acrescido em 1
		cliente.id = ultimo_cliente.id + 1;
	}
	// obtém o nome do filme
	// ^\n indica para pegar até a quebra de linha (enter)
	// %*c descarta o enter
	printf("\nDigite o nome do cliente: ");
	scanf("%99[^\n]%*c", cliente.nome);
 
	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
 
	// se o ponteiro não estiver no final do arquivo nada é escrito
	fseek(arq_clientes, 0, SEEK_END);
	// escreve no arquivo
	fwrite(&cliente, sizeof(t_cliente), 1, arq_clientes);
 
	// fecha o arquivo
	fclose(arq_clientes);
 
	printf("\nCliente \"%s\" cadastrado com sucesso!\n", cliente.nome);
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c"); // pega o Enter e descarta
 
	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
}
 
 
// função para cadastrar filme
void cadastrar_filme()
{
	// abre o arquivo para escrita
	// a+b => acrescenta dados ao final do arquivo ou cria
	// um arquivo binária para leitura e escrita
	FILE *arq_filmes = fopen("filmes.bin", "a+b");
 
	// testa a abertura do arquivo
	if(arq_filmes == NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");
		exit(1); // aborta o programa
	}
	t_filme filme;
 
	/*
		NÃO é interessante que o usuário digite o ID do filme, esse
		ID tem que ser gerado automático, então temos que pegar o
		ID do último filme cadastrado
	*/
	int cont_bytes = 0;
 
	// seta o ponteiro do arquivo para o final do arquivo
	fseek(arq_filmes, 0, SEEK_END);
	// cont irá guardar o número total de bytes
	cont_bytes = ftell(arq_filmes);
 
	if(cont_bytes == 0)
	{
		// se for 0, então não existe filme cadastrado
		// coloco o ID começando de 1
		filme.id = 1;
	}
	else
	{
		t_filme ultimo_filme;
 
		// utilizo a função fseek para posicionar o arquivo
		// cont_bytes - sizeof(t_cliente) serve para posicionar
		// para que possamos pegar o último filme cadastrado
		fseek(arq_filmes, cont_bytes - sizeof(t_filme), SEEK_SET);
 
		// ler o filme
		fread(&ultimo_filme, sizeof(t_filme), 1, arq_filmes);
 
		// o ID do filme é o ID do último filme acrescido em 1
		filme.id = ultimo_filme.id + 1;
	}
	// obtém o nome do filme
	// ^\n indica para pegar até a quebra de linha (enter)
	// %*c descarta o enter
	printf("\nDigite o nome do filme: ");
	scanf("%99[^\n]%*c", filme.nome);
 
	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
 
	do
	{
		char str_preco[5];
		float float_preco;
		int somente_numeros = 1;
 
		// obtém o preço do filme
		printf("Digite o preco do filme: ");
		scanf("%4s%*c", str_preco);
 
		fseek(stdin, 0, SEEK_END); // não recomendável o uso
 
		// verifica se o preço possui somente números
		somente_numeros = str_somente_numeros(str_preco);
		// verifica se o preço contém somente números
		if(somente_numeros == 1)
		{
			// se chegou aqui, é porque tudo está validado
			// preencho a variável float_preco com o valor de str_preco
			int int_preco;
			// exemplo: 49,50 deve digitar 4950
			sscanf(str_preco, "%d", &int_preco);
			float_preco = int_preco / 100.0;
			filme.preco = float_preco;
			break;
		}
	}
	while(1);
 
	// inicializa o id_cliente com -1 indicando que o filme NÃO está alugado
	filme.id_cliente = -1;
 
	// se o ponteiro não estiver no final do arquivo nada é escrito
	fseek(arq_filmes, 0, SEEK_END);
	// escreve no arquivo
	fwrite(&filme, sizeof(t_filme), 1, arq_filmes);
 
	// fecha o arquivo
	fclose(arq_filmes);
 
	printf("\nFilme \"%s\" cadastrado com sucesso!\n", filme.nome);
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c"); // pega o Enter e descarta
 
	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
}
 
 
// função para listar todos os clientes
void listar_clientes()
{
	// rb => abre arquivo binário para leitura apenas
	FILE *arq_clientes = fopen("clientes.bin", "rb");
 
	// testa a abertura do arquivo
	if(arq_clientes == NULL)
	{
		printf("\nFalha ao abrir arquivo(s) ou ");
		printf("Nenhum cliente cadastrado.\n");
		printf("\nPressione <Enter> para continuar...");
		scanf("%*c"); // pega o Enter e descarta
 
		// uma forma de "limpar" o buffer de entrada
		fseek(stdin, 0, SEEK_END); // não recomendável o uso
		return;
	}
 
	// variável que indica se encontrou pelo menos 1 cliente
	int encontrou_clientes = 0;
	t_cliente cliente;
 
	printf("\nListando todos os clientes...\n");
	// loop para percorrer o arquivo
	while(1)
	{
		// fread retorna o número de elementos lidos com sucesso
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);
 
		// se for 0, é porque não há mais elemento, então sai do loop
		if(result == 0)
			break;
 
		// atualiza a variável indicando que encontrou
		// pelo menos um cliente
		encontrou_clientes = 1;
 
		// mostra os dados do cliente
		printf("\nID do cliente: %d\n", cliente.id);
		printf("Nome do cliente: %s\n", cliente.nome);
	}
 
	if(encontrou_clientes == 0)
		printf("\nNenhum cliente cadastrado.\n");
 
	fclose(arq_clientes);
 
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");
 
	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
}
 
 
// função que obtém um cliente pelo ID
t_cliente *obter_cliente(FILE *arq_clientes, int id_cliente)
{
	// vai para o início do arquivo
	rewind(arq_clientes);
 
	t_cliente *cliente;
 
	// loop para percorrer o arquivo
	// busca linear O(n), como o ID é crescente é possível fazer uma busca binária O(log(n))
	// aloca espaço mesmo sem saber se o cliente existe
	cliente = (t_cliente *)malloc(sizeof(t_cliente));
	while(1)
	{
 
		// fread retorna o número de elementos lidos com sucesso
		size_t result = fread(cliente, sizeof(t_cliente), 1, arq_clientes);
 
		// se for 0, é porque não há mais elemento, então sai do loop
		if(result == 0)
		{
			free(cliente); // libera a mémoria, pois o cliente não foi encontrado
			return NULL;
		}
		// verifica se os ID's são iguais
		if(cliente->id == id_cliente)
			break;
	}
	return cliente;
}
 
 
// função para listar todos os filmes
void listar_filmes()
{
	// lista de todos os filmes
 
	// rb => abre para leitura somente, ponteiro para o início do arquivo
	FILE *arq_filmes = fopen("filmes.bin", "rb");
	FILE *arq_clientes = fopen("clientes.bin", "rb");
 
	// se o arquivo de filmes não existe
	if(arq_filmes == NULL)
	{
		printf("\nFalha ao abrir arquivo ou ");
		printf("Nenhum filme cadastrado.\n");
		printf("\nPressione <Enter> para continuar...");
		scanf("%*c"); // pega o Enter e descarta
 
		// uma forma de "limpar" o buffer de entrada
		fseek(stdin, 0, SEEK_END); // não recomendável o uso
		return;
	}
	// variável que indica se encontrou pelo menos 1 filme
	int encontrou_filmes = 0;
	printf("\nListando todos os filmes...\n");
	// loop para percorrer o arquivo
	t_filme filme;
	while(1)
	{
		// fread retorna o número de elementos lidos com sucesso
		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);
 
		// se for 0, é porque não há mais elemento, então sai do loop
		if(result == 0)
			break;
 
		// atualiza a variável indicando que encontrou
		// pelo menos um filme
		encontrou_filmes = 1;
 
		// mostra os dados do filme
		printf("\nID do filme: %d\n", filme.id);
		printf("Nome do filme: %s\n", filme.nome);
		printf("Preco: %.2f\n", filme.preco);
 
		// se id_cliente for diferente de -1, então o filme está alugado, pois
		// possui algum id válido do cliente que alugou o filme.
		// se id_cliente for igual a -1, indica que o filme não está alugado,
		// pois o id -1 NÃO é um id válido
		if(filme.id_cliente != -1)
		{
			// se o arquivo de clientes não existir, atenção esse teste
			// não pode ser realizado no início da função, pois pode acontecer de
			// todos os filmes não estarem alugados
			if(arq_clientes == NULL)
			{
				printf("\nFalha ao abrir arquivo!\n");
				fclose(arq_filmes); // libera recursos
				exit(1); // aborta o programa
			}
			t_cliente *cliente = obter_cliente(arq_clientes, filme.id_cliente);
			printf("Alugado? Sim. Cliente: %s\n", cliente->nome);
			free(cliente); // evita vazamento de memória
		}
		else
			printf("Alugado? Nao\n");
	}
 
	// verifica se encontrou pelo menos um filme
	if(encontrou_filmes == 0)
		printf("\nNenhum filme cadastrado.\n");
 
	// fecha os arquivos em ordem inversa que foram abertos
	if(arq_clientes != NULL)
		fclose(arq_clientes); // apenas se foi aberto
	fclose(arq_filmes);
 
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");
 
	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
}
 
 
// função para pesquisar por algum filme
void pesquisar_filme()
{
	char nome[MAX];
	int encontrou_filme = 0;
 
	// rb => abre para leitura somente
	FILE *arq_filmes = fopen("filmes.bin", "rb");
	FILE *arq_clientes = fopen("clientes.bin", "rb");
 
	// testa a abertura do arquivo
	if(arq_filmes == NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");
		exit(1); // aborta o programa
	}
 
	printf("\nDigite o nome do filme: ");
	scanf("%99[^\n]%*c", nome);
 
	printf("\nFilmes com o nome \"%s\":\n\n", nome);
	// loop para percorrer o arquivo
	// busca linear, pois o campo nome não possui índice
	t_filme filme;
	while(1)
	{
		// fread retorna o número de elementos lidos com sucesso
		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);
 
		// se for 0, é porque não há mais elemento, então sai do loop
		if(result == 0)
			break;
 
		char nome_aux[MAX];
		// faz uma cópia para não alterar filme.nome
		strcpy(nome_aux, filme.nome);
 
		// verifica se é igual
		if(strcmp(strupr(nome_aux), strupr(nome)) == 0)
		{
			// mostra os dados do filme
			printf("ID do filme: %d\n", filme.id);
			printf("Preco: %.2lf\n", filme.preco);
			if(filme.id_cliente != -1)
			{
				// se o arquivo de clientes não existir
				if(arq_clientes == NULL)
				{
					printf("\nFalha ao abrir arquivo!\n");
					fclose(arq_filmes); // libera recursos
					exit(1); // aborta o programa
				}
				t_cliente *cliente = obter_cliente(arq_clientes, filme.id_cliente);
				printf("Alugado? Sim. Cliente: %s\n", cliente->nome);
				free(cliente); // evita vazamento de memória
			}
			else
				printf("Alugado? Nao\n");
			encontrou_filme = 1;
			printf("\n");
		}
	}
 
	if(encontrou_filme == 0)
		printf("Nenhum filme encontrado.\n\n");
 
	fclose(arq_filmes);
 
	printf("Pressione <Enter> para continuar...");
	scanf("%*c");
 
	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
}
 
 
// função para pesquisar por algum cliente
void pesquisar_cliente()
{
	char nome[MAX];
	int encontrou_cliente = 0;
 
	// rb+ => abre para leitura somente
	FILE *arq_clientes = fopen("clientes.bin", "rb");
 
	// testa a abertura do arquivo
	if(arq_clientes == NULL)
	{
		printf("\nFalha ao abrir arquivo(s)!\n");
		exit(1); // aborta o programa
	}
 
	printf("\nDigite o nome do cliente: ");
	scanf("%99[^\n]%*c", nome);
 
	printf("\nClientes com o nome \"%s\":\n\n", nome);
	// loop para percorrer o arquivo
	t_cliente cliente;
	while(1)
	{
		// fread retorna o número de elementos lidos com sucesso
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);
 
		// se for 0, é porque não há mais elemento, então sai do loop
		if(result == 0)
			break;
 
		char nome_aux[MAX];
		// faz uma cópia para não alterar cliente->nome
		strcpy(nome_aux, cliente.nome);
 
		// verifica se é igual
		if(strcmp(strupr(nome_aux), strupr(nome)) == 0)
		{
			// mostra os dados do cliente
			printf("ID do cliente: %d\n\n", cliente.id);
			encontrou_cliente = 1;
		}
	}
 
	if(encontrou_cliente == 0)
		printf("Nenhum cliente encontrado.\n\n");
 
	// fecha o arquivo
	fclose(arq_clientes);
 
	printf("Pressione <Enter> para continuar...");
	scanf("%*c");
 
	// uma forma de "limpar" o buffer de entrada
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
}
 
 
// função que verifica se um filme existe
// retorna 0 se NÃO existe e 1 caso contrário
int existe_filme(FILE *arq_filmes, int id_filme)
{
	// vai para o início do arquivo, pois não sabemos a posição do ponteiro no arquivo
	rewind(arq_filmes);
 
	t_filme filme;
	// loop para percorrer o arquivo
	// busca linear O(n), como o ID é crescente é possível fazer uma busca binária O(log(n))
	while(1)
	{
 
		// fread retorna o número de elementos lidos com sucesso
		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);
 
		// se for 0, é porque não há mais elemento, então sai do loop
		if(result == 0)
			break;
 
		// verifica se o ID é igual
		if(filme.id == id_filme)
			return 1;
	}
 
	// se chegou aqui é porque NÃO existe o filme, então retorna 0
	return 0;
}
 
 
// função que verifica se um cliente existe
// retorna 0 se NÃO existe e 1 caso contrário
int existe_cliente(FILE *arq_clientes, int id_cliente)
{
	// vai para o início do arquivo
	rewind(arq_clientes);
 
	t_cliente cliente;
	// loop para percorrer o arquivo
	// busca linear O(n), como o ID é crescente é possível fazer uma busca binária O(log(n))
	while(1)
	{
		// fread retorna o número de elementos lidos com sucesso
		size_t result = fread(&cliente, sizeof(t_cliente), 1, arq_clientes);
 
		// se for 0, é porque não há mais elemento, então sai do loop
		if(result == 0)
			break;
 
		// verifica se o ID é igual
		if(cliente.id == id_cliente)
			return 1;
	}
 
	// se chegou aqui é porque NÃO existe o cliente, então retorna 0
	return 0;
}
 
 
// função que obtém um filme pelo ID
t_filme *obter_filme(FILE *arq_filmes, int id_filme)
{
	// vai para o início do arquivo
	rewind(arq_filmes);
 
	// loop para percorrer o arquivo
	// busca linear O(n), como o ID é crescente é possível fazer uma busca binária O(log(n))
	t_filme *filme;
 
	// aloca espaço mesmo sem saber se o filme existe
	filme = (t_filme *)malloc(sizeof(t_filme));
	while(1)
	{
 
		// fread retorna o número de elementos lidos com sucesso
		size_t result = fread(filme, sizeof(t_filme), 1, arq_filmes);
 
		// se for 0, é porque não há mais elemento, então sai do loop
		if(result == 0)
			break;
 
		// verifica se os ID's são iguais
		if(filme->id == id_filme)
			return filme;
	}
	free(filme); // libera recursos
	return NULL;
}
 
 
// função para atualizar um filme
// recebe o ponteiro para o arquivo e o filme
void atualizar_filmes(FILE *arq_filmes, t_filme *filme_alugado)
{
	// vai para o início do arquivo
	rewind(arq_filmes);
 
	t_filme filme;
	while(1) // loop para percorrer o arquivo
	{
 
		// fread retorna o número de elementos lidos com sucesso
		size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);
 
		// se for 0, é porque não há mais elemento, então sai do loop
		if(result == 0)
			break;
 
		// verifica se os ID's são iguais
		if(filme.id == filme_alugado->id)
		{
			// fseek posiciona o arquivo
			fseek(arq_filmes, - sizeof(t_filme), SEEK_CUR);
			// atualiza o filme
			fwrite(filme_alugado, sizeof(t_filme), 1, arq_filmes);
			break; // sai do loop
		}
	}
}
 
 
// função responsável pelo aluguel dos filmes
void alugar_filme()
{
	char str_id_cliente[10];
	int id_cliente;
 
	// rb+ abre para leitura/atualização
	FILE *arq_filmes = fopen("filmes.bin", "rb+");
	FILE *arq_clientes = fopen("clientes.bin", "rb+");
 
	// se não conseguiu abrir, então cria o arquivo
	// wb+ abre para escrita/atualização (cria o arquivo se ele NÃO existir)
	if(arq_filmes == NULL)
	{
		arq_filmes = fopen("filmes.bin", "wb+");
		if(arq_filmes == NULL)
		{
			printf("\nFalha ao criar arquivo(s)!\n");
			exit(1); // aborta o programa
		}
	}
 
	if(arq_clientes == NULL)
	{
		arq_clientes = fopen("clientes.bin", "wb+");
		if(arq_clientes == NULL)
		{
			printf("\nFalha ao criar arquivo(s)!\n");
			exit(1); // aborta o programa
		}
	}
 
	// obtém o ID do cliente
	printf("\nDigite o ID do cliente: ");
	scanf("%10s%*c", str_id_cliente);
 
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
 
	if(str_somente_numeros(str_id_cliente) == 1)
	{
		// se caiu aqui é porque o ID possui somente números, então
		// preenche a variável "id_cliente" com o valor de "str_id_cliente"
		sscanf(str_id_cliente, "%d", &id_cliente);
 
		// verifica se o ID do do cliente existe
		if(existe_cliente(arq_clientes, id_cliente))
		{
			char str_id_filme[10];
			int id_filme;
 
			printf("\nDigite o ID do filme: ");
			scanf("%10s%*c", str_id_filme);
 
			fseek(stdin, 0, SEEK_END); // não recomendável o uso
 
			if(str_somente_numeros(str_id_filme) == 1)
			{
				// se chegou aqui é porque o ID do filme é válido
				sscanf(str_id_filme, "%d", &id_filme);
 
				// obtém o filme pelo ID
				t_filme *filme = obter_filme(arq_filmes, id_filme);
 
				// testa se o filme existe...
				if(filme != NULL)
				{
					// se chegou aqui é porque o filme existe
					// testa se o filme já está alugado
					if(filme->id_cliente != -1)
						printf("\nO filme \"%s\" ja esta alugado!\n", filme->nome);
					else
					{
						// se o filme NÃO está alugado, então seta o
						// id_cliente do filme para associar o cliente
						// ao aluguel do filme em questão
						filme->id_cliente = id_cliente;
						atualizar_filmes(arq_filmes, filme); // atualiza o filme no arquivo
						printf("\nFilme \"%s\" alugado com sucesso!\n", filme->nome);
					}
					free(filme); // libera o filme alocado
				}
				else
					printf("\nNao existe filme com o ID \"%d\".\n", id_filme);
			}
			else
				printf("\nO ID so pode conter numeros!\n");
		}
		else
			printf("\nNao existe cliente com o ID \"%d\".\n", id_cliente);
	}
	else
		printf("\nO ID so pode conter numeros!\n");
 
	// fecha os arquivos
	fclose(arq_clientes);
	fclose(arq_filmes);
 
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");
 
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
}
 
 
// função responsável pela entrega dos filmes
void entregar_filme()
{
	char str_id_filme[10];
	int id_filme;
 
	// rb+ abre para leitura/atualização
	FILE *arq_filmes = fopen("filmes.bin", "rb+");
 
	// se não conseguiu abrir, então cria o arquivo
	// wb+ abre para escrita/atualização (cria o arquivo se ele NÃO existir)
	if(arq_filmes == NULL)
	{
		arq_filmes = fopen("filmes.bin", "wb+");
		if(arq_filmes == NULL)
		{
			printf("\nFalha ao criar arquivo(s)!\n");
			exit(1); // aborta o programa
		}
	}
 
	printf("\nDigite o ID do filme: ");
	scanf("%10s%*c", str_id_filme);
 
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
 
	if(str_somente_numeros(str_id_filme) == 1)
	{
		// se chegou aqui é porque o ID do filme é válido
		sscanf(str_id_filme, "%d", &id_filme);
 
		// obtém o filme pelo ID
		t_filme *filme = obter_filme(arq_filmes, id_filme);
 
		// testa se o filme existe...
		if(filme != NULL)
		{
			// se chegou aqui é porque o filme existe
			// testa se o filme já foi entregue
			if(filme->id_cliente == -1)
				printf("\nO filme \"%s\" ja esta disponivel!\n", filme->nome);
			else
			{
				// se o filme NÃO foi entregue, então seta o
				// id_cliente para -1 para indicar que ele foi entregue
				filme->id_cliente = -1;
				atualizar_filmes(arq_filmes, filme); // atualiza o filme no arquivo
				printf("\nFilme \"%s\" entregue com sucesso!\n", filme->nome);
			}
			free(filme); // libera memória
		}
		else
			printf("\nNao existe filme com o ID \"%d\".\n", id_filme);
	}
	else
		printf("\nO ID so pode conter numeros!\n");
 
	// fecha o arquivo
	fclose(arq_filmes);
 
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");
 
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
}
 
 
// função responsável por excluir filmes
void excluir_filme()
{
	char str_id_filme[10];
	int id_filme;
 
	printf("\nDigite o ID do filme: ");
	scanf("%10s%*c", str_id_filme);
 
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
 
	// verifica se str_id_filme só contém números
	if(str_somente_numeros(str_id_filme) == 1)
	{
		// se chegou aqui é porque o ID do filme é válido
		sscanf(str_id_filme, "%d", &id_filme);
 
		// rb abre para leitura (o arquivo deve existir)
		FILE *arq_filmes = fopen("filmes.bin", "rb");
 
		if(arq_filmes == NULL)
		{
			printf("\nFalha ao abrir arquivo(s)!\n");
			exit(1); // aborta o programa
		}
 
		// verifica se o filme existe
		if(existe_filme(arq_filmes, id_filme) == 1)
		{
			char nome_filme[MAX];
			// abre um novo arquivo temporário
			FILE *arq_temp = fopen("temp_filmes.bin", "a+b");
			if(arq_temp == NULL)
			{
				printf("\nFalha ao criar arquivo temporario!\n");
				fclose(arq_filmes);
				exit(1); // aborta o programa
			}
			rewind(arq_filmes); // vai para o início do arquivo
 
			t_filme filme;
			while(1) // loop para percorrer o arquivo
			{
 
				// fread retorna o número de elementos lidos com sucesso
				size_t result = fread(&filme, sizeof(t_filme), 1, arq_filmes);
 
				// se for 0, é porque não há mais elemento, então sai do loop
				if(result == 0)
					break;
 
				// só copia pro novo arquivo se for diferente
				if(filme.id != id_filme)
				{
					// escreve no arquivo temporário
					fwrite(&filme, sizeof(t_filme), 1, arq_temp);
				}
				else
					strcpy(nome_filme, filme.nome);
			}
 
			// antes de fazer operações de remover arquivo e renomear,
			// é preciso fechar os dois arquivos
			fclose(arq_filmes);
			fclose(arq_temp);
 
			// depois de fechar o arquivo, então tentamos remover
			if(remove("filmes.bin") != 0)
				printf("\nErro ao deletar o arquivo \"filmes.bin\"\n");
			else
			{
				// renomeia o arquivo
				int r = rename("temp_filmes.bin", "filmes.bin");
				if(r != 0)
				{
					printf("\nPermissao negada para renomear o arquivo!\n");
					printf("Feche esse programa bem como o arquivo \"temp_filmes.bin\" e renomeie manualmente para \"filmes.bin\"\n");
				}
				else
					printf("\nFilme \"%s\" removido com sucesso!\n", nome_filme);
			}
		}
		else
		{
			fclose(arq_filmes);
			printf("\nNao existe filme com o ID \"%d\".\n", id_filme);
		}
	}
	else
		printf("\nO ID so pode conter numeros!\n");
 
	printf("\nPressione <Enter> para continuar...");
	scanf("%*c");
	fseek(stdin, 0, SEEK_END); // não recomendável o uso
}