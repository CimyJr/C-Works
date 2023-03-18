#include<stdio.h>
#include<math.h>


float imc(float peso, float altura){
	float imc = peso/pow(altura, 2.0);
	return imc;
}
