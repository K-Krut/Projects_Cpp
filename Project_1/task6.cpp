/*
Внесите необходимые изменения в код функции addname и delname (см. Unit 1 "Growing Arrays") так, 
чтобы удалять имена, помечая их как неиспользуемые. Насколько остальная часть программы изолирована от этих изменений? 
Подсказка: Подход, альтернативный перемещению элементов (memmove) в массиве, - это пометить удаленные элементы 
как неиспользуемые. Затем, чтобы добавить новый элемент, вначале необходимо найти свободную ячейку, 
и только в том случае, если таковых нет, расширить массив до нового размера. 
В примере (см. Unit 1 "Growing Arrays"), чтобы пометить элемент как неиспользуемый, 
в его поле name можно записать значение NULL.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
    char *name;
    int value;
};

struct NVtab {
    int nval; int max;
    Nameval *nameval;
} nvtab;

enum {NVINIT = 1, NVGROW = 2};

int addname(Nameval newname){
    Nameval *nvp;

    if (nvtab.nameval == NULL){
        nvtab.nameval = (Nameval *)malloc(NVINIT * sizeof(Nameval));
        if (nvtab.nameval == NULL)
            return -1;
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    }

    else{
        for (int i = 0; i < nvtab.nval; ++i) {
            if (nvtab.nameval[i].name == NULL) {
                nvtab.nameval[i] = newname;

                return ++nvtab.nval;
            }
        }
    }

    if (nvtab.nval == nvtab.max) {
        nvp = (Nameval *)realloc(nvtab.nameval, (NVGROW * nvtab.max) * sizeof(Nameval));
        if (nvp == NULL)
            return -1;
        nvtab.max *= NVGROW;
        nvtab.nameval = nvp;
    }

    nvtab.nameval[nvtab.nval] = newname;
    ++return nvtab.nval;
}

int delname(char *name) {
    for (int i = 0; i < nvtab.nval; ++i) {
        if (strcmp(nvtab.nameval[i].name, name) == 0) {
            nvtab.nameval[i].name = NULL;
            nvtab.nval--;
            return 1;
        }
    }
    return 0;
}

int main(){
    addname((struct Nameval){.name = "Andy", .value = 12});
    addname((struct Nameval){.name = "Billy", .value = 17});
    addname((struct Nameval){.name = "Mike", .value = 17});
    addname((struct Nameval){.name = "Endy", .value = 17});
    addname((struct Nameval){.name = "John", .value = 17});
    delname("Endy");
    addname((struct Nameval){.name = "Alice", .value = 17});
    for(int i = 0; i < nvtab.nval; ++i){
        printf("%s %d\n", nvtab.nameval[i].name, nvtab.nameval[i].value);
    }
    return 0;
}

