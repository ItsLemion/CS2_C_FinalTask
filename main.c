/*******************************************************************************************
*
*   raylib [models] example - Load 3d model with animations and play them
*
*   Example originally created with raylib 2.5, last time updated with raylib 3.5
*
*   Example contributed by Culacant (@culacant) and reviewed by Ramon Santamaria (@raysan5)
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2019-2024 Culacant (@culacant) and Ramon Santamaria (@raysan5)
*
********************************************************************************************
*
*   NOTE: To export a model from blender, make sure it is not posed, the vertices need to be
*         in the same position as they would be in edit mode and the scale of your models is
*         set to 0. Scaling can be done from the export menu.
*
********************************************************************************************/
#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
// Function to draw buttons and handle clicks
void DrawButton(int x, int y, int width, int height, const char* label, int number)
{
    // Check if mouse is over the button
    Rectangle buttonRec = { x, y, width, height };
    bool mouseOnButton = CheckCollisionPointRec(GetMousePosition(), buttonRec);

    // Draw button
    if (mouseOnButton) {
        DrawRectangleRec(buttonRec, DARKGRAY);  // Darker color when hovering
    } else {
        DrawRectangleRec(buttonRec, LIGHTGRAY);
    }

    // Draw the label
    DrawText(label, x + 10, y + 10, 20, BLACK);

    // If clicked, output the number on the screen
    if (mouseOnButton && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        // Correct usage of FormatText
        const char* formattedText = DrawText("Number: %d", number);
        DrawText(formattedText, 300, 200, 30, DARKGREEN);
    }
}

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib - Buttons with Number Output");

    SetTargetFPS(60);  // Set target FPS to 60

    // Main game loop
    while (!WindowShouldClose())
    {
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the 4 buttons
        DrawButton(50, 50, 200, 50, "Button 1", 1);
        DrawButton(50, 120, 200, 50, "Button 2", 2);
        DrawButton(50, 190, 200, 50, "Button 3", 3);
        DrawButton(50, 260, 200, 50, "Button 4", 4);

        // End drawing
        EndDrawing();
    }

    // De-Initialization
    CloseWindow();  // Close window and OpenGL context

    return 0;
}