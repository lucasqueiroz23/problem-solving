#include <bits/stdc++.h>

using namespace std;

void solve(int n) {
    vector<int> ans;

    while(n--) {

        string b;
        cin >> b;

        for(int i = 0; i < 4; i++) {
            if(b[i] == '#') {
                ans.push_back(i + 1);
                break;
            }
        }
    }

    int l = ans.size() - 1;
    for(int i = l; i >= 0 ; i--) {
        cout << ans[i] << " ";
    }
    cout <<"\n";
}

int main() {

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}
