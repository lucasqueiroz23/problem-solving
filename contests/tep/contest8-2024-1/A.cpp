#include <bits/stdc++.h>

using namespace std;

long long foo(int t) { return t * t + 2 * t + 3; }

int main() {
    int t;
    cin >> t;

    cout << foo(foo(foo(t) + t) + foo(foo(t))) << "\n";
    
    return 0;
}
