#include <bits/stdc++.h>

using namespace std;

double distancia (pair<int, int> a, pair<int, int> b) {
    return sqrt((b.first-a.first)*(b.first-a.first) + (b.second-a.second)*(b.second-a.second));
}


int main() {

    double maiorDistancia = 0;
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    while(n--) {
        pair<int, int> p;
        cin >> p.first >> p.second;

        v.push_back(p);
    }

    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            maiorDistancia = max(maiorDistancia, distancia(v[i], v[j]));
        }
    }

    cout << fixed;
    cout << setprecision(9);
    cout << maiorDistancia;

    cout << "\n";
    
    return 0;
}
