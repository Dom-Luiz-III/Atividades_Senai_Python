#include <stdio.h>
#include <locale.h>

main(){
	float nota,soma = 0;
	int c, alunos;
		
	setlocale(LC_ALL,"Portuguese");
	
	printf ("Informe quantas notas o aluno tem: ");
	scanf("%d", &alunos);
	
	for (c=1;c<=alunos;c++){
	printf("Informe a %d° nota do aluno: ",c);
		scanf("%f", &nota);
			soma += nota;
	};
	
	soma/=alunos;
	printf("A média foi:\n %.1f ", soma);
	
	return 0;
};
