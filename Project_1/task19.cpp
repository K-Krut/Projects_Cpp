/*
Хэш-функция, хорошо работающая с данными одного вида (например, короткими именами переменных), 
может оказаться неудачной в работе с другими (такими как URL-адреса), 
поэтому хэш-функцию для своей программы следует тестировать на типичных наборах входных данных. 
Хорошо ли она кодирует короткие строки? А длинные? А строки одинаковой длины с небольшими отличиями? 
Сгенерируйте поток данных для заполнения хэша и проверьте качество хэширования 
(длины цепочек) при MULTIPLIER от 31 до 37.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NHASH 127

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

void create(){
	lookup("a", 1, 1);
	lookup("a0", 1, 2);
	lookup("a000", 1, 3);
	lookup("a0000", 1, 4);
	lookup("a0000", 1, 5);
	lookup("a0000", 1, 6);
	lookup("a00000r", 1, 7);
}

void show() {
    Nameval *sym;
    for(int i = 0; i < NHASH; ++i){
        for (sym = symtab[i]; sym != NULL; sym = sym->next)
            printf("%s %d\n", sym->name, sym->value);
	}
}

int main(){

	create();
	show();
	
	return 0;
}

