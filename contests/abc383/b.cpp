#include <bits/stdc++.h>

using namespace std;

bool manhattan(pair<int, int> pos1, pair<int,int> pos2, int d) {
    return (abs(pos1.first - pos2.first) + abs(pos1.second - pos2.second)) <= d;
}

int main() {
    int h,w,d;
    cin >> h >> w >> d;

    vector<pair<int, int>> posFloors;

    for(int i = 1; i <= h; i++) {
        string cell;
        cin >> cell;

        for(int j = 0; j < w; j++) {
            if(cell[j] == '.') 
                posFloors.push_back({i, j + 1});
        }
    }

    int max = 0;
    for(int i = 0; i < posFloors.size(); i++) {
        for(int j = i + 1; j < posFloors.size(); j++) {

            pair<int, int> selected1 = posFloors[i];
            pair<int, int> selected2 = posFloors[j];
            int sum = 2;

            for(int k = 0; k < posFloors.size(); k++) {
                if(k == i || k == j) continue;

                if(manhattan(selected1, posFloors[k], d)) {
                    sum++;
                    continue;
                }
                if(manhattan(selected2, posFloors[k], d)) sum++;
            }

            if(sum > max) {
                max = sum;
            }
        }
    }

    cout << max << "\n";

    return 0;
}
