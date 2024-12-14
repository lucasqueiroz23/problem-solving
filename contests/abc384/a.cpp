#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;


    char c1, c2;
    cin >> c1 >> c2;

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++) {
        if(s[i] != c1) s[i] = c2;
    }


    cout << s << "\n";

    return 0;
}
