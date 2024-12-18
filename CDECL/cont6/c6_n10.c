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
  Node *after_last = n_last->next; 
  if (n_last->next == NULL) {
    last->next = NULL;
    n_first->prev = NULL;
    n_last->next = first;
    first->prev = n_last;
    list->head = n_first;
    // printf("first_case ");
  }
  else {
    n_first->prev = NULL;
    n_last->next = first;
    first->prev = n_last;
    last->next = after_last;
    after_last->prev = last;
    list->head = n_first;
    // printf("second_case ");
  }
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
    
    int start, finish;
    for (int i = 0; i < M; i++) {
      // scanf("%d%d", &start, &finish);
      fscanf(file, "%d%d", &start, &finish);
      change(list, start, finish, nodes);
    }
    
    tmp = list->head;
    // printf("\n");
    for (int i = 1; i <= N; i++) {
      // printf("%d ", *(int*)(tmp->value));
      // printf("node: %d|prev: %d|next: %d\n", *(int*)(tmp->value), (tmp->prev == NULL) ? 0 : *(int*)(tmp->prev->value), (tmp->prev == NULL)? 0 :*(int*)(tmp->next->value));
      fprintf(out, "%d ", *((int*)(tmp->value)));
      tmp = tmp->next;
    }
    return 0;
}
