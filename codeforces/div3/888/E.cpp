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

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

ll makingPotion(map<int, vector<int>>& listOfIngredients, int potionToMake, vector<ll>& dp, vector<ll>& costPotions) {
    ll costMaking = 0;
    rep(i, listOfIngredients[potionToMake].size()) {
        int potionUsed = listOfIngredients[potionToMake][i];
        if(dp[potionUsed] == -1) {
            dp[potionUsed] = min(costPotions[potionUsed], makingPotion(listOfIngredients, potionUsed, dp, costPotions));
        }

        costMaking += dp[potionUsed];
    }
    return costMaking;
}

void solve(){
    int n, k;
    cin >> n >> k;

    vector<ll> costPotions(n);
    rep(i, n) {
        cin >> costPotions[i];
    }

    vector<int> unlimited(n);
    rep(i, k) {
        int x;
        cin >> x;
        x--;
        unlimited[x] = true;
    }

    map<int, vector<int>> listOfIngredients;
    rep(i, n) {
        int m;
        cin >> m;
        rep(j, m) {
            int x;
            cin >> x;
            x--;
            listOfIngredients[i].push_back(x);
        }
    }

    vector<ll> dp(n, -1);
    rep(i, n) {
        if(unlimited[i]) {
            dp[i] = 0;
        } else if(listOfIngredients[i].empty()) {
            dp[i] = costPotions[i];
        }
    }

    rep(i, n) {
        if(dp[i] == -1) {
            dp[i] = min(costPotions[i], makingPotion(listOfIngredients, i, dp, costPotions));
        }
    }

    for(ll x : dp) {
        cout << x << " ";
    }
    cout << '\n';

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}