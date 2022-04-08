/*
Напишите функцию coolfun, выполняющую перебор списка (см. Unit 1 "A singlylinked list") 
и вызывающую другую заданную функцию для каждого его элемента. 
Функцию coolfun сделать гибкой, включив в ее параметры аргумент для передачи в ту, 
другую функцию. Таким образом, coolfun будет принимать три аргумента: сам список; указатель на функцию, 
вызываемую для каждого элемента списка; аргумент для передачи в эту функцию. 

Прототип: void coolfun(Nameval *listp, void (*fn)(Nameval*, void*), void *arg).

Пример. Для подсчета элементов определяется функция с аргументом в виде 
указателя на целочисленный счетчик, который нужно инкрементировать:

inccounter: инкрементирует счетчик *arg 
void inccounter(Nameval *p, void *arg) {
int *ip;
p здесь не используется!
ip = (int *) arg;
(*ip)++;
}
Эта функция вызывается следующим образом:
int n = 0;
coolfun(nvlist, inccounter, &n);
printf("%d elements in nvlist\n", n);

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
	
Nameval *create_item(char *name, int value){
	Nameval *newp;
	
	newp = (Nameval *)malloc(sizeof(Nameval));
	newp->name = name;
	newp->value = value;
	newp->next = NULL;
	return newp;
}

Nameval *push_front(Nameval *listp, Nameval *newp){
	newp->next = listp;
	return newp;
}

Nameval *push_end(Nameval *listp, Nameval *newp){
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
    Nameval *p = listp;

    while (p != NULL) {
        printf("%s %d\n", p->name, p->value);
        p = p->next;
    }
}

void coolfun(Nameval *listp, void (*fn)(Nameval*, void*), void *arg){
	for ( ;listp != NULL; listp = listp->next)
		(*fn)(listp, arg);
}

int main(){

	Nameval *list = NULL;
	int n = 0;
	
	list = push_front(list, create_item("data1", 10));
	
	Nameval *item = create_item("data2", 45);
	list = push_end(list, item);
	
	show_list(list);

	coolfun(list, inccounter, &n);
	printf("%d elements in list\n", n);

	return 0;
}
