#ifndef _DRAWNODE_H
#define _DRAWNODE_H
#include "bst.h"
#include "raylib.h"
#include <stdio.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define TITLE "EXAMPLES RAYLIB"

void calculateNodePos(Node *root, int depth, int xStart, int xEnd, int ySpacing);
void drawTree(Node *root);
void initialWindow(Node *root);


#endif
