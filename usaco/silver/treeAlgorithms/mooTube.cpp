#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;
const int DIM = 5e3 + 1;

struct Edge{
    int end, weight;
};

vector<Edge> graph[DIM];
vector<bool> visited(DIM);

int numFilms(int node, int relevance){
    int res = 0;
    visited[node] = true;

    for(Edge e : graph[node]){
        if(e.weight >= relevance && !visited[e.end]){
            res += numFilms(e.end, relevance);
        }
    }

    return res + 1;
}

void solve(){
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n - 1; i++){
        int a, b, r;
        cin >> a >> b >> r;
        graph[a].push_back({b, r});
        graph[b].push_back({a, r});
    }

    for(int i = 0; i < q; i++){
        int k, v;
        cin >> k >> v;

        fill(all(visited), false);
        cout << numFilms(v, k) - 1 << '\n';
    }
}

int main(){
    freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);
    solve();
} 