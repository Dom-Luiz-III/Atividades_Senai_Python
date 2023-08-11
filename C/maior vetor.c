#include <stdio.h>
#include <locale.h>

main (){
	int a;
	int vet[10];
	
	setlocale(LC_ALL,"Portuguese");
	
	for(a=0;a<10;a++)
	{
	printf("Informe um valor: \n");
	scanf("%d", &vet[a],&vet);
	}
		
	if (vet[0]>vet[1]&&vet[2]&&vet[3]&&vet[4]&&vet[5]&&vet[6]&&vet[7]&&vet[8]&&vet[9])
		printf("\nO vetor com o maior valor tem %d",vet[0]);
	else
		if (vet[1]>vet[0]&&vet[2]&&vet[3]&&vet[4]&&vet[5]&&vet[6]&&vet[7]&&vet[8]&&vet[9])
			printf("\nO vetor com o maior valor tem %d",vet[1]);
		else
			if (vet[2]>vet[0]&&vet[1]&&vet[3]&&vet[4]&&vet[5]&&vet[6]&&vet[7]&&vet[8]&&vet[9])
				printf("\nO vetor com o maior valor tem %d",vet[2]);
			else
				if (vet[3]>vet[0]&&vet[1]&&vet[2]&&vet[4]&&vet[5]&&vet[6]&&vet[7]&&vet[8]&&vet[9])
					printf("\nO vetor com o maior valor tem %d",vet[3]);
				else
					if (vet[4]>vet[0]&&vet[1]&&vet[2]&&vet[3]&&vet[5]&&vet[6]&&vet[7]&&vet[8]&&vet[9])
						printf("\nO vetor com o maior valor tem %d",vet[4]);
					else 
						if (vet[5]>vet[0]&&vet[1]&&vet[2]&&vet[3]&&vet[4]&&vet[6]&&vet[7]&&vet[8]&&vet[9])
							printf("\nO vetor com o maior valor tem %d",vet[5]);
						else
							if (vet[6]>vet[0]&&vet[1]&&vet[2]&&vet[3]&&vet[4]&&vet[5]&&vet[7]&&vet[8]&&vet[9])
								printf("\nO vetor com o maior valor tem %d",vet[6]);
							else
								if (vet[7]>vet[0]&&vet[1]&&vet[2]&&vet[3]&&vet[4]&&vet[5]&&vet[6]&&vet[8]&&vet[9])
									printf("\nO vetor com o maior valor tem %d",vet[7]);
								else
									if (vet[8]>vet[0]&&vet[1]&&vet[2]&&vet[3]&&vet[4]&&vet[5]&&vet[6]&&vet[7]&&vet[9])
										printf("\nO vetor com o maior valor tem %d",vet[8]);
									else
										if (vet[9]>vet[0]&&vet[1]&&vet[2]&&vet[3]&&vet[4]&&vet[5]&&vet[6]&&vet[7]&&vet[8])
											printf("\nO vetor com o maior valor tem %d",vet[9]);
	return 0;
};
