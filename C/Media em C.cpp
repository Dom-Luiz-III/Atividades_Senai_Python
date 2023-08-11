#include <stdio.h>

main () {
	float media;
	printf ("Informe a média: ");
	scanf ("%f", &media);
	
	if (media>=7){
			printf("Aprovado!");
	}
	else if(media>=5){
		printf("Recuperação!");
	}
	
	else{
		printf("Reprovado!");
	}
}
