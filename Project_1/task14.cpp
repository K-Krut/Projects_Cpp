/*
Дерево, в котором любой путь от корня к листу имеет примерно одинаковую длину, называется сбалансированным. 
(Преимущество сбалансированного дерева заключается в том, что поиск по нему имеет характер O(log n), 
поскольку, как и в двоичном поиске, на каждом шаге отбрасывается половина оставшихся данных.) 
Сгенерировать поток данных для заполнения дерева (см. Unit 1 "Binary search tree"). 
По мере поступления данных для каждого элемента данных формировать узел и добавлять его в дерево. 

Вариант "1": элементы поступают в случайном порядке (поступающие данные достаточно стохастичны). 
Написать функцию проверки сбалансированности заполненного (построенного) дерева, 
чтобы подтвердить или опровергнуть следующее утверждение: если элементы поступают в случайном порядке, 
то дерево будет более-менее сбалансированным. 

Вариант "2": элементы прибывают в отсортированном виде. Написать функцию проверки сбалансированности 
заполненного (построенного) дерева, чтобы подтвердить или опровергнуть следующее утверждение: 
если элементы прибывают в отсортированном виде, то спуск всегда будет выполняться до 
самого низа одной из ветвей дерева, фактически представляя собой список по указателю right. 
Этот случай характеризуется проблемами быстродействия, присущими спискам.
*/


//a)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree Tree;

struct Tree {
  char *name;
  int value;
  Tree *left;
  Tree *right;
};

int comparison(int brancha, int branchb){
 if(brancha >= branchb)
    return brancha;
 else
    return branchb;
}

int height(struct Tree *treep){
    if(treep == NULL)
        return 0;
    int l_height = height(treep->left);
    int r_height = height(treep->right);
    return comparison(l_height, r_height) + 1;
}

int check(struct Tree *treep){
   if(treep == NULL)
       return 1;
   int l_height = height(treep->left);
   int r_height = height(treep->right);

   if(abs(l_height - r_height) <= 1 && check(treep->right) && 
   check(treep->left))
       return 1;
   else
       return 0;
}

Tree *insert(Tree *treep, Tree *new_item){
	if(treep == NULL)
		return new_item;
	int cmp = strcmp(new_item->name, treep->name);
	if(cmp==0)
		printf("insert: duplicate entry %s ignored", new_item->name);
	else if (cmp < 0)
		treep -> left = insert(treep->left, new_item);
	else
		treep -> right = insert(treep->right, new_item);
	return treep;
}

Tree *search(Tree *treep, char *name){
	if (treep == NULL)
		return NULL;
	int cmp = strcmp(name, treep->name);
	if(cmp == 0)
		return treep;
	else if(cmp < 0)
		return search(treep->left, name);
	else
		return search(treep->right, name);
}

void preorder(Tree *treep) {
  if (treep != NULL) {
    printf("%s %d\n", treep->name, treep->value);
    preorder(treep->left);
    preorder(treep->right);
  }
}

int main() {

  Tree *treep = NULL;
  treep = insert(treep, &(struct Tree) {.name = "A", .value = 9});
  treep = insert(treep, &(struct Tree) {.name = "B", .value = 2});
  treep = insert(treep, &(struct Tree) {.name = "C", .value = 87});
  treep = insert(treep, &(struct Tree) {.name = "D", .value = 98});
  treep = insert(treep, &(struct Tree) {.name = "Y", .value = 78});

        preorder(treep);
        check(treep) ? printf("Balanced\n") : printf("Unbalanced\n");  

return 0;
}

 

//b)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree Tree;

struct Tree {
  char *name;
  int value;
  
  Tree *left;
  Tree *right;
};

int comparison(int brancha, int branchb) {
	brancha >= branchb ?  brancha : branchb;
}

int height(struct Tree *treep){
    if(treep == NULL)
        return 0;
    int l_height = height(treep->left);
    int r_height = height(treep->right);
    return comparison(l_height, r_height) + 1;
}

int check(struct Tree *treep){
   if(treep == NULL)
       return 1;
   int l_height = height(treep->left);
   int r_height = height(treep->right);

   if(abs(l_height - r_height) <= 1 && check(treep->right) && check(treep->left))
       return 1;
   else
       return 0;
}

Tree *insert(Tree *treep, Tree *new_item){
	if(treep == NULL)
		return new_item;
	int cmp = strcmp(new_item->name, treep->name);
	if(cmp == 0)
		printf("duplicate ignored");
	else if (cmp < 0)
		treep->left = insert(treep->left, new_item);
	else
		treep->right = insert(treep->right, new_item);
	return treep;
}

void preorder(Tree *treep) {
  if (treep != NULL) {
    printf("%s %d\n", treep->name, treep->value);
    preorder(treep->left);
    preorder(treep->right);
  }
}

int main() {

  Tree *treep = NULL;
  treep = insert(treep, &(struct Tree) {.name = "A", .value = 2});
  treep = insert(treep, &(struct Tree) {.name = "B", .value = 4});
 // treep = insert(treep, &(struct Tree) {.name = "C", .value = 6});
 // treep = insert(treep, &(struct Tree) {.name = "D", .value = 8});
 // treep = insert(treep, &(struct Tree) {.name = "E", .value = 10});
 // treep = insert(treep, &(struct Tree) {.name = "F", .value = 12});

	preorder(treep);
    check(treep) ? printf("Balanced\n") : printf("Unbalanced\n");
  
  return 0;
}
