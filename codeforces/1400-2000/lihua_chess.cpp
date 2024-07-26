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

void solve(){
    int n, m; cin >> n >> m;
    cout << "? 1 1" << endl << flush;
    int x; cin >> x;
    x++;
    int i = min(x, n), j = min(x, m);

    cout << "? " << i << " " << j << endl << flush;
    int y; cin >> y;

    if(i == x && j == x) {
        int h = x - y;
        cout << "? " << x << " " << h << endl << flush;
        int guess; cin >> guess;

        if(guess == 0) {
            cout << "! " << x << " " << h << endl << flush;
        } else {
            cout << "! " << h << " " << x << endl << flush;
        }
    } else if(i != x) {
        // there are less rows
        cout << "! " << i - y << " " << j << endl << flush;
    } else {
        // there are less cols
        cout << "! " << i << " " << j - y << endl << flush;
    }
    
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}