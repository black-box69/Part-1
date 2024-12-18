#include <stdio.h>
#include <stdlib.h>
#define MAX(A, B) (A > B) ? A : B

//made by: 2cache

typedef struct tree {

    int x;
    struct tree *left;
    struct tree *right;
} tree;

int is_subset(int size, struct tree *t1, struct tree *t2) {
    //return 0;

    int depth_binary_tree(struct tree *root) {
        if (root == NULL) return 0;
        int depth_left = 1 + depth_binary_tree(root->left);
        int depth_right = 1 + depth_binary_tree(root->right);
        return MAX(depth_left, depth_right);
    }
   
    void fill_m (struct tree *t, int *m) {
        if (t->left != NULL) fill_m(t->left, m);
        *m = t->x;
        m++;
        if (t->right != NULL) fill_m(t->right, m);
    }

    int is_s (int n, int * arr, int * Arr) { // len(arr) < len(Arr)
        int i = 0;
        int j = 0;

        while (i != n) {
            if (*(arr + i) < *(Arr + j)) return 0;
            else if (*(arr + i) == *(Arr + j)) {
                i++;
                j++;
            }
            else if (*(arr + i) > *(Arr + j)) j++;
        }

        // 1 2 3 4 5 6 Arr 
        // 1 3 5 arr 
        return 1;
    }
    int* nodes1 = malloc(sizeof(int) * (int) 1<<depth_binary_tree(t1)); //pow of 2
    int* nodes2 = malloc(sizeof(int) * (int) 1<<depth_binary_tree(t2)); //pow of 2

    fill_m(t1, nodes1);
    fill_m(t2, nodes2);

    return is_s(size, nodes1, nodes2);
}

int layer_size (struct tree *root, int layer) {
    if (root == NULL) return 0;
    if (layer == 1) return 1;
    return layer_size(root->left, layer - 1) + layer_size(root->right, layer - 1);
}

void print_tree(struct tree *t) {
    if (t->left != NULL) print_tree(t->left);
    printf("%d ", t->x); 
    if (t->right != NULL) print_tree(t->right);
}



int main(void) {
    /*
    tree t1_3 = {3, 0, 0}; //!
    tree t1_2 = {2, 0, &t1_3};
    tree t1 = {1, 0, &t1_2};

    tree t2_5 = {5, 0, 0};
    tree t2_4 = {4, 0, &t2_5};
    tree t2_3 = {3, 0, &t2_4};
    tree t2_2 = {2, 0, &t2_3};
    tree t2 = {1, 0, &t2_2};
    */
    /*
    struct tree t1 = {1, 0, 0};
    struct tree t3 = {3, 0, 0};
    struct tree t5 = {5, 0, 0};
    struct tree t7 = {7, 0, 0};
    struct tree t2 = {2, &t1, &t3};
    struct tree t6 = {6, &t5, &t7};
    struct tree t4 = {4, &t2, &t6};

    struct tree d1 = {1, 0, 0};
    struct tree d3 = {3, 0, 0};
    struct tree d5 = {5, 0, 0};
    struct tree d7 = {7, 0, 0};
    struct tree d2 = {2, &d1, &d3};
    struct tree d6 = {6, &d5, &d7};
    struct tree d4 = {4, &d2, &d6};
    */
    
    //tree t1_ = {-1, 0, 0};
    tree t1_1 = {1, 0, 0};

    //tree t3_3 = {3, 0, 0};
    tree t2_2 = {2, &t1_1, 0};
    tree t5_5 = {5, 0, 0};
    tree t7_7 = {7, 0, 0};
    tree t6_6 = {6, &t5_5, &t7_7};
    tree t = {4, &t2_2, &t6_6};
    
    //print_tree(&t);
    //printf("%d", depth_binary_tree(&t));

    //printf("%d", is_subset(7, &t4, &d4));

    printf("%d", layer_size(&t, 3));
    return 0;
}
