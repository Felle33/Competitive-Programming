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

void solve(){
    int n; cin >> n;

    vvi adj(n);
    rep(i, n - 1) {
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int mostDistant = -1;
    queue<int> q;
    vector<bool> visited(n);

    q.push(0);
    visited[0] = 1;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        mostDistant = node;

        for(int to : adj[node]) {
            if(!visited[to]) {
                visited[to] = 1;
                q.push(to);
            }
        }
    }

    fill(all(visited), 0);
    q.push(mostDistant);
    visited[mostDistant] = 1;
    int distance = 0;

    while(!q.empty()) {
        int cycles = q.size();

        while(cycles--) {
            int node = q.front();
            q.pop();
            mostDistant = node;

            for(int to : adj[node]) {
                if(!visited[to]) {
                    visited[to] = 1;
                    q.push(to);
                }
            }
        }

        distance++;
    }
    distance--;
    cout << distance * 3 << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}