/*
Сравните быстродействие функций lookup и nvlookup (см. Unit 1 "Binary search tree"). 
Какова разница между рекурсивной и итерационной формами
*/

#include<stdio.h>
#include <string.h>
#include <time.h> 

static clock_t clock_start;

typedef struct Nameval Nameval;

struct Nameval {
	char *name;
	int value;
	Nameval *left;
	Nameval *right;
};

void timer_start(){
	clock_start = clock();
}

double timer_elapsed(){
	return ((double) clock() - clock_start) / CLOCKS_PER_SEC;
}

Nameval *insert(Nameval *treep, Nameval *newp){
	if(treep == NULL)
		return newp;
	int cmp = strcmp(newp->name, treep->name);
	if(cmp == 0)
		printf("insert: dupcate entry %s ignored", newp->name);
	else if (cmp < 0)
		treep->left = insert(treep->left, newp);
	else
		treep->right = insert(treep->right, newp);
	return treep;

}

Nameval *lookup(Nameval *treep, char *name){
	if(treep == NULL)
		return NULL;
	int cmp = strcmp(name, treep->name);
	if(cmp == 0)
		return treep;
	else if(cmp < 0)
		return lookup(treep->left, name);
	else 
		return lookup(treep->right, name);
}

Nameval *nrlookup(Nameval *treep, char *name){
	while(treep != NULL){
		int cmp = strcmp(name, treep->name);
		if(cmp == 0)
			return treep;
		else if(cmp < 0)
			treep = treep->left;
		else
			treep = treep->right;
	}
	return NULL;
}


int main(){

	timer_start();
	Nameval *treep = NULL;

	struct Nameval newv = {.name = "Andy", .value = 12};
	printf("%s %d\n", newv.name, newv.value);
	treep = insert(treep, &newv);
	treep = insert(treep, &(struct Nameval){.name = "Billy", .value = 18});
		//printf("%g s\n", timer_start());

	Nameval *res = lookup(treep, "Billy");
	printf("%f s\n",timer_elapsed());
	printf("%s %d\n", res->name, res->value);
	timer_start();
	res = nrlookup(treep, "Andy");
	printf("%f s\n", timer_elapsed());
	printf("%s %d\n", res->name, res->value);
	printf("%f  s\n", timer_elapsed());
	return 0;
}

