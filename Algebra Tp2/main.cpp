#include <iostream>
#include "raylib.h"
#include "raymath.h"

using namespace std;

struct Vector3Custom {
	Vector3 start;
	Vector3 end;
};

Vector3Custom initVector;
Vector3Custom vector1;
Vector3Custom vector2;
Vector3Custom vector3;

Vector3 Point1;
Vector3 Point2;
Vector3 Point3;

Camera3D MainCamera;

//funcion
float getTriangleArea(float Pa, float Pb, float Pc);
float getDistanceFor(Vector3Custom from, Vector3Custom to);
void getTotArea();
void getBase();

//create vector
void InitVectors();
void CreateVector1();
void CreateVector2();
void CreateVector3();

//core functions
void Loop();
void Update();
void Draw();

int main()
{
	InitWindow(700, 700, "Tp2_Enzo Coletta_Algebra");
	
	MainCamera.position = Vector3{ 0.0f, 10.0f, 20.0f };
	MainCamera.target = Vector3{ 0.0f, 5.0f, 0.0f };
	MainCamera.up = Vector3{ 0.0f, 1.0f, 0.0f };
	MainCamera.fovy = 45.0f;
	MainCamera.projection = CAMERA_PERSPECTIVE;

	SetCameraMode(MainCamera, CAMERA_ORBITAL);
	system("cls");
	InitVectors();

	SetTargetFPS(30);

	while (!WindowShouldClose()) {
		Loop();
	}
	CloseWindow();

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

float getDistanceFor(Vector3 from, Vector3 to)
{
	//pitagoras
	return pow((pow((to.x - from.x), 2) + pow((to.y - from.y), 2) + pow((to.z - from.z), 2)), 0.5);
}

float getTriangleArea(float Pa, float Pb, float Pc) {
	//formula de heron
	float s = ((Pa + Pb + Pc) / 2);
	return sqrt(s * ((s - Pa) * (s - Pb) * (s - Pc)));
}

void getTotArea()
{
	float distance1;
	float distance2;
	float distance3;
	float area1;
	float area2;
	float area3;

	distance1 = getDistanceFor(Point1, Point3);
	distance2 = getDistanceFor(Point3, initVector.start);
	distance3 = getDistanceFor(initVector.start, Point1);
	area1 = getTriangleArea(distance1, distance2, distance3);
	cout << "Triangle 1 lines = (" << distance1 << ")" << "(" << distance2 << ")" << "(" << distance3 << ")" << endl;
	cout << "Area/Face = " << area1 << endl;
	cout << endl;

	distance1 = getDistanceFor(Point1, Point2);
	distance2 = getDistanceFor(Point2, initVector.start);
	distance3 = getDistanceFor(initVector.start, Point1);
	area2 = getTriangleArea(distance1, distance2, distance3);
	cout << "Triangle 2 lines = (" << distance1 << ")" << "(" << distance2 << ")" << "(" << distance3 << ")" << endl;
	cout << "Area/Face = " << area2 << endl;
	cout << endl;

	distance1 = getDistanceFor(Point2, Point3);
	distance2 = getDistanceFor(Point3, initVector.start);
	distance3 = getDistanceFor(initVector.start, Point2);
	area3 = getTriangleArea(distance1, distance2, distance3);
	cout << "Triangle 3 lines = (" << distance1 << ")" << "(" << distance2 << ")" << "(" << distance3 << ")" << endl;
	cout << "Area/Face = " << area3 << endl;
	cout << endl;

	float totArea = area1 + area2 + area3;

	cout << "Total sum of the 3 faces = "<< totArea << endl;
}

void getBase()
{
	if (vector1.end.y < vector2.end.y) {
		Point1 = vector1.end;

		Point2.y = Point1.y;
		Point2.x = (vector2.end.x / vector2.end.y) * Point2.y;
		Point2.z = (vector2.end.z / vector2.end.y) * Point2.y;

		Point3.y = Point1.y;
		Point3.x = (vector3.end.x / vector3.end.y) * Point2.y;
		Point3.z = (vector3.end.z / vector3.end.y) * Point2.y;
	}
	else{
		Point1 = vector2.end;

		Point2.y = Point1.y;
		Point2.x = (vector1.end.x / vector1.end.y) * Point2.y;
		Point2.z = (vector1.end.z / vector1.end.y) * Point2.y;

		Point3.y = Point1.y;
		Point3.x = (vector3.end.x / vector3.end.y) * Point2.y;
		Point3.z = (vector3.end.z / vector3.end.y) * Point2.y;
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void InitVectors()
{
	initVector.start.x = 0;
	initVector.start.y = 0;
	initVector.start.z = 0;

	initVector.end.x = 0;
	initVector.end.y = 0;
	initVector.end.z = 0;

	CreateVector1();
	cout << "Vector A: (X: " << vector1.end.x << ", Y: " << vector1.end.y << ", Z: " << vector1.end.z << ")" << endl;

	CreateVector2();
	cout << "Vector B: (X: " << vector2.end.x << ", Y: " << vector2.end.y << ", Z: " << vector2.end.z << ")" << endl;

	CreateVector3();
	cout << "Vector C: (X: " << vector3.end.x << ", Y: " << vector3.end.y << ", Z: " << vector3.end.z << ")" << endl;
	cout << endl;

	getBase();
	cout << "Point 1: (X: " << Point1.x << ", Y: " << Point1.y << ", Z: " << Point1.z << ")" << endl;
	cout << "Point 2: (X: " << Point2.x << ", Y: " << Point2.y << ", Z: " << Point2.z << ")" << endl;
	cout << "Point 3: (X: " << Point3.x << ", Y: " << Point3.y << ", Z: " << Point3.z << ")" << endl;
}

void CreateVector1()
{
	vector1.start.x = 0;
	vector1.start.y = 0;
	vector1.start.z = 0;
	vector1.end.x = 5;
	vector1.end.y = 2;
	vector1.end.z = -5;
}

void CreateVector2()
{
	vector2.start.x = 0;
	vector2.start.y = 0;
	vector2.start.z = 0;
	vector2.end.x = -vector1.end.y;
	vector2.end.y = vector1.end.x;
	vector2.end.z = vector1.end.z;
}

void CreateVector3()
{
	vector3.end.x = ((vector1.end.y * vector2.end.z) - (vector1.end.z * vector2.end.y));
	vector3.end.y = ((vector1.end.z * vector2.end.x) - (vector1.end.x * vector2.end.z));
	vector3.end.z = ((vector1.end.x * vector2.end.y) - (vector1.end.y * vector2.end.x));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////

void Loop()
{
	Update();
	Draw();
}

void Update()
{
	UpdateCamera(&MainCamera);
}

void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	BeginMode3D(MainCamera);
	DrawGrid(10, 1.0f);

	DrawLine3D(vector1.start, vector1.end, BLUE);
	DrawLine3D(vector2.start, vector2.end, BLUE);
	DrawLine3D(vector3.start, vector3.end, BLUE);

	DrawLine3D(Point1, Point2, YELLOW);
	DrawLine3D(Point2, Point3, YELLOW);
	DrawLine3D(Point3, Point1, YELLOW);

	DrawSphere(Point1, 0.1, RED);
	DrawSphere(Point2, 0.1, RED);
	DrawSphere(Point3, 0.1, RED);

	EndMode3D();
	EndDrawing();
}