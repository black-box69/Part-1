#include <stdio.h>
#define MAX(A, B) (A > B) ? A : B

//made by: 2cache

struct list {
    int key;
    struct list * next;
    struct list * sublist_head;
};

int examine_br(struct list * garl, int brightness) {
    if (garl == NULL) return 0;
    if (garl->sublist_head != NULL) return MAX(MAX(brightness, examine_br(garl->sublist_head, 0)), examine_br(garl->next, 0));
    
}


int examine(struct list * garland) {

    //if (garland->sublist_head == NULL) return examine() + 1;
}

int main(void) {
    struct list g10  = {10, 0, 0};
    struct list g9  = {9, &g10, 0};
    struct list g8  = {8, 0, &g9};
    struct list g6  = {6, &g8, 0};
    struct list g5  = {5, &g6, 0};
    struct list g4  = {4, 0, 0};
    struct list g3  = {3, &g4, 0};
    
    struct list g2  = {2, &g3, &g5};

    struct list g  = {1, &g2, 0};


    printf("%d", examine(&g));
    return 0;

}
