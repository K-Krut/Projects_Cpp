/*
В коде Unit 1 "Growing Arrays" функция delname не вызывает функцию realloc, 
чтобы возвратить память, освободившуюся при удалении. Стоит ли это делать? 
Как бы вы определили, делать это или нет?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval {
  char *name;
  int value;
} Nameval;

struct Array { //NVtab
  int nval;
  int max;
  Nameval *items;
};

enum { NVINIT = 1, NVGROW = 2 };

  int add_timem(struct Array *array, Nameval newname){  
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

  int delname(struct Array *array, char *name) {
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
  add_timem(&array, (struct Nameval) {.name = "Andy", .value = 12});
  add_timem(&array, (struct Nameval){.name = "Billy", .value = 16});
  add_timem(&array, (struct Nameval){.name = "Tom", .value= 25});
  add_timem(&array, (struct Nameval){.name = "Alice", .value= 25});

  for (int i = 0; i < array.nval; ++i){
    printf("%s %d\n", array.items[i].name, array.items[i].value);
  }
  return 0;
}

/*
Функція delname не викликає функцію realloc, адже:
функція realloc()повертає вказівник на перший байт знову 
виділеного блоку памяті, а оскільки в програмі не передбачене
подальше використання цього блоку пам'яті, то її використання
не є необхідністю.
*/
