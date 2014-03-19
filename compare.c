#include<stdlib.h>
#include<stdio.h>
#include<utime.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include "tree.h"
#include<time.h>
void setTime(struct treest* timetemp)
{
        struct stat sb;
	struct utimbuf ubuf;
	if(timetemp!=NULL)
	{
		ubuf.modtime = 1000; //set final time to check against init

		utime(timetemp->info, &ubuf);
		setTime(timetemp->left);
		setTime(timetemp->right);
		stat(timetemp->info, &sb);
	}
}

	
char* postorder(struct treest * timetemp, struct treest* par, int flag)
{

	struct stat order;
	time_t final;
	int i;
	if(timetemp!=NULL && flag == 1)
	{	
		
		stat(timetemp->info, &order);
		final = order.st_mtime;

		if(final != 1000)
		{
			largest = par->info;
			flag = 0;
		}
		if(flag == 1)
		{
			postorder(timetemp->left, par, flag);
			postorder(timetemp->right, par, flag);
		}
	}
	return largest;
}

int checkLeft(struct treest * temp, int flag)
{
	struct stat order;
	time_t final;
	int i;
	if(temp!=NULL && flag == 1)
	{
		stat(temp->info, &order);
		final = order.st_mtime;
		if(final != 1000)
		{
			flag = 0;
			compile = 1;
		}
		if(flag == 1)
		{
			checkLeft(temp->left, flag);
			checkLeft(temp->right, flag);
		}
	}
	return compile;
}
void toCall()
{
	struct stat sb1;
	int count = 1;
	char* updated = NULL;
	struct treest* timetemp;
	timetemp = NULL;

	parent = malloc(sizeof(struct treest));
	parent->right = NULL;
	parent->left = NULL;
	timetemp = treeroot->right;
	char array[100];
	printf("\n \n");
	printf("Files to be recompiled are:\n");
	while(timetemp!=NULL)
	{
		largest = "";
		strcpy(array, timetemp->info);	
		parent->info = array;
		updated = postorder(timetemp->left, parent, 1);
		printf("%s\n",updated);
		if(strcmp(updated, "")!=0)
		{
			execute(parent->info);
		}
		/*if(strcmp(updated, timetemp->info)==0)
		{
			count = 0;
		}*/
                timetemp = timetemp->right;
	}
	largest = "";
	timetemp = treeroot;
	compile = 0;
	/*if(count == 0)
	{
		execute(treeroot->info);
		printf("%s\n", treeroot->info);
	}*/
	int check = checkLeft(treeroot->left, 1);
	if(check == 1)
	{
		printf("%s\n", treeroot->info);
		execute(treeroot->info);
	}
	
	setTime(treeroot);
}

void execute(char* pattern)
{
	struct treest *temp=treeroot;
	while(temp!=NULL)
	{
		struct treest *comm=temp->command;
		if(strcmp(temp->info, pattern)==0)
		{
			while(comm!=NULL)
			{
				printf("%s\n",comm->info);
				system(comm->info);
				comm = comm->command;
			}
		}
		temp = temp->right;
	}
}
	


