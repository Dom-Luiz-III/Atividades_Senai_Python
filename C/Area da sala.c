#include<stdio.h>
#include<locale.h>

main(){
	setlocale(LC_ALL, "portuguese");
	float cmp;
		printf("Informe o Comprimento: ");
		scanf("%f",cmp);
	float lrg;
		printf("%f",&lrg);
	printf("A área da sala é: %2fm",cmp*lrg);
}
