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

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct DSU {
	int n;
	vector<int> p;
    vector<unsigned int> r;
	vector<int> age;

	DSU() {}

    DSU(int N) {
		n = N;
        p = vector<int>(N);
        r = vector<unsigned int>(N, 1);
        age = vector<int>(N);

        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    int get(int x) { 
		if(p[x] == x) return x;
		return get(p[x]);
	}

	void get_parents(int x, vector<int>& v) {
		v.push_back(x);
		if(p[x] == x) return;
		get_parents(p[x], v);
	}

    bool unite(int x, int y, int a) {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(r[x] == r[y]) 
            r[x]++;
        
        if(r[x] > r[y]){
			p[y] = x;
			age[y] = a;
		}
        else {
			p[x] = y;
			age[x] = a;
		}  
        return true;
    }

	void reset() {
		for(int i = 0; i < n; i++){
            p[i] = i;
			r[i] = 1;
        }
	}
};

void solve(){
	int n, m, q;
	cin >> n;

	DSU dsu = DSU(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;

		dsu.unite(a, b, i + 1);
	}

	// LCA and take the min time
	rep(i, q) {
		int a, b;
		cin >> a >> b;
		vector<int> v1, v2, v_intersection;
		dsu.get_parents(a, v1);
		dsu.get_parents(a, v2);

		std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(),
                          std::back_inserter(v_intersection));
		
		int t = 1e9;
		for(int x : v_intersection) {
			t = min(t, dsu.age[t]);
		}
	}
	
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("tractor.in", "r", stdin);
	//freopen("tractor.out", "w", stdout);

    solve();
}