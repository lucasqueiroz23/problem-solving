#include <bits/stdc++.h>

using namespace std;

double distancia (pair<int, int> a, pair<int, int> b) {
    return sqrt((b.first-a.first)*(b.first-a.first) + (b.second-a.second)*(b.second-a.second));
}

int main() {

    pair<int, int> esq = {1001, -1001};
    pair<int, int> dir = {-1001, -1001};
    pair<int, int> cima = {-1001, -1001};
    pair<int, int> baixo = {-1001, 1001};

    int n;
    cin >> n;

    while(n--) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        
        esq = p.first < esq.first ? p : esq;
        dir = p.first > dir.first ? p : dir;
        baixo = p.second < baixo.second ? p : baixo;
        cima = p.second > cima.second ? p : cima;
    }

    double maiorDistancia = -1;

    vector<pair<int,int>> v = {esq, dir, cima, baixo};

    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            maiorDistancia = max(maiorDistancia, distancia(v[i], v[j]));
        }
    }

    cout << fixed;
    cout << setprecision(9);
    cout << maiorDistancia;

    cout << "\n";
    
    return 0;
}
