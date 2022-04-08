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




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval {
  char *name;
  int value;
} Nameval;

struct Array {
  int nval;
  int max;
  Nameval *items;
};

enum { NVINIT = 1, NVGROW = 2 };

  int add_item(struct Array *array, Nameval newname){  
    Nameval *temp;
     if (array->items == NULL) {
      array->items = (Nameval *)malloc(NVINIT * sizeof(Nameval));
      if(array->items == NULL)
        return -1;
      array->max = NVINIT;
      array->nval = 0;
    }
    else if (array->nval >= array->max) {
      temp = (Nameval *) realloc(array->items, 
        (NVGROW * array->max) * sizeof(Nameval));
      if (temp == NULL)
        return -1;
      array->max *= NVGROW;
      array->items = temp;
    }
    array->items[array->nval] = newname;
    return ++array->nval;
  }

  int del_item(struct Array *array, char *name) {
    for (int i = 0; i<array->nval; ++i){
      if (strcmp(array->items[i].name, name) == 0){
        memmove(array->items + i, array->items + i + 1, (array->nval - (i + 1)) * sizeof(Nameval));
        --array->nval;
        return 1;
      }
    }
    return 0;  
  }

int main() {
  struct Array array = { 0, 0, NULL }; //Initializing fields of a structure
  add_item(&array, (struct Nameval) {.name = "Andy", .value = 12});
  add_item(&array, (struct Nameval){.name = "Billy", .value = 16});
  add_item(&array, (struct Nameval){.name = "Tom", .value= 25});
  add_item(&array, (struct Nameval){.name = "Alice", .value= 25});

  for (int i = 0; i < array.nval; ++i){
    printf("%s %d\n", array.items[i].name, array.items[i].value);
  }
  return 0;
}
