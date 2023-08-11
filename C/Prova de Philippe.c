#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void exibir_menu(){
	system("cls");
	setlocale(LC_ALL,"Portuguese");
	printf("Menu\n\n1 - Domingo \n2 - Segunda \n3 - Terça \n4 - Quarta... \n");
}

float calcular_desconto(float valor, int diaSemana){
	if(diaSemana ==1) return valor;
	if (diaSemana %2== 0) return valor*0.85;
	else return valor*0.9;
}

bool verifica_numero(int numero){
	if (numero>= 1 && numero <=7) return true;
	else return false;
}

int main(){
	float venda;
	int dia;
	printf("Informe o valor da venda: ");
	scanf("%d", venda);
	exibir_menu();
	
	do{
		scanf ("%d". &dia);
	} while(!verifica_numero(dia));
	
	printf("O valor total é R$ %f", calcular_desconto(venda,dia));
	
	return 0
}
