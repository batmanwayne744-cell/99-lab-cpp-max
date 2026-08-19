#include<iostream>
using namespace std;

int main()
{
    int n, a[200], b[200];
    int i = 0, j = 0, count = 0;

    cout << "Enter stuffed frame length:";
    cin >> n;

    cout << "Enter stuffed frame bits:";
    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++)
    {
        b[j] = a[i];

        if(a[i] == 1)
            count++;
        else
            count = 0;

        if(count == 5)
        {
            i++;       // Skip the stuffed 0
            count = 0;
        }

        j++;
    }

    cout << "Frame after bit destuffing:";
    for(i = 0; i < j; i++)
        cout << b[i];

    return 0;
}