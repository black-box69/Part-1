#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//made by: 2cache

const char NAME[] = "input.txt";

typedef struct _Node {
  int key;
  struct _Node *next;
  struct _Node *prev;
} Node;

void read_ints (int *arr, int len, FILE *f) { // was adapted from stack overflow
    for (int j = 0; j < len; j++) {
        fscanf(f, "%d", &arr[j]);
    }
    fclose(f);
}

int count_ints(const char *file_name) { // may be not enough
    FILE *f = fopen(file_name, "r");
    int len = 0;
    int buf = 0;
    while (!feof(f)) {
        fscanf(f, "%d", &buf);
        len++;
    }
    fclose(f);
    return len;
}

Node *create_node (void) {
    Node *temp = malloc(sizeof(Node));
    temp->next = NULL;
    temp->key = 0;
    return temp;
}

Node *fill_list(Node *arr, int permutation) {// fills up list with values, fills up array with links on every element
    Node *first_node = create_node();
    first_node->key = 1;
    for (int i = 1; i < permutation; i++) {
        Node *next_node = create_node();
        next_node->key = i + 1;
        first_node->next = next_node;
        next_node->prev = first_node;
        arr[i - 1] = *first_node;
        arr[i] = *next_node;
        //printf("%d \n", first_node);
        //printf("%d ", next_node);
        first_node = next_node;
        //printf("%d has been written\n", i + 1);
    }

    return &arr[0];
}

Node *build_link (int a, int c, Node *head, Node *arr) {
    Node *link_a = arr + (a - 1);
    Node *link_c = arr + (c - 1);

    if (a == head->key) {
        return link_a;
    }
    else if (link_c->next == NULL) {
        Node *buf = link_a->prev;
        buf->next = NULL;
        link_c->next = head;
        head->prev = link_c;
    }
    else {
        int before_a = link_a->prev->key;
        int after_c = link_c->next->key;
        link_a->prev = NULL;

        link_c->next = head;
        head->prev = link_c;
        (arr + (before_a - 1))->next = (arr + (after_c - 1));
        (arr + (after_c - 1))->prev = (arr + (before_a - 1));
    }

    return link_a;
}

int main(void) {
    FILE *f = fopen(NAME, "r");
    int len = count_ints(NAME) - 1;
    int *buffer = malloc(sizeof(int) * len); // [permutations, iterations, ...]

    read_ints(buffer, len, f);


    int iterations = buffer[1];
    int permutation = buffer[0];
    if (permutation == 1) {
        f = fopen("output.txt", "w");
        fprintf(f, "%d ", 1);
        return 0;
    }

    Node *links_permutation = malloc(sizeof(Node) * permutation);


    Node *first_node = fill_list(links_permutation, permutation);

    for (int i = 1; i < iterations + 1; i++) {
        int a = buffer[2 * i];
        int c = buffer[2 * i + 1];
        Node *new_first_node = build_link(a, c, first_node, links_permutation);
        first_node = new_first_node;
    }

    f = fopen("output.txt", "w");

    //printf("%d", first_node->next->next->key);

    int val = first_node->key;
    //printf("1)node: %d|prev: %d|next %d\n", val, (first_node->prev == NULL) ? 0 : first_node->prev->key,(first_node->next == NULL)? 0: first_node->next->key);
    fprintf(f, "%d ", val);
    for (int i = 0; i < permutation - 1; i++) {
        Node * val_node = (links_permutation + (val - 1))->next;
        val = val_node->key;
        //printf("node: %d|prev: %d|next %d\n", val_node->key, (val_node->prev == NULL) ? 0 : val_node->prev->key,(val_node->next == NULL) ? 0: val_node->next->key);
        fprintf(f, "%d ", val);
        //printf("\n");
    }
    free(buffer);

    //printf("%d ", links_permutation[0]);
    return 0;
}
