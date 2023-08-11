#include <stdio.h>
#include <locale.h>
#define ValorHora 19.50
#define IMPOSTO 0.25

int main() {

    setlocale(LC_ALL, "Portuguese");

float h,s,d;
printf("Por favor, informe suas horas de trabalho: ");
scanf("%f", &h);

s = h*ValorHora;

if(s >= 2500.00){
	d = IMPOSTO*s;
	printf("Desconto = R$ %.2f\n", d);
	s = s - d;
};
printf("Salário = R$ %.f\n", s);
}
