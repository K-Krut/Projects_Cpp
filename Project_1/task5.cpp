/*
Удаление имени из массива требует решить что делать с освободившейся ячейкой. 
Если порядок элементов не имеет значения, то легче всего перебросить последний 
элемент в образовавшуюся свободную позицию. Если же порядок необходимо соблюсти, 
то придется сдвинуть на одну ячейку назад все элементы после свободной позиции. 
Именно так поступает функция delname (см. Unit 1 "Growing Arrays"). 
 
Покажите на действующем примере переброску последнего элемента в образовавшуюся свободную позицию.
*/


//a)
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
} array;


enum { NVINIT = 1, NVGROW = 2 };


int addname(Nameval newname) {
    Nameval *temp;
    if (array.items == NULL) {
        array.items = (Nameval *)malloc(NVINIT * sizeof(Nameval));
        if (array.items == NULL)
            return -1; 
        array.capacity = NVINIT;
        array.lenght = 0;
    }
    else if (array.lenght == array.capacity) {
        temp = (Nameval *)realloc(array.items, (16 * array.capacity) * sizeof(Nameval));
        if (temp == NULL)
            return -1; 
        array.capacity *= NVGROW;
        array.items = temp;
    }
    array.items[array.lenght] = newname;
    return array.lenght++;
}

int delname(char *name) {
    for (int i = 0; i < array.lenght; i++){
        if (strcmp(array.items[i].name, name) == 0){
            memmove(array.items + i, array.items + i + 1, (array.lenght - (i + 1)) * sizeof(Nameval));
            //for (int j = i; j < array.lenght; j++) ///заміна функції memmove(), 
            //    array.items[j] = array.items[j + 1];
            array.lenght--;
            return 1;
        }
    }
    return 0;
}

int main() {
  //  struct Array array = {0, 0, NULL};
    addname((struct Nameval){.name = "Andy", .value = 12});
    addname((struct Nameval){.name = "Billy", .value = 17});
    addname((struct Nameval){.name = "Mike", .value = 17});
    addname((struct Nameval){.name = "Endy", .value = 17});
    addname((struct Nameval){.name = "John", .value = 17});
    
    for(int i = 0; i < array.lenght; ++i)
        printf("%s %d\n", array.items[i].name, array.items[i].value);
    delname("Endy");

    
    for(int i = 0; i < array.lenght; ++i)
        printf("%s %d\n", array.items[i].name, array.items[i].value);

    return 0;
}





//b)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct {
    char *name;
    int value;
} Nameval;
 
typedef struct {
    Nameval *items;
    int length;
    int capacity;
} Array;
 
Array* create() {
    Array *result = malloc(sizeof(Array));
    result->items = malloc(16 * sizeof(Nameval));
    result->length = 0;
    result->capacity = 16;
    return result;
}
 
void destroy(Array  *array) {
    if (array != NULL && array->items != NULL) {
        for (int i = 0; i < array->length; ++i) {
            free(array->items[i].name);
        }
        free(array->items);
    }
    free(array);
}
 
void expand(Array *array) {
    array->items = realloc(array->items, array->capacity *= 2);
}

void resize(Array *array, int size) {
    while (array->capacity < size) {
        expand(array);
    }
    array->length = size;
}
 
void add_item(Array *array, Nameval item) {
    resize(array, array->length + 1);
    array->items[array->length - 1] = item;
}

void remove_item(Array *array, int position) {
    if (position < 0 || position >= array->length) {
        return;
    }
    array->items[position] = array->items[array->length - 1];
    resize(array, array->length - 1);
}
 
void remove_items_by_name(Array *array, const char *name) {
    for (int i = array->length - 1; i >= 0; --i) {
        if (strcmp(array->items[i].name, name) == 0) {
            remove_item(array, i);
        }
    }
}
 
char* make_string(const char *source) {
    return strcpy(malloc(sizeof(char) * (strlen(source) + 1)), source);
}
 
Array* init() {
    Array *result = create();
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i) {
        static char name[1024];
        int value;
        scanf("%s %d", name, &value);
        add_item(result, (Nameval){.name = make_string(name), .value = value});
    }
    return result;
}
 
void print(Array *array) {
    if (array->items == NULL) {
        return;
    }
    for (int i = 0; i < array->length; ++i) {
        printf("%s %d\n", array->items[i].name, array->items[i].value);
    }
    putchar('\n');
}
 
int main (void) {
 
    Array *array = init();
	  puts("\n\n");
  
    print(array);
 
    remove_items_by_name(array, "Andy");
 
    print(array);
 
}
