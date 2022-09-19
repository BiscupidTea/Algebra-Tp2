#include "camera.h"

int main()
{
	//Inicio los limites de la pantalla
	InitWindow(800, 600, "Algebra");
	SetWindowState(FLAG_VSYNC_HINT);
	SetTargetFPS(60);

	//Loop de programa
	while (!WindowShouldClose())
	{
		//valores temporales
		Vector3 a = { 6, 0, 0 };
		Vector3 b = { 0, 10, 0 };
		Vector3 c = { 0, 0, 13 };

		//camera and insert vector 3 
		UserCamera(a, b, c);

	}

	return 0;
}

