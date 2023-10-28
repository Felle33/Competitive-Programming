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

struct Edge {
    int a, b, index;
    ll w;
};

bool cmp1(const Edge e1, const Edge e2) {
    return e1.w > e2.w;
}

struct DSU {
    vector<int> p;
    vector<unsigned int> r;

    DSU(int N) {
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
};

void solve(){
    int n, m;
    ll s;
    cin >> n >> m >> s;

    vector<Edge> edges;
    set<int> edgesDeleted;
    set<int> added;
    ll totalSum = 0;
    rep(i, m) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        a--, b--;
        totalSum += w;
        edges.push_back({a, b, i, w});
        edgesDeleted.insert(i);
    }
    sort(all(edges), cmp1);
    ll sumAddedEdges = 0;

    DSU dsu = DSU(n);
    
    for(int i = 0, e = 0; i < m && e < n - 1; i++) {
        if(dsu.unite(edges[i].a, edges[i].b)) {
            sumAddedEdges += edges[i].w;
            added.insert(edges[i].index);
            edgesDeleted.erase(edges[i].index);
            e++;
        }
    }

    // at this point i have a MST, how to maximize the total number of deleted nodes?
    // to maximize I have to add only the heaviest edges
    // continue to add edges until the sum is >= s
    int pEdges = 0;

    while(pEdges < m && (totalSum - sumAddedEdges) >= s) {
        // I have to add an edge
        // which edge?
        while(pEdges < m && added.count(edges[pEdges].index) > 0) {
            pEdges++;
        }

        if(pEdges < m) {
            sumAddedEdges += edges[pEdges].w;
            edgesDeleted.erase(edges[pEdges].index);
            pEdges++;
        }
    }

    /*for(int i = 0; i < m; i++) {
        cout << edges[i].a << " " << edges[i].b << " " << edges[i].w << '\n';
    }*/

    int deleted = edgesDeleted.size();
    cout << deleted << '\n';
    for(auto it = edgesDeleted.begin(); it != edgesDeleted.end(); it++) {
        cout << *it + 1 << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}