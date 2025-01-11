#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    map<int,vector<int>> recebe;

    while(n--) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i = 0; i < v.size(); i++) {
        int max = v[i] + recebe[i].size();
        int j = i + 1;
        int x = max;
        while(x--) {
            recebe[j++].push_back(i);
        }
    }

    for(int i = 0; i < v.size(); i++) {
        v[i] += recebe[i].size();
        for(auto x : recebe[i]) {
            v[x]--;
        }
    }

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << "\n";


    return 0;
}
