#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

typedef struct node 
{
	int age;
	char name[50];
	struct node *next;
}NODEPTR;

NODEPTR *create_node()
{
	NODEPTR *p;
	p=(NODEPTR*)malloc(sizeof(struct node));
	return (p);
}

void freenode(NODEPTR *p)
{
	free(p);
}

void insertInOrder(NODEPTR * p, NODEPTR ** start)
{
	NODEPTR * old;
	NODEPTR * temp;

	old = NULL;
	temp = *start;
	while (temp != NULL)
	{
		if (strcmp(temp->name, p->name) < 0)
		{
			old = temp;
			temp = temp->next; // passa pro proximo
		}
		else
		{
			if (old != NULL) // se o anterior nao e nulo, devemos inserir no meio da lista
			{
				// insere no meio da lista 
				old->next = p;
				p->next = temp;
				return;
			}
			
			// insere no comeco da lista
			p->next = temp;
			*start = p;
			return;
		}
	}

	// insere no fim da lista
	old->next = p;
	p->next = NULL;
}

NODEPTR *push(NODEPTR **ft, int x, char *name)
{
	NODEPTR *q;
	if(*ft == NULL)
	{
		printf("INSERCAO NULA :c\n");
		exit(1);
	}

	q=create_node();
	q->age=x;
	strcpy(q->name,name);
	
	insertInOrder(q, ft);
}

void print_list(NODEPTR * start)
{
	NODEPTR * temp = start;
	while(temp != NULL)
	{
		printf("NOME: %sIDADE: %d\n", temp->name, temp->age);
		temp = temp->next;
	}
}

NODEPTR* pop(NODEPTR *p)
{
	NODEPTR *q;
	while(p->next!=NULL)
	{
		
		if(p->next->next==NULL)
		{	
			p->next=NULL;
//			free(p->next);
			return p;
			
		}
		p=p->next;
	}
//	q=p->next;
//	free(p);
//	return q;
}

int main()
{
	int age, i;
	char ch, name[50];
	NODEPTR *ft,*p,*last;
	p=create_node();
	printf("DIGITE A IDADE DO PRIMEIRO ALUNO DA LISTA\n>");
	scanf("%d", &age);
	fflush(stdin);
	p->age=age;
	printf("DIGITE O NOME DO PRIMEIRO ALUNO\n>");
	fgets(name,50,stdin);
	fflush(stdin);
	strcpy(p->name,name);
	p->next=NULL;
	ft=last=p;
	printf("DESEJA INSERIR OUTRO NO NO FINAL?\n>");
	ch=getch();
	printf("%c\n",ch);
	while(ch=='s'||ch=='S')
	{
		printf("DIGITE A IDADE DO PROXIMO ALUNO DA LISTA\n>");
		scanf("%d",&age);
		fflush(stdin);
		printf("DIGITE O NOME DO PROXIMO ALUNO DA LISTA\n>");
		fgets(name,50,stdin);
		fflush(stdin);
		push(&ft, age, name);
		printf("DESEJA INSERIR OUTRO NO NA LISTA?\n>");
		ch=getch();
		printf("%c\n",ch);
	}
	print_list(ft);
	printf("VOCE QUER REMOVER O ULTIMO DA LISTA?\n>");
	ch=getch();
	printf("%c\n",ch);
	while(ch=='s'||ch=='S')
	{
		pop(ft);
		print_list(ft);
		printf("DESEJA REMOVER DE NOVO?\n>");
		ch=getch();
		printf("%c\n",ch);
	}	
	print_list(ft);
}
