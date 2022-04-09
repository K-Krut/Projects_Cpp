/*
Создайте класс с циклической очередью целых (см. Unit 2 "A more practical example"). 
Сделайте очередь длиной 100 целых. В функцию main() включите краткую демонстрацию
ее работы. Провести инициализацию с помощью конструктора.



Завдання № 6: 
Реализуйте на С решение Задачи 2.5. (см. Unit 1 "A singly-linked list"). 
Пример циклической очереди, построенной при помощи указателей:
*/

Код програми:
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;

void addlist(struct node** new_node) {
  struct node* temp;
  if (head == NULL) {
    head = *new_node;
    head->next = head;
  }
  else {
    temp = head;
    while (temp->next != head)
      temp = temp->next;
    temp->next = *new_node;
    temp = *new_node;
    temp->next = head;
  }
}
void disp(int size) {
  struct node* temp;
  printf("%3d\n", head->data);
  temp = head->next;

  for (int i = 0; i < size - 1; ++i) {
    printf("%3d\n", temp->data);
    temp = temp->next;
  }
}

int main() {
  struct node* new_node;
  int size, num;
  printf("Enter size, number of elements in queue\n");
  scanf("%d %d", &size, &num);

  for (int i = 1; i <= num; ++i) {
    new_node = (struct node*)malloc(sizeof(struct node));
    // new_node -> data = i;
    new_node->data = rand() % 64;
    addlist(&new_node);
  }
  disp(size);
  return 0;
}

