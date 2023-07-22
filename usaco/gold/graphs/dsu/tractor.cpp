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

int n;
int dfs(int i, int j, vector<vector<int>>& grid, int x, vector<vector<bool>>& visited) {
	visited[i][j] = true;
	int ans = 0;

	for(int k = 0; k < 4; k++){
		int newi = i + DY[k];
		int newj = j + DX[k];

		if(newi < 0 || newi >= n || newj < 0 || newj >= n || visited[newi][newj] || abs(grid[i][j] - grid[newi][newj]) > x) continue;
		ans += dfs(newi, newj, grid, x, visited);
	}

	return ans + 1;
}

void solve(){
	cin >> n;

	vector<vector<int>> grid(n, vector<int>(n));
	int l = -1, r = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) {
			cin >> grid[i][j];
			r = max(r, grid[i][j]);
		}
	}

	int goal = (n * n) % 2 == 0 ? (n * n) / 2 : (n * n) / 2 + 1;
	vector<vector<bool>> visited(n, vector<bool>(n));

	while(l + 1 < r) {
		int m = l + (r - l) / 2;
		bool assigned = false;

		for(int i = 0; i < n && !assigned; i++) {
			for(int j = 0; j < n && !assigned; j++) {
				if(dfs(i, j, grid, m, visited) >= goal) {
					r = m;
					assigned = true;
				}
			}
		}

		rep(i, n) {
			rep(j, n) {
				visited[i][j] = false;
			}
		}

		if(!assigned) l = m;
	}
	
	cout << r << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("tractor.in", "r", stdin);
	freopen("tractor.out", "w", stdout);

    solve();
}