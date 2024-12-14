#include <bits/stdc++.h>

using namespace std;


struct cell {
    int x, y;
};

struct boundaries {
    cell a, b, c, d;
};

boundaries getBoundaries(char** grid, int i, int j, int size, int h, int w) {
    cell a = {size*i - 1, j - size};
    cell b = {size*i - 1, j + size};
    cell c = {size*i + 1, j - size};
    cell d = {size*i - 1, j + size};

    return {a,b,c,d};
}

bool okBoundaries(cell c, int h, int w) {
    return c.x >= 0 && c.x < h && c.y >= 0 && c.y < w;
}

bool isHash(cell c, char** grid) {
    return grid[c.x][c.y] == '#';
}

bool checkBoundaries(boundaries b, int h, int w) {

    if(!okBoundaries(b.a, h, w)) return false;
    if(!okBoundaries(b.b, h, w)) return false;
    if(!okBoundaries(b.c, h, w)) return false;
    if(!okBoundaries(b.d, h, w)) return false;

    return true;
}

bool isCross(char grid[][], int i, int j, int size, int h, int w) {
    boundaries b = getBoundaries(grid, i, j, size, h, w);
    if(!checkBoundaries(b, h, w)) return false;
    if(
        isHash(b.a, grid) &&
        isHash(b.b, grid) &&
        isHash(b.c, grid) &&
        isHash(b.d, grid) 
    ) return true;

    return false;
}

int main() {
    int h, w;
    cin >> h >> w;

    int m = min(h,w);

    vector<int> s;

    char grid[h][w];
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }

    int size = 1;

    for(int k = 0; k < m; k++) {
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++) {
                bool isC = isCross(grid, i, j, size, h, w);
            }
        }
    }


    return 0;
}
