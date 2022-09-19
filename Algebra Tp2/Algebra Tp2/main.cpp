#include "camera.h"

int main()
{
	//Inicio los limites de la pantalla
	InitWindow(800, 600, "Algebra");
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);
	UserCamera();

	//Loop de programa
	while (!WindowShouldClose())
	{

		UserCamera();

	}

	return 0;
}

