#include <iostream>
 
using namespace std;
 
int main() {
    int t = 0;
    cin >> t;
    int cp = 1, ca = 0;
    while(cp<=5){
        int ans = 0;
        cin >> ans;
        if(ans == t)
            ca++;
        cp++;
    }
    cout << ca << "\n";
    return 0;
}
