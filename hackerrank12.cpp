#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int x, l, r;
    cin >> x;
    cin >> l >> r;

    a.erase(a.begin() + x - 1);

    a.erase(a.begin() + l - 1,
            a.begin() + r - 1);

    cout << a.size() << endl;

    for (int v : a)
        cout << v << " ";

    return 0;
}