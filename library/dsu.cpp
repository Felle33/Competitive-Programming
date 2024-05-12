#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

typedef long long ll;
using namespace std;

struct DSU {
	int n; vector<int> p; vector<unsigned int> r;

	DSU() {}

    DSU(int N) {
        p = vector<int>(N); r = vector<unsigned int>(N, 1);
        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(r[x] == r[y]) r[x]++;
        
        if(r[x] > r[y]){
			p[y] = x;
		} else {
			p[x] = y;
		}  
        return true;
    }

    void reset() { rep(i, n) {p[i] = i; r[i] = 1;} }
};