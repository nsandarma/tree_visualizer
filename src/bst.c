#include "bst.h"
#include <stdio.h>
#include <stdlib.h>

Node* createNode(int data){
  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

Node* insert(Node *root, int data){
  if (root == NULL){
    return createNode(data);
  }
  if (data < root->data){
    root->left = insert(root->left,data);
  }else{
    root->right = insert(root->right,data);
  }
  return root;
}

void insertLeft(Node *root,int data){
  if (root->left != NULL) return;
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  root->left = newNode;
}

void insertRight(Node *root,int data){
  if (root->right != NULL) return;
  Node *newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  root->right = newNode;
}


// Traversal
void inOrder(Node *root){
  if (root == NULL) return;
  inOrder(root->left);
  printf("%d ",root->data);
  inOrder(root->right);
}

void preOrder(Node *root){
  if (root == NULL) return;
  printf("%d ",root->data);
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node *root){
  if (root == NULL) return;
  postOrder(root->left);
  postOrder(root->right);
  printf("%d ",root->data);
}

void printTraversal(Node *root){
  printf("preOrder : ");
  preOrder(root);
  printf("\n");

  printf("inOrder : ");
  inOrder(root);
  printf("\n");

  printf("postOrder : ");
  postOrder(root);
  printf("\n");
}

// freeNode
void freeTree(Node *root){
  if(root == NULL) return;
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}
