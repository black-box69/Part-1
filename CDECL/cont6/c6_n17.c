#include <stdio.h>
#include <stdlib.h>

//made by: CDECL

struct Node {
  int key;
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};

int height(struct Node *N){
  if (N == NULL)
    return 0;
  return N->height;
}

int max(int a, int b){
  return (a > b) ? a : b;
}

struct Node* find(struct Node *root, int key) {
    if (root == NULL) return NULL;
    if (root->key == key) return root;
    if (root->key < key) {
        if (root->right == NULL) return NULL;
        return find(root->right, key);
    }
    if (root->key > key) {
        if (root->left == NULL) return NULL;
        return find(root->left, key);
    }
    return root;
}


struct Node *newNode(int key, int data){
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  node->data = data;
  return (node);
}

struct Node *rightRotate(struct Node *y){
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(height(y->left), height(y->right)) + 1;
  x->height = max(height(x->left), height(x->right)) + 1;

  return x;
}

struct Node *leftRotate(struct Node *x){
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->height = max(height(x->left), height(x->right)) + 1;
  y->height = max(height(y->left), height(y->right)) + 1;

  return y;
}

int getBalance(struct Node *N){
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

struct Node *insertNode(struct Node *node, int key, int data){
  struct Node* tmp = find(node, key);
  if (tmp == NULL) {
      if (node == NULL)
        return (newNode(key, data));
    
      if (key < node->key)
        node->left = insertNode(node->left, key, data);
      else if (key > node->key)
        node->right = insertNode(node->right, key, data);
      else
        return node;
    
      node->height = 1 + max(height(node->left),
                   height(node->right));
    
      int balance = getBalance(node);
      if (balance > 1 && key < node->left->key)
        return rightRotate(node);
    
      if (balance < -1 && key > node->right->key)
        return leftRotate(node);
    
      if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
      }
    
      if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
      }
    
      return node;
  }
  else {
    tmp->data = data;
    return node;
  }
}

struct Node *minValueNode(struct Node *node){
  if (node == NULL) return NULL;
  struct Node *current = node;

  while (current->left != NULL)
    current = current->left;

  return current;
}

struct Node *deleteNode(struct Node *root, int key){
  if (root == NULL)
    return root;
  struct Node* tmp = find(root, key);
  if (tmp == NULL) return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);

  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    if ((root->left == NULL) || (root->right == NULL)) {
      struct Node *temp = root->left ? root->left : root->right;

      if (temp == NULL) {
        temp = root;
        root = NULL;
      } else
        *root = *temp;
      free(temp);
    } else {
      struct Node *temp = minValueNode(root->right);

      root->key = temp->key;
      root->data = temp->data;

      root->right = deleteNode(root->right, temp->key);
    }
  }

  if (root == NULL)
    return root;

  root->height = 1 + max(height(root->left),
               height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
    return rightRotate(root);

  if (balance > 1 && getBalance(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  if (balance < -1 && getBalance(root->right) <= 0)
    return leftRotate(root);

  if (balance < -1 && getBalance(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

int main ( void )
{
    char op = ' ';
    int k = 0, d = 0;
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    in = stdin;
    out = stdout;
    struct Node *root = NULL;
 
    while ( op != 'F' )
    {
        fscanf(in, "%c", &op);
        // scanf ( "%c", &op );
        if ( op == 'A' )
        {
            fscanf(in, "%d%d", &k, &d);
            // scanf ( "%d%d", &k, &d);
            root = insertNode(root, k, d);
        }
        if ( op == 'S' )
        {
            //scanf ( "%d", &k);
            fscanf(in, "%d", &k);
            struct Node *t = find(root, k);
            if ( t != NULL ) {
                // printf ( "%d %d\n", t->key, t->data );
                fprintf(out, "%d %d\n", t->key, t->data);
            }
        }
        if ( op == 'D' )
        {
            // scanf ( "%d", &k );
            fscanf(in, "%d", &k);
            root = deleteNode(root, k);
        }
    }
    return 0;
}
