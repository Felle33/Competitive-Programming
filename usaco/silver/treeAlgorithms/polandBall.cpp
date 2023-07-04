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
const int DIM = 1e5 + 1;

vector<int> graph[DIM];
vector<bool> visited(DIM);

void dfs(int node){
    visited[node] = true;

    for(int e : graph[node]){
        if(!visited[e]){
            dfs(e);
        }
    }
}

void solve(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ans++;
            dfs(i);
        }
    }

    cout << ans;
}

int main(){
    /* freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout); */
    solve();
} 