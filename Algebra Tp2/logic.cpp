#include "raylib.h"
#include "logic.h"
#include "raymath.h"
#include <algorithm>
#include <iostream>

struct VectorUser
{
    Vector2 startPos = { 0,0 };
    Vector2 endPos = { 0,0 };
    float rotation = 0;
} vectorUser, vectorUser2, vectorUser3;

const int screenWidth = 1000;
const int screenHeight = 450;

const int initX = screenWidth / 2;
const int initY = screenHeight / 2;

float variableUSerX = 100;
float variableUSerY = -150;

void draw();
void calculateArea();
VectorUser copyOn90(VectorUser);
float calculateMinVectorHeigth();
float getRadiansFromDegrees(int);
float getCentimeterFromPixel(float);
VectorUser createVector3(VectorUser);

int executeProgram()
{
	InitWindow(screenWidth, screenHeight, "Algebra");
    SetWindowState(FLAG_VSYNC_HINT);

    /*cout << "Ingrese x: ";
    cin >> variableUSerX;
    cout << "Ingrese y: ";
    cin >> variableUSerY;*/

	while (!WindowShouldClose())
	{
        vectorUser.startPos = {initX, initY};
        vectorUser.endPos = {initX + variableUSerX, initY + variableUSerY};

        copyOn90(vectorUser);
        
        createVector3(vectorUser);

        draw();

        calculateArea();

        /*cout << vectorUser.endPos.x << "  " << vectorUser.endPos.y << " Vector 1" << endl;
        cout << vectorUser2.endPos.x << "  " << vectorUser2.endPos.y << " Vector 2" << endl;
        cout << vectorUser3.endPos.x << "  " << vectorUser3.endPos.y << " Vector 3" << endl;*/

	}
	CloseWindow();

	return 0;
}

void draw()
{
    BeginDrawing();
    ClearBackground(BLACK);

    DrawLine(vectorUser.startPos.x, vectorUser.startPos.y, vectorUser.endPos.x, vectorUser.endPos.y, WHITE);
    DrawLine(vectorUser2.startPos.x, vectorUser2.startPos.y, vectorUser2.endPos.x, vectorUser2.endPos.y, WHITE);
    DrawLine(vectorUser3.startPos.x, vectorUser3.startPos.y, vectorUser3.endPos.x, vectorUser3.endPos.y, WHITE);

    //Base de piramede
    float yPos = calculateMinVectorHeigth();
    DrawLine(vectorUser.endPos.x, yPos, vectorUser2.endPos.x, yPos, RED);

    EndDrawing();
};

void calculateArea()
{
    float largeVector1 = Vector2Distance(vectorUser.startPos, vectorUser.endPos);
    float largeVector2 = Vector2Distance(vectorUser2.startPos, vectorUser2.endPos);

    /*cout << largeVector1 << " Vector 1" << endl;
    cout << largeVector2 << " Vector 2" << endl;*/

    float area = largeVector1 * largeVector2 / 2;

    /*cout << area << " area" << endl;

    cout << getCentimeterFromPixel(area) << " centimetro" << endl;*/

    float centimeter1 = getCentimeterFromPixel(area);
    int centimeter2 = getCentimeterFromPixel(area);

    DrawText(TextFormat("El area es: %02f cm", centimeter1), 10, 370, 20, WHITE);
    DrawText(TextFormat("El area redondeada es: %02i cm", centimeter2), 10, 400, 20, WHITE);
}

VectorUser copyOn90(VectorUser vectorUser)
{
    int newRotation = vectorUser.rotation + 90;

    vectorUser2.startPos = vectorUser.startPos;

    float angle = getRadiansFromDegrees(90);

    Vector2 newEndPos = {variableUSerX , variableUSerY};
    vectorUser2.endPos = Vector2Rotate(newEndPos, angle);


    if (newRotation > 360) {
        newRotation = newRotation - 360;
    }

    vectorUser2.rotation = newRotation;

    return vectorUser2;
}

float calculateMinVectorHeigth()
{
    float minValue = max(vectorUser.endPos.y, vectorUser2.endPos.y);

    return  minValue;
}

float getRadiansFromDegrees(int degrees)
{
    return (degrees * PI_DEFINES) / 180;
}

float getCentimeterFromPixel(float pixel)
{
    return (pixel * CENTIMETER_DEFINES);
}

//Angulo de diferencia entre dos vectores
VectorUser createVector3(VectorUser vectorUser) 
{
    Vector2 newEndPos = { variableUSerX , variableUSerY };

    float angleDiff = getRadiansFromDegrees(45);

    vectorUser3.startPos = vectorUser.startPos;

    vectorUser3.endPos = Vector2Rotate(newEndPos, angleDiff);

    vectorUser3.rotation = angleDiff;

    return vectorUser3;
}