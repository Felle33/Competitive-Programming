#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define FELLE ios_base::sync_with_stdio(false); cin.tie(NULL); std::cout.precision(10); cout << std::fixed;

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

ll n1, n2, n3;
int k;
vector<int> choices;
int dp[101][101][101][2];

bool dfs(int n1, int n2, int n3, bool petTurn) {
    if(n1 == 0 && n2 == 0 && n3 == 0) {
        return !petTurn;
    }

    if(dp[n1][n2][n3][petTurn] != -1) return dp[n1][n2][n3][petTurn];

    bool canWin = 0;
    bool atLeastOneChoice = 0;
    for(int choice : choices) {
        if(canWin) break;
        if(choice >= n1) canWin |= dfs(n1 - choice, n2, n3, !petTurn), atLeastOneChoice = 1;
        if(choice >= n2) canWin |= dfs(n1, n2 - choice, n3, !petTurn), atLeastOneChoice = 1;
        if(choice >= n3) canWin |= dfs(n1, n2, n3 - choice, !petTurn), atLeastOneChoice = 1;
    }

    dp[n1][n2][n3][petTurn] = canWin;
    return canWin;
}


// NOT SOLVED
void solve(){
    cin >> n1 >> n2 >> n3 >> k;
    
    choices = vi(k);
    rep(i, k) cin >> choices[i];

    memset(dp, -1, sizeof(dp));

    cout << dfs(n1, n2, n3, 1) << "\n";
}

int main(){
    FELLE
    solve();
}