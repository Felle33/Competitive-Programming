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
#include <bitset>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n, m;
vvi adj;
vector<bool> visited, onStack;
vi path;

bool dfs(int node) {
    visited[node] = 1;
    onStack[node] = 1;

    for(int to : adj[node]) {
        if(!visited[to]) {
            if(dfs(to)) {
                path.push_back(node);
                return true;
            }
        } else {
            if(onStack[to]) {
                path.push_back(to);
                path.push_back(node);
                return true;
            }
        }
    }

    onStack[node] = 0;
    return false;
}

void solve(){
    cin >> n >> m;
    adj = vvi(n);
    visited = vector<bool>(n);
    onStack = vector<bool>(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
    }

    bool yes = false;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(dfs(i)) {
                yes = 1;
                break;
            }
        }
    }

    if(yes) {
        int start = path.front();
        int s = path.size();
        vi ans;
        ans.push_back(start);
        for(int i = 1; i < s; i++) {
            ans.push_back(path[i]);
            if(path[i] == start) break;
        }

        reverse(all(ans));
        cout << ans.size() << '\n';
        for(int x : ans) {
            cout << (x + 1) << ' ';
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;
    
    solve();
}