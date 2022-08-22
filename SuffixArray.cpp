#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    //n log^2(n) algorithm, O(nlogn) space
    string s; cin >> s;
    
    s += '$';
    int n = s.length();
    vector<int> p(n), c(n);
    {
        vector<pair<char, int>> a(n); // array used to sort, but kept local so can be reused later on for differnt purpose
        for (int i = 0; i < n; i++) {
            a[i] = make_pair(s[i], i);
        }
        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        //builds the ordering, in the sorted order, if two elements are not the same, then you increase the assigned number by 1
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }

    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++) {
            //splits the segment i to (i + 2^k modulus n) into halves. (each half is assigned the number in vector c)
            a[i] = make_pair(make_pair(c[i], c[(i + (1 << k)) % n]), i);
        }
        sort(a.begin(), a.end());
        //defining the order
        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        //redefining the number assignments
        c[p[0]] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        k++;
    }

    for (int i = 0; i < n; i++) {
        cout << s.substr(p[i], n - p[i]) << '\n';
    }

}