#include "read.h"
struct treest
{
        char *info;
        struct treest *right;
        struct treest *left;
	struct treest *command;
};
struct treest *treeroot;
struct treest *createDependent(struct treest *,struct node *);
struct node *findPos(struct treest *);
void printLeft(struct treest *root);
void printTree();
void addCommand();
struct treest *expandifPresent(struct treest *treeexpand,struct node *downpos,int fpos);
