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
#define pb push_back
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
ll k, n; 
vll groups;

bool good(ll cons) {
    ll mem = k * cons;
    ll counterMemDisp = 0;

    for(int i = 0; i < n; i++) {
        ll memDisp = min(cons, groups[i]);
        counterMemDisp += memDisp;
    }

    return counterMemDisp >= mem;
}

void solve(){
    cin >> k >> n;
    groups = vll(n);
    rep(i, n) cin >> groups[i];

    ll l = 0, r = 1;

    while(good(r)) r *= 2;

    while(l + 1 < r) {
        ll mid = l + (r - l) / 2;

        if(good(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    solve();
}