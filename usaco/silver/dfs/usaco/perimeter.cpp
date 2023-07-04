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
int area = 0;
int perimeter = 0;
vector<int> DIRS = {-1, 0, 1, 0, -1};
int n;

void dfs(int i, int j){
    visited[i][j] = true;
    area++;


    for(int k = 0; k < 4; k++){
        int newI = i + DIRS[k];
        int newJ = j + DIRS[k + 1];

        if(newI < 0 || newJ < 0 || newI == n || newJ == n || graph[newI][newJ] == '.'){
            perimeter++;
            continue;
        }
        else if(visited[newI][newJ]){
            continue;
        }
        dfs(newI, newJ);
    }
}

void solve(){
    
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }

    int ansArea = 0;
    int ansPerimeter = 1e9;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && graph[i][j] == '#'){
                area = 0;
                perimeter = 0;
                dfs(i, j);
                if(ansArea < area){
                    ansArea = area;
                    ansPerimeter = perimeter;
                }
                else if(ansArea == area){
                    ansPerimeter = min(ansPerimeter, perimeter);
                }
            }
        }
    }

    cout << ansArea << " " << ansPerimeter << '\n';
}

int main(){
    freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
    solve();
} 