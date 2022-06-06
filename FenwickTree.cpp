#include <bits/stdc++.h>
#include <iostream>
 
using namespace std;
typedef long long ll;
 
 
 
ll getLeading(ll num) {
    return (1 << __builtin_ctz(num));
}
 
//inclusive boundaries
void sum(ll l, ll r, const ll tree[]) {
    l--;
    ll sum1 = 0;
    ll sum2 = 0;
    while (r != 0) {
        sum1 += tree[r];
        r -= getLeading(r);
    }
    while (l != 0) {
        sum2 += tree[l];
        l -= getLeading(l);
    }
    cout << sum1 - sum2 << '\n';
} 
 
void update(ll index, ll tree[], ll newVal, const vector<ll>& arr) {
    ll val = arr[index - 1];   
    while (index <= arr.size()) {
        tree[index] -= val;
        tree[index] += newVal;
        index += (index & (-1 * index));
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin >> n;
    ll m; cin >> m;
 
    vector<ll> arr;
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        arr.push_back(num);
    }
    
    ll pref[n + 1]{};
 
    for (ll i = 1; i < n + 1; i++) {
        pref[i] += pref[i - 1] + arr[i - 1];
    }
    ll tree[n + 1]{};
 
    for (ll i = 1; i < n + 1; i++) {
        ll length = getLeading(i);
        tree[i] = pref[i] - pref[i - length];
    }
 
 
    for (ll i = 0; i < m; i++) {
        bool up = 0;
        ll val;
        cin >> val;
        val %= 2;
        up = val;
        if (up) {
            ll index, newVal;
            cin >> index >> newVal;
            ll temp = index;
            update(index, tree, newVal, arr);
            arr[temp - 1] = newVal;
        } else {
            ll l, r;
            cin >> l >> r;
            sum(l, r, tree);
        }
    }
 
    
 
 
}