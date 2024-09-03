#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b;

    cin >> a >> b;

    a--;
    b--;

    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    if(v[b] == 10) {
        if(a == 0 || a == 8) cout << "Yes\n"; 
        else cout <<"No\n";

        return 0;
    }
    if(v[a] == v[b] - 1) {
        cout << "Yes\n";
    } else cout << "No\n";

    return 0;
}
