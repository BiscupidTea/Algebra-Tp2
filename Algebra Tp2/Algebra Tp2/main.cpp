#include <iostream>
#include <cmath>

using namespace std;

struct Vector3Custom {
    float x = 0.0;
    float y = 0.0;
    float z = 0.0;
};

Vector3Custom initVector = { 0.0, 0.0, 0.0 };
Vector3Custom vector1 = { 10.0, 12.0, -4.0 };
Vector3Custom vector2 = { 0.0, 0.0, 0.0 };
Vector3Custom vector3 = { 0.0, 0.0, 0.0 };

void printVectorCoordinates(Vector3Custom vector) {
    cout << " (" << vector.x << ", " << vector.y << ", " << vector.z << ")" << endl;
}

/*
    Producto punto
    (https://www.youtube.com/watch?v=pSj_Cgk80Do)

    Que un vector en r3 sea perpendicular a otro, significa que su producto vectorial sea igual a 0
    Ej:
        - v1 = (-2, 1, 4)
        - v2 = (x, y, z) // tengo 3 incognitas e infinitas soluciones

    Para obtener un único vector tengo que acotar las posibilidades
    Entonces podemos hacer un cálculo más fácil, tomar del vector de referencia X e Y
    invertirlas y cambiarle el signo a una. dejamos Z en 0
*/

void calculateVectorAt90Degrees(Vector3Custom referenceVector, Vector3Custom* vectorToCalculate) {
    *vectorToCalculate = { referenceVector.y, referenceVector.x * (-1), 0 };
}

/*
    Producto cruz / vectorial / de Gibbs
    (https://www.youtube.com/watch?v=57dX3R6Sa9c)

    Dice que dado dos vectores en r3, se puede obtener un tercero perpendicular a ambos
    Para esto se puede utilizar una fórmula más compleja, pero vamos a ir con una más fácil
    Ej:
        - v1 = (-3, 2, -2)
        - v2 = (8, -3, 5)

        ->         ->
        v1    x    v2
      | -3 |     |  8 |     | (2 * 5)   - (-2 * -3) |   |  4 |
      |  2 |  X  | -3 |  =  | (-2 * 8)  - (-3 * 5)  | = | -1 |
      | -2 |     |  5 |     | (-3 * -3) - (2 * 8)   |   | -7 |
*/

void calculateCrossProduct(Vector3Custom vectorA, Vector3Custom vectorB, Vector3Custom* productVector) {
    float valueOnX = 0.0;
    float valueOnY = 0.0;
    float valueOnZ = 0.0;

    valueOnX = vectorA.y * vectorB.z - vectorA.z * vectorB.y;
    valueOnY = vectorA.z * vectorB.x - vectorA.x * vectorB.z;
    valueOnZ = vectorA.x * vectorB.y - vectorA.y * vectorB.x;

    *productVector = { valueOnX, valueOnY, valueOnZ };
}

/*
    Cálculo de distancia de un vector en r3

    d = sqrt((x1 - x2)^2 + (y1 - y2)^2 + (z1 - z2)^2)
*/
float calculateDistanceFor(Vector3Custom from, Vector3Custom to) 
{
    return sqrt(pow(to.x - from.x, 2) + pow(to.y - from.y, 2) + pow(to.z - from.z, 2));
}

Vector3Custom getProductVector(Vector3Custom vectorA, Vector3Custom vectorB) 
{
    return { vectorB.x - vectorA.x, vectorB.y - vectorA.y, vectorB.z - vectorA.z };
};

/*
  Calculo el area de un triangulo
   (sqrt(x^2 + y^2 + z^2))/2
*/
float getTriangleArea(Vector3Custom resultVector) {
    return (sqrt(pow(resultVector.x, 2) + pow(resultVector.y, 2) + pow(resultVector.z, 2))) / 2;
}

int main() 
{
    char userOption = ' ';

    cout << "Desea ingresar su propio vector?" << endl;
    cout << "               Y/N              " << endl;

    cin >> userOption;
    system("cls");
    
    while (userOption != 'y' && userOption != 'n')
    {
        cout << "Desea ingresar su propio vector?" << endl;
        cout << "               Y/N              " << endl;

        cin >> userOption;

        system("cls");
    };
    
    if (userOption == 'y')
    {
        cout << "Ingrese la Posicion del Vector en 'X': ";
        cin >> vector1.x;

        system("cls");

        cout << "Ingrese la Posicion del Vector en 'Y': ";
        cin >> vector1.y;

        system("cls");

        cout << "Ingrese la Posicion del Vector en 'Z': ";
        cin >> vector1.z;

        system("cls");
    }

    cout << "Init vector: ";
    printVectorCoordinates(initVector);

    cout << "Vector1: ";
    printVectorCoordinates(vector1);
    cout << "Vector2 pre calculo: ";
    printVectorCoordinates(vector2);

    calculateVectorAt90Degrees(vector1, &vector2);
    cout << "Vector2 post calculo: ";
    printVectorCoordinates(vector2);


    cout << "Vector3 pre calculo: ";
    printVectorCoordinates(vector3);

    calculateCrossProduct(vector1, vector2, &vector3);
    cout << "Vector3 post calculo: ";
    printVectorCoordinates(vector3);


    float d1 = calculateDistanceFor(initVector, vector1);
    float d2 = calculateDistanceFor(initVector, vector2);
    float d3 = calculateDistanceFor(initVector, vector3);

    cout << "Distancia 1: " << d1 << endl;
    cout << "Distancia 2: " << d2 << endl;
    cout << "Distancia 3: " << d3 << endl;

    // AB
    Vector3Custom productInitVector1 = getProductVector(initVector, vector1);

    // AC
    Vector3Custom productInitVector2 = getProductVector(initVector, vector2);

    // AD
    Vector3Custom productInitVector3 = getProductVector(initVector, vector3);

    //Obtengo producto cruz para calcular el area de esa cara
    Vector3Custom crossProductSideA;
    Vector3Custom crossProductSideB;
    Vector3Custom crossProductSideC;

    calculateCrossProduct(productInitVector1, productInitVector2, &crossProductSideA);
    calculateCrossProduct(productInitVector1, productInitVector3, &crossProductSideB);
    calculateCrossProduct(productInitVector2, productInitVector3, &crossProductSideC);

    //aca podrias imprimir el vector resultante

    float areaSideA = getTriangleArea(crossProductSideA);
    cout << "El area de la primer cara es: " << areaSideA << endl;

    float areaSideB = getTriangleArea(crossProductSideB);
    cout << "El area de la segunda cara es: " << areaSideB << endl;

    float areaSideC = getTriangleArea(crossProductSideC);
    cout << "El area de la tercer cara es: " << areaSideC << endl << endl;

    float sumOfTheThreeSides = areaSideA + areaSideB + areaSideC;

    cout << "Sumatoria de las tres caras externas --> " << sumOfTheThreeSides << endl;

    return 0;
}