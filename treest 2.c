#include<stdio.h>
#include "treeform.h"
#include<string.h>
#include<stdlib.h>
struct treest *temptree=NULL;
struct node *tempdown=NULL;
struct node *templine=NULL;
void createRight()
{

	struct node *nodetemp=head;
	 struct treest *temproot=NULL;
	struct node *temp=NULL;
	while(nodetemp!=NULL)
	{
		printf("enterd while]\n");
		struct treest *q=malloc(sizeof(struct treest));
		int length=strlen(nodetemp->store);
		q->info=malloc(length);
		 strncpy(q->info,nodetemp->store,length);
                  q->right=NULL;
                  q->left=NULL;

		if(treeroot==NULL)
		{
			treeroot=q;
			temproot=treeroot;
			printf("Created root\n");
		}
		else
		{
			temproot->right=q;
			printf("on  pass root is %s and its right is     %s\n",temproot->info,temproot->right->info);
		}
		temp=nodetemp->right;
		if(temp!=NULL)

		{	
			struct treest *wcr=createDependent(q,nodetemp->right);
			temp=temp->right;
		}
		temproot=q;
		nodetemp=nodetemp->down;
	}
}
struct treest *createDependent(struct treest *treetrav,struct node *nodetrav)
{
	printf("entered dependent funtion\n");
	struct node *nodetemp=nodetrav;
//	struct treest *p=malloc(sizeof(struct treest));
	int fcase=1;
	struct treest *treeleft=treetrav;
	while(nodetemp!=NULL)
	{

		 struct treest *p=malloc(sizeof(struct treest));
 
		int length=strlen(nodetemp->store);
		printf("length is %d string is %s\n",length,nodetemp->store);
      		 p->info=malloc(length);
	         strncpy(p->info,nodetemp->store,length);
       		 p->right=NULL;
       		 p->left=NULL;
		 struct node *presentif=findPos(p);
		if(presentif!=NULL)	
		{
				printf("node present is %s \n",presentif->store);
		        	treeleft=expandifPresent(treeleft,presentif,fcase);
				fcase=0;
	       	}
		else

		{
			if(fcase)
			{	
				treeleft->left=p;
				fcase=0;
				printf("in facse inserted to the left.info is %s\n",treeleft->left->info);
				treeleft=p;
				   printf("treeleft in fcase is now %s\n",treeleft->info);
		
			}
			else
			{
		
				printf("common else treeleft is now %s\n",treeleft->info);
				 if(treeleft->left==NULL)
                         	 {
                             		 treeleft->left=p;
					   printf(" inserted to the left.info is %s\n",treeleft->left->info);
				
                         	 }
                               

				else if(treeleft->right==NULL)
				{
					printf("came here\n");
					treeleft->right=p;
					   printf(" inserted to the right.info is %s\n",treeleft->right->info);

				}
				else
				{
					printf("in last else\n");
					  printf("treeleft is now %s\n",treeleft->info);

					treeleft=treeleft->left;
					   printf(" inserted to the left.info is %s\n",treeleft->left->info);

					treeleft->left=p;

				}
			}
	        }	
	   	 nodetemp=nodetemp->right;
	}
	return treeleft;
}
struct node *findPos(struct treest *q)
{
	struct node *nodetemp=head;
	while(nodetemp!=NULL)
	{
		if(strcmp(nodetemp->store,q->info)==0)
		return nodetemp;
		nodetemp=nodetemp->down;
	}
	return NULL;
}
struct treest *expandifPresent(struct treest *treeexpand,struct node *downpos,int fcase)
{
	        printf("entered expand  funtion\n");
        struct node *nodetemp=downpos->right;
   
        struct treest *treeleft=treeexpand;
        while(nodetemp!=NULL)
        {

                 struct treest *p=malloc(sizeof(struct treest));

                int length=strlen(nodetemp->store);
                printf("expand lengt  is %d string is %s\n",length,nodetemp->store);
                 p->info=malloc(length);
                 strncpy(p->info,nodetemp->store,length);
                 p->right=NULL;
                 p->left=NULL;  
			 if(fcase)
                        {
                                treeleft->left=p;
                                fcase=0;
                                printf("in facse inserted to the left.info is %s\n",treeleft->left->info);
                               treeleft=p;
                                   printf("treeleft in fcase is now %s\n",treeleft->info);

                        }
                        else

			{
                                printf("expand common else treeleft is now %s\n",treeleft->info);
                                 if(treeleft->left==NULL)
                                 {
                                         treeleft->left=p;
                                           printf("expand  inserted to the left.info is %s\n",treeleft->left->info);

                                 }


                                else if(treeleft->right==NULL)
                                {
                                        printf("expand came here\n");
                                        treeleft->right=p;
                                           printf(" expand inserted to the right.info is %s\n",treeleft->right->info);
				 }
                                else
                                {
                                        printf("expand in last else\n");
                                          printf("expand treeleft is now %s\n",treeleft->info);

                                        treeleft=treeleft->left;
                                           printf(" expand inserted to the left.info is %s\n",treeleft->info);

                                        treeleft->left=p;

                                }
                      
                	}
                 nodetemp=nodetemp->right;
	}
      
        return treeleft;
}



	
void printTree()
{
	printf("**************************FINAL RESULT***************\n");
	struct treest *temp=treeroot;
	struct treest *temp2=treeroot;
	while(temp!=NULL)
	{
		printf("\ninfo is %s \n",temp->info);
		temp2=temp->left;
		printf("To its left is\n");
		printLeft(temp2);
		temp=temp->right;
	}
}

void printLeft(struct treest *root)
{
	 if(root!=NULL)
        {
               printLeft(root->left);
               printLeft(root->right);
                printf("%s ",root->info);
        }
}

