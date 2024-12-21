#include <bits/stdc++.h>

using namespace std;

int h, w;

pair<int, int> next(char c, int i, int j) {
    switch(c) {
        case 'U': 
            return {i - 1, j};
        case 'D': 
            return {i + 1, j};
        case 'L': 
            return {i, j-1};
        case 'R': 
            return {i, j+1};
        default:
            return {i,j};
    }
}

bool inbounds(pair<int, int> next) {
    if(!(next.first >= 0  && next.first < h))
        return false;

    if(!(next.second >= 0  && next.second < w))
        return false;

    return true;
}


int main() {
    int x, y;
    cin >> h >> w >> x >> y;

    char m[h][w];

    x--;y--;
    pair<int, int> pos = {x,y};

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> m[i][j];
        }
    }
    string t;
    cin >> t;

    int count = 0;
    pair<int, int> n = {x,y};

    map<pair<int,int>, bool> visited;

    for(int i = 0; i < t.size(); i++) {
        pair<int, int> thisPos = n;
        n = next(t[i], n.first, n.second);

        if(inbounds(n) && m[n.first][n.second] != '#') {
            if(m[n.first][n.second] == '@' && !visited[n]) {
                visited[n] = true;
                count++;
            }
        } else n = thisPos;
    }

    cout << n.first + 1 << " " << n.second + 1 << " " << count << "\n";

    return 0;
}
