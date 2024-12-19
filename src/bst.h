#ifndef _BST_H
#define _BST_H
#include <stdlib.h>

struct node_st{
  int data;
  struct node_st *left,*right;
};
typedef struct node_st Node;


Node* createNode(int data);

Node* insert(Node* root,int data);
void insertLeft(Node *root,int data);
void insertRight(Node *root, int data);

void inOrder(Node *root);
void postOrder(Node *root);
void preOrder(Node *root);
void printTraversal(Node *root);

void freeNode(Node *root);

#endif


