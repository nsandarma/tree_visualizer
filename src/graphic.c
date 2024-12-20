#include "graphic.h"
#include <raylib.h>

// WARNING: Posisi nya masih belum rapi !
void calculateNodePos(Node *root, int depth, int xStart, int xEnd, int ySpacing){
  if (root == NULL) return;
  root->x = (xStart + xEnd) / 2;
  root->y = depth * ySpacing;
  calculateNodePos(root->left,depth + 1 , xStart,root->x,ySpacing);
  calculateNodePos(root->right,depth + 1 ,root->x ,xEnd,ySpacing);
}

// WARNING: Garis nya masih belum rapi !
void drawTree(Node *root){
  if (root == NULL) return;

  if (root->left != NULL) {
    DrawLine(root->x,root->y,root->left->x,root->left->y,BLACK);
  }
  if (root->right != NULL) {
    DrawLine(root->x,root->y,root->right->x,root->right->y,BLACK);
  }
  DrawCircle(root->x,root->y, NODE_RADIUS,BLACK);
  DrawCircleLines(root->x,root->y,NODE_RADIUS,BLACK);

  // Gambar value di tengah node
  char valueText[10];
  sprintf(valueText, "%d", root->data);
  DrawText(valueText, root->x - MeasureText(valueText, 10) / 2,root->y - 5, 15, WHITE);

  // Gambar child nodes
  drawTree(root->left);
  drawTree(root->right);
}

void initialWindow(Node *root){
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT,TITLE);

  Camera2D camera = {0};
  camera.offset = (Vector2){ SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f };
  camera.zoom = 0.8f;

  calculateNodePos(root, 1, 0, SCREEN_WIDTH, 100);

  camera.target = (Vector2){ root->x, root->y+450};
  printf("pos x : %d || pos y : %d\n",root->x,root->y);

  SetTargetFPS(60); // Set FPS
  Vector2 lastMousePosition = { 0.0f, 0.0f };
  bool isDragging = false;

  while(!WindowShouldClose()){

    float zoomSpeed = 0.1f;
    float moveSpeed = 5.0f;

    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        isDragging = true;
        lastMousePosition = GetMousePosition(); // Menyimpan posisi mouse saat drag dimulai
    }
    
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
        isDragging = false;
    }

    if (isDragging) {
        Vector2 currentMousePosition = GetMousePosition();
        Vector2 mouseDelta = { currentMousePosition.x - lastMousePosition.x, currentMousePosition.y - lastMousePosition.y };
        camera.target.x -= mouseDelta.x / camera.zoom;
        camera.target.y -= mouseDelta.y / camera.zoom;
        lastMousePosition = currentMousePosition;
    }

    float scroll = GetMouseWheelMove();
    if (scroll != 0.0f) {
        camera.zoom += scroll * zoomSpeed;
        if (camera.zoom < 0.1f) camera.zoom = 0.1f;
        if (camera.zoom > 3.0f) camera.zoom = 3.0f;
    }
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode2D(camera);

    drawTree(root);

    EndMode2D();

    DrawText("Binary Search Tree Visualizer", 10, 10, 20, DARKGRAY);
    DrawText("Tekan ESC untuk keluar.", 10, 40, 20, DARKGRAY);

    EndDrawing();
  }

  CloseWindow();

}
