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

typedef long long ll;
using namespace std;

const int dim = 1000;
vector<vector<char>> graph(dim, vector<char>(dim));
vector<vector<bool>> visited(dim, vector<bool>(dim));
int ans = 0;
vector<int> DIRS = {-1, 0, 1, 0, -1};
int n, m;

void dfs(int i, int j){
    visited[i][j] = true;

    for(int k = 0; k < 4; k++){
        int newI = i + DIRS[k];
        int newJ = j + DIRS[k + 1];

        if(newI < 0 || newJ < 0 || newI == n || newJ == m || visited[newI][newJ] || graph[newI][newJ] != '.') continue;
        dfs(newI, newJ);
    }
}

void solve(){
    
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!visited[i][j] && graph[i][j] == '.'){
                ans++;
                dfs(i, j);
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    /* freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout); */
    solve();
} 