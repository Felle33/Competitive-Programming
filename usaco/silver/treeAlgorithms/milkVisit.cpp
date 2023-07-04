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

bool dfs(int node, int end){
    return true;
}

void solve(){
    int n, q;
    string cowsBreed;
    cin >> n >> q >> cowsBreed;

    for(int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int numComponent = 0;
    vector<int> component(n, -1);
    for(int i = 0; i < n; i++){
        if(component[i] != -1) continue;

        queue<int> q;
        q.push(i);
        component[i] = numComponent;
        char breed = cowsBreed[i];

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int e : graph[node]){
                if(component[e] == -1 && cowsBreed[e] == breed){
                    q.push(e);
                    component[e] = numComponent;
                }
            }
        }
        numComponent++;
    }

    for(int i = 0; i < q; i++){
        int start, end;
        char pref;
        cin >> start >> end >> pref;

        start--, end--;
        if(component[start] != component[end]){
            cout << 1;
        }
        else{
            cout << (cowsBreed[start] == pref);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout); */
    solve();
} 