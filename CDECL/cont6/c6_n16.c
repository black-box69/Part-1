#include<stdio.h>

#include<stdlib.h>

//made by: CDECL

typedef struct _Node {
    int value;
    struct _Node *next, *prev;
} Node;

Node *split(Node *head) {
    Node *fast = head,*slow = head;
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

Node *merge(Node *first, Node *second) {
    if (!first) return second;
    if (!second) return first;
    if (first->value < second->value) {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}


Node *mergeSort(Node *head) {
    if (!head || !head->next) return head;
    Node *second = split(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head,second);
}

void insert(Node **head, int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->next = temp->prev = NULL;
    if (!(*head)) (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

int main(void) {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    Node *list = NULL;
    int cur;
    while (1) {
        fscanf(in, "%d", &cur);
        if (feof(in)) break;
        insert(&list, cur);
    }
    /* for (int i = 0; i < 10; i++) {
        scanf("%d", &cur);
        insert(&list, cur);
    } */
    list = mergeSort(list);
    while (list) {
        fprintf(out, "%d ", list->value);
        // printf("%d ", list->value);
        list = list->next;
    }
    return 0;
}
