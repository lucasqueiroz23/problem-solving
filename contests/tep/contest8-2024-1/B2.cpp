#include <bits/stdc++.h>

using namespace std;

double distancia (pair<int, int> a, pair<int, int> b) {
    return sqrt((b.first-a.first)*(b.first-a.first) + (b.second-a.second)*(b.second-a.second));
}

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
    return (a.second < b.second);
}

int main() {

    double maiorDistancia = 0;
    int n;
    cin >> n;
    vector<pair<int, int>> vx, vy;

    while(n--) {
        pair<int, int> p;
        cin >> p.first >> p.second;

        vx.push_back(p);
        vy.push_back(p);
    }

    sort(vx.begin(), vx.end()); // ordenado em x
    sort(vy.begin(), vy.end(), sortbysec); //ordenado em y
    

    maiorDistancia = distancia(vx[0], vx[vx.size() - 1]);
    maiorDistancia = max(maiorDistancia, distancia(vy[0], vy[vy.size() -1]));
    maiorDistancia = max(maiorDistancia, distancia(vy[0], vx[vx.size() -1]));
    maiorDistancia = max(maiorDistancia, distancia(vx[0], vy[vy.size() -1]));

    cout << fixed;
    cout << setprecision(9);
    cout << maiorDistancia;

    cout << "\n";
    
    return 0;
}
