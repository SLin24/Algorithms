#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, match; cin >> s >> match;
    int n = match.length();
    int psTable[n + 1]{}; //prefix suffix table. First index is left as 0 and it is 1 indexed. For each index, it counts the longest suffix of the string that is also the prefix excluding the entire string
    int i = 0;
    int j = 1;
    int count = 0;
    while (j < match.length()) {
        if (match[i] == match[j]) {
            i++;
            psTable[j + 1] = psTable[j] + 1;
        } else {
            i = 0;
            psTable[j + 1] = 0;
        }
        j++;
    }
    int target = 0;
    i = 0;
    while (i < s.length()) {
        for (; target < match.length() && i < s.length(); target++, i++) {
            if (match[target] == s[i]) {
                continue;
            } else {
                if (target == 0) {
                    i++;
                }
                break;
            }
        }  
        count += (target == match.length())?1:0;
        target = psTable[target];
    }
    cout << count << '\n';

}
