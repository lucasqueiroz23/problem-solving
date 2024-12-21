#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    bool possible = (a == b && b == c);
    possible = possible || ((a+b) == c);
    possible = possible || ((a+c) == b);
    possible = possible || ((b+c) == a);

    if(possible) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
