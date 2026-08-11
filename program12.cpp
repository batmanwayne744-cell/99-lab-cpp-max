#include <iostream>
using namespace std;

int main()
{
    int *arr;
    int size;

    cout << "Enter the size of array: ";
    cin >> size;

    cout << "Creating array..." << endl;
    arr = new int[size];

    cout << "Enter values of array:" << endl;

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Display array:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << " " << arr[i];
    }

    delete[] arr;   // Free dynamically allocated memory

    return 0;
}