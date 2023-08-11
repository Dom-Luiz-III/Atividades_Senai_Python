#include <stdio.h>


main(){
	char senha[100],resposta[12];
	strcpy(resposta,"abracadabra");

	do{	
		printf("Por favor, solicite uma senha: \n");
		scanf("%s", &senha);
		
		if (strcmp(senha,resposta)==0)
				printf("Senha correta!");
		else
				printf("Senha incorreta!\n\n");
	}while (strcmp(senha,resposta)!=0);
	return 0;
} 
