#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "pet the friend!");

    int times_pet = 0;
    Texture2D friend = LoadTexture("./friend.png");
    const int friend_original_width = friend.width;
    const int friend_original_height = friend.height;
    const int friend_original_y = screenHeight/2 - friend.height/2;

    InitAudioDevice();
    Sound pop = LoadSound("./click.ogg");

    int friend_y = friend_original_y;

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            times_pet++;
            PlaySound(pop);
            friend.width = friend_original_width * 1;
            friend.height = friend_original_height * 0.6;
            friend_y += 75;
        }
        if(IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            friend.width = friend_original_width;
            friend.height = friend_original_height;
            friend_y = friend_original_y;
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawTexture(friend, screenWidth/2 - friend.width/2, friend_y, WHITE);

        DrawText(TextFormat("Times Pet: %d", times_pet), 0, 0, 20, BLACK);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    UnloadTexture(friend);
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
