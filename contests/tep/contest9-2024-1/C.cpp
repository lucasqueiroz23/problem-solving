#include <bits/stdc++.h>

//0 4 5 2024072928 32767 -1029696912 21924 

using namespace std;

int main() {
    int n, x;

    cin >> n >> x;

    int N = n;

    int size = (int) pow(2, n + 1);

    int tree[size];
    for(int i = 0; i < size; i++) tree[i] = -1;

    tree[0] = 0;

    int i = 0;
    int level = 0;

    while(n--) {

        int a, b;

        cin >> a >> b;

        int nodes = (int) pow(2, level);

        while(nodes) {


            int j = 2 * i + 1;
            int k = 2 * i + 2;
            if(i >= size || j>=size || k>=size) return 0;

            tree[j] = a + tree[i];
            tree[k] = b + tree[i];

            i++;

            if(level == N - 1) {

                if(tree[j] == x || tree[k] == x){
                    cout << "Yes\n";
                    return 0;
                }
            }

            nodes--;
        }

        level++;
    }
    cout <<"No\n";


    return 0;
}
