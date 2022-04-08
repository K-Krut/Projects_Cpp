/*
Каким должен быть размер массива symtab (см. Unit 1 "Hash Table")?
Общая идея состоит в том, что массив symtab должен быть достаточно велик, 
чтобы цепочка каждого хэш-кода содержала поменьше элементов, 
и операция поиска имела характер 0(1). Свой ответ подкрепите примером кода.
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define mod 89

enum{ MULTIPLIER = 31 };

typedef struct List List; 
typedef unsigned char uch;
typedef unsigned int ui;


typedef struct List {
    int data;
    char *string;
    struct List *next;
} List;

List *symtab[mod];

ui hash(char *str){
    ui h = 0;
    uch *p;
    for(p = (uch*)str; *p != '\0'; p++) 
		h = MULTIPLIER * h + *p;
    return h % mod;
}

List *search(char *string, int create, int value){
    List *sym;
    int h = hash(string);
    for(sym = symtab[h]; sym != NULL; sym = sym->next)
        if(strcmp(string, sym->string) == 0)
			return sym;
    if(create) {
        sym = (List *)malloc(sizeof(List));
        sym->string = string;
        sym->data = value;
        sym->next = symtab[h];
        symtab[h] = sym;
    }
    return sym;
}

void free_list(List * list){
    List *temp;
    while(list){
        temp = list;
        list = list->next;
        free(temp->string);
        free(temp);
    }
}

void show() {
	List *sym;
	for (int i = 0; i < mod; ++i){
		for(sym = symtab[i]; sym != NULL; sym = sym->next)
			printf("%s %d\n", sym->string, sym->data);
	}
}
int main(){
    List *node;
	node = search("A", 1, 1);
	node = search("B", 1, 2);
	node = search("C", 1, 3);
	node = search("D", 1, 4);
	show();
	//free_list(node);
    return 0;
}


/*Для того, щоб функція розприділяла дані в таблиці рівномірно найкраще 
вибрати розмір масиву числом, яке мало б наймеше спільних дільників 
при будь якому можливому значенні h */


