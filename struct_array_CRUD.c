#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define cnst 2000

typedef struct product
{
    int id;
    char name[50];
    int stock;
    int pastsales;
    float salesprice;
    float buyprice;
} Product;

Product product[cnst], sort;

int main()
{
    int index = 0, iaux = 0;
    char cnslt[50];
    char num[] = "zzzzzzzzzzzzz";
    int len, i, j, cnslt_id;
    FILE *fp;

    fp = fopen("database.bin", "rb+");
    if (fp == NULL)
    {
        fp = fopen("database.bin", "wb+");
        if (fp == NULL)
        {
            printf("NAO FOI POSSIVEL ABRIR/CRIAR O ARQUIVO :(\n");
            return 1;
        }
    }
    else
    {
        fread(&iaux, sizeof(iaux), 1, fp);
        fread(&len, sizeof(len), 1, fp);
        if (iaux == 0)
        {
            fclose(fp);
            //return 1;
        }
        else
        {
            for (i = 0; i < len; i++)
            {
                fread(&product[i].id, sizeof(product[i].id), 1, fp);
                fread(product[i].name, sizeof(char), sizeof(product[i].name), fp);
                fread(&product[i].buyprice, sizeof(product[i].buyprice), 1, fp);
                fread(&product[i].pastsales, sizeof(product[i].pastsales), 1, fp);
                fread(&product[i].salesprice, sizeof(product[i].salesprice), 1, fp);
                fread(&product[i].stock, sizeof(product[i].stock), 1, fp);
            }
            fclose(fp);
        }
    }

    int option = 0;
    while (option != 5)
    {
        printf("=========SUPERMERCADO=========\n1. LISTAR.\n2. CONSULTAR.\n3. INSERIR.\n4. DELETAR.\n5. SALVAR E SAIR.\n\n ESCOLHA\n>");
        scanf("%d", &option);
        fflush(stdin);

        switch (option)
        {
        case 1:
            system("cls");
            printf("=========LISTA=========\n");
            if (iaux == 0)
            {
                printf("NAO HA PRODUTOS NA LISTA\n");
            }
            else
            {
                len = iaux;
                for (index = 0; index < len; index++)
                {
                    printf("ID: %d |NOME: %s\n", product[index].id, product[index].name);
                }
            }
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            printf("=========CONSULTAR=========\n");
            i = 0, cnslt_id = -1;
            if (iaux == 0)
            {
                printf("NAO HA PRODUTOS A SEREM CONSULTADOS\n");
            }
            else
            {
                len = iaux;
                printf("DIGITE O NOME DO PRODUTO\n>");
                fflush(stdin);
                fgets(cnslt, sizeof(cnslt), stdin);
                fflush(stdin);

                for (i = 0; i < len; i++)
                {
                    if (strcmp(product[i].name, cnslt) == 0)
                    {
                        cnslt_id = i;
                    }
                }
                if (cnslt_id != -1)
                {
                    printf("ID: %d\nNOME: %s\nPRECO DE VENDA: R$ %.2f\nPRECO DE COMPRA: R$ %.2f\nQUANTIDADE NO ESTOQUE: %d\nQUANTIDADE VENDIDA NO MES PASSADO: %d\n", product[cnslt_id].id, product[cnslt_id].name, product[cnslt_id].salesprice, product[cnslt_id].buyprice, product[cnslt_id].stock, product[cnslt_id].pastsales);
                    printf("LUCRO: R$%.2f\nSUGESTAO DE COMPRA: %d\n", ((product[cnslt_id].pastsales * product[cnslt_id].salesprice) - (product[cnslt_id].pastsales * product[cnslt_id].buyprice)), (product[cnslt_id].pastsales + 10));
                }
                else
                {
                    printf("PRODUTO NAO ENCONTRADO :c\n");
                }
            }
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            iaux++;
            product[index].id = iaux;
            printf("=========INSERIR=========\n");
            printf("DIGITE O NOME DO PRODUTO\n>");
            fflush(stdin);
            fgets(product[index].name, sizeof(product[index].name), stdin);
            fflush(stdin);
            printf("DIGITE O PRECO DE VENDA DO PRODUTO EM REAIS\n>");
            scanf("%f", &product[index].salesprice);
            fflush(stdin);
            printf("DIGITE O PRECO DE COMPRA DO PRODUTO EM REAIS\n>");
            scanf("%f", &product[index].buyprice);
            fflush(stdin);
            printf("DIGITE A QUANTIDADE NO ESTOQUE\n>");
            scanf("%d", &product[index].stock);
            fflush(stdin);
            printf("DIGITE A QUANTIDADE VENDIDA NO MES PASSADO\n>");
            scanf("%d", &product[index].pastsales);
            fflush(stdin);
            strcpy(product[iaux].name, num);
            index++;
            system("cls");
            len = iaux;
            for (i = 0; i <= len; i++)
            {
                for (j = i + 1; j <= len; j++)
                {
                    if (strcmp(product[i].name, product[j].name) > 0)
                    {
                        strcpy(sort.name, product[i].name);
                        sort.buyprice = product[i].buyprice;
                        sort.pastsales = product[i].pastsales;
                        sort.salesprice = product[i].salesprice;
                        sort.stock = product[i].stock;
                        strcpy(product[i].name, product[j].name);
                        product[i].buyprice = product[j].buyprice;
                        product[i].pastsales = product[j].pastsales;
                        product[i].salesprice = product[j].salesprice;
                        product[i].stock = product[j].stock;
                        strcpy(product[j].name, sort.name);
                        product[j].buyprice = sort.buyprice;
                        product[j].pastsales = sort.pastsales;
                        product[j].salesprice = sort.salesprice;
                        product[j].stock = sort.stock;
                    }
                }
            }
            break;
        case 4:
            system("cls");
            printf("=========DELETAR=========\n");
            i = 0, cnslt_id = -1;
            if (iaux == 0)
            {
                printf("NAO HA PRODUTOS A SEREM DELETADOS\n");
            }
            else
            {
                len = iaux;
                printf("DIGITE O NOME DO PRODUTO\n>");
                fflush(stdin);
                fgets(cnslt, sizeof(cnslt), stdin);
                fflush(stdin);

                for (i = 0; i < len; i++)
                {
                    if (strcmp(product[i].name, cnslt) == 0)
                    {
                        cnslt_id = i;
                    }
                }
                if (cnslt_id != -1)
                {
                    for (cnslt_id; cnslt_id <= len; cnslt_id++)
                    {
                        int inextproduct = cnslt_id + 1;
                        strcpy(product[cnslt_id].name, product[inextproduct].name);
                        product[cnslt_id].buyprice = product[inextproduct].buyprice;
                        product[cnslt_id].pastsales = product[inextproduct].pastsales;
                        product[cnslt_id].salesprice = product[inextproduct].salesprice;
                        product[cnslt_id].stock = product[inextproduct].stock;
                    }
                    printf("PRODUTO DELETADO :D\n");
                    index--;
                    iaux--;
                }
                else
                {
                    printf("PRODUTO NAO ENCONTRADO :c\n");
                }
            }
            system("pause");
            system("cls");
            break;
        case 5:
	            fp = fopen("database.bin", "wb");
	            if (fp == NULL)
	            {
	                printf("NAO FOI POSSIVEL SALVAR ESSE ARQUIVO :(\n");
	            }
	            else
	            {
	                fwrite(&iaux, sizeof(iaux), 1, fp);
	                if (iaux > 0)
	                {
	                    len = iaux;
	                    fwrite(&len, sizeof(len), 1, fp);
	
	                    for (i = 0; i < len; i++)
	                    {
	                        fwrite(&product[i].id, sizeof(product[i].id), 1, fp);
	                        fwrite(product[i].name, sizeof(char), sizeof(product[i].name), fp);
	                        fwrite(&product[i].buyprice, sizeof(product[i].buyprice), 1, fp);
	                        fwrite(&product[i].pastsales, sizeof(product[i].pastsales), 1, fp);
	                        fwrite(&product[i].salesprice, sizeof(product[i].salesprice), 1, fp);
	                        fwrite(&product[i].stock, sizeof(product[i].stock), 1, fp);
	                    }
	                }
	                fclose(fp);
	                printf("DADOS SALVOS COM SUCESSO :D\n");
	            }
            printf("TCHAU :c\n");
            break;

        default:
            system("cls");
            printf("OPCAO INVALIDA XD\n");
            system("pause");
            system("cls");
            break;
        }
    }
}
