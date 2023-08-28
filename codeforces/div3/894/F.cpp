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
#include <bitset>

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

vector<ll> monsters;
bitset<1000001> bit;
int n;
ll w, f;
ll sumOverMonsters;

void reset() {
    bit.reset();
}

ll maxSubsSum(ll sum) {
    ll maxNumber = 0;
    bit[0] = 1;
    for(int i = 0; i < n; i++) {
        bit |= (bit << monsters[i]);
    }

    for(int i = sum; i >= 0; i--) {
        if(bit[i]) {
            maxNumber = i;
            break;
        }
    }
    return maxNumber;
}

bool good(ll time) {
    ll maxSpell = time * w;
    reset();
    ll res = maxSubsSum(min(maxSpell, (ll) 1e6));
    return (sumOverMonsters - res) <= f * time;
}

void solve(){
    cin >> w >> f;
    cin >> n;
    monsters.resize(n);
    sumOverMonsters = 0;
    rep(i, n) {
        cin >> monsters[i];
        sumOverMonsters += monsters[i];
    }

    ll l = -1, r = 1e6;
    while(r - l > 1) {
        ll time = l + (r - l) / 2;
        if(good(time)) {
            r = time;
        } else {
            l = time;
        }
    }

    cout << r << '\n';
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