#include <stdio.h>
#include"read.h"
#include<string.h>
#include<stdlib.h>
void read( FILE *file)
{
   static const char filename[] = "trial.mk";
   file = fopen ( filename, "r" );
   count=0;
   tempcount=1;
   if ( file != NULL )
   {
   	char line [ len ]; /* or other suitable maximum line size */
	while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
	{
		fputs ( line, stdout ); /* write the line on the output sreen*/
		printf("\n");
		if(line[0]=='\t')
		{
			endins(line);
		}
		else
		{
			count++;
			tokenize(line);/* calls the function which tokenizes the string into required parts*/
		}
	}
	fclose ( file );
   }
   else
   {
	   perror ( filename ); 
   }	
}
void tokenize(char * line)
{
	char *result = NULL;
	char str[len][len];//double dimensional array to store the tokenized strings.
	int i=0,n=0;
	result = strtok( line, ":" );
	while( result != NULL ) 
	{
	   //tokenizes the string based on the ':' operator.
	    strcpy(str[i],result);
	    i++;//keeps a count of the number of tokenized parts
	    result = strtok( NULL, ":" );
	}
	for(n=0;n<i;n++)
	{
		tokenline(str[n]); // each of the tokenized part is further tokenized based on words.
	}
}
void tokenline(char * line)
{
	int l=k;//stores the starting count.
	int i;
	char *result = NULL;
	result = strtok( line, " " );
	while( result != NULL ) 
	{
	    strcpy(s[k],result);// copies the tokenized strings into a double dimensional array.
	    k++;
	    result = strtok( NULL, " " );
	}
	subString(l,k);//calls the substring function which removes new line character.
}	
void subString(int l,int k)  //this function is used to remove the newline character. 
{
    	int i;
    	char *temp=NULL;
	int j;
	for(i=l;i<k;i++)
	{
		char *string=s[i];
		j=0;
		while(string[j]!='\n'&&(string[j]!='\0'))
		{
			j++;
		}
		temp=strndup(string+0,j);
		printf("\t %s\n",temp);
		
		if(temp[0]!='\0')
		endins(temp);
	}

}
void endins(char *s)
{
	struct node *newnode;
	char s2[len];
	strcpy(s2,s);
	newnode=malloc(sizeof(struct node));
        newnode->down = newnode->right =  newnode->left = 0;
	newnode->store=malloc(sizeof(s2));
	strcpy(newnode->store,s);
	
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	else
	{
		if(tempcount==count)
		{
			struct node *temp=head;
			while(temp->down!=NULL)// to travel the list downwards
			{
				temp=temp->down;
			}
		

			if(newnode->store[0]=='\t')// in case it is a command to be executed, then it will get stored on the left side of the 							   //respective node. i. e in case client has a command gcc -c main.c io.c, this statement 							   //will be inserted to the left node of client 
			{
				
				while(temp->left!=NULL)
				{
					temp=temp->left;
				}
				temp->left=newnode;
			}
			else
			{
				if((newnode->store[0]!=' ')||(newnode->store[0]!='\n')||(newnode->store[0]!='\t'))
				{
					while(temp->right!=NULL)// to store the dependencies on the right side of the node.
					{
						temp=temp->right;
					}	
					temp->right=newnode;
				}
			}
		}
		else if((count-1)==tempcount)
		{
			tempcount=count;
			struct node *temp=head;
			while(temp->down!=NULL)
			{
				temp=temp->down;
			}
			temp->down=newnode;				
		}
		
	}

}
void disp()
{
	
	struct node *temp;
	
	
	struct node *temp2;
	
	
	temp=head;
	temp2=head;
   	while(temp!=NULL)	
	{
		
		printf("\tleft %s",temp->store);// prints the left side of the node.
		temp2=temp->left;
		
		while(temp2!=NULL)
		{
				printf("\tleft %s",temp2->store);
				temp2=temp2->left;
				
		}	
		
		temp=temp->down;
		temp2=temp;
	
	}
	temp=head;
	temp2=head;
	
	 while(temp!=NULL)// prints the right side.
	 {                 
	 	while(temp2!=NULL)
		{
			printf("right : %s\t",temp2->store);
			temp2=temp2->right;
                }
                printf("\n");
                temp=temp->down;
                temp2=temp;
         }
}

