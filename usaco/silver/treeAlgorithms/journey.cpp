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
#include <iomanip>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;
const int DIM = 1e5 + 1;

vector<int> graph[DIM];
vector<bool> visited(DIM);

double dfs(int node, int con){
    visited[node] = true;
    if(con == 0) return 0;

    double ans = 0;
    for(int e : graph[node]){
        if(!visited[e]){
            ans += dfs(e, graph[e].size() - 1);
        }
    }

    return ans / con + 1;
}

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    double ans = 0;
    int con = graph[1].size();
    visited[1] = true;
    for(int e : graph[1]){
        ans += dfs(e, graph[e].size() - 1);
    }

    cout << fixed << setprecision(8);
    if(con != 0){
        ans = ans / con;
        cout << ans + 1 << '\n';
    }
    else{
        cout << 0 << '\n';
    }
}

int main(){
    /* freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout); */
    solve();
} 