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
#include <unordered_set>

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

vvi adj;
vector<bool> partOfTheCycle;
vector<int> inArc;
vi distancesMarcel, distancesValerie;
int n, m, v;

void topSort() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(inArc[i] == 1) {
            partOfTheCycle[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int to : adj[node]) {
            inArc[to]--;
            if(inArc[to] == 1) {
                partOfTheCycle[to] = 0;
                q.push(to);
            }
        }
    }
}

void bfs(int start) {
    vector<bool> visited(n + 1);
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    distancesMarcel[start] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int to : adj[node]) {
            if(!visited[to]) {
                distancesMarcel[to] = distancesMarcel[node] + 1;
                visited[to] = 1;
                q.push(to);
            }
        }
    }
}

pair<int, int> bfsV(int start) {
    vector<bool> visited(n + 1);
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    distancesValerie[start] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int to : adj[node]) {
            if(!visited[to]) {
                distancesValerie[to] = distancesValerie[node] + 1;
                visited[to] = 1;
                if(partOfTheCycle[to]) {
                    return mp(to, distancesValerie[node] + 1);
                }
                q.push(to);
            }
        }
    }

    return mp(-1, -1);
}

void solve(){
    cin >> n >> m >> v;
    adj = vvi(n + 1);
    inArc = vi(n + 1);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        inArc[a]++;
        inArc[b]++;
    }

    if(m == v) {
        cout << "NO\n";
        return;
    }

    partOfTheCycle = vector<bool>(n + 1, 1);
    partOfTheCycle[0] = 0;

    topSort();

    if(partOfTheCycle[v]) {
        cout << "YES\n";
        return;
    }

    distancesMarcel = vi(n + 1);
    distancesValerie = vi(n + 1);
    bfs(m);
    pii res = bfsV(v);

    if(res.second < distancesMarcel[res.first]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}