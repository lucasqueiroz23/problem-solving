#include <bits/stdc++.h>

using namespace std;

int getsums(int *sums, int *arr, int pos) {
  if (pos == 0 || sums[pos] != 0)
    return sums[pos];

  sums[pos] = arr[pos] + getsums(sums, arr, pos - 1);
  return sums[pos];
}

void solve(int n, int q) {
  int arr[n];
  int sums[n];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sums[i] = 0;
  }

  sums[0] = arr[0];

  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;

    int ksum = (r - l + 1) * k; 

    l--;
    r--;

    int lsum = l - 1 >= 0 ? getsums(sums, arr, l - 1) : 0;
    int rsum = getsums(sums, arr, n - 1) - getsums(sums, arr, r);


    if ((lsum + ksum + rsum) % 2 == 0)
      cout << "NO\n";
    else
      cout << "YES\n";

  }
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    int n, q;
    cin >> n >> q;
    solve(n, q);
  }

  return 0;
}
