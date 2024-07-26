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

void solve(){
    int n; cin >> n;

    int idxMax = 0;

    for(int i = 1; i < n; i++) {
        cout << "? " << idxMax << " " << idxMax << " " << i << " " << i << endl << flush;
        char c; cin >> c;
        if(c == '<') {
            idxMax = i;
        }
    }

    int maxXor = n;
    for(int i = 31; i >= 0; i--) {
        if(n & (1 << i)) {
            for(int j = i; j >= 0; j--) {
                maxXor |= (1 << j);
            }
            break;
        }
    }

    vi cand;
    int twin = 0;
    cand.push_back(twin);
    for(int i = 1; i < n; i++) {
        if(i != idxMax) {
            cout << "? " << idxMax << " " << twin << " " << idxMax << " " << i << endl << flush;
            char c; cin >> c;
            if(c == '<') {
                twin = i;
                cand.clear();
                cand.push_back(twin);
            } else if(c == '=') {
                cand.push_back(i);
            }
        }
    }

    int idxMin = cand.front();

    for(int i = 1; i < (int)cand.size(); i++) {
        cout << "? " << idxMin << " " << idxMin << " " << cand[i] << " " << cand[i] << endl << flush;
        char c; cin >> c;

        if(c == '>') idxMin = cand[i];
    }

    cout << "! " << idxMin << " " << idxMax << endl << flush;
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}