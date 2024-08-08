#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

#define all(x) (x).begin(), (x).end()
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define FELLE ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.precision(10); cout << std::fixed;

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll DIM = 1e3;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

int n, m;
bool visited[DIM + 1][DIM + 1];
char grid[DIM + 1][DIM + 1];

bool near_trap(int i, int j) {
    bool flag = 0;
    if(i > 0) flag |= (grid[i - 1][j] == 'T');
    if(j > 0) flag |= (grid[i][j - 1] == 'T');
    if(i < n - 1) flag |= (grid[i + 1][j] == 'T');
    if(j < m - 1) flag |= (grid[i][j + 1] == 'T');
    return flag;
}

ll bfs(pii start) {
    ll ans = 0;
    queue<pii> q;
    
    visited[start.first][start.second] = 1;
    q.push(start);

    while(!q.empty()) {
        pii node = q.front(); q.pop();
        int i = node.first, j = node.second;

        if(grid[i][j] != 'S' && grid[i][j] != '.') ans += grid[i][j] - '0';
        if(near_trap(i, j)) continue;
        for(int k = 0; k < 4; k++) {
            int newi = i + DX[k];
            int newj = j + DY[k];

            if(newi < 0 || newj < 0 || newi >= n || newj >= m || grid[newi][newj] == '#' || visited[newi][newj]) continue;
            visited[newi][newj] = 1;
            q.push({newi, newj});
        }
    }

    return ans;
}

void solve(){
    while(cin >> n >> m) {
        pii start;
    
        rep(i, n) {
            rep(j, m) {
                cin >> grid[i][j];
                if(grid[i][j] == 'S') start = {i, j};
            }
        }

        cout << bfs(start) << "\n";
        memset(visited, 0, sizeof(visited));
    }
}

int main(){
    FELLE
    solve();
}