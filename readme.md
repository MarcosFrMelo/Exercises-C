#include <stdio.h>
int main(){
    int x;
    float valor;
    scanf("%d %f", &x, &valor);

    if(x < 13){
        valor += 5;
        printf("Valor: %f\n", valor);
    }else{
    	printf("Valor: %d\n", x);

        if(x > 15){
    	    valor += -5;
    	    printf("Valor: %f\n", valor);
        }else{

           printf("Valor: %d\n", x);

        }
    
	}

    return 0;
}