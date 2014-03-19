#define len 128
#include<stdio.h>
void read(FILE *fp);
void tokenize(char * st);
void tokenline(char * st);
void display();
void subString(int l,int k);
int k;
char s[len][len];
struct node
{
	char *store;
	struct node *down;
	struct node *left;
	struct node *right;
 
};
struct node * head;
void endins(char *s);
void disp();
int count;
int tempcount;
