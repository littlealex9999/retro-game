/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "GameManager.h"
#include "Player.h"
#include <string>
std::string gameText;

namespace Manager
{
    GameManager manager = { };
}

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Retro Game");

    Manager::manager.Init();

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        
        Manager::manager.Update(GetFrameTime());

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Manager::manager.Draw();

        if (Manager::manager.getPlayer() != nullptr) {
            gameText = "Life: ";
            gameText.append(std::to_string(Manager::manager.getPlayer()->health));
            DrawText(gameText.c_str(), 0, screenHeight - 20, 15, GRAY);
        } else {
            DrawText("YOU DIED", screenWidth / 2 - MeasureText("YOU DIED", 20) / 2, screenHeight / 2 - 10, 20, GRAY);
            gameText = "Score: ";
            gameText.append(std::to_string(Manager::manager.getScore()));
            DrawText(gameText.c_str(), screenWidth / 2  - MeasureText(gameText.c_str(), 20) / 2, screenHeight / 2 + 10, 20, GRAY);
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}