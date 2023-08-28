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
// dp[i][j] = maximum possible achievable points by a player knowing
// that the start element is in position i and the last element
// is in the positio j - 1 (i < j)
vector<vector<int>> dp;

// turn = 0 => turn of the first player
// turn = 1 => turn of the second player
int win(int i, int j, int turn) {
    if(j - i == 1) {
        return A[i];
    }

}

void solve(){
    int n; 
    cin >> n;
    A = vector<int>(n);
    
    rep(i, n) {
        cin >> A[i];
    }

    win(0, n, 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}