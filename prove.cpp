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
#define mp make_pair
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

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges){
    // first dest and second weight
    vector<vector<pair<int, int>>> adj(n);
    for(int i = 0; i < m; i++) {
        adj[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
    }
    
    vector<int> distances(n, INF);
    vector<int> parent(n);
    vector<bool> visited(n);
    // first distance and second the node
    priority_queue<pair<int, int>> min_queue;
    min_queue.push(make_pair(0, 0));
    
    while(!min_queue.empty()) {
        pair<int, int> nodeTop = min_queue.top();
        min_queue.pop();
        
        if(visited[nodeTop.second]) continue;
        visited[nodeTop.second] = true;
        
        cout << nodeTop.second << " ----- " << nodeTop.first << '\n';
        for(pair<int, int> to : adj[nodeTop.second]) {
            if(distances[to.first] > to.second + nodeTop.first) {
                distances[to.first] = to.second + nodeTop.first;
                min_queue.push(make_pair(distances[to.first], to.first));
                parent[to.first] = nodeTop.second;
            }
        }
    }
    
    if(parent[n - 1] == -1) return {-1};
    vector<int> ans;
    
    ans.push_back(n - 1);
    int p = n - 1;
    do {
        int p = parent[p];
        if(p != -1) {
            ans.push_back(p);
            
        }
    } while(p != -1);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    map<int,int> compress;

    int t; cin >> t;
    rep(i, t) {
        int a; cin >> a;
        compress[a];
    }

    for(auto& v : compress) {
        cout << v.first << " " << v.second << '\n';
    }
}
