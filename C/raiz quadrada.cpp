#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float calculo(float a, float b, float c){
    float delta;// res, x,x2;
    delta=b*b-4*a*c;

   
    return delta;
}
main (){
    float a,b,c, x,x2,y;
    do{
        printf("Informe o valor de 'A': ");
        scanf("%f", &a);
    }while(a==0);
    printf("Informe o valor de 'B': ");
    scanf("%f", &b);
    printf("Informe o valor de 'C': ");
    scanf("%f", &c);
    printf("\n\nO resultado.\n");

    //float calculo();
    //calculo(a,b,c);
    printf("DElta %f.\n", calculo(a,b,c));

}
