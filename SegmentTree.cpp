#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

const int N = 1e5;  // limit for array size
int n;  // array size
int t[2 * N];

//for each node k, it's children are node 2k, and node 2k + 1 hence using (k << 1 for 2k and bitwise OR to add 1)
void build() {
  for (int i = n - 1; i > 0; i--) {
    t[i] = t[i << 1] + t[i << 1 | 1];
  }
}

void modify(int p, int value) {  //t[p>>1] = t[p] + t[p^1] (t[p] is 2x the amount of (p >> 1) and p^1 is the 2*(p >> 1) + 1, except it is written in the format that is easier
//we know that if p is odd, then 2 * (p >> 1) will be one less than p, and if p is even, then 2 * (p >> 1) will be equal to p (p^1 adds 1 if p is odd and subtracts 1 if p is even))
  p += n;
  for (t[p] = value; p > 1; p >>= 1) {
    //fancy formatting (t[p >> 1] = t[2 * (p >> 1)] + t[2 * (p >> 1) + 1] also works)
    t[p>>1] = t[p] + t[p^1];
  }
}

int query(int l, int r) {  
  // for the left, it checks if it is the right node of the parent (Parents will only have 2 children) -> if it is, the parent won't include just the node, so we add it, and then we move the left pointer to the right of the parent. Else, we just move it normally to the parent
  // for the right, we can have it check if it is the left most node, and if it is, then we will add it to our sum. 
  int res = 0;
  for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (!(r&1)) res += t[r--];
  }
  return res;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> t[n + i];
  build();
  for (int i = 0; i < 24; i++) {
    cout << t[i] << " ";
  }
  cout << '\n';
  modify(0,2);
  for (int i = 0; i < 24; i++) {
    cout << t[i] << " ";
  }
  cout << '\n';
  printf("%d\n", query(0, 2));
  return 0;
}
