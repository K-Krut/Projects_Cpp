/*
Напишите рекурсивную и итерационную версии функции reverse_list, 
которая бы изменяла порядок следования элементов в списке на противоположный. 
Не создавайте новых элементов списка — используйте только существующие.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
	char *name;
	int value;
	Nameval *next;
};
	
Nameval *newitem(char *name, int value){

	Nameval *newp;
	newp = (Nameval *)malloc(sizeof(Nameval));
	newp->name = name;
	newp->value = value;
	newp->next = NULL;
	return newp;
}

Nameval *addfront(Nameval *listp, Nameval *newp){
	newp->next = listp;
	return newp;
}

Nameval *addend(Nameval *listp, Nameval *newp){
	Nameval *p;
	if (listp == NULL)
		return newp;
	for (p = listp; p->next != NULL; p = p->next);
		p->next = newp;
	return listp;
}

void show_list(struct Nameval *listp) { 
	struct Nameval *temp = listp; 
	while(temp != NULL) { 
		printf("%s %d\n", temp->name, temp->value);
		temp = temp->next; 
	} 
}	 

void reverse(struct Nameval** listp) { 
	struct Nameval* prev = NULL; 
	struct Nameval* current = *listp; 
	struct Nameval* next; 
	while (current != NULL) 
	{ 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	} 
	*listp = prev; 
} 

void recursiveReverse(struct Nameval **listp){ 
    struct Nameval* first; 
    struct Nameval* oters; 
       
    if (*listp == NULL) 
       return;    
  
    first = *listp;   
    oters  = first->next; 

    if (oters == NULL) 
       return;    
    recursiveReverse(&oters); 
    first->next->next  = first;   
    first->next  = NULL;           
    *listp = oters;               
}

int main(){

	Nameval *nvlist = NULL;
	int n = 0;
	
	nvlist = addfront(nvlist, newitem("data1", 10));
	nvlist = addend(nvlist, newitem("data2", 45));
	nvlist = addend(nvlist, newitem("data3", 40));

	show_list(nvlist);
	puts("\n\n");

	reverse(&nvlist);
	show_list(nvlist);
	puts("\n\n");
	recursiveReverse(&nvlist);

	show_list(nvlist);
	return 0;
}
