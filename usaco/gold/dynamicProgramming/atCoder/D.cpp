#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

const int DIM = 1e5 + 1;
const ll inf = 1e12;
int n, cap;
vector<int> weights;
vector<ll> values;
vector<vector<ll>> dp(101, vector<ll>(1e9 + 1, -1));

ll rec(int i, int weight){
    if(i == n) return 0;

    if(dp[i][weight] != -1) return dp[i][weight];

    ll res1 = rec(i + 1, weight);
    ll res2 = 0;
    if(weight + weights[i] <= cap){
        res2 = values[i] + rec(i + 1, weight + weights[i]);
    }

    dp[i][weight] = max(res1, res2);
    return dp[i][weight];
}

void solve(){
    cin >> n >> cap;
    weights.resize(n);
    values.resize(n);

    for(int i = 0; i < n; i++){
        cin >> weights[i];
        cin >> values[i];
    }

    cout << rec(0, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 