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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

int n;

// adjecency graph
vvi adj;

// capacity of every edge
vector<vll> cap;

// Given a graph, the algo calculates the max flow from the source (node 0)
// to the end point (node n - 1)
// To do this we run a bfs
// Time complexity O(|V| * |E| * |E|)

ll bfs(int source, int sink, vi& parent) {
    fill(all(parent), -1);
    parent[source] = -2;
    queue<pair<int, ll>> q;
    q.push(mp(source, INF));

    while(!q.empty()) {
        int node = q.front().first;
        ll capacity = q.front().second;
        q.pop();

        for(int to : adj[node]) {
            if(parent[to] == -1 && cap[node][to] > 0) {
                parent[to] = node;
                ll new_flow = min(capacity, cap[node][to]);
                if (to == sink)
                    return new_flow;
                q.push(mp(to, new_flow));
            }
        }
    }
    return 0;
}

ll edmonds_karp(int source, int sink) {
    vi parent(n + 1);
    int result = 0;
    while(1) {
        ll currFlow  = bfs(source, sink, parent);
        result += currFlow;

        if(currFlow  == 0) break;
        int from = parent[sink];
        int dest = sink; 
        while (dest != source) {
            cap[from][dest] -= currFlow;
            cap[dest][from] += currFlow;
            dest = from;
            from = parent[from];
        }
    }

    return result;
}

void solve(){
    n = 4;
    int source = 1, sink = 4;
    adj = vvi(n + 1);
    cap = vector<vll>(n + 1, vll(n + 1));
    
    adj[1].push_back(2);
    adj[2].push_back(1);
    cap[1][2] = 40;
    
    adj[1].push_back(4);
    adj[4].push_back(1);
    cap[1][4] = 20;
    
    adj[2].push_back(4);
    adj[4].push_back(2);
    cap[2][4] = 20;
    
    adj[2].push_back(3);
    adj[3].push_back(2);
    cap[2][3] = 30;
    
    adj[3].push_back(4);
    adj[4].push_back(3);
    cap[3][4] = 10;
    
    printf("%d\n", edmonds_karp(source, sink));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}