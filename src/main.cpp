#include <raylib.h>
#include <raymath.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>

#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

#include "Engine/Game/Game.hpp"

#include "Main/Main.hpp"
#include "Other/Other.hpp"

namespace Scenes
{
    std::unique_ptr<Main> main_scene;
    std::unique_ptr<Other> other_scene;
}

Game game;

void UpdateDrawFrame();

int main(void)
{
	InitWindow(game.WIDTH, game.HEIGHT, game.TITLE.c_str());
	//ToggleFullscreen();
	game.Init();

	Scenes::main_scene = std::make_unique<Main>();
    Scenes::other_scene = std::make_unique<Other>();
	game.SetScene(Scenes::main_scene.get());

	#if defined(PLATFORM_WEB)
    	emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
	#else
		SetTargetFPS(60);   // Set our game to run at 60 frames-per-second
		//--------------------------------------------------------------------------------------

		// Main game loop
		while (!WindowShouldClose())    // Detect window close button or ESC key
		{
			UpdateDrawFrame();
		}
	#endif

	CloseWindow();

	return 0;
}

void UpdateDrawFrame()
{
	game.Update();
	game.Draw();
}