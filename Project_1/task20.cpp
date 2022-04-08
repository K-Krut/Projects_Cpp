/*
Хэш-функция (см. Unit 1 "Hash Table") имеет довольно общий характер и 
удобна при работе со строками. Однако с некоторыми исходными данными она 
может справляться недостаточно эффективно. Сконструируйте набор данных,
который бы заставил эту функцию работать плохо. 
Насколько трудно построить такой набор для различных значений NHASH?
*/


#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum { MULTIPLIER = 31, NHASH = 127, SIZE = 6};

typedef struct Nameval Nameval;
typedef unsigned int ui;
struct Nameval {
	char *name;
	int	value;
	Nameval	*next;
};

Nameval *symtab[NHASH];

ui hash_mod(char *str, ui nhash){
	ui h = 0;
	unsigned char *p;

	for (p = (unsigned char *) str; *p != '\0'; p++)
		h = MULTIPLIER * h + *p;

	return h % nhash;
}

ui hash(char *str) {
	return hash_mod(str, NHASH);
}

Nameval *lookup(char *name, int create, int value) {
	Nameval *sym;

		int h = hash(name);
	for (sym = symtab[h]; sym != NULL; sym = sym->next)
		if (strcmp(name, sym->name) == 0)
			return sym;
	if (create) {
		sym = (Nameval *) malloc(sizeof(Nameval));
		sym->name = name;
		sym->value = value;
		sym->next = symtab[h];
		symtab[h] = sym;
	}
	return sym;
}

static char *random_string(char *s, int len){
	int i;
	char c;

	for (i = 0; i < len; i++) {
		do {
			c = rand() % 128;
		} while (!isprint(c));
		s[i] = c;
	}
	s[i] = '\0';

	return s;
}

void create() {

	lookup("a", 1, 1);
	lookup("a0", 1, 2);
	lookup("a000", 1, 3);
	lookup("a0000", 1, 4);
	lookup("a0000", 1, 5);
	lookup("a0000", 1, 6);
	lookup("a00000r", 1, 7);
}

static void nhash_collisions() {

	char string[SIZE + 1];

		for (int i = 0; i < SIZE; ++i) {
			random_string(string, i);
			string[i] = 'a';
			string[i + 1] = '\0';
			printf("%s %u\n", string, hash_mod(string, MULTIPLIER));
		}
}
void show() {
    Nameval *sym;
    for(int i = 0; i < NHASH; ++i){
        for (sym = symtab[i]; sym != NULL; sym = sym->next)
            printf("%s %d    %d \n", sym->name, sym->value, i);
	}
}

int main() {

	srand(time(NULL));

	nhash_collisions();
	printf("\n");

	create();
	show();

	return 0;
}

