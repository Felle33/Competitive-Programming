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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n;
    cin >> n;
    vector<int> to(n), parents(n);

    rep(i, n){
        cin >> to[i];
        to[i]--;
        parents[to[i]]++;
    }

    int ans = n;
    queue<int> q;
    rep(i, n){
        if(parents[i] == 0){
            q.push(i);
            ans--;
        }
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        parents[to[node]]--;
        if(parents[to[node]] == 0){
            q.push(to[node]);
            ans--;
        }
    }

    cout << ans << '\n';
}

int main(){
    freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);
    solve();
}