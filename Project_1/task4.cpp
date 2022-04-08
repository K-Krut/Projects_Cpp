/*
Обратите внимание, что в коде Unit 1 "Growing Arrays" не употребляется такая конструкция: 
nvtab.nameval = (Nameval *) realloc(nvtab.nameval, (NVGROW*nvtab.max) * sizeof(Nameval)); 
В этом случае, если бы при перераспределении памяти произошла ошибка, 
все накопленные в исходном массиве данные были бы потеряны. 
Объясните почему? Покажите действующий пример.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval {
    char *name;
    int value;
} Nameval;

struct Array {
    int lenght;
    int capacity;
    Nameval *items;
};

enum {NVINIT = 1, NVGROW = 2};

int add_item(struct Array *Array, Nameval newname) {
//    Nameval *nvp;
    if (Array->items == NULL) {
        Array->items = (Nameval *) malloc(NVINIT * sizeof(Nameval));
        if (Array->items == NULL)
            return -1;
        Array->capacity = NVINIT;
        Array->lenght = 0;

    } else if (Array->lenght >= Array->capacity) {
    //  vp = (items *) realloc(Array->items, (NVGROW*Array->capacity)*sizeof(Nameval));
		Array->items = (Nameval *) realloc(Array->items, (NVGROW*Array->capacity)*sizeof(Nameval));
	    if (Array->items == NULL) return -1;
			Array->capacity *= NVGROW;
    //      Array->items = nvp;
    }

    Array->items[Array->lenght] = newname;
    return Array->lenght++;
}

int del_item(struct Array *Array, char *name) {
    for (int i = 0; i < Array->lenght; ++i) {
        if (strcmp(Array->items[i].name, name) == 0){
            memmove(Array->items + i, Array->items + i + 1, (Array->lenght - ( i + 1))*sizeof(Nameval));
            Array->lenght--;
            return 1;
        }
    }
    return 0;
}

int main () {
	struct Array Array = {0, 0, NULL}; //Initializing fields of a structure

    add_item (&Array, (struct Nameval) {.name = "Andy", .value = 12});
    add_item(&Array, (struct Nameval) {.name = "Billy", .value = 18});
    for (int i = 0; i < Array.lenght; ++i) {
        printf("%s %d\n", Array.items[i].name, Array.items[i].value);
    }
    return 0;
}

/*
Функція void *realloc(void *ptr, size_t size);
повертає вказівник на перший байт знову виділеного блоку пам'яті
і при цьому копіює вміст попереднього блоку пам'яті в новий
тому і не відбувається втрата пам'яті.
В конструкції 
nvtab.nameval = (Nameval *) realloc(nvtab.nameval, (NVGROW*nvtab.max) * sizeof(Nameval));
копіювання буде відбуватись у той самий блок пам'яті 
через що можлива втрата даних.
*/
