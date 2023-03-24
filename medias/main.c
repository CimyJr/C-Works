#include"medias.c"

main(){
    float x,y,z, m;
	int op;
	while(op!=3){
	
	printf("===========ESCOLHA UMA OPCAO=================\n");
	printf("1---------MEDIA GEOMETRICA\n");
	printf("2---------MEDIA PONDERADA\n");
	printf("3---------SAIR\n");
	printf("=============================================\n");
	scanf("%d",&op);

	switch(op){
	
	
	
	case 1:
	printf("Digite os tres valores\n>");
    scanf("%f %f %f", &x, &y, &z);

    m = mediaGeometrica(x,y,z);
    printf("%f\n", m);
    break;
    
    case 2:
    
	printf("Digite os tres valores\n>");
    scanf("%f %f %f", &x, &y, &z);	
    
    m = mediaPonderada(x,y,z);
    printf("%f\n", m);
	
	case 3:
	printf("TCHAU :D\n");
	break;
	}
}
}