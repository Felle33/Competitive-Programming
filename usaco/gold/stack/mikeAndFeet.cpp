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
#include <stack>

#define all(x) (x).begin(), (x).end()
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

typedef long long ll;
using namespace std;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    int n;
    cin >> n;

    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
    }

    stack<pair<ll, ll>> s;
    vector<ll> frontSmall(n), behindSmall(n);

    for(int i = 0; i < n; i++){
        while(!s.empty() && s.top().first > a[i]) {
            pair<ll, ll> top = s.top();
            s.pop();
            frontSmall[top.second] = i;
        }

        s.push({a[i], i});
    }

    while(!s.empty()) {
        pair<ll, ll> top = s.top();
        s.pop();
        frontSmall[top.second] = n;
    }

    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && s.top().first > a[i]) {
            pair<ll, ll> top = s.top();
            s.pop();
            behindSmall[top.second] = i;
        }

        s.push({a[i], i});
    }

    while(!s.empty()) {
        pair<ll, ll> top = s.top();
        s.pop();
        behindSmall[top.second] = -1;
    }

    vector<ll> ans(n + 1, -1);
    for(int i = 0; i < n; i++) {
        ll index = frontSmall[i] - behindSmall[i] - 1;
        ans[index] = max(ans[index], a[i]);
    }

    ll val = ans[n];
    for(int i = n; i >= 1; i--) {
        ans[i] = max(ans[i], val);
        val = max(val, ans[i]);
    }

    for(int i = 1; i <= n; i++) cout << ans[i] << ' ';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}