#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//made by: CDECL

typedef struct _Node {
  void *value;
  struct _Node *next;
  struct _Node *prev;
} Node;


typedef struct _DblLinkedList {
  size_t size;
  Node *head;
  Node *tail;
} DblLinkedList;


DblLinkedList* create(void) {
  DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
  tmp->size = 0;
  tmp->head = tmp->tail = NULL;

  return tmp;
}

void add(DblLinkedList *list, void *value) {
  Node *tmp = (Node*) malloc(sizeof(Node));
  if (tmp == NULL) {
      exit(3);
  }
  tmp->value = value;
  tmp->next = NULL;
  tmp->prev = list->tail;
  if (list->tail) {
      list->tail->next = tmp;
  }
  list->tail = tmp;

  if (list->head == NULL) {
      list->head = tmp;
  }
  list->size++;
}

void change(DblLinkedList *list, int start, int finish, Node** nodes) {
  if (start == *(int*)list->head->value) return;
  Node *n_first = nodes[start - 1];
  Node *n_last = nodes[finish - 1];
  Node *first = list->head;
  Node *last = n_first->prev;
  // printf("%d %d %d %d\n", *((int*)first->value), *((int*)last->value), *((int*)n_first->value), *((int*)n_last->value));
  first->prev = n_last;
  last->next = n_last->next;
  n_first->prev = NULL;
  n_last->next = first;
  list->head = n_first;
  if (last->next == NULL) list->tail = last;
}


int main(void) {
    FILE *file = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int N, M;
    fscanf(file, "%d%d", &N, &M);
    // scanf("%d%d", &N, &M);
    DblLinkedList *list = create();
    int values[N];
    Node* nodes[N];
    Node* tmp = NULL;
    for (int i = 1; i <= N; i++) {
        values[i - 1] = i;
        add(list, &values[i - 1]);
        if (i == 1) tmp = list->head; 
        else tmp = tmp->next; 
        nodes[i - 1] = tmp;
    }
    
    int start;
    for (int i = 0; i < M; i++) {
      fscanf(file, "%d", &start);
      // scanf("%d", &start);
      change(list, start, *((int*)list->tail->value), nodes);
    }
    
    tmp = list->head;
    for (int i = 1; i <= N; i++) {
      fprintf(out, "%d ", *((int*)(tmp->value)));
      // printf("%d ", *((int*)(tmp->value)));
      tmp = tmp->next;
    }
    return 0;
}
