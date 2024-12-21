#include <bits/stdc++.h>

using namespace std;

int getMaxBuildings(vector<int> v) {
    int limit = *(v.end() - 1) - *v.begin();
    int count = 1;

    for(int i = 0; i < v.size(); i++) {
        int nc = 1;
        int k = v[i];

        for(int j = 1; j <= limit; j++) {
            while(binary_search(v.begin(), v.end(), k + j)) {
                k += j;
                nc++;
            } 
            count = max(nc, count);
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    map<int, vector<int>> m;

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        m[x].push_back(i);
    }

    int ans = 0;
    for (const auto& [key, value] : m) {
        ans = max(ans, getMaxBuildings(value));
    }

    cout << ans << "\n";

    return 0;
}
