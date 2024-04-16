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

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n;
vector<vector<pair<ll, ll>>> adj;
queue<int> q;
vll ans;

ll calcDistances(int start) {
    vector<bool> visited(n);

    ll distance = 0;
    ll sumDistance = 0;
    q.push(start);
    visited[start] = 1;

    while(!q.empty()) {
        int cycles = q.size();
        while(cycles--) {
            int node = q.front();
            q.pop();
            sumDistance += distance;

            for(pair<ll, ll>& p : adj[node]) {
                int to = p.first;
                if(!visited[to]) {
                    visited[to] = 1;
                    q.push(to);
                }
            }
        }
        distance++;
    }

    return sumDistance;
}

int dfs(int node, int pa) {
    int totSubtree = 1;
    for(pair<ll, ll>& p : adj[node]) {
        int to = p.first;
        if(to != pa) {
            int szGroup = dfs(to, node);
            p.second = szGroup;
            totSubtree += szGroup;
        }
    }

    return totSubtree;
}

void calcGroups(int node, int pa) {
    for(pair<ll, ll>& p : adj[node]) {
        int to = p.first;
        if(to != pa) {
            calcGroups(to, node);
        }
    }

    int sum = 0;
    for(pair<ll, ll>& p : adj[node]) {
        if(p.second != -1) sum += p.second;
    }

    for(pair<ll, ll>& p : adj[node]) {
        if(p.second == -1) p.second = n - (sum + 1);
    }
}

void calcAns(int node, int pa, ll sum) {
    ans[node] = sum;
    for(pair<ll, ll>& p : adj[node]) {
        int to = p.first;
        if(to != pa) {
            calcAns(to, node, sum - p.second + n - p.second);
        }
    }
}

void solve(){
    cin >> n;
    adj = vector<vector<pair<ll, ll>>>(n);
    ans = vll(n);
    for(int i; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back({b, -1});
        adj[b].push_back({a, -1});
    }

    dfs(0, -1);
    calcGroups(0, -1);
    ll distance = calcDistances(0);
    calcAns(0, -1, distance);

    rep(i, n) cout << ans[i] << " ";
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}