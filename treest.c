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
		
		struct treest *q=malloc(sizeof(struct treest));
		int length=strlen(nodetemp->store);
		q->info=malloc(length+1);
		 strncpy(q->info,nodetemp->store,length+1);
                  q->right=NULL;
                  q->left=NULL;

		if(treeroot==NULL)
		{
			treeroot=q;
			temproot=treeroot;
			
		}
		else
		{
			temproot->right=q;
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
	struct node *nodetemp=nodetrav;
	int fcase=1;
	struct treest *treeleft=treetrav;
	while(nodetemp!=NULL)
	{

		 struct treest *p=malloc(sizeof(struct treest));
 
		int length=strlen(nodetemp->store);
      		 p->info=malloc(length+1);
	         strncpy(p->info,nodetemp->store,length+1);
       		 p->right=NULL;
       		 p->left=NULL;
		 struct node *presentif=findPos(p);
		if(presentif!=NULL)	
		{
		        	treeleft=expandifPresent(treeleft,presentif,fcase);
				fcase=0;
	       	}
		else

		{
			if(fcase)
			{	
				treeleft->left=p;
				fcase=0;
			        treeleft=p;
				
		
			}
			else
			{
		
				
				 if(treeleft->left==NULL)
                         	 {
                             		 treeleft->left=p; 
				
                         	 }
                               

				else if(treeleft->right==NULL)
				{
					treeleft->right=p;
					 
				}
				else
				{
					treeleft=treeleft->left;
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
	        
        struct node *nodetemp=downpos->right;
   
        struct treest *treeleft=treeexpand;
        while(nodetemp!=NULL)
        {

                 struct treest *p=malloc(sizeof(struct treest));

                int length=strlen(nodetemp->store);
                 p->info=malloc(length+1);
                 strncpy(p->info,nodetemp->store,length+1);
                 p->right=NULL;
                 p->left=NULL;  
			 if(fcase)
                        {
                                treeleft->left=p;
                                fcase=0;
                               treeleft=p;
                        }
                        else

			{
                               
                                 if(treeleft->left==NULL)
                                 {
                                         treeleft->left=p;

                                 }


                                else if(treeleft->right==NULL)
                                {
                                        treeleft->right=p;
				 }
                                else
                                {
                                        treeleft=treeleft->left;
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
void printCommand()
{
	struct treest *temp=treeroot;
	struct treest *temp2=temp;
	while(temp!=NULL)
	{
		if(temp->command!=NULL)
		{
			temp2=temp->command;
			printf("Node is %s \n",temp->info);
			while(temp2!=NULL)
			{
				printf("command is %s \n",temp2->info);
				temp2=temp2->command;
	
			}
		}
			temp=temp->right;
	}
}
void addCommand()
{
	
	struct treest *treetrav=treeroot;
	struct node *nodetemp=head;
	while(nodetemp!=NULL &&  treetrav!=NULL)
	{
		// struct treest *p=malloc(sizeof(struct treest));
		// p->left = p->right = p->command = NULL;
		 struct node *comm=nodetemp;
		 struct treest *temp=treetrav;
		printf("came to before entering inside  while\n");
         	while(comm->left!=NULL)	
		{
			int length=strlen(comm->left->store);
        	       
		 struct treest *p=malloc(sizeof(struct treest));
                 p->left = p->right = p->command = NULL;
                 p->info=malloc(length+1);
        	         strncpy(p->info,comm->left->store,length+1);
			 printf("node is %s before any change \n",temp->info);
			 temp->command=p;
			// printf("Seond time node is %s to its command is %s\n",temp->info,temp->command->info);
			 temp=temp->command;
			// printf("comm left store is %s\n",comm->left->store);
			 printf("new node is %s\n",temp->info);
			 comm=comm->left;
			// printf("comm left store is %s\n",comm->left->store);

		}	
		
			treetrav=treetrav->right;
			nodetemp=nodetemp->down;
		
	}
}
