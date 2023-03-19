#include"bmi.c"

int main(){
	
	float peso, altura, resultado;
	
	printf("Digite seu peso\n>");
	
	scanf("%f", &peso);
	
	printf("Digite sua altura\n>");
	
	scanf("%f", &altura);
	
	resultado = imc(peso, altura);
		
	if(resultado<=18.5)
		printf("Seu resultado e %.2f voce esta abaixo do peso", resultado);
	
	else if((resultado>=18.6) && (resultado<=24.9))
		printf("Seu resultado e %.2f voce esta saudavel", resultado);
		
	else if((resultado>=25.0) && (resultado<=29.9))
		printf("Seu resultado e %.2f voce esta acima do peso", resultado);
		
	else if((resultado>=30.0) && (resultado<=34.9))
		printf("Seu resultado e %.2f voce esta na obesidade 1", resultado);
	
	
}
