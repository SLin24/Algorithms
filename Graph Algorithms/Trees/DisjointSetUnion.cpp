#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

/*
const int MAX = 500;
int p[MAX];
int sz[MAX];

int get(int a) {
	return (p[a] = (a == p[a]?a:get(p[a])));
}

void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (sz[a] > sz[b]) swap(a, b);
    p[a] = p[b];
	sz[b] += sz[a];
}
*/

//more optimized solution with Struct:

struct DSU {
    vector<int> p;
    void init(int N) {p = vector<int>(N, -1);} //vector p counts the number of elements in each set (if value is neg, node is the root, else it is a pointer to the leader)
    int get(int a) {return ((p[a] < 0)? a : p[a] = get(p[a]));} //if value is negative, it is root node, and return index of the root node, else if not negative, it is a pointer to the the parent of the root of the subtree (may or may not be root of entire tree)
    bool same_set(int a, int b) {return (get(a) == get(b));}
    int getSize(int a) {return -p[get(a)];}
    bool unite(int a, int b) {
        a = get(a); b = get(b); //indices of the roots of the trees
        if (a == b) return 0;
        if (p[a] > p[b]) swap(a, b); //reversed since if a value is a greater negative, it has a smaller size
        p[a] += p[b]; p[b] = a; //set the pointer of the leader of the smaller set to the leader of the larger set
        return 1;
    }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    DSU D;
    D.init(8); //8 nodes
    cout << D.get(0) << '\n'; //0 indexed
    D.unite(0, 3);
    D.unite(1, 2);
    D.unite(0, 1);
    cout << D.get(5) << '\n';
    cout << "SIZE: " << D.getSize(1) << '\n';
    cout << "SAMESET: 1 and 3: " << D.same_set(1, 3) << '\n';

    


	
	
}
