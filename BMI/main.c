#include"bmi.c"

int main(){
	float peso, altura;
	
	printf("Digite seu peso\n>");
	
	scanf("%f", &peso);
	
	printf("Digite sua altura\n>");
	
	scanf("%f", &altura);
	
	printf("%f", imc(peso, altura));
}
