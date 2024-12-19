#ifndef _DRAWNODE_H
#define _DRAWNODE_H
#include "bst.h"
#include "raylib.h"

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define TITLE "EXAMPLES RAYLIB"

void drawTree(Node *root, int x, int y, int offset);
void initialWindow(Node *root);


#endif
