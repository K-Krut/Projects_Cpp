/*
Напишите нетипизированное определение типа Type_List на языке С. 
Самый простой способ - это включить в состав каждого элемента списка указатель на данные типа void*. 
Только для продвинутых: проделайте то же самое на языке C++ в виде шаблона, а также на Java, 
определив класс для списка, содержащего элементы типа Object. 
Каковы сильные и слабые стороны разных языков в реализации этой задачи?
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
typedef struct node_t node_t;

struct node_t {

    void *value;
    node_t *next;
    node_t *head;

};

node_t* make_node(void *value) {
    node_t *node = malloc(sizeof(node_t));
    *node = (node_t) {.value = value, .next = NULL};
    return node;
}
 
void push_front(node_t *list, void *value) {
    node_t *temp = make_node(value);
    temp->next = list->head;
    list->head = temp;
}
 
void push_back(node_t *list, void *value) {
    node_t *temp = list->head;
    for ( ; temp != NULL && temp->next != NULL; temp = temp->next)
        continue;
    if (temp != NULL) {
        temp->next = make_node(value);
    } else {
        list->head = make_node(value);
    }
}

typedef void (*some_func)(void* );


void print_string(void *ptr) {
    puts(*(const char**)ptr);
}

void free_name(void *ptr) {
      free(*(char**)ptr);
}

void foreach(node_t *list, some_func func) {
    node_t *p;

    for (p = list->head; p != NULL; p = p->next) {
        func(p->value);
    }
}

void clear(node_t *list, some_func free_name) {
    foreach(list, free_name);
    node_t *p;
    for (p = list->head; p != NULL; p = p->next) {
        free(p);
    }
    free(list);
}

int main() {
 
    node_t *list = malloc(sizeof(node_t));
    *list = (node_t) { .head = NULL };
 
    char *a = strcpy(malloc(strlen("abc") + 1), "abc");
    char *b = strcpy(malloc(strlen("def") + 1), "def");
    char *c = strcpy(malloc(strlen("ghi") + 1), "ghi");
    char *d = strcpy(malloc(strlen("jkl") + 1), "jkl");

    push_back(list, &a);
    push_back(list, &b);
    push_back(list, &d);
    push_back(list, &c);
    foreach(list, print_string);
    clear(list, free_name);
//  foreach(list, print_string);

}
