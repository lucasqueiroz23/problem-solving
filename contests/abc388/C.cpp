#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> array, int targetValue, int leftIndex, int rightIndex) {

        if(array[leftIndex] >= targetValue) return leftIndex;

        while(leftIndex < rightIndex - 1)
        {
                int middleIndex = (leftIndex + rightIndex)/2;

                if(array[middleIndex] >= targetValue) return middleIndex;
                leftIndex = middleIndex;
        }
        
        if(array[rightIndex] >= targetValue) return rightIndex;

        return -1;
}

void solve(vector<int> v) {
    int count = 0;

    for(int i = 0; i < v.size(); i++) {

        int x = 2 * v[i];
        int increment = 0;

        int pos = binarySearch(v, x, i + 1, v.size() - 1);
        if(pos == -1) break;

        int pos2 = binarySearch(v, x, i + 1, pos);
        if(pos2 != pos) pos = pos2;

        while(pos - 1 >= 0 && v[pos - 1] >= x) 
            pos--;

        increment = v.size() - pos;
        count += increment;

        while(v[i + 1] == v[i]) {
            count += increment;
            i++;
        }
    }

    cout << count << "\n";
}

int main() {
    int n;
    cin >> n;
    vector<int> v;

    while(n--) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    solve(v);

    return 0;
}
