#include "camera.h"

void UserCamera(Vector3 Endline1, Vector3 Endline2, Vector3 Endline3)
{

	Camera3D camera = { 0 };
	camera.position = Vector3{ 10.0f, 10.0f, 10.0f }; // Camera position
	camera.target = Vector3{ 0.0f, 0.0f, 0.0f };      // Camera looking at point
	camera.up = Vector3{ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
	camera.fovy = 45.0f;                              // Camera field-of-view Y
	camera.projection = CAMERA_PERSPECTIVE;           // Camera mode type

	Vector3 spherePosition = { 0.0f, 0.0f, 0.0f };

	SetCameraMode(camera, CAMERA_ORBITAL);

	bool camerafreeze = false;

	while (!WindowShouldClose())        // Detect window close button or ESC key
	{

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

	//draw 2d
		DrawRectangle(0, 0, 300, 100, SKYBLUE);
		DrawText("Press SPACE to stop the rotation", 15, 15, 15, BLACK);

	//draw 3d
		BeginMode3D(camera);
		//main lines
		DrawLine3D(spherePosition, Endline1, BLUE);
		DrawLine3D(spherePosition, Endline2, RED);
		DrawLine3D(spherePosition, Endline3, GREEN);
		//union lines
		DrawLine3D(Endline1, Endline2, BLUE);
		DrawLine3D(Endline1, Endline3, RED);
		DrawLine3D(Endline2, Endline3, GREEN);
		//grid
		DrawGrid(50, 1.0f);
		EndMode3D();

		EndDrawing();
	}
}