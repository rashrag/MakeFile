#include "treeform.h"

struct treest* parent;
int compile;
char* postorder(struct treest *, struct treest*, int);
char*largest;
void setTime(struct treest*);
struct treest* createNode(char*);
void createTree();
void execute(char *);
int checkRight(struct treest*, int);
void toCall();
