/*
Напишите функцию для обращения к последовательным элементам хэштаблицы в несортированном порядке.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NHASH 11

typedef struct Nameval Nameval;
typedef unsigned int ui;
typedef unsigned char uch;

struct Nameval {
	char *name;
	int value;
	Nameval *next;
};

Nameval *symtab[NHASH];

enum { MULTIPLIER = 31 };

ui hash(char *str){
	ui h = 0;
	for(uch *p = (uch *)str; *p != '\0'; ++p)
		h = MULTIPLIER*h + *p;
	return h % NHASH;
}

Nameval *lookup(char *name, int create, int value){
		Nameval *sym;
	int h = hash(name);
	for(sym = symtab[h]; sym != NULL; sym = sym->next)
		if(strcmp(name, sym->name) == 0)
			return sym;
	if(create){
		sym = (Nameval *)malloc(sizeof(Nameval));
		sym->name = name;
		sym->value = value;
		sym->next = symtab[h];
		symtab[h] = sym;
	}
	return sym;
}

void generate(){
	lookup("Billy", 1, 12);
	lookup("Alise", 1, 65);
	lookup("John", 1, 6);
	lookup("Endy", 1, 7);
	lookup("Rozie", 1, 2);
	lookup("Julia", 1, 3);
	lookup("Martin", 1, 74);
	lookup("Nick", 1, 0);
}

void show(){
		Nameval *sym;
	for(int i = 0; i < NHASH; ++i){
		for (sym = symtab[i]; sym != NULL; sym = sym->next)
		printf("%s %d\n", sym->name, sym->value);

	}
}

int main(){
	generate();
	show();

	Nameval *node = lookup("Billy", 1, 12);
	printf("\n\n%s %d\n", node->name, node->value);
	return 0;
}
