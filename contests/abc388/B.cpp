#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, d;
    cin >> n >> d;

    vector<pair<int,int>> snakes;

    while(n--) {
        int t, l;
        cin >> t >> l;
        snakes.push_back({t, l});
    }

    for(int i = 1; i <= d; i++) {
        int biggest = 0;

        for(auto s : snakes) {
            if(biggest < (s.first * (s.second + i)))
               biggest = s.first * (s.second+i);
        }
        cout << biggest << "\n";
    }

    return 0;
}
