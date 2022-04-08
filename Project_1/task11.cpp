/*
Как и функция freeall (см. Unit 1 "A singly-linked list"), функция delitem не освобождает поля name. 
Модифицируйте обе эти функции с учетом того, что память, выделенную под поля name, нужно освобождать.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nameval Nameval;

struct Nameval {
  char *name;
  int value;
  Nameval *next;
};

Nameval *create_item(char *name, int value) {
  Nameval *new; 
    new = (Nameval*)malloc(sizeof(Nameval));
    new->name = malloc(strlen(name) +1);
    strcpy(new->name, name);
	new->value = value;
	new->next = NULL;
  return new;
}

Nameval *puch_front(Nameval *listp, Nameval *new){
  new->next = listp;
  return new;
}

Nameval *push_end(Nameval *listp, Nameval *new){
  Nameval *p;
  if(listp == NULL) 
    return new;
  for (p=listp; p->next !=NULL; p = p->next);
    p->next = new;
  return listp;
}

 Nameval *search(Nameval *listp, char *name) {
	for ( ; listp != NULL; listp = listp->next)
		if (strcmp(name, listp->name) == 0)
			return listp;
	return NULL; 
 }

Nameval *delitem(Nameval *listp, char *name){
 Nameval *p, *prev;
 prev = NULL;
 for (p = listp; p != NULL; p = p->next) {
   if (strcmp(name, p->name) == 0) {
     if (prev == NULL)
       listp = p->next;
       else
      prev->next = p->next;
     //  free(p->name);
       free(p);
       return listp;
      }
     prev = p;
   }
   return NULL; 
 }


void print(Nameval *listp) {
	for( ; listp != NULL; listp = listp->next)
		printf("%s %d\n", listp->name, listp->value);
	printf("\n\n");
}

void freeall(Nameval *listp){
  Nameval *next;
  for( ; listp != NULL; listp = listp->next){
    free(listp->name);
    free(listp);
  }
}

int main() {
	
  Nameval *nvlist = NULL;
  
  nvlist = puch_front(nvlist, create_item("data1", 10));
  nvlist = push_end(nvlist, create_item("data2", 45));
  nvlist = push_end(nvlist, create_item("data3", 100));
  nvlist = push_end(nvlist, create_item("data4", 50));
  nvlist = push_end(nvlist, create_item("data5", 15));
  
  print(nvlist);
  
  delitem(nvlist, "data2");
  print(nvlist);
  
  freeall(nvlist);
  //print(nvlist);
  
  return 0;
}

