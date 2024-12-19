#include "graphic.h"

void drawTree(Node *root, int x, int y, int offset){
  if (root == NULL) return;
  DrawCircle(x, y, 20, DARKGRAY);
  DrawText(TextFormat("%d", root->data), x - 10, y - 10, 20, WHITE);

  if (root->left != NULL) {
      DrawLine(x, y, x - offset, y + 50, DARKGREEN);
      drawTree(root->left, x - offset, y + 50, offset / 2);
  }
  if (root->right != NULL) {
      DrawLine(x, y, x + offset, y + 50, DARKGREEN);
      drawTree(root->right, x + offset, y + 50, offset / 2);
  }
}

void initialWindow(Node *root){
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,TITLE);

  while(!WindowShouldClose()){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    drawTree(root, SCREEN_WIDTH / 2, 60, 150);

    DrawText("Binary Search Tree Visualizer", 10, 10, 20, DARKGRAY);
    DrawText("Tekan ESC untuk keluar.", 10, 40, 20, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();

}
