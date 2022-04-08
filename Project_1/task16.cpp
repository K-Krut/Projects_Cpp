/*
Напишите функцию сортировки с симметричным обходом (см. Unit 1 "Treetraverser"). 
Какой порядок по быстродействию имеет данная операция? При каких условиях она может работать плохо? 
Каковы ее характеристики по сравнению с алгоритмом быстрой сортировки и с библиотечными функциями?
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
  char *name;
  int value;
  Nameval *left;
  Nameval *right;
};

Nameval *insert(Nameval *treep, Nameval *newp){
  if(treep == NULL)
    return newp;
  int cmp = strcmp(newp->name, treep->name);
  if(cmp == 0)
    printf("%s %d\n", newp->name, newp->value);
  else if (cmp < 0)
    treep->left = insert(treep->left, newp);
  else
    treep->right = insert(treep->right, newp);
  return treep;
}

void print_sorted(Nameval *treep) {
  if (treep == NULL)
      return;

  print_sorted(treep->right);
    printf("%s", treep->name);
  print_sorted(treep->left);
}

void inorder(Nameval *treep) {
if (treep != NULL) {
inorder(treep->left);
printf("%s %d\n", treep->name, treep->value);
inorder(treep->right);
}
}

void preorder(Nameval *treep) {
  if (treep != NULL) {
    printf("%s %d\n", treep->name, treep->value);
    preorder(treep->left);
    preorder(treep->right);
  }
}

void postorder(Nameval *treep) {
  if (treep != NULL) {
     postorder(treep->left);
     postorder(treep->right);
    printf("%s %d\n", treep->name, treep->value);
  }
}

void applyinorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg){
  if (treep == NULL)
    return;
  applyinorder(treep->left, fn, arg);
  (*fn)(treep, arg);
  applyinorder(treep->right, fn, arg);
}

void applypostorder(Nameval *treep, void (*fn)(Nameval*, void*), void *arg){
  if(treep == NULL)
    return;
  applypostorder(treep->left, fn, arg);
  applypostorder(treep->right, fn, arg);
  (*fn)(treep, arg);
}

void printnv(Nameval *p, void *arg){
  char *fmt;
  fmt = (char *)arg;
  printf(fmt, p->name, p->value);
}


int main() {
  Nameval *treep = NULL;
  treep = insert(treep, &(struct Nameval){.name = "A", .value = 1});
  treep = insert(treep, &(struct Nameval){.name = "F", .value = 6});
  treep = insert(treep, &(struct Nameval){.name = "B", .value = 2});
  treep = insert(treep, &(struct Nameval){.name = "E", .value = 5});
 // treep = insert(treep, &(struct Nameval){.name = "C", .value = 3});
 // treep = insert(treep, &(struct Nameval){.name = "D", .value = 4});
 // treep = insert(treep, &(struct Nameval){.name = "G", .value = 7});
 // treep = insert(treep, &(struct Nameval){.name = "I", .value = 8});
  treep = insert(treep, &(struct Nameval){.name = "H", .value = 9});
  
 // applyinorder(treep, printnv, "%s: %d\n");
 // putchar('\n');
  //applypostorder(treep, printnv, "%s: %d\n");
  // printf("\n\n");
     preorder(treep);
     printf("\n\n");

     inorder(treep);
     printf("\n\n");

     postorder(treep);
     printf("\n\n");

  return 0;
}
