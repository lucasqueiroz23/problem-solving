#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum, last, delay;
    last = sum = delay = 0;
    int n;
    cin >> n;

    int t,v;
    cin >> t >> v;
    n--;

    sum += v;
    last = t;

    while(n--) {
        cin >> t >> v;
        delay = t - last;
        last = t;

        sum -= delay;
        if(sum < 0) sum = 0;
        sum += v;
    }


    cout << sum << "\n";
    return 0;
}
