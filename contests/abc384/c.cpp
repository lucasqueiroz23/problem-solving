// idea: find all possible combinations of the chars a, b, c, d and e. 
// then, fill an array with the scores of each combination.
// sort the array by value and, if there is a tie, untie with the lexical order.
// finally, print the array backwards.

// my problem was finding all possible combinations. couldn't do it.

#include <bits/stdc++.h>

using namespace std;

struct posScore {
    int score;
    string name;
};


int main() {
    vector<int> scores;
    string hash = "ABCDE";
    vector<posScore> positions;

    map<char, int> m;
    int n;

    for(int i = 0; i < 5; i++) {
        cin >> n;
        scores.push_back(n);
        m[hash[i]] = n;
    }


    for(int i = 0; i < hash.size(); i++) {
        string str = "";
        str += hash[i];
        cout << str << "\n";

        for(int j = i + 1; j < hash.size(); j++) {
            string str2 = str + hash[j];
            cout << str2 << "\n";

            for(int k = j + 1; k < hash.size(); k++) {

            }
        }
    }


    return 0;
}
