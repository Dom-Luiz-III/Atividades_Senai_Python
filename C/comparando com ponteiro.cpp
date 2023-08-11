#include <stdio.h>

int main(){
	char *p;
	char letra;
	
	letra = 'A';
	p = &letra;
	
	printf("%d", *p);
	printf("\n\n");
	printf("%d", p);
	
}
