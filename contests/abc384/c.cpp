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

// now I just need to sort this one out.
// (pun intended)
bool sortFunction(posScore& a, posScore& b) {
    if(a.score == b.score) return a.name < b.name;

    if(a.name.size() < b.name.size()) {
        if(a.name == b.name.substr(0, a.name.size())) {
            return true;
        }
    }

    for(int i = 0; i < min(a.name.size(), b.name.size()); i++) {
        if(!(a.name[i] < b.name[i])) return false;
        for(int j = 0; j < i; j++) {
            if(!(a.name[j] == b.name[j])) {
                return false;
            }
        }
    }

    return true;
}


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


    // ok! found all combinations (subsets). Thanks, professor Edson!
    for(int i = 1; i <= 31; i++) {
        int s = 0;
        string n = "";
        for(int j = 0; j < 5; j++) {
            if (i & (1 << j)) {
                s += m[hash[j]];
                n += hash[j];
            }
        }
        positions.push_back({s, n});
    }

    sort(positions.begin(), positions.end(), sortFunction);
    for(int i = positions.size() - 1; i >= 0; i--) 
        cout << positions[i].name << "\n";

    return 0;
}
