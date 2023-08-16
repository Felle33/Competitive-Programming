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
#define f first
#define s second
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for(int to : adj[node]) {
        if(!visited[to]) {
            dfs(to, adj, visited);
        }
    }
}

void solve(){
    ll n; cin >> n;
    vi nums(n);
    vector<bool> flag(2e5 + 1);
    ll numbers = 0;
    rep(i, n) {
        cin >> nums[i];
        if(!flag[nums[i]]) numbers++;
        flag[nums[i]] = true;
    }

    vector<vector<int>> adj(2e5 + 1);
    for(int i = 0; i < n / 2; i++) {
        int a = nums[i], b = nums[n - i - 1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(2e5 + 1);
    ll conn = 0;
    rep(i, 2e5 + 1) {
        if(flag[i]) {
            if(!visited[i]) {
                conn++;
                dfs(i, adj, visited);
            }
        }
    }

    cout << numbers - conn << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}