#include <stdio.h>

int main(){
	char *p;
	char letra, letra2;
	
	p = &letra;
	letra = 'A';
	letra2 = 'B';
	
	printf("%c", *p);
	printf("\n\n");
	
	p = &letra2;
	*p = 'C';
	
	printf("%c", *p);
	printf("\n\n");
	printf("%d", p);
	
	return 0;
}
