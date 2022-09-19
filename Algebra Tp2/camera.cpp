#include "camera.h"

void UserCamera()
{

	Camera3D camera = { 0 };
	camera.position = Vector3{ 10.0f, 10.0f, 10.0f }; // Camera position
	camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                              // Camera field-of-view Y
	camera.projection = CAMERA_PERSPECTIVE;           // Camera mode type

	Vector3 cubePosition = { 0.0f, 1.0f, 0.0f };

	SetCameraMode(camera, CAMERA_ORBITAL);

	bool camerafreeze = false;

	while (!WindowShouldClose())        // Detect window close button or ESC key
	{

		cout << "(" << camera.position.x << ") (" << camera.position.y << ") (" << camera.position.z << ")" << endl;

		if (IsKeyPressed(KEY_SPACE))
		{
			if (camerafreeze == false)
			{
				camerafreeze = true;
			}
			else
			{
				camerafreeze = false;
			}
		}

		if (camerafreeze == false)
		{
			UpdateCamera(&camera);
		}

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);

		DrawCube(cubePosition, 1.0f, 1.0f, 1.0f, RED);
		DrawCubeWires(cubePosition, 1.0f, 1.0f, 1.0f, MAROON);

		DrawGrid(10, 1.0f);

		EndMode3D();

		EndDrawing();
	}
}