#include <iostream>
using namespace std;

// Function prototypes
int area(int);
int area(int, int);
float area(float);

int main()
{
    cout << "Area of square = " << area(5) << endl;

    cout << "Area of rectangle = " << area(5, 10) << endl;

    cout << "Area of circle = " << area(5.5f) << endl;

    return 0;
}

// Area of square
int area(int side)
{
    return side * side;
}

// Area of rectangle
int area(int length, int breadth)
{
    return length * breadth;
}

// Area of circle
float area(float radius)
{
    return 3.14f * radius * radius;
}