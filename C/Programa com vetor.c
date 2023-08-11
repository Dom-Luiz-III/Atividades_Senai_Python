#include <stdio.h>
#include <locale.h>

main (){
	int a;
	int vet[5];
	
	setlocale(LC_ALL,"Portuguese");
	
	for(a=0;a<5;a++) /*Comando muito útil para adicionar todos os vetores*/
	{
	printf("Informe um valor: \n");
	scanf("%d", &vet[a]);
	}
	for(a=0;a<5;a++){
		printf("\nO valor do vetor na %d° posição é %d",a,vet[a]);
	}
	return 0;
};
