/*
Поскольку адрес массива может изменяться при перераспределении памяти, 
в основной части программы (в теле функции main()) следует обращаться к 
элементам по индексам, а не через указатели. Почему? 
Покажите пример обращения к элементам через указатели.
*/


#include <stdio.h>
#define SIZE 40

struct tag {
    char name[SIZE];
	int episodes;
    char duration[SIZE];
};

int main(){

   struct tag film = 
   {"The Queen's Gambit",7,"3 hours, 33 minutes"};

    struct tag *ptr;
    ptr = &film;

    printf("name: %s\nepisodes: %d\nduration %s",
	ptr->name, ptr->episodes,ptr->duration);

    return 0;
}

/*
функція realloc() - це функція, яка використовується тоді, коли
потрібно змінити розмір виділеної пам'яті (як на більший, так і наменьший).
Ця функція може використовувати як і раніше виділену ділянку пам'яті,
так і нову
*/
