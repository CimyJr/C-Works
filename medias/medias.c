#include <stdio.h>
#include<math.h>

float mediaGeometrica(float x, float y, float z){
    float r, p;
    r = x*y*z;
    p = pow(r, 1/3.0);
    return p;
}

float mediaPonderada(float x, float y, float z){
	float media = (x+2*y+3*z)/6;
	return media;
}