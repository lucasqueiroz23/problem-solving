#include <bits/stdc++.h>

using namespace std;

struct CharCount {
    int point;
    int hash;
};

bool equalCount(CharCount a, CharCount b) {
    if(a.hash != b.hash || a.point != b.point) return false;
    return true;
}

int main() {
    int h, w;
    cin >> h >> w;

    CharCount countA = {0,0}, countB = {0,0};

    vector<CharCount> histA;
    vector<CharCount> histB;


    for(int i = 0; i < h; i++) {
        int countPoint = 0;
        int countHash = 0;

        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if(c == '.') {
                countA.point++;
                countPoint++;
            } else {
                countA.hash++;
                countHash++;
            }
        }
        histA.push_back({countPoint, countHash});
    }

    for(int i = 0; i < h; i++) {
        int countPoint = 0;
        int countHash = 0;

        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            if(c == '.') {
                countB.point++;
                countPoint++;
            } else {
                countB.hash++;
                countHash++;
            }
        }
        histB.push_back({countPoint, countHash});
    }

    if(!equalCount(countB, countA)){
        cout << "No\n";
        return 0;
    }

    vector<int> visited;

    for(int i = 0; i < histA.size(); i++) {
        int count = visited.size();
        for(int j = 0; j < histB.size(); j++) {
            bool visitedPos = false;

            for(auto pos : visited) {
                if(pos == j) {
                    visitedPos = true;
                    break;
                }
            }
            if(visitedPos) continue;

            if(equalCount(histA[i], histB[j])) {
                visited.push_back(j);
                break;
            }
        }
        if(count == visited.size())
            break;
    }


    visited.size() == h ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
