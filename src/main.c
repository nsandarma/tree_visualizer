#include "graphic.h"

int main(){
  Node* root = NULL;
  root = insert(root,10);
  insert(root,11);
  insert(root,2);
  insert(root,3);
  insert(root,100);
  insert(root,120);
  insert(root,323);
  insert(root,10);
  insert(root,12);
  insert(root,9);
  insert(root,1);
  
  initialWindow(root);

  freeNode(root);

  return 0;
}