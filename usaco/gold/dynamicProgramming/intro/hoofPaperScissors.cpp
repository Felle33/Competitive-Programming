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

#define HOOF 0
#define PAPER 1
#define SCISSORS 2

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;

ll area(vector<ll> rect) {
	ll width = rect[2] - rect[0];
	ll height = rect[3] - rect[1];
	return width * height;
}

// return 0 if it doesn't intersect
int inter_area(vector<ll> s1, vector<ll> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	ll l1 = min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x);
	ll l2 = min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y);

	if(l1 <= 0 || l2 <= 0) return 0;

	return l1 * l2;
}

// return true if x,y is covered by the rectangle s
bool covered(ll x, ll y, vector<ll> s){
	return x >= s[0] && x <= s[2] && y >= s[1] && y <= s[3];
}

ll exponentiation(ll b, ll e){
    ll res = 1;
    b %= MOD;
    while(e > 0){
        if(e & 1)
            res = res * b % MOD;
        
        b = b * b % MOD;
        e >>= 1;
    }

    return res;
}

int n, k;
vector<int> jones;

int win(int game, int gesture){
    if(gesture == HOOF && jones[game] == SCISSORS) return 1;
    if(gesture == PAPER && jones[game] == HOOF) return 1;
    if(gesture == SCISSORS && jones[game] == PAPER) return 1;
    return 0;
}

void solve(){
    cin >> n >> k;
    jones.resize(n + 1);
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(3)));

    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;

        if(c == 'H') jones[i] = HOOF;
        if(c == 'P') jones[i] = PAPER;
        if(c == 'S') jones[i] = SCISSORS;
    }

    ll ans = 0;

    for(int i = 1; i <= n; i++){
        int addone = win(i, HOOF);
        dp[i][0][HOOF] = dp[i - 1][0][HOOF] + addone;

        addone = win(i, PAPER);
        dp[i][0][PAPER] = dp[i - 1][0][PAPER] + addone;

        addone = win(i, SCISSORS);
        dp[i][0][SCISSORS] = dp[i - 1][0][SCISSORS] + addone;

        if(i == n){
            ans = max({ans, dp[i][0][HOOF], dp[i][0][PAPER], dp[i][0][SCISSORS]});
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            int addone = win(i, HOOF);
            dp[i][j][HOOF] = addone + max({dp[i - 1][j][HOOF], dp[i - 1][j - 1][PAPER], dp[i - 1][j - 1][SCISSORS]});

            addone = win(i, PAPER);
            dp[i][j][PAPER] = addone + max({dp[i - 1][j][PAPER], dp[i - 1][j - 1][HOOF], dp[i - 1][j - 1][SCISSORS]});

            addone = win(i, SCISSORS);
            dp[i][j][SCISSORS] = addone + max({dp[i - 1][j][SCISSORS], dp[i - 1][j - 1][HOOF], dp[i - 1][j - 1][PAPER]});

            if(i == n){
                ans = max({ans, dp[i][j][HOOF], dp[i][j][PAPER], dp[i][j][SCISSORS]});
            }
        }
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

    solve();
}