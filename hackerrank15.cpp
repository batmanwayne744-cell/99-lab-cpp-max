#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    map<string, int> m;

    while (q--) {
        int type;
        string name;

        cin >> type >> name;

        if (type == 1) {
            int marks;
            cin >> marks;
            m[name] += marks;
        }

        else if (type == 2)
            m.erase(name);

        else
            cout << m[name] << endl;
    }

    return 0;
}