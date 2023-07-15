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

	DSU() {}

    DSU(int N) {
		n = N;
        p = vector<int>(N);
        r = vector<unsigned int>(N, 1);

        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(r[x] == r[y]) 
            r[x]++;
        
        if(r[x] > r[y]){
			p[y] = x;
		}
        else {
			p[x] = y;
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

DSU dsu;
int n;

bool good(int x, vector<pii>& cows) {
	int rem = n - 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) {
			if (i == j) continue;

			// already in the same set
			if(dsu.get(i) == dsu.get(j)) continue;
			int dist_x = abs(cows[i].first - cows[j].first) * abs(cows[i].first - cows[j].first);
			int dist_y = abs(cows[i].second - cows[j].second) * abs(cows[i].second - cows[j].second);

			if ((dist_x + dist_y) <= x) {
				dsu.unite(i, j);
				rem--;
			}
		}
	}

	return rem == 0;
}

void solve(){
	cin >> n;

	vector<pii> cows(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		cows[i].first = x;
		cows[i].second = y;
	}

	dsu = DSU(n);
	int r = 2e9, l = -1;
	while(l + 1 < r) {
		int x = l + (r - l) / 2;

		if(good(x, cows)) {
			r = x;
		} else {
			l = x;
		}

		dsu.reset();
	}

	cout << r << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

    solve();
}