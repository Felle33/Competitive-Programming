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
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
int DI[] = {0, 1, -1, 0};
int DJ[] = {1, 0, 0, -1};

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;
ll pref_row[DIM + 10], pref_col[DIM + 10];
ll dots_row[DIM + 10], dots_col[DIM + 10];

void bfs(int starti, int startj) {
    int mn_row = starti, mx_row = starti;
    int mn_col = startj, mx_col = startj;
    int s = 0;

    queue<pii> q;
    q.push({starti, startj});
    visited[starti][startj] = 1;

    while(!q.empty()) {
        pii p = q.front(); q.pop();
        int i = p.first, j = p.second;
        mn_row = min(mn_row, i);
        mx_row = max(mx_row, i);
        mn_col = min(mn_col, j);
        mx_col = max(mx_col, j);
        s++;

        for(int k = 0; k < 4; k++) {
            int newi = i + DI[k], newj = j + DJ[k];

            if(newi < 0 || newj < 0 || newi >= n || newj >= m || visited[newi][newj] || grid[newi][newj] == '.') continue;
            q.push({newi, newj});
            visited[newi][newj] = 1;
        }
    }

    if(mn_row - 1 >= 0) pref_row[mn_row - 1] += s;
    else pref_row[mn_row] += s;
    pref_row[mx_row + 2] -= s;

    if(mn_col - 1 >= 0) pref_col[mn_col - 1] += s;
    else pref_col[mn_col] += s;
    pref_col[mx_col + 2] -= s;
}

void solve(){
    cin >> n >> m;
    grid = vector<vector<char>>(n, vector<char>(m));
    visited = vector<vector<bool>>(n, vector<bool>(m));

    rep(i, n) 
        rep(j, m) cin >> grid[i][j];

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!visited[i][j] && grid[i][j] == '#') {
                bfs(i, j);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        int dots = 0;
        for(int j = 0; j < m; j++) {
            dots += (grid[i][j] == '.');
        }
        dots_row[i] = dots;
    }

    for(int j = 0; j < m; j++) {
        int dots = 0;
        for(int i = 0; i < n; i++) {
            dots += (grid[i][j] == '.');
        }
        dots_col[j] = dots;
    }

    int cur = 0;
    for(int i = 0; i < n; i++) {
        cur += pref_row[i];
        pref_row[i] = cur;
    }

    cur = 0;
    for(int i = 0; i < m; i++) {
        cur += pref_col[i];
        pref_col[i] = cur;
    }

    ll ans = 0;

    for(int i = 0; i < n; i++) {
        ans = max(ans, dots_row[i] + pref_row[i]);
    }

    for(int j = 0; j < m; j++) {
        ans = max(ans, dots_col[j] + pref_col[j]);
    }
    
    cout << ans << "\n";

    for(int i = 0; i < n + 5; i++) pref_row[i] = dots_row[i] = 0;
    for(int j = 0; j < m + 5; j++) pref_col[j] = dots_col[j] = 0;
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}