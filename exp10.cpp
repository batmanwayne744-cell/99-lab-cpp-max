#include <iostream>
#include <fstream>
using namespace std;

// Driver Code
int main()
{
    // Creation of ofstream class object
    ofstream fout;
    string line;

    // By default ios::out mode automatically deletes
    // the content of the file.
    // To append the content, open in ios::app
    // fout.open("sample.txt", ios::app);

    fout.open("sample.txt");

    // Execute a loop if file successfully opened
    while (fout)
    {
        // Read a line from standard input
        getline(cin, line);

        // Press -1 to exit
        if (line == "-1")
            break;

        // Write line in file
        fout << line << endl;
    }

    // Close the file
    fout.close();

    // Creation of ifstream class object to read the file
    ifstream fin;

    // By default open mode = ios::in mode
    fin.open("sample.txt");

    // Execute a loop until EOF (End of File)
    while (getline(fin, line))
    {
        // Print line (read from file) in console
        cout << line << endl;
    }

    // Close the file
    fin.close();

    return 0;
}