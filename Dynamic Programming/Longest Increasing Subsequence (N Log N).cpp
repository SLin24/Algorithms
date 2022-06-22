#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> sequence;
    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        if (sequence.empty() || arr[i] > *sequence.rbegin()) {
            sequence.push_back(arr[i]);
        } else {
            int it = lower_bound(sequence.begin(), sequence.end() ,arr[i]) - sequence.begin();
            sequence[it] = arr[i];
        }
    }
    cout << sequence.size() << '\n';
}
