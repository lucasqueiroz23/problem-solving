#include <bits/stdc++.h>


using namespace std;

void solve(int x, int y, int k) { 
    int count = 0;

    int goal[2] = {x, y};
    int pos[2] = {0, 0};

    int i = 0;

    while(pos[0] != x || pos[1] != y) {

        if(pos[i] != goal[i]) {

            int d = pos[i] + k > goal[i] ? goal[i] - pos[i] : k;
            pos[i] += d;

            count++;
        } else count++;


        i++;
        i = i % 2;
    }

    cout << count << "\n";
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        int x, y, k;
        cin >> x >> y >> k;
        solve(x, y, k);
    }

    return 0;
}

