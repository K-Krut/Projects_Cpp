/*
Напишите функцию для вывода всех элементов списка (см. Unit 1 "A singlylinked list"), 
которая перебирает его и последовательно выводит каждый элемент. 
Подсказка: Чтобы вычислить длину списка, можно написать функцию 
с простым перебором и инкрементированием счетчика.
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

void inccounter(Nameval *p, void *arg) {
	int *ip;
	ip = (int *)arg;
	(*ip)++;
}

void show_list(Nameval *listp) {
    Nameval *ptr = listp;
	
	for(int i = 0; ptr != NULL; ++i){
        printf("%s %d\n", ptr->name, ptr->value);
        ptr = ptr->next;
    }
}


int main(){

	Nameval *nvlist = NULL;
	int n = 0;
	
	nvlist = addfront(nvlist, newitem("data1", 10));
	
	Nameval *item = newitem("data2", 45);
	nvlist = addend(nvlist, item);
	
	show_list(nvlist);

	return 0;
}
