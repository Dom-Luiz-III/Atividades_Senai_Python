#include <stdio.h>

main (){
	int a, b, maior, valor[10];
	
	for(a=0;a<10;a++){
		printf("Informe um valor: \n");
		scanf("%d", &valor[a]);
	}
	/*Nesse comando, a variável "maior" receberá o primeiro vetor, e ele será comparado com os outros para saber qual o maior número de fato.
	 Ele fará isso com outra variável, o "b", que ficará pulando a variável "valor" de 1 em 1 até dar 10, ajudando assim a comparar os outros números.*/
	maior = valor[0];
	for(b=1;b<10;b++){
		if(valor[b]>maior){
			maior=valor[b];
		}
	}
	printf("O maior valor eh: %d", maior);
	
	return 0;
};
