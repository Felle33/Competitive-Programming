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
#define f first
#define s second
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    ll n, k; cin >> n >> k;
    vector<pii> ids(n);
    vll ans(n, k / n);
    rep(i, n){
        cin >> ids[i].first;
        ids[i].second = i;
    }
    sort(all(ids));
    rep(i, k % n) {
        ans[ids[i].second]++;
    }

    for(ll x : ans) {
        cout << x << ' ';
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}