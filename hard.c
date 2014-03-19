#include<stdlib.h>
#include<stdio.h>
void print(void);
truct datast
{
        char *info;
//      char info[50];
        struct datast *right;
        struct datast *down;
};
struct datast *root=NULL;
struct datast *temproot=NULL;
void create()
{
	int i;
	//char *x;
	char x[50];
	struct datast *q=malloc(sizeof(struct datast));
	printf("Enter root info\n");
	scanf("%s",x);
	q->info=x;
	q->right=0;
	q->down=0;
	root=q;
	print();
	struct datast *temp=root;
	struct datast *tempdwn=root;
	int j;

	        for(i=0;i<2;i++)
                {
                    if(temp!=root)
		    {
		        printf("ENter new info\n");
                        scanf("%s",x);  
                        struct datast  *p=malloc(sizeof(struct datast));
                        p->info=x;
                        p->down=0;
                        p->right=0;
                        temp->right=p;
                        temp=temp->right;
			print();
		    }
                }
                printf("\n finished inner for loop");

	for(j=0;j<2;j++)
	{
		  printf("Enter root info\n");
	       	scanf("%s",x);
       		 q->info=x;
	        q->right=0;
        	q->down=0;
        	//temproot=q;
		tempdwn->down=q;
		tempdwn=tempdwn->down;
		temp=tempdwn;
		print();
		for(i=0;i<2;i++)
		{
			printf("ENter new info\n");
			scanf("%s",x);	
			struct datast *p=malloc(sizeof(struct datast));
			p->info=x;
			p->down=0;
			p->right=0;
			temp->right=p;
			temp=temp->right;
			print();
		}
		printf("\n finished inner for loop");
		//tempdwn=tempdwn->down;
		//temp=tempdwn;
	}
}
void print()
{
	struct datast *temp=root;
	struct datast *tempdwn=root;
	int i=1;
	printf("The root is %s \n",root->info);
//	while(tempdwn!=NULL)
	{
		printf("For %d th row\n",i);
		while(temp!=NULL)
		{
			printf("%s ",temp->info);
			temp=temp->right;
		}
		tempdwn=tempdwn->down;
		temp=tempdwn;
		i++;
	}
}
void main()
{
	create();
	print();
}
