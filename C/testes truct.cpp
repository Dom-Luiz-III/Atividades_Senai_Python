#include <stdio.h>

typedef struct relogio{
	int hora;
	int minuto;
	int segundo;
}relo;

int main(){
	relo ag;
	
	ag.hora = 23;
	ag.minuto = 17;
	ag.segundo = 33;
	
	printf("%d:%d:%d",ag.hora,ag.minuto,ag.segundo);
}
