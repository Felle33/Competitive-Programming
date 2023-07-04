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

    vector<int> students(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        a--;

        students[i] = a;
    }

    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++){
        int a = i;
        
        

    }

    for(int i = 0; i < n; i++){
        cout << ans[i] << ' ';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout); */
    solve();
} 