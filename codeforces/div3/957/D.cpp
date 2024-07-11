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

int n, m, k;
string river;

void solve(){
    cin >> n >> m >> k;
    cin >> river;

    river = "L" + river + "L";
    
    vi logs, croc;
    for(int i = 1; i <= n + 1; i++) {
        if(river[i] == 'L') logs.pb(i);
        if(river[i] == 'C') croc.pb(i);
    }

    bool arrive = 1;
    for(int i = 0, idxLog = 0, idxCroc = 0; i <= n && arrive; ) {
        if(river[i] == 'L') {
            if(logs[idxLog] <= i + m) {
                i = logs[idxLog];
                idxLog++;
            } else {
                i += m;
            }
        } else if(river[i] == 'C') {
            arrive = 0;
        } else {
            auto next_croc_it = lower_bound(croc.begin(), croc.end(), i);
            auto next_log_it = lower_bound(logs.begin(), logs.end(), i);
            int next_croc = (next_croc_it == croc.end() ? INF : *next_croc_it);
            int next_log = (next_log_it == logs.end() ? INF : *next_log_it);

            if(next_croc < next_log) {
                arrive = 0;
            } else {
                k -= (next_log - i);
                if(k < 0) arrive = 0;
                i = next_log;
            }
        }
    }

    if(arrive) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    FELLE
    int t; cin >> t;
    while(t--){
        solve();
    }
}