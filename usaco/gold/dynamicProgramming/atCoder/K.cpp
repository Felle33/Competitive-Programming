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
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

vector<int> A;
// dp[stones][0] = 0, 1, -1
// -1 => not already calculated
// 0 wins the first player
// 1 wins the second player
// in a state a player wins if there is at least one another linked state
// in which he/she wins
vector<vector<int>> dp;

// turn = 0 => turn of the first player
// turn = 1 => turn of the second player
int win(int stones, int turn) {
    if(stones == 0) {
        // if the turn of 0 => 1 wins
        // if the turn of 1 => 0 wins
        dp[stones][turn] = !turn;
    }
    if(dp[stones][turn] != -1) return dp[stones][turn];

    bool one_win = false;
    for(int choice : A) {
        if(choice > stones || one_win) break;
        if(win(stones - choice, !turn) == turn) {
            one_win = true;
        }
    }

    if(one_win) {
        dp[stones][turn] = turn;
    } else {
        dp[stones][turn] = !turn;
    }
    
    return dp[stones][turn];
}

void solve(){
    int n, k; 
    cin >> n >> k;
    A = vector<int>(n);
    dp = vector<vector<int>>(k + 1, vector<int>(2, -1));
    rep(i, n) {
        cin >> A[i];
    }

    cout << (win(k, 0) == 0 ? "First" : "Second") << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}