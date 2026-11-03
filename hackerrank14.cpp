#include <bits/stdc++.h>
using namespace std;

int main() {
    int q;
    cin >> q;

    set<int> s;

    while (q--) {
        int type, x;
        cin >> type >> x;

        if (type == 1)
            s.insert(x);

        else if (type == 2)
            s.erase(x);

        else {
            if (s.count(x))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}