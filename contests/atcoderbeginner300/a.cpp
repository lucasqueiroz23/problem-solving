#include <bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;
    
    int a, b;
    cin >> a >> b;

    int i = 1;
    while(n--) {
        int c;
        cin >> c;
        if ((a+b) == c) {
            cout << i << "\n";
            break;
        }
        i++;
    }

    return 0;
}
