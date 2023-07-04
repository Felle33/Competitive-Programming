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
int n, k;
vector<vector<ll>> dp;
vector<vector<ll>> activities;

ll rec(int i, int activity){
    if(dp[i][activity] != 0) return dp[i][activity];

    if(activity == 0){
        dp[i][0] = max(activities[i][1] + rec(i + 1, 1), activities[i][2] + rec(i + 1, 2));
    }
    else if(activity == 1){
        dp[i][1] = max(activities[i][0] + rec(i + 1, 0), activities[i][2] + rec(i + 1, 2));
    } else if(activity == 2){
        dp[i][2] = max(activities[i][0] + rec(i + 1, 0), activities[i][1] + rec(i + 1, 1));
    }

    return dp[i][activity];
}

void solve(){
    cin >> n;

    activities.resize(n);
    dp.resize(n);

    for(int i = 0; i < n; i++){
        dp[i].resize(3);
        activities[i].resize(3);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> activities[i][j];
        }
    }
    dp[n - 1][0] = max(activities[n - 1][1], activities[n - 1][2]);
    dp[n - 1][1] = max(activities[n - 1][0], activities[n - 1][2]);
    dp[n - 1][2] = max(activities[n - 1][0], activities[n - 1][1]);
    
    ll res = rec(0, 0);
    res = max(res, rec(0, 1));
    res = max(res, rec(0, 2));

    cout << res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /* freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout); */
    solve();
} 