#include<stdio.h>
#include "treeform.h"
#include<string.h>
#include<stdlib.h>
void disp(void);
void main()
{

	struct node *p;
	 struct node *q;
	struct node *r;
	p=malloc(sizeof(struct node));
	head=p;
	p->store=malloc(50);
	strcpy(p->store,"top");
	p->down=NULL;
	r=p;
	r->right=malloc(sizeof(struct node));
	r->right=NULL;
	r->down=NULL;

	strcpy(r->store,"nametop.o");
	r->right=malloc(sizeof(struct node));
        r->right->right=NULL;
        r->down=NULL;
        strcpy(r->store,"top.o");
	r->right=malloc(sizeof(struct node));
        r->right=NULL;
        r->down=NULL;
        strcpy(r->store,"my.o");
	printf("Created top\n");
	disp();	
        q=malloc(sizeof(struct node));
	q->store=malloc(50);
        strcpy(q->store,"nametop.o");
        q->down=NULL;
        q->right=NULL;
	p->down=q;
	 p=malloc(sizeof(struct node));
        p->store=malloc(50);
        strcpy(p->store,"nametop.c");
        p->down=NULL;
         r=p;
        r->right=malloc(sizeof(struct node));
        r->right=NULL;
        r->down=NULL;
        strcpy(r->store,"nametop.h");
        r->right=malloc(sizeof(struct node));
        r->right=NULL;
        r->down=NULL;
        strcpy(r->store,"my.h");
        r->right=malloc(sizeof(struct node));
        r->right=NULL;
        r->down=NULL;
        strcpy(r->store,"ot.o");

	q->down=p;
        q->store=malloc(50);
        strcpy(q->store,"my.o");
        q->down=NULL;
         r=q;
        r->right=malloc(sizeof(struct node));
        r->right=NULL;
        r->down=NULL;
        strcpy(r->store,"my.c");
        r->right=malloc(sizeof(struct node));
        r->right=NULL;
        r->down=NULL;
        strcpy(r->store,"my.h");
        

        p->down=q;
	 p=malloc(sizeof(struct node));
        p->store=malloc(50);
        strcpy(p->store,"ot.o");
        p->down=NULL;
         r=p;
        r->right=malloc(sizeof(struct node));
        r->right=NULL;
        r->down=NULL;
        strcpy(r->store,"ot.c");
        r->right=malloc(sizeof(struct node));
        r->right=NULL;
        r->down=NULL;
        strcpy(r->store,"ot.h");
        q->down=p;
	printf("Before display\n");
	disp();
	
}
void disp()
{
	struct node *temp=head;
	struct node *temp2=head;
	printf("enterd display\n");
	printf("heas is %s\n",head->store);
	while(temp!=NULL)
	{
		while(temp2!=NULL)
		{
			printf("%s\t",temp2->store);
			temp2=temp2->right;
		}
		printf("\n");
		temp=temp->down;
		temp2=temp;
	}
}

