#include <stdio.h>

int main() {
    int choice;
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    do {
        printf("\n--- MENU ---\n");
        printf("1. Addition\n");
        printf("2. Sum\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Addition = %d\n", a + b);
                break;

            case 2:
                printf("Sum = %d\n", a + b);
                break;

            case 3:
                printf("Multiplication = %d\n", a * b);
                break;

            case 4:
                if (b != 0)
                    printf("Division = %.2f\n", (float)a / b);
                else
                    printf("Division by zero is not possible.\n");
                break;

            case 5:
                if (b != 0)
                    printf("Modulus = %d\n", a % b);
                else
                    printf("Modulus by zero is not possible.\n");
                break;

            case 6:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}