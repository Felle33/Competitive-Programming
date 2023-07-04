#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>

typedef long long ll;
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> seeds(n);

    for(int i = 0; i < n; i++){
        vector<bool> used(5);
        for(int con : adj[i]){
            used[seeds[con]] = true;
        }

        for(int g = 1; g <= 4; g++){
            if(!used[g]){
                seeds[i] = g;
                break;
            }
        }
    }
    

    for(int i = 0; i < n; i++){
        cout << seeds[i];
    }

    cout << '\n';
}

int main(){
    freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);
    solve();
} 