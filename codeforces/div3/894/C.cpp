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
const int MAX = 2e5 + 1;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";



void solve(){
    int n; cin >> n;
    vll heights(n);
    ll ma = -INF;
    
    vector<int> cum(n + 1, 0);
    bool abrt = false;
    rep(i, n) {
        cin >> heights[i];
        if(heights[i] > n) {
            abrt = true;
        } else {
            cum[heights[i]]++;
        }
    }

    if(abrt) {
        cout << "NO\n";
        return;
    }
    
    int cur = 0;
    for(int i = n; i >= 0; i--) {
        cur += cum[i];
        cum[i] = cur;
    }

    for(int i = 0; i < n; i++) {
        if(heights[i] != cum[i + 1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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