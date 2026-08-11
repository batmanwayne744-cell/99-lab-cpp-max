
#include <iostream>

int main() {
    float radius, area, circumference;
    const float PI = 3.14159;

    printf("Enter radius of circle: ");
    scanf("%f", &radius);

    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    printf("Area of circle = %.2f\n", area);
    printf("Circumference of circle = %.2f\n", circumference);

    return 0;
}

