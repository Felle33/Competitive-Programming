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
const int DIM = 2e5 + 1;

vector<int> graph[DIM];
vector<bool> visited(DIM);

int dfs(int node){
    visited[node] = true;

    for(int e : graph[node]){
        if(!visited[e]){
            int res = dfs(e);
            
        }
    }

}

void solve(){
    int n;
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout); */
    solve();
} 