#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

void solve(vector<int> v) {
    int m = INT_MAX;
    int a = v[0];
    int b = v[1];

    for(int c = 0; c <= b; c++) {
        int val = (c-a) + (b-c);
        m = min(val, m);
    }

    cout << m << "\n";
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        vector<int> v;
        int a, b;

        cin >> a >> b;
        v.push_back(a);
        v.push_back(b);

        sort(v.begin(), v.end());

        solve(v);

    }

    return 0;
}
